/*
 * ====================== FenwickTree.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 树状数组
 */
#ifndef TPR_FENWICK_TREE_H
#define TPR_FENWICK_TREE_H
#include "pch.h"


// 树状数组
// 内部，从1号开始存储
class Fenwick_Tree{
public:
    Fenwick_Tree()=default;

    void init( size_t num_ ){
        this->tree.resize( num_+1, 0 );//0号空缺
    }

    void add( int idx_, int val_ ){
        int i = idx_+1; // 内部从1号开始存储
        while( i < static_cast<int>(tree.size()) ){
            this->tree.at(i) += val_;
            i += lowBits(i); // 指向自己父节点
        }
    }
        
    // [0, idx_] 前缀和
    int sum( int idx_ ){
        int i = idx_+1; // 内部从1号开始存储
        int ans {0};
        while( i > 0 ){
            ans += tree.at(i);
            i -= lowBits(i);// 指向排在自己下方（前部）的，比自己大一级的区间节点
        }
        return ans;
    }

private:
    // 获得 数字在二进制表达中，最后一位1 的 数字表示
    // 6(0b110),去掉尾部1，变成 4(0b100)
    int lowBits( int v_ ){
        return (v_&(-v_));
    }

    std::vector<int> tree {};
};



#endif 
