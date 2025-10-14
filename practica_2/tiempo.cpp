#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min = INT_MAX;
       int maxProfit = 0;

       for (int price : prices) {
            if (price < min){
                min = price;
            } else {
                int profit = price - min;
                maxProfit = max(maxProfit,profit);
            }
        }
        return maxProfit;
    }
};
int main() {
    Solution solution;
    vector<int> prices;
    int price;
    cout << "Ingresa la lista (termina con -1): ";
    while (cin >> price && price != -1) {
        prices.push_back(price);
    }
    int result = solution.maxProfit(prices);
    cout << "Max Ganancia: " << result << endl; 
    return 0;
}