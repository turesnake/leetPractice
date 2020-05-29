/*
 * ====================== leet_1302.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1302. 层数最深叶子节点的和
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_1302 {//~




// bfs 朴素 71%, 9%
class S1{
    struct Elem{
        Elem(TreeNode *tp_, int deep_):
            tp(tp_),deep(deep_){}
        TreeNode *tp {nullptr};
        int     deep {0};//based on 0
    };
public:

    int deepestLeavesSum( TreeNode* root ){
        if( !root ){ return 0; }
        std::deque<Elem> que {Elem{root,0}};
        int maxDeep {0};
        int sum {0};
        while( !que.empty() ){
            auto [tp,deep] = que.front();
            que.pop_front();
            if( !tp->left && !tp->right ){
                if( deep > maxDeep ){
                    maxDeep = deep;
                    sum = tp->val;
                }else{
                    sum += tp->val;
                }
            }
            if(tp->left){ que.emplace_back(tp->left,deep+1); }
            if(tp->right){ que.emplace_back(tp->right,deep+1); }
        }
        return sum;
    }
};




//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 1302 :end ~~~~\n" );
}
}//~
