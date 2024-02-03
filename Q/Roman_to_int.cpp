#include <iostream>
using namespace std;

int romanToInt(string s) {
    int len = s.length();
    int ans = 0;
    int num[] = {    1,   4,    5,    9,  10,   40,  50,   90,  100, 400,  500, 900, 1000};
    string rom[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    for (int i = 0; i < len; i++) {
        for (int j = 12; j >= 0; j--) {
            if (s.substr(i, rom[j].length()) == rom[j]) {
                ans += num[j];
                i += rom[j].length() - 1;
                break;
            }
        }
    }

    return ans;
}

int main() {
    string s = "XCIX";
    int result = romanToInt(s);
    cout << "Roman numeral " << s << " is equivalent to " << result << endl;

    return 0;
}
