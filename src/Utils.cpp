#include <string>

#include "Utils.h"

extern "C" {
    // from inp into ans (from attrib.c)
    void copyMostAttrib(SEXP inp, SEXP ans);
}

// this is the map, used for storing the hashes
std::map<size_t, bool> seenSigs;
// this is the str version of the std hash function
std::hash<std::string> str_hash;

// [[Rcpp::export]]
bool is_interesting(std::string pkg_name, std::string fun_name, int arg_len, SEXP arg_names,
                    SEXP arg_types, SEXP arg_attrs, SEXP arg_classes) {
  // NOTE: ensure that arg_attrs passed as a list of strings, i.e. collate already

  // first, compute hash
  // first.1: make a big string
  std::string aggr_string = pkg_name + ":" + fun_name + "/";

  for (int i = 0; i < arg_len; i++) {
    aggr_string = aggr_string + arg_names[i] + "," + arg_types[i] + "," + arg_attrs[i] + "," + arg_classes[i] + "/";
  }

  // first.2: hash it
  size_t hashedSig = str_hash(aggr_string);

  // second, see if hash collision occurs
  bool collision = false;

  if (seenSigs.find(hashedSig) != seenSigs.end()) {
    // in
    collision = true;
  } else {
    // out, add it
    seenSigs[hashedSig] = true;
  }

  // third, determine if we should tract

  return collision;
}

// [[Rcpp::export]]
SEXP get_dd_val(int i, SEXP rho, SEXP default_value, bool force=false) {
    // TODO: check args
    SEXP dots = findVar(R_DotsSymbol, rho);

    if (TYPEOF(dots) == DOTSXP && dots != R_UnboundValue) {
        if (length(dots) >= i) {
            dots = nthcdr(dots, i - 1);
            SEXP val = CAR(dots);

            if (TYPEOF(val) == PROMSXP) {
                if (force) {
                    return Rf_eval(val, rho);
                } else if (PRVALUE(val) == R_UnboundValue) {
                    return default_value;
                } else {
                    return PRVALUE(val);
                }
            } else {
                return val;
            }
        } else {
            Rf_error("Unable to find ..%d - the ... does not contain %d elements", i, i);
        }
    } else {
        Rf_error("Unable to find ..%d - used in an incorrect context, no ... to look in", i);
    }

    return default_value;
}

// [[Rcpp::export]]
SEXP reassign_function(SEXP target_fun, SEXP new_fun) {
  if (TYPEOF(target_fun) != CLOSXP) error("target_fun must be a function");
  if (TYPEOF(new_fun) != CLOSXP) error("new_fun must be a function");

  SET_BODY(target_fun, BODY(new_fun));

  return R_NilValue;
}

// [[Rcpp::export]]
SEXP create_duplicate(SEXP target) {
  if (isNull(target)) error("target must not be null");

  return duplicate(target);
}

// [[Rcpp::export]]
std::string environment_name(SEXP env) {
    if (R_IsPackageEnv(env) == TRUE) {
        // cf. builtin.c:432 do_envirName
        return CHAR(STRING_ELT(R_PackageEnvName(env), 0));
    } else if (R_IsNamespaceEnv(env) == TRUE) {
        // cf. builtin.c:434 do_envirName
        return CHAR(STRING_ELT(R_NamespaceEnvSpec(env), 0));
    } else {
        return "";
    }
}

// [[Rcpp::export]]
std::string environment_name_as_code(SEXP env) {
    if (env == R_EmptyEnv) {
        return "emptyenv()";
    } else if (env == R_GlobalEnv) {
        return ".GlobalEnv";
    } else if (env == R_BaseEnv || env == R_BaseNamespace) {
        return ".BaseNamespaceEnv";
    } else {
        std::string name = environment_name(env);
        if (!name.empty()) {
            return "getNamespace(\"" + name + "\")";
        } else {
            return "";
        }
    }
}