#include <stdio.h>
#include <ctype.h>

int calculate_score(char *word) {
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        switch (tolower(word[i])) {
            case 'a': case 'e': case 'i': case 'l': case 'n': case 'o': case 'r': case 's': case 't': case 'u':
                score += 1;
                break;
            case 'd': case 'g':
                score += 2;
                break;
            case 'b': case 'c': case 'm': case 'p': case '0':
                score += 3;
                break;
            case 'f': case 'h': case 'v': case 'w': case 'y': case '1': case '2':
                score += 4;
                break;
            case 'k': case '3':
                score += 5;
                break;
            case '5': case '6':
                score += 6;
                break;
            case 'j': case 'x':
                score += 8;
                break;
            case '4':
                score += 9;
                break;
            case 'q': case 'z': case '8':
                score += 10;
                break;
            case '9':
                score += 12;
                break;
            case '7':
                score += 15;
                break;
        }
    }
    return score;
}  
