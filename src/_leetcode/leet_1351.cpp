/*
 * ====================== leet_1351.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1351. 统计有序矩阵中的负数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1351 {//~


// 二分查找 83%, 100%
class S{
public:
    // 1 <= m, n <= 100
    // -100 <= grid[i][j] <= 100
    int countNegatives( std::vector<std::vector<int>>& grid ){

        int H = static_cast<int>(grid.size());
        int W = static_cast<int>(grid.at(0).size());
        int sum = 0;
        int wn = INT_MAX; //本行第一个负元素下标

        for( int h=0; h<H; h++ ){
            int l = 0;
            int r = (wn==INT_MAX) ? (W-1) : wn;
            bool isFindNeg {false};
            while(l<=r){
                if( l==r ){  // find
                    isFindNeg = grid.at(h).at(l)<0;
                    break; 
                }
                int mid = l+(r-l)/2;//mid-left
                if( grid.at(h).at(mid) >= 0 ){
                    l = mid+1; // 坚决剔除
                }else{
                    r = mid; // 保留到下一回合
                }
            }
            if(isFindNeg){ 
                wn = l;
                sum += W-wn; 
            }
        }
        return sum;
    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {4,3,2,1}
    };

    cout<<S{}.countNegatives(v)<<endl;

    
    debug::log( "\n~~~~ leet: 1351 :end ~~~~\n" );
}
}//~
