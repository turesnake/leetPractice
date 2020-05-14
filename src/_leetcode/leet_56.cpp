/*
 * ====================== leet_56.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 56. 合并区间
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_56 {//~


 


std::vector<std::vector<int>> merge( std::vector<std::vector<int>>& intervals ){

    if( intervals.empty() ){ return {}; }
    if( intervals.size()==1 ){ return intervals; }

    std::sort( intervals.begin(), intervals.end(), 
        []( const std::vector<int> &v1_, const std::vector<int> &v2_ ){
            return (v1_.front() <= v2_.front());
        }
    );

    std::vector<std::vector<int>> out { intervals.front() };

    for( auto &&v : intervals ){

        if( out.back().back() < v.front() ){ // ab相离
            out.emplace_back( std::move(v) );
        }else{ // 相交/包含
            out.back().back() = std::max( out.back().back(), v.back() );
        }
    }


    return out;
}






//=========================================================//
void main_(){

    //std::vector<std::vector<int>> vv{ {1,3}, {2,6}, {8,10}, {15,18} };
    std::vector<std::vector<int>> vv{ {1,4}, {4,5} };
    

    auto retVec = merge( vv );


    for( const auto & v : retVec ){
        cout << "{" << v.front() << ", "
            << v.back() << "} ";
    }
    cout << endl;


    debug::log( "\n~~~~ leet: 56 :end ~~~~\n" );
}
}//~

