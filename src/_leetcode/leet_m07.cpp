/*
 * ====================== leet_m07.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题07. 重建二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m07 {//~


// 迭代 41%, 100%
// 根据 前序/中序 遍历 重建二叉树
class S{
    
    // 使用 指针的指针 来反向绑定 返回值
    struct Elem{
        TreeNode **bind{};// 本回合生成的新节点，绑定到这个指针对象上 
        int preL {};
        int preR {};
        int inL {};
        int inR {};
    };

public:
    // bfs
    TreeNode* buildTree( std::vector<int> preorder, std::vector<int> inorder ){

        if( preorder.empty() ){ return nullptr; }
        int N = static_cast<int>(preorder.size());// 两数组长度相同
        
        TreeNode *root = new TreeNode(0);//sentry
        TreeNode *ptr = root;
        std::deque<Elem> que {Elem{ &root->right, 0,N-1,0,N-1}};
        while( !que.empty() ){
            auto [bind,preL,preR,inL,inR] = que.front();
            que.pop_front();

            int curVal = preorder.at(preL);
            TreeNode *cur = new TreeNode(curVal);
            *bind = cur;

            if( preR==preL ){ continue; }// 本回合节点 为leaf

            int inMid = inL;
            for( ; inorder.at(inMid)!=curVal; inMid++ ){}
            int Nl = inMid-inL;
            int Nr = inR - inMid;
            if(Nl>0){ que.push_back(Elem{ &cur->left, preL+1, preL+Nl, inL, inMid-1 }); }
            if(Nr>0){ que.push_back(Elem{ &cur->right, preR-Nr+1, preR, inMid+1, inR }); }
        }
        return root->right;
    }
};







//=========================================================//
void main_(){

    TreeNode *ret = S{}.buildTree( {1,2}, {2,1} );

    print_a_tree(ret);
    cout<<endl;

    
    debug::log( "\n~~~~ leet: m07 :end ~~~~\n" );
}
}//~
