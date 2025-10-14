#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        for (char ch : columnTitle) {
            result = result * 26 + (ch - 'A' + 1);
        }
        return result;
    }
};

int main() {
    Solution sol;
    string columnTitle;
    cout << "Ingresa el título de la columna: ";
    cin >> columnTitle;
    int result = sol.titleToNumber(columnTitle);
    cout << "El número de columna es: " << result << endl;
    return 0;
}
