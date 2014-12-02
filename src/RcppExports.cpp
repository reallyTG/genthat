// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// DecorateSubst_cpp
bool DecorateSubst_cpp(CharacterVector packages, CharacterVector name, CharacterVector functionTypes);
RcppExport SEXP testr_DecorateSubst_cpp(SEXP packagesSEXP, SEXP nameSEXP, SEXP functionTypesSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< CharacterVector >::type packages(packagesSEXP );
        Rcpp::traits::input_parameter< CharacterVector >::type name(nameSEXP );
        Rcpp::traits::input_parameter< CharacterVector >::type functionTypes(functionTypesSEXP );
        bool __result = DecorateSubst_cpp(packages, name, functionTypes);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// UndecorateCpp
bool UndecorateCpp(CharacterVector name);
RcppExport SEXP testr_UndecorateCpp(SEXP nameSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< CharacterVector >::type name(nameSEXP );
        bool __result = UndecorateCpp(name);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// GetArgs
SEXP GetArgs(Environment evalFrame, List missingArgs, Environment dotsEnv);
RcppExport SEXP testr_GetArgs(SEXP evalFrameSEXP, SEXP missingArgsSEXP, SEXP dotsEnvSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< Environment >::type evalFrame(evalFrameSEXP );
        Rcpp::traits::input_parameter< List >::type missingArgs(missingArgsSEXP );
        Rcpp::traits::input_parameter< Environment >::type dotsEnv(dotsEnvSEXP );
        SEXP __result = GetArgs(evalFrame, missingArgs, dotsEnv);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// WriteCapInfo_cpp
void WriteCapInfo_cpp(CharacterVector fname, List args, SEXP retv, SEXP errs, SEXP warns);
RcppExport SEXP testr_WriteCapInfo_cpp(SEXP fnameSEXP, SEXP argsSEXP, SEXP retvSEXP, SEXP errsSEXP, SEXP warnsSEXP) {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< CharacterVector >::type fname(fnameSEXP );
        Rcpp::traits::input_parameter< List >::type args(argsSEXP );
        Rcpp::traits::input_parameter< SEXP >::type retv(retvSEXP );
        Rcpp::traits::input_parameter< SEXP >::type errs(errsSEXP );
        Rcpp::traits::input_parameter< SEXP >::type warns(warnsSEXP );
        WriteCapInfo_cpp(fname, args, retv, errs, warns);
    }
    return R_NilValue;
END_RCPP
}
