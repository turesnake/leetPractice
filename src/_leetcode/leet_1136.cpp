/*
 * ====================== leet_1136.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1136. 平行课程
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1136 {//~



//  拓扑排序


//   38%  70%
class S{
public:
    // N 门课程，{1...N}
    // 1 <= N <= 5000
    // 1 <= relations.length <= 5000
    // relations[i][0] != relations[i][1]
    // 输入中没有重复的关系
    int minimumSemesters(int N, std::vector<std::vector<int>>& relations ){


        std::vector<int> indegrees (N+1,0);
        std::vector<std::vector<int>> nexts (N+1, std::vector<int>{});

        for( auto &e : relations ){
            indegrees[e[1]]++;
            nexts[e[0]].push_back( e[1] );
        }

        int ans = 0;
        while( true ){

            std::vector<int> zeros {};

            bool isFindZero = false;   // 是否发现 入度为 0 的节点
            bool isFindBigger = false; // 是否发现 入度大于 0 的节点

            for( int i=0; i<=N; i++ ){
                if( indegrees[i]==0 ){
                    isFindZero = true;
                    zeros.push_back(i);
                    indegrees[i] = -1;
                }else if( indegrees[i]>0 ){
                    isFindBigger = true;
                }
            }

            if( !isFindZero ){
                if( isFindBigger ){
                    return -1; // 找到了 环
                }else{
                    break; // 全部元素遍历完了
                }
            }
            ans++;

            for( int i : zeros ){
                for( int b : nexts[i] ){
                    indegrees[b]--;
                }
            }
        }
        return ans;


    }
};





//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 1136 :end ~~~~\n" );
}
}//~
