/*
 * ====================== leet_1494.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1494. 并行课程 II
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1494 {//~


// 有向无环图，但并不是一颗树，

// 首先，统计每个点的 出度表，出度为0的，就是 拟树根们
// 依次取出，出度为0的节点，为自己的 前置节点们，累加 deep 值
// 然后，用 bfs，计算每个节点的 “accumDeep” 值
// 因为不是真的树，有些节点，可能会计算出 不同的 deep，选取 值最大的

// 获得以上信息后，再从头开始，做一次类似 拓扑排序的操作，
// 每回合都收集 所有 入度为 0 的点，从中删除 maxdeep 最大的 前 k 个
// 然后下一回合


// 这个思路 是错误的
// accumDeep 这个 概念不成立
// 或者是，它不一定到达 最优解

// 不管是用这个概念来 统计 最深的叶节点，还是 累计后缀最多的 节点
// 都会被测试反驳


// 题解中 有提到 dp

// ...



class S{


struct HE{
    int idx {};
    int w   {};
};
struct HELess{
    bool operator()( HE a, HE b ){
        return a.w < b.w;
    }
};

public:
    // 1 <= n <= 15
    // 1 <= k <= n
    // 0 <= dependencies.length <= n * (n-1) / 2
    // dependencies[i].length == 2
    // 1 <= xi, yi <= n
    // xi != yi
    // 所有先修关系都是不同的，也就是说 dependencies[i] != dependencies[j]
    // 题目输入的图是个有向无环图
    int minNumberOfSemesters(int n, std::vector<std::vector<int>>& dependencies, int k ){

        std::vector<std::vector<int>> fronts (n+1, std::vector<int>{});
        std::vector<std::vector<int>> nexts  (n+1, std::vector<int>{});

        std::vector<int> indegrees (n+1, 0);
        std::vector<int> outdegrees (n+1, 0);
        std::vector<char> vis{};

        for( auto &e : dependencies ){
            indegrees[e[1]]++;
            outdegrees[e[0]]++;
            fronts[e[1]].push_back( e[0] );
            nexts[e[0]].push_back( e[1] );
        }

        //=== accum deep ===//
        std::vector<int> accumDeeps (n+1, 1);// 累加深度，拟树根为0
        while( true ){
            bool isFindZero = false;
            for( int i=1; i<=n; i++ ){
                if( outdegrees[i]==0 ){
                    isFindZero = true;
                    outdegrees[i] = -1;
                    for( int b : fronts[i] ){
                        outdegrees[b]--;
                        //accumDeeps[b] = std::max( accumDeeps[b], accumDeeps[i]+1 );

                        accumDeeps[b] += accumDeeps[i];


                    }
                }
            }
            if( !isFindZero ){ break; }
        }

        cout<<"accumDeeps:"<<endl;
        for( int i=0; i<=n; i++ ){cout<<"  "<<i<<": "<<accumDeeps[i]<<endl;}cout<<endl;


        //=== 拓扑排序 ===//
        int ans = 0;

        while( true ){// 一个回合

            bool isFindZero = false;
            std::priority_queue<HE,std::vector<HE>,HELess> heap {};
            for( int i=1; i<=n; i++ ){
                if( indegrees[i]==0 ){
                    isFindZero = true;
                    heap.push( HE{i,accumDeeps[i]} );
                }
            }

            if( !isFindZero ){ break; }
            for(int count=0; !heap.empty() && count<k; count++ ){
                auto [ai,aw] = heap.top();
                heap.pop();
                indegrees[ai] = -1;
                for( int b : nexts[ai] ){
                    indegrees[b]--;
                }
            }
            ans++;
        }
        return ans;


    }
};





//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 1494 :end ~~~~\n" );
}
}//~
