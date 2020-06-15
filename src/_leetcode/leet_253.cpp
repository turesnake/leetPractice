/*
 * ====================== leet_253.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 253. 会议室 II
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_253 {//~



// 首先，对所有区间排序
// 然后用一个 小顶堆，来记录 每个区间集合中，最尾端值
// 当插入一个新区间时，寻找现有的 区间链中，尾部值最小的
// 如果这条链可以放下，就将新区间，合并到它后方（更新尾端）
// 如果这条链放不下，说明其它的也放不下，直接新建一个 区间链


//   41%  100%
class S{
public:
    int minMeetingRooms( std::vector<std::vector<int>>& intervals) {

        if(intervals.empty()){ return 0; }
        std::sort( intervals.begin(), intervals.end() );
        std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap {};
        minHeap.push( intervals.at(0).at(1) );

        int N = static_cast<int>(intervals.size());
        for( int i=1; i<N; i++ ){
            auto &elem = intervals.at(i);
            int minVal = minHeap.top();
            if( minVal > elem.at(0) ){//要新建 区间链
                minHeap.push( elem.at(1) );
            }else{// 替换成现有的
                minHeap.pop();
                minHeap.push( elem.at(1) );
            }
        }
        return static_cast<int>(minHeap.size());

    }
};




//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 253 :end ~~~~\n" );
}
}//~
