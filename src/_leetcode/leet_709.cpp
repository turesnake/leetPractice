/*
 * ====================== leet_709.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_709 {//~


class S{
public:
    std::string toLowerCase( std::string str ){
        for( auto &c : str ){
            if( c>='A' && c<='Z' ){ c += 32; }
        }
        return str;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 709 :end ~~~~\n" );
}
}//~
