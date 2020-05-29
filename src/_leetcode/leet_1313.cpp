/*
 * ====================== leet_1313.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1313. 解压缩编码列表
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1313 {//~



std::vector<int> decompressRLElist( std::vector<int>& nums ){

    int N = static_cast<int>(nums.size());
    std::vector<int> outs {};
    for( int i=1; i<N; i+=2 ){// [i-1], [i]
        outs.insert( outs.end(), nums.at(i-1), nums.at(i) );
    }
    return outs;
}






//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 1313 :end ~~~~\n" );
}
}//~
