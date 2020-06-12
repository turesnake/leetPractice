/*
 * ====================== leet_523.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 523. 连续的子数组和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_523 {//~



// 优化版实现：
// 因为元素都非负，前缀和一定是 递增的，
// 那就可以通过 preSum[0,r]/k 求的 N 上限
// 然后看是否存在 匹配的 N 就行了


// 前缀和 
// 朴素法，记录每一位的 前缀和
// 然后逐个比较 
class S{
public:
    // [i] >= 0
    // nums.len < 10000
    // all sum legal in int32
    bool checkSubarraySum( std::vector<int>& nums, int k ){


        if( nums.empty() ){ return false; }
        int N = static_cast<int>(nums.size());
        
        // 当k==0，数组中存在连续的两个0，也成立
        // 这个情况，需要单独处理
        if( k==0 ){
            bool isLstZero = false;
            for( int i=0; i<N; i++ ){
                if( nums.at(i)==0 ){
                    if( isLstZero ){ return true; }
                    isLstZero = true;
                }else{
                    isLstZero = false;
                }
            }
            return false;
        }
        
        std::vector<int> preSums (N,0);
        int preSum = 0;
        for( int i=0; i<N; i++ ){
            preSum += nums.at(i);
            preSums.at(i) = preSum;

            if( i>0 && (preSum%k)==0 ){ return true; }

            for( int l=0; l<i-1; l++ ){
                int off = preSum - preSums.at(l);
                if( (off%k)==0 ){ return true; }
            }
        }
        return false;
    }
};



//=========================================================//
void main_(){

 


    
    debug::log( "\n~~~~ leet: 523 :end ~~~~\n" );
}
}//~
