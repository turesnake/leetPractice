/*
 * ====================== leet_207.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 207. 课程表
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_207 {//~


// 有向图：拓扑排序  bfs

//   62%   93%
class S{
public:
    // 你可以假定输入的先决条件中没有重复的边
    // 1 <= numCourses <= 10^5
    bool canFinish( int numCourses, std::vector<std::vector<int>>& prerequisites ){


        if( numCourses==1 || prerequisites.empty() ){ return true; }
        std::vector<int> indegrees ( numCourses, 0 );
        std::unordered_map<int,std::vector<int>> nexts {};//<val,vec>
        std::deque<int> que {};// 0入度的 idx
        int N = numCourses;

        for( auto &v : prerequisites ){
            indegrees[v[1]]++;
            nexts[v[0]].push_back( v[1] );
        }
        //-- 正式遍历 --//
        for( int i=0; i<numCourses; i++ ){
            if( indegrees[i] == 0 ){
                que.push_back( i );
                N--;
            }
        }
        while( !que.empty() ){
            int val = que.front();
            que.pop_front();
            for( int i : nexts[val] ){
                indegrees[i]--;
                if( indegrees[i]==0 ){
                    que.push_back( i );
                    N--;
                }
            }
        }
        //== check ==//
        return N==0;

    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 207 :end ~~~~\n" );
}
}//~
