/*
 * ===================== leet_1284.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1284. 转化为全零矩阵的最少反转次数
 */
#include "innLeet.h"


namespace leet_1284 {//~



// 按照提示的说法， 在整个翻转路径中，如果一个点被翻转2次，等于do nothing
// 所以，每个点，能被翻转 0/1 次
// 用暴力回溯法来解， 随机翻转一个点，然后翻转剩余的点，每次翻转后检测状态

// 时间：O(2^(n*m))
// 鉴于 n,m<=3
// 所以暴力法是可接受的 

class S{


struct Elem{
    int x {};
    int y {};
};



public:
    // 1 <= w,h <= 3
    // mat[i][j] 是 0 或 1
    int minFlips( std::vector<std::vector<int>>& mat) {

        int H = static_cast<int>(mat.size());
        int W = static_cast<int>(mat.at(0).size());

        std::deque<Elem> que {Elem{0,0}}; // bfs

        while( !que.empty() ){
        }


        // 未来再做...


        return 0;
    }
};



//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 1284 :end ~~~~\n" );
}
}//~
