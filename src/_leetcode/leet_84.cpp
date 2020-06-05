/*
 * ====================== leet_84.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 84. 柱状图中最大的矩形
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_84 {//~


// 单调栈
// 需要单独抽出来练习



// 78%, 100%  看着教程还能一连错3次
// ----
// 此单调栈中记载的，是一组连续排列的元素的 最右那个
//   也就是说，当出现 {1,1,1,3} 这么一段时，
//   虽然一开始，会记录 [0]号的1，但是后面的紧挨着的相同的1，会改写这个 stk.top().idx 
class S{

struct Elem{
    int val {0};
    int idx {0};
};

public:
    int largestRectangleArea( std::vector<int>& heights ){

        if(heights.empty()){ return 0; }
        int N = static_cast<int>(heights.size());
        int maxSum = 0;
        // 单调栈，数据递增
        std::stack<Elem> stk {};
        stk.push( Elem{heights.at(0),0} );
        for( int i=1; i<N; i++ ){
            int curVal = heights.at(i);
            if( curVal > stk.top().val ){
                stk.push( Elem{heights.at(i),i} );

            }else if( curVal < stk.top().val ){
                // 将所有比 curVal 大的栈内元素，做一次清算
                while( !stk.empty() && stk.top().val>curVal ){
                    auto &elem = stk.top();
                    stk.pop();
                    int l = stk.empty() ? -1 : stk.top().idx;
                    int rectH = elem.val;
                    int rectW = i-l-1; // l，新值，两者所在位，都不被算入矩形,
                    //cout<<"w:"<<rectW<<", h:"<<rectH<<endl;
                    maxSum = std::max(maxSum, rectW*rectH );
                }
                // 清算过后，还是要把剩余元素 塞入 栈中
                stk.push( Elem{heights.at(i),i} );

            }else{
                // 当与上一值相等，将要 top.idx 改成自己    
                stk.top().idx = i;
            }
        }
        //cout<<"---------"<<endl;
        // 遍历完所有元素后，栈中还是存在剩余元素
        while( !stk.empty() ){
            auto &elem = stk.top();
            stk.pop();
            int l = stk.empty() ? -1 : stk.top().idx;
            int rectH = elem.val;
            int rectW = (N-1)-l;// l 所在 位，不被算入矩形
            //cout<<"w:"<<rectW<<", h:"<<rectH<<endl;
            maxSum = std::max(maxSum, rectW*rectH );
        }
        return maxSum;
    }
};



//=========================================================//
void main_(){

    //std::vector<int> v { 4,2,0,3,2,5 };
    //std::vector<int> v { 2,1,5,6,2,3 };
    //std::vector<int> v { 0,0,0,0,0,0,0,0,2147483647 };

    //std::vector<int> v { 0,0,0,0,0,0,0,0,3 };

    //cout<< S{}.largestRectangleArea(v) << endl;

    //cout<<INT_MIN<<endl;
    //cout<<INT_MAX<<endl;

    
    debug::log( "\n~~~~ leet: 84 :end ~~~~\n" );
}
}//~
