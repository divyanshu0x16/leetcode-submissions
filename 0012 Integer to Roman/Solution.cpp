class Solution {

private:
    vector<int> base = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000, 4000};

public:
    string intToRoman(int num) {

        if(num == 1) return "I";
        else if(num == 4) return "IV";
        else if(num == 5) return "V"; 
        else if(num == 9) return "IX";
        else if(num == 10) return "X"; 
        else if(num == 40) return "XL";
        else if(num == 50) return "L"; 
        else if(num == 90) return "XC";
        else if(num == 100) return "C"; 
        else if(num == 400) return "CD";
        else if(num == 500) return "D"; 
        else if(num == 900) return "CM";
        else if(num == 1000) return "M"; 

        int closestBase = *(lower_bound(base.begin(), base.end(), num) - 1);
        int remaining = num - closestBase;

        return intToRoman(closestBase)+intToRoman(remaining);
    }
};