/*
 * ====================== leet_112.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 112. 路径总和
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_112 {//~



// 因为 各个元素值可能为负数，一定要遍历到 叶节点才做判断
class S{
    struct Elem{
        TreeNode    *tp {};
        int         leftSum {};// 剩余的，需要消化的值
    };
public:
    bool hasPathSum( TreeNode* root, int sum ){

        if(!root){ return false; }
        std::deque<Elem> que { Elem{root,sum} };
        while( !que.empty() ){
            auto [tp,leftSum] = que.front();
            que.pop_front();
            int off = leftSum - tp->val;

            if( off==0 && !tp->left && !tp->right ){
                return true;// 找到目标
            }

            if(tp->left){  que.push_back(Elem{tp->left, off}); }
            if(tp->right){ que.push_back(Elem{tp->right,off}); }
        }
        return false;
    }
};




//=========================================================//
void main_(){


    
    std::vector<int> v { 3,3,3 };

    TreeNode *t = create_a_tree( v );
    print_a_tree( t );
    cout << endl;

    //auto ret = S{}.longestUnivaluePath( t );
    //cout<<"ret: " << ret<< endl;


    debug::log( "\n~~~~ leet: 112 :end ~~~~\n" );
}
}//~
