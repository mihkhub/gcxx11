// Copyright [2018] <Copyright Changfeng Chen>
/*
 * use_codecvt.cc
 *
 *  Created on: Feb 13, 2018
 *      Author: changfengc
 *      Brief: The standard class codecvt attempts to address conversions between different character coding schemes.
 *      File Encoding: utf8
 */

#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <ext/codecvt_specializations.h>
#include <locale>
#include <iostream>


typedef std::codecvt_base::result                             result;
typedef uint16_t                                    unicode_t;
typedef unicode_t                                           int_type;
typedef char                                                ext_type;
typedef __gnu_cxx::encoding_state                         state_type;
typedef std::codecvt<int_type , ext_type , state_type> unicode_codecvt;

int main(int argc, char **argv) {
  const ext_type *              e_lit = "black pearl jasmine tea";
  int                           size = strlen(e_lit);

  const ext_type*              efrom_next;
  int_type*                 i_arr = new int_type[size+1];
  int_type*                   ito_next;

  // construct a locale object with the specialized fact.
  std::locale              loc(std::locale(), new unicode_codecvt);
  // sanity check the constructed locale has the specialized facet.

  std::has_facet<unicode_codecvt>(loc);
  const unicode_codecvt & cvt = std::use_facet<unicode_codecvt>(loc);
  // convert between const char* and unicode strings
  unicode_codecvt::state_type state01("ASCII", "UTF-8");
  result r1 = cvt.in(state01, e_lit, e_lit + size, efrom_next,
                     i_arr, i_arr+size, ito_next);
  assert(r1 == std::codecvt_base::ok);
//  assert(efrom_next == e_lit + size);
//  assert(ito_next == i_arr + size);
  char *out = reinterpret_cast<char*>(i_arr);
  std::cout << "Out: " << out << std::endl;
  return 0;
}

