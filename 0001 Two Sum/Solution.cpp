class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int> > indexes;
        
        for (int i = 0; i < nums.size(); i++)
            indexes[nums[i]].push_back(i);

        vector<int> ans;

        for (auto &&i : indexes)
        {
            int rem = target - i.first;

            if( indexes.find(rem) != indexes.end()){
                
                vector<int> first = i.second;
                vector<int> second = indexes[rem];

                for (int i = 0; i < first.size(); i++)
                    for (int j = 0; j < second.size(); j++)
                        if( first[i] != second[j]) {
                            ans.push_back(first[i]);
                            ans.push_back(second[j]);
                            return ans;
                        }
            }
        }
        return ans;
    }
};