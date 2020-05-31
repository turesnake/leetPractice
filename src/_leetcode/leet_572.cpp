/*
 * ====================== leet_572.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 572. 另一个树的子树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_572 {//~



class S{

    // a/b 可以为空
    bool isSame( TreeNode* a, TreeNode* b ){
        if( (!a&&b) || (a&&!b) ){ return false; }
        if( !a && !b ){ return true; }
        if( a->val!=b->val ){ return false; }
        bool l = isSame(a->left,b->left);
        bool r = isSame(a->right,b->right);
        return l && r;
    }


public:

    bool isSubtree(TreeNode* s, TreeNode* t) {

        // 找到 目标 父节点
        std::deque<TreeNode*> que {s};
        std::vector<TreeNode*> v {};// 所有符合的节点
        while( !que.empty() ){
            TreeNode *tp = que.front();
            que.pop_front();
            if( tp->val == t->val ){  v.push_back(tp); }
            if(tp->left){ que.push_back(tp->left); }
            if(tp->right){ que.push_back(tp->right); }
        }
        if( v.empty() ){ return false; }
        //-----
        for( TreeNode *ptr : v ){
            bool b = isSame(ptr,t);
            if(b){ return b; }
        }
        return false;
    }

};



//=========================================================//
void main_(){

    TreeNode *p1 = create_a_tree({ 3,4,5,1,niln,2 });
    TreeNode *p2 = create_a_tree({ 3,1,2 });


    cout<<"ret:"<<S{}.isSubtree( p1,p2 )<<endl;


    

    debug::log( "\n~~~~ leet: 572 :end ~~~~\n" );
}
}//~
