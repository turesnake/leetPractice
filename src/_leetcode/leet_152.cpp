/*
 * ====================== leet_152.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 152. 乘积最大子数组
 */
#include "innLeet.h"


namespace leet_152 {//~


// 这种 区间积，一定是 前缀积
// 难点在于，要处理好 负数，和 0

// 就算使用 64位，也会在测试中导致溢出 

// 为了防止溢出，引出一种新思路：
// 用 lstZeroIdx 来表示，最后一次遇到的0的下标，初始为-1
// 每个元素，只要发现自己排在 lstZeroIdx 后面。
// 就要把自己当成 第一个元素那样，从头开始积累 

// 然而依旧会超时...




class S{
public:
    int maxProduct( std::vector<int>& nums ){

        if( nums.empty() ){ return 0; }// 可能不需要
        int N = static_cast<int>(nums.size());
        std::vector<int64_t> pres {};
        int64_t mmaxProduct { LONG_MIN };
        int lstZeroIdx = -1;
        
        for( int i=0; i<N; i++ ){
            int64_t curVal = static_cast<int64_t>(nums.at(i));

            if( curVal==0 ){
                lstZeroIdx = i;
                pres.push_back(0);// 没啥意义，仅用来对齐
                mmaxProduct = std::max(mmaxProduct, curVal);//0
            }else{

                if( i==lstZeroIdx+1 ){// 0后首元素 重新开始积累
                    pres.push_back( curVal );
                    mmaxProduct = std::max(mmaxProduct, curVal );

                }else{
                    int64_t curPrePdt = curVal * pres.back();
                    pres.push_back( curPrePdt );
                    // 先登记 此回合 前缀积
                    mmaxProduct = std::max(mmaxProduct, curPrePdt );
                    // 再登记 各个区间积
                    for( int n=lstZeroIdx+1; n<i; n++ ){
                        mmaxProduct = std::max(mmaxProduct, curPrePdt/pres.at(n) );
                    }
                }
            }
        }

        return static_cast<int>(mmaxProduct);
    }
};



//=========================================================//
void main_(){

    std::vector<int> v { -2 };

    cout<<"ret:"<<S{}.maxProduct(v)<<endl;


    debug::log( "\n~~~~ leet: 152 :end ~~~~\n" );
}
}//~
