/*
 * ====================== leet_64.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 64. 最小路径和
 * 和 m47 类似
 */
#include "innLeet.h"


namespace leet_64 {//~



int minPathSum( std::vector<std::vector<int>> &grid ){
        
    int H = static_cast<int>(grid.size());
    int W = static_cast<int>(grid.at(0).size());
    if( H==0 || W==0 ){ return 0; }
    // 偷个懒，dp空间直接使用 原始数组的...
    for( int w=1; w<W; w++ ){ // h==0 行数据
        grid.at(0).at(w) += grid.at(0).at(w-1);
    }
    for( int h=1; h<H; h++ ){ // w==0 列数据
        grid.at(h).at(0) += grid.at(h-1).at(0);
    }
    //---
    for( int h=1; h<H; h++ ){
        for( int w=1; w<W; w++ ){
            grid.at(h).at(w) += std::min( grid.at(h-1).at(w), grid.at(h).at(w-1) );
        }
    }
    return grid.back().back();
}






//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,2,3},
        {1,1,1}
    };
    
    cout << minPathSum(v) << endl;
    


    debug::log( "\n~~~~ leet: 64 :end ~~~~\n" );
}
}//~
