/*
 * ====================== leet_m56_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m56_1 {//~


// 13%, 100%
class S{
public:
    std::vector<int> singleNumbers( std::vector<int>& nums ){

        std::unordered_set<int> sett {};
        for( int i : nums ){
            if( sett.erase(i)==0 ){
                sett.insert(i);
            }
        }
        return std::vector<int> ( sett.begin(), sett.end() );
    }
};


//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: m56_1 :end ~~~~\n" );
}
}//~
