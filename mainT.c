#include <stdio.h>
#include "txtfind.h"

#define WORD 30


int main() {
    char word[WORD] = {0};
    getWord(word);
    char function[WORD] = {0};
    getWord(function);
    if (function[0] == 'a')
        printLines(word);
    if (function[0] == 'b')
        printSimilarWords(word);
    return 0;
}