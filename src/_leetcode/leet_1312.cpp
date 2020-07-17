/*
 * ====================== leet_1312.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1312. 让字符串成为回文串的最少插入次数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1312 {//~



// 本质上是个 中等题




//   69%   49%
class S{
public:
    // 1 <= s.length <= 500
    // s 中所有字符都是小写字母
    int minInsertions( std::string s ){

        if( s.empty() ){ return 0; }

        int N = static_cast<int>(s.size());

        std::vector<std::vector<int>> dp (N+1, std::vector<int>(N,0));//dp[0][w] 空置
        // dp[1][w]=0
        // dp[2][w] 
        for( int w=0; w<N-1; w++ ){// [w],[w+1]
            dp[2][w] = s[w]==s[w+1] ? 0 : 1;
        }
        // dp[h][w], h>2
        for( int h=3; h<=N; h++ ){
            for( int w=0; w<=N-h; w++ ){// [w, w+h-1]
                dp[h][w] = s[w]==s[w+h-1] ?
                            dp[h][w] = dp[h-2][w+1] :
                            std::min( dp[h-1][w], dp[h-1][w+1] ) + 1;
            }
        }
        //cout<<"dp: "<<endl;
        //for( auto &c:dp ){ for( int i:c ){ cout<<i<<", "; }cout<<endl; }
        return dp[N][0];


    }
};



//=========================================================//
void main_(){

    auto ret = S{}.minInsertions( "zzaz" );

    cout<<"ret:"<<ret<<endl;



    debug::log( "\n~~~~ leet: 1312 :end ~~~~\n" );
}
}//~
