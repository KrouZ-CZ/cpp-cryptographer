#include "AES.h"
#include "SHA256.h"
#include "Base64.h"
#include <string>

using namespace std;

class Encryptor {
public:
    Encryptor(string key);
    string encrypt(string &text);
    string decrypt(string &text);
private:
    string SHA_256(string);
    string key;
};
