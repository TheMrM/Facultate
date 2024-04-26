#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    stringstream ss;
    ss << n;

    for (int i = 0; i < a; i++) {
        ss << "0";
    }

    string result = ss.str();
    cout << result << endl;

    return 0;
}
