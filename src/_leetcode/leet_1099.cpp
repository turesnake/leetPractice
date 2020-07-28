/*
 * ====================== leet_1099.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1099. 小于 K 的两数之和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1099 {//~


// 排序，二分查找

//   97%  33%
class S{
public:
    // 1 <= A.length <= 100
    // 1 <= A[i] <= 1000
    // 1 <= K <= 2000
    int twoSumLessThanK( std::vector<int>& A, int K ){

        int N = static_cast<int>(A.size());
        if( N<2 ){ return -1; }
        std::sort( A.begin(), A.end() );

        int out = -1;
        
        for( int i=0; i<N-1; i++ ){// [l], [l+1]
            int l=i+1;
            int r=N-1;
            while( l<r ){
                int mid = l+(r-l)/2+1;// mid-left
                if( A[mid]+A[i] >= K ){
                    r = mid-1;// 坚决剔除
                }else{
                    l = mid;// 保留到下一回合
                }
            }// now l==r
            if( A[l]+A[i] < K ){
                out = std::max( out, A[l]+A[i] );
            }
        }
        return out;

    }
};



//=========================================================//
void main_(){





    
    debug::log( "\n~~~~ leet: 1099 :end ~~~~\n" );
}
}//~
