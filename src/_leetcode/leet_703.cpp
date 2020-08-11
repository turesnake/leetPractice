/*
 * ====================== leet_703.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 703. 数据流中的第K大元素
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_703 {//~



// 烂题




// 你可以假设 nums 的长度≥ k-1 且k ≥ 1
// 意味着，nums 也许会缺一个元素


//   82%   97%
class KthLargest {
    std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap {};
    int Nk {};
    // 常年保持 k 个元素，第k个，在 top 处
public:
    KthLargest(int k, std::vector<int>& nums) {
        Nk = k;
        int N = static_cast<int>(nums.size());
        int i=0;
        int minK = std::min(k,N);
        for(; i<minK; i++ ){
            minHeap.push( nums[i] );
        }
        for(; i<N; i++ ){
            if( nums[i] > minHeap.top() ){
                minHeap.pop();
                minHeap.push( nums[i] );
            }
        }
    }
    
    int add(int val) {
        if( minHeap.size()<Nk ){
            minHeap.push( val );// 最多只会缺一个
        }else{
            if( val > minHeap.top() ){
                minHeap.pop();
                minHeap.push( val );
            }
        }
        return minHeap.top();
    }
};



//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 703 :end ~~~~\n" );
}
}//~
