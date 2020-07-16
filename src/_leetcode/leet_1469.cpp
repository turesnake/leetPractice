/*
 * ====================== leet_1469.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1469. 寻找所有的独生节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1469 {//~


// bfs   8%   100%
class S{
public:
    std::vector<int> getLonelyNodes( TreeNode* root ){

        if( !root ){ return {}; }

        std::vector<int> outs {};
        std::deque<TreeNode*> que { root };

        while( !que.empty() ){
            TreeNode *tp = que.front();
            que.pop_front();

            if( tp->left ){
                if(!tp->right){ outs.push_back(tp->left->val); }
                que.push_back(tp->left);
            }
            if( tp->right ){
                if(!tp->left){ outs.push_back(tp->right->val); }
                que.push_back(tp->right);
            }
        }
        return outs;

        
    }
};


//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 1469 :end ~~~~\n" );
}
}//~
