/*
 * ====================== leet_1162.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1162. 地图分析
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1162 {//~


// 用类似 3D接雨水 的思路
// 第一回合，找到所有 临接1 的 0点，将他们存入 uset
// 之后的回合，从 uset 中取出所有元素，为他们设置 距离值，将邻接它们的0点再次存入 uset


// 这个思路还可以被正规化： 多源bfs
// 设置一个超级起点，将它连通 所有陆地点，然后做广度搜索



//   45%   35%
class S{
    const std::vector<std::vector<int>> nearOffs {
        {-1,0},
        { 1,0},
        { 0,-1},
        { 0, 1}
    };

public:
    // 1 <= grid.length == grid[0].length <= 100
    // grid[i][j] 不是 0 就是 1
    int maxDistance( std::vector<std::vector<int>>& grid ){

        int H = static_cast<int>(grid.size());
        int W = static_cast<int>(grid[0].size());
        int Ntotal = H*W;

        std::unordered_set<int> uset1 {};
        std::unordered_set<int> uset2 {};
        auto *usp1 = &uset1;// 上回合数据
        auto *usp2 = &uset2;// 本回合装入的 新数据

        for( int h=0; h<H; h++ ){
            for( int w=0;w<W; w++ ){
                if( grid[h][w] == 0 ){
                    bool isFind = false;
                    for( auto &of : nearOffs ){
                        int bh = h + of[0];
                        int bw = w + of[1];
                        if( bh<0 || bh>=H || bw<0 || bw>=W ){ continue; }
                        if( grid[bh][bw]==1 ){
                            isFind = true;
                            break;
                        }
                    }
                    if( isFind ){
                        usp1->insert( h * W + w );
                    }
                }
            }
        }
        //cout<<"fst usp1 size:"<<usp1->size()<<endl;
        int deep = 0;
        while( !usp1->empty() ){
            // 上回合收集的元素，全部标记 deep 值
            for( int a : (*usp1) ){
                int ah = a/W;
                int aw = a%W;
                grid[ah][aw] = deep-1;
            }
            // 收集新的 0 集合 
            for( int a : (*usp1) ){
                int ah = a/W;
                int aw = a%W;
                for( auto &of : nearOffs ){
                    int bh = ah + of[0];
                    int bw = aw + of[1];
                    if( bh<0 || bh>=H || bw<0 || bw>=W ){ continue; }
                    if( grid[bh][bw]==0 ){
                        usp2->insert( bh * W + bw );
                    }
                }
            }
            deep--;
            usp1->clear();
            std::swap( usp1, usp2 );
        }
        //cout<<"grid:"<<endl;
        //for( auto &e : grid ){for( int i : e ){cout<<i<<", ";}cout<<endl;}
        return deep==0 ? -1 : -deep;

    }
};



//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {0,0,1,1,1},
        {0,1,1,0,0},
        {0,0,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,1}
    };

    auto ret = S{}.maxDistance( v );
    cout<<"ret:"<<ret<<endl;



    

    debug::log( "\n~~~~ leet: 1162 :end ~~~~\n" );
}
}//~
