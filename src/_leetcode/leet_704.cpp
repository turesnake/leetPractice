/*
 * ====================== leet_704.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 704. 二分查找
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_704 {//~



// 奇怪，怎么还有比 标准写法 更快的 ？？？？？


// 29% 5%
// 数组元素 不重复，非空，递增，可为负数
class S{
public:
    int search( std::vector<int>& nums, int target) {

        int N = static_cast<int>(nums.size());
        int l = 0;
        int r = N-1;
        while( l<=r ){
            int mid = l+(r-l)/2;//mid-left
            int v = nums.at(mid);
            if( target < v ){
                r = mid-1;
            }else if( target > v ){
                l = mid+1;
            }else{
                return mid; // find
            }   
        }
        return -1;
    }
};






//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 704 :end ~~~~\n" );
}
}//~
