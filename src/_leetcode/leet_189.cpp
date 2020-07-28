/*
 * ====================== leet_189.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 189. 旋转数组
 */
#include "innLeet.h"


namespace leet_189 {//~


//   86%  5%
class S{
public:
    // k>=0
    void rotate( std::vector<int>& nums, int k ){

    
        if(k==0){ return; }
        int N = static_cast<int>(nums.size());
        int j = N - k%N;
        nums.insert( nums.end(), nums.begin(), nums.begin()+j );
        nums.erase( nums.begin(), nums.begin()+j );

        
    }
};


//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 189 :end ~~~~\n" );
}
}//~
