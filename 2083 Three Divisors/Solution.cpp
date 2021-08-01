class Solution
{
public:
    int countDivisors(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (n / i == i)
                    cnt++;
                else 
                    cnt = cnt + 2;
            }
        }
        return cnt;
    }

    bool isThree(int n)
    {
        int ans = countDivisors(n);
        if(ans == 3) return 1;
        else return 0;
    }
};