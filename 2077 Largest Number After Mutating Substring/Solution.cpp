class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
    bool mutated = false;
    for (auto i = 0; i < num.size(); ++i) {
        int d = num[i] - '0';
        num[i] = '0' + max(d, change[d]);
        if (change[d] < d && mutated) 
            break;
        mutated |= change[d] > d;
    }
    return num;
}
};