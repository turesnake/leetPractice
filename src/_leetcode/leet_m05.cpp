/*
 * ====================== leet_m05.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题05. 替换空格
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m05 {//~

// 100%, 100%
class S{
public:
    std::string replaceSpace( std::string s ){

        std::string out {};
        for( char c : s ){
            if( c==' ' ){
                out += "%20";
            }else{
                out.push_back(c);
            }
        }
        return out;
    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m05 :end ~~~~\n" );
}
}//~
