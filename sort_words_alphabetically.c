// Menghubungkan dengan header file yang telah dibuat
#include "header.h"

// Fungsi untuk mengurutkan kata sesuai dengan abjad
void sort_words(struct WordInfo* words, int word_count) {
    int i, j;
    char* temp_word;
    int temp_length;
    for (i = 0; i < word_count - 1; i++) {
        for (j = i + 1; j < word_count; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                // Tukar tempat kata
                temp_word = words[i].word;
                words[i].word = words[j].word;
                words[j].word = temp_word;

                // Tukar tempat panjang kata
                temp_length = words[i].length;
                words[i].length = words[j].length;
                words[j].length = temp_length;
            }
        }
    }

}


// Sort words alphabetically for each score
void sort_words_alphabetically(Score* score_info){
for (int i = 0; i < MAX_LINE_LENGTH; i++) {
         if (score_info[i].score > 0) {
             for (int j = 0; j < score_info[i].word_count; j++) {
                 sort_words(score_info[i].words, score_info[i].word_count);
             }
         }
     }
}


