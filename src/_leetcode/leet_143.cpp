/*
 * ====================== leet_143.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 143. 重排链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_143 {//~


// 虽然只是 “中分-翻转right” 的一个变种
// 但是非常容易写错
// 也许要做一段检查一段 


// 76%, 14%
class S{
public:
    void reorderList( ListNode* head ){

        if(!head){ return; }
        // 找到 mid-left
        int N = 1;
        ListNode *f = head;
        ListNode *s = head;
        while( f->next ){
            f = f->next;
            N++;
            if(!f->next){ break; }
            f = f->next;
            N++;
            s = s->next;
        }// s: mid-left
        // 总体为奇数个时，right 比 left 少一个
        if( N<=2 ){ return; }
        // right
        ListNode *right {};
        if( N==3 ){
            right = s->next; // right 只有一个元素
        }else{
            // N>3 reverse right
            ListNode *l = s->next;
            ListNode *r = l->next;
            l->next = nullptr; // 断开
            while( r ){
                ListNode *tmp = r->next;
                r->next = l;
                l = r;
                r = tmp;
            }// l 指向最后一个元素
            right = l; 
        }
        s->next = nullptr;//断开
        //--//
        ListNode *ptr = head;
        while( ptr && right ){// right 可能会先用光，还剩一个 left
            ListNode *nextLeft = ptr->next;
            ptr->next = right;
            right = right->next;
            ptr = ptr->next;
            ptr->next = nextLeft;
            ptr = ptr->next;
        }
    }
};





//=========================================================//
void main_(){

    ListNode *l = create_list({ 0,1,2 });

    S{}.reorderList(l);
    print_list( l, "MM" );

    
    debug::log( "\n~~~~ leet: 143 :end ~~~~\n" );
}
}//~
