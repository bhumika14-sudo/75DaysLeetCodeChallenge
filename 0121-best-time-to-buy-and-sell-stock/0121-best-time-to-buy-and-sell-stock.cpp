class Solution {
public:
    int maxProfit(vector<int>& price) {

        int min_Price = INT_MAX;
        int max_Profit = 0;

        for(int i=0 ; i<price.size() ; i++){

            min_Price = min(price[i] , min_Price);

            int profit = price[i] - min_Price;

            max_Profit = max(max_Profit , profit);

        }

        return max_Profit;

    }
};