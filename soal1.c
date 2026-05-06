/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : 4 - Dynamic Structure 
*   Hari dan Tanggal    : Senin, 6 Mei 2026
*   Nama (NIM)          : Jeva Steve Sinaga (13224002)
*   Nama File           : soal1.c
*   Deskripsi           :   Sebuah terminal medis orbit menangani pasien berdasarkan urutan kedatangan. Setiap pasien
                            membutuhkan durasi pelayanan yang berbeda. Untuk mengevaluasi efisiensi pelayanan, manajemen
                            terminal ingin mengetahui urutan pasien yang diproses serta total waktu tunggu seluruh antrean. Anda
                            diminta mensimulasikan antrean tersebut sesuai aturan layanan yang berlaku.
                            Simulasikan antrean pasien dan hitung total waktu tunggu.
                            EL2008 Pemecahan Masalah dengan Pemrograman - Laboratorium Dasar Teknik Elektro - STEI ITB |
                            2
                            Kondisi/Aturan:
                                1. Pasien diproses sesuai urutan datang
                                2. Waktu tunggu pasien pertama = 0
                                3. Waktu tunggu pasien berikutnya = total durasi semua pasien sebelumnya
                                4. Cetak urutan ID dan total waktu tunggu seluruh pasien
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pasien {
    char id[100];
    int durasi;
    struct Pasien* next;
} Pasien;


int main() {
    int n;
    scanf("%d", &n);

    Pasien* head = NULL;
    Pasien* tail = NULL;

    for (int i = 0; i < n; i++) {
        Pasien* newPasien = (Pasien*)malloc(sizeof(Pasien));
        scanf("%s %d", newPasien->id, &newPasien->durasi);
        newPasien->next = NULL;

        if (head == NULL) {
            head = newPasien;
            tail = newPasien;
        } else {
            tail->next = newPasien;
            tail = newPasien;
        }
    }

    printf("ORDER");
    int waktutunggu = 0;
    int waktutemp = 0;
    Pasien* current = head;
    while (current != NULL) {
        printf(" %s", current->id);
        waktutunggu += waktutemp;
        waktutemp += current->durasi;
        current = current->next;
    }
    printf("\nWAIT %d\n", waktutunggu);

    current = head;
    while (current != NULL) {
        Pasien* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
