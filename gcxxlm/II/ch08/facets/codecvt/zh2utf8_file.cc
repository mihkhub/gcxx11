// Copyright [2018] <Copyright changfeng.or.chen79@gmail.com>
/*
 * zh2utf8_file.cc
 *
 *  Created on: Feb 13, 2018
 *      Author: changfengc
 *      Brief: Convert GB2312 to UTF-8
 */
#include <assert.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include "codecvt_zh.h"

const char kGbFileName[] = "gb18030.txt";
const char kUtf8FileName[] = "utf8.txt";

int main(int argc, char **argv) {
  std::ofstream out_utf8(kUtf8FileName);
  std::ifstream fin(kGbFileName);
  fin.imbue(std::locale("zh_CN.utf8"));

  std::cout << "The UTF-8 file contains the following wide characters: \n";

  char line[4096];
  int size = sizeof(line) / 2;
  const ext_type * e_lit;
  const ext_type* efrom_next;
  int_type* i_arr = new int_type[size + 1];
  int_type* ito_next;

  // construct a locale object with the specialized fact.
  std::locale loc(std::locale(), new unicode_codecvt);
  // sanity check the constructed locale has the specialized facet.

  std::has_facet<unicode_codecvt>(loc);
  const unicode_codecvt & cvt = std::use_facet<unicode_codecvt>(loc);
  // convert between const char* and unicode strings
  unicode_codecvt::state_type state01("UTF-8", "GB18030");
  char *c_line;

  while (!fin.eof()) {
    fin.getline(line, sizeof(line));
    e_lit = line;
    size = strlen(e_lit);
    result r1 = cvt.in(state01, e_lit, e_lit + size, efrom_next, i_arr,
                       i_arr + size, ito_next);
    assert(r1 == std::codecvt_base::ok);
    c_line = reinterpret_cast<char*>(i_arr);
    std::cout << "SRC: " << line << std::endl << "OUT: " << c_line << std::endl
              << std::endl;
    out_utf8 << c_line;
  }

  fin.close();
  out_utf8.close();

  return 0;
}

