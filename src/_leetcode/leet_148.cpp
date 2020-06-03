/*
 * ====================== leet_148.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 148. 排序链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_148 {//~


// 归并排序 57%, 12%
class S{
    ListNode *sentry {};//tmp

    // 将两个 链表合并
    ListNode *merge( ListNode *left, int Nl, ListNode *right, int Nr ){
        ListNode *ptr = sentry;
        ListNode *l = left;
        ListNode *r = right;
        int li = 0;
        int ri = 0;
        while( li<Nl || ri<Nr ){
            if( li>=Nl ){// left 空了
                ptr->next = r;
                break;
            }else if( ri>=Nr ){// right 空了
                ptr->next = l;
                break;
            }
            // 两list 都没空
            if( l->val <= r->val ){
                ptr->next = l;
                ptr = ptr->next;
                l = l->next;
                li++;
            }else{
                ptr->next = r;
                ptr = ptr->next;
                r = r->next;
                ri++;
            }
        }
        return sentry->next;
    }

    // lp 可为空
    // n 本区间元素个数 
    ListNode *work( ListNode *lp, int N ){
        if( N==0 ){
            return nullptr;
        }else if( N==1 ){
            lp->next = nullptr;//断开
            return lp;
        }else if( N==2 ){
            if( lp->val <= lp->next->val ){
                lp->next->next = nullptr;//断开
                return lp;
            }else{
                ListNode *tmp = lp->next;
                tmp->next = lp;
                lp->next = nullptr;//断开
                return tmp;
            }
        }
        // when N > 2
        // 找到中间节点
        ListNode *f = lp;// fast
        ListNode *s = lp;// slow
        int fi {0};
        while( fi<N-1 ){
            s = s->next;
            f = f->next;
            fi++;
            if( fi<N-1 ){
                f = f->next;
                fi++;
            }
        }// s: mid-right
        //=== 分 ===//
        int Nl = N/2; //
        int Nr = N-Nl;// 偶尔会比左侧多一个元素
        ListNode *left  = work( lp, Nl );
        ListNode *right = work( s,  Nr );
        //=== 合并 ===//
        return merge( left, Nl, right, Nr );
    }  

public:
    ListNode* sortList(ListNode* head) {
        if(!head){ return nullptr; }
        int N {0};
        ListNode *p = head;
        while(p){
            N++;
            p = p->next;
        }
        sentry = new ListNode (0);// sentry
        return work( head, N );
    }
};



//=========================================================//
void main_(){

    //ListNode *l = create_list({ 1,2,3,4,5,6 });
    ListNode *l = create_list({ 4,6,2,5,7,1,3 });


    ListNode *ret = S{}.sortList(l);

    print_list( ret, "###" );

    


    
    debug::log( "\n~~~~ leet: 148 :end ~~~~\n" );
}
}//~
