/*
 * ====================== leet_1216.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1216. 验证回文字符串 III
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1216 {//~




//    43%   100%
class S{
public:
    // 1 <= s.length <= 1000
    // s 中只含有小写英文字母
    // 1 <= k <= s.length
    bool isValidPalindrome( std::string s, int k ){


        int N = static_cast<int>(s.size());
        std::vector<std::vector<int>> dp (N+1, std::vector<int>(N, 0));// dp[0][w] 空置
        // dp[1][w]=0;
        // dp[2][w]
        for( int w=0; w<N-1; w++ ){// [w, w+1]
            dp[2][w] = s[w]==s[w+1] ? 0 : 1;
        }
        // dp[h][w], h>2
        for( int h=3; h<=N; h++ ){
            for( int w=0; w<=N-h; w++ ){// [w, w+h-1]
                dp[h][w] = s[w]==s[w+h-1] ?
                                dp[h-2][w+1] :
                                std::min( dp[h-1][w], dp[h-1][w+1] ) + 1;
            }
        }
        return dp[N][0]<=k;


    }
};



//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 1216 :end ~~~~\n" );
}
}//~
