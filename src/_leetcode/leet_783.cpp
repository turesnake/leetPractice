/*
 * ====================== leet_783.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 783. 二叉搜索树节点最小距离
 * 与 530 相同 
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_783 {//~


// 注意，这题的要求是：“任意两个节点间”



// 暴力法
// 树节点个数 [2,100]
int minDiffInBST( TreeNode* root ){

    std::set<int> sett {};
    std::deque<TreeNode*> que {root};
    while( !que.empty() ){
        auto *tp = que.front();
        que.pop_front();
        sett.insert(tp->val);
        if(tp->left){  que.push_back(tp->left); }
        if(tp->right){ que.push_back(tp->right); }
    }

    int mmin {INT_MAX};
    auto it = sett.begin();
    int l = *it;
    it++;
    for( ; it!=sett.end(); it++ ){
        mmin = std::min( mmin, std::abs(*it-l) );
        l = *it;
    }
    return mmin;
}


// 但是因为这是颗 二叉搜索树，其实可以用 中序遍历（一定有序）  78%, 100%
class S{
    int mmin {INT_MAX};
    int lstVal {};
    bool isFst {true};

    void work( int v ){
        if( isFst ){
            isFst = false;
            lstVal = v;
        }else{
            mmin = std::min( mmin, std::abs(v-lstVal) );
            lstVal = v;
        }
    }
public:
    int minDiffInBST( TreeNode* root ){
        std::stack<TreeNode*> stk {};
        TreeNode *ptr = root;
        while( ptr || !stk.empty() ){
            if( ptr ){
                // 无限下探，寻找 最左元素
                stk.push(ptr);
                ptr = ptr->left;
            }else{
                ptr = stk.top();
                stk.pop();
                work( ptr->val );
                ptr = ptr->right;
            }
        }
        return mmin;
    }
};





//=========================================================//
void main_(){

    TreeNode *p = create_a_tree( { 10,5,15,1,7,13,20 } );

    cout << S{}.minDiffInBST(p) << endl;




    debug::log( "\n~~~~ leet: 783 :end ~~~~\n" );
}
}//~
