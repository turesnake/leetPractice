/*
 * ==================== max_flow_problem.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 有权有向图， 最大流/最小割
 */
#ifndef TPR_MAX_FLOW_PROBLEM_H
#define TPR_MAX_FLOW_PROBLEM_H
#include "pch.h"

namespace tpr_max_flow_problem{//~


//====== Ford_Fulkerson ======//
// to find the max flow, the ff method repeatedly finds Augmenting-Paths(增广路径)
// through the Residual-Graph(残留图) and augments the flow until no more  
// Augmenting-Paths(增广路径) can be found.
// ---
// ff算法 在 残留图中，不停地搜索 增广路径，每找到一条，就增加其流量
// 直到 再也找不到 增广路径 为止

// 增广路径：在残留图中，只要一条路径上，每条边的 剩余容量 都大于0。这个路径就是增广路径
// 增广路径上的 边，可以是 反向边

// ff算法 时间复杂度上界为 O(m*f), m 是 边的个数，f为 最后求得的最大流
// 这个上界 非常 高，但在实际表现中 还能接受
// 缺点是，当 流 的大小越大，这个算法的 上界就越高


// ff算法
// 抄来的实现，写法非常的 C语言
// 这个实现 使用了 比较陌生的 C风格的 邻接表
class Ford_Fulkerson_C{

struct Edge{
    int to   {};// 弧头节点序号（边的尾端）
    int w    {};// 权重
    int next {};// 下一条边的序号 (并不是下一条边的头节点值)
                // 这个 next，本质上是个 链表结构，可以逐个 next 下去
                // 获得的是 本边所有的 下一条边
};

    int target {};// 汇点
    std::vector<char> vis {};

    //-- 以下2容器，需要放入数据 --//
    // 这组数据中，每条边的 正向边 和 反向边，紧临存储，{0,1},{2,3},{4,5}...
    // 这样可以快速在 正反边之间切换
    // 初始阶段时，正向边 存储 初始容量x， 反向边初始容量为 0

    // 两个容器，使用相同的 idx 去访问
    // idx 仅表示 第i号边：[i]
    // 此边的 头节点是 head[i]
    // 此边的 尾节点是 edge[i].to
    // 此边的 权重（残余容量） edge[i].w
    // 此边的 下一条边的idx号是 edge[i].next
    std::vector<Edge> edges {};// 
    std::vector<int>  head {}; // 记录每条边的 头节点idx, 初始为-1

    // flow: 整条路径上，最小 边权值
    int dfs( int p, int flow ){

        if( p==target ){ return flow; } // 到达终点，返回这条增广路的流量

        vis[p] = 1;

        // 获得 当前边的 所有的 下一条边（next）
        for( int eg=head[p]; eg!=-1; eg=edges[eg].next ){

            int to = edges[eg].to;
            int vol = edges[eg].w;
            int c {};
            // 返回的条件是残余容量大于0、未访问过该点且接下来可以达到终点（递归地实现）
            // 传递下去的流量是边的容量与当前流量中的较小值
            if( vol>0 && // 剩余容量 <=0, 意味着此边 暂时不能通行
                vis[to]==0 && 
                (c=dfs(to,std::min(vol,flow))) != -1
            ){
                edges[eg].w -= c;
                edges[eg^1].w += c;
                // [原] 这是链式前向星取反向边的一种简易的方法
                // [原] 建图时要把cnt置为1，且要保证反向边紧接着正向边建立

                // eg^1 是什么意思：
                // 若 eg 为偶数，结果为 eg+1
                // 若 eg 为奇数，结果为 eg-1
                // 当在设计 数据结构是， 正向边和反向边，正好紧邻布置，就用通过这个方法高效查找到彼此
                // 比如 {0,1},{2,3}...

                // 在这份实现中，一条边的 正反实现，都只用一个值来存储，
                // 假设 边a 的 原正向容量为 6，当被消耗 4个单位后
                // 正向剩余 2， 反向变成 4， 这样，下次搜索时，可以很方便地发现，反向路径的可用流量
                return c;
            }
        }
        // 在这个问题中，就算不是放 错误边上的点，也不会影响 本次dfs 的后续搜索的
        // 这是一个很少见的情况
        // vis[p] = 0;
        return -1; // 无法到达终点
    }

public:
    // edges_[i]: { 边起点，边尾点，边容量 }
    // N_: 一共 N_ 条边，{ 0,...N_-1 }
    int FF( std::vector<std::vector<int>> edges_, int N_, int start_, int target_ ){

        //== 准备数据 ==//
        edges.resize( N_*2, Edge{} );
        head.resize( N_*2, -1 );
        for( auto &e : edges_ ){
            // 执行一些 初始化 edges，head 数组的操作
            // 未实现 
            // ... 
        }
        //== 正式处理 ==//
        target = target_;
        int ans = 0;
        while( true ){
            vis.assign( N_, 0 );
            int c = dfs( start_, INT_MAX );
            if( c==-1 ){ break; }
            ans += c;
        }
        return ans;
    }
};


// 基于上述版本，自行修改来的 C++ 风格的
class Ford_Fulkerson_CPP{

    std::vector<std::unordered_map<int,int>> adjs {};// <to,w>
    std::vector<char> vis {};
    int N {};
    int tgt {};

    // 只要随便找到 一条 完整的路径，就会从整个 递归中 彻底返回
    int dfs( int from, int minFlow ){

        if( from==tgt ){ return minFlow; }// 一条路径完整获得
        vis[from] = 1;
        for( auto [to,w] : adjs[from] ){
            if( w<=0 || vis[to]==1 ){ continue; }
            int c = dfs( to, std::min(w,minFlow) );
            if( c==-1 ){ continue; }// 此分支 找不到完整路径
            //-- find --//
            adjs[from][to] -= c;// 当前方向边 减少容量
            adjs[to][from] += c;// 反向边 增加容量
            return c;
        }
        // 在这个问题中，就算不是放 错误边上的点，也不会影响 本次dfs 的后续搜索的
        // 这是一个很少见的情况
        //vis[from] = 0;
        return -1; // 未能找到 完整路径
    }

public:
    // edges_[i]: { 边起点，边尾点，边容量 }
    // N_: 一共 N_ 条边，{ 0,...N_-1 }
    int ff( std::vector<std::vector<int>> edges_, int N_, int start_, int target_ ){

        N = N_;
        tgt = target_;
        adjs.resize(N,std::unordered_map<int,int>{});
        for( auto &e : edges_ ){
            int head = e[0];
            int tail = e[1];
            adjs[head].emplace( tail, e[2] );// 正向边
            adjs[tail].emplace( head, 0 );   // 反向边
        } 

        int ans = 0;
        while( true ){
            vis.assign(N,0);
            int c = dfs( start_, INT_MAX );
            if( c==-1 ){ break; }// 再也找不到 增广路径了
             ans += c;
        }
        return ans;
    }

};



//====== Edmond_Karp ======//
// 就是 bfs 版的 ff算法
// 时间复杂度上界 O(n*m^2)： n 为顶点个数，m为边个数

class Edmond_Karp{

    std::vector<std::unordered_map<int,int>> adjs {};// <to,w>
    std::vector<int> last {};// 记录 节点i的 前缀节点，从而可以反向查找路径
    std::vector<int> flow {};// 记录 bfs 过程中，每个节点计算出来的 minFlow 值
    int N {};
    int start {}; 
    int tgt   {};

    bool bfs(){

        last.assign( N,-1 );
        std::queue<int> que;
        que.push( start );

        flow[start] = INT_MAX;
        while( !que.empty() ){

            int from = que.front();
            que.pop();
            if( from==tgt ){ break; } // 到达汇点，结束搜索

            for( auto [to,w] : adjs[from] ){
                if( w>0 && last[to]==-1 ){// 如果残余容量大于0且未访问过（所以last保持在-1）
                    last[to] = from;
                    flow[to] = std::min( flow[from], w );
                    que.push(to);
                }
            }
        }
        return last[tgt] != -1;
    }

public:
    // edges_[i]: { 边起点，边尾点，边容量 }
    // N_: 一共 N_ 条边，{ 0,...N_-1 }
    int ek( std::vector<std::vector<int>> edges_, int N_, int start_, int target_ ){

        start = start_;
        tgt = target_;
        N = N_;
        adjs.resize(N,std::unordered_map<int,int>{});
        for( auto &e : edges_ ){
            int head = e[0];
            int tail = e[1];
            adjs[head].emplace( tail, e[2] );// 正向边
            adjs[tail].emplace( head, 0 );   // 反向边
        } 

        flow.resize( N,0 );

        //===//
        int maxflow = 0;
        while( bfs() ){
            maxflow += flow[tgt];
            for( int i=tgt; i!=start; i=last[i] ){// 从汇点原路返回更新残余容量
                adjs[last[i]][i] -= flow[tgt];
                adjs[i][last[i]] += flow[tgt];
            }
        }
        return maxflow;
    }
};



//====== Dinic ======//
// 是 ff/ek 算法的 优化

// Dinic is a strongly polynomial(多项式) max flow algorithm
// with a runtime of O(V^2E)
// 速度很快，尤其实在 二分图中, 性能可以达到 O( sqrt(V*E) )

// 算法的核心在于，借助一个 Level-Graph 来找到 当前最短的 增广路径，
// 通过一个 bfs搜索，为每个节点建立 lv信息
// 在这个过程中，只有 正方向的边，才会被保留

// 实现流程
// -1- 每一周期中，从 start 点出发，用 bfs 遍历图， 
//     为每一个 可以到达的点，标注 lv 值
// -2- 如果本次 bfs 后，tgt点 未能遍历到，说明 残留图 中不在存在 增广路径
//     可以终止程序了
// -3- 在仅保留了 前向边（从 lv 到 lv+1 ）的图中，做多次 dfs 搜索，直到找到一条
//     Blocking-Flow(阻塞流), 将所有 成功找到的 增广路径的 瓶颈值，累加起来，统计到全局中
//     ---
//     阻塞流 的产生是因为，随着越来越多的 边达到饱和（剩余容量为0）
//     再也找不到能从 s 到 t 的有效路径了
// -4- 重复上述的 1~3 步

// 优化
// 有时候，在 dfs 中会反复出现 相同的死路径（被前方的一个饱和边阻塞）
// 一个优化思路是，在 dfs 遇到 死路径，在回撤时，将这个分枝减去,
// 这样，一个死路径 就只会被遍历一次
//

/*
class Dinic{

    //int n, m, s, t, lv[MAXN], cur[MAXN]; // lv是每个点的层数，cur用于当前弧优化标记增广起点

    std::vector<std::unordered_map<int,int>> adjs {};// <to,w>
    int N {};
    int start {};
    int tgt {};

    std::vector<int> lv  {};// 每个点的 层数
    std::vector<int> cur {};// cur用于当前弧优化标记增广起点


    bool bfs(){ // BFS分层

        lv.assign( N, -1 );

        lv[start] = 0;

        memcpy(cur, head, sizeof(head)); // 当前弧优化初始化, head 复制给 cur


        std::queue<int> que;
        que.push(start);
        while (!que.empty()){

            int p = que.front();
            que.pop();

            for (int eg = head[p]; eg; eg = edges[eg].next){

                int to = edges[eg].to, vol = edges[eg].w;
                if (vol > 0 && lv[to] == -1)
                    lv[to] = lv[p] + 1, que.push(to);
            }
        }
        return lv[tgt] != -1; // 如果汇点未访问过说明已经无法达到汇点，此时返回false
    }



    int dfs(int p, int flow ){

        if( p==tgt ){ return flow; }
            
        int rmn = flow; // 剩余的流量

        // 并不是找到一条 有效路径就终止，而是要反复找，直到出现 阻塞流 为止
        // 每搜索得到一条 有效路径，会即刻更新 边上的 容量值
        // 所以在之后的搜索中，已经饱和的边 会自动封闭道路

        for (int &eg = cur[p]; eg; eg = edges[eg].next){ // eg带引用，跳过已经增广过的边,下次增广直接从这条边开始循环
        
            if (!rmn){ break; } // 如果已经没有剩余流量则退出
                
            int to = edges[eg].to;
            int vol = edges[eg].w;


            if( vol>0 && lv[to]==lv[p]+1 ){ // 往层数高的方向增广
            
                int c = dfs( to, std::min(vol,rmn) ); // 尽可能多地传递流量
                rmn -= c; // 剩余流量减少
                edges[eg].w -= c; // 更新残余容量
                edges[eg^1].w += c; // 再次提醒，链式前向星的cnt需要初始化为1（或-1）才能这样求反向边
            }
        }
        return flow - rmn; // 返回传递出去的流量的大小
    }



public:
    // edges_[i]: { 边起点，边尾点，边容量 }
    // N_: 一共 N_ 条边，{ 0,...N_-1 }
    int dinic( std::vector<std::vector<int>> edges_, int N_, int start_, int target_ ){
  

        start = start_;
        tgt = target_;
        N = N_;
        adjs.resize(N,std::unordered_map<int,int>{});
        for( auto &e : edges_ ){
            int head = e[0];
            int tail = e[1];
            adjs[head].emplace( tail, e[2] );// 正向边
            adjs[tail].emplace( head, 0 );   // 反向边
        } 



        int ans = 0;
        while (bfs()){
            ans += dfs( start, INT_MAX );
        }
        return ans;
    }





};
*/



}//~
#endif
