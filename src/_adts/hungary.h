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
    // --
    // vis 比较奇怪，它只在一个元素的查找周期内，有效，之后会被彻底清空
    bool match( int m ){

        for( int n=1; n<=N; n++ ){
            if( mat[m][n]==1 && vis[n]==0 ){ //有边且未访问
                vis[n]=1;                    //记录状态为访问过，只修改一次，不可逆
                if( pre[n]==0 || match(pre[n]) ){ //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
                    pre[n]=m;      //当前左侧元素成为当前右侧元素的新匹配
                    return true; //返回匹配成功
                }
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
        for( int m=1; m<=M; m++ ){
            vis.resize( N, 0 );
            if( match(m) ){ cnt++; }
        }
        return cnt;
    }



};





}//~
#endif
