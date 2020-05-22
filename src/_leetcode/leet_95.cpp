/*
 * ====================== leet_95.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 95. 不同的二叉搜索树 II
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_95 {//~



// 在 96 题基础上 发展出来的方案： 28.72%, 84.21%
class S{
public:

    struct QueElem{
        QueElem(TreeNode *node_,
                TreeNode *newParent_,
                bool isLeft_ ):
                node(node_),
                newParent(newParent_),
                isLeft(isLeft_){}
        TreeNode *node;
        TreeNode *newParent;
        bool isLeft;
    };

    // 复制一颗 modeTree，每个元素的值累加 off，将这个新子树，挂载到 newParent下（左or右）
    void copy_a_tree( TreeNode *newParent, TreeNode *modeTree, int off, bool isLeft ){

        std::deque<QueElem> que {};
        if( modeTree!=nullptr ){ que.emplace_back(modeTree,newParent,isLeft); }
        while( !que.empty() ){
            auto &n = que.front();
            TreeNode *neo = new TreeNode (n.node->val+off);
            if( n.isLeft ){
                n.newParent->left = neo;
                if( n.node->left!=nullptr ){  que.emplace_back( n.node->left,n.newParent->left,true ); }
                if( n.node->right!=nullptr ){ que.emplace_back( n.node->right, n.newParent->left,false); }
            }else{
                n.newParent->right = neo;
                if( n.node->left!=nullptr ){  que.emplace_back( n.node->left,n.newParent->right,true ); }
                if( n.node->right!=nullptr ){ que.emplace_back( n.node->right, n.newParent->right,false); }
            }
            que.pop_front();
        }
    }


    std::vector<TreeNode*> generateTrees( int n ){

        std::vector<std::vector<TreeNode*>> dp (std::max(3,n+1), std::vector<TreeNode*>{}); 
            // 用 [N] 获得一组对应的 树范例
        // 手动装配 [0][1][2] 三种情况
        //[0] 占位, 集合为空
        //[1]
        dp.at(1).push_back( new TreeNode(1) );
        {//[2]
            TreeNode *n1 = new TreeNode(1);
            n1->right =new TreeNode(2);
            TreeNode *n2 = new TreeNode(2);
            n2->left =new TreeNode(1);
            dp.at(2).push_back( n1 );
            dp.at(2).push_back( n2 );
        }

        for( int eachN=3; eachN<=n; eachN++ ){// 依次计算 [3,n] 每种值，它的 二叉树总数

            for( int i=1; i<=eachN; i++ ){// 根节点 val (不是下标)
                int left = i-1; // 左子树个数
                int right = eachN-i; // 右子树个数
                // [1] 左侧树为 null
                if( left==0 && right!=0 ){
                    for( TreeNode *rTree : dp.at(right) ){// 每种 右子树模板
                        dp.at(eachN).push_back( new TreeNode(i) );
                        TreeNode *root = dp.at(eachN).back();// 全新的 树模板
                        copy_a_tree( root, rTree, i, false ); // 生成 右侧子树
                    }
                    continue;
                }
                // [2] 右侧树为 null
                if( left!=0 && right==0  ){
                    for( TreeNode *lTree : dp.at(left) ){// 每种 左子树模板
                        dp.at(eachN).push_back( new TreeNode(i) );
                        TreeNode *root = dp.at(eachN).back();// 全新的 树模板
                        //copy_a_tree( root, lTree, 0, true ); // 生成 左侧子树
                        // 一步优化，不需要复制 左侧树，用指针指向即可
                        root->left = lTree;
                    }
                    continue;
                }
                // [3] 两侧都有元素时
                for( TreeNode *lTree : dp.at(left) ){// 每种 左子树模板
                    for( TreeNode *rTree : dp.at(right) ){// 每种 右子树模板
                        dp.at(eachN).push_back( new TreeNode(i) );
                        TreeNode *root = dp.at(eachN).back();// 全新的 树模板
                        //copy_a_tree( root, lTree, 0, true ); // 生成 左侧子树
                        // 一步优化，不需要复制 左侧树，用指针指向即可
                        root->left = lTree;
                        copy_a_tree( root, rTree, i, false );// 生成 右侧子树
                        
                    }
                }
            }
        }
        return dp.at(n);
    }   



};



//=========================================================//
void main_(){

    

    auto ret = S{}.generateTrees( 3 );

    for( TreeNode *tp : ret ){
        std::vector<TreeNode*> ov = tree_2_vector( tp );
        for( auto *p : ov ){
            (p) ?
                cout << p->val << ", " :
                cout << "null, ";
        }
        cout << "\n=======" << endl;
    }


    
    

    
    

    debug::log( "\n~~~~ leet: 95 :end ~~~~\n" );
}
}//~
