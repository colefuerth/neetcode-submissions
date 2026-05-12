#include <map>
#include <list>
#include <assert.h>
#include <iostream>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : c(capacity) { }

    int get(int key) {
        auto i = m.find(key);
        if (i != m.end()) {
            d.erase(i->second.second);
            d.push_front(key);
            i->second.second = d.begin();
            return i->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        auto i = m.find(key);
        if (i == m.end()) {
            if (d.size() >= c) {
                m.erase(d.back());
                d.pop_back();
            }
            d.push_front(key);
        } else {
            d.erase(i->second.second);
            d.push_front(key);
        }
        m[key] = {value, d.begin()};
    }

private:
    int c;
    list<int> d;
    map<int, pair<int, list<int>::iterator>> m;
};