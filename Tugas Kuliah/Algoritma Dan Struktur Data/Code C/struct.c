#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100

// Definisi struct Mahasiswa
struct Mahasiswa {
    char nim[20];
    char nama[50];
    char alamat[100];
    float ipk;
};

// Deklarasi array untuk menyimpan data mahasiswa
struct Mahasiswa dataMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("\nMenu:\n");
    printf("1. Lihat semua data mahasiswa\n");
    printf("2. Masukkan 1 data mahasiswa\n");
    printf("3. Masukkan 3 data mahasiswa\n");
    printf("4. Lihat data mahasiswa yang memiliki IPK < 3.00\n");
    printf("5. Lihat data mahasiswa berdasarkan urutan NIM ascending\n");
    printf("6. Edit data mahasiswa\n");
    printf("0. Exit\n");
    printf("Pilihan Anda: ");
}

// Fungsi untuk menampilkan semua data mahasiswa
void lihatSemuaData() {
    printf("\nData Mahasiswa:\n");
    if (jumlahMahasiswa == 0) {
        printf("Tidak ada data mahasiswa\n");
        return;
    }
    printf("%-20s %-30s %-50s %-10s\n", "NIM", "Nama", "Alamat", "IPK");
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        printf("%-20s %-30s %-50s %-10.2f\n", dataMahasiswa[i].nim, dataMahasiswa[i].nama, dataMahasiswa[i].alamat, dataMahasiswa[i].ipk);
    }
}

// Fungsi untuk memasukkan data mahasiswa
void masukkanData() {
    if (jumlahMahasiswa >= MAX_MAHASISWA) {
        printf("Kapasitas maksimal data mahasiswa telah tercapai.\n");
        return;
    }
    struct Mahasiswa mhs;
    printf("\nMasukkan data mahasiswa:\n");
    printf("NIM: ");
    scanf("%s", mhs.nim);
    printf("Nama: ");
    scanf(" %[^\n]s", mhs.nama);
    printf("Alamat: ");
    scanf(" %[^\n]s", mhs.alamat);
    printf("IPK: ");
    scanf("%f", &mhs.ipk);

    dataMahasiswa[jumlahMahasiswa++] = mhs;
    printf("Data mahasiswa berhasil dimasukkan.\n");
}

// Fungsi untuk melihat data mahasiswa dengan IPK < 3.00
void lihatDataIPK() {
    printf("\nData Mahasiswa dengan IPK < 3.00:\n");
    printf("%-20s %-30s %-50s %-10s\n", "NIM", "Nama", "Alamat", "IPK");
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        if (dataMahasiswa[i].ipk < 3.00) {
            printf("%-20s %-30s %-50s %-10.2f\n", dataMahasiswa[i].nim, dataMahasiswa[i].nama, dataMahasiswa[i].alamat, dataMahasiswa[i].ipk);
        }
    }
}

// Fungsi untuk membandingkan NIM untuk pengurutan
int compareNIM(const void *a, const void *b) {
    return strcmp(((struct Mahasiswa*)a)->nim, ((struct Mahasiswa*)b)->nim);
}

// Fungsi untuk melihat data mahasiswa berdasarkan urutan NIM ascending
void lihatDataUrutanNIM() {
    printf("\nData Mahasiswa berdasarkan urutan NIM ascending:\n");
    printf("%-20s %-30s %-50s %-10s\n", "NIM", "Nama", "Alamat", "IPK");

    // Mengurutkan data mahasiswa berdasarkan NIM
    qsort(dataMahasiswa, jumlahMahasiswa, sizeof(struct Mahasiswa), compareNIM);

    // Menampilkan data yang sudah diurutkan
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        printf("%-20s %-30s %-50s %-10.2f\n", dataMahasiswa[i].nim, dataMahasiswa[i].nama, dataMahasiswa[i].alamat, dataMahasiswa[i].ipk);
    }
}

// Fungsi untuk mengedit data mahasiswa
void editData() {
    char nim[20];
    printf("\nMasukkan NIM mahasiswa yang ingin di-edit: ");
    scanf("%s", nim);

    int found = 0;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        if (strcmp(dataMahasiswa[i].nim, nim) == 0) {
            printf("Masukkan data baru:\n");
            printf("NIM: ");
            scanf("%s", dataMahasiswa[i].nim);
            printf("Nama: ");
            scanf(" %[^\n]s", dataMahasiswa[i].nama);
            printf("Alamat: ");
            scanf(" %[^\n]s", dataMahasiswa[i].alamat);
            printf("IPK: ");
            scanf("%f", &dataMahasiswa[i].ipk);
            printf("Data mahasiswa berhasil di-edit.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Data mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
    }
}

int main() {
    // Inisialisasi 2 data statis mahasiswa
    struct Mahasiswa mhs1 = {};
   
  

    int pilihan;
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihatSemuaData();
                break;
            case 2:
                masukkanData();
                break;
            case 3:
                for (int i = 0; i < 3; ++i) {
                    masukkanData();
                }
                break;
            case 4:
                lihatDataIPK();
                break;
            case 5:
                lihatDataUrutanNIM();
                break;
            case 6:
                editData();
                break;
            case 0:
                printf("Terima kasih telah menggunakan program ini. Sampai jumpa!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}