/*
 * ====================== leet_1492.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1492. n 的第 k 个因子
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1492 {//~


// 此题 存在一个 大技巧： 成对放入 vector 中的 因数，是有规律的
// 可以根据 前半区间/后半区间，快速查找到 k 的位置
// 无需排序

//   100%   100%
class S{
public:
    // 1 <= k <= n <= 1000
    int kthFactor( int n, int k ){
        k--;

        std::vector<int> divs { 1 };
        if( n>1 ){ divs.push_back(n); }

        int l=2;
        int r=n/l;
        for(; l<=r; l++,r=n/l ){
            if( (n%l)==0 ){
                divs.push_back( l );
                if( l!=r ){ divs.push_back( r ); }
            }
        }

        int N = static_cast<int>(divs.size());// 可奇可偶
        if( N-1<k ){ return -1; }

        int mid = (N-1)/2;
        if( k<=mid ){// 前半部分
            return divs[k*2];
        }else{// 后半部分
            int i = (N-mid-1) - (k-mid); // N为奇偶，都成立
            return divs[i*2+1];
        }


    }
};



//=========================================================//
void main_(){

    auto ret = S{}.kthFactor( 12 , 3 );

    cout<<"ret:"<<ret<<endl;

    


    debug::log( "\n~~~~ leet: 1492 :end ~~~~\n" );
}
}//~
