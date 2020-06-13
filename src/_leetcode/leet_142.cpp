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


class S{
public:
    ListNode *detectCycle( ListNode *head ){

        if(!head){ return nullptr; }

        ListNode *f = head;
        ListNode *s = head;

        int si = 0;


        while( f && f->next ){
            f = f->next->next;
            s = s->next;
            si++;
            if( s==f ){// 说明有环
                //计算环长度
                int loopi = 0;
                for( ListNode *l=s; l!=s; l++,loopi++  ){}
                cout<<"loopi:"<<loopi<<endl;




                // 未完...





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
