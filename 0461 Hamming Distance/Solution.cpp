class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x^y;
        int count = 0;
        //Count the number of one's
        while( XOR ){
            XOR = XOR & (XOR - 1);
            count++;
        }
        return count;
    }
};