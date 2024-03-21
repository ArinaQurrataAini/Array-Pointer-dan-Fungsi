#include <stdio.h>

// Fungsi untuk mencetak papan catur
void printBoard(int *chessBoard, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *((chessBoard+i*size) + j));
        }
        printf("\n");
    }
}

// Fungsi untuk menandai posisi yang dapat dicapai oleh bidak kuda
void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Gerakan bidak kuda
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (int k = 0; k < 8; k++) {
        int x = i + moves[k][0];
        int y = j + moves[k][1];

        // Cek apakah posisi berada di dalam papan catur
        if (x >= 0 && x < size && y >= 0 && y < size) {
            *((chessBoard+x*size) + y) = 1;
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);

    int size = 8;
    int chessBoard[size][size];

    // Inisialisasi papan catur dengan 0
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            chessBoard[x][y] = 0;
        }
    }

    // Menandai posisi yang dapat dicapai oleh bidak kuda
    koboImaginaryChess(i, j, size, (int *)chessBoard);

    // Mencetak papan catur
    printBoard((int *)chessBoard, size);

    return 0;
}
