/*
    Nama      : Ahmad Bustanul Aziz
    NIM       : 24060118120022
    Matkul    : Analisis dan Strategi Algoritma
    Tanggal   : 03 November 2021
    Deskripsi : Sum of Subset Problem dengan Algoritma Backtraking (Note: Backtraking dengan rekursi)
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

static int total_nodes;
void printHimpunan(int himpunan[], int nHimpunan) {
    //Kamus Lokal

    //Algoritma
    cout << "{ ";
    for (int i = 0; i < nHimpunan; i++) {
         cout << himpunan[i] << " ";
    }
    cout << "} \n";
}

void sumOfSubset (int hmpn[], int hasil[100], int nHmpn, int nHasil, int sum, int ite, int const target_sum) {
    //Kamus Lokal

    //Algoritma
    total_nodes++;
    if (target_sum == sum) {
        printHimpunan(hasil, nHasil);
        sumOfSubset(hmpn, hasil, nHmpn, nHasil - 1, sum - hmpn[ite], ite + 1, target_sum);
        return;
    } else {
        for (int i = ite; i < nHmpn; i++) {
            hasil[nHasil] = hmpn[i];
            sumOfSubset(hmpn, hasil, nHmpn, nHasil+1, sum + hmpn[i], i+1, target_sum);
        }
    }
}
int main() {
    int Hasil[100];
    int A[] = {5, 6, 10, 16};
    int nHimpunan = 4;
    int m = 21;
    sumOfSubset(A, Hasil, nHimpunan, 0, 0, 0, m);
    printf ("Nodes generated %d", total_nodes);
    return 0;
}
