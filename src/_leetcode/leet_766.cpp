/*
 * ====================== leet_766.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 766. 托普利茨矩阵
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_766 {//~



// 矩阵
bool isToeplitzMatrix( std::vector<std::vector<int>>& matrix ){

    int H = static_cast<int>(matrix.size());
    int W = static_cast<int>(matrix.at(0).size());
    if( W==1 || H==1 ){ return true; }
    for( int h=1; h<H; h++ ){// h-1, h
        auto &up = matrix.at(h-1);
        auto &down = matrix.at(h);
        for( int w=0; w<W-1; w++ ){// 上排不查尾元素，下排不查头元素
            if( up.at(w) != down.at(w+1) ){
                return false;
            }
        }
    }
    return true;
}



//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 766 :end ~~~~\n" );
}
}//~
