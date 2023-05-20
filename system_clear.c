#include "header.h"

void system_clear(){

#if defined(_WIN32) || defined(_WIN64)
    system("cls");  // Perintah untuk membersihkan layar pada Windows
#else
    system("clear");  // Perintah untuk membersihkan layar pada Unix/Linux
#endif

}
