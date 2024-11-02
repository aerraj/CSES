#include <iostream>
using namespace std;

int count_trailing_zeros(int n) {
    int count = 0;
    for (int i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << count_trailing_zeros(n) << endl;
    return 0;
}
