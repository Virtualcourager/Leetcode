class Solution {
public:
    int climbStairs(int n) {
        int a,b;
        a=1,b=1;
        for(int i=1;i<n;i++)
        {
            b=b+a;
            a=b-a;
        }
        return b;
    }
}; 


class Solution {
public:
    int climbStairs(int n) {
        double root5 = sqrt(5);
        return (1 / root5) * (pow((1 + root5) / 2, n + 1) - pow((1 - root5) / 2, n + 1));
    }
};
