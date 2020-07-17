/*
 * ====================== leet_1400.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1400. 构造 K 个回文字符串
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1400 {//~



//   50%   100%
class S{
public:
    // 1 <= s.length <= 10^5
    // s 中所有字符都是小写英文字母。
    // 1 <= k <= 10^5
    bool canConstruct( std::string s, int k ){

        int N = static_cast<int>(s.size());
        if( k>N ){ return false; }

        std::vector<int> chars (26,0);
        for( char c : s ){
            chars[c-'a']++;
        }

        int oddNum = 0;
        for( int i : chars ){
            if( (i&1)==1 ){ oddNum++; }
        }
        return oddNum<=k;

        
    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 1400 :end ~~~~\n" );
}
}//~
