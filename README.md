# cpp-cryptographer
Simple c++ text cryptographer with key
# How to use
```C++
#include "encryptor.hpp"

// ------

Encryptor encr = Encryptor(key);
encrypted_text = encr.encrypt(text);
decrypted_text = encr.decrypt(encrypted_text);
```
