/*
 * ====================== leet_901.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 901. 股票价格跨度
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_901 {//~




// 单调栈   64%,  33%
// 递减，如果出现一组值相同的元素，要在栈内维护，最右侧的 元素
class StockSpanner {

    struct Elem{
        int val {};
        int idx {};
    };
    std::stack<Elem> stk {};
    int curIdx  {-1}; //based on 0

public:
    StockSpanner() {
    }
    
    int next( int price ){
        curIdx++; //指向本回合所在位

        if( stk.empty() ){
            stk.push(Elem{price,curIdx});
            return curIdx - (-1);// 不包含-1，包含 curIdx
        }

        if( price < stk.top().val ){
            stk.push(Elem{price,curIdx});
            return 1;

        }else{ // >=
            // 先清理，所有比 curVal 小或相等的元素
            // 相等的元素 要被更新为 新值，等同于删了再加
            while( !stk.empty() && price>=stk.top().val ){
                stk.pop();
            }
            int l =  stk.empty() ? -1 : stk.top().idx;
            int off = curIdx - l; // 包含 curIdx，不包含l
            stk.push(Elem{price,curIdx});
            return off;
        }
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 901 :end ~~~~\n" );
}
}//~
