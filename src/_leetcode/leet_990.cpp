/*
 * ====================== leet_990.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 990. 等式方程的可满足性
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_990 {//~


// 并查集 

class S{

public:
    // 1<= len<= 500
    bool equationsPossible( std::vector<std::string>& equations ){


        for( const auto &str : equations ){
            char a = str.at(0);
            char b = str.at(3);

        }

        return false;
    }
};




//=========================================================//
void main_(){

    std::vector<std::string> v {
        "a==b", "b!=a"
    };

    
    debug::log( "\n~~~~ leet: 990 :end ~~~~\n" );
}
}//~
