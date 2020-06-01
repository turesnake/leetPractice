/*
 * ====================== leet_129.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 129. 求根到叶子节点数字之和
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_129 {//~


// 100%, 6%
class S{

    std::vector<int> road {};
    int sum {0};

    //tp非空
    bool work( TreeNode *tp ){
        road.push_back(tp->val);
        if( !tp->left && !tp->right ){ add_to_sum(); }
        if(tp->left){ 
            bool b = work(tp->left);
            if(b){ return true; }
        }
        if(tp->right){ 
            bool b = work(tp->right);
            if(b){ return true; }
        }
        road.pop_back();
        return false;
    }


    void add_to_sum(){
        int v = 0;
        for( int i : road ){
            v = v*10 + i;
        }
        //cout<<"v = "<<v<<endl;
        sum += v;
    }


public:
    int sumNumbers(TreeNode* root) {
        if(!root){ return 0; }
        work(root);
        return sum;
    }
};


//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: 129 :end ~~~~\n" );
}
}//~
