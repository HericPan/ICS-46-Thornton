// String.cpp
//
// ICS 46 Spring 2021
// Project #0: Getting to Know the ICS 46 VM
//
// Implement all of your String member functions in this file.
//
// Note that the entire standard library -- both the C Standard
// Library and the C++ Standard Library -- is off-limits for this
// task, as the goal is to exercise your low-level implementation
// skills (pointers, memory management, and so on).



#include "String.hpp"
#include "OutOfBoundsException.hpp"



namespace
{
    unsigned int calculateLength(const char* chars)
    {
        unsigned int len = 0;
        while (chars[len] != '\0')
        {
            len++;
        }
        return len;
    }

    void charArrayCopy(const char* source, char* target, unsigned int len)
    {
        unsigned int i = 0;
        for (; i < len; i++)
        {
            target[i] = source[i];
        }
        // give a null-terminated sign
        target[i] = '\0';
    }

    void charArrayAppend(const char* source, char* target, unsigned int sourceLen, unsigned int start)
    {
        for (unsigned int i = 0; i < sourceLen; i++)
        {
            target[start] = source[i];
            start++;
        }
        target[start] = '\0';
    }

    void boundCheck(unsigned int len, unsigned int index)
    {
        if (index >= len){
        throw OutOfBoundsException{};
        }
    }

    bool isInFront(const char* astring, const char* substring) 
    {
        if (calculateLength(substring) == 0) {
            return true;
        } else {
            
            if (astring[0] == substring[0]) {
                return true && isInFront(astring+1, substring+1);
            } else {
                return false;
            }
            
        }
    }

    bool isEqual(const char* str1, const char* str2)
    {
        if (str1[0] == '\0' || str2[0] == '\0')
        {
            return (str1[0] == '\0' && str2[0] == '\0');
        } else {
            if (str1[0] == str2[0]){
                return isEqual(str1+1, str2+1);
            } else {
                return false;
            }
        }
    }
}

String::String()
: len{0}, sz{len+1}, string{new char[sz]}
{
    string[0] = '\0';
}

String::String(const char* chars)
{
    // get the length of chars pointer's content
    len = calculateLength(chars);
    // the size including \0 character
    sz = len + 1;

    // allocate a new one
    string = new char[sz];
    charArrayCopy(chars, string, len);

}

String::String(const String& s)
: len{s.len}, sz{s.sz}, string{new char[s.sz]}
{
    charArrayCopy(s.string, string, len);
}

String::~String() noexcept
{
    delete[] string;
}

String& String::operator=(const String& s)
{
    if (this != &s)
    {
        char* newstring = new char[s.sz];
        charArrayCopy(s.string, newstring, s.len);
        
        sz = s.sz;
        len = s.len;

        delete[] string;
        string = newstring;
    }
    return *this;
}

// not finished yet

void String::append(const String& s){
    
    char* newstring = new char[sz];
    charArrayCopy(string, newstring, len);

    unsigned int oldLen = len;
    len += s.len;
    charArrayAppend(s.string, newstring, s.len, oldLen);

    delete[] string;
    
    string = newstring;
}



char String::at(unsigned int index) const 
{
    boundCheck(len, index);
    return string[index];
}
char& String::at(unsigned int index)
{
    boundCheck(len, index);
    return string[index];
}

// clear() makes this string be empty.
void String::clear(){
    delete[] string;
    len = 0;
    sz = 1;
    string = new char[sz];
    string[0] = '\0';
}

// compareTo() compares the contents of this string to the
// contents of another string lexicographically, returning
// zero if they're exactly equal, a negative value if this
// string is "less than" the other one lexicographically,
// or a positive value if this string is "greater than"
// the other one lexicographically.
int String::compareTo(const String& s) const noexcept 
{
    unsigned int i = 0;
    while (i <= s.len && i <= len) {
        if (string[i] == s.string[i])
        {
            i++;
        } else 
        {
            return int(string[i] - s.string[i]);
        }
    }
    return 0;
}

// concatenate() returns a string that contains the
// characters in this string followed by the characters
// in s.
String String::concatenate(const String& s) const {
    String newString{string};
    // charArrayCopy(string, newstring, len);

    // unsigned int oldLen = len;
    // len += s.len;
    // charArrayAppend(s.string, newstring, s.len, oldLen);

    newString.append(s);
    
    return newString;
};

// contains() returns true if this string contains the
// given substring somewhere (e.g., the string "Is Boo
// happy today?" contains the substring "Boo"), or false
// otherwise.
bool String::contains(const String& substring) const noexcept {
    
    bool hasSub = false;

    
    if (len >= substring.len){
        for (unsigned int i = 0; i < (len - substring.len + 1); i++)
        {
            hasSub = hasSub || isInFront(string + i, substring.string);
        }
        return hasSub;
    } else {
        return false;
    }
}

// equals() returns true if this string is equivalent to
// the given string (i.e., they both have the same length
// and contain the same sequence of characters).
bool String::equals(const String& s) const noexcept {
    return isEqual(string, s.string);
}

// find() returns the index where the given substring is
// found within this string, or -1 if it's not found.
int String::find(const String& substring) const noexcept {
    
    for(unsigned int index = 0; index < len; index++) {
        if (isInFront(string + index, substring.string)) {
            return index;
        }
    }
    return -1;
}

// isEmpty() returns true if this string is empty, or
// false otherwise.
bool String::isEmpty() const noexcept {
    if (len == 0) {
        return true;
    } else {
        return false;
    }
}

// length() returns the number of characters in this string.
unsigned int String::length() const noexcept {
    return len;
}

// substring() returns a substring of this substring,
// containing the characters beginning at startIndex
// and ending at (but not including) endIndex.  For
// example, in the string "Boo is happy today",
// substring(7, 12) would return "happy".
String String::substring(unsigned int startIndex, unsigned int endIndex) const {
    int nSize = endIndex - startIndex + 1;
    int nLen = nSize - 1;
    if (startIndex < 0 || startIndex > len-1 || endIndex > len-1 || endIndex <0) {
        throw OutOfBoundsException{};
    }
    char *newCharPtr = new char[nSize];
    newCharPtr[nLen] = '\0';
    for (unsigned int i = 0; i < nLen; i ++) newCharPtr[i] = string[startIndex + i];
    String newString{newCharPtr};

    delete[] newCharPtr;
    return newString;
}

// toChars() returns a C-style string that is equivalent
// (i.e., has the same length and contains the same
// sequence of characters) as this string.  Note that
// the C-style string is not allocated by this member
// function, so it is not necessary to deallocate it.
const char* String::toChars() const noexcept 
{
    return string;
};
