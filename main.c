#include <stdio.h>

int max (int *a, int length, int i, int j, int k) {// a: array,length: length ,   i
                                                                    // j /  \ k

    int m = i;             //m: max  check if left side bigger then the right one
    if (j <length && a[j] > a[m]) {
        m = j;
    }
    if (k <length && a[k] > a[m]) {
        m = k;
    }
    return m;
}

void downheap (int *a, int length, int i) {
    while (1) {
        int j = max(a, length, i, 2 * i + 1, 2 * i + 2); // j: max index
        if (j == i) {
            break;
        }
        int t = a[i];   //
        a[i] = a[j];    // swap : 4,5 -> 5,4
        a[j] = t;      //
        i = j;

    }
}

void heapsort (int *a, int length) {           //n :length , a :array
    int i;                                              // i: counter for heaps head i
    for (i = (length - 2) / 2; i >= 0; i--) {// to make a heap
        downheap(a, length, i);
    }
    for (i = 0; i <length; i++) { // to sort the heap
        int t = a[length - i - 1];       //--
        a[length - i - 1] = a[0];  //   -----++++ to swap
        a[0] = t;                  // --
        downheap(a,length - i - 1, 0);
    }
}

int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int length = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < length; i++)
        printf("%d%s", a[i], i == length - 1 ? "\n" : " ");
    heapsort(a, length);
    for (i = 0; i < length; i++)
        printf("%d%s", a[i], i == length - 1 ? "\n" : " ");


    return 0;
}