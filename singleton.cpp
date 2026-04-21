#include<iostream>
using namespace std;

class CacheManager {
    
    private: 

        static CacheManager* instance;
        unordered_map<string, string> mp;

        CacheManager() {

        }

        CacheManager(const CacheManager&) = delete;
        CacheManager* operator=(const CacheManager&) = delete;

    public: 
        static CacheManager* getInstance() {
            if (instance == nullptr) {
                instance = new CacheManager();
            }
            return instance;
        }

        bool hasKey(string key) {
            return mp.find(key) != mp.end();
        }

        void setKey(string key, string val) {
            mp[key] = val;
        }

        string getVal(string key) {
            return mp[key];
        }
};

CacheManager* CacheManager::instance = nullptr;

int main() {
    CacheManager* c1 = CacheManager::getInstance();
    string key = "foo";

    if (c1->hasKey("foo") == false) {
        c1->setKey("foo", "bar1");
    }

    CacheManager* c2 = CacheManager::getInstance();

    if (c2->hasKey("foo") == false) {
        c2->setKey("foo", "bar2");
    }

    if (c2->hasKey("foo1") == false) {
        c2->setKey("foo1", "bar2");
    }

    // should print bar1 since c2 has same reference as c1 and foo is already present in c1
    cout << c2->getVal("foo") << endl;

    // should print bar2
    cout << c2->getVal("foo1") << endl;

    // should print bar2
    cout << c1->getVal("foo1") << endl;

    return 0;
}