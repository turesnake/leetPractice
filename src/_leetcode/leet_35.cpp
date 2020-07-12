/*
 * ====================== leet_35.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 35. 搜索插入位置
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_35 {//~



// 找到 >= target 的最小值的 下标
// 二分查找
// 剔除策略：如果一个元素，小于 target，那它一定不属于！！！
//
int searchInsert( std::vector<int> nums, int target ){

    int N = static_cast<int>(nums.size());
    if( nums.empty() ){ return 0; }
    if( target > nums.back() ){ return N; }// 超出右边界
    if( target <= nums.front() ){ return 0; }// 超出左边界
    // 现在开始，返回值 一定在 中间区间内 
    int l=0;
    int r=N-1;
    while( l<=r ){
        if( l==r ){ 
            //cout<<"=="<<endl;
            return (nums.at(l)>=target) ? l : l+1; 
        }//边界
        int mid = l+(r-l)/2;//mid-left
        int midVal = nums.at(mid);
        if( midVal==target ){ return mid; }//正好找到
        if( midVal<target ){
            // mid 明确小于 target，一定不属于，踢出搜索圈
            l = mid+1;
        }else{
            // mid 大于 target，也许是，保留在 搜索圈
            // 如果 mid 就是正确值，此时，l==r
            // 下一循环 会命中头部的==检测
            r = mid; 
        }
    }
    return -99;//never reach
}


// 重新实现：
// 实质就是 查找 大于等于 tgt 的 最小值（左区间）


// 2020_0712     95%  100%
class S{
public:
    // 数组元素 已排序，无重复元素
    int searchInsert( std::vector<int>& nums, int target ){

        int N = static_cast<int>(nums.size());
        int l=0;
        int r=N-1;
        while( l<=r ){
            if( l==r ){ 
                return nums[l]>=target ? l : l+1;// find
            }
            int mid = l+(r-l)/2;//mid-left
            int midVal = nums[mid];
            if( midVal<target ){
                l = mid+1; // 坚决剔除
            }else if( midVal>target ){
                r = mid; // 保留到下一回合
            }else{// == 
                return mid;// find
            }
        }
        return 0; // nums.empty()
        
    }
};



//=========================================================//
void main_(){

    // 详细地排查 二分查找 

    // 0
    tprAssert( searchInsert( {}, 0 )==0 );
    cout<<"=0=:done"<<endl;

    // 1
    tprAssert( searchInsert( {1}, 0 )==0 );
    tprAssert( searchInsert( {1}, 1 )==0 );
    tprAssert( searchInsert( {1}, 2 )==1 );
    cout<<"=1=:done"<<endl;

    // 2
    tprAssert( searchInsert( {1,3}, 0 )==0 );
    tprAssert( searchInsert( {1,3}, 1 )==0 );
    tprAssert( searchInsert( {1,3}, 2 )==1 );
    tprAssert( searchInsert( {1,3}, 3 )==1 );
    tprAssert( searchInsert( {1,3}, 4 )==2 );
    cout<<"=2=:done"<<endl;

    // 3
    tprAssert( searchInsert( {1,3,5}, 0 )==0 );
    tprAssert( searchInsert( {1,3,5}, 1 )==0 );
    tprAssert( searchInsert( {1,3,5}, 2 )==1 );
    tprAssert( searchInsert( {1,3,5}, 3 )==1 );
    tprAssert( searchInsert( {1,3,5}, 4 )==2 );
    tprAssert( searchInsert( {1,3,5}, 5 )==2 );
    tprAssert( searchInsert( {1,3,5}, 6 )==3 );
    cout<<"=3=:done"<<endl;

    // 4
    tprAssert( searchInsert( {1,3,5,7}, 0 )==0 );
    tprAssert( searchInsert( {1,3,5,7}, 1 )==0 );
    tprAssert( searchInsert( {1,3,5,7}, 2 )==1 );
    tprAssert( searchInsert( {1,3,5,7}, 3 )==1 );
    tprAssert( searchInsert( {1,3,5,7}, 4 )==2 );
    tprAssert( searchInsert( {1,3,5,7}, 5 )==2 );
    tprAssert( searchInsert( {1,3,5,7}, 6 )==3 );
    tprAssert( searchInsert( {1,3,5,7}, 7 )==3 );
    tprAssert( searchInsert( {1,3,5,7}, 8 )==4 );
    cout<<"=4=:done"<<endl;

    // 5
    tprAssert( searchInsert( {1,3,5,7,9}, 0 )==0 );
    tprAssert( searchInsert( {1,3,5,7,9}, 1 )==0 );
    tprAssert( searchInsert( {1,3,5,7,9}, 2 )==1 );
    tprAssert( searchInsert( {1,3,5,7,9}, 3 )==1 );
    tprAssert( searchInsert( {1,3,5,7,9}, 4 )==2 );
    tprAssert( searchInsert( {1,3,5,7,9}, 5 )==2 );
    tprAssert( searchInsert( {1,3,5,7,9}, 6 )==3 );
    tprAssert( searchInsert( {1,3,5,7,9}, 7 )==3 );
    tprAssert( searchInsert( {1,3,5,7,9}, 8 )==4 );
    tprAssert( searchInsert( {1,3,5,7,9}, 9 )==4 );
    tprAssert( searchInsert( {1,3,5,7,9}, 10 )==5 );
    cout<<"=5=:done"<<endl;


    
    debug::log( "\n~~~~ leet: 35 :end ~~~~\n" );
}
}//~
