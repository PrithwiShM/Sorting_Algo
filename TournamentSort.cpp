#include <iostream>
#include <vector>

using namespace std;

class Tournament {
    public:
        vector<int*> layers;
        vector<int> length_layers;
        int total_layers;

        Tournament(int arr[], int n) {
            length_layers.push_back(n);
            while(n > 1) {
                n= n/2 + n%2;
                length_layers.push_back(n);}
            total_layers = length_layers.size();
            layers.resize(total_layers);
            layers[0] = arr;
        }
        void Initialize() { //set the tournament for the first time
            for(int i = 1 ; i< total_layers; i++){
                int * tu = new int[length_layers[i]];
                int * ty = layers[i-1];
                tu[length_layers[i]-1] = ty[length_layers[i-1]-1];
                int w = (length_layers[i-1]/2);
                for (int j = 0 ; j < w ;j++) {
                    tu[j] = max(ty[2*j], ty[2*j+1]);
                }
                layers[i] = tu;
            }
        }
        int search(int item) {
            int ss = 0;
            for (int u = total_layers-2; u >= 0 ; u--) {
                int *g= layers[u];
                if (item == g[ss*2]) {ss = ss*2;}
                else {ss= 2*ss + 1;}
            }
            return ss;
        }
        void rebuild(int pos) {
            layers[0][pos] = INT16_MIN;
            for (int i = 1; i < total_layers ; i++) {
                int *ty = layers[i-1];
                if (pos % 2 == 0 && pos == length_layers[i-1]-1) { //odd postion at th end of the layer
                    pos = pos/2;
                    layers[i][pos] = ty[2*pos];}
                else {
                    pos = pos/2;
                    layers[i][pos] = max(ty[2*pos], ty[2*pos+1]);}
            }
        }
        int winner() {
            return layers.back()[0];
        }
        /*void Status() {
            for (int i = 0 ; i < total_layers ; i++) {
                int * curr = layers[i];
                for(int j = 0 ; j < length_layers[i] ; j++) {
                    cout << curr[j] << " ";
                }
                cout << endl;
            }
        }*/
};
void TournamentSort(int inp[], int a){
    Tournament tour(inp, a);
    int ut[a];
    int win;
    tour.Initialize();
    for (int i = 0; i < a ; i++) {
        win = tour.winner();
        ut[i] = win;
        tour.rebuild(tour.search(win));
    }
    for (int i = 0 ; i < a ; i++){ inp[i] = ut[i];}
}

int main() {
    int input[] = {-23, 45, -12, 29, -41, 59, 0, 05, 64, 44};
    int s = sizeof(input)/sizeof(input[0]);
    //int * ans;
    TournamentSort(input, s);
    for ( int i = 0; i < s; i++ ) {
        cout << input[i] << " ";
    }
}