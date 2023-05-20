// Menghubungkan dengan header file yang telah dibuat
#include "header.h"

void read_from_binary_file(char* open_binary_file, Score* score_info_bin) {
    FILE* binary_fp = fopen(open_binary_file, "rb");

    if (binary_fp == NULL) {
        printf("File not found or cannot be opened!\n");
        exit(1);
    }

    int entry_count = 0; // Jumlah entri yang telah dibaca

    while (fread(&(score_info_bin[entry_count].score), sizeof(double), 1, binary_fp) == 1) {
        fread(&(score_info_bin[entry_count].word_count), sizeof(int), 1, binary_fp);

        score_info_bin[entry_count].words = (struct WordInfo*)malloc(score_info_bin[entry_count].word_count * sizeof(struct WordInfo));
        if (score_info_bin[entry_count].words == NULL) {
            printf("Failed to allocate memory for words!\n");
            exit(1);
        }

        for (int i = 0; i < score_info_bin[entry_count].word_count; i++) {
            fread(&(score_info_bin[entry_count].words[i].length), sizeof(int), 1, binary_fp);

            score_info_bin[entry_count].words[i].word = (char*)malloc((score_info_bin[entry_count].words[i].length + 1) * sizeof(char));
            if (score_info_bin[entry_count].words[i].word == NULL) {
                printf("Failed to allocate memory for word!\n");
                exit(1);
            }

            fread(score_info_bin[entry_count].words[i].word, sizeof(char), score_info_bin[entry_count].words[i].length, binary_fp);
            score_info_bin[entry_count].words[i].word[score_info_bin[entry_count].words[i].length] = '\0'; // Menambahkan karakter terminasi string
        }

        entry_count++;
    }

    fclose(binary_fp);
}

