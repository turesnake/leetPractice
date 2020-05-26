/*
 * ====================== leet_m32_2.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题32 - II. 从上到下打印二叉树 II
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m32_2 {//~



struct Elem{
    TreeNode    *tp {nullptr};
    int         deep {0};// base on 0
};


std::vector<std::vector<int>> levelOrder( TreeNode* root ){

    if( !root ){ return {}; }
    std::deque<Elem> que { Elem{root,0} };
    std::vector<std::vector<int>> elems {};
    while( !que.empty() ){
        auto [tp,deep] = que.front();
        que.pop_front();
        while( static_cast<int>(elems.size()) < deep+1 ){
            elems.push_back( std::vector<int>{} );
        }
        elems.at(deep).push_back( tp->val );
        if( tp->left  ){ que.push_back( Elem{tp->left,deep+1} ); }
        if( tp->right ){ que.push_back( Elem{tp->right,deep+1} ); }
    }
    return elems; 
}




//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: m32_2 :end ~~~~\n" );
}
}//~
