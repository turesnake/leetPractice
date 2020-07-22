/*
 * ====================== leet_m17_20.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.20. 连续中值
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_20 {//~


// 大顶堆 维护左区间，小顶堆，维护右区间
// 全局奇数个时，左区间多1元素 



//  68%  100%
class MedianFinder {

    std::priority_queue<int,std::vector<int>,std::less<int>>    lHeap {};
    std::priority_queue<int,std::vector<int>,std::greater<int>> rHeap {};
    int N {0};


public:
    /** initialize your data structure here. */
    MedianFinder() {}
    

    void addNum(int num) {
        if(N==0){
            lHeap.push(num);
            N++;
            return;
        }
        //---//
        if( (N&1)==0 ){// 原初 偶数个
            if( num<=lHeap.top() ){
                lHeap.push(num);
            }else{
                rHeap.push(num);
                lHeap.push( rHeap.top() );
                rHeap.pop();
            }
        }else{// 原初 奇数个
            lHeap.push(num);
            rHeap.push( lHeap.top() );
            lHeap.pop();
        }
        N++;
    }
    
    double findMedian() {
        return (N&1)==0 ?
                static_cast<double>( lHeap.top()+rHeap.top() )/2.0 :
                static_cast<double>(lHeap.top());
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m17_20 :end ~~~~\n" );
}
}//~
