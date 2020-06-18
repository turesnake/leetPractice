/*
 * ====================== leet_413.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 413. 等差数列划分
 */
#include "innLeet.h"


namespace leet_413 {//~


// 一维dp，
// dp[i] 表示，以自己为右边界 的 最大等差数列区间 长度
// dp[0],dp[1] 都为 0
// 等差数列区间 最小要 3个元素


//  70%  100%
class S{
public:
    int numberOfArithmeticSlices( std::vector<int>& A ){

        int N = static_cast<int>(A.size());
        if(N<3){ return 0; }
        std::vector<int> dp (N,0); // dp[0],dp[1] 都为 0
        int outSum = 0;

        for( int i=2; i<N; i++ ){// [i-2],[i-1],[i]
            int off1 = A[i] - A[i-1];
            int off2 = A[i-1] - A[i-2];
            if( off1==off2 ){
                dp[i] = dp[i-1]==0 ? 3 : (dp[i-1]+1);
            }else{
                dp[i] = 0;
            }
            //---//
            if( dp[i] < dp[i-1] ){
                int lstLen = dp[i-1] - 2; // 3个元素 组成一个单位
                outSum += (lstLen+1)*lstLen/2;
            }
        }
        // 补上最后一个区间
        if( dp.back()>0 ){
            int lstLen = dp.back() - 2;
            outSum += (lstLen+1)*lstLen/2;
        }
        //cout<<"dp: "<<endl; for(int i:dp){ cout<<i<<", ";  }cout<<endl;
        return outSum;


    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 1,2,3,4 };

    auto ret = S{}.numberOfArithmeticSlices(v);
    cout<<"ret:"<<ret<<endl;



    debug::log( "\n~~~~ leet: 413 :end ~~~~\n" );
}
}//~
