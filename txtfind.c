#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define LINES 250
#define WORDS 30

int get_line(char s[])
{
    int numOfChar = 0;
    char c;
    while( ((c=getchar())!=EOF)  && (c != '\n'))
    {
        
        *(s+numOfChar)=c;
        numOfChar ++;
    }
    *(s+numOfChar)='\0';
    return numOfChar; 
}

int getword(char w[])
{
    int numOfChar = 0;
    char c;
    while( ((c=getchar())!=EOF ) && (c != '\n') && (c != '\t') && (c != ' '))
    {
        *(w+numOfChar)=c;
        numOfChar ++;
    }
    *(w+numOfChar)='\0';
    return numOfChar; 
}

int substring( char * str1, char * str2)
{
    int num2 =0;
    int num1 = 0;

    while(*(str2+num2)!='\0')
    {
        if(*(str1+num1)=='\0')
        {
            return 1;
        }
        else if(*(str1+num1)==*(str2+num2))
        {
            num2++;
            num1++;
        }
        else
        {
            num2++;
            num1=0;
        }
    }
    if(*(str1+num1)=='\0')
    {
        return 1;
    }
    return 0;    
}

int similar (char *s, char *t, int n)
{
    int num2 = 0;
    int num1 = 0;
    while(*(s+num2)!='\0')
    {
        if(*(s+num2)!=*(t+num1))
        {
            n--;
            num2++;
        }
        else if(n<0)
        {
            return 0;
        }
        else{
            num2++;
            num1++;
        }
    }
    if(*(t+num1)=='\0'&&n>=0)
    {
        return 1;
    }
    return 0;   
}

void print_lines(char * str)
{
    char line [LINE];
    
    while(get_line(line))
    {   
        
        if(substring(str,line)){
            printf("%s\n" ,line);
        }
       
    }
}

void print_similar_words(char * str)
{
    char word [WORD];
    
    while(getword(word))
    {
        if(similar(word,str,1)){
            printf("%s\n" ,word);
        }
       
    }
}