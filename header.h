#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 20 // konstanta untuk ukuran nama file
#define MAX_LINE_LENGTH 2000 // konstanta untuk ukuran panjang line

// Struktur data untuk menyimpan informasi tentang kata
typedef struct {
    double score;
    int word_count;
    struct WordInfo {
        int length;
        char* word;
    }* words;
} Score;

// Fungsi untuk memberishkan layar saat program dijalankan
void system_clear();

// Fungsi untuk membuka file input, membaca baris per baris, dan menghapus tanda baca serta mengubah huruf menjadi huruf kecil
void process_file(char* text_filename, Score* score_info);

// Fungsi untuk menghitung skor kata
int calculate_score(char* word);

// Fungsi untuk mengurutkan Score berdasarkan skor (descending order)
void quick_sort(Score *score_info, int left, int right);

// Fungsi untuk mengurutkan kata sesuai dengan abjad
void sort_words_alphabetically(Score* score_info);

// Fungsi untuk menyimpan score ke file biner
void save_to_binary_file(char* binary_filename, Score* score_info);

// Fungsi untuk membaca Score dari file binari dan menampilkan n kata dengan skor terbesar ke layar monitor
void read_from_binary_file(char* open_binary_file, Score* score_info_bin);

// Fungsi untuk mencetak hasil pada layar
void print_score(int* n, Score* Score_info_bin);

// Fungsi untuk menampilkan menu dan meminta pilihan dari user
int get_menu_choice();

#endif /* __HEADER_H__ */
