/*
 * ====================== leet_26.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 26. 删除排序数组中的重复项  
 */
#include "innLeet.h"


namespace leet_26 {//~




int removeDuplicates( std::vector<int>& nums) {

    if( nums.size() < 2 ){
        return nums.size();
    }

    auto tail = nums.begin();
    auto head = tail;

    while( tail != nums.end() ){
        
        head = tail + 1;
        while( true ){
            if(head==nums.end()){
                // 最后一组数了
                nums.erase( tail+1, head );
                return nums.size();
            }
            if( *head != *tail ){
                break;
            }
            head++;
        }

        // 现在，head 指向新值
        tail = nums.erase( tail+1, head );
    }

    return 0;
}





int removeDuplicates_2( std::vector<int>& nums) {

    auto last = std::unique( nums.begin(), nums.end() );
    nums.erase( last, nums.end() ); 
    return nums.size();
}






//=========================================================//
void main_(){

    //std::vector<int> v { 0,0,1,1,1,2,2,3,3,4 };
    std::vector<int> v { 0, 0, 0, 1, 2,2 };

    int ret = removeDuplicates_2( v );

    cout << "ret = " << ret << endl;
    for( const auto &i : v ){
        cout << i << ", ";
    }
    cout << endl;


    debug::log( "\n~~~~ leet: 26 :end ~~~~\n" );
}
}//~
