/*
 * ====================== leet_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 两数之和
 */
#include "innLeet.h"


namespace leet_1 {//~




std::vector<int> twoSum( std::vector<int>& nums, int target ) {

    std::unordered_multimap<int,int> umap {}; // {val,idx}

    int numsSize = static_cast<int>(nums.size());

    for( int i=0; i<numsSize; i++ ){
        umap.emplace( nums.at(i), i );
    }

    for( int i=0; i<numsSize; i++ ){

        int b = target - nums.at(i);

        size_t howmuch = umap.count( b );
        if( howmuch > 0 ){

            auto bIt = umap.find(b);

            while( howmuch > 0 ){
                if( bIt->second != i ){
                    return { i, bIt->second };
                }
                i++;
                howmuch++;
            }
        }
    }
    return {};
}



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 11 :end ~~~~\n" );
}
}//~
