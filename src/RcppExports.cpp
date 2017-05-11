// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// serialize_value
std::string serialize_value(SEXP s);
RcppExport SEXP genthat_serialize_value(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type s(sSEXP);
    rcpp_result_gen = Rcpp::wrap(serialize_value(s));
    return rcpp_result_gen;
END_RCPP
}
// reassign_function
SEXP reassign_function(SEXP target_fun, SEXP new_fun);
RcppExport SEXP genthat_reassign_function(SEXP target_funSEXP, SEXP new_funSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type target_fun(target_funSEXP);
    Rcpp::traits::input_parameter< SEXP >::type new_fun(new_funSEXP);
    rcpp_result_gen = Rcpp::wrap(reassign_function(target_fun, new_fun));
    return rcpp_result_gen;
END_RCPP
}
// create_duplicate
SEXP create_duplicate(SEXP target);
RcppExport SEXP genthat_create_duplicate(SEXP targetSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type target(targetSEXP);
    rcpp_result_gen = Rcpp::wrap(create_duplicate(target));
    return rcpp_result_gen;
END_RCPP
}
