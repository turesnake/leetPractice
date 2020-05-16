/*
 * ====================== leet_295.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 295. 数据流的中位数
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_295 {//~


 
// 最大堆/最小堆 组合法
class MedianFinder_1 {

    std::priority_queue<int> maxHeap {};
    std::priority_queue<int,std::vector<int>,std::greater<int>>  minHeap {};
    int size     {0};
    //int halfSize {0};

public:
    /** initialize your data structure here. */
    MedianFinder_1() {}
    
    // 通过 穷举+图表分析，来获知流程
    // 在代码上不够友好
    void addNum( int num ) {
        size++;
        bool isOdd = size%2 != 0;
        //halfSize = isOdd ? size/2+1 : size/2;
        if( size==1 ){
            // 无脑压入
            minHeap.push( num );
            maxHeap.push( num );
            return;
        }
        double dNum = static_cast<double>(num);
        double mid = findMedian();
        if( dNum == mid ){// 新值等于 中位数值
            if( isOdd ){//奇数
                // halfSize 变大了，两堆都变大
                // 中位数变成1个，就是那个新值
                minHeap.push( num );
                maxHeap.push( num );
            }else{//偶数
                // halfSize 不变，两堆不变大
                // 什么也不用做
            }
        }else if( dNum < mid ){// 新值小
            if( isOdd ){//奇数
                // halfSize 变大了，两堆都变大
                // 中位数变成1个，两堆共享     
                maxHeap.push( num );
                minHeap.push( maxHeap.top() );// 分享给对方
            }else{//偶数
                // halfSize 不变，两堆不变大
                // 中位数变成2个，各不相同
                maxHeap.push( num );
                maxHeap.pop();
            }
        }else{// 新值大
            if( isOdd ){//奇数
                // halfSize 变大了，两堆都变大
                // 中位数变成1个，两堆共享     
                minHeap.push( num );
                maxHeap.push( minHeap.top() );// 分享给对方
            }else{//偶数
                // halfSize 不变，两堆不变大
                // 中位数变成2个，各不相同
                minHeap.push( num );
                minHeap.pop();
            }
        }
    }


    double findMedian(){
        if( size==0 ){ return 0; }
        return (size%2 == 0) ?
            (static_cast<double>(minHeap.top()) + static_cast<double>(maxHeap.top()))*0.5 :
            minHeap.top();
    }
};




//=========================================================//
void main_(){

    MedianFinder_1 mf {};

    mf.addNum( 1 );
    cout<< "mid: " << mf.findMedian() << endl;
    mf.addNum( 2 );
    cout<< "mid: " << mf.findMedian() << endl;
    mf.addNum( 3 );
    cout<< "mid: " << mf.findMedian() << endl;
    mf.addNum( 5 );
    cout<< "mid: " << mf.findMedian() << endl;



    debug::log( "\n~~~~ leet: 295 :end ~~~~\n" );
}
}//~

