#include <stdio.h>
#include <string.h>

// Fungsi untuk menukar nilai dua elemen dalam array
void tukar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mencetak array
void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Fungsi untuk mengurutkan kartu dan mengembalikan jumlah minimum pertukaran
int urutKartu(char kartu[], int size) {
    int minTukar = 0;

    // Loop untuk setiap elemen di array
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Temukan indeks elemen terkecil dari sisa array
        for (int j = i + 1; j < size; j++) {
            // Membuat urutan "1-10-J-Q-K"
            char urutan[] = "123456789JQK";
            if (strchr(urutan, kartu[j]) < strchr(urutan, kartu[minIndex])) {
                minIndex = j;
            }
        }

        // Jika elemen terkecil tidak di posisi saat ini, tukar mereka
        if (minIndex != i) {
            tukar(&kartu[i], &kartu[minIndex]);
            minTukar++; // Tambahkan jumlah pertukaran
            printf("Pertukaran ke-%d: ", minTukar);
            printArray(kartu, size);
        }
    }

    return minTukar;
}

int main() {
    int noKartu;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &noKartu);

    char kartu[noKartu];
    printf("Masukkan nilai kartu : ");
    for (int i = 0; i < noKartu; i++) {
        scanf(" %c", &kartu[i]);
    }

    int minTukar = urutKartu(kartu, noKartu);

    printf("Jumlah minimum pertukaran: %d\n", minTukar);

    return 0;
}