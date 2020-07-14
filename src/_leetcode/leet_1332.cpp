/*
 * ====================== leet_1332.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1332. 删除回文子序列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1332 {//~


// 每次可以删除一个 "回文子序列" （不需要字符相邻）

// 注意，仅由 'a','b' 组成
// 所以，一次可以抽出所有的 'a',剩下的就是 'b'

// 只需判断 字符串本身是不是 回文即可 


//   100%  100%
class S{
public:
    int removePalindromeSub( std::string s ){

        if( s.empty() ){ return 0; }
        int N = static_cast<int>(s.size());
        bool isRev = true;
        for( int l=0,r=N-1; l<r; l++,r-- ){
            if( s[l]!=s[r] ){
                isRev = false;
                break;
            }
        }
        return isRev ? 1 : 2;

    }
};


//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 266 :end ~~~~\n" );
}
}//~
