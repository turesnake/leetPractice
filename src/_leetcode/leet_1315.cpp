/*
 * ====================== leet_1315.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1315. 祖父节点值为偶数的节点和
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1315 {//~


// bfs  44%, 100%
class S{
    struct Elem{
        TreeNode *tp {};
        int deep   {};//based on 0
        int paVal  {};
        int gPaVal {};
    };
public:
    int sumEvenGrandparent( TreeNode* root ){
        if( !root ){ return 0; }
        int sum {0};
        std::deque<Elem> que {Elem{root,0,0,0}};
        while( !que.empty() ){
            auto [tp,deep,pa,gPa] = que.front();
            que.pop_front();
            if( deep>1 && (gPa&1)==0 ){ sum += tp->val; }
            if(tp->left){que.push_back(Elem{tp->left,deep+1,tp->val,pa});}
            if(tp->right){que.push_back(Elem{tp->right,deep+1,tp->val,pa});}
        }
        return sum;
    }
};



//=========================================================//
void main_(){

    TreeNode *t = create_a_tree({ 6,7,8,2,7,1,3 });
    cout << S{}.sumEvenGrandparent(t) <<endl;

    
    debug::log( "\n~~~~ leet: 1315 :end ~~~~\n" );
}
}//~
