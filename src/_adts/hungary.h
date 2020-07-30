/*
 * ====================== hungary.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 无项图：匈牙利算法
 */
#ifndef TPR_HUNGARY_H
#define TPR_HUNGARY_H
#include "pch.h"

namespace tpr_hungary{//~


// 最基础的问题：
// 集合 {1...M}, {1...N} 之间做 匈牙利算法
// 暂定 集合元素不超过 100 个


// 这个递归 很难懂.....


// 为 每个左集合元素m，寻找一个 “暂时”匹配的 右元素n， 此为一个 “周期”
// 在单个 “周期” 内，可能会 递归改动 之前已经分配好的 方案，
// 每次递归调用，称为 一个 "回合"



class Hungary{

    int M; // 左集合 元素个数
    int N; // 右集合 元素个数
    int Ntotal {};

    std::vector<std::vector<int>> mat {}; //邻接矩阵
    std::vector<int>  pre {}; //记录当前右侧元素所对应的左侧元素
    std::vector<char> vis {}; //记录右侧元素是否已被访问过


    // 对于最初的元素来说，并不会掉用 递归函数，因为此时 pre[n] 往往等于0
    // 可以直接绑定，然后干净地退出这个函数
    // 后期元素开始，pre[n] 往往是有值的，此时会掉用 递归函数，
    bool match( int m ){

        for( int n=1; n<=N; n++ ){

            if( mat[m][n]==0 ){ continue; }// 无效边
            if( vis[n]==1 ){ continue; }// 本套流程中，此元素，已经被访问过了

            vis[n]=1;// 核心，提前登记，这样，在本 “周期” 的后续递归 “回合” 中，会跳过本元素n

            // 核心，如果当前项n 在本周期内未使用，直接匹配它
            // 否则，用递归尝试，是否可以修改 此n 的现有匹配对象m （这个修改是链式的）
            if( pre[n]==0 || match(pre[n]) ){
                pre[n]=m;    //执行匹配操作
                return true; //返回匹配成功
            }
        }
        return false; //循环结束，仍未找到匹配，返回匹配失败
    }


public:

    int Hungarian( int M_, int N_ ){

        M=M_;
        N=N_;
        mat.resize( M, std::vector<int>(N, 0) );
        pre.resize( N, 0 );

        //--- 一个缺失的环节 ---//
        // 将数据中，存在的有效边，写入 mat矩阵中：1
        // ...

        int cnt = 0;

        // 为每一个 左集元素m，匹配一个 “临时” 的匹配项n
        // 此为一个 “周期”
        for( int m=1; m<=M; m++ ){
            vis.clear(); // 每个周期，都要清空 vis
            vis.resize( N, 0 );
            if( match(m) ){ cnt++; }
        }
        return cnt;
    }

};








}//~
#endif
