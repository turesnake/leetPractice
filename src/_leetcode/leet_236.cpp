/*
 * ====================== leet_236.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 236. 二叉树的最近公共祖先
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_236 {//~



// 未完成 


class S{
public:

    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q ){

        std::vector<TreeNode*> v1 {};
        std::vector<TreeNode*> v2 {};
        int nextTarget {};
        int findNum {0};// 已经找到的个数

        std::stack<TreeNode*>stk {};
        stk.push( root );

        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            stk.pop();
            int val = tp->val;
            v1.push_back(tp);

            if( findNum==0 ){
                if( val == p->val ){
                    nextTarget = q->val;
                    findNum++;
                    v2.insert( v2.end(), v1.begin(), v1.end() );
                }else if( val == q->val ){
                    nextTarget = p->val;
                    findNum++;
                    v2.insert( v2.end(), v1.begin(), v1.end() );
                }
            }else if( findNum==1 ){
                if( val==nextTarget ){
                    findNum++;
                    break;
                }
            }
            if(tp->right){  
                stk.push(tp->right); 
                //v1.pop_back(); 
            }
            if(tp->left){  
                stk.push(tp->left);  
                //v1.pop_back(); 
            }
            v1.pop_back(); 

        }
        // 2值一定被找到，两条路径存储在 v1,v2 中

        cout<<"v1:";
        for( TreeNode *p : v1 ){ cout<<p->val<<", "; }cout<<endl;

        cout<<"v2:";
        for( TreeNode *p : v2 ){ cout<<p->val<<", "; }cout<<endl;


        int N1 = static_cast<int>(v1.size());
        int N2 = static_cast<int>(v2.size());
        int idx = 0;
        for( int i=0; i<N1 && i<N2; i++ ){
            if( v1.at(i)->val==v2.at(i)->val ){
                idx = i;
            }else{
                break;
            }
        }
        return v1.at(idx);
    }



};




//=========================================================//
void main_(){

    TreeNode *t = create_a_tree({ 1,2,3,4,5,6,7 });

    TreeNode *a = new TreeNode(2);
    TreeNode *b = new TreeNode(7);

    TreeNode *ret = S{}.lowestCommonAncestor( t, a, b );

    cout<<"ret:"<<ret->val <<endl;


    

    debug::log( "\n~~~~ leet: 236 :end ~~~~\n" );
}
}//~
