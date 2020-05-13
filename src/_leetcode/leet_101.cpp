/*
 * ====================== leet_101.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 101. 对称二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_101 {//~


// 左右翻转
TreeNode* flip( TreeNode *root ){
    if( !root ){ return nullptr; }
    std::swap(root->left, root->right);
    flip(root->left);
    flip(root->right);
    return root;
}


// 繁琐的比较
bool is_two_tree_same( TreeNode* a, TreeNode* b ){
    if( !a && !b ){ return true; }
    if( !a || !b ){ return false; }
    return  is_two_tree_same(a->left, b->left) && 
            is_two_tree_same(a->right, b->right) &&
            (a->val==b->val);
}



bool isSymmetric( TreeNode* root ){
    if( !root ){ return true; }
    if( !root->left && !root->right ){ return true; }
    if( !root->left || !root->right ){ return false; }
    return is_two_tree_same( root->left, flip(root->right) );
}



//=========================================================//
void main_(){

    int Nil {INT_MIN};

    //std::vector<int> inputs1 { 2,97,97,Nil,47,80,Nil,Nil,Nil,-7,Nil,Nil,-7,Nil,Nil };
    std::vector<int> inputs1 { 97,0,80,Nil,Nil,-7,Nil };
    std::vector<int> inputs2 { 97,0,80,Nil,Nil,-7,Nil };
    //std::vector<int> inputs2 { 1,2,Nil,4 };
    //std::vector<int> inputs { 1,2,3,4,5 };
    //std::vector<int> inputs { 1,2,3,4,5,Nil,Nil,8,9,10,11,Nil,Nil,Nil,Nil,16 };

    TreeNode *t1 = create_a_tree( inputs1 );
    //TreeNode *t1 = nullptr;
    TreeNode *t2 = create_a_tree( inputs2 );
    //TreeNode *treeRoot = nullptr;

    //print_a_tree( tree1 );
    //cout << endl;



    //---
    //bool ret = isSymmetric( t1 );
    bool ret = is_two_tree_same( t1, t2 );
    debug::log( "bool = {}", ret );
    
    

    debug::log( "\n~~~~ leet: 101 :end ~~~~\n" );
}
}//~
