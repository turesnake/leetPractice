/*
 * ====================== leet_653.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 653. 两数之和 IV - 输入 BST
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_653 {//~


// 未完工...

class Solution {

    // 查找目标元素
    // root 一定不为 nullptr
    bool find( TreeNode* root, int v ){
        if( v==root->val ){  
            return true; 
        }else if( v<root->val ){ 
            return (!root->left) ? false : find(root->left,v);
        }else{ 
            return (!root->right) ? false : find(root->right,v); 
        }
    }


public:

    // 中序遍历
    // root 一定不为空
    /*
    void work( TreeNode* root, int k ){
        if( root->left ){ work(root->left,k); }
        //...
        if( root->right ){ work(root->right,k); }
    }
    */



    bool findTarget( TreeNode* root, int k ){

        if( !root ){ return false; }

        // 未完工


        return false;
    }



};





//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 1,2,3,4,5,6,7 } );
    print_a_tree(t);
    cout << "\n======"<<endl;

    

    

    debug::log( "\n~~~~ leet: 653 :end ~~~~\n" );
}
}//~
