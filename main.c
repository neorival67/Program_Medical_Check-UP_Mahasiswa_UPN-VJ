#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100000 // Maksimum jumlah data pasien yang dapat disimpan

struct mahasiswa {
    char nama[100];
    char nim[20];
    char fakultas[100];
    char prodi[100];
    int usia;
    float bb;
    float tinggi;
    char jenis_kelamin[10];
    char riwayat_penyakit[100];
};

struct mahasiswa data_mahasiswa[MAX_MAHASISWA]; // Array untuk menyimpan data pasien
int hitung_mahasiswa = 0; // Jumlah pasien yang terdaftar

// Fungsi untuk menambahkan data pasien ke dalam array
void tambah_mahasiswa() {

  system("clear");
    while (hitung_mahasiswa < MAX_MAHASISWA) {
        struct mahasiswa mahasiswa;
        printf("==========================\n");
        printf("Pendaftaran Data Mahasiswa\n");
        printf("==========================\n");

        printf("\nMasukkan nama mahasiswa: ");
        scanf(" %[^\n]s", mahasiswa.nama);

        printf("\nMasukkan nim mahasiswa: ");
        scanf(" %s", mahasiswa.nim);

        printf("\nMasukkan fakultas mahasiswa: ");
        scanf(" %[^\n]s", mahasiswa.fakultas);

        printf("\nMasukkan prodi mahasiswa: ");
        scanf(" %[^\n]s", mahasiswa.prodi);

        printf("\nMasukkan jenis kelamin mahasiswa: ");
        scanf(" %[^\n]s", mahasiswa.jenis_kelamin);

        printf("\nMasukkan usia mahasiswa: ");
        scanf("%d", &mahasiswa.usia);

        printf("\nMasukkan berat badan mahasiswa(kg): ");
        scanf("%f", &mahasiswa.bb);

        printf("\nMasukkan tinggi mahasiswa(cm): ");
        scanf("%f", &mahasiswa.tinggi);

        printf("\nMasukkan riwayat penyakit mahasiswa: ");
        scanf(" %[^\n]s", mahasiswa.riwayat_penyakit);

        data_mahasiswa[hitung_mahasiswa ++] = mahasiswa;
        printf("Data mahasiswa berhasil ditambahkan.\n");

        printf("\nApakah Anda ingin menambahkan data mahasiswa lagi? (1: Ya, 0: Tidak): ");
        int lanjut;
        scanf("%d", &lanjut);
        if (!lanjut) {
            break; 
        }
        getchar();
    } 
        if (hitung_mahasiswa >= MAX_MAHASISWA) {
            printf("Kapasitas maksimum pendaftaran telah tercapai.\n");
        }
}

// Fungsi untuk menampilkan semua data pasien
void tampilkan_mahasiswa() {

  system("clear");
    printf("Data mahasiswa yang terdaftar:\n");
    for (int i = 0; i < hitung_mahasiswa; i++) {
        printf("Nama: %s  | NIM: %s  | Fakultas: %s | Prodi: %s | Usia: %d  | Berat Badan : %.2f | Tinggi: %.2f | Jenis Kelamin: %s | Riwayat Penyakit: %s  \n", data_mahasiswa[i].nama, data_mahasiswa[i].nim, data_mahasiswa[i].fakultas, data_mahasiswa[i].prodi, data_mahasiswa[i].usia, data_mahasiswa[i].bb, data_mahasiswa[i].tinggi, data_mahasiswa[i].jenis_kelamin, data_mahasiswa[i].riwayat_penyakit );
    }
}

// Algoritma sorting (Bubble Sort) untuk mengurutkan data pasien berdasarkan nama
void sorting_data() {

    struct mahasiswa temp;
    for (int i = 0; i <hitung_mahasiswa - 1; i++) {
        for (int j = 0; j < hitung_mahasiswa - i - 1; j++) {
            if (strcmp(data_mahasiswa[j].nim, data_mahasiswa[j + 1].nim) > 0) {
                temp = data_mahasiswa[j];
                data_mahasiswa[j] = data_mahasiswa[j + 1];
                data_mahasiswa[j + 1] = temp;
            }
        }
    }
    printf("Data mahasiswa telah diurutkan berdasarkan nim:\n");
    tampilkan_mahasiswa();
}

// Algoritma searching (Sequential Search) untuk mencari data pasien berdasarkan nama
void cari_mahasiswa() {
    char nim_cari[100];
    printf("Masukkan NIM mahasiswa yang ingin dicari: ");
    scanf(" %s", nim_cari);
    int ketemu = 0;
    for (int i = 0; i < hitung_mahasiswa; i++) {
        if (strcmp(data_mahasiswa[i].nim, nim_cari) == 0) {
             printf("Data mahasiswa yang ditemukan:\n");
             printf("Nama: %s  | NIM: %s  | Fakultas: %s | Prodi: %s | Usia: %d  | Berat Badan : %.2f | Tinggi: %.2f | Jenis Kelamin: %s | Riwayat Penyakit: %s  \n",
                data_mahasiswa[i].nama, data_mahasiswa[i].nim, data_mahasiswa[i].fakultas, data_mahasiswa[i].prodi, data_mahasiswa[i].usia,
                data_mahasiswa[i].bb, data_mahasiswa[i].tinggi, data_mahasiswa[i].jenis_kelamin, data_mahasiswa[i].riwayat_penyakit);
            ketemu = 1;
            break;
        }
    }
    if (!ketemu) {
        printf("Data mahasiswa dengan NIM '%s' tidak ditemukan.\n", nim_cari);
    }
}


// Fungsi utama
int main() { 
    int pilihan;
    while (1) {
        printf("==========================================\n");
        printf("  Menu Medical Check Up Mahasiswa UPN-VJ\n");
        printf("==========================================\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Urutkan Data Mahasiswa Berdasarkan Nim\n");
        printf("4. Cari Data Mahasiswa\n");
        printf("5. Keluar\n");

        printf("Masukkan pilihan Anda (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambah_mahasiswa();
                break;
            case 2:
                tampilkan_mahasiswa();
                break;
            case 3:
                sorting_data();
                break;
            case 4:
                cari_mahasiswa();
                break;
            case 5:
                printf("Terima kasih! Program selesai.\n");
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan pilih angka 1-5.\n");
        }
        printf("\nTekan tombol apapun untuk melanjutkan...\n");
        getchar();
        getchar(); // Tunggu masukan sebelum membersihkan layar
        system("clear"); // Membersihkan layar
    }

    return 0;
}