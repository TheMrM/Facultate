#include <iostream>
#include <string>
using namespace std;

class custString {
    private:
        string value = "ThisIsAcustomString";
    
    public:
        custString(string initVal = "") {
            if (!initVal.empty()) {
                value = initVal;
            }
        }
    
        void concatenate(const custString& otherString) {
            value.append(otherString.value);
        }

        string slice(size_t start, size_t end) {
            if (start < end && end <= value.length()) {
                return value.substr(start, end - start);
            } else {
                return "";
            }
        }

        int compare(const custString& otherString) {
            if (value == otherString.value) {
                return 0;
            } else if (value > otherString.value) {
                return 1;
            } else {
                return -1;
            }
        }

        void display() {
            cout << value << endl;
        }
};

int main() {
    custString str1("Hello");
    custString str2("World");
    custString str3;

    cout << "str1: ";
    str1.display();
    cout << "str2: ";
    str2.display();
    cout << "str3: ";
    str3.display();

    str1.concatenate(str2);
    cout << "After concatenating str2 and str1: ";
    str1.display();

    cout << "Slice of str1 (0, 5): " << str1.slice(0, 3) << endl;

    int comparisonResult = str1.compare(str3);
    cout << "Comparing str1 with str3: " << comparisonResult << endl;

    comparisonResult = str2.compare(custString(str1.slice(5, 10)));
    cout << "Comparing str2 with a slice of str1: " << comparisonResult << endl;

    return 0;
}