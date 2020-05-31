/*
 * ====================== leet_m27.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题27. 二叉树的镜像
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m27 {//~


TreeNode* mirrorTree(TreeNode* root) {

    if( !root ){ return nullptr; }
    std::swap(root->left,root->right);
    if(root->left){ mirrorTree(root->left); }
    if(root->right){ mirrorTree(root->right); }
    return root;
}




//=========================================================//
void main_(){

    TreeNode *t = create_a_tree({ 1,2,3,4,5,6,7 });

    TreeNode *ret = mirrorTree(t);

    print_a_tree(ret);
    cout<<endl;


    

    debug::log( "\n~~~~ leet: m27 :end ~~~~\n" );
}
}//~
