/*
 * ====================== leet_976.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 976. 三角形的最大周长
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_976 {//~


//   10%  81%
class S{
public:
    int largestPerimeter( std::vector<int>& A ){

        std::sort( A.rbegin(), A.rend() );
        int N = static_cast<int>(A.size());
        bool isFind = false;
        int i=0;
        for(; i<=N-3; i++ ){// [i], [i+1], [i+2]
            if( A[i+1]+A[i+2] > A[i] ){
                isFind = true; 
                break; 
            }// find
        }
        return isFind ? A[i]+A[i+1]+A[i+2] : 0;


    }
};





//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 976 :end ~~~~\n" );
}
}//~
