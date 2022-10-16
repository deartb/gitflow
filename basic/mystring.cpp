#include<iostream>
#include<assert.h>
using namespace std;

// 实现自定义c++中的strcpy strlen strcat strcmp函数
// 实现c++中的strcpy函数
char *mystrcpy(char * dest, const char * src)
{
    assert((src!=nullptr) && (dest!=nullptr) && (src != dest));
    char *str = dest;
    while ((*dest = *src) != '\0')
    {
        dest++;
        src++;
    }
    return str;
}

// 实现c++中的strlen函数
int mystrlen(const char * s)
{
    assert(nullptr != s); //非空判断
    int len = 0;
    while ('\0' != *s)
    {
        len++;
        s++; //不能忘记
    }
    return len;
}

// 实现c++中的strcat函数
char *mystrcat(char * dest, const char * src)
{
    assert((nullptr != src) && (nullptr != dest) && (src != dest));
    char *str = dest;
    while('\0' != *dest){
        dest++;
    }
    while ('\0' != *src)
    {
        *dest++ = *src++;
    }
    *dest = *src; //将*src的'\0'也赋值给*dest
    return str;
}

// 实现c++中的strcmp函数
int mystrcmp(char * s1, const char * s2)
{
    assert((nullptr!=s1)&&(nullptr!=s2));
    while (*s1 == *s2)
    {
        if('\0' == *s1)
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main()
{
    // char a[] = "111";
    // char b[] = "abc";
    // char *c = mystrcpy(b,a);
    // char d[10] = "123";
    // char e[20] = "abcdef";
    // char f[] = "123";
    // cout<< "a:"<< a <<endl;
    // cout<< "b:" << b <<endl;
    // cout<< "c:" << c <<endl;
    // cout<< "b_len:" << mystrlen(b) <<endl;
    // cout<< "new_e: " << mystrcat(e, d) << endl;
    // cout<< "len_e: " << mystrlen(e) << endl;
    // cout<< "strcmp(a,b):" << mystrcmp(a,b) << endl;
    // cout<< "strcmp(b,e):" << mystrcmp(b,e) << endl;
    // cout<< "strcmp(e,b):" << mystrcmp(e,b) << endl;
    // cout<< "strcmp(d,f):" << mystrcmp(d,f) << endl;
    return 0;
}