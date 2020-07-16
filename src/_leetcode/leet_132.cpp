/*
 * ====================== leet_132.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 132. 分割回文串 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_132 {//~


// 实现两个 dp
// 第一个 用来记录，dp[len][r] 不同字符不同长度时，是否为 回文
// 第二个，用来记录，dp[i] 每个字符为结尾时，最小 分配次数  



class S{
public:
    int minCut( std::string s ){

        if(s.empty()){ return 0; }

        int N = static_cast<int>(s.size());
        //=== dp 1 ===//
        std::vector<std::vector<char>> dp1 (N+1, std::vector<char>(N,0));// dp1[0] 空置
        // dp1[1][w]
        for( int w=0; w<N; w++ ){
            dp1[1][w] = 1;
        }
        // dp1[2][w]
        for( int w=1; w<N; w++ ){// [w-1], [w]
            dp1[2][w] = s[w-1]==s[w] ? 1 : 0; 
        }
        // dp1[h][w], h>2
        for( int h=3; h<=N; h++ ){
            for( int w=h-1; w<N; w++ ){
                dp1[h][w] = (s[w-h+1]==s[w] && dp1[h-2][w-1]==1) ? 1 : 0;
            }
        }
        if( dp1[N][N-1]==1 ){ return 0; }// s 自己就是个完整的 回文
        //cout<<"dp1: "; for( auto &cv : dp1 ){ for( char c : cv ){ cout<<(int)c<<", "; }cout<<endl; }
        
        //=== dp 2 ===//
        std::vector<int> dp2 (N, 0);
        // dp2[0]=0; 一个元素时，不需要分割

        for( int i=1; i<N; i++ ){
            if( dp1[i+1][i]==1 ){
                dp2[i]=0;
                continue;
            }
            int mmin = INT_MAX;
            for( int len=1; len<=i; len++ ){
                if( dp1[len][i]==1 ){
                    mmin = std::min( mmin, dp2[i-len]+1 );
                }
            }
            dp2[i] = mmin;
        }
        //cout<<"dp2: "; for( int i : dp2 ){ cout<<i<<", "; }cout<<endl;
        return dp2.back();

    }
};


//=========================================================//
void main_(){

    std::string s = "1412123";

    auto ret = S{}.minCut(s);

    cout<<"ret:"<<ret<<endl;




    debug::log( "\n~~~~ leet: 132 :end ~~~~\n" );
}
}//~
