#include "main.h"

int modInverse(int a, int n) {
    // TODO Calculate totient number for all n
    int totient = 12; // Totient number for 26 is 12
    int r=1;
    while(--totient) {
        r = r*a % 26;
    }
    return r;
}

string encAffine(string plain, int a, int b) {
    string cipher = "";
    for(int i=0; i<plain.length(); i++) {
        char start, c = plain[i], x;
        if(isalpha(c)) {
            start = islower(c) ? 'a' : 'A';
            x = c - start;
            c = (a*x + b) % 26;
            c += start;
        }
        cipher += c;
    }
    return cipher;
}

string decAffine(string cipher, int a, int b) {
    string plain = "";
    a = modInverse(a, 26);
    for(int i=0; i<cipher.length(); i++) {
        char start, c = cipher[i], x;
        if(isalpha(c)) {
            start = islower(c) ? 'a' : 'A';
            x = c - start;
            c = (a*(x - b)) % 26;
            c += (c >= 0 ? start : start + 26);
        }
        plain += c;
    }
    return plain;
}

void test_modInverse() {
    assert(modInverse(3, 26) == 9);
    assert(modInverse(17, 26) == 23);
    assert(modInverse(25, 26) == 25);
}

void affine() {
    int a, b;
    string plain, cipher;
    cout << "Affine Cipher" << endl;
    cout << "Enter plain text : ";
    getline(cin, plain);
    //cin >> plain;
    cout << "Enter key (a b) : ";
    cin >> a >> b;

    cipher = encAffine(plain, a, b);
    cout << "Cipher text : " << cipher << endl;
    cout << "Plain text : " << decAffine(cipher, a, b) << endl;
}

