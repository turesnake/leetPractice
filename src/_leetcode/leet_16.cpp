/*
 * ====================== leet_16.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 最接近的三数之和  
 */
#include "innLeet.h"


namespace leet_16 {//~




int threeSumClosest( std::vector<int>& nums, int target ) {

    std::sort( nums.begin(), nums.end() );

    int out {};
    int curMin { 0x7fffffff }; // init max
    int now = 0;

    while( now < static_cast<int>(nums.size()-2) ){

        int nowVal = nums.at(now);

        int left = now + 1;
        int right = nums.size() - 1;

        while( left < right ){

            int leftVal = nums.at(left);
            int rightVal = nums.at(right);

            int sum = nowVal + leftVal + rightVal;
            if( sum > target ){

                if( sum-target < curMin ){
                    curMin = sum-target;
                    out = sum;
                }
                right--;

            }else if( sum < target ){

                if( target-sum < curMin ){
                    curMin = target-sum;
                    out = sum;
                }
                left++;

            }else{
                return target;
            }

        }
        //-----//
        now++;
    }

    return out;
}






//=========================================================//
void main_(){

    std::vector<int> v { -1 , 2, 1, -4 };

    int ret = threeSumClosest( v, 1 );

    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 16 :end ~~~~\n" );
}
}//~
