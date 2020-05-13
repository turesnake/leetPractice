/*
 * ====================== leet_617.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 617. 合并二叉树
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_617 {//~


// 保证 t1,t2 一定非空
TreeNode* mergeHelper(TreeNode* t1, TreeNode* t2) {





    return nullptr;
}


// 将 t2 合并到 t1 上去
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    if( !t1 && !t2 ){ return nullptr; }
    if( !t1 ){ return t2; }
    if( !t2 ){ return t1; }

    return mergeHelper( t1, t2 );

}




//=========================================================//
void main_(){

    int Nil {INT_MIN};

    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,2,3,3,Nil,Nil,4,4 };
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,3,4,5 };

    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 3,9,8,4,0,1,7 };
    std::vector<int> inputs { 3,9,8,4,0,1,7,Nil,Nil,Nil,2,5 };

    TreeNode *treeRoot = create_a_tree( inputs );
    print_a_tree( treeRoot );
    cout << endl;



    debug::log( "\n~~~~ leet: 617 :end ~~~~\n" );
}
}//~
