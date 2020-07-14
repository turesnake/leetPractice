/*
 * ====================== leet_m01_04.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 266. 回文排列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m01_04 {//~



// 与 266 题相同


//  100%   100%
class S{
public:
    // 字符 不限于 小写字母
    bool canPermutePalindrome( std::string s ){


        std::unordered_map<char,int> umap {};
        for( char c : s ){
            umap[c]++;
        }
        int oddNum = 0;
        for( auto e : umap ){
            if( (e.second&1)==1 ){
                oddNum++;
            }
        }
        return oddNum<=1;


    }
};




//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: m01_04 :end ~~~~\n" );
}
}//~
