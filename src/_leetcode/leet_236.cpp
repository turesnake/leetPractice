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

// 93%, 19%
class S{

    std::vector<TreeNode*> v1 {};
    std::vector<TreeNode*> v2 {};
    int nextTarget {};
    bool isFstFind {false};// 已经找到的个数
    int vp {};
    int vq {};

    // tp 非空
    // ret 是否找到两个路径了，不用继续找了
    bool search( TreeNode *tp ){
        v1.push_back(tp);
        int val = tp->val;
        if( !isFstFind ){
            if( val == vp ){
                nextTarget = vq;
                isFstFind = true;
                v2.insert( v2.end(), v1.begin(), v1.end() );
            }else if( val == vq ){
                nextTarget = vp;
                isFstFind = true;
                v2.insert( v2.end(), v1.begin(), v1.end() );
            }
        }else{
            if( val==nextTarget ){ return true; } // find sec
        }
        //---//
        if(tp->left){ 
            bool l = search(tp->left); 
            if(l){ return true; }
        }
        if(tp->right){ 
            bool r = search(tp->right); 
            if(r){ return true; }
        }
        v1.pop_back();
        return false;
    }

public:

    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q ){

        vp = p->val;
        vq = q->val;
        search(root);// 2值一定被找到，两条路径存储在 v1,v2 中
        //cout<<"v1: size="<<v1.size()<<"; "; for( TreeNode *pi : v1 ){ cout<<pi->val<<", "; }cout<<endl;
        //cout<<"v2: size="<<v2.size()<<"; "; for( TreeNode *pi : v2 ){ cout<<pi->val<<", "; }cout<<endl;
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

    TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(7);

    TreeNode *ret = S{}.lowestCommonAncestor( t, a, b );

    cout<<"ret:"<<ret->val <<endl;


    

    debug::log( "\n~~~~ leet: 236 :end ~~~~\n" );
}
}//~
