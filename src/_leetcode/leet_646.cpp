/*
 * ====================== leet_646.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 646. 最长数对链
 */
#include "innLeet.h"


namespace leet_646 {//~


// 一维dp
// dp[i] 表示，在此之前（包含自己）最长链表的 长度

// 首先，要对 数据做一次 特殊的排序
// 优先排列 [i][1], 其次排列 [i][0]




//   50%   100%
class S{

// 优先排 [i][1], 其次才是 [i][0]
struct VecLess{
    bool operator()(const std::vector<int> &a, 
                    const std::vector<int> &b ){
        if( a[1]==b[1] ){ return a[0] < b[0]; }
        return a[1] < b[1];
    }
};

public:
    // 1<= len <= 1000
    int findLongestChain( std::vector<std::vector<int>>& pairs ){

        int N = static_cast<int>(pairs.size());
        std::sort( pairs.begin(), pairs.end(), VecLess{} );

        std::vector<int> dp (N,0);
        dp[0] = 1;

        int curMax = 1; // 遍历的过程中，统计的 最长链表 长度

        // [oth]
        for( int i=1; i<N; i++ ){//[i-1],[i]

            int n=i-1;
            for( ; n>=0; n-- ){
                if( pairs[n][1] < pairs[i][0] ){ break; }
            }
            int tmpLen = n<0 ? 1 : dp[n]+1;

            dp[i] = std::max( tmpLen, curMax );
            curMax = dp[i];            
        }
        return dp.back();


    }
};


//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,2},{2,3},{3,4},{1,4},{1,5},{2,7},{2,5}
    };



    auto ret = S{}.findLongestChain(v);
    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: 646 :end ~~~~\n" );
}
}//~
