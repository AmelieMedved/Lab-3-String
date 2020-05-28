#pragma once
#include <string>
#include "_string.h"

void MyString::CycleAssign(const char* string)
{
  this->len = strlen(string);
  this->str = new char[len + 1];
  for (size_t i = 0; i < len; i++)
  {
    this->str[i] = string[i];
  }
  this->str[len] = '\0';
}

void MyString::CycleAssign(const MyString& obj)
{

  this->len = obj.len;
  this->str = new char[len + 1];
  for (size_t i = 0; i < len; i++)
  {
    this->str[i] = obj.str[i];
  }
  this->str[len] = '\0';
}

int position(const MyString* obj, const char* substr, int entry)
{
  size_t i = 0, j = 0;
  size_t sslen = 0;
  size_t objlen = 0;

  for (sslen = 0; substr[sslen]; sslen++);
  for (objlen = 0; obj->str[objlen]; objlen++);

  for (i = 0; i <= objlen - sslen; i++)
  {
    for (j = 0; obj->str[i + j] == substr[j]; j++);
    if (j - sslen == 1 && i == objlen - sslen && !(entry - 1)) return i;
    if (j == sslen)
      if (entry - 1) entry--;
      else return i;
  }

  return -1;
}

int position(const MyString* obj, const char symbol, int entry)
{
  size_t i = 0, j = 0;
  size_t objlen = 0;

  for (objlen = 0; obj->str[objlen]; objlen++);

  for (i = 0; i <= objlen - 1; i++)
  {
    for (j = 0; obj->str[i + j] == symbol; j++);
    if (j - 1 == 1 && i == objlen - 1 && !(entry - 1)) return i;
    if (j == 1)
      if (entry - 1) entry--;
      else return i;
  }

  return -1;
}

int* MyString::findSubAll(const char* substr)
{
  int* temp;
  int entry = 0;
  int ENTRYT = 0;
  try
  {
    for (int i = 1; entry != -1; i++)
    {
      entry = position(this, substr, i);
      ENTRYT++;
    }

    if (ENTRYT != 0)
    {
      int l = 0;
      temp = new int[ENTRYT];
      entry = 0;
      for (int i = 1; entry != -1; i++)
      {
        for (; ((l < i) && (entry != -1)); l++)
        {
          entry = position(this, substr, i);
          if (entry >= 0)
          {
            temp[l] = entry;
          }
        }
      }
    }
    else
    {
      throw "character not found";
    }
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
    throw;
  }

  for (int i = 0; i < (ENTRYT - 1); i++)
  {
    std::cout << temp[i] << std::endl;
  }

  return temp;
}

int MyString::findSubfirst(const char* substr)
{
  try
  {
    size_t i;
    int entry = 0;
    for (i = 1; entry != -1; i++)
    {
      entry = position(this, substr, i);
      if (entry >= 0)
        return entry;
      else
        return -1;
    }
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
    throw;
  }

  throw;
}

int MyString::findSymbolfirst(const char symbol)
{
  try
  {
    size_t i;
    int entry = 0;
    for (i = 1; entry != -1; i++)
    {
      entry = position(this, symbol, i);
      if (entry >= 0)
        return entry;
      else
        return -1;
    }
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
    throw;
  }

  throw;
}

void MyString::SetStr(const char* string)
{
  CycleAssign(string);
}

char* MyString::GetStr()
{
  return this->str;
}

void MyString::Segment(const char symbol)
{
  int i = 0;
  int entry = 0;
  int ENTRYT = 0;
  char** temp;

  for (i = 1; entry != -1; i++)
  {
    entry = position(this, symbol, i);
    ENTRYT++;
  }

  if (ENTRYT != 0)
  {
    temp = new char* [256];
    for (int i = 0; i < ENTRYT + 1; i++)
      temp[i] = new char[256];
  }
  else
  {
    temp = nullptr;
  }

  i = 0;
  int j = -1;
  int k, l = 0;
  entry = 0;

  for (i = 1; entry != -1; i++)
  {
    for (; l < i && entry != -1; l++)
    {
      entry = position(this, symbol, i);
      if (entry >= 0)
      {
        j++;
        k = 0;
        for (; j < entry; j++)
        {
          for (; k < (entry - j) || (entry - j) >= 0; k++)
          {
            temp[l][k] = str[j];
            k++;
            break;
          }
        }
        temp[l][k] = '\0';
        for (int p = 0; p < k; p++)
          std::cout << temp[l][p];
        std::cout << " " << std::endl;
      }
    }
  }

  if (len - j > 1)
  {
    j++;
    k = 0;
    for (; j < len; j++)
    {
      for (; k < (len - j) || len - j >= 0; k++)
      {
        temp[l][k] = str[j];
        k++;
        break;
      }
    }
    temp[l][k] = '\0';
    for (int p = 0; p < k; p++)
      std::cout << temp[l][p];
    std::cout << " " << std::endl;
  }

  if (temp != nullptr)
  {
    for (int i = 0; i < ENTRYT; i++)
      delete[] temp[i];
    delete[] temp;
  }

}

MyString::MyString()
{
  len = 0;
  str = nullptr;
}

MyString::MyString(const char* string)
{
  CycleAssign(string);
}

MyString::MyString(const MyString& obj)
{
  CycleAssign(obj);
}

MyString::~MyString()
{

  if (this->str != nullptr)
  {
    delete[] str;
  }
}

char MyString::GetMostUsedChar()
{
  size_t count[256];

  for (size_t i = 0; i < 256; ++i)
  {
    count[i] = 0;
  }

  for (size_t i = 0; i < len; i++)
  {
    count[(int)str[i]]++;
  }

  size_t index = 0;
  for (size_t i = 1; i < 256; ++i)
  {
    if (count[i] > count[index])
    {
      index = i;
    }
  }

  return (char)index;
}

void MyString::duplicatString(size_t k)
{
  if (k >= 2)
  {
    MyString temp(*this);
    size_t i = 0;
    size_t new_len = len * k;
    if (str != nullptr)
    {
      delete[] str;
    }
    len = new_len + k;
    str = new char[len];
    for (size_t q = 2; q <= k; q++)
    {
      for (; i < temp.len; i++)
      {
        str[i] = temp.str[i];
      }
      str[i] = ' ';
      i++;
      for (size_t j = 0; j < temp.len; j++, i++)
      {
        str[i] = temp.str[j];
      }
    }
    str[len - 1] = '\0';
  }
}

MyString& MyString::operator=(const MyString& obj)
{
  if (this != &obj)
  {
    if (this->str != nullptr)
    {
      delete[] str;
    }
    CycleAssign(obj);
  }

  return *this;
}

std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
  if (obj.len != 0)
    for (size_t i = 0; i < obj.len; i++)
    {
      out << obj.str[i];
    }
  out << std::endl;

  return out;
}


std::istream& operator>>(std::istream& in, MyString& obj)
{
  char buff[2048];
  in.getline(buff, sizeof(buff));
  MyString temp(buff);
  obj = temp;

  return in;
}

bool operator==(const MyString& obj_1, const MyString& obj_2)
{
  if (obj_1.len == obj_2.len)
  {
    int count = 0;
    for (size_t i = 0; i < obj_1.len; i++)
    {
      if (obj_1.str[i] == obj_2.str[i])
      {
        count++;
      }
    }
    if (count == obj_1.len)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  return false;
}

bool operator<(const MyString& obj_1, const MyString& obj_2)
{
  if (obj_1.len < obj_2.len)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool operator>(const MyString& obj_1, const MyString& obj_2)
{
  if (obj_1.len > obj_2.len)
  {
    return true;
  }
  else
  {
    return false;
  }
}

const char& MyString::operator[](int i) const
{
  return str[i];
}

MyString MyString::operator+(const MyString& obj)
{
  MyString temp;

  temp.len = this->len + obj.len;
  temp.str = new char[this->len + obj.len + 1];

  size_t i = 0;
  for (; i < this->len; i++)
  {
    temp.str[i] = this->str[i];
  }

  for (size_t j = 0; j < obj.len; j++, i++)
  {
    temp.str[i] = obj.str[j];
  }

  temp.str[temp.len] = '\0';

  return temp;
}