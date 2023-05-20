// Menghubungkan dengan header yang telah dibuat
#include "header.h"

int main (){

    // Fungsi untuk membersihkan layar
    system_clear();

    // Deklarasi untuk menyimpan nama file input dari user
    char text_filename[MAX_FILENAME_LENGTH], binary_filename[MAX_FILENAME_LENGTH];

    // Input nama file text
    printf("Enter the text file name (txt): ");
    scanf("%s", text_filename);

    // Deklarasi dan mengalokasikan memori untuk score_info
    Score* score_info = (Score*) malloc(MAX_LINE_LENGTH * sizeof(Score));
    if (score_info == NULL) {
        printf("Failed to allocate memory!\n");
        return EXIT_FAILURE;
    }

    // Fungsi untuk menginisialisasi memori yang dialokasikan dengan nilai nol
    memset(score_info, 0, MAX_LINE_LENGTH * sizeof(Score));

    // Deklarasi dan mengalokasikan memori untuk score_info_bin
    Score* score_info_bin = (Score*) malloc(MAX_LINE_LENGTH * sizeof(Score));
    if (score_info_bin == NULL){
        printf("Failed to allocate memory!\n");
        return EXIT_FAILURE;
    }

    // Fungsi untuk menginisialisasi memori yang dialokasikan dengan nilai nol
    memset(score_info_bin, 0, MAX_LINE_LENGTH * sizeof(Score));

    // Fungsi untuk memproses file dan hitung skor kata
    process_file(text_filename, score_info);

    // Fungsi untuk mengurutkan kata sesuai abjad
    sort_words_alphabetically(score_info);

    // Fungsi mengurutkan skor berdasarkan descending 
    quick_sort(score_info, 0, MAX_LINE_LENGTH - 1);

    // Fungsi untuk membersihkan layar
    system_clear();

    // Deklarasi variabel untuk menampung nilai untuk melakukan looping
    int choice, choice_1 = 0;

    // Looping pilihan menu
    do {
        choice = get_menu_choice(); // Fungsi untuk mendapatkan nilai dari pilihan menu
        
        // pengecekan case sesuai pilihan dari user
        switch (choice) {

            case 1: {

                // Input nama file binari untuk menyimpan hasil skoring
                printf("Enter the binary file name to save the data: ");
                scanf("%s", binary_filename);

                // Fungsi untuk menyimpan hasil ke dalam file binari
                save_to_binary_file(binary_filename, score_info);
                
                // Mencetak pesan untuk menginfokan hasil telah disimpan di dalam file binari
                printf("Score info saved to %s\n", binary_filename);

                // Menambah nilai untuk variabel choice_1 agar dapat memilih pilihan menu 2
                choice_1 ++;

                // Jeda program saat berjalan agar lebih interaktif 
                printf("\033[1mPress enter to continue!\033[0m\n");
                // Fungsi untuk memastikan agar pesan segera ditampilkan
                fflush(stdout); 
                // Fungsi untuk mengambil karakter 
                getchar();
                // Looping untuk membaca karakter dari input pengguna hingga karakter '\n'
                int c;
                do {
                c = getchar();
                } while (c != '\n');
                // Fungsi untuk membersihkan layar
                system_clear();
                // Melanjutkan iterasi berikutnya
                continue;
            }
            case 2: {
                // Memastikan agar pilihan satu telah dipilih sebelumnya 
                if (choice_1 == 0){
                    printf("Please select option one first!\n");
                    printf("\033[1mPress enter to continue!\033[0m\n");
                    fflush(stdout);
                    getchar();
                    int c;
                    do {
                    c = getchar();
                    } while (c != '\n');
                    system_clear();
                    continue;
                }
               
                // Deklarasi untuk menyimpan nama file binari yang ingin dibuka
                char open_binary_file[MAX_FILENAME_LENGTH];
                printf("Enter the binary file name: ");
                scanf("%s", open_binary_file);
               
                // Fungsi untuk membaca file binari 
                read_from_binary_file(open_binary_file, score_info_bin);

                // Looping untuk meminta n score untuk ditampilkan
                int n;
                do {
                printf("Enter n highest score to display (0<n<=40): ");
                scanf("%d", &n);
                if (n < 0 || n > 40)
                    printf("\033[1mInvalid n value! (0<n<=40)\033[0m\n");
                }while (n < 0 || n > 40);

                printf("\nResult of %d highest score: \n", n);

                // Fungsi untuk mencetak hasil pada layar
                print_score(&n, score_info_bin);


                // Jeda program saat berjalan agar lebih interaktif
                printf("\n\033[1mPress enter to continue!\033[0m\n");
                fflush(stdout);
                getchar();
                int c;
                do {
                c = getchar();
                } while (c != '\n');
                system_clear();
                continue;
            }
            case 3: {

                printf("Thank you for using our app. \n\033[1mGoodbye!\033[0m\n");
                fflush(stdout);

                // Fungsi untuk membersihkan memori 
                free(score_info);
                free(score_info_bin);

                // Menghentikan jalannya seluruh program
                break;
            }
            default: {
                // Pesan apabila input yang dimasukkan tidak sesuai
                printf("\033[1mInvalid choice!\033[0m\n");
                printf("Press enter to continue!\n");
                fflush(stdout);
                int c;
                do {
                c = getchar();
                } while (c != '\n');
                getchar();
                system_clear();
                continue;
            }
        }
    } while (choice != 3); // Melakukan looping selama pilihan tidak sama dengan 3

    return 0;
}
