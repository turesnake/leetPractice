/*
 * ====================== leet_1168.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1168. 水资源分配优化
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1168 {//~



// 最小生成树
// 小顶堆 + 并查集 + kruskal 算法

// 将每个顶点的 well 因素，抽象为一个 单一的虚拟顶点：水库：0，每个实际顶点，都连通这个水库
// 边的权重就是 wells[i]
// 这样，图中就真的有 n+1 个顶点
// ---
// 然后，使用 并查集 + kruskal 算法
// 从所有边中，选出 不构成环的，权重最小的 n+1-1 条边
// 因为它们不构成环，所以，它们一定能连通所有节点，构成最小生成树
// 累计这些 边的 值，获得结果



class S3{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
public:
    explicit UnionFindSet(int N_){
        N=N_;
        st.resize(N,0);
        for( int i=0; i<N; i++ ){
            st[i]=i;
        }
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
    int a {};
    int b {};
    int w {};
};
struct EGreater{
    bool operator()( Elem a, Elem b ){
        return a.w > b.w;
    }
};

public:
    // 共 n 个房子，{1,...n}
    // 1 <= n <= 10000
    // wells.length == n
    // 0 <= wells[i] <= 10^5
    // 1 <= pipes.length <= 10000
    // 1 <= pipes[i][0], pipes[i][1] <= n
    // 0 <= pipes[i][2] <= 10^5
    // pipes[i][0] != pipes[i][1]
    // 可能会出现，连通 点 a，b 的重复的 边，要选择其中短的那个
    int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes ){


        UnionFindSet ufs { n+1 };// [0] 代表水库

        std::priority_queue<Elem,std::vector<Elem>,EGreater> minHeap {};
        for( auto &e : pipes ){// 实际顶点，实际边
            minHeap.push( Elem{ e[0], e[1], e[2] } );
        }
        for( int i=1; i<=n; i++ ){// 水库顶点，虚拟边
            minHeap.push( Elem{ 0, i, wells[i-1] } );
        }

        int ans = 0;
        int edgeCount = 0;
        while( !minHeap.empty() ){      
            auto [a,b,w] = minHeap.top();
            minHeap.pop();
            if( ufs.isSameRoot(a,b) ){ continue; }// 放弃这个边
            ans += w;
            ufs.merge(a,b);
            edgeCount++;
            if( edgeCount==n ){ break; }
        }
        return ans;


    }
};




//=========================================================//
void main_(){

    std::vector<int> wells { 46012,72474,64965,751,33304 };

    std::vector<std::vector<int>> pipes {
        { 2,1,6719 },
        { 3,2,75312 },
        { 5,3,44918 }
    };

    auto ret = S3{}.minCostToSupplyWater( 5, wells, pipes );
    cout<<"ret:"<<ret<<endl;

    

    debug::log( "\n~~~~ leet: 1168 :end ~~~~\n" );
}
}//~
