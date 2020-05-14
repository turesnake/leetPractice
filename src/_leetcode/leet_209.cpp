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



int minSubArrayLen(int s, std::vector<int>& nums) {

    int left  {0}; // window tail idx
    int right {0}; // window head idx

    int sum {0};
    int  minSize { 0x7fffffff };
    bool isMinSize {false};

    for( ; right<static_cast<int>(nums.size()); right++ ){

        sum += nums.at(right);

        if( sum == s ){// perfect
            minSize = std::min( minSize, right-left+1 );
            if( !isMinSize ){ isMinSize = true; }

        }else if( sum > s ){

            while( left <= right ){

                sum -= nums.at(left);
                left++;
                if( sum == s ){// perfect
                    minSize = std::min( minSize, right-left+1 );
                    if( !isMinSize ){ isMinSize = true; }
                    break;
                }else if( sum < s ){// last time is ok
                    minSize = std::min( minSize, right-left+2 );
                    if( !isMinSize ){ isMinSize = true; }
                    break;
                }
            }
        }
    }

    return isMinSize ? minSize : 0;
}







//=========================================================//
void main_(){

    std::vector<int> v {};
    //std::vector<int> v { 2,3,1,2,4,3 };

    int ret = minSubArrayLen( 7, v );
    
    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 209 :end ~~~~\n" );
}
}//~
