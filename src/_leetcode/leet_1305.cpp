/*
 * ====================== leet_1305.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1305 {//~


// 48%, 6%
class S{
    std::stack<TreeNode*> stk1 {};
    std::stack<TreeNode*> stk2 {};
    TreeNode *p1 {};
    TreeNode *p2 {};
    
    // INT_MAX 表示树已空
    int next1(){
        if( p1 || !stk1.empty() ){
            //--1--//
            while(p1){
                stk1.push(p1);
                p1=p1->left;
            }
            p1 = stk1.top();
            stk1.pop();
            int ret = p1->val;
            p1=p1->right;
            return ret;
        }else{
            return INT_MAX;
        }
    }
    // INT_MAX 表示树已空
    int next2(){
        if( p2 || !stk2.empty() ){
            //--1--//
            while(p2){
                stk2.push(p2);
                p2=p2->left;
            }
            p2 = stk2.top();
            stk2.pop();
            int ret = p2->val;
            p2=p2->right;
            return ret;
        }else{
            return INT_MAX;
        }
    }

public:
    
    std::vector<int> getAllElements( TreeNode* root1, TreeNode* root2 ){

        std::vector<int> outs {};
        p1 = root1;
        p2 = root2;
        int v1 = next1();
        int v2 = next2();

        while( !(v1==INT_MAX && v2==INT_MAX) ){

            if( v1==INT_MAX ){// 树1已空
                outs.push_back(v2);
                v2 = next2();
            }else if( v2==INT_MAX ){// 树2已空
                outs.push_back(v1);
                v1 = next1();
            }else{// 两树都有值
                if( v1<=v2 ){
                    outs.push_back(v1);
                    v1 = next1();
                }else{
                    outs.push_back(v2);
                    v2 = next2();  
                }
            }
        }
        return outs;
    }
};





//=========================================================//
void main_(){

    TreeNode *t1 = create_a_tree({  });
    TreeNode *t2 = create_a_tree({  });

    auto ret = S{}.getAllElements( t1, t2 );

    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;

   

    debug::log( "\n~~~~ leet: 1305 :end ~~~~\n" );
}
}//~
