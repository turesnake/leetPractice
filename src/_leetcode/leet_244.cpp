/*
 * ====================== leet_244.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 244. 最短单词距离 II
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_244 {//~


class WordDistance{

    std::unordered_map<std::string,std::vector<int>> umap {};
    std::vector<std::pair<int,int>> v {};// 用于比较的容器


    void sort( const std::string &s1, const std::string &s2 ){

        v.clear();
        auto &v1 = umap.at(s1);
        auto &v2 = umap.at(s2);
        int N1 = static_cast<int>(v1.size());
        int N2 = static_cast<int>(v2.size());
        int p1 = 0;
        int p2 = 0;
        while( p1<N1 || p2<N2 ){
            int idx1 = (p1<N1) ? v1.at(p1) : INT_MAX;
            int idx2 = (p2<N2) ? v2.at(p2) : INT_MAX;
            if( idx1 <= idx2 ){
                v.emplace_back( idx1, 1 );
                p1++;
            }else{
                v.emplace_back( idx2, 2 );
                p2++;
            }
        }
        /*
        cout<<"v:"<<endl;
        for( auto [idx,val] : v ){
            cout << idx << ":" << val <<"; ";
        }cout<<endl;
        */
    }

public:
    WordDistance( std::vector<std::string>& words) {
        int N = static_cast<int>(words.size());
        for( int i=0; i<N; i++ ){
            auto [it,bl] = umap.emplace(words.at(i),std::vector<int>{});
            it->second.push_back(i);
        }
    }

    int shortest(std::string word1, std::string word2) {
        sort(word1,word2);
        int minOff {INT_MAX};
        int Nv = static_cast<int>(v.size());
        for( int i=1; i<Nv; i++ ){// i-1, i
            if( v.at(i-1).second != v.at(i).second ){
                minOff = std::min( minOff, v.at(i).first-v.at(i-1).first );
            }
        }
        return minOff;
    }

};








//=========================================================//
void main_(){

    std::vector<std::string> v { "a", "b", "c", "d", "b", "c" };


    WordDistance w {v};

    cout<< w.shortest("c","a") << endl;




    //cout << shortestDistance( v, "c", "a" ) << endl;




    debug::log( "\n~~~~ leet: 244 :end ~~~~\n" );
}
}//~
