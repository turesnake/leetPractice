/*
 * ====================== leet_617.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 617. 合并二叉树
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_617 {//~


struct Elem{
    Elem()=default;
    TreeNode *tp1 {};
    TreeNode *tp2 {};
};



// bfs
// 将 t2 合并到 t1 上去
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    if( !t1 && !t2 ){ return nullptr; }
    if( !t1 ){ return t2; }
    if( !t2 ){ return t1; }
    std::deque<Elem> que { Elem{t1,t2} };
    while( !que.empty() ){
        auto [tp1,tp2] = que.front();// 必须都不为空
        que.pop_front();
        //=== self ===//
        tp1->val += tp2->val;
        //=== left ===//
        if( tp2->left ){
            if( tp1->left ){
                que.push_back( Elem{tp1->left,tp2->left} );
            }else{
                tp1->left = tp2->left;
            }
        }
        //=== right ===//
        if( tp2->right ){
            if( tp1->right ){
                que.push_back( Elem{tp1->right,tp2->right} );
            }else{
                tp1->right = tp2->right;
            }
        }
    }
    return t1;
}




//=========================================================//
void main_(){


    std::vector<int> v1 { 1,3,2,5 };
    std::vector<int> v2 { 2,1,3,niln,4,niln,7 };

    //std::vector<int> v1 { 1,2 };
    //std::vector<int> v2 { 3,niln,5 };

    TreeNode *t1 = create_a_tree( v1 );
    TreeNode *t2 = create_a_tree( v2 );
    TreeNode *ret = mergeTrees( t1, t2 );

    print_a_tree( ret );
    cout << endl;



    debug::log( "\n~~~~ leet: 617 :end ~~~~\n" );
}
}//~
