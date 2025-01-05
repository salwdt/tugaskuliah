#include <iostream>
#include <string>
using namespace std;

// Fungsi Merge Sort
void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
// Nandita Salwa Utarie ( 241011401425 )
    string L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(string arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Fungsi Binary Search
int binarySearch(string arr[], int size, string target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // Tidak ditemukan
}

int main() {
    // Dataset nama anggota TWICE (tidak diurutkan)
    string members[] = {"Mina", "Sana", "Chaeyoung", "Jihyo", "Tzuyu", "Nayeon", "Momo", "Dahyun", "Jeongyeon"};
    int size = sizeof(members) / sizeof(members[0]);

    // Urutkan dataset menggunakan Merge Sort
    mergeSort(members, 0, size - 1);
// Nandita Salwa Utarie ( 241011401425 )
    // Nama yang ingin dicari
    string target;
    cout << "Masukkan nama anggota TWICE yang ingin dicari: ";
    getline(cin, target);

    // Pencarian Binary Search setelah data diurutkan
    int result = binarySearch(members, size, target);

    // Output hasil pencarian
    if (result != -1)
        cout << "Anggota \"" << target << "\" ditemukan pada indeks " << result << " setelah data diurutkan." << endl;
    else
        cout << "Anggota \"" << target << "\" tidak ditemukan dalam dataset." << endl;

    return 0;
}

