/*
 * ====================== leet_663.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 663. 均匀树划分
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_663 {//~



// 需要先制作一个 累积和的树，然后再做检查
// 不算是最好的办法


// 23%, 33%
// 由于 元素可能为负数，实际上要老老实实地检测每一条边，直到发现 可断开点
class S{

    struct Elem{
        TreeNode *po {};// origin tree
        TreeNode *ps {};// sumTree
        int outSum {};// 自顶向下遍历，积累的 外层树数据，累加到每个父节点上
    };
    // tp 非空
    TreeNode *build_sumTree( TreeNode *tp ){
        TreeNode *p = new TreeNode (tp->val);
        if(tp->left){ 
            p->left = build_sumTree(tp->left); 
            p->val += p->left->val;
        }
        if(tp->right){
            p->right = build_sumTree(tp->right);
            p->val += p->right->val; 
        }
        return p;
    } 

public:
    // root 非空
    // 节点值 可为负数
    bool checkEqualTree( TreeNode* root ){

        TreeNode *sumTree = build_sumTree(root);
            //print_a_tree(root); cout<<endl;
            //print_a_tree(sumTree); cout<<endl;
        std::stack<Elem> stk {};
        stk.push(Elem{root,sumTree,0});

        while( !stk.empty() ){
            auto [po,ps,outSum] = stk.top();
            stk.pop();
                //cout<<"outSum:"<<outSum << "; po:"<<po->val<<"; ps:"<<ps->val<<endl;
            if( !po->left && !po->right ){ continue; }
            if( !po->right ){// only left
                int vp = po->val+outSum;
                //cout<<"vp = "<<vp<<endl;
                if( vp == ps->left->val ){ return true; }
                stk.push(Elem{po->left,ps->left, vp });

            }else if( !po->left ){// only right
                int vp = po->val+outSum;
                if( vp == ps->right->val ){ return true; }
                stk.push(Elem{po->right,ps->right, vp });

            }else{// both have left, right
                int vp = po->val+outSum;
                int vl = ps->left->val;
                int vr = ps->right->val;
                if( (vp+vl==vr) || (vp+vr==vl) ){ return true; }
                stk.push(Elem{po->left, ps->left,  vp+vr });
                stk.push(Elem{po->right,ps->right, vp+vl });
            }
        }
        return false;// 始终没找到分割方式
    }

};



//=========================================================//
void main_(){

    //TreeNode *t = create_a_tree({ 1,2,3,4,5,6,7 });
    //TreeNode *t = create_a_tree({ 5,10,10,niln,niln,3,2 });
    //TreeNode *t = create_a_tree({ 5 });
    //TreeNode *t = create_a_tree({ -5,-5,0 });
    TreeNode *t = create_a_tree({ 0,-4,-3,niln,-1,8,niln, niln,niln,niln,1, niln,-5,niln,niln, });

    bool ret = S{}.checkEqualTree(t);
    debug::log( "ret:{}",ret );
    

    debug::log( "\n~~~~ leet: 663 :end ~~~~\n" );
}
}//~
