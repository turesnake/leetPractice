/*
 * ====================== UnionFindSet.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 并查集
 */
#ifndef TPR_UNION_FIND_SET_H
#define TPR_UNION_FIND_SET_H
#include "pch.h"



class UnionFindSets{

    // 根节点 parentIdx < 0, 绝对值表示 本树高度, 比如 -1,-4
    std::vector<std::pair<int,int>> datas {}; // <val,parentIdx>
public:


    void insert( int val_, int parentIdx_ ){
        if( parentIdx_ >= 0 ){
            assert( parentIdx_ < static_cast<int>(datas.size()) ); // 不指向未存在的元素
        }
        this->datas.push_back({ val_, parentIdx_ });
        // 更新 根节点 高度信息
        int deep { 1 };
        int i = static_cast<int>(datas.size())-1; // 本元素下标
        for( ; datas.at(i).second>=0; i=datas.at(i).second,deep++ ){} //找到根节点下标
        datas.at(i).second = -deep; // 修改深度值
    }


    // 查找目标元素 根节点下标
    int find( int val_ ){
        int datasSize = static_cast<int>(datas.size());
        int i=0; 
        for( ; i<datasSize && datas.at(i).first!=val_; i++ ){}
        if( i >= datasSize ){ return INT_MIN; }// 目标元素不存在
        for( ; datas.at(i).second>=0; i=datas.at(i).second ){} //找到根节点下标
        return i;
    }


    void union1( int v1_, int v2_ ){
        int root1 = this->find( v1_ );
        int root2 = this->find( v2_ );
        assert( root1 != INT_MIN ); // 必须存在
        assert( root2 != INT_MIN ); // 必须存在
        if( root1 == root2 ){ return; } // already union
        int len1 = (-datas.at(root1).second);
        int len2 = (-datas.at(root2).second);
        if( len1 == len2 ){
            datas.at(root2).second = root1;
            datas.at(root1).second -= 1; // 变高了
        }else if( len1 > len2 ){
            datas.at(root2).second = root1;
        }else{
            datas.at(root1).second = root2;
        }
    }


    void debug0()const{
        debug::log( "-UF--------------" );
        for( int i=0; i<static_cast<int>(datas.size()); i++ ){
            auto &[v,p] = datas.at(i);
            debug::log( "{}- val: {}, parentIdx: {}", i, v, p );
        }        
        debug::log( "-----------<<<---" );
    }
};







#endif
