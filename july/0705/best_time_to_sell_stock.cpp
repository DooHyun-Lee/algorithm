// first idea was to implement it buy storing it to map(value,index) -> sort the price vector -> find the max difference that both exists in the map
// but bad idea in time and spatial POV


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int ret = 0;
        for(int i=1;i<prices.size();i++){
            buy = min(buy,prices[i]);
            ret = max(ret,prices[i]-buy);
        }
        return ret;
    }
};
