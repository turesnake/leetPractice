/*
 * ====================== leet_234.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 234. 回文链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_234 {//~


// 将后半段链表翻转，然后比较 57%， 5%
class S{
public:
    bool isPalindrome( ListNode* head ){

        if( !head || !head->next ){ return true; }
        //--- 找到 mit-left ---//
        ListNode *f = head;
        ListNode *s = head;
        while( f->next ){
            f = f->next;     
            if(!f->next){ break; }
            f = f->next;
            s = s->next;
        }// s: mid-left
        //--- 将后半段 翻转 ----//
        ListNode *l = s->next;
        ListNode *r = l->next;
        if(r){
            l->next = nullptr;
            while(r){
                ListNode *tmp = r->next;
                r->next = l;
                l = r;
                r = tmp;
            }// l 指向最后一元素
            s->next = l;
        }
        //--- 对比两个区间 ---//
        // 若链表奇数个，right段短一个
        l = head;
        r = s->next;
        for( ; r; l=l->next,r=r->next ){
            if( l->val!=r->val ){  return false; }
        }
        return true;
    }
};



//=========================================================//
void main_(){

    ListNode *l = create_list({ 1,2,3,4,5,5,4,3,2,1  });

    cout<< S{}.isPalindrome(l) <<endl;
    
    debug::log( "\n~~~~ leet: 234 :end ~~~~\n" );
}
}//~
