/*
 * ====================== leet_m22.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题22. 链表中倒数第k个节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m22 {//~


// 原始朴素法 87%, 100%
// 使用一个 中间节点，来适当加速
class S{
public:
    ListNode* getKthFromEnd( ListNode* head, int k ){
        ListNode *f = head;// fast
        ListNode *s = head;// slow
        int fi = 0;
        int si = 0;
        while( f->next ){
            s = s->next;
            f = f->next;
            si++;
            fi++;
            if( f->next ){
                f = f->next;
                fi++;
            }
        }
        // s: mid-right
        //cout<<"si:"<<si <<"; fi:"<<fi<<endl;
        int ki = fi+1-k;// k位元素正序下标
        if(ki<0){ return nullptr; }
        if( ki >= si ){
            while( si!=ki ){
                s = s->next;
                si++;
            }
            return s;
        }else{
            ListNode *ptr = head;
            int i = 0;
            while( i!=ki ){
                ptr = ptr->next;
                i++;
            }
            return ptr;
        }

    }
};



// 推荐方法： 双指针  50%, 100%
// 前指针 先走出 k 步间距，然后两指针一起前进
// 当前指针抵达尾部，后指针正好指向目标
class S2{
public:
    ListNode* getKthFromEnd( ListNode* head, int k ){

        ListNode *l = head;
        ListNode *r = head;
        for( int i=0; i<k; i++ ){
            r = r->next;
        }
        while( r ){
            r = r->next;
            l = l->next;
        }
        return l;
    }
};


//=========================================================//
void main_(){

    //ListNode *l = create_list({ 0,1,2,3,4,5 });
    //ListNode *ret = S{}.getKthFromEnd( l, 2 );


    
    debug::log( "\n~~~~ leet: m22 :end ~~~~\n" );
}
}//~
