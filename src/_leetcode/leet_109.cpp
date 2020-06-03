/*
 * ====================== leet_109.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 109. 有序链表转换二叉搜索树
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_109 {//~




// 朴素法 42%， 9%
// 用快慢指针，寻找 链表的 mid-right
class S{
    // n 表达本区间元素个数，lp是第一个 
    // lp 非空
    TreeNode* work( ListNode* lp, int n ){
        ListNode *f = lp;// fast
        ListNode *s = lp;// slow
        int si = 0;
        int fi = 0;
        while( fi<n-1 ){// 只能跳 n-1 次
            s = s->next;
            f = f->next;
            si++;
            fi++;
            if( fi<n-1 ){
                f = f->next;
                fi++;
            }
        }
        // s 指向 mid-right, f 指向 区间最后一个元素 
        //debug::log( "si:{}, fi:{}", si, fi );
        int ln = si;   // 前半区间长度
        int rn = fi-si;// 后半区间长度
        TreeNode *parent = new TreeNode(s->val);
        if(ln>0){ parent->left = work(lp,ln); }
        if(rn>0){ parent->right = work(s->next,rn); }
        return parent;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head){ return nullptr; }
        ListNode *p = head;
        int N = 0;
        while( p ){
            p = p->next;
            N++;
        }
        return work( head, N );
    }
};





//=========================================================//
void main_(){

    ListNode *l = create_list({ 0,1,2,3,4,5 });

    //S{}.work(l,3);
    S{}.sortedListToBST( l );
  
    debug::log( "\n~~~~ leet: 109 :end ~~~~\n" );
}
}//~
