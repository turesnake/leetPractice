/*
 * ====================== leet_1349.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1349. 参加考试的最大学生数
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1349 {//~


// =1= 状态压缩dp
// =2= 二分图 


//-------------- 二分图，最大独立集 -----------------//

// -1- 任意一个元素，只和自己两侧的 元素相连，可以把整张图，按照 w 序号奇偶性，
//     分成两个集合
// -2- 实际问题中，偷看是有方向的，只能从 一个位置，偷看左上角的，不能用左上角，反向偷看回来
//     但在建模中，我们一律认为。偷看的边，并无先后关系
//     而且，为了方便形成 从 左侧m集 到 右侧n集 的指向，
//     人为的，把所有边，都改成 m->n 方向的

// -2- 然后，求得 最大匹配数
//     可以用 匈牙利法，也可以用 最大流

// -3- 总元素个数 - 最大匹配数，获得解



// 匈牙利算法    51%  40%
class S1{

    const std::vector<std::vector<int>> nearOffs {//<h,w>
        { -1,-1 },
        { -1, 1 },
        { 0, -1 },
        { 0,  1 }
    };

    std::vector<std::unordered_set<int>> adjs {};
    std::vector<int>  pre {};// 为 n 暂时分配的 m
    std::vector<char> vis {};// 在一个周期内，n 是否被访问

    std::vector<int> mv {};// 二向图，左集
    std::vector<int> nv {};// 二向图，右集

    bool hungary( int m ){
        for( int n : nv ){
            if( adjs[m].count(n)==0 ){ continue; }
            if( vis[n]==1 ){ continue; }
            vis[n] = 1;
            if( pre[n]==-1 || hungary(pre[n]) ){
                pre[n] = m;
                return true;
            }
        }
        return false;
    }


public:
    // seats 只包含字符 '.' 和'#'
    // 1 <= H <= 8
    // 1 <= W <= 8
    int maxStudents( std::vector<std::vector<char>>& seats ){

        int H = static_cast<int>(seats.size());
        int W = static_cast<int>(seats[0].size());
        int Ntotal = H*W;
        int allElemNum = 0;// 所有学生个数

        //===== 生成 邻接表 =====//
        adjs.assign( Ntotal, std::unordered_set<int>{} );
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( seats[h][w] == '#' ){ continue; }
                allElemNum++;
                int a = h * W + w;

                (w&1)==0 ?
                    mv.push_back( a ) :
                    nv.push_back( a );

                for( auto &of : nearOffs ){
                    int offh = h + of[0];
                    int offw = w + of[1];
                    if( offh>=0 && offw>=0 && offw<W && 
                        seats[offh][offw]=='.' 
                    ){
                        int b = offh * W + offw;
                        // 不管实际上，偷看的边是从谁指向谁
                        // 一律设置为 从 m 指向 n
                        (w&1)==0 ?
                            adjs[a].insert( b ) : // maybe
                            adjs[b].insert( a );  // maybe
                    }
                }
            }
        }

        //===== 用匈牙利算法，获得 最大匹配数 =====//
        pre.assign( Ntotal, -1 );

        int hNum = 0;// 最大连通数
        for( int m : mv ){
            vis.assign( Ntotal, 0 );
            if( hungary(m) ){ hNum++; }
        }
        return allElemNum - hNum;

        
    }
};





// 最大流，ff法     51%   20%
class S2{

    const std::vector<std::vector<int>> nearOffs {//<h,w>
        { -1,-1 },
        { -1, 1 },
        { 0, -1 },
        { 0,  1 }
    };

    std::vector<std::unordered_map<int,int>> adjs {};//<to,w>
    std::vector<char> vis {};// 在一个周期内，n 是否被访问

    std::vector<int> mv {};// 二向图，左集
    std::vector<int> nv {};// 二向图，右集

    int start {};
    int tgt {};

    
    int dfs( int from, int flow ){
        if( from==tgt ){ return flow; }
        vis[from] = 1;

        for( auto [to,w] : adjs[from] ){

            if( w>0 && vis[to]==0 ){
                int c = dfs( to, std::min(flow,w) );
                if( c==-1 ){ continue; }
                adjs[from][to] -= c;
                adjs[to][from] += c;
                return c;
            }
        }
        return -1;
    }


public:
    // seats 只包含字符 '.' 和'#'
    // 1 <= H <= 8
    // 1 <= W <= 8
    int maxStudents( std::vector<std::vector<char>>& seats ){

        int H = static_cast<int>(seats.size());
        int W = static_cast<int>(seats[0].size());
        int Ntotal = H*W + 2;
        int allElemNum = 0;// 所有学生个数

        //===== 生成 邻接表 =====//
        adjs.assign( Ntotal, std::unordered_map<int,int>{} );
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( seats[h][w] == '#' ){ continue; }
                allElemNum++;
                int a = h * W + w;

                (w&1)==0 ?
                    mv.push_back( a ) :
                    nv.push_back( a );

                for( auto &of : nearOffs ){
                    int offh = h + of[0];
                    int offw = w + of[1];
                    if( offh>=0 && offw>=0 && offw<W && 
                        seats[offh][offw]=='.' 
                    ){
                        int b = offh * W + offw;
                        // 不管实际上，偷看的边是从谁指向谁
                        // 一律设置为 从 m 指向 n
                        (w&1)==0 ?
                            adjs[a].emplace( b, 1 ) : // maybe
                            adjs[b].emplace( a, 1 );  // maybe
                    }
                }
            }
        }

        // s 到 mv，nv 到 t
        start = Ntotal - 2;
        tgt   = Ntotal - 1;
        for( int m : mv ){
            adjs[start].emplace( m, 1 );
        }
        for( int n : nv ){
            adjs[n].emplace( tgt, 1 );
        }

        //===== 用ff算法，获得 最大流 == 最大连通数 =====//
        int hNum = 0;
        while( true ){
            vis.assign( Ntotal, 0 );
            int c = dfs( start, INT_MAX );
            if( c==-1 ){ break; }
            hNum++;
        }
        cout<<"allElemNum:"<<allElemNum<<", hNum:"<<hNum<<endl;
        return allElemNum - hNum;

    }
};


//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 1349 :end ~~~~\n" );
}
}//~
