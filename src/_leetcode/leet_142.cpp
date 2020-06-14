/*
 * ====================== leet_142.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 142. 环形链表 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_142 {//~


// 假设，环首 与 链表首 间距为 n
// 在 s进入环的时候，f 已经领先 n%loopN 
// 当 s 和 f 继续前进，最终相遇时，其实存在一个 算术特征
// 那就是，此时在 环中，s距离环首的 距离，恰恰等于 环首 和 链表首的距离
// 所以，只要分别从 链表首 和 环首派出一个指针步进
// 最终相遇点，就是 环首节点 


// 有点不容易想到...


//   72%   100%
class S{
public:
    ListNode *detectCycle( ListNode *head ){

        if(!head){ return nullptr; }
        ListNode *f = head;
        ListNode *s = head;
        while( f && f->next ){
            f = f->next->next;
            s = s->next;
            if( s==f ){// 说明有环
                ListNode *a = head;
                ListNode *b = s;
                while( a!=b ){
                    a=a->next;
                    b=b->next;
                }
                return a;
            }
        }
        return nullptr;
    }
};





//=========================================================//
void main_(){
    

    
    debug::log( "\n~~~~ leet: 142 :end ~~~~\n" );
}
}//~
