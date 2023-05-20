// Menghubungkan dengan header file yang telah dibuat
#include "header.h"

void save_to_binary_file(char* binary_filename, Score* score_info) {
    FILE* binary_fp = fopen(binary_filename, "wb");

    if (binary_fp == NULL) {
        printf("Tidak dapat membuat file biner\n");
        return;
    }

    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        if (score_info[i].score > 0) {
            fwrite(&(score_info[i].score), sizeof(double), 1, binary_fp);
            fwrite(&(score_info[i].word_count), sizeof(int), 1, binary_fp);

            for (int j = 0; j < score_info[i].word_count; j++) {
                fwrite(&(score_info[i].words[j].length), sizeof(int), 1, binary_fp);
                fwrite(score_info[i].words[j].word, sizeof(char), score_info[i].words[j].length, binary_fp);
            }
        }
    }

    fclose(binary_fp);
}





