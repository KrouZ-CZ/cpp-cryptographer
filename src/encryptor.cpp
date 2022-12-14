#include "encryptor.hpp"

Encryptor::Encryptor(string key) : key(key) {}

string Encryptor::encrypt(string text) {
    using namespace macaron;
    string result;
    AES instance = AES(SHA_256(key));
    Base64 bs = Base64();
    text = bs.Encode(text);
    // cout << "Base64: " << text << endl;
    for (int i = 0; i < text.length(); i+=16) {
        // cout << text.substr(i, 16).length() << endl;
        if (text.substr(i, 16).length() == 16) {
            result += instance.encrypt(text.substr(i, 16));
        } else {
            int tmp = 16 - text.substr(i, 16).length();
            string ts = text.substr(i, 16);
            for (int i = 0; i < tmp; i++) {
                ts += "|";
            }
            result += instance.encrypt(ts);
        }
    }

    return result;
}

string Encryptor::decrypt(string text) {
    using namespace macaron;
    string result, of_res, out;
    AES instance = AES(SHA_256(key));
    Base64 bs = Base64();
    for (int i = 0; i < text.length(); i+=16) {
        result += instance.decrypt(text.substr(i, 16));
    }
    for (int i = 0; i < result.length(); i++) {
        if (result[i] != '|') {
            of_res += result[i];
        }
    }
    bs.Decode(of_res, out);
    return out;
}

string Encryptor::SHA_256(string key) {
    SHA256 sha;
    sha.update(key);
    uint8_t * digest = sha.digest();

    // std::cout << "SHA256 key: " << SHA256::toString(digest).substr(0, 32) << std::endl;
    string result = SHA256::toString(digest);

    delete[] digest; // Don't forget to free the digest!
    return result.substr(0, 32);
}