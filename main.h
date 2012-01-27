#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>

using namespace std;

string shift(string cipher, int key);
int modInverse(int a, int n);

void test_shift();
void test_modInverse();

string encCeasar(string plain, int key);
string decCeasar(string cipher, int key);
string encAffine(string plain, int a, int b);
string decAffine(string cipher, int a, int b);
string encHill(string plain, int a, int b);
string decHill(string cipher, int a, int b);

void ceasar();
void affine();
void hill();

void solve();

#endif // MAIN_H_INCLUDED
