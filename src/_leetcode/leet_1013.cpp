/*
 * ====================== leet_1013.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1013. 将数组分成和相等的三个部分
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1013 {//~


// -1- 计算每个值的 前缀和
// -2- 如果全体和，不可被3整除，返回 false
//     计算 1/3和 tgt
// -3- 从前缀和中，依次寻找 tgt，2*tgt
//     若找到，可返回 true


//   30%  10%
class S{
public:
    // 3 <= A.length <= 50000
    // -10^4 <= A[i] <= 10^4
    bool canThreePartsEqualSum( std::vector<int>& A ){


        int N = static_cast<int>(A.size());

        std::vector<int> preSums (N,0);
        preSums[0] = A[0];
        for( int i=1; i<N; i++ ){
            preSums[i] = preSums[i-1] + A[i];
        }

        if( preSums[N-1]%3!=0 ){ return false; }// 不能被 3 整除
        int tgt = preSums[N-1]/3;

        bool isFindFst = false;// 是否找到 值为 tgt 的元素
        bool isFindSec = false;// 是否找到 值为 2*tgt 的元素
        for( int i=0; i<N; i++ ){
            if( !isFindFst ){
                if( preSums[i]==tgt ){
                    isFindFst = true;
                }
            }else{
                if( preSums[i]==2*tgt && i<N-1  ){
                    isFindSec = true;
                }
            }
        }
        return isFindFst && isFindSec;


    }
};




//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 1013 :end ~~~~\n" );
}
}//~
