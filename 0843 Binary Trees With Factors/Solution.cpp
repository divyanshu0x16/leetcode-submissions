class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        long ans = 0;
        unordered_map<int , long> fmap;
        for(int num: arr) {
            long ways = 1;
            double lim = sqrt(num);
            for (int j = 0, fa = arr[0]; fa <= lim; fa = arr[++j])
            {
                if(num % fa != 0) continue;
                int fb = num/fa;
                if( fmap.find(fb) != fmap.end())
                    ways += fmap[fa]*fmap[fb]*( fa == fb ? 1 : 2);
            }
            fmap[num] = ways;
            ans = (ans + ways)%1000000007;
        }
        return (int)ans;
    }
};