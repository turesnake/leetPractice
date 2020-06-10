/*
 * ====================== leet_449.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 449. 序列化和反序列化二叉搜索树
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_449 {//~


// 反序列化显然更难


//  51%  25% 
class S{
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {

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

    // Decodes your encoded data to tree.
    // "1,2,3,N,5"
    // 借用 deque 来实现树的复原 
    TreeNode* deserialize( std::string data) {

        int N = static_cast<int>(data.size());
        std::vector<TreeNode*> tps {};

        for( int l=0,r=0; r<N; r++,l=r ){
            for( ; r<N && data.at(r)!=','; r++ ){}//推出时，r==N or =','
            std::string word (data, l, r-l);
            //cout<<"word:"<<word<<endl;
            if( word == "N" ){
                tps.push_back(nullptr);
            }else{
                int val = std::stoi(word);
                //cout<<"int val:"<<val<<endl;
                tps.push_back( new TreeNode(val) );
            }
        }
        if( tps.empty() || tps.at(0)==nullptr ){ return nullptr; }
        
        TreeNode *root= new TreeNode(0);//sentry
        int Ntps = static_cast<int>(tps.size());
        std::deque<TreeNode**> que { &root->right };

        for( int i=0; !que.empty() && i<Ntps; i++ ){
            TreeNode **pp = que.front();
            que.pop_front();
            TreeNode *tp = tps.at(i);
            if( tp!=nullptr ){
                *pp = tp;//bind
                que.push_back( &tp->left );
                que.push_back( &tp->right );
            }
        }
        return root->right;
    }
};




//=========================================================//
void main_(){

    std::string s {"5,4,7,3,N,2,N,-1,N,9"};


    TreeNode *retTree = S{}.deserialize( s );

    //cout<<"ret tree:"<<endl;
    //print_a_tree( retTree );

    cout << S{}.serialize(retTree)<<endl;

    

    
    debug::log( "\n~~~~ leet: 449 :end ~~~~\n" );
}
}//~
