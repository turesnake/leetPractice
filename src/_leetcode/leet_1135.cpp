/*
 * ====================== leet_1135.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1135. 最低成本联通所有城市
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1135 {//~


// 无向带权图 的 最小生成树

// -1- 要求 图为 单一连通图
// -2- 计算 最小生成树 成本


//    61%   27%
class S{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
public:
    explicit UnionFindSet(int N_):N(N_){
        st.assign( N, 0 );
        for( int i=0; i<N; i++ ){
            st[i] = i;
        }
    }
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
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
    int rootSize()const{
        int ans = 0;
        for( int i=1; i<N; i++ ){// 不包含 [0]
            if( st[i]==i ){ 
                ans++; 
            }
        }
        return ans;
    }
};

struct HE{
    int a {};
    int b {};
    int w {};
};
struct HEGreater{
    bool operator()( HE a, HE b ){
        return a.w > b.w;
    }
};


public:
    // N 个元素 {1,...N}
    // 1 <= N <= 10000
    // 1 <= conections.length <= 10000
    // 1 <= conections[i][0], conections[i][1] <= N
    // 0 <= conections[i][2] <= 10^5
    // conections[i][0] != conections[i][1]
    int minimumCost(int N, std::vector<std::vector<int>>& connections ){


        std::priority_queue<HE,std::vector<HE>,HEGreater> minHeap {};
        for( auto &e : connections ){
            minHeap.push( HE{ e[0],e[1],e[2] } );
        }

        UnionFindSet ufs {N+1};
        int edgeCount = 0;
        int ans = 0;

        while( !minHeap.empty() && edgeCount<N-1 ){
            HE e = minHeap.top();
            minHeap.pop();
            //---//
            if( ufs.isSameRoot( e.a, e.b ) ){ continue; }//放弃可以形成环的 边
            ufs.merge( e.a, e.b );
            ans += e.w;
            edgeCount++;
        }
        return ufs.rootSize()==1 ? ans : -1;


    }
};


//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 1135 :end ~~~~\n" );
}
}//~
