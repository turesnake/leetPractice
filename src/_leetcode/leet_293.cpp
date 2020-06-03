/*
 * ====================== leet_293.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 293. 翻转游戏
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_293 {//~


// 64%, 100%
class S{
public:
    std::vector<std::string> generatePossibleNextMoves(std::string s){

        if( s.size()<2 ){ return {}; }
        int N = static_cast<int>(s.size());
        std::vector<std::string> strs {};
        for( int i=1; i<N; i++ ){// [i-1],[i]
            if( s.at(i)=='+' && s.at(i-1)=='+' ){
                strs.push_back(s);
                strs.back().at(i)='-';
                strs.back().at(i-1)='-';
            }
        }
        return strs;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 293 :end ~~~~\n" );
}
}//~
