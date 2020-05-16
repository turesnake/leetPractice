/*
 * ====================== leet_209.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 209. 长度最小的子数组
 */
#include "innLeet.h"


namespace leet_209 {//~


// 双指针法
int minSubArrayLen(int s, std::vector<int>& nums) {

    if( nums.empty() ){ return 0; }

    int left  {0}; // window lst elem
    int right {0}; // window fst elem
    int sum {0};
    int minLen { INT_MAX };

    // 每一循环都固定递进 right，然后动态收缩 left
    for( ; right<static_cast<int>(nums.size()); right++ ){

        sum += nums.at(right);
        if( sum == s ){// perfect
            minLen = std::min( minLen, right-left+1 );
        }else if( sum > s ){

            while( left <= right ){
                sum -= nums.at(left);
                left++;
                // 现在，窗口收缩了一格，left 重新指向新区间 lst elem
                if( sum == s ){// perfect
                    minLen = std::min( minLen, right-left+1 );
                    break;
                }else if( sum < s ){// last time is ok
                    minLen = std::min( minLen, right-left+2 );
                    break;
                }
            }
        }
    }
    return (minLen==INT_MAX) ? 0 : minLen;
}







//=========================================================//
void main_(){

    //std::vector<int> v {};
    std::vector<int> v { 2,3,1,2,4,3 };

    //int ret = minSubArrayLen( 7, v );
    int ret = minSubArrayLen( 7, v );
    
    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 209 :end ~~~~\n" );
}
}//~
