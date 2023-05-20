#include <stdio.h>

int get_menu_choice() {
    int pilihan;

    /*printf("\033[2J"); // membersihkan layar*/
    printf("\033[1;33m"); // mengubah warna teks menjadi kuning
    printf("=======================================\n");
    printf("||========> COUNT WORD SCORE <=======||\n");
    printf("=======================================\n");
    printf("\n");
    printf("\033[0m"); // mereset warna teks

    printf("\033[1;36m"); // mengubah warna teks menjadi biru terang
    printf("Menu Options:\n");
    printf("\033[0m"); // mereset warna teks

    printf("\033[1;32m"); // mengubah warna teks menjadi hijau terang
    printf("1. Save sorted data\n");
    printf("2. Show n highest score\n");
    printf("3. Exit\n");
    printf("\033[0m"); // mereset warna teks

    printf("\033[1;36m"); // mengubah warna teks menjadi biru terang
    printf("Enter your choice: ");
    printf("\033[0m"); // mereset warna teks
    scanf("%d", &pilihan);

    return pilihan;
}
    
