/*
 * ====================== leet_m59_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题59 - I. 滑动窗口的最大值
 */
#include "innLeet.h"
#include "ListNode.h"



namespace leet_m59_1 {//~


// 非常罕见的 “有序单调递减队列”


// 遍历窗口中的每个元素，保留所有 “维持递减状态”的数据
std::vector<int> maxSlidingWindow( std::vector<int>& nums, int k ){

    if( nums.empty() ){ return {}; }

    int N = static_cast<int>(nums.size());
    std::deque<int> que {};// 单调递减队列，存储序号
    std::vector<int> outs {};

    //=1= 建立窗口
    for( int i=0; i<k; i++ ){
        while( !que.empty() && nums.at(que.back())<nums.at(i) ){ que.pop_back(); }
        que.push_back(i);
    }
    outs.push_back( nums.at(que.front()) );// 头部是最大值

    //=2= slip
    for( int l=0,r=k; r<N; l++,r++ ){// l:begin; r:end
        while( !que.empty() && nums.at(que.back())<nums.at(r) ){ que.pop_back(); }
        que.push_back(r);
        while( que.front() <= l ){ que.pop_front(); }
        outs.push_back( nums.at(que.front()) );
    }
        /*
        cout<<"que: ";
        while( !que.empty() ){
            cout<<que.front()<<", ";
            que.pop_front();
        }cout<<endl;
        */
    return outs;
}



//=========================================================//
void main_(){

    //std::vector<int> v { 1,3,-1,-3,5,3,6,7 };
    std::vector<int> v { 1,2,3 };

    auto ret = maxSlidingWindow( v, 3 );

    for( int i : ret ){
        cout <<i<<", ";
    }
    cout <<endl;

    

    debug::log( "\n~~~~ leet: m59_1 :end ~~~~\n" );
}
}//~
