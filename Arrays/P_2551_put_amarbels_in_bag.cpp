class Solution {
public:
    long long putMarbles(vector<int> &weights, int k) {
        long long ans = 0;
        int n = weights.size();
        vector<long long int> cost;
        for (int i = 1; i < n; i++) {
            cost.push_back(weights[i] + weights[i - 1]);
        }
        sort(cost.begin(), cost.end());
        int m = n - 1;
        long long int sumbegin = accumulate(cost.begin(), cost.begin() + (k - 1), 0LL);
        long long int sumend = accumulate(cost.end() - (k - 1), cost.end(), 0LL);
        return sumend - sumbegin;
    }
};

//
Leetcode - 561 : https : // www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVZEbXlHa1NFSjAxVUF5LWhzY1lpZ3BLdEJGQXxBQ3Jtc0ttLUtaczM3QUcxUS1MaThKS05lZ0N1WVB5WGlXRHhmUXktb0JXMkxuaWtSSktQbVFCVlpPaUtLUzZDM2hwTnAyU09JNFprdnBrTFRMdGRuNlQxRzFsaVFKMWJqWTJFX2M3TWhCbnE3TFAtbEhfeVU0NA&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Farray-partition%2F&v=L-KWU8W3OqE

                         Leetcode -
                         1877 : https : // www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqblR0YmhQekFkQ0s3R1FUX1MzY3lCbnQydmYzUXxBQ3Jtc0trazQ3REIzR29qQ0l2Qk4wV3RjWEcyNVlHVVcxbk1vam16dURSZGMxa1NCTVB6ODFFUmFKRDZzbXNORTlJNVRRaTRCVUpLNE5vU2VDYzUtMEc0Zm03dHRVWTMwd043ZlpSU1VIZldtb2xhSVVsVkFSOA&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fminimize-maximum-pair-sum-in-array%2F&v=L-KWU8W3OqE

                                        Leetcode -
                                        2740 : https: // www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmttTHo2YnZTNjhucUFJNGROYkhyYzVveXo1d3xBQ3Jtc0tubnp1YXN3YkRMUjBuQ3ZSdTREOHU2SUNPalJWbTl2MHVrSWdRVGJrWkFHSzNwSGlMY2l3THJtRjR2ZHQwRjNxNG4zMVJfVG05NEczSjI3NTFkb3lwX0xMeXdJMjdjWnRBUmxBSHJYY1dkU2ZKdjJGZw&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Ffind-the-value-of-the-partition%2F&v=L-KWU8W3OqE
