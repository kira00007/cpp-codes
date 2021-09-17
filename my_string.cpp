#include "my_string.h"

myspace::String::String()
    : m_Buffer(nullptr), m_Size(0)
{

}
myspace::String::String(const char *name)
    : m_Size((size_t) strlen(name))
{
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, name, m_Size);
    m_Buffer[m_Size] = 0;
}
myspace::String::String(const String &string)
    : m_Size(string.m_Size)
{
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string.m_Buffer, m_Size + 1);
}
myspace::String::String(const char ch)
    : m_Size(1)
{
    m_Buffer = new char[1];
    m_Buffer[0] = ch;
    m_Buffer[1] = 0;
}
myspace::String::String(String &&string)
    : m_Buffer(string.m_Buffer), m_Size(string.m_Size)
{
    string.m_Buffer = nullptr;
    string.m_Size = 0;
}
myspace::String::~String() {
    delete[] m_Buffer;
}
size_t myspace::String::size() {
    return m_Size;
}
myspace::String myspace::String::substr(int fromIndex = 0, int len = -1) {
    if(len == -1) len = m_Size - fromIndex;
    String returnValue;
    returnValue.m_Buffer = new char[len + 1];
    memcpy(returnValue.m_Buffer, this->m_Buffer + fromIndex, len);
    returnValue.m_Buffer[len] = 0;
    return returnValue;

}
myspace::String& myspace::String::operator = (const String &string) {
    if(this != &string) {
        if(this->m_Buffer) delete[] this->m_Buffer;
        this->m_Size = string.m_Size;
        this->m_Buffer = new char[this->m_Size + 1];
        memcpy(this->m_Buffer, string.m_Buffer, m_Size + 1);
    }
    return *this;
}
myspace::String& myspace::String::operator = (const char *string) {
    if(this->m_Buffer) delete[] this->m_Buffer;
    this->m_Size = strlen(string);
    this->m_Buffer = new char[m_Size + 1];
    memcpy(this->m_Buffer, string, m_Size);
    this->m_Buffer[this->m_Size] = 0;
    return *this;
}
myspace::String& myspace::String::operator = (const char ch) {
    if(this->m_Buffer) delete[] this->m_Buffer;
    this->m_Size = 1;
    this->m_Buffer = new char[2];
    this->m_Buffer[0] = ch;
    this->m_Buffer[1] = 0;
    return *this;
}
myspace::String myspace::String::operator + (const String &string) {
    String returnValue;
    returnValue.m_Size = this->m_Size + string.m_Size;
    returnValue.m_Buffer = new char[returnValue.m_Size + 1];
    strcpy(returnValue.m_Buffer, this->m_Buffer);
    strcat(returnValue.m_Buffer, string.m_Buffer);
    return returnValue;
}
myspace::String myspace::String::operator + (const char *string) {
    String returnValue;
    returnValue.m_Size = this->m_Size + strlen(string);
    returnValue.m_Buffer = new char[returnValue.m_Size + 1];
    strcpy(returnValue.m_Buffer, this->m_Buffer);
    strcat(returnValue.m_Buffer, string);
    return returnValue;
}
myspace::String myspace::String::operator + (const char ch) {
    String returnValue;
    returnValue.m_Size = this->m_Size + 1;
    returnValue.m_Buffer = new char[returnValue.m_Size + 1];
    strcpy(returnValue.m_Buffer, this->m_Buffer);
    returnValue[returnValue.m_Size - 1] = ch;
    returnValue[returnValue.m_Size] = 0;
    return returnValue;
}
myspace::String myspace::String::operator += (const String &string) {
    strcat(m_Buffer, string.m_Buffer);
    m_Size += string.m_Size;
    return *this;
}
myspace::String& myspace::String::operator += (const char *string) {
    strcat(m_Buffer, string);
    m_Size += strlen(string);
    return *this;
}
myspace::String& myspace::String::operator += (const char ch) {
    char *temp = new char[2];
    temp[0] = ch;
    temp[1] = 0;
    strcat(this->m_Buffer, temp);
    this->m_Size += 1;
    delete[] temp;
    return *this;
}
char& myspace::String::operator [] (int idx) {
    return m_Buffer[idx];
}
bool myspace::String::operator == (const String &string) {
    return !strcmp(this->m_Buffer, string.m_Buffer);
}
bool myspace::String::operator != (const String &string) {
    return strcmp(this->m_Buffer, string.m_Buffer);
}
std::istream& myspace::operator >> (std::istream &stream, String &string) {
    if(string.m_Buffer) delete[] string.m_Buffer;
    string.m_Buffer = new char[256];
    stream >> string.m_Buffer;
    string.m_Size = strlen(string.m_Buffer);
    return stream;
}
std::ostream& myspace::operator << (std::ostream &stream, const String &string) {
    stream << string.m_Buffer;
    return stream;
}