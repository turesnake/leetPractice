/*
 * ====================== leet_1108.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1108. IP 地址无效化
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1108 {//~


//   100%   100%
class Solution {
public:
    std::string defangIPaddr( std::string address ){

        std::string outs {};
        for( char c : address ){
            if( c == '.' ){
                outs += "[.]";
            }else{
                outs.push_back(c);
            }
        }
        return outs;



    }
};




//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 1108 :end ~~~~\n" );
}
}//~
