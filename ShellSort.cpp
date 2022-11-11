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
void ShellSort(int arr[], int s) {
    int margin = s/2,  changes;
    while(margin) {
        for (int i = 0 ; i < margin ; i++) {  //ith subarray with gap=margin
            changes=1;
            while(changes) {                   //bubbling till no changes
                changes=0; int j =i+margin;
                while (j < s) {
                    if (arr[j-margin] > arr[j]) {
                        swap(&arr[j-margin], &arr[j]);
                        changes++;}
                    j += margin;
                }   
            }
        }

        margin = margin/2;
    }
}

/*int main () {
    int a[]  = {9,32, 52, 86, 56, 14, 98, 72, 42, 26, 38};
    int n = sizeof(a)/sizeof(a[0]); 
    ShellSort(a, n);
    printArray(a, n);
}*/
