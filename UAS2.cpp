#include <iostream>
#include <string>
using namespace std;

// Fungsi Linear Search
int linearSearch(string arr[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i; // Jika ditemukan, kembalikan indeks
    }
    return -1; // Tidak ditemukan
}
// Nandita Salwa Utarie ( 241011401425 )
int main() {
    // Dataset nama anggota TWICE (tidak diurutkan)
    string members[] = {"Mina", "Sana", "Chaeyoung", "Jihyo", "Tzuyu", "Nayeon", "Momo", "Dahyun", "Jeongyeon"};
    int size = sizeof(members) / sizeof(members[0]);

    // Nama yang ingin dicari
    string target;
    cout << "Masukkan nama anggota TWICE yang ingin dicari: ";
    getline(cin, target);

    // Pencarian Linear Search
    int result = linearSearch(members, size, target);

    // Output hasil pencarian
    if (result != -1)
        cout << "Anggota \"" << target << "\" ditemukan pada indeks " << result << " dalam dataset." << endl;
    else
        cout << "Anggota \"" << target << "\" tidak ditemukan dalam dataset." << endl;

    return 0;
}

