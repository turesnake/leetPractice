/*
 * ====================== leet_59.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 59. 螺旋矩阵 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_59 {//~


//  100%  100%
class S{
public:
    std::vector<std::vector<int>> generateMatrix(int n){

        if( n<1 ){ return {}; }
        std::vector<std::vector<int>> outs (n,std::vector<int>{});
        for( auto &c : outs ){
            c.resize(n,0);
        }
        int idx = 1;
        int ll = 0;
        int rr = n-1;
        for( ; ll<=rr; ll++,rr-- ){
            if( ll==rr ){
                outs.at(ll).at(ll) = idx++;
                break;
            }
            // up
            for( int w=ll; w<rr; w++ ){ outs.at(ll).at(w) = idx++; }
            // right
            for( int h=ll; h<rr; h++ ){ outs.at(h).at(rr) = idx++; }
            // down
            for( int w=rr; w>ll; w-- ){ outs.at(rr).at(w) = idx++; }
            // left
            for( int h=rr;h>ll; h-- ){ outs.at(h).at(ll) = idx++; }
        }
        return outs;

    }
};







//=========================================================//
void main_(){
    

    
    debug::log( "\n~~~~ leet: 59 :end ~~~~\n" );
}
}//~
