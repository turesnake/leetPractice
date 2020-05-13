/*
 * ====================== leet_452.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 用最少数量的箭引爆气球
 */
#include "innLeet.h"


namespace leet_452 {//~


int findMinArrowShots( std::vector<std::vector<int>>& points) {

    if( points.empty() ){ return 0; }

    std::sort( points.begin(), points.end() );

    std::vector<std::pair<int,int>> ranges {};
    ranges.push_back({ points.at(0).at(0), points.at(0).at(1) });

    for( const auto &b : points ){
        auto &a = ranges.back();
        if( b.at(0) > a.second ){ // seperate
            ranges.push_back({ b.at(0), b.at(1) });
        }else{
            a.first = b.at(0);
            a.second = (b.at(1)>=a.second) ? a.second : b.at(1);
        }
    }
    return static_cast<int>( ranges.size() );
}




//=========================================================//
void main_(){

    std::vector<std::vector<int>> v{
        {10,16},
        {6,8},
        {1,6},
        {7,12}
    };

    auto ret = findMinArrowShots( v );

    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 452 :end ~~~~\n" );
}
}//~
