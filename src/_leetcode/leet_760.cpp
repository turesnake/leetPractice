/*
 * ====================== leet_760.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 760. 找出变位映射
 */
#include "innLeet.h"


namespace leet_760 {//~


//   81%   50%
class S{
public:
    // A,B 长度相同，[1,100]
    // A[i], B[i] 都是范围在 [0, 10^5] 的整数。
    std::vector<int> anagramMappings( std::vector<int>& A, std::vector<int>& B ){

        std::unordered_map<int,int> umap {}; //<val,idx>
        int Nb = static_cast<int>(B.size());
        for( int i=0; i<Nb; i++ ){
            umap.emplace( B[i], i );
        }
        for( int &elem : A ){
            elem = umap[elem];
        }
        return A;

    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 760 :end ~~~~\n" );
}
}//~
