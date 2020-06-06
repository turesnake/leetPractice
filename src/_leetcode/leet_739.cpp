/*
 * ====================== leet_739.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_739 {//~


// 单调栈 43%, 7%
class S{

struct Elem{
    int val {};
    int idx {};
};

public:
    // len:[1,30000]
    // val:[30,100]
    std::vector<int> dailyTemperatures( std::vector<int> T ){

        int N = static_cast<int>(T.size());
        std::vector<int> outs (N,-99);
        std::stack<Elem> stk {};
        for( int i=0; i<N; i++ ){
            int curVal = T.at(i);
            if( stk.empty() ){
                stk.push(Elem{curVal,i});
                continue;
            }
            if( curVal > stk.top().val ){
                // 将 stk 中所有 小于 curVal 的元素，执行清算
                while( !stk.empty() && curVal>stk.top().val ){
                    auto &e = stk.top();
                    stk.pop();
                    outs.at(e.idx) = i-e.idx;
                }
            }
            // 依然压入新元素
            stk.push(Elem{curVal,i});
        }
        // 处理 stk 中剩余元素
        // 这些值 都等不到 更大值了， 默认为0，什么也不用做 
        /*
        while( !stk.empty() ){
            auto &e = stk.top();
            stk.pop();
            outs.at(e.idx) = 0;
        }
        */
        return outs;
    }
};



//=========================================================//
void main_(){

    auto ret = S{}.dailyTemperatures({ 73, 74, 75, 71, 69, 72, 76, 73 });

    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;

    
    debug::log( "\n~~~~ leet: 739 :end ~~~~\n" );
}
}//~
