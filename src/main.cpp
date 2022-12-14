#include "encryptor.hpp"
#include <iostream>

int main() {
    string text, encrypted_text, key;
    cout << "Text: ";
    getline(cin, text);
    cout << "Key: ";
    getline(cin, key);
    Encryptor encr = Encryptor(key);
    encrypted_text = encr.encrypt(text);

    cout << "Encrypted text: " << encrypted_text << endl;
    cout << "Decrypted text: " << encr.decrypt(encrypted_text) << endl;
    return 0;
}