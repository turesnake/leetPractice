/*
 * ====================== leet_494.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 494. 目标和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_494 {//~

// 中间值 记忆法
// 每次运算，获得的 累加和，都记录到一个 umap 中，顺带统计 每个 值，被实现了几次
// 这个方法 比较容易想到


// 但它似乎 不是 最好的 解法 ...

// 官方答案 提示 此题的本质是 背包dp，
// 我们好像忽略了 总和 小于 1000 这个信息....
// 可以建立一个 2000元素的 dp （兼容正负）

// 未来实现 ......


// 其实，我们的解法，也类似 背包dp 思路....


//   43%     5%
class S{
public:
    // 1 <= len <= 20 
    // 0 <= [i]
    // 0 <= sum <= 1000
    // 保证返回的最终结果能被 32 位整数存下
    int findTargetSumWays( std::vector<int>& nums, int S ){

        std::unordered_map<int,int> umap1 {};//<sum,num>
        std::unordered_map<int,int> umap2 {};
        auto *up1 = &umap1;// 双指针 交替使用
        auto *up2 = &umap2;

        int Nn = static_cast<int>(nums.size());

        if( nums[0]==0 ){
            up1->emplace( 0, 2 );
        }else{
            up1->emplace( nums[0], 1 );
            up1->emplace( -nums[0], 1 );
        }

        for( int i=1; i<Nn; i++ ){
            int val = nums[i];
            up2->clear();
            for( auto &[iSum,iNum] : *up1 ){
                (*up2)[iSum+val] += iNum;
                (*up2)[iSum-val] += iNum;
            }
            std::swap( up1, up2 );
        }
        return up1->count(S)==0 ? 0 : up1->at(S);

    }
};







//=========================================================//
void main_(){

    std::vector<int> v { 1,1,1,1,1 };

    auto ret = S{}.findTargetSumWays( v, 3 );

    cout<<"ret:"<<ret<<endl;
    


    debug::log( "\n~~~~ leet: 494 :end ~~~~\n" );
}
}//~
