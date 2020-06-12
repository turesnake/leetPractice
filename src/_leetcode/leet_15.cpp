/*
 * ====================== leet_15.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 15. 三数之和
 */
#include "innLeet.h"


namespace leet_15 {//~



// 这题甚至比很多困难题都麻烦 ...




// 参数列表中，元素值是可以重复的
/*
std::vector<std::vector<int>> threeSum_old1( std::vector<int>& nums ){

    if( nums.size() < 3 ){ return {}; }

    std::map<int,int> mmap {}; // { val, valNum }
    std::vector<std::vector<int>> out {};

    for( const auto &i : nums ){
        auto [insertIt, insertBool] = mmap.emplace(i, 1);
        if( !insertBool ){
            insertIt->second++;
        }
    }

    auto left = mmap.begin(); // min
    auto right = mmap.end(); right--; // max

    auto zero = mmap.find(0);
    if( (zero!=mmap.end()) && (zero->second>=3) ){
        out.push_back({ 0, 0, 0 });
    }

    while( (left->first<0) && (right->first>0) ){

        int leftVal = left->first;
        int rightVal = right->first;

        if( std::abs(leftVal) == std::abs(rightVal) ){
            if( mmap.find(0) != mmap.end() ){
                out.push_back({ leftVal, 0, rightVal });
            }
            left++;
            mmap.erase( leftVal );

            right--;
            mmap.erase( rightVal );

        }else if( std::abs(leftVal) > std::abs(rightVal) ){ // handle BIG left

            auto tmpRight = right;
            while( tmpRight->first > 0 ){

                int tmpRightVal = tmpRight->first;
                int thirdVal = -leftVal - tmpRightVal;

                if( thirdVal == tmpRightVal ){
                    if( tmpRight->second > 1 ){
                        out.push_back({ leftVal, thirdVal, tmpRightVal });
                    }
                }else if( thirdVal < tmpRightVal ){
                    if( mmap.find(thirdVal) != mmap.end() ){
                        out.push_back({ leftVal, thirdVal, tmpRightVal });
                    }
                }else{
                    break;
                }
                //-----//
                tmpRight--;
            }

            // 永久删除这个 left
            left++;
            mmap.erase( leftVal );

        }else{ // handle BIG right

            auto tmpLeft = left;
            while( tmpLeft->first < 0 ){

                int tmpLeftVal = tmpLeft->first;
                int thirdVal = -( rightVal - (-tmpLeftVal) );

                if( thirdVal == tmpLeftVal ){
                    if( tmpLeft->second > 1 ){
                        out.push_back({ tmpLeftVal, thirdVal, rightVal });
                    }
                }else if( thirdVal > tmpLeftVal ){
                    if( mmap.find(thirdVal) != mmap.end() ){
                        out.push_back({ tmpLeftVal, thirdVal, rightVal });
                    }
                }else{
                    break;
                }
                //-----//
                tmpLeft++;
            }

            // 永久删除这个 right
            right--;
            mmap.erase( rightVal );
        }
    }

    return out;
}
*/



std::vector<std::vector<int>> threeSum( std::vector<int>& nums ){

    if( nums.size() < 3 ){ return {}; }

    std::vector<std::vector<int>> out {};
    std::sort( nums.begin(), nums.end() );

    int now = 0;
    while( now < static_cast<int>(nums.size()-2) ){

        int nowVal = nums.at(now);

        if( nowVal>0 ){
            break;
        }

        int left = now + 1;
        int right = nums.size()-1;

        while( left < right ){

            int lVal = nums.at(left);
            int rVal = nums.at(right);

            bool isLeft  {false};
            bool isRight {false};

            int sum = nowVal + lVal + rVal;

            if( sum > 0 ){
                right--;
                isRight = true;
            }else if( sum < 0 ){
                left++;
                isLeft = true;
            }else{ // equal !
                out.push_back({ nowVal, lVal, rVal });
                left++;
                right--;
                // 两指针可能重合or错位，但不影响本轮
                isRight = true;
                isLeft = true;
            }

            while( isLeft && (left<right) && (nums.at(left)==nums.at(left-1)) ){
                left++;
            }
            while( isRight && (left<right) && (nums.at(right)==nums.at(right+1)) ){
                right--;
            }

        }

        do{
            now++;
        }while( (nums.at(now)==nums.at(now-1)) && (now<static_cast<int>(nums.size()-2)) );

    }

    return out;
}



/*
std::vector<std::vector<int>> threeSum_2(std::vector<int>& nums) {


    std::vector<std::vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        // 如果和前值相同，跳
        if (i > 0 && nums[i] == nums[i - 1]){ 
            continue;
        }

        // 接下来全为正数了，结束一切
        int target = nums[i];
        if(target > 0){ 
            break;
        }

        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r) {

            int sum = nums[l] + nums[r] + target;

            if( sum < 0 ){ 
                ++l;
            }else if( sum > 0 ){ 
                --r;
            }else {
                ans.push_back({target, nums[l], nums[r]});
                ++l;
                --r;
                while ( (l<r) && (nums[l] == nums[l-1]) ) ++l;
                while ( (l<r) && (nums[r] == nums[r+1]) ) --r;
            }

        }
    }
    return ans; 
}
*/



//=========================================================//
void main_(){

    std::vector<int> v { -5, -4,-3,-2,-1, 6, 7, 8, 9 };

    //std::vector<int> v { -1, 0, 1, 2 };
    //std::vector<int> v { 1,2,-2,-1 };
    //std::vector<int> v { -1,0,1,2,-1,-4, 7, -2, -5, -4, -3, 0, 0, 0 };
    //std::vector<int> v { 0, 0, 0 };
    //std::vector<int> v { -1, -3, 5 };

    //std::vector<int> v { -1, 0 };


    //std::vector<int> v { -1,0,1,2,-1,-4, 7, -2, -5, -4, -3 };

    //std::vector<int> v { -1,0,1,2,-1,-4 };

    auto retVecs = threeSum( v );

    cout << "call DONE" << endl;

    for( const auto &iVec : retVecs ){
        debug::log("--------");
        cout << "   ";

        for( const auto i: iVec ){
            cout << i << ", ";
        }
        cout << endl;
    }

    


    debug::log( "\n~~~~ leet: 15 :end ~~~~\n" );
}
}//~
