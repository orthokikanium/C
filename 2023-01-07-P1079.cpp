#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int* Key_Offset(string key) {
	int size = key.size();
	int* offset=new int[size];
	for (int i = 0; i < key.size(); i++) {
		if (int(key[i]) <= 90) {
			offset[i] =int(key[i])-65;
		}
		else {
			offset[i] = int(key[i]) - 97;
		}
	}
	return offset;
}

//令人伤心的是，这是加密
string Compute_R(int* offset, string plain,int key_length) {
	string cipher = "";
	for (int i = 0; i < plain.size(); i++) {
		if (int(plain[i]) <= 90) {
			if(int(plain[i]) + offset[i % key_length]>90){
				cipher = cipher + char(int(plain[i]) + offset[i % key_length] - 26);
			}
			else {
				cipher = cipher + char(int(plain[i]) + offset[i % key_length]);
			}
		}
		else {
			if (int(plain[i]) + offset[i % key_length] > 122) {
				cipher = cipher + char(int(plain[i]) + offset[i % key_length] - 26);
			}
			else {
				cipher = cipher + char(int(plain[i]) + offset[i % key_length]);
			}
		}
	}
	//for (int i = 0; i < key_length; i++) {
	//	cout << offset[i] << " ";
	//}

	return cipher;
}

string Vigenere_Encrypion(string key,string plain) {
	int* offset = Key_Offset(key);
	int key_length= key.size();
	string cipher=Compute_R(offset, plain, key_length);
	return cipher;
}

//这是解密
string Dec_Compute_R(int* offset, string cipher, int key_length) {
	string plain = "";
	for (int i = 0; i < cipher.size(); i++) {
		if (int(cipher[i]) <= 90) {
			if (int(cipher[i]) - offset[i % key_length] <65) {
				plain = plain + char(int(cipher[i]) - offset[i % key_length] + 26);
			}
			else {
				plain = plain + char(int(cipher[i]) - offset[i % key_length]);
			}
		}
		else {
			if (int(cipher[i]) - offset[i % key_length] <97) {
				plain = plain + char(int(cipher[i]) - offset[i % key_length] + 26);
			}
			else {
				plain = plain + char(int(cipher[i]) - offset[i % key_length]);
			}
		}
	}
	return plain;
}

string Vigenere_Decrypion(string key, string cipher) {
	int* offset = Key_Offset(key);
	int key_length = key.size();
	string plain = Dec_Compute_R(offset, cipher, key_length);
	return plain;
}


int main() {

	string key;
	//string plain;
	//cin >> key >> plain;
	//cout << Vigenere_Encrypion(key, plain) << endl;

	string cipher;
	cin >> key >> cipher;
	cout << Vigenere_Decrypion(key, cipher) << endl;

	return 0;
}

