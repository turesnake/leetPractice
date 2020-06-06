/*
 * ====================== leet_85.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 85. 最大矩形
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_85 {//~





// 这题并不能用 正方形题 的思路简单套用

// 有的解法，用到了 单调栈，遍历每一层，以每层为底，将高度压缩
// 然后对每一层的情况做统计 
// 类似 84 题



// 单调栈 51%， 100%
// 84题的 升级版
class S{

struct Elem{
    int val {0};
    int idx {0};
};

public:
    int maximalRectangle( std::vector<std::vector<char>>& matrix ){

        if( matrix.empty() || matrix.at(0).empty() ){ return 0; }
        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix.at(0).size());

        int maxSum = 0;
        std::stack<Elem> stk {};// 单调栈
        std::vector<int> heights (W,0);// 记录每一层的 向上积累高

        for( int h=0; h<H; h++ ){
            // 准备 heights 数据
            for( int w=0; w<W; w++ ){
                ( matrix.at(h).at(w)=='1' ) ?
                    heights.at(w)++ :
                    heights.at(w) = 0;
            }
            // 单调栈
            stk.empty();
            stk.push(Elem{heights.at(0),0});
            for( int w=1; w<W; w++ ){
                int curVal = heights.at(w);
                if( stk.empty() ){
                    stk.push(Elem{curVal,w});
                    continue;
                }
                if( curVal > stk.top().val ){
                    stk.push(Elem{curVal,w});

                }else if( curVal < stk.top().val ){
                    while( !stk.empty() && curVal<stk.top().val ){
                        // 将栈中，所有高于 curVal 的元素，清洗掉
                        auto &e = stk.top();
                        stk.pop();
                        int l = stk.empty() ? -1 : stk.top().idx;
                        int rectH = e.val;
                        int rectW = w-l-1;//此区间，不含 w 和 l位
                        //cout<<"w:"<<w<<" l:"<<l<<endl;
                        //cout<<"rectW:"<<rectW<<" rectH:"<<rectH <<endl;
                        maxSum = std::max( maxSum, rectW*rectH );
                    }
                    // 压入新值
                    stk.push(Elem{curVal,w});
                }else{// ==
                    stk.top().idx = w; // 元素高度相同时，记录最右侧的 下标
                }
            }
            //cout<<"------"<<endl;
            // 处理 栈尾元素
            while( !stk.empty() ){
                auto &e = stk.top();
                stk.pop();
                int l = stk.empty() ? -1 : stk.top().idx;
                int rectH = e.val;
                int rectW = W-l-1;//此区间，不含 W 和 l位
                //cout<<"w:"<<rectW<<" h:"<<rectH <<endl;
                maxSum = std::max( maxSum, rectW*rectH );
            }
        }
        return maxSum;
    }
};




//=========================================================//
void main_(){

    
    std::vector<std::vector<char>> v {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    
    /*
    std::vector<std::vector<char>> v {
        {'1'}
    };
    */


    cout<<"ret: "<< S{}.maximalRectangle(v)<<endl;

    
    debug::log( "\n~~~~ leet: 85 :end ~~~~\n" );
}
}//~
