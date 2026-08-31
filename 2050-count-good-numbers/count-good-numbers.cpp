// // class Solution {
// // public:
// //    const int MOD = 1e9+7;
// //    int solve(int idx,int n){
// //     if(idx==n){
// //         return 1;
// //     }
// //     int res = 0;
// //     if(idx%2==0){
// //         for(int i :{0,2,4,6,8}){
// //            res = (res+solve(idx+1,n))%MOD;
// //         }
// //     }
// //     else {
// //         for(int i :{2,3,5,7}){
// //             res =(res+ solve(idx+1,n))%MOD;
// //         }
// //     }
// //     return res;
// //    }
// //     int countGoodNumbers(long long n) {
// //         return solve(0,n);

// //     }
// // };

// class Solution {
// public:
//     const int MOD = 1e9 + 7;

//     int solve(long long idx, long long n) {
//         if (idx == n) {
//             return 1;
//         }

//         if (idx % 2 == 0) {
//             return (5LL * solve(idx + 1, n)) % MOD;
//         } 
//         else {
//             return (4LL * solve(idx + 1, n)) % MOD;
//         }
//     }

//     int countGoodNumbers(long long n) {
//         return solve(0, n);
//     }
// };

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};