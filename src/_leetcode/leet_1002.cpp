/*
 * ====================== leet_1002.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1002. 查找常用字符
 */
#include "innLeet.h"


namespace leet_1002 {//~


//  86%  50%
class S{
public:
    // 1 <= A.length <= 100
    // 1 <= A[i].length <= 100
    std::vector<std::string> commonChars( std::vector<std::string>& A ){


        std::unordered_map<char,int> umap {};
        std::vector<int> v {};
        std::set<char> eSet {};
        int N = static_cast<int>(A.size());
        // 先收集第一个单词
        for( char c : A.at(0) ){
            umap[c]++;
        }
        for( int i=1; i<N; i++ ){
            v.clear();
            v.resize(26,0);
            for( char c : A.at(i) ){
                v.at(c-'a')++;
            }
            //---//
            eSet.clear();
            for( auto [c,uNum] : umap ){
                char vNum = v.at(c-'a');
                if( vNum==0 ){
                    eSet.insert(c);
                }else{
                    if( vNum < uNum ){ umap.at(c) = vNum; }
                }
            }
            for( char c : eSet ){ umap.erase(c); }
        }
        std::vector<std::string> outstrs {};
        for( auto [c,num] : umap ){
            outstrs.insert( outstrs.end(), num, std::string{c} );
        }
        return outstrs;
    }
};






//=========================================================//
void main_(){

    std::vector<std::string> v {
        "bella","label","roller"
    };

    auto ret = S{}.commonChars(v);

    for( auto &s : ret ){
        cout<<s<<endl;
    }




    debug::log( "\n~~~~ leet: 1002 :end ~~~~\n" );
}
}//~
