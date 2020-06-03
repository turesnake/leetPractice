/*
 * ====================== leet_92.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 92. 反转链表 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_92 {//~


// 反转链表的题 写起来很生疏 


// 67%, 100%
class S{
    ListNode *newM {};
    ListNode *newN {};

    void work( ListNode *mp, int times ){

        ListNode *l = mp;
        ListNode *r = mp->next;
        for( int i=0; i<times; i++ ){
            ListNode *rnext = r->next;
            r->next = l;
            l = r;
            r = rnext;
        }
        newM = l;
        newN = mp;
    }
public:
    // based on 1
    // 1 ≤ m ≤ n ≤ 链表长度。所以无需做 null 检测
    ListNode* reverseBetween( ListNode* head, int m, int n ){

        if( m==n ){ return head; }
        ListNode *root = new ListNode (0);//sentry
        root->next = head;
        ListNode *before {nullptr};
        ListNode *after  {nullptr};
        ListNode *mp     {nullptr};
        ListNode *np     {nullptr};
        //--//
        ListNode *p = head;
        if( m==1 ){
            before = root;
            mp = head;
            for( int i=1; p && i<=n; p=p->next,i++ ){
                if( i==n ){ np = p; }
            }
        }else{
            for( int i=1; p && i<=n; p=p->next,i++ ){
                if(       i==m-1 ){ before = p;
                }else if( i==m ){   mp = p;
                }else if( i==n ){   np = p; }
            }
        }
        after = np->next;//maybe nullptr
        //--//
        work( mp, n-m );
        before->next = newM;
        newN->next = after;
        return root->next;
    }
};



//=========================================================//
void main_(){

    ListNode *l = create_list({ 1,2 });

    ListNode *ret = S{}.reverseBetween( l, 1,2 );

    print_list( ret, "KKK" );

    
    debug::log( "\n~~~~ leet: 92 :end ~~~~\n" );
}
}//~
