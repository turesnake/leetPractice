/*
 * ====================== leet_252.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 252. 会议室
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_252 {//~


// 只要一个区间，和另一个区间 相交，即可返回 false
// 全部不相交，返回 true
// 但是，这种朴素法会超时 


// 排序法：  47%，  100%
// 先排序，然后就可以用 O(N) 时间，单次遍历，检查所有区间关系
class S{
public:
    bool canAttendMeetings( std::vector<std::vector<int>>& intervals ){

        std::sort( intervals.begin(), intervals.end() );
        int N = static_cast<int>(intervals.size());
        for( int i=1; i<N; i++ ){// [i-1],[i]
            if( intervals.at(i).at(0) < intervals.at(i-1).at(1) ){
                return false;
            }
        }
        return true;
    }
};




// 另一种办法，离散法
// 将每个区间的 开始节点 和 结束节点，记录在 std::map 中
// 从小到大遍历 map，遇见 开始节点，就+1, 遇见 结束节点，就-1
// 当发现维护的值，>=2 意味着同时开展了 2 场会议。ret false
// 这个思路非常巧





//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 252 :end ~~~~\n" );
}
}//~
