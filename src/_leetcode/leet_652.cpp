/*
 * ====================== leet_652.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 652. 寻找重复的子树
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_652 {//~


// 普通的解法，这题会超时
// 需要将每棵树都序列化，hash化


// 目前这种，将整颗 子树 序列化的 操作，效率很低
// 还可制造一种 更紧凑的 标示符



// 后续遍历  5%， 100%
class S{

    struct Elem{
        TreeNode    *tp      {nullptr};
        bool        isSingle {true};
    };

    std::unordered_map<std::string,Elem> umap {};// <hash,elem>


    std::string serialize_and_hash(TreeNode* root) {
        if(!root){ return ""; }
        std::vector<TreeNode*> tps {};
        std::deque<TreeNode*> que {root};
        while( !que.empty() ){
            TreeNode *tp = que.front();
            que.pop_front();
            tps.push_back(tp);// 不管是不是 nullptr
            if(!tp){ continue; }
            que.push_back(tp->left);
            que.push_back(tp->right);
        }
        //去掉尾部 nullptr
        while( tps.back()==nullptr ){
            tps.pop_back();
        }
        // to string
        std::string out {};
        for( TreeNode *tp : tps ){
            out += tp ? std::to_string(tp->val) : "N";
            out += ",";
        }
        return out;
    }


    // 需要忠实地遍历每一个节点
    // tp not null
    void work( TreeNode *tp ){
        if(tp->left){work(tp->left);}
        if(tp->right){work(tp->right);}
        // HANDLE
        std::string strKey = serialize_and_hash(tp);
        auto fit = umap.find( strKey );
        if( fit==umap.end() ){//not find
            umap.emplace( strKey, Elem{tp,true} );
        }else{//find
            fit->second.isSingle = false;
        }
    }


public:
    std::vector<TreeNode*> findDuplicateSubtrees( TreeNode* root ){

        if(!root){ return {}; }
        work(root);
        std::vector<TreeNode*> outs {};
        for( auto &[strKey,elem] : umap ){
            if( !elem.isSingle ){
                outs.push_back(elem.tp);
            }
        }
        return outs;
    }
};





//=========================================================//
void main_(){

    //TreeNode *t = create_a_tree({ 1,2,3,4,niln,2,4,niln,niln,4 });
    TreeNode *t = create_a_tree({ 1,2,2 });

    auto ret = S{}.findDuplicateSubtrees(t);
    
    for( TreeNode *tp : ret ){
        print_a_tree(tp);
        cout<<endl;
    }
    

    

    
    debug::log( "\n~~~~ leet: 652 :end ~~~~\n" );
}
}//~
