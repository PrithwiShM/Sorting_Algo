#include <iostream>

using namespace std;

void swap(int* e, int* f) {
    int temp = *e;
    *e = *f;
    *f = temp;
}
void printArray(int ar[], int n) {
    for (int i=0; i<n; i++) 
        cout << ar[i] << " ";
    cout << "\n";
}
void ShellSortNext(int arr[], int s) {
    int margin = s/2,  changes;
    while(margin) {
        
        for (int t = margin; t < s ; t++) { 
            int curr = arr[t];  //insert arr[t] in its correct place in subarray of margin gap
            int itr = t;
            while(itr >= margin && curr < arr[itr-margin]) {
                swap(&arr[itr-margin], &arr[itr]);
                itr -= margin;
            }
        }

        margin = margin/2;
    }
}

int main () {
    /*int n= 10;
    int tester[n];
    for (int ct = 0 ; ct < 5 ; ct++) {
        for (int j =0 ; j < n ; j++) {
            tester[j] = rand();
        }
        printArray(tester, n);
        ShellSortNext(tester, n);
        printArray(tester, n);
    }*/
    int a[] = {-3, 4 ,-2, 0 , 11, 56, 49 , -3, 22};
    int n = sizeof(a)/sizeof(a[0]); 
        ShellSortNext(a, n);
        printArray(a, n);
}
