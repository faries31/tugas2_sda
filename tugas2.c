#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000
#define MAX_WORDS 5000
#define MAX_LEN 50

char dataset[MAX_WORDS][MAX_LEN];
int word_count = 0;

// Function prototype
void generateRandom(int arr[]);
void displayData(int arr[]);
void bubbleSort(int arr[]);
void insertionSort(int arr[]);

void bacaFile();
void shuffleDataset();
void displayDataset();

void quickSort(int low, int high);
int partition(int low, int high);

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
               do {
                //submenu advance sorting
                printf("\n===== ADVANCE SORTING =====\n");
                printf("1. Merge Sort\n");
                printf("2. Quick Sort\n");
                printf("3. Shell Sort\n");
                printf("4. Kembali\n");
                printf("Pilih metode : ");
                scanf("%d", &metode);

                switch(metode) {
                    case 1:
                        printf("\nMerge Sort dikerjakan oleh orang 2.\n");
                        break;
                    case 2:
                        //baca data dari words.txt
                        printf("\nMembaca file dataset...\n");
                        bacaFile();

                        if (word_count == 0) {
                            break;
                        }

                        //melakukan shuffle sebelum sorting
                        printf("Melakukan shuffle dataset...\n");
                        shuffleDataset();

                        //menampilkan data sebelum sorting
                        printf("\nData sebelum sorting: \n");
                        displayDataset();

                        //hitung waktu eksekusi quick sort
                        clock_t start, end;
                        double waktu;

                        start = clock();

                        quickSort(0, word_count - 1);

                        end = clock();

                        //menampilkan data setelah sorting
                        printf("\nData setelah Quick Sort: \n");
                        displayDataset();

                        //menampilkan total waktu proses
                        waktu = ((double)(end - start)) / CLOCKS_PER_SEC;
                        printf("\nWaktu eksekusi Quick Sort : %f detik\n", waktu);
                        break;

                    case 3:
                        printf("\nShell Sort dikerjakan oleh orang 2.\n");
                        break;

                     case 4:
                         printf("\nKembali ke menu utama...\n");
                         break;

                    default:
                        printf("\nPilihan tidak valid!\n");
                }
               }
               while(metode != 4);
               break;

            case 3:
                printf("\nProgram selesai.\n");
                break;

            default:
                printf("\nPilihan tidak valid!\n");
        }

    } while(pilihan != 4);

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

//membaca dataset dari words.txt
void bacaFile(){
    FILE *file = fopen("words.txt", "r");
    word_count = 0;

    if (file == NULL) {
        printf("\nGagal membuka file words.txt!\n");
        return;
    }

    while (fscanf(file, "%s", dataset[word_count]) != EOF && word_count < MAX_WORDS) {
        word_count ++;
    }

    fclose(file);
}

//fungsi untuk menampilkan 10 kata pertama
void displayDataset(){
    if (word_count == 0) {
        printf("Dataset kosong atau belum dibaca.\n");
        return;
    }

    //menampilkan max 10 kata pertama
    for (int i = 0; i < 10 && i < word_count; i++) {
        printf("%s ", dataset[i]);
    } 
    printf("\n");
}

//fungsi untuk mengacak data set
void shuffleDataset(){
    char temp[MAX_LEN];
    
    for (int i = word_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        strcpy(temp, dataset[i]);
        strcpy(dataset[i], dataset[j]);
        strcpy(dataset[j], temp);
    }
}

//fungsi membantu quick sort membagi array berdasarkan pivot
int partition(int low, int high) {
    char pivot[MAX_LEN];
    strcpy(pivot, dataset[high]);

    int i = (low - 1);
    char temp[MAX_LEN];

    for (int j = low; j < high; j++) {
        //strcmp(a, b) < 0 artinya kata 'a' < 'b'
        if (strcmp(dataset[j], pivot) < 0) {
            i++;

             strcpy(temp, dataset[i]);
             strcpy(dataset[i], dataset[j]);
             strcpy(dataset[j], temp);
        }
    }
    //tukar posisi pivot ke tempat yang benar
    strcpy(temp, dataset[i + 1]);
    strcpy(dataset[i + 1], dataset[high]);
    strcpy(dataset[high], temp);

    return (i  + 1);
}

//fungsi utama quick sort 
void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        //sortir bagian kiri dan kana secara terpisah
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
