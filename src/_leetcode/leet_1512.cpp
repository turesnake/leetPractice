/*
 * ====================== leet_1512.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1512. 好数对的数目
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1512 {//~

// 排列组合题


// 既然元素值 只有 100种，
// 用 vector 取代 umap，提高速度

//   100%   100%
class S{
public:
    // 1 <= nums.length <= 100
    // 1 <= nums[i] <= 100
    int numIdenticalPairs( std::vector<int>& nums ){


        std::vector<int> v (101, 0);//  优化点
        for( int i : nums ){ v[i]++; }

        int outSum = 0;
        for( int n : v ){
            if( n>=2 ){ 
                outSum += n*(n-1)/2;
            }  
        }
        return outSum;

    }
};



//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 1512 :end ~~~~\n" );
}
}//~
