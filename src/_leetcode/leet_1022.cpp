/*
 * ====================== leet_1022.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1022. 从根到叶的二进制数之和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1022 {//~


// dfs  50%, 60%
class S{

    int sum {0};
    std::vector<int> road {};

    // tp not null
    void work( TreeNode *tp ){
        road.push_back(tp->val);
        if( !tp->left && !tp->right ){//leaf
            calc_num();
        }
        if(tp->left){ work(tp->left); }
        if(tp->right){ work(tp->right); }
        road.pop_back();
    }

    void calc_num(){
        int num = 0;
        for( int i : road ){
            num<<=1;
            num += i;
        }
        num %= 1000000007;
        cout<<"num:"<<num<<endl;
        sum = (sum+num)%1000000007;
    }

public:
    // 树非空
    int sumRootToLeaf( TreeNode* root ){
        work(root);
        return sum;
    }
};



//=========================================================//
void main_(){

    TreeNode *t = create_a_tree({ 1,0,1,0,1,0,1 });

    cout << S{}.sumRootToLeaf(t) <<endl;



    
    debug::log( "\n~~~~ leet: 1022 :end ~~~~\n" );
}
}//~
