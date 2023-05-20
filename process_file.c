#include "header.h"

#define DELIMETER " \n"

void process_file(char* text_filename, Score* score_info) {

    FILE* fp = fopen(text_filename, "r");
    if (fp == NULL) {
        printf("File not found or cannot be opened!\n");
        exit(EXIT_FAILURE);
    }
   
    char line[MAX_LINE_LENGTH];
    char* token;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Hapus tanda baca dan ubah menjadi huruf kecil
        for (int i = 0, len = strlen(line); i < len; i++) {
            if (ispunct(line[i])) {
                line[i] = ' ';
            }
            line[i] = tolower(line[i]);
        }

       // Ambil kata-kata dari setiap baris
       token = strtok(line, DELIMETER);
       while (token != NULL) {
       int token_score = calculate_score(token);
       if (token_score > 0) {
            // Cek apakah sudah ada skor yang sama
            int i;
            for (i = 0; i < MAX_LINE_LENGTH; i++) {
                if (score_info[i].score == token_score) {
                break;
                }
            }
            if (i == MAX_LINE_LENGTH) { // Belum ada skor yang sama
               score_info[token_score].word_count = 0;
               score_info[token_score].score = token_score;
               score_info[token_score].words = NULL;
            }
           // Cek apakah sudah ada kata dengan skor yang sama
           int j;
           for (j = 0; j < score_info[token_score].word_count; j++) {
                if (strcmp(score_info[token_score].words[j].word, token) == 0) {
                break;
                }
           }
           if (j == score_info[token_score].word_count) { // Belum ada kata dengan skor yang sama
              score_info[token_score].word_count++;
              score_info[token_score].words = realloc(score_info[token_score].words, sizeof(struct WordInfo) * score_info[token_score].word_count);
              score_info[token_score].words[score_info[token_score].word_count - 1].word = strdup(token);
              score_info[token_score].words[score_info[token_score].word_count - 1].length = strlen(token);
           }
         }
        token = strtok(NULL, DELIMETER);
        }
    }

    fclose(fp);
}

