/*
 * ====================== leet_1133.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1133. 最大唯一数
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1133 {//~


// 1 <= A.length <= 2000
// 0 <= A[i] <= 1000
int largestUniqueNumber( std::vector<int> A ){

    std::map<int,int> mp {};//<val,times>
    for( int i : A ){
        auto [it,bl] = mp.emplace(i,1);
        if( !bl ){ it->second++; }
    }
    auto it = mp.rbegin();
    for( ; it!=mp.rend(); it++ ){
        if( it->second == 1 ){
            return it->first;
        }
    }
    return -1;
}



//=========================================================//
void main_(){

    cout<<largestUniqueNumber({ 1,1 }) << endl;
    
    

    debug::log( "\n~~~~ leet: 1133 :end ~~~~\n" );
}
}//~
