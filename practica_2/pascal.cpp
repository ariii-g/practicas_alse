#include <iostream>
#include <vector>
using namespace std; 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector < vector < int >> pascal(numRows);

        for (int i =0; i< numRows; i++){
            pascal[i].resize(i+1);
            pascal [i][0] = pascal [i][i] = 1;

            for (int j = 1; j < i; j++){
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};
int main(){
    Solution sol;
    int filas;
    cout << "Ingresa el numero de filas: ";
    cin >> filas;
    vector<vector<int>> res = sol.generate(filas);// para imprimir como leetcode
    cout << "Trangulo de pascal:"<< endl;
    cout << "[";
    for (size_t i = 0; i < res.size(); i++){
        cout << "[";
        for (size_t j = 0; j < res[i].size(); j++){
            cout << res [i][j];
            if (j+1 < res[i].size()){
                cout << ",";
            }
        }
        cout << "]";
        if (i+1 < res.size()){
            cout << ", ";
        }
    }
    cout << "]"<< endl;
    return 0;
}
