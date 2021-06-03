class Solution {
public:
    int getMax(int hh, vector<int> &h) {
        sort(h.begin(), h.end());
        int nh = h.size();
        int maxHeight = max(hh - h[nh-1], h[0]);
        for(int i = 1; i < nh; i++){
            maxHeight = max(maxHeight, h[i]-h[i-1]);
        }
        return maxHeight;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (int)((long)getMax(h, horizontalCuts)*getMax(w, verticalCuts)%1000000007);
        
    }
};