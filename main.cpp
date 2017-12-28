#include <iostream>
#include <sstream>

using namespace std;

bool read(int *mas, int n) {
    string str;
    int i;
    getline(cin, str);
    istringstream stream(str);
    for (i = 0; i < n; i++) {
        if (!(stream >> mas[i]) || (mas[i] > 255) || (mas[i] < 0)) return false;
    }
    if (stream >> mas[i]) return false;
    return true;
}

void sort(int *mas,int *dub,  int n){
    int sortmas[256] = {0};
    for (int i = 0; i < n; i++) dub[i] = i;
    for (int i = 0; i < n; i++) sortmas[mas[i]]++;
    for (int j = 1; j < 256; j++) 	sortmas[j] += sortmas[j - 1];
    n--;
    while(n >= 0){
        sortmas[mas[n]]--;
        dub[sortmas[mas[n]]] = mas[n];
        n--;
    }
}

int main() {
    int n;
    string str;
    int *mas = new int;
    int *dub = new int;
    getline(cin, str);
    istringstream stream(str);

    if (stream >> n) {
        if (read(mas, n)) {
            sort(mas, dub, n);
            for (int i = 0; i < n; i++) {
                cout << dub[i] << ' ';
            }
        }
        else cout << "An error has occured while reading input data.";
    }

    delete mas;
    delete dub;

    return 0;
}
