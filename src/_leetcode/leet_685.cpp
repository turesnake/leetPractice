/*
 * ====================== leet_685.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 685. 冗余连接 II
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_685 {//~


// 并查集 活用 

// 自想的方案
// 分两种情况来处理：
// ==1== 全局 存在 一个点的 入度为0，它就是 树根， 
//   此时，一定存在一个，入度为 2 的点，错误的边，就是指向它的某一条
//   情况也分为两种，要么是一个 祖先点，短路指向它，要么是一个 子孙点，回路指向它
// 处理方式是：
//   从已经找到的 树根开始，用 bfs，为每个点 刷 deep 值，以str的格式 
//   目标点 会被刷两次，当第二次刷到它时，
//   如果 自己现有key，是 第二点 的一部分，说明 第二次想来刷自己的 第二点，是自己的 子孙
//   此时为 一个 回路，这个回路就是 目标边

//   如果不是，则说明 此次来刷自己的 第二点，是自己的 表亲，此时，两条入边 是 平行关系
//   谁靠后出现，选谁
//   ----
//   这部分 也可以用 并查集 统一搞定：
//   在上述两种情况中，目标边，一定是 两条指向 目标点的 边 之一
//   我们可以先包含 某条边a，剔除另一条边b。此时对全局做一次 并查集
//   如果此时 全局只有一个 连通分量，那么 边b 一定是 要找的
//   如果此时有 两个连通分量，那么边a 就是目标 


// ==2== 全局 不存在 入度为0 的点，说明错误边，是一条，子孙节点，指向 树根的 边
//    此时采用剥离法，将所有 出度为0 的点 依次剥离，最后剩下一个 入度都为1 的有向环
//    这个环上的 所有 点 都是平等的，哪条边靠后出现，就选哪条边
//    ---
//    还可以用 传统的 并查集，最后一条组成环的边，会被检测出来，这样就找到了
//    类似 题 684



//   89%   76%
class S{

class UnionFindSet{
    std::vector<int> st {};// [0] 空置
    int N {};
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
public:
    explicit UnionFindSet(int N_):N(N_){
        st.resize( N,0 );
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
    int rootSize()const{// not include 0
        int sum = 0;
        for( int i=1; i<N; i++ ){
            if( st[i]==i ){ sum++; }
        }
        return sum;
    }
};

    std::vector<std::vector<int>> *datas {nullptr};
    std::vector<int> tgtEdge {};// 目标边
    int N {};
    int rootIdx {-1};
    int tgtIdx  {-1};

    void twoInEdge(){

        UnionFindSet ufs {N+1};
        int fst = -1;
        int sec = -1;

        for( auto &e : *datas ){
            bool isInclude = true;
            if( e[1]==tgtIdx ){
                if( fst==-1 ){
                    fst = e[0];
                }else{
                    sec = e[0];
                    isInclude = false;
                }
            }
            if( isInclude ){
                ufs.merge( e[0], e[1] );
            }
        }

        tgtEdge.push_back( ufs.rootSize()==1 ? sec : fst  );
        tgtEdge.push_back( tgtIdx );
    }

    void loopWithRoot(){

        UnionFindSet ufs {N+1};
        for( auto &e : *datas ){
            if( ufs.isSameRoot(e[0],e[1]) ){
                tgtEdge.push_back( e[0] );
                tgtEdge.push_back( e[1] );
                return;
            }
            ufs.merge( e[0], e[1] );
        }
    }


public:
    // 二维数组大小的在3到1000范围内
    // 二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小
    std::vector<int> findRedundantDirectedConnection( std::vector<std::vector<int>>& edges ){


        N = static_cast<int>(edges.size());// 也是顶点个数
        datas = &edges;

        std::vector<int> indegrees (N+1, 0);

        for( auto &e : edges ){
            indegrees[e[1]]++;
        }

        for( int i=1; i<=N; i++ ){
            if( indegrees[i]==0 ){ rootIdx = i; }
            else if( indegrees[i]==2 ){ tgtIdx = i; }
        }

        if( rootIdx==-1 ){
            // 多余的边，指向 树根节点，所有节点的入度 都为1
            loopWithRoot();
            
        }else{
            // 两条边 指向同一个普通节点， 目标就在 两条边中间 
            twoInEdge();
        }
        return tgtEdge;


    }
};



//=========================================================//
void main_(){

    


    

    debug::log( "\n~~~~ leet: 685 :end ~~~~\n" );
}
}//~
