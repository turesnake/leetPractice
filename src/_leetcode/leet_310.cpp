/*
 * ====================== leet_310.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 310. 最小高度树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_310 {//~



// 拓扑排序思维
// 既然是无向图，且符合树特征，意味着 全图 连通分量一定为1，
// 每一回合，把 degree<=1 的元素，都收集起来，删除它们，顺便把关联的边 删除
// 最后，图中 可能会留下 一个 degree==0 的元素，或者 两个 degree==1 的元素，它们就是 目标值


// 不管是使用 vector，还是 umap，运行速度 都很低 
// 当改用 邻接矩阵 来存储 数据时，内存消耗更是 暴增 

//  7%  32%
class S{
public:
    // 给定的无向图信息，符合树的特征
    // 包含 n 个节点，标记为 0 到 n - 1
    // 没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，
    // 因此不会同时出现在 edges 里
    //
    std::vector<int> findMinHeightTrees( int n, std::vector<std::vector<int>>& edges ){
        
        if(n==0){ return {}; }
        if(n==1){ return {0}; }

        std::vector<int> degrees (n,0);
        std::vector<std::vector<char>> mat (n, std::vector<char>(n,0));

        for( auto &e : edges ){
            mat[e[0]][e[1]] = 1;
            mat[e[1]][e[0]] = 1;
            degrees[ e[0] ]++;
            degrees[ e[1] ]++;
        }

        std::vector<int> ones {};
        while( true ){
            int maxDegree = 0;
            ones.clear();

            for( int i=0; i<n; i++ ){
                if( degrees[i]==-1 ){ continue; }
                maxDegree = std::max( maxDegree, degrees[i] );
                if( degrees[i]<=1 ){ ones.push_back(i); }
            }
            if( maxDegree<=1 ){ return ones; }// find

            for( int a : ones ){
                degrees[a] = -1;
                int b = 0;
                for(; b<n && mat[a][b]==0; b++ ){}// 只有一个元素
                //assert( b<n );
                mat[a][b]=0;
                mat[b][a]=0;
                //--//
                degrees[b]--;
            }
        }
        return {};// never reach


    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> edges {
        {1,0},
        {1,2},
        {1,3}
    };

    auto ret = S{}.findMinHeightTrees( 4, edges );

    cout<<"ret:"<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;

    

    
    

    debug::log( "\n~~~~ leet: 310 :end ~~~~\n" );
}
}//~
