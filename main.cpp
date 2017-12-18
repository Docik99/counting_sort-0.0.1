#include <iostream>
#include <sstream>

using namespace std;

bool read(int n, int *mas){
    string str;
    getline(cin, str);
    istringstream stream(str);
    bool f = true;
    for (int i = 0; i < n; i++){
        if (!(stream >> mas[i]) || (mas[i] > 255) || (mas[i] < 0) ) f = false;
    }
    return f;
}

void sort(int n, int mas[], int sortmas[]){
    int k, g;
    bool pov;
    for(int i = 0; i < n; i++){
        k = 0;
        pov = false;
        g = 0;
        for (int j = 0; j < n; j++){
            if (mas[i] > mas[j]) k++;
            else if ((mas[i] == mas[j]) && (i != j)){
                k++;
                g++;
                pov = true;
            }
        }
        if (pov == false) sortmas[k] = mas[i];
        else {
            for (int l = 0; l <= g; l++) sortmas[k - l] = mas[i];
        }
    }
}

int main() {
    int n;
    int *mas = new int;
    int *sortmas = new int;

    string str;
    getline(cin, str);
    istringstream stream(str);

    if (stream >> n){
        if (read(n, mas) == true){
            sort(n, mas, sortmas);
            for (int i = 0; i < n; i++){
                cout << sortmas[i] << " ";
            }
        }
        else cout <<"An error has occured while reading input data.";
    }

    delete mas;
    delete sortmas;
    return 0;
}