/*
 * ====================== leet_18.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 18. 四数之和
 */
#include "innLeet.h"


namespace leet_18 {//~


// 朴素法
// 在 三数之和 的基础上，再增加一个维度，
// 时间 O(N^3)

//   32%  100%
class S{
public:
    std::vector<std::vector<int>> fourSum( std::vector<int>& nums, int target ){

        int N = static_cast<int>(nums.size());
        if(N<4){ return {}; }
        std::sort( nums.begin(), nums.end() );
        std::vector<std::vector<int>> ans {};

        for( int a=0; a<=N-4; a++ ){
            if( a>0 && nums[a]==nums[a-1] ){ continue; }
            for( int b=a+1; b<=N-3; b++ ){
                if( b>a+1 && nums[b]==nums[b-1] ){ continue; }
                int c=b+1;
                int d=N-1;
                while( c<d ){
                    if( c>b+1 && nums[c]==nums[c-1] ){ c++; continue; }
                    if( d<N-1 && nums[d]==nums[d+1] ){ d--; continue; }
                    //---//
                    int tsum = nums[a] + nums[b] + nums[c] + nums[d];
                    if( tsum>target ){
                        d--;
                    }else if( tsum<target ){
                        c++;
                    }else{// ==
                        ans.push_back({ nums[a], nums[b], nums[c], nums[d] });
                        c++;
                        d--;
                    }
                }
            }
        }
        return ans;

        
    }
};



//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 18 :end ~~~~\n" );
}
}//~
