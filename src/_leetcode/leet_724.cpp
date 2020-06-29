/*
 * ====================== leet_724.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 724. 寻找数组的中心索引
 */
#include "innLeet.h"


namespace leet_724 {//~


// 先求得所有元素和，然后从左向右遍历，一旦发现 符合的，就返回 


//   41%   6%
class S{
public:
    // nums 的长度范围为 [0, 10000]
    // 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数
    int pivotIndex( std::vector<int>& nums ){

        if( nums.empty() ){ return -1; }

        int N = static_cast<int>(nums.size());

        int l = 0;
        int r = 0;// sum
        for( int i=1; i<N; i++ ){  r += nums[i]; }
        if( r==0 ){ return 0; }
        
        for( int i=1; i<N; i++ ){// [i-1], [i]
            r -= nums[i];
            l += nums[i-1];
            //cout<<"i:"<<i<<", l:"<<l<<", r"<<r<<endl;
            if( l==r ){ return i; }
        }
        return -1;



    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 1,2,3 };

    cout << S{}.pivotIndex(v) << endl;


    
    debug::log( "\n~~~~ leet: 724 :end ~~~~\n" );
}
}//~
