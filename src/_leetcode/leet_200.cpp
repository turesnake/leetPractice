/*
 * ====================== leet_200.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 200. 岛屿数量
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_200 {//~


class S {
public:


// 需要对 并查集 做一定的改装
// 原始并查集中，find 查找的是 val，每次都要遍历整个数据集。
// 可以改成基于下标的。代价就是把 无关信息（水域）也填充进来
// 
class UF{
    // 根节点 parentIdx < 0, 绝对值表示 本树高度
    std::vector<std::pair<int,int>> datas {}; // <val,parentIdx>
public:
    void insert( int val_, int parentIdx_ ){
        this->datas.push_back({ val_, parentIdx_ });
        if( parentIdx_ == INT_MAX ){ return; }// 水域
        // 更新 根节点 高度信息
        int deep { 1 };
        int i = static_cast<int>(datas.size())-1; // 本元素下标
        for( ; datas.at(i).second>=0; i=datas.at(i).second,deep++ ){} //找到根节点下标
        datas.at(i).second = -deep; // 修改深度值
    }

    // 直接用下标查找
    int find_by_idx( int idx_ ){
        if( idx_ >= static_cast<int>(datas.size()) ){ return INT_MIN; }// 目标元素不存在
        for( ; datas.at(idx_).second>=0; idx_=datas.at(idx_).second ){} //找到根节点下标
        return idx_;
    }

    void union_by_idx( int idx1_, int idx2_ ){
        int root1 = this->find_by_idx( idx1_ );
        int root2 = this->find_by_idx( idx2_ );
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


    int rootNums()const{
        int num {0};
        for( const auto &[v,p] : datas ){
            if( p<0 ){ num++; }
        }
        return num;
    }

    /*
    void debug0()const{
        debug::log( "-UF--------------" );
        for( int i=0; i<static_cast<int>(datas.size()); i++ ){
            auto &[v,p] = datas.at(i);
            debug::log( "{}- val: {}, parentIdx: {}", i, v, p );
        }        
        debug::log( "-----------<<<---" );
    }
    */
};




    int numIslands( std::vector<std::vector<char>>& grid ) {

        if( grid.size()==0 || grid.at(0).size()==0 ){ return 0; }

        int h = static_cast<int>(grid.size());
        int w = static_cast<int>(grid.at(0).size());
        UF uf {};
        for( int j=0; j<h; j++ ){
            for( int i=0; i<w; i++ ){
                int elemIdx = j*w + i;
                
                bool isSelfLand = grid.at(j).at(i)=='1';
                if( !isSelfLand ){ 
                    uf.insert( elemIdx, INT_MAX ); // p值没有任何意义，仅用来占位
                    continue; 
                }
                uf.insert( elemIdx, -1 );

                bool isTopLand   = (j==0) ? false : grid.at(j-1).at(i)=='1';
                bool isLeftfLand = (i==0) ? false : grid.at(j).at(i-1)=='1';
                if( isTopLand ){
                    uf.union_by_idx( elemIdx, (j-1)*w + i );
                }
                if( isLeftfLand ){
                    uf.union_by_idx( elemIdx, j*w + (i-1) );
                }
            }
        }
        return uf.rootNums();
    }

};



//=========================================================//
void main_(){

    /*
    // UF 测试
    S::UF uf {};
    uf.insert( 1, -1 );
    uf.insert( 2,  0 );
    uf.insert( 3, -1 );
    uf.insert( 4,  0 );
    uf.insert( 5,  2 );
    uf.insert( 6, -1 );
    uf.insert( 7,  0 );
    uf.insert( 8,  2 );
    uf.insert( 9,  5 );
    uf.insert(10,  5 );
    uf.insert(11,  9 );

    uf.debug();
    uf.union1( 8, 11 );
    uf.debug();
    */

    std::vector<std::vector<char>> v1 {
        { '1','1','1','1','0' },
        { '1','1','0','1','0' },
        { '1','1','0','0','0' },
        { '0','0','0','0','0' }
    };
    std::vector<std::vector<char>> v2 {
        { '1','1','0','0','0' },
        { '1','1','0','0','0' },
        { '0','0','1','0','0' },
        { '0','0','0','1','1' }
    };
    auto ret = S{}.numIslands( v2 );

    cout << "ret = " << ret << endl;




    
    


    debug::log( "\n~~~~ leet: 200 :end ~~~~\n" );
}
}//~

