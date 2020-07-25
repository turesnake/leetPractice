/*
 * ====================== leet_329.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 329. 矩阵中的最长递增路径
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"

namespace leet_329 {//~


// 用 入度表，邻接表 的思路来实现
// 性能似乎有点低



//  16%  50%
class S{

struct IntVec{
    int h;
    int w;
};

struct Elem{
    int indegree {0};
    int len      {1};
    std::vector<IntVec> nexts {};
};

    const std::vector<IntVec> nearOffs {
        IntVec{ -1, 0 },
        IntVec{  1, 0 },
        IntVec{  0, -1 },
        IntVec{  0,  1 }
    };

public:
    int longestIncreasingPath( std::vector<std::vector<int>>& matrix ){

        if( matrix.empty() || matrix[0].empty() ){ return 0; }

        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix[0].size());

        //std::vector<std::vector<int>> lens ( H, std::vector<int>(W,0) );
        //std::vector<std::vector<int>> indegrees ( H, std::vector<int>(W,0) );
        //std::unordered_map<IntVec, std::vector<IntVec>, MyHash> nexts {};
        std::vector<std::vector<Elem>> elems ( H, std::vector<Elem>(W, Elem{} ) );
        std::deque<IntVec> que {};

        // 适当优化了 对矩阵数据的 遍历，但性能提升有限
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                // 上
                if( h>0 && matrix[h][w]!=matrix[h-1][w] ){
                    if( matrix[h][w] > matrix[h-1][w] ){
                        elems[h][w].indegree++;
                        elems[h-1][w].nexts.push_back( IntVec{h,w} );
                    }else{
                        elems[h-1][w].indegree++;
                        elems[h][w].nexts.push_back( IntVec{h-1,w} );
                    }
                }
                // 左
                if( w>0 && matrix[h][w]!=matrix[h][w-1] ){
                    if( matrix[h][w] > matrix[h][w-1] ){
                        elems[h][w].indegree++;
                        elems[h][w-1].nexts.push_back( IntVec{h,w} );
                    }else{
                        elems[h][w-1].indegree++;
                        elems[h][w].nexts.push_back( IntVec{h,w-1} );
                    }
                }
            }
        }

        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( elems[h][w].indegree==0 ){
                    que.push_back( IntVec{h,w} );
                    //elems[h][w].len = 1;
                }
            }
        }
        
        int outMax = 1;
        while( !que.empty() ){
            auto e = que.front();
            que.pop_front();
            for( auto i : elems[e.h][e.w].nexts ){
                elems[i.h][i.w].indegree--;
                if( elems[i.h][i.w].indegree==0 ){
                    que.push_back( i );
                    elems[i.h][i.w].len = std::max( elems[i.h][i.w].len, elems[e.h][e.w].len+1 );
                    outMax = std::max( outMax, elems[i.h][i.w].len );
                }
            }
        }
        return outMax;


    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> m {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };

    auto ret = S{}.longestIncreasingPath(m);
    cout<<"ret:"<<ret<<endl;





    
    debug::log( "\n~~~~ leet: 329 :end ~~~~\n" );
}
}//~
