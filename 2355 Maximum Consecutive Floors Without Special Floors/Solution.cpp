class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        vector<int> consFloors;
        sort(special.begin(), special.end());

        consFloors.push_back(special[0] - bottom);

        for (int i = 0; i < special.size()-1; i++)
            consFloors.push_back(special[i+1] - special[i] - 1);

        consFloors.push_back(top - special[special.size() - 1]);

        return *max_element(consFloors.begin(), consFloors.end());
    }
};