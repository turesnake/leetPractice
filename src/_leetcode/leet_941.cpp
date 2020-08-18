/*
 * ====================== leet_941.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 941. 有效的山脉数组
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_941 {//~

// 要求
// len>=3
// 必须严格上升下降，不能出现连续两个相等的元素（不算严格的上升 or 下降）


//   19%  91%
class S{
public:
    // 0 <= A.length <= 10000
    // 0 <= A[i] <= 10000 
    bool validMountainArray( std::vector<int>& A ){

        int N = static_cast<int>(A.size());
        if( N<3 ){ return false; }

        int i=1;
        for(; i<N; i++ ){// [i-1], [i]
            if( A[i-1]==A[i] ){ return false; }// 同值元素
            if( A[i]<A[i-1] ){ break; }
        }
        if(i==1 || i==N ){ return false; }// 整条链都在递增 or 前部不存在递增区间

        for(; i<N; i++ ){// [i-1], [i]
            if( A[i]>=A[i-1] ){ return false; }
        }
        return true;


    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 941 :end ~~~~\n" );
}
}//~
