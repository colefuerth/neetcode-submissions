class DynamicArray {

private:
    vector<int> v;
public:

    DynamicArray(int capacity) {
        v.reserve(capacity);
    }

    int get(int i) {
        return v[i];
    }

    void set(int i, int n) {
        v[i] = n;
    }

    void pushback(int n) {
        v.push_back(n);
    }

    int popback() {
        int ret = v.back();
        v.pop_back();
        return ret;
    }

    void resize() {
        v.reserve(v.capacity() * 2);
    }

    int getSize() {
        return v.size();
    }

    int getCapacity() {
        return v.capacity();
    }
};
