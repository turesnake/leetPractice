/*
 * ====================== leet_57.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 57. 插入区间
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_57 {//~



// 二分查找




//   81%   100%
class S{
public:
    std::vector<std::vector<int>> insert(   std::vector<std::vector<int>>& intervals, 
                                            std::vector<int>& newInterval ){
        
        // 前置补丁
        if( intervals.empty() ){
            intervals.push_back( newInterval );
            return intervals;
        }
        if( newInterval[1] < intervals[0][0] ){
            intervals.insert( intervals.begin(), 1, newInterval );
            return intervals;
        }
        if( newInterval[0] > intervals.back()[1] ){
            intervals.push_back( newInterval );
            return intervals;
        }

        int N = static_cast<int>(intervals.size());

        //=== 收集 左区间 ==//
        int l=0; 
        int r=N-1;
        while( l<r ){
            int mid = l+(r-l)/2;//mid-left
            if( intervals[mid][1] < newInterval[0] ){
                l = mid+1;// 坚决剔除
            }else{
                r = mid;// 保留到下一回合
            }
        }
        int tgtL = l;
        //=== 收集 右区间 ==// 
        l=0;
        r=N-1;
        while( l<r ){
            int mid = l+(r-l)/2+1;//mid-right
            if( intervals[mid][0] > newInterval[1] ){
                r = mid-1;// 坚决剔除
            }else{
                l = mid;// 保留到下一回合
            }
        }
        int tgtR = l;


        if( tgtL>tgtR ){
            assert( tgtL-tgtR==1 );
            // 在 l 位置，插入 新区间
            intervals.insert( intervals.begin()+tgtL, 1, newInterval );
        }else{
            int nL = std::min( intervals[tgtL][0], newInterval[0] );
            int nR = std::max( intervals[tgtR][1], newInterval[1] );
            if( tgtR>tgtL ){
                intervals.erase( intervals.begin()+tgtL+1, intervals.begin()+tgtR+1 );
            }
            intervals[tgtL][0] = nL;
            intervals[tgtL][1] = nR;
        }
        return intervals;

        
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 57 :end ~~~~\n" );
}
}//~
