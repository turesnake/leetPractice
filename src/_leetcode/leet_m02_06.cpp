/*
 * ====================== leet_m02_06.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 02.06. 回文链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m02_06 {//~


// 要求：时间 O(N), 空间 O(1)

// -1- 找到 链表中电
// -2- 将后半段链表 反转
// -3- 比较两段


//  24%   100%
class S{
public:
    bool isPalindrome( ListNode* head ){

        if( !head ){ return true; }
        
        //== 找到 中点 ==/
        int Nl = 0; 
        int Nr = 0;
        ListNode *l=head;// mid-left
        ListNode *r=head;// r-end
        while( r->next ){
            r = r->next; Nr++;
            if( r->next ){
                l = l->next; Nl++;
                r = r->next; Nr++;
            }
        }

        //== 反转 后半段 ==//
        ListNode *h=l;
        ListNode *p=h->next;
        while( p ){
            ListNode * tmp = p->next;
            p->next = h;
            h=p;
            p=tmp;
        }

        //== 比较 ==//
        l = head;
        for( int i=0; i<Nl+1; i++, l=l->next, r=r->next ){
            if( l->val!=r->val ){ return false; }
        }
        return true;


    }
};


//=========================================================//
void main_(){

    ListNode *lt = create_list( { 1,2,1,2,1,2,1 } );

    auto ret = S{}.isPalindrome( lt );

    debug::log( "ret:{}", ret );





    debug::log( "\n~~~~ leet: m02_06 :end ~~~~\n" );
}
}//~
