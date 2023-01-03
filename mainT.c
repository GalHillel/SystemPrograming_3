#include <stdio.h>
#include "txtfind.h"

#define word 30

int main() {
    char in;
    char s[word];
    getword(s);
    scanf("%c\n", &in);
    if (in == 'a') {
        print_lines(s);
    }
    if (in == 'b') {
        print_similar_words(s);
    }
    return 0;
}