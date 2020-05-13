/*
 * ====================== leet_215.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 数组中的第K个最大元素
 */
#include "innLeet.h"


namespace leet_215 {//~


// 最粗暴的方式 
int findKthLargest( std::vector<int>& nums, int k) {

    if( nums.size()==1 ){ return nums.back(); }
    std::priority_queue<int> heap {};
    for( auto i : nums ){
        heap.push(i);
    }
    for( int i=1; i<k; i++ ){
        heap.pop();
    }
    return heap.top();
}

// 小顶堆
int findKthLargest_2( std::vector<int>& nums, int k) {

    if( nums.size()==1 ){ return nums.back(); }
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap {};
    for( auto i : nums ){
        if( (static_cast<int>(heap.size())<k) || (i>heap.top()) ){
            heap.push( i );
        }
        while( static_cast<int>(heap.size()) > k ){
            heap.pop();
        }
    }
    return heap.top();
}





//=========================================================//
void main_(){

    std::vector<int> v {2,1};

    auto ret = findKthLargest_2(v,2);

    debug::log( "ret = {}", ret );


    debug::log( "\n~~~~ leet: 215 :end ~~~~\n" );
}
}//~
