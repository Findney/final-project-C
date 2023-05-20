// Mengbungkan dengan header file telah dibuat
#include "header.h"


// Fungsi untuk melakukan swab 
void swap(Score *a, Score *b) {
    Score temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk menentukan pivot
int partition(Score *score_info, int left, int right) {
    int pivot = score_info[right].score;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (score_info[j].score >= pivot) {
            i++;
            swap(&score_info[i], &score_info[j]);
        }
    }

    swap(&score_info[i + 1], &score_info[right]);
    return i + 1;
}

// Fungsi untuk melakukan sorting nilai numerik
void quick_sort(Score *score_info, int left, int right) {
    if (left < right) {
        int partition_index = partition(score_info, left, right);

        quick_sort(score_info, left, partition_index - 1);
        quick_sort(score_info, partition_index + 1, right);
    }
}

