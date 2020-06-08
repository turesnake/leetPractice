/*
 * ====================== leet_547.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 547. 朋友圈
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_547 {//~



// 并查集  63%,  9%
class S{

    std::vector<int> uf {};//[0]被用到了 

    int find( int v ){
        while( uf.at(v)!=v ){
            v = uf.at(v);
            uf.at(v) = uf.at(uf.at(v));// 路径压缩
        }
        return v;
    }
    void merge( int a, int b ){
        int rootA = find(a);
        int rootB = find(b);
        if( rootA!=rootB ){ uf.at(rootA) = rootB; }
    }

public:
    // N*N
    // 1<= N <= 200
    int findCircleNum( std::vector<std::vector<int>>& M ){

        int N = static_cast<int>(M.size());
        uf.resize(N);
        for( int i=0; i<N; i++ ){
            uf.at(i)=i;
        }
        for( int h=1; h<N; h++ ){
            for( int w=0; w<h; w++ ){
                if( M.at(h).at(w) == 1 ){
                    merge( w,h );
                }
            }
        }
        int sum = 0;
        for( int i=0; i<N; i++ ){
            if( uf.at(i)==i ){
                sum++;
            }
        }
        return sum;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 547 :end ~~~~\n" );
}
}//~
