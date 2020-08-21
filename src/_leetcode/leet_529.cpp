/*
 * ====================== leet_529.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 529. 扫雷游戏
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_529 {//~



//   57%,  55%
class S{

struct Elem{
    int h {};
    int w {};
};

    const std::vector<Elem> nearOffs {
        Elem{ -1,-1 },
        Elem{ -1, 0 },
        Elem{ -1, 1 },
        //--
        Elem{  0,-1 },
        //Elem{  0, 0 },
        Elem{  0, 1 },
        //--
        Elem{  1,-1 },
        Elem{  1, 0 },
        Elem{  1, 1 }
    };

public:
    // 输入矩阵的宽和高的范围为 [1,50]。
    // 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
    // 输入面板不会是游戏结束的状态（即有地雷已被挖出）。
    // 简单起见，未提及的规则在这个问题中可被忽略。例如，
    // 当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
    std::vector<std::vector<char>> updateBoard(
            std::vector<std::vector<char>>& board, 
            std::vector<int>& click ){

        int H = static_cast<int>(board.size());
        int W = static_cast<int>(board[0].size());

        if( board[click[0]][click[1]]=='M' ){// 直接挖到地雷
            board[click[0]][click[1]] = 'X';
            return board;
        }

        std::deque<Elem> que { Elem{ click[0], click[1] } };
        while( !que.empty() ){
            Elem e = que.front();
            que.pop_front();
            if( board[e.h][e.w]!='E' ){ continue; }
            //---//
            int count = 0;
            for( auto [ofh, ofw] : nearOffs ){
                int nh = e.h + ofh;
                int nw = e.w + ofw;
                if( nw<0 || nw>=W || nh<0 || nh>=H ){ continue; }
                if( board[nh][nw]=='M' ){ 
                    count++; 
                }
            }

            if( count!=0 ){
                board[e.h][e.w] = '0' + count;
            }else{
                board[e.h][e.w] = 'B';
                for( auto [ofh, ofw] : nearOffs ){
                    int nh = e.h + ofh;
                    int nw = e.w + ofw;
                    if( nw<0 || nw>=W || nh<0 || nh>=H ){ continue; }
                    if( board[nh][nw]=='E' ){
                        que.push_back( Elem{nh,nw} );
                    }
                }
            }
        }
        return board;

    }
};




//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 529 :end ~~~~\n" );
}
}//~
