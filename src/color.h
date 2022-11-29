/* File color.h */
#ifndef COLOR_H
#define COLOR_H

#define MERAH printf("\033[31m")
#define BIRU printf("\033[34m")
#define KUNING printf("\033[33m")
#define HIJAU printf("\033[32m")
#define UNGU printf("\033[35m")
#define CYAN printf("\033[36m")
#define PUTIH printf("\033[37m")
#define HITAM printf("\033[30m")

#define BACKGROUND_MERAH printf("\033[41m")
#define BACKGROUND_BIRU printf("\033[44m")
#define BACKGROUND_KUNING printf("\033[43m")
#define BACKGROUND_HIJAU printf("\033[42m")
#define BACKGROUND_UNGU printf("\033[45m")
#define BACKGROUND_CYAN printf("\033[46m")
#define BACKGROUND_PUTIH printf("\033[47m")
#define BACKGROUND_HITAM printf("\033[40m")

#define RESET printf("\033[0m") /* reset warna menjadi warna semua pada console */
/* selalu dipakai saat telah mengubah warna */

#endif