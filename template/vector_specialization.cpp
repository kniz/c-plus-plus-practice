#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int getSize(const T& t) {
    return sizeof(T);
}

template <typename T>
int getSize(const vector<T>& t) {
    cout << sizeof(t) << " and " << t.size() << "\n";
    return sizeof(T) * t.size();
}

int main() {
    vector<float> f;
    f.push_back(3.5f);
    f.push_back(2.5f);
    cout << getSize(int(5)) << ", " << getSize(f);
    return 0;
}
