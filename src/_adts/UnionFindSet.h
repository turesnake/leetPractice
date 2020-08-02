/*
 * ====================== UnionFindSet.h =====================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 并查集
 */
#ifndef TPR_UNION_FIND_SET_H
#define TPR_UNION_FIND_SET_H
#include "pch.h"

namespace tpr_UnionFindSet{//~


// 比较简单的一版
// 0 可空置，也可不空置
// 每个元素初始时，等于自己，表示，自己是个 独立的集
// ---
// 合并两个集 a，b，时，先找到 rootA,rootB,然后让 两个root 建立 父子关系
// ---
// find_root() 函数 是核心
// 其中包含 路径压缩，建议将其 实现为 递归版，更容易理解
// 在递归版中，所有 子元素，都在遍历过程中，直接指向 本路径最终root
// 树的深度变矮了，反过来减少了 递归的深度，
// 最终导致，实际的递归深度，并不深
// ---
// 如果某个元素 等于自己的下标值，说明自己是 root


// 还可以有 带权重的 并查集
// 例见 339


class UnionFindSet{

    std::vector<int> st {};
    int N {};

    // 递归版，更容易理解
    int find_root_1( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find_root_1( st[a] );// 路径压缩
        return st[a];
    }

    // 迭代版, 没有 递归版 易于理解
    int find_root_2( int a ){
        while( st[a]!=a ){
            a = st[a];
            st[a] = st[st[a]];// 路径压缩
        }
        return a;
    }

public:
    void init(int N_){
        N=N_;
        st.resize(N);
        for( int i=0; i<N; i++ ){
            st[i]=i;
        }
    }

    void merge( int a, int b ){
        int ra = find_root_1(a);
        int rb = find_root_1(b);
        if( ra==rb ){ return; }
        st[rb] = ra;
    }

    bool isSameRoot( int a, int b ){
        return find_root_1(a) == find_root_1(b);
    }


};




}//~
#endif
