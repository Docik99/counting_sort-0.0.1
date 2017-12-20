#include <iostream>
#include <sstream>

using namespace std;

bool read(int *mas, int len) {
    string str;
    getline(cin, str);
    istringstream stream(str);
    for ( int i = 0; i < len; i++) {
        if (!(stream >> mas[i]) || (mas[i] > 255) || (mas[i] < 0)) return false;
    }
    return true;
}

void sort(int *mas, int len) {
    int sortmas[256] = {0}, b = 0;
    for (int i = 0; i < len; i++) sortmas[mas[i]]++;
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < sortmas[j]; i++) {
            mas[b] = j; b++;
        }
    }
}


int main() {
    int len; string str;
    int *mas = new int;
    getline(cin, str);
    istringstream stream(str);

if (stream >> len) {
    if (read(mas, len) == true) {
        sort(mas, len);
        for (int i = 0; i < len; i++) {
            cout << mas[i] << ' ';
        }
    }
    else cout << "An error has occured while reading input data.";
}

    delete mas;
    return 0;
}