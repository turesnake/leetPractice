/*
 * ====================== leet_437.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 437. 路径总和 III
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_437 {//~


// 88%   30%
// dfs，然后用 前缀和来实现 路径上的 区间和计算 
// 由于存在负数，必须完整地遍历整颗树
// 在每个节点做检测，而是等到 leaf节点才做
// 需要为 root 节点 预设 0


class S{

    std::unordered_map<int,int> umap {};// 辅助用
    std::vector<int> preSums {};// road 前缀和
    int targetSum {};
    int outSum {0};

    // tp not null
    // deep: based on 0
    void work( TreeNode *tp ){

        //-- 本回合累加和 --//
        int preSum = tp->val;
        if( !preSums.empty() ){ preSum+=preSums.back(); }
        //------//

        int off = preSum-targetSum;
        if( umap.count(off)>0 ){
            /*
            cout<<"tpval:"<<tp->val
                <<", preSum:"<<preSum
                <<", off:"<<off
                <<", [off]:"<< umap.at(off)
                <<endl;
            cout<<"---- ";
            for( auto [k,v] : umap ){
                cout<<"["<<k<<","<<v<<"]; ";
            }cout<<endl;
            */
            outSum += umap.at(off);
        }
        //-- insert --//
        preSums.push_back( preSum );
        umap[preSum]++;
        
        if(tp->left){work(tp->left);}
        if(tp->right){work(tp->right);}
        preSums.pop_back();
        if( umap[preSum]==1 ){
            umap.erase(preSum);
        }else{
            umap[preSum]--;
        }
    }


public:
    int pathSum( TreeNode* root, int sum ){
        
        if(!root){ return 0; }
        umap[0]=1; // 主要是照顾 root 元素
        targetSum = sum;
        work(root);
        return outSum;
    }
};



//=========================================================//
void main_(){
    
    TreeNode *t = create_a_tree({ 0,1,1 });

    cout<<"ret:"<<S{}.pathSum( t, 1 )<<endl;
    

    
    debug::log( "\n~~~~ leet: 437 :end ~~~~\n" );
}
}//~
