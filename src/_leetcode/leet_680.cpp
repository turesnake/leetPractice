/*
 * ====================== leet_680.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 680. 验证回文字符串 Ⅱ
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_680 {//~

// 最多删除一个 字符，当然也可以不删


//   65%   100%
class S{
public:
    // s 非空
    // 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
    bool validPalindrome( std::string s ){

        if(s.empty()){ return true; }
        int N = static_cast<int>(s.size());

        for( int l=0,r=N-1; l<r; l++,r-- ){
            if( s[l]!=s[r] ){// 允许出现一次 不同
                //-- A --//
                bool isRec1 = true;
                for( int i=l+1,j=r; i<j; i++,j--  ){
                    if( s[i]!=s[j] ){ 
                        isRec1=false;
                        break;
                    }
                }
                //-- B --//
                bool isRec2 = true;
                for( int i=l,j=r-1; i<j; i++,j--  ){
                    if( s[i]!=s[j] ){ 
                        isRec2=false;
                        break;
                    }
                }
                return isRec1 || isRec2;
            }
        }
        return true;

    }
};


//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 680 :end ~~~~\n" );
}
}//~
