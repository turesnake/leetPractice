/*
 * ====================== leet_1328.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1328. 破坏回文串
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1328 {//~

// 查找第一个 非'a' 字符

// 若长度为1，无论怎么改都是 回文，返回 ""

// 若全为 'a', 则将末位改为 'b', 返回此字符串
// 若恰好是一个 奇数长回文 的mid 位 非'a', 则将末位改为 'b', 返回此字符串
// 若是其它位置 非'a', 将其改为 'a', 返回此字符串


//   100%  100%
class S{
public:
    // 1 <= palindrome.length <= 1000
    // palindrome 只包含小写英文字母。
    std::string breakPalindrome( std::string palindrome ){


        int N = static_cast<int>(palindrome.size());
        if(N==1){ return ""; }
        for( int i=0; i<N; i++ ){
            if( palindrome[i]=='a' ){ continue; }
            if( !(i==(N-1)/2 && (N&1)==1) ){ // 若是 奇数长mid位 非'a', 将被忽视
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[N-1] = 'b';
        return palindrome;

    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 1328 :end ~~~~\n" );
}
}//~
