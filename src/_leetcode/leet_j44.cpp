/*
 * ====================== leet_j44.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 44. 数字序列中某一位的数字
 */
#include "innLeet.h"


namespace leet_j44 {//~


// 与 400 题相同 

//   100%   100%
class S{

    int64_t calc_range( int64_t N ){
        int64_t tens = 1;
        for( int64_t i=1; i<N; i++ ){ tens *= 10; }
        return 9 * tens * N;
    }

public:
    int findNthDigit(int n) {

        if( n<10 ){ return n; }

        int64_t nn = n;
        int64_t i=1;
        for(; ; i++ ){
            int64_t range = calc_range(i);
            //---//
            if( nn == range ){
                return 9;
            }else if( nn > range ){
                nn -= range;
                continue;
            }else{
                break;
            }
        }
        // 找到目标区间，在区间内 寻找目标值
        nn -= 1; // 让 nn 基于0
        //cout<<"nn:"<<nn<<", i:"<<i<<endl;

        int64_t tgtElem = 1;
        for( int64_t j=1; j<i; j++ ){ tgtElem *= 10; }
        tgtElem += nn/i;
        int64_t antiBitIdx = i - nn%i - 1; // 将一个数字，从低位遍历到 高位，下标值
        //cout<<"tgtElem:"<<tgtElem<<", idx:"<<antiBitIdx<<endl;

        //---//
        for( int64_t k=0; k<antiBitIdx; k++ ){
            tgtElem /= 10;
        }
        return tgtElem%10;
    }
};





//=========================================================//
void main_(){

    auto ret = S{}.findNthDigit( 13 );

    cout<<"ret:"<<ret<<endl;

    


    debug::log( "\n~~~~ leet: j44 :end ~~~~\n" );
}
}//~
