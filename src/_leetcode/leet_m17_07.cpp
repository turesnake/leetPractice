/*
 * ====================== leet_m17_07.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.07. 婴儿名字
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_m17_07 {//~


// 这题真正麻烦在：
// -1- 需要切割字符串
// -2- 需要 比较字符串的 字典序: a.compare(b) 来实现


// 并查集   60%，  27%
class S{


class UnionFindSet{
    std::vector<int> st {};
    int N {};
public:
    explicit UnionFindSet(int N_):N(N_){
        st.assign(N,0);
        for( int i=0; i<N; i++ ){
            st[i] = i;
        }
    }
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
    void merge( int a, int b ){
        int ra = find(a);
        int rb = find(b);
        if( ra==rb ){ return; }
        st[rb] = ra;
    }

    bool isSameRoot( int a, int b ){
        return find(a)==find(b);
    }
};
struct Elem{
    std::string minRoot {};
    int sum {};
};


public:
    // names.length <= 100000
    std::vector<std::string> trulyMostPopular(  std::vector<std::string>& names, 
                                                std::vector<std::string>& synonyms) {

        int Nn = static_cast<int>(names.size());
        int Ns = static_cast<int>(synonyms.size());

        std::vector<std::string> nameStrs (Nn, "");
        std::vector<int>         nameWs   (Nn, 0);
        std::unordered_map<std::string, int> nameIds {};

        for( int i=0; i<Nn; i++ ){
            int Ne = static_cast<int>(names[i].size());
            auto mid = names[i].find_first_of( '(' );
            std::string name ( names[i], 0, mid );
            int w = std::stoi( std::string( names[i], mid+1, Ne-1-(mid+1) ) );
            nameStrs[i] = name;
            nameWs[i] = w;
            nameIds.emplace( name, i );
        }

        UnionFindSet ufs {Nn};

        for( auto &e : synonyms ){
            int Ne = static_cast<int>(e.size());
            auto mid = e.find_first_of( ',' );
            std::string l ( e, 1, mid-1 );
            std::string r ( e, mid+1, Ne-1-(mid+1) );
            ufs.merge( nameIds[l], nameIds[r] );
        }

        std::unordered_map<int, Elem> umap {};//<ufsRoot,elem>

        for( int i=0; i<Nn; i++ ){
            int ufsRoot = ufs.find(i);

            if( umap.count(ufsRoot)==0 ){
                umap.emplace( ufsRoot, Elem{ nameStrs[i], nameWs[i] } );
            }else{
                if(umap[ufsRoot].minRoot.compare(nameStrs[i])>0){// 字典序
                    umap[ufsRoot].minRoot = nameStrs[i];
                }
                umap[ufsRoot].sum += nameWs[i];
            }
        }

        std::vector<std::string> ans {};
        for( auto &[k,e] : umap ){
            ans.push_back( e.minRoot + "(" + std::to_string(e.sum) + ")" );
        }
        return ans;

    }
};





//=========================================================//
void main_(){

    std::string a = "john";
    std::string b = "jon";


    auto ret  = a.compare(b);
    cout<<"ret:"<<ret<<endl;
    


    debug::log( "\n~~~~ leet: m17_07 :end ~~~~\n" );
}
}//~
