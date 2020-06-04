/*
 * ====================== leet_160.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 160. 相交链表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_160 {//~

// 双指针循环法
// 假设 ab 相交，
// a 的长度为 4+2
// b 的长度为 3+2
// 让指针pa，走完a后从b头继续走，指针pb也是，走完b后，从a头部继续走
// 那么，当走完 a.size()+b.size() 长度后，
// 如果 pa，pb 相同，这个节点就是交点
// 否则，两链表 就是不想交的
// 时间 O[m+n]
// 空间 O[1]
class S{
public:
    ListNode *getIntersectionNode( ListNode *headA, ListNode *headB ){

        if( !headA || !headB ){ return nullptr; }
        ListNode *pa = headA;
        ListNode *pb = headB;
        // 当 pa/pb 完成 m+n 个节点的遍历后，会都等于 nullptr
        // 然后推出 while 循环
        while( pa!=pb ){ 
            pa = !pa ? headB : pa->next;
            pb = !pb ? headA : pb->next;
        }
        return pa;
    }

    // 更为繁琐的写法 
    ListNode *getIntersectionNode2( ListNode *headA, ListNode *headB ){

        if( !headA || !headB ){ return nullptr; }
        ListNode *pa = headA;
        ListNode *pb = headB;

        int Na = 0;
        int Nb = 0;
        for( ;pa; pa=pa->next ){ Na++; }
        for( ;pb; pb=pb->next ){ Nb++; }
        pa = headB;
        pb = headA;
        int Nsml = std::min(Na,Nb);
        if( Na > Nb ){
            int off = Na-Nb;
            for( int i=0; i<off; i++ ){ pb=pb->next; }
        }else if( Na < Nb ){
            int off = Nb-Na;
            for( int i=0; i<off; i++ ){ pa=pa->next; }
        }
        for( int i=0; i<Nsml; i++ ){
            if( pa == pb ){
                return pa; 
            }
            pa=pa->next;
            pb=pb->next;
        }
        return nullptr;
    }
};




//=========================================================//
void main_(){

    // 这样实现例子是错误的
    // 最终，两个链表的 尾部并不真的 相交
    ListNode *a = create_list({ 1,2,3,4,9,99 });
    ListNode *b = create_list({   5,6,7,9,99 });

    ListNode *ret = S{}.getIntersectionNode( a,b );

    print_list(ret,"MM");

    
    debug::log( "\n~~~~ leet: 160 :end ~~~~\n" );
}
}//~
