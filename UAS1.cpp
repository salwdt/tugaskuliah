#include <iostream>
#include <string>
using namespace std;

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
// Nandita Salwa Utarie ( 241011401425 )

int main() {
    // Dataset nama anggota TWICE (sudah diurutkan alfabetis)
    string members[] = {"Chaeyoung", "Dahyun", "Jeongyeon", "Jihyo", "Mina", "Momo", "Nayeon", "Sana", "Tzuyu"};
    int size = sizeof(members) / sizeof(members[0]);

    // Nama yang ingin dicari
    string target;
    cout << "Masukkan nama anggota TWICE yang ingin dicari: ";
    getline(cin, target);

    // Pencarian Binary Search
    int result = binarySearch(members, size, target);

    // Output hasil pencarian
    if (result != -1)
        cout << "Anggota \"" << target << "\" ditemukan pada indeks " << result << " dalam dataset." << endl;
    else
        cout << "Anggota \"" << target << "\" tidak ditemukan dalam dataset." << endl;

    return 0;
}

