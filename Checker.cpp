#include <iostream>
#include <fstream>
#include <time.h>
#include "ShellSortInsert.cpp"

using namespace std;
int main() {
    int no_array_I = 10;
    double cal;
    ofstream myfile("out_ShellInsert.txt");

    for (int i =10 ; i <= 1000 ; i++ )
    {
        int no_elements = 100*i;
        int tester[no_elements];
        cal = 0;
        for (int k = 0 ; k < no_array_I ; k++) { // avaraging for no_array_I times
            //create random array
            for (int j =0 ; j < no_elements ; j++) {
                tester[j] = rand();
            }
            
            int start = clock();
            ShellSortNext(tester, no_elements);
            int end = clock();
            
            cal += (double)(end- start)/CLOCKS_PER_SEC;
        }
        cout << i << "\n";
        cal = cal/no_array_I;
        myfile << cal << "," << no_elements << "\n";
    }
    myfile.close();
}