#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <string.h>

namespace myspace {
    class String {
    private:
        char *m_Buffer;
        size_t m_Size;
    public:
        String();
        String(const char *name);
        String(const String &string);
        String(const char ch);
        String(String &&string);
        virtual ~String();
        size_t size();
        String substr(int fromIndex, int len);
        String &operator = (const String &string);
        String &operator = (const char *string);
        String &operator = (const char ch);
        String operator + (const String &string);
        String operator + (const char *string);
        String operator + (const char ch);
        String operator += (const String &string);
        String &operator += (const char *string);
        String &operator += (const char ch);
        char &operator [] (int idx);
        bool operator == (const String &string);
        bool operator != (const String &string);
        friend std::istream &operator >> (std::istream &stream, String &string);
        friend std::ostream &operator << (std::ostream &stream, const String &string);
    };
    std::istream &operator >> (std::istream &stream, String &string);
    std::ostream &operator << (std::ostream &stream, const String &string);
}

#endif