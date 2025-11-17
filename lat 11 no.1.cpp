#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nama[70];
    char NIM[35];
    char gender[12];
    float nilai;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *head = NULL;

Mahasiswa* buatNode(char nama[], char NIM[], char gender[], float nilai) {
    Mahasiswa *baru = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    strcpy(baru->nama, nama);
    strcpy(baru->NIM, NIM);
    strcpy(baru->gender, gender);
    baru->nilai = nilai;
    baru->next = NULL;
    return baru;
}

void push(char nama[], char NIM[], char gender[], float nilai) {
    Mahasiswa *baru = buatNode(nama, NIM, gender, nilai);
    baru->next = head;
    head = baru;
    printf("\n Menambahkan data ke Stack...\n");
    printf(" Data berhasil ditambahkan!\n");
}

void pop() {
    if (head == NULL) {
        printf("\n Stack kosong, tidak ada data yang bisa dihapus.\n");
        return;
    }
    Mahasiswa *hapus = head;
    head = head->next;
    printf("\n Menghapus data teratas...\n");
    printf(" Data '%s' telah dihapus dari Stack.\n", hapus->nama);
    free(hapus);
}

void cetak() {
    if (head == NULL) {
        printf("\n Stack kosong, belum ada data mahasiswa.\n");
        return;
    }
    printf("\n Daftar Data Mahasiswa (dari atas ke bawah):\n");
    printf("------------------------------------------------------------\n");
    Mahasiswa *temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("%d. Nama   : %s\n", i, temp->nama);
        printf("   NIM    : %s\n", temp->NIM);
        printf("   Gender : %s\n", temp->gender);
        printf("   Nilai  : %.2f\n", temp->nilai);
        printf("------------------------------------------------------------\n");
        temp = temp->next;
        i++;
    }
}

int main() {
    int pilih;
    char nama[70], NIM[35], gender[12];
    float nilai;

    do {
        printf("\n===== PROGRAM STACK (DENGAN HEAD) =====\n");
        printf("1. INSERT DATA\n");
        printf("2. HAPUS DATA\n");
        printf("3. CETAK DATA\n");
        printf("4. EXIT\n");
        printf("Pilih menu [1-4]: ");
        scanf("%d", &pilih);
        getchar(); 

        switch (pilih) {
            case 1:
                printf("\n--- INPUT DATA MAHASISWA ---\n");
                printf("Nama Mahasiswa       : ");
                fgets(nama, sizeof(nama), stdin); nama[strcspn(nama, "\n")] = '\0';
                printf("NIM                  : ");
                fgets(NIM, sizeof(NIM), stdin); NIM[strcspn(NIM, "\n")] = '\0';
                printf("Gender (L/P)         : ");
                fgets(gender, sizeof(gender), stdin); gender[strcspn(gender, "\n")] = '\0';
                printf("Nilai Struktur Data  : ");
                scanf("%f", &nilai);
                getchar();
                push(nama, NIM, gender, nilai);
                break;

            case 2:
                pop();
                break;

            case 3:
                cetak();
                printf("Tekan ENTER untuk kembali ke menu...");
                getchar();
                break;

            case 4:
                printf("\nTerima kasih telah menggunakan program ini\n");
                break;

            default:
                printf("\nPilihan tidak valid, coba lagi\n");
        }
    } while (pilih != 4);

    return 0;
}

