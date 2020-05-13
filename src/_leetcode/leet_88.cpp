/*
 * ====================== leet_88.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 合并两个有序数组
 */
#include "innLeet.h"


namespace leet_88 {//~



void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    
    int p1 = m-1;
    int p2 = n-1;
    int tail = m+n-1;

    while( (p1>=0) && (p2>=0) ){

        if( nums2.at(p2) >= nums1.at(p1) ){
            nums1.at(tail) = nums2.at(p2);
            p2--;
        }else{
            nums1.at(tail) = nums1.at(p1);
            p1--;
        }
        tail--;
    }

    while( p2>=0 ){
        nums1.at(tail) = nums2.at(p2);
        tail--;
        p2--;
    }

}




//=========================================================//
void main_(){

    std::vector<int> v1 { 6,7,8,0,0,0 };
    std::vector<int> v2 { 1,2,3 };

    merge( v1, 3, v2, 3 );

    for( const auto &i : v1 ){
        cout << i << ", ";
    }
    cout << endl;
    

    debug::log( "\n~~~~ leet: 88 :end ~~~~\n" );
}
}//~
