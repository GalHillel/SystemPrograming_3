#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define WORD 30
#define LINE 256
#define MAXLINES 250

int getLine(char str[]) {
    int index = 0;
    scanf("%c", &str[index]);
    while (index < LINE && str[index] != '\n' && str[index] != '\r') {
        index++;
        if (scanf("%c", &str[index]) == EOF)
            return 0;
    }

    str[index] = '\0';
    return (index + 1);
}

int getWord(char word[]) {
    int index = 0;
    scanf("%c", &word[index]);
    while (index < WORD && word[index] != '\n' && word[index] != '\t' && word[index] != ' ' && word[index] != '\r') {
        index++;
        if (scanf("%c", &word[index]) == EOF) return 0;
    }
    word[index] = '\0';
    return (index + 1);
}

int substring(char *str1, char *str2) {
    if (strlen(str1) < strlen(str2))
        return 0;
    for (int i, j = 0; j < strlen(str1); j++) {

        if (str1[j] == str2[0]) {
            i = 1;
            while (i < strlen(str2) && (j + i) < strlen(str1) && str1[i + j] == str2[i])
                i++;
            if (i == strlen(str2))
                return 1;
        }
    }
    return 0;
}


int similar(char *s, char *t) {
    int count = 0;
    if (strlen(s) != strlen(t) + 1)
        return 0;
    for (int i, j = 0; j < strlen(s) && i < strlen(t); j++) {
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
    for (int i = 0; i < MAXLINES; i++) {
        size = getLine(line);
        if (size == 0)
            break;
        if (substring(line, str) == 1)
            printf("%s\n", line);
    }
}

void printSimilarWords(char *str) {
    char word[WORD] = {0};
    int size;
    for (int i = 0; i < MAXLINES; i++) {
        size = getWord(word);
        if (size == 0)
            break;
        if (similar(word, str) == 1 || strcmp(word, str) == 0)
            printf("%s\n", word);
    }
}