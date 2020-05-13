/*
 * ====================== leet_27.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 移除元素
 */
#include "innLeet.h"


namespace leet_27 {//~



int removeElement( std::vector<int>& nums, int val) {

    if( nums.empty() ){ return 0; }
        
    int left = 0;
    int right = nums.size()-1;

    while( left < right ){

        while( (left<right) && (nums.at(right)==val) ){
            right--;
        }

        while( (left<right) && (nums.at(left)!=val) ){
            left++;
        }

        if( left >= right ){
            break;
        }

        // swap
        std::swap( nums.at(left), nums.at(right) );
    }

    return (nums.at(left)==val) ? left : (left+1);
}



int removeElement_2( std::vector<int>& nums, int val) {

    int fast = 0;
    int slow = 0;

    for( ; fast< static_cast<int>(nums.size()); fast++ ){
        if( nums.at(fast) != val ){
            nums.at(slow) = nums.at(fast);
            slow++;
        }
    }
    
    return slow;
}




//=========================================================//
void main_(){

    //std::vector<int> v { 3,2,2,3 };
    //int ret = removeElement( v, 3 );

    std::vector<int> v { 0,1,2,2,3,0,4,2 };
    int ret = removeElement_2( v, 2 );

    //std::vector<int> v { 2,2,1 };
    //int ret = removeElement( v, 2 );



    cout << "arrNum: " << ret << endl;

    for( const auto &i : v ){
        cout << i << ", ";
    }
    cout << endl;


    
    


    debug::log( "\n~~~~ leet: 27 :end ~~~~\n" );
}
}//~
