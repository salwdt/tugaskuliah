#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk menyimpan pesanan
struct Pesanan {
    int id;
    string namaPelanggan;
    string waktuPemesanan; // Format waktu: "YYYY-MM-DD HH:MM:SS"
};

// Fungsi untuk mencetak array pesanan
void cetakPesanan(Pesanan pesanan[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "ID: " << pesanan[i].id
             << ", Nama: " << pesanan[i].namaPelanggan
             << ", Waktu: " << pesanan[i].waktuPemesanan << endl;
    }
}

// Fungsi untuk membandingkan waktu pemesanan (format string)
bool compareWaktu(const string &waktu1, const string &waktu2) {
    return waktu1 <= waktu2; // Menggunakan perbandingan string secara leksikografis
}

// Fungsi Merge untuk menggabungkan dua subarray
void merge(Pesanan pesanan[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
// Nandita Salwa Utarie ( 241011401425 )

    Pesanan L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = pesanan[left + i];
    for (int i = 0; i < n2; i++) R[i] = pesanan[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compareWaktu(L[i].waktuPemesanan, R[j].waktuPemesanan))
            pesanan[k++] = L[i++];
        else
            pesanan[k++] = R[j++];
    }

    while (i < n1) pesanan[k++] = L[i++];
    while (j < n2) pesanan[k++] = R[j++];
}

// Fungsi Merge Sort
void mergeSort(Pesanan pesanan[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(pesanan, left, mid);
    mergeSort(pesanan, mid + 1, right);
    merge(pesanan, left, mid, right);
}

int main() {
    // Dataset pesanan
    Pesanan pesanan[] = {
        {101, "Nandita", "2025-01-04 14:25:30"},
        {102, "Salwa", "2025-01-04 09:15:45"},
        {103, "Utarie", "2025-01-04 12:05:10"},
        {104, "Angela", "2025-01-04 16:45:00"},
        {105, "Zhuxin", "2025-01-04 08:30:25"}
    };

    int size = sizeof(pesanan) / sizeof(pesanan[0]);

    cout << "Data pesanan sebelum diurutkan:" << endl;
    cetakPesanan(pesanan, size);

    // Mengurutkan pesanan menggunakan Merge Sort
    mergeSort(pesanan, 0, size - 1);

    cout << "\nData pesanan setelah diurutkan berdasarkan waktu pemesanan:" << endl;
    cetakPesanan(pesanan, size);

    return 0;
}

