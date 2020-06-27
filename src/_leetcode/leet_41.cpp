/*
 * ====================== leet_41.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 41. 缺失的第一个正数
 */
#include "innLeet.h"


namespace leet_41 {//~


// 自解法：
// 本质上，这是一道区间题，把所有元素，划归为数个 区间，
// 如果存在一个区间，头元素为1，那么答案一定是 此区间尾后元素
// 如果所有区间头部都不为 1，那么答案一定是 1
// ---
// 但是，这个解法存在一个问题，它不是 常数空间 开销 



// 官方解法：
// 一个崭新的思维是：当数组为 N 个时，目标值最大可能是多少。
// 如果目标值最大，数组就应该是一个 从1开始的紧密排列的数，也就是 [1,N]
// 此时，答案为 N+1
// ---
// 原地hash 法：
// 将原始数组的下标看作是 1 开始的，然后，访问每个元素，如果元素val 在 [1,N] 范围内
// 将本元素 和 下标为 val 的元素 进行交换。（在范围之外的直接不管）
// 依次遍历每个元素，就能将所有 [1,N] 内元素 归位
// 然后遍历修改过的数组，第一个发现的 i!=val 的，就是目标值 


// 自解法，空间使用上 不合规
//  54%  100%
class S{
public:
    int firstMissingPositive( std::vector<int>& nums ){

        std::unordered_set<int64_t> uset {};

        for( int i : nums ){
            if(i<=0){ continue; }// 只保留 正整数
            uset.insert( static_cast<int64_t>(i) );
        }

        while( !uset.empty() ){
            int64_t num = *uset.begin();
            uset.erase(num);
            int64_t l {};
            int64_t r {};
            // 寻找左边界
            if( uset.count(num-1)>0 ){
                l = num-2;
                for(; uset.count(l)>0; uset.erase(l),l-- ){}
                l++;
            }else{
                l = num;
            }
            // 寻找右边界
            if( uset.count(num+1)>0 ){
                r = num+2;
                for(; uset.count(r)>0; uset.erase(r),r++ ){}
                r--;
            }else{
                r = num;
            }
            //cout<<"num:"<<num<<", l:"<<l<<", r:"<<r<<endl;
            if( l==1 ){ return static_cast<int>(r+1); }
        }
        return 1;
        
    }
};


// 原地hash法  100%，  100%
class S2{
public:
    int firstMissingPositive( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());

        for( int i=0; i<N; i++ ){
            // 不停交换，直到 [i] 位元素 无法交换为止
            // 极具标志性的写法
            // -1- a[i] 值必须在区间 [1,N] 内
            // -2- a[i] 与下标 i 不对应
            // -3- 两个要被交换的值，不能相同（否则会陷入死循环）
            while( (nums[i]>=1) && (nums[i]<=N) && (nums[i]!=i+1) && (nums[i]!=nums[nums[i]-1]) ){
                std::swap( nums[i], nums[nums[i]-1] );
            }
        }

        //cout<<"nums: "; for(int i: nums){ cout<<i<<", "; }cout<<endl;

        int i=0;
        for(; i<N; i++ ){
            if( nums[i] != i+1 ){ return i+1; }
        }
        return N+1;


    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 3,4,-1,1 };

    auto ret = S2{}.firstMissingPositive(v);

    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 41 :end ~~~~\n" );
}
}//~
