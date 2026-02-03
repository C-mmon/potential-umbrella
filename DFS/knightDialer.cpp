class Solution {
public:
    static constexpr int MOD = 1000000007;
    vector<vector<int>> moves;
    vector<vector<int>> memo;

    int dfs(int digit, int stepsLeft) {
        if (stepsLeft == 0) {
            return 1;
        }
        int& res = memo[digit][stepsLeft];
        if (res != -1) {
            return res;
        }
        long long ways = 0;
        for (int nxt : moves[digit]) {
            ways += dfs(nxt, stepsLeft - 1);
            if (ways >= MOD)
                ways -= MOD;
        }
        return res = (int)ways;
    }
    int knightDialer(int n) {
        moves = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                 {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        memo.assign(10, vector<int>(n, -1));

        long long ans = 0;
        int stepsLeft = n - 1; // we already press starting digit
        for (int d = 0; d <= 9; ++d) {
            ans += dfs(d, stepsLeft);
            ans %= MOD;
        }
        return (int)ans;
    }
};
