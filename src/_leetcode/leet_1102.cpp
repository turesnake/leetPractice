/*
 * ====================== leet_1102.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1102. 得分最高的路径
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1102 {//~



// Dijkstra 
// 但是 性能看起来不太好看


//   16%   66%
class S{

struct Elem{
    int idx {};// key
    int w   {};
};
struct ELess{
    bool operator()( Elem a, Elem b )const noexcept{
        return a.w < b.w;
    }
};

    const std::vector<std::vector<int>> nearOffs {
        { -1,  0 },
        {  1,  0 },
        {  0, -1 },
        {  0,  1 }
    };

public:
    // 1 <= R, C <= 100
    // 0 <= A[i][j] <= 10^9
    int maximumMinimumPath( std::vector<std::vector<int>>& A ){

        int H = static_cast<int>(A.size());
        int W = static_cast<int>(A[0].size());
        int Ntotal = H*W;

        std::vector<char> vis (Ntotal, 0);// based on key
        std::vector<int> ans (Ntotal, INT_MAX);// based on key
        ans[0] = A[0][0];

        std::priority_queue<Elem,std::vector<Elem>,ELess> maxHeap {};

        maxHeap.push( Elem{0, A[0][0]} );

        while( !maxHeap.empty() ){
            Elem a = maxHeap.top();
            maxHeap.pop();
            if( vis[a.idx]==1 || ans[a.idx]!=a.w ){ continue; }
            vis[a.idx]=1;
            //---//
            int ah = a.idx/W;
            int aw = a.idx%W;

            for( auto &off : nearOffs ){
                int h = ah + off[0];
                int w = aw + off[1];
                if( h<0 || h>=H || w<0 || w>=W ){ continue; }
                int b = h*W+w;

                if( vis[b]==1 ){ continue; }
                ans[b] = std::min( ans[b], std::min( A[h][w], ans[a.idx] ) );
                maxHeap.push( Elem{b, ans[b]} );
            }
        }
        return ans.back();

    }
};



//=========================================================//
void main_(){

    std::vector<std::vector<int>> m {
        {2,2,1,2,2,2},
        {1,2,2,2,1,2}
    };

    auto ret = S{}.maximumMinimumPath( m );
    cout<<"ret:"<<ret<<endl;


    

    debug::log( "\n~~~~ leet: 1102 :end ~~~~\n" );
}
}//~
