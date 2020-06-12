/*
 * ====================== leet_560.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 560. 和为K的子数组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_560 {//~


// 前缀和   85%,  6%
// 在这一版实现中，将先后两次遍历，合并到了一次中
// 提高了 时间性能 
class S{
public:
    // 1<= nums.len <= 20000
    // -1000<= nums[i] <=1000
    // -1e7 <= k <= 1e7
    int subarraySum( std::vector<int>& nums, int k ){

        if(nums.empty()){ return 0; }
        int N = static_cast<int>(nums.size());
        int maxNum = 0;
        //== 收集 前缀和 ==//
        std::unordered_map<int,int> preSumNums {};//目前已找到的，某个前缀和的值 <val,nums>
        int preSum = 0;
        for( int i=0; i<N; i++ ){
            preSum += nums.at(i);
            if( preSum==k ){ maxNum++; }
            int off = preSum - k;
            auto fit = preSumNums.find(off);
            if( fit != preSumNums.end() ){
                maxNum += fit->second;
            }
            // 要等 maxNum 收集完毕后，再更新 umap
            preSumNums[preSum]++;//maybe insert
        }
        return maxNum;
    }
};




//=========================================================//
void main_(){

    std::vector<int> v { -1,1,-1,1 };

    cout<<"ret:\n"<<S{}.subarraySum(v,0)<<endl;


    
    debug::log( "\n~~~~ leet: 560 :end ~~~~\n" );
}
}//~
