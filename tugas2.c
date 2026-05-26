#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// Function prototype
void generateRandom(int arr[]);
void displayData(int arr[]);
void bubbleSort(int arr[]);
void insertionSort(int arr[]);

int main() {
    int pilihan, metode;
    int data[SIZE];

    // Seed random number
    srand(time(NULL));

    do {
        // Menu utama
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Sorting Dasar\n");
        printf("2. Advance Sorting\n");
        printf("3. Keluar\n");
        printf("Pilih menu : ");
        scanf("%d", &pilihan);

        switch(pilihan) {

            case 1:
                do {
                    // Submenu sorting dasar
                    printf("\n===== SORTING DASAR =====\n");
                    printf("1. Bubble Sort\n");
                    printf("2. Insertion Sort\n");
                    printf("3. Selection Sort\n");
                    printf("4. Kembali\n");
                    printf("Pilih metode : ");
                    scanf("%d", &metode);

                    switch(metode) {

                        case 1:
                            // Generate data random
                            generateRandom(data);

                            printf("\nData sebelum sorting:\n");
                            displayData(data);

                            // Jalankan Bubble Sort
                            bubbleSort(data);

                            printf("\nData setelah Bubble Sort:\n");
                            displayData(data);
                            break;

                        case 2:
                            // Generate data random
                            generateRandom(data);

                            printf("\nData sebelum sorting:\n");
                            displayData(data);

                            // Jalankan Insertion Sort
                            insertionSort(data);

                            printf("\nData setelah Insertion Sort:\n");
                            displayData(data);
                            break;

                        case 3:
                            printf("\nSelection Sort dikerjakan anggota lain.\n");
                            break;

                        case 4:
                            printf("\nKembali ke menu utama...\n");
                            break;

                        default:
                            printf("\nPilihan tidak valid!\n");
                    }

                } while(metode != 4);
                break;

            case 2:
                printf("\nAdvance Sorting dikerjakan anggota lain.\n");
                break;

            case 3:
                printf("\nProgram selesai.\n");
                break;

            default:
                printf("\nPilihan tidak valid!\n");
        }

    } while(pilihan != 3);

    return 0;
}

// Generate 1000 data random
void generateRandom(int arr[]) {
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

// Menampilkan 10 data pertama
void displayData(int arr[]) {
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Algoritma Bubble Sort
void bubbleSort(int arr[]) {
    int temp;
    clock_t start, end;
    double waktu;

    // Mulai hitung waktu
    start = clock();

    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = 0; j < SIZE - i - 1; j++) {

            // Tukar jika data lebih besar
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Selesai hitung waktu
    end = clock();

    waktu = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nWaktu eksekusi Bubble Sort : %f detik\n", waktu);
}

// Algoritma Insertion Sort
void insertionSort(int arr[]) {
    int key, j;
    clock_t start, end;
    double waktu;

    // Mulai hitung waktu
    start = clock();

    for(int i = 1; i < SIZE; i++) {

        key = arr[i];
        j = i - 1;

        // Geser data lebih besar ke kanan
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    // Selesai hitung waktu
    end = clock();

    waktu = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nWaktu eksekusi Insertion Sort : %f detik\n", waktu);
}
