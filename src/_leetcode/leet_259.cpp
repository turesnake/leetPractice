/*
 * ====================== leet_259.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 259. 较小的三数之和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_259 {//~


// 两层遍历，第三层用 二分查找
// 时间 O(N^2*logN)
// 并不符合题目 O(N^2) 的要求

//   24%   100%
class S{
public:
    int threeSumSmaller( std::vector<int>& nums, int target ){

        int N = static_cast<int>(nums.size());
        if(N<3){ return 0; }
        std::sort(nums.begin(), nums.end());
        int sum = 0;

        for( int a=0; a<N-2; a++ ){//[a],[a+1],[a+2]

            for( int b=a+1; b<N-1; b++ ){
                int tgt = target - nums[a] - nums[b];

                int l=b+1;
                int r=N-1;
                while( l<r ){
                    int mid=l+(r-l)/2+1;//mid-right
                    if( nums[mid] >= tgt ){
                        r = mid-1;//坚决剔除
                    }else{
                        l = mid;// 保留到下一回合
                    }
                }
                if( l==r && nums[l] < tgt ){
                    
                    cout<<"  :"<<nums[a]<<","<<nums[b]<<","<<nums[l]
                        <<"; sum:"<< nums[a]+nums[b]+nums[l] 
                        <<"; num="<<l-b<<endl;
                    
                    sum += l-b;
                }
            }
        }
        return sum;
    }
};


// 官方
// 外层一次循环嵌套。
// 内层改用双指针法


// 100%  100%
class S2{
public:
    int threeSumSmaller( std::vector<int>& nums, int target ){

        int N = static_cast<int>(nums.size());
        if(N<3){ return 0; }
        std::sort(nums.begin(), nums.end());
        int sum = 0;

        for( int a=0; a<N-2; a++ ){//[a],[a+1],[a+2]
            int tgt = target - nums[a];
            int l=a+1;
            int r=N-1;
            while( l<r ){
                if( nums[l]+nums[r] >= tgt ){
                    r--;
                }else{
                    sum += r-l;
                    l++;
                }
            }
        }
        return sum;

    }
};





//=========================================================//
void main_(){

    std::vector<int> v { -4,-1,-1,0,1,2 };

    auto ret = S{}.threeSumSmaller(v, -5 );

    cout<<"ret:"<<ret<<endl;




    
    debug::log( "\n~~~~ leet: 259 :end ~~~~\n" );
}
}//~
