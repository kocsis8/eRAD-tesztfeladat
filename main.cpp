#include <unordered_set>
#include <iostream>

class KeyManager {
private:
    std::unordered_set<unsigned int> allocatedKeys;  // Tartalmazza a foglalt kulcsokat

public:
    unsigned int getKey() {
        unsigned int key = 0;
        while (allocatedKeys.find(key) != allocatedKeys.end()) {
            // Amíg talál foglalt kulcsot, növeljük a kulcs értékét
            ++key;
        }
        allocatedKeys.insert(key);  // Foglaljuk le a kulcsot
        return key;
    }

    bool releaseKey(unsigned int key) {
        if (allocatedKeys.find(key) != allocatedKeys.end()) {
            // Ha a kulcs foglalt, felszabadítjuk
            allocatedKeys.erase(key);
            return true;
        } else {
            // Ha a kulcs nem foglalt, hibát jelzünk
            return false;
        }
    }
};


int main() {
    KeyManager keyManager;

    unsigned int a1 = keyManager.getKey();
    std::cout << "a1 = " << a1 << std::endl;

    unsigned int a2 = keyManager.getKey();
    std::cout << "a2 = " << a2 << std::endl;

    unsigned int a3 = keyManager.getKey();
    std::cout << "a3 = " << a3 << std::endl;

    keyManager.releaseKey(a2);

    unsigned int a4 = keyManager.getKey();
    std::cout << "a4 = " << a4 << std::endl;

    keyManager.releaseKey(a1);
    keyManager.releaseKey(a3);
    keyManager.releaseKey(a4);

    return 0;
}
