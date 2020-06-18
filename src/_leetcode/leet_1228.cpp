/*
 * ====================== leet_1228.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1228. 等差数列中缺失的数字
 */
#include "innLeet.h"


namespace leet_1228 {//~


//   69%   100%

class S{
public:
    // 3 <= arr.len <= 1000
    // 0 <= arr[i] <= 10^5
    int missingNumber( std::vector<int>& arr ){

        int N = static_cast<int>(arr.size());
        std::unordered_set<int> uset {};
        
        int offA = arr.at(1) - arr.at(0);
        int offB = arr.at(2) - arr.at(1);
        int offBig {};
        if( offA==0 ){ return 0; }

        if( offB == offA ){// offA 是小值
            offBig = 2*offA;
        }else{// 发现两值不同
            offBig = std::abs(offA)>std::abs(offB) ? offA : offB;
        }

        for( int i=0; i<N-1; i++ ){//[i],[i+1]
            int off = arr.at(i+1) - arr.at(i);
            if( off == offBig ){
                return arr.at(i) + offBig/2;
            }
        }
        return 0;//never reach

    }
};








//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 1228 :end ~~~~\n" );
}
}//~
