/*
 * ====================== leet_1278.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1278. 分割回文串 III
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1278 {//~


// 依旧是 两个 dp 来实现 
// -1- dp[len][r] 字符[r]结尾的，长度为len 的 区间，变成 回文，需要修改几次
// -2- dp[k][i] 将 [0,i] 段，分割为 k个回文，最少需要修改 几次


//    96%   100%
class S{
public:
    // 1 <= k <= s.length <= 100  说明k一定够用
    // s 中只含有小写英文字母。
    int palindromePartition( std::string s, int k ){

        int N = static_cast<int>(s.size());

        //=== dp 1 ===//
        std::vector<std::vector<int>> dp1 (N+1, std::vector<int>(N,0));// dp1[0] 空置
        // dp1[1][w] = 0;
        // dp1[2][w]
        for( int w=1; w<N; w++ ){// [w-1], [w]
            dp1[2][w] = s[w-1]==s[w] ? 0 : 1;
        }
        // dp1[h][w]
        for( int h=3; h<=N; h++ ){
            for( int w=h-1; w<N; w++ ){
                dp1[h][w] = (s[w-h+1]==s[w] ? 0:1) + dp1[h-2][w-1];
            }
        }
        //cout<<"dp1: ";for( auto &c : dp1 ){ for( int i : c ){ cout<<i<<", "; }cout<<endl; }cout<<endl;

        //=== dp 2 ===//
        // dp2 也是 二维数组
        // 以[i]结尾的区间，被分割成 j 块，需要修改几次
        std::vector<std::vector<int>> dp2 (k+1, std::vector<int>(N, 0));// dp2[0][w] 空置

        // dp2[1][0]=0;
        // dp2[1][w], w>0
        for( int w=1; w<N; w++ ){
            dp2[1][w] = dp1[w+1][w];
        }
        // dp2[h][w], h>1
        for( int h=2; h<=k; h++ ){
            for( int w=h-1; w<N; w++ ){
                if( h==w+1 ){
                    dp2[h][w] = 0;
                    continue;
                }
                int mmin = INT_MAX;
                for( int l=w-1; l>=h-2; l-- ){
                    int tmin = dp1[w-l][w] + dp2[h-1][l];
                    mmin = std::min( mmin, tmin );
                }
                dp2[h][w] = mmin;
            }
        }
        //cout<<"dp2: ";for( auto &c : dp2 ){ for( int i:c ){ cout<<i<<", "; }cout<<endl; }cout<<endl;
       
        return dp2[k].back();

    }
};



//=========================================================//
void main_(){

    auto ret = S{}.palindromePartition( "askjiydsd", 4 );
    cout<<"ret:"<<ret<<endl;


    debug::log( "\n~~~~ leet: 1278 :end ~~~~\n" );
}
}//~
