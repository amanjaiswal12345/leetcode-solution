class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> ways(amount+1);
        //ways[i] = total # ways to get amount = i;
        //so, for amount = 0, we have one way {}
        ways[0] = 1;
        
        //take each coin one by one and see
        for(int i = 0; i<n; i++) {
            //I select a coin coins[i] and find # ways to get coins[i], coins[i]+1...until amount
            int curr_coin = coins[i];
            for(int j = curr_coin; j<=amount ; j++) {
                int remain_amount = j-curr_coin; //Kis kis amount me tumne curr_coin add kara hoga to reach j
                
                //ways[remain_amount] = # ways to get amount "remain_amount"
                
                //ways[j] = # ways to get amount "j"
                ways[j] = ways[j] + ways[remain_amount];
            }
        }
                
        return ways[amount];
    }
};
