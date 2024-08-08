#include <stdio.h>

// Fibonacci Search function
int fibMonaccianSearch(int arr[], int x, int n) {
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    // finding smallest Fibonacci greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // eliminating elements not in the interval [0, fibM-1]
    while (fibM > 1) {
        int i = min(x, fibMMm2);

        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = i;
        }
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = i;
        }
        else {
            return i;
        }
    }

    // comparing last element with x
    if (fibMMm1 == 0 && arr[0] == x)
        return 0;

    printf("Element not found in array.\n");
    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 85;
    int ind = fibMonaccianSearch(arr, x, n);
    if (ind != -1)
        printf("Element found at index %d.\n", ind);
    return 0;
}