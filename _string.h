#pragma once
#include <iostream>

#ifndef __STRING_H_
#define __STRING_H_

class MyString
{
private:
  size_t len;
  char* str;

  void CycleAssign(const char* string);
  void CycleAssign(const MyString& obj);
  friend int position(const MyString* obj, const char* substr, int entry);
  friend int position(const MyString* obj, const char symbol, int entry);
public:
  MyString();
  MyString(const char* string);
  MyString(const MyString& obj);
  ~MyString();
  void duplicatString(size_t k);
  int* findSubAll(const char* substr);
  int findSubfirst(const char* substr);
  int findSymbolfirst(const char symbol);
  void SetStr(const char* string);
  char* GetStr();
  void Segment(const char symbol);
  char GetMostUsedChar();

  //operators
  MyString& operator = (const MyString& obj);
  MyString  operator+(const MyString& obj);
  friend std::ostream& operator << (std::ostream& out, const MyString& obj);
  friend std::istream& operator >> (std::istream& in, MyString& obj);
  const char& operator[](int i) const;
  friend bool operator==(const MyString& obj_1, const MyString& obj_2);
  friend bool operator<(const MyString& obj_1, const MyString& obj_2);
  friend bool operator>(const MyString& obj_1, const MyString& obj_2);

};

#endif // !__STRING_H_