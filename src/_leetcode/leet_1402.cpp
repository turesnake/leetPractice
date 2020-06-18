/*
 * ====================== leet_1402.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1402. 做菜顺序
 */
#include "innLeet.h"


namespace leet_1402 {//~



// 先排序，
// 如果 最大值 <= 0，直接返回 0
// 倒序计算 后缀和
// 同时累加每一个 后缀和，就是问题的解
// 找出这些解中的 最大值 


//   51%   100%
class S{
public:
    // 1 <= len <= 500
    // -10^3 <= satisfaction[i] <= 10^3
    int maxSatisfaction( std::vector<int>& satisfaction ){
        
        std::vector<int> &sat = satisfaction;
        int N = static_cast<int>(sat.size());
        std::sort( sat.begin(), sat.end() );
        if( sat.back() <= 0 ){ return 0; }

        std::vector<int> postSums (N,0);// 后缀和
        postSums.back() = sat.back();
        int sum = sat.back();
        int mmax = INT_MIN;

        for( int i=N-2; i>=0; i-- ){//[i],[i+1]
            postSums.at(i) = postSums.at(i+1) + sat.at(i);
            sum += postSums.at(i);
            //cout<<"i:"<<i<<" sum:"<<sum<<endl;
            if( sum<mmax ){ break; }
            mmax = sum;
        }
        return mmax;
        
    }
};



//=========================================================//
void main_(){

    std::vector<int> v { -2,5,-1,0,3,-3 };

    auto ret = S{}.maxSatisfaction(v);

    cout<<"ret:"<<ret<<endl;




    debug::log( "\n~~~~ leet: 1402 :end ~~~~\n" );
}
}//~
