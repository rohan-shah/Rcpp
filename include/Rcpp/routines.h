// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Copyright (C) 2013  Romain Francois
// Copyright (C) 2015  Dirk Eddelbuettel
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RCPP_ROUTINE_H
#define RCPP_ROUTINE_H

// the idea is that this file should be generated automatically by Rcpp::register

namespace Rcpp{
    const char* type2name(SEXP x);

    namespace internal{
        unsigned long enterRNGScope();
        unsigned long exitRNGScope();
        char* get_string_buffer();
        SEXP get_Rcpp_namespace();
    }
    double mktime00(struct tm &);
    struct tm * gmtime_(const time_t * const);
}

SEXP          rcpp_get_stack_trace();
SEXP          rcpp_set_stack_trace(SEXP);
std::string   demangle(const std::string& name);
const char*   short_file_name(const char* );
int*          get_cache(int n);
SEXP          stack_trace( const char *file, int line);
SEXP          get_string_elt(SEXP s, int i);
const char*   char_get_string_elt(SEXP s, int i);
void          set_string_elt(SEXP s, int i, SEXP v);
void          char_set_string_elt(SEXP s, int i, const char* v);
SEXP*         get_string_ptr(SEXP s);
SEXP          get_vector_elt(SEXP v, int i);
void          set_vector_elt(SEXP v, int i, SEXP x);
SEXP*         get_vector_ptr(SEXP v);
const char*   char_nocheck(SEXP x);
void*         dataptr(SEXP x);
Rcpp::Module* getCurrentScope();
void          setCurrentScope( Rcpp::Module* mod );
SEXP          reset_current_error();
int           error_occured();
SEXP          rcpp_get_current_error();
// void          print(SEXP s);

#endif
