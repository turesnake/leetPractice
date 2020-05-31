/*
 * ====================== leet_199.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 199. 二叉树的右视图
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_199 {//~


// bfs
class S{
    struct Elem{
        TreeNode    *tp {nullptr};
        int         deep {0};//based on 0
    };
public:
    std::vector<int> rightSideView( TreeNode* root ){

        if( !root ){ return {}; }
        std::vector<int> outs {};
        std::deque<Elem> que {Elem{root,0}};
        while( !que.empty() ){
            auto [tp,deep] = que.front();
            que.pop_front();
            if( static_cast<int>(outs.size()) < deep+1 ){
                outs.push_back( tp->val ); // 只被写入一次，就是最右侧的
            }
            if(tp->right){ que.push_back(Elem{tp->right,deep+1}); }
            if(tp->left){  que.push_back(Elem{tp->left,deep+1}); }
        }
        return outs;
    }
};




//=========================================================//
void main_(){

   

    

    debug::log( "\n~~~~ leet: 199 :end ~~~~\n" );
}
}//~
