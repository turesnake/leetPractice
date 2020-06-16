/*
 * ====================== leet_239.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 239. 滑动窗口最大值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_239 {//~


// 用单调递减队列  28%  5%
class S{

struct Elem{
    int val {};
    int idx {};
};

public:
    // 1 <= nums.len <= 10^5
    // -10^4 <= nums[i] <= 10^4
    // 1 <= k <= nums.len
    std::vector<int> maxSlidingWindow( std::vector<int>& nums, int k ){

        std::deque<Elem> que { Elem{nums.at(0),0} };
        int N = static_cast<int>(nums.size());
        std::vector<int> outs {};

        // 填充前 k 个元素
        for( int i=1; i<k; i++ ){
            int val = nums.at(i);
            while( !que.empty() && val>que.back().val ){
                que.pop_back();
            }
            que.push_back(Elem{val,i});
        }
        outs.push_back( que.front().val );
        // 处理剩余元素 
        for( int r=k; r<N; r++ ){
            int l = r-k;// 指向 本回合区间 left 外一个
            // 删除 l 元素
            if( que.front().idx == l ){
                que.pop_front(); 
            }
            // 添加新元素 r
            int vr = nums.at(r);
            while( !que.empty() && vr>que.back().val ){
                que.pop_back();
            }
            que.push_back(Elem{vr,r});
            // 统计
            outs.push_back( que.front().val );
        }
        return outs;

    }
};





//=========================================================//
void main_(){

    std::vector<int> v { 1,3,-1,-3,5,3,6,7 };

    auto ret = S{}.maxSlidingWindow(v,3);
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;




    

    debug::log( "\n~~~~ leet: 239 :end ~~~~\n" );
}
}//~
