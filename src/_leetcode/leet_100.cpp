/*
 * ====================== leet_100.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 100. 相同的树
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_100 {//~


// bfs
class S{

struct Elem{
    TreeNode* tp {};// allow nullptr
    TreeNode* tq {};// allow nullptr
};


public:
    bool isSameTree( TreeNode* p, TreeNode* q){

        std::deque<Elem> que {Elem{p,q}};
        while( !que.empty() ){
            auto [tp,tq] = que.front();
            que.pop_front();
            if( !tp && !tq ){ continue; }
            if( (!tp && tq) || 
                (tp && !tq) ||
                (tp->val!=tq->val) ){
                return false;
            }
            que.push_back(Elem{ tp->left, tq->left });
            que.push_back(Elem{ tp->right,tq->right });
        }
        return true;
    }
};





//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 100 :end ~~~~\n" );
}
}//~
