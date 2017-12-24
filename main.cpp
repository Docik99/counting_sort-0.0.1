#include <iostream>
#include <sstream>

using namespace std;

bool read(int *mas, int n) {
    string str;
    getline(cin, str);
    istringstream stream(str);
    for ( int i = 0; i < n; i++) {
        if (!(stream >> mas[i]) || (mas[i] > 255) || (mas[i] < 0)) return false;
    }
    return true;
}

void sort(int *mas, int n) {
    int sortmas[256] = {0}, b = 0, k = 0;
    for (int i = 0; i < n; i++) sortmas[mas[i]]++;
    for (int j = 0; j < 256; j++) {
        while (sortmas[j] > 0) {
            mas[b] = j;
            b++;
            sortmas[j]--;
        }
    }
}

int main() {
    int n; string str;
    int *mas = new int;
    getline(cin, str);
    istringstream stream(str);

if (stream >> n) {
    if (read(mas, n) == true) {
        sort(mas, n);
        for (int i = 0; i < n; i++) {
            cout << mas[i] << ' ';
        }
    }
    else cout << "An error has occured while reading input data.";
}

    delete mas;
    return 0;
}