#include "header.h"


void print_score(int* n, Score* score_info_bin) {
    for (int i = 0; i < *n; i++) {
        if (score_info_bin[i].score > 0) {
            printf("%g {", score_info_bin[i].score);

            for (int j = 0; j < score_info_bin[i].word_count; j++) {
                printf("%s (%d)", score_info_bin[i].words[j].word, score_info_bin[i].words[j].length);

                if (j < score_info_bin[i].word_count - 1) {
                    printf(", ");
                }
            }

            printf("}\n");
        }
    }
}


