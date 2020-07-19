/*
 * ====================== leet_m17_14.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.14. 最小K个数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_14 {//~


// 大顶堆

//  28%  100%
class S{
public:
    // 0 <= len(arr) <= 100000
    // 0 <= k <= min(100000, len(arr))
    std::vector<int> smallestK( std::vector<int>& arr, int k ){

        if( arr.empty() || k==0 ){ return {}; }

        int N = static_cast<int>(arr.size());
        if( N==k ){ return arr; }

        std::priority_queue<int> maxHeap {};
        
        int i=0;
        for(; i<k; i++ ){
            maxHeap.push( arr[i] );
        }

        for(; i<N; i++ ){
            if( arr[i] < maxHeap.top() ){
                maxHeap.pop();
                maxHeap.push( arr[i] );
            }
        }

        std::vector<int> outs {};
        for( int j=0; j<k; j++ ){
            outs.push_back( maxHeap.top() );
            maxHeap.pop();
        }
        return outs;


    }
};




//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: m17_14 :end ~~~~\n" );
}
}//~
