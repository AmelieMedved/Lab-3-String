#pragma once
#include "_string.h"

int main()
{
  MyString string_1;
  MyString string_2("Order");
  MyString string_3;
  MyString string_4("Hello World!");

  string_1 = string_2;

  string_3 = string_1 + string_2;

  (string_2 == string_1) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

  (string_3 > string_1) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

  (string_3 < string_1) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

  string_2.duplicatString(2);
  string_4.duplicatString(1);

  string_4 = string_2 + " " + string_4;

  std::cout << string_4;

  MyString string_5("LANDLANDaaLANDa   sfLANDLANDasfLAND");
  string_5.findSubfirst("LAND");

  MyString string_6("a/b/c/d");
  std::cout << string_6.GetStr() << std::endl;

  string_6.findSymbolfirst('a');

  string_6.Segment('/');

  MyString string_10("test1ptest2");

  string_10.Segment('p');

  MyString string_34("sladkiy_pirosjochek");

  string_34.Segment('_');

  MyString string_99;
  MyString string_1999;

  string_99 = string_1999;

  MyString string_23("OCULUS");

  string_99 = string_23;

  MyString String100("appearance");

  std::cout << String100.findSymbolfirst('a') << std::endl;
  std::cout << String100.findSubAll("a") << std::endl;

  return 0;
}