#include <iostream>
#include <algorithm>
using namespace std;

// int main()
// {
//     int arr[ 5 ] = { 4, 1, 3, 2, 6 }, x;
//     int num = 3;

//     auto it = find(begin(arr), end(arr), num);

//     if (it != end(arr)) 
//     {
//         int index = distance(begin(arr), it);
//         cout << "Number " << num << " found at index: " << index << endl;
//     }
// }

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            while (i < s.size() && !isalnum(s[i])) {
                i++;
            }

            while (j > -1 && !isalnum(s[j])) {
                j--;
            }

            if (i >= j) {
                break;
            }

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test cases
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;  // Should print 1 (true)
    cout << solution.isPalindrome("race a car") << endl;  // Should print 0 (false)
    cout << solution.isPalindrome("0P") << endl;  // Should print 1 (true)

    return 0;
}
