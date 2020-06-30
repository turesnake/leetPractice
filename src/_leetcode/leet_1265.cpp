/*
 * ====================== leet_1265.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1265. 逆序打印不可变链表
 */
#include "innLeet.h"


namespace leet_1265 {//~


class ImmutableListNode {
public:
   void printValue(); // print the value of the node.
   ImmutableListNode* getNext(); // return the next node.
};


class S{
public:
    void printLinkedListInReverse(ImmutableListNode* head) {

        if( !head ){ return; }
        printLinkedListInReverse( head->getNext() );
        head->printValue();
        
    }
};





//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1265 :end ~~~~\n" );
}
}//~
