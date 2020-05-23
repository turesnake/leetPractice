/*
 * ====================== leet_m17_16.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.16. 按摩师
 */
#include "innLeet.h"


namespace leet_m17_16 {//~




int massage( std::vector<int>& nums ){

    int N = static_cast<int>(nums.size());
    if( N==0 ){ return 0; }
    std::vector<int> dp1 {0, nums.at(0)};
    std::vector<int> dp2 (2,0);
    auto *fst = &dp1;
    auto *lst = &dp2;
    for( int n=1; n<N; n++ ){
        lst->at(0) = std::max( fst->at(0),fst->at(1) );
        lst->at(1) = fst->at(0) + nums.at(n);
        std::swap( fst, lst );
    }
    return std::max( fst->at(0), fst->at(1) );
}




//=========================================================//
void main_(){

    std::vector<int> v { 88 };

    cout << massage(v) << endl;
    




    debug::log( "\n~~~~ leet: m17_16 :end ~~~~\n" );
}
}//~
