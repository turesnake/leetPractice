/*
 * ====================== leet_m53.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题53 - II. 0～n-1中缺失的数字
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m53 {//~



// 差值法。最直接的思路
// 缺点，需要遍历整个数组，计算和
int missingNumber( std::vector<int>& nums ){

    int N = static_cast<int>(nums.size());
    int sum {0};
    for( int i : nums ){ sum += i; }
    return (N+1)*N/2 - sum;
}



// 二分查找，
// 正常时，值应该和 下标 相同. 第一个和下标不同的值，它的下标值，就是目标
int missingNumber_2( std::vector<int>& nums ){

    int l = 0;
    int r = static_cast<int>(nums.size()) - 1;
    while( l < r ){
        int mid = l + (r-l)/2;// 中间偏左
        (mid==nums.at(mid)) ?
            l = mid+1 : //此值正常，目标在后半段
            r = mid;    // 目标在前半段（包含自己）
    }
    return (l==nums.at(l)) ? l+1 : l;
}






//=========================================================//
void main_(){

    //std::vector<int> v { 0,2,3,4 };
    //std::vector<int> v { 0,1,2,3,4 };
    //std::vector<int> v { 0 };
    //std::vector<int> v { 1 };
    //std::vector<int> v { 0,1,2,3,4,5,7 };
    std::vector<int> v { 0,1,3,4,5 };

    cout << missingNumber_2(v) << endl;
    

    

    debug::log( "\n~~~~ leet: m53 :end ~~~~\n" );
}
}//~
