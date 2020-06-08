/*
 * ====================== leet_721.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 721. 账户合并
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_721 {//~



// 这题 太破了！！！
// 全是无聊的操作


// 并查集  78%, 100%
class S{


// 一个 name，一份数据 
class User{
    std::vector<int> uf {};// 并查集
    std::unordered_map<std::string, int> umap {};// <email,idx>
    std::vector<std::string> emails {};// [idx]=email
    int maxIdx {-1}; // based on 0 访问 并查集

    int find( int v ){
        while( uf.at(v)!=v ){
            v = uf.at(v);
            uf.at(v) = uf.at(uf.at(v));//路径压缩
        }
        return v;
    }

    void merge( int a, int b ){
        int rootA = find(a);
        int rootB = find(b);
        if( rootA!=rootB ){ uf.at(rootA) = rootB; }
    }

public:
    User()=default;
    // [0] name, [i] emails
    void add( std::vector<std::string> &strs ){

        int N = static_cast<int>(strs.size());
        // tmp root
        const auto &rootEmail = strs.at(1);
        int tmpRootIdx {};
        if( umap.find(rootEmail)==umap.end() ){// not find
            maxIdx++;
            tmpRootIdx = maxIdx;
            umap.emplace(rootEmail,maxIdx);
            emails.push_back(rootEmail);
            uf.push_back( maxIdx );
        }else{// find
            tmpRootIdx = umap.at(rootEmail);
        }
        // oth email
        for( int i=2; i<N; i++ ){
            const auto &email = strs.at(i);
            if( umap.find(email)==umap.end() ){// not find
                maxIdx++;
                umap.emplace(email,maxIdx);
                emails.push_back(email);
                uf.push_back( maxIdx );
                merge( tmpRootIdx, maxIdx );
            }else{// find
                merge( tmpRootIdx, umap.at(email) );
            }
        }
    }

    // 将数据写入参数 outs 中 
    void out( const std::string &userName, std::vector<std::vector<std::string>> &outs ){
        /*
            cout<<"emails:"<<endl;
            for( auto &s : emails ){
                cout<<" "<<s <<endl;
            }cout<<endl;
        */

        std::unordered_map<int,std::vector<int>> mp {};
        for( int i=0; i<=maxIdx; i++ ){
            int root = find( i );
            auto [it,bl] = mp.emplace( root, std::vector<int>{} );
            it->second.push_back( i );
        }

        //cout<<"mp.size():"<<mp.size()<<endl;

        std::set<std::string> setts {};// 将 emails 排序 

        for( auto &[root, vs] : mp ){
            outs.push_back( std::vector<std::string>{} );
            auto &con = outs.back();
            con.push_back( userName );

            setts.clear();
            for( int i : vs ){
                setts.insert( emails.at(i) );
            }
            con.insert( con.end(), setts.begin(), setts.end() );
        }
    }
};



public:
    // 1<= accounts.size() <= 1000
    // 1<= accounts[i].size() <= 10
    // 1<= accounts[i][j].size() <= 30
    std::vector<std::vector<std::string>> accountsMerge( std::vector<std::vector<std::string>>& accounts ){

        int N = static_cast<int>(accounts.size());

        std::unordered_map<std::string, User> users {};// <name,user>

        for( auto &c : accounts ){
            auto [it,bl] = users.emplace( c.at(0), User{} );//maybe
            it->second.add( c );
        }

        std::vector<std::vector<std::string>> outs {};

        for( auto &[name, user] : users ){
            user.out( name, outs );
        }
        return outs;
    }
};







//=========================================================//
void main_(){

    std::vector<std::vector<std::string>> v {
        { "a", "a1.e", "a2.e", "a3.e" },
        { "b", "b1.e", "b2.e" },
        { "a", "a4.e", "a2.e", "a6.e" },
        { "a", "a7.e" },
        { "c", "c1.e", "c2.e", "c3.e" }
    };

    auto ret = S{}.accountsMerge(v);


    cout<<"===== ret:====="<<endl;
    for( auto &c : ret ){
        cout<<"--"<<endl;
        for( auto &s : c ){ cout<<"   "<<s<<endl; }
    }


    
    debug::log( "\n~~~~ leet: 721 :end ~~~~\n" );
}
}//~
