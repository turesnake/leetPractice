/*
 * ====================== leet_980.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 980. 不同路径 III
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_980 {//~




// dfs 回溯 77%,  100%
class S{

    std::vector<std::vector<int>> *gridp {};
    int H {};
    int W {};
    int roadNum {0};
    int targetDeep {};

    const std::vector<std::pair<int,int>> nearOffs {
        {-1,0},{1,0},{0,-1},{0,1}
    };


    // dfs
    // [h][w] 可能是无效的，要检测
    void walk( int h, int w, int deep ){
        int mapVal = gridp->at(h).at(w);
        if( mapVal == 2 ){
            // 只有彻底遍历的，才被统计
            if( deep==targetDeep ){ roadNum++; }
            return;
        }
        gridp->at(h).at(w) = -2;//表示 本格 已经走过了
        for( const auto &[offW,offH] : nearOffs ){
            int newW = w + offW;
            int newH = h + offH;
            if( newW<0 || newW>=W || newH<0 || newH>=H ){ continue; }
            if( gridp->at(newH).at(newW)<0 ){ continue; }// 直接不走无效路
            walk( newH, newW, deep+1 );
        }
        gridp->at(h).at(w) = 0;
    }



public:
    // 1 <= len * [0].len <= 20
    // == 1 起点
    // == 2 终点
    // == 0 可行走
    // == -1 法定障碍
    // == -2 自设障碍
    int uniquePathsIII( std::vector<std::vector<int>>& grid ){

        H = static_cast<int>(grid.size());
        W = static_cast<int>(grid.at(0).size());
        if( H==1 && W==1 ){ return 0; }
        gridp = &grid;
        // 找到 起点
        int begW = 0;
        int begH = 0;
        int negNum = 0; // -1 个数
        bool isFind = false;
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                int v = grid.at(h).at(w);
                if( v==1 ){
                    isFind = true;
                    begW = w;
                    begH = h;
                }else if( v==-1 ){
                    negNum++;
                }
            }
        }
        if( !isFind ){ return false; }
        targetDeep = W*H - negNum;
        //cout<<"begW:"<<begW<<" begH:"<<begH<<endl;
        walk( begH, begW, 1 );
        return roadNum;
    }
};



//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,2}
    };

    cout<<"ret:"<<S{}.uniquePathsIII(v)<<endl;

    
    debug::log( "\n~~~~ leet: 980 :end ~~~~\n" );
}
}//~
