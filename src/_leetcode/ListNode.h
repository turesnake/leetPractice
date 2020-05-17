/*
 * ======================== ListNode.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_LIST_NODE_H
#define TPR_LIST_NODE_H
#include "innLeet.h"




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


inline ListNode* create_list( std::vector<int> v_ ){

    ListNode* root {nullptr};
    ListNode* p {nullptr};
    
    for( size_t idx =0; idx<v_.size(); idx++ ){

        ListNode* newP = new ListNode ( v_.at(idx) );
        if( idx == 0 ){
            root = newP;
            p = root;
        }else{
            p->next = newP;
            p = p->next;
        }
    }
    return root;
}


inline void print_list( ListNode* l_, const std::string &str_ ){

    debug::log( "{}:",str_ );
    while( l_ ){
        debug::log( "  -> {} ", l_->val );
        l_ = l_->next;
    }
    debug::log( "\n" );
}


inline ListNode* get_listNode( ListNode* l_, size_t idx_ ){

    ListNode* p { l_ };
    for( size_t i=0; i<idx_; i++ ){
        tprAssert( p->next );
        p = p->next;
    }
    return p;
}






#endif 

