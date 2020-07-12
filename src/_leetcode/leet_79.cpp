/*
 * ====================== leet_79.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 79. 单词搜索
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_79 {//~

// dfs + 回溯
// 矩阵中，一个字母 只能被使用一次，需要用 一个矩阵 来标记每个 字母的 使用情况。


// 此题中的 dfs，不知道 能不能用 迭代来实现


//   79%   100%
class S{

    const std::vector<std::vector<int>> nearOffs{
        { -1,  0 },
        {  1,  0 },
        {  0, -1 },
        {  0,  1 }
    };


    std::vector<std::vector<char>>  *bp {nullptr};
    std::string                     *wordp {nullptr};
    int H {};
    int W {};
    int Ns {};

    std::vector<std::vector<char>> uses {}; // 0:未使用  1:已使用


    bool work( int w, int h, int idx ){

        if( idx==Ns-1 ){ return true; }
        uses[h][w] = 1;//登记
        bool isFind = false;
        for( const auto &off : nearOffs ){
            int nw = w + off[0];
            int nh = h + off[1];
            if( nw<0 || nw>=W || nh<0 || nh>=H){ continue; }
            if( uses[nh][nw]==0 && (*bp)[nh][nw]==(*wordp)[idx+1] ){
                bool bl = work( nw, nh, idx+1 );
                if( bl ){ return true; }
            }
        }
        uses[h][w] = 0;// 解除登记
        return false;
    }

public:
    // 只含 大小写 字母
    // 1 <= board.length <= 200
    // 1 <= board[i].length <= 200
    // 1 <= word.length <= 10^3
    bool exist( std::vector<std::vector<char>>& board, std::string word ){

        bp = &board;
        wordp = &word;
        H = static_cast<int>(board.size());
        W = static_cast<int>(board[0].size());
        Ns = static_cast<int>(word.size());

        uses.resize( H, std::vector<char>(W, 0) );
            
        // 收集 所有 起点
        for( int h=0; h<H; h++ ){
            for( int w=0; w<W; w++ ){
                if( board[h][w] == word[0] ){
                    if( work( w, h, 0 ) ){ return true; }
                }
            }
        }
        return false;
    }
};





//=========================================================//
void main_(){

    std::vector<std::vector<char>> m {
        { 'A','B','C','E' },
        { 'S','F','E','S' },
        { 'A','D','E','E' }
    };

    std::string word = "ABCESEEEFS";

    auto ret = S{}.exist( m, word );

    debug::log( "ret:{}", ret );

    

    debug::log( "\n~~~~ leet: 79 :end ~~~~\n" );
}
}//~
