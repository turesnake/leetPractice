/*
 * ====================== leet_307.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 307. 区域和检索 - 数组可修改
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_307 {//~


 
class NumArray {

    // 树状数组
    // 内部，从1号开始存储
    class Fenwick_Tree{
        std::vector<int> tree {};
        // 获得 数字在二进制表达中，最后一位1 的 数字表示
        // 6(0b110),去掉尾部1，变成 4(0b100)
        int lowBits( int v_ ){
            return (v_&(-v_));
        }
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
                i -= lowBits(i);// 排在自己下方（前部）的，比自己大一级的区间节点
            }
            return ans;
        }
    };


    std::vector<int>    datas {};
    Fenwick_Tree        tree {};

public:

    NumArray( std::vector<int>& nums ) {
        this->datas.insert( this->datas.end(), nums.begin(), nums.end() );
        this->tree.init( nums.size() );
        for( int i=0; i<static_cast<int>(nums.size()); i++ ){
            this->tree.add( i, nums.at(i) );
        }
    }
    
    void update( int i, int val ) {
        int off = val - this->datas.at(i);
        this->datas.at(i) = val;
        this->tree.add( i, off );
    }
    
    int sumRange( int i, int j ) {
        return this->tree.sum(j) - this->tree.sum(i-1);
    }
};









//=========================================================//
void main_(){


    


    debug::log( "\n~~~~ leet: 307 :end ~~~~\n" );
}
}//~

