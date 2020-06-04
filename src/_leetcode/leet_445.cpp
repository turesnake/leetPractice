/*
 * ====================== leet_445.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 445. 两数相加 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_445 {//~


// 66%， 11%
// 双栈法。 倒序存储参数中值
// 最后计算出来的值，也是倒序的，所以，在组装链表时，也要倒着装
class S{
public:
    // 参数链表 非空
    ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 ){

        std::stack<int> stk1 {};
        std::stack<int> stk2 {};
        for( ;l1; l1=l1->next ){ stk1.push(l1->val); }
        for( ;l2; l2=l2->next ){ stk2.push(l2->val); }
        ListNode *root = new ListNode(0);
        ListNode *lst  = nullptr;
        int carry = 0;
        while( !stk1.empty() || !stk2.empty() ){
            int v1 {};
            int v2 {};
            if(stk1.empty()){
                v1 = 0;
            }else{
                v1 = stk1.top();
                stk1.pop();
            }
            if(stk2.empty()){
                v2 = 0;
            }else{
                v2 = stk2.top();
                stk2.pop();
            }
            int sum = v1 + v2 + carry;
            carry = sum/10;
            ListNode *np = new ListNode(sum%10);
            np->next = lst;// 反向链接
            root->next = np;
            lst = np;
        }
        if( carry>0 ){ 
            ListNode *np = new ListNode(1);
            np->next = lst;// 反向链接
            root->next = np; 
        }
        return root->next;
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 445 :end ~~~~\n" );
}
}//~
