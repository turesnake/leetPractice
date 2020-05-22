/*
 * ====================== leet_m47.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题47. 礼物的最大价值
 * 和 64 题 类似
 */
#include "innLeet.h"


namespace leet_m47 {//~


// 动态规划
// grid 长宽 都大于 0
int maxValue( std::vector<std::vector<int>>& grid ){

    int H = static_cast<int>(grid.size());
    int W = static_cast<int>(grid.at(0).size());
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
            grid.at(h).at(w) += std::max( grid.at(h-1).at(w), grid.at(h).at(w-1) );
        }
    }
    return grid.back().back();
}






//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1},
        {7},
        {3}
    };

    cout << maxValue(v) << endl;
    


    debug::log( "\n~~~~ leet: m47 :end ~~~~\n" );
}
}//~
