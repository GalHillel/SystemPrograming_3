#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30


int getLine(char s[]) {
    int numOfChar = 0;
    char c;
    while (((c = getchar()) != EOF) && (c != '\n')) {

        *(s + numOfChar) = c;
        numOfChar++;
    }
    *(s + numOfChar) = '\0';
    return numOfChar;
}

int getWord(char w[]) {
    int numOfChar = 0;
    char c;
    while (((c = getchar()) != EOF) && (c != '\n') && (c != '\t') && (c != ' ')) {
        *(w + numOfChar) = c;
        numOfChar++;
    }
    *(w + numOfChar) = '\0';
    return numOfChar;
}

int substring(char *str1, char *str2) {
    int num2 = 0;
    int num1 = 0;

    while (*(str2 + num2) != '\0') {
        if (*(str1 + num1) == '\0') {
            return 1;
        } else if (*(str1 + num1) == *(str2 + num2)) {
            num2++;
            num1++;
        } else {
            num2++;
            num1 = 0;
        }
    }
    if (*(str1 + num1) == '\0') {
        return 1;
    }
    return 0;
}

int similar(char *s, char *t) {
    int i = 0;
    int count = 0;
    if (strlen(s) != strlen(t) + 1)
        return 0;
    for (int j = 0; j < strlen(s) && i < strlen(t); j++) {
        if (s[j] == t[i])
            i++;
        else
            count++;
    }
    if (count > 1)
        return 0;
    return 1;
}

void printLines(char *str) {
    char line[LINE] = {0};
    int size;

    for (int i = 0; i < LINE; i++) {
        size = getLine(line);
        if (size == 0)
            break;
        if (substring(line, str) == 1)
            printf("%s\n", line);
    }
}

void printSimilarWords(char *str) {
    char check[WORD] = {0};
    int size;
    for (int i = 0; i < LINE; i++) {
        size = getWord(check);

        if (size == 0)
            break;

        if (similar(check, str) == 1 || strcmp(check, str) == 0)
            printf("%s\n", check);


    }
}