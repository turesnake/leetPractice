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


// 从小值开始，逐个拿出来，求其差值B，然后搜索 B 是否在 bst 中
// 这个方法存在一个漏洞
// 如果 A，B 相同，可能会搜到同一个值去
// 简陋的补丁方案是：
// 当发现 AB同值时，检查下一个元素 是否等于本回合元素。
// ---
// 通常，AB同值 将是检查的最后一个元素，要是还找不到，就直接 返回 false 了

class S{

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

    bool findTarget( TreeNode* root, int k ){

        if( !root ){ return false; }
        std::stack<TreeNode*> stk {};
        TreeNode *ptr = root;

        bool isNeedFindSameVal {false};
        int  targetSameVal {};

        while( ptr!=nullptr || !stk.empty() ){
            while( ptr!=nullptr ){
                stk.push(ptr);
                ptr=ptr->left;
            }
            ptr = stk.top();
            stk.pop();
            //===//
            int A = ptr->val;
            int B = k - A;
            // 如果上一回合发现，AB同值，就会进入此检测
            if( isNeedFindSameVal ){ 
                return A==targetSameVal; // AB同值 是流程的最后一个检查元素
            }
            if( A>B ){ 
                return false; // 停止搜索
            }else if( A==B ){
                // 等到下回合，检查元素 是否等于本次的 B
                isNeedFindSameVal = true;
                targetSameVal = B;
            }else{
                // 目前有个问题，如何防止 搜索到的 B，和 A 是同一元素
                if( find(root,B) ){ return true; } 
            }
            //===//
            ptr = ptr->right;//maybe nullptr
        }
        return false;
    }

};





//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 1 } );
    print_a_tree(t);
    cout << "\n======"<<endl;


    debug::log( "ret: {}", S{}.findTarget(t,2) );

    

    

    debug::log( "\n~~~~ leet: 653 :end ~~~~\n" );
}
}//~
