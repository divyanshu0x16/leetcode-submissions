class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;

        while ( i + 1 < n and arr[i] < arr[i+1])
            i += 1;

        //Peak can't be first or last
        if(i == 0 or i == n-1)
            return false;

        //walk down
        while (i + 1 < n and arr[i] > arr[i+1])
            i += 1;
        
        return i == n-1;
    }
};
