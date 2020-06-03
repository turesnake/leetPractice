/*
 * ====================== leet_1464.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1464 {//~


// 小顶堆 99%, 100%
class S{
public:
    // 2 <= nums.length <= 500
    // 1 <= nums[i] <= 10^3
    int maxProduct( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap {};
        minHeap.push( nums.at(0) );
        minHeap.push( nums.at(1) );
        for( int i=2; i<N; i++ ){
            int v = nums.at(i);
            if( v > minHeap.top() ){ minHeap.push(v); }
            while( minHeap.size()>2 ){ minHeap.pop(); }
        }
        int v1 = minHeap.top()-1;
        minHeap.pop();
        int v2 = minHeap.top()-1;
        return v1*v2;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1464 :end ~~~~\n" );
}
}//~
