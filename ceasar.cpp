#include "main.h"

string shift(string text, int key) {
    string plain = "";
    for(int i=0; i<text.length(); i++) {
        char start, num, c = text[i];
        if(isalnum(c)) {
            start = isdigit(c) ? '0' : islower(c) ? 'a' : 'A';
            num = isdigit(c) ? 10 : 26;
            c = (c - start + key) % num;
            c += (c >= 0 ? start : start + num);
        }
        plain += c;
    }
    return plain;
}

string encCeasar(string plain, int key) {
    return shift(plain, key);
}

string decCeasar(string cipher, int key) {
    return shift(cipher, -key);
}

void test_shift() {
    string plain = "abc ABC 123 xyz XYZ 789 .,?";
    string cipher1 = shift(plain, 1);
    string cipher25 = shift(plain, 25);
    assert(cipher1 == "bcd BCD 234 yza YZA 890 .,?");
    assert(cipher25 == "zab ZAB 678 wxy WXY 234 .,?");
}

void ceasar() {
    int key;
    string plain, cipher;
    cout << "Ceasar's Cipher" << endl;
    cout << "Enter plain text : ";
    getline(cin, plain);
    cout << "Enter key : ";
    cin >> key;

    cipher = encCeasar(plain, key);
    cout << "Cipher text : " << cipher << endl;
    cout << "Plain text : " << decCeasar(cipher, key) << endl;
}
