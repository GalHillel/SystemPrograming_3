#include <stdio.h>
#include "txtfind.h"

#define WORD 30

int main() {
    char word[WORD] = {0};
    getword(word);
    char function[WORD] = {0};
    getword(function);
    if (function[0] == 'a')
        print_lines(word);
    if (function[0] == 'b')
        print_similar_words(word);
    return 0;
}