/*
 * ====================== leet_256.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 256. 粉刷房子
 */
#include "innLeet.h"


namespace leet_256 {//~




// 动态规划
int minCost( std::vector<std::vector<int>>& costs ){

    if( costs.empty() ){ return 0; }
    if( costs.size()==1 ){
        auto &base = costs.at(0);
        return std::min( std::min( base.at(0), base.at(1) ), base.at(2) );
    }

    int h = static_cast<int>(costs.size()); // h 个房子
    int w = 3; // 3 种颜色
    // 不再分配 额外的规划空间，直接在原数据上改

    for( int j=h-2; j>=0; j-- ){ // 倒序房子
        auto &lst     = costs.at(j+1);
        auto &current = costs.at(j);

        current.at(0) += std::min( lst.at(1), lst.at(2) );
        current.at(1) += std::min( lst.at(0), lst.at(2) );
        current.at(2) += std::min( lst.at(0), lst.at(1) );
    }

    auto &base = costs.at(0);
    return std::min( std::min( base.at(0), base.at(1) ), base.at(2) );
}





//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
    
    };

    auto ret = minCost( v );
    
    cout << "ret = " << ret << endl;

    debug::log( "\n~~~~ leet: 256 :end ~~~~\n" );
}
}//~
