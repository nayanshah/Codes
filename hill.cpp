#include "main.h"

string encHill(string plain, int a, int b) {
    string cipher = "";
    return cipher;
}

string decHill(string cipher, int a, int b) {
    string plain = "";
    return plain;
}

void hill() {
    int a, b;
    string plain, cipher;
    cout << "Enter plain text : ";
    cin >> plain;
    cout << "Enter key : ";
    cin >> a >> b;

    cipher = encHill(plain, a, b);
    cout << "Cipher text : " << cipher << endl;
    cout << "Plain text : " << decHill(cipher, a, b) << endl;
}

