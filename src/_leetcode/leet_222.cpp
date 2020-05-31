/*
 * ====================== leet_222.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 222. 完全二叉树的节点个数
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_222 {//~


// 这并不是最好的办法 


// 34%, 10%
class S{

    int targetIdx {};

    // idx 是本回合元素的 idx
    // tp 不为空
    // ret: true: 表示不用检测了直接返回
    bool work( TreeNode *tp, int idx ){
        if(tp->right){ 
            bool l = work(tp->right, idx*2+1); 
            if(l){ return true; }
        }
        if(tp->left){ 
            bool r = work(tp->left, idx*2); 
            if(r){ return true; }
        }
        if( idx >= targetIdx ){
            targetIdx = idx;
            return true;
        }else{
            return false;
        }
    }


public:
    int countNodes(TreeNode* root) {

        if( !root ){ return 0; }
        // 计算 最底层 左侧首元素 idx(base on 1)
        targetIdx = 1;
        TreeNode *ptr = root;
        while( ptr ){
            if( ptr->left ){
                targetIdx = targetIdx*2;
                ptr = ptr->left;
                continue;
            }
            if( ptr->right ){
                targetIdx = targetIdx*2+1;
                ptr = ptr->right;
                continue;
            }
            break;
        }
        // 找到目标元素
        work( root, 1 );
        return targetIdx;
    }
};



//=========================================================//
void main_(){

    //TreeNode *t = create_a_tree({ 1,2,3,4,5,6,7,8,9 });
    TreeNode *t = create_a_tree({ 1,2,3,4,5 });
    //TreeNode *t = create_a_tree({ 1,2,3,4 });

    int ret = S{}.countNodes(t);
    cout<<"ret = " << ret <<endl;
    

    debug::log( "\n~~~~ leet: 222 :end ~~~~\n" );
}
}//~
