#include "txtfind.h"

#define WORD 30

int main() {

    char word1[WORD] = {0}, word2[WORD] = {0};

    getWord(word1);
    getWord(word2);

    if (word2[0] == 'a')
        printLines(word1);
    if (word2[0] == 'b')
        printSimilarWords(word1);

    return 0;
}