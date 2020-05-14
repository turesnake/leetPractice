/*
 * ====================== leet_347.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 347. 前 K 个高频元素
 */
#include "innLeet.h"


namespace leet_347 {//~


// 最粗暴实现
std::vector<int> topKFrequent( std::vector<int>& nums, int k ){

    if( nums.size()==1 ){ return nums; }
    std::map<int,int> mp {}; // <val,num>
    for( auto i : nums ){
        auto [insertIt, insertBool] = mp.emplace( i, 1 );
        if( !insertBool ){
            insertIt->second++;
        }
    }

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> heap {};
    // <num,val>

    for( auto [iVal,iNum] : mp ){
        if( static_cast<int>(heap.size())<k || iNum>heap.top().first ){
            heap.emplace( iNum, iVal );
        }
        while( static_cast<int>(heap.size()) > k ){
            heap.pop();
        }
    }

    std::vector<int> outs {};
    while( !heap.empty() ){
        outs.push_back( heap.top().second );
        heap.pop();
    }
    return outs;
}





//=========================================================//
void main_(){

    std::vector<int> v { 1,1,1,1,1,1,1,3,3,3,5,5,5,5,5,5,5,6,8,9,11,10 };

    auto ret = topKFrequent( v, 3 );

    for( auto i : ret ){
        cout << i << ", ";
    }
    cout << endl;



    debug::log( "\n~~~~ leet: 347 :end ~~~~\n" );
}
}//~
