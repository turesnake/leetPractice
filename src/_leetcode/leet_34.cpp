/*
 * ====================== leet_34.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_34 {//~


// 二分查找 77%, 100%
// 寻找左侧区间 还是 右侧区间时，要用不同的 mid 计算法
std::vector<int> searchRange( std::vector<int> nums, int target ){

    int N = static_cast<int>(nums.size());
    int l=0;
    int r=N-1;
    int mid {};
    //-- 找到第一个 target --//
    bool isFind {false};
    while( l<=r ){
        mid = l+(r-l)/2;
        int v = nums.at(mid);//mid-left
        if( v < target ){
            l = mid+1;
        }else if( v > target ){
            r = mid-1;
        }else{//==
            isFind = true;
            break;
        }
    }
    //debug::log( "isFind={}; mid={}, l={}, r={}", isFind, mid, l, r );
    if( !isFind ){ return {-1,-1}; }

    //-- 寻找两侧边界  --//
    int confirm = mid; // 上次搜索中，确定为 target 的值
    int mmin {};
    int mmax {};
    // 寻找 左边界 
    l=0;
    r=confirm;
    while( l<=r ){
        if( l==r ){
            mmin = l;
            break;
        }
        mid = l+(r-l)/2;//mid-left
        if( nums.at(mid)==target ){// 可能等于，保留到下一回合
            r = mid;
        }else{// 小于，一定被剔除
            l = mid+1;
        }
    }
    // 寻找 右边界 
    l=confirm;
    r=N-1;
    while( l<=r ){
        if( l==r ){
            mmax = l;
            break;
        }
        mid = l+(r-l)/2+1;//mid-right
        if( nums.at(mid)==target ){// 可能等于，保留到下一回合
            l = mid;
        }else{// 大于，一定被剔除
            r = mid-1;
        }
    }
    return { mmin, mmax };
}




//=========================================================//
void main_(){


    auto ret = searchRange( { 5,7,7,8,8,10 }, 10 );
    for( int i : ret ){
        cout << i << ", ";
    }
    cout<<endl;
    

    debug::log( "\n~~~~ leet: 34 :end ~~~~\n" );
}
}//~
