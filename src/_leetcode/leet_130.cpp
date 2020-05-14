/*
 * ====================== leet_130.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 130. 被围绕的区域
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_130 {//~



//------------ 广度优先 -----------//
class S_BFS{

    // elem:0
    // elem:1 "边缘O区域"
    std::vector<std::vector<int>> datas {};
    std::deque<std::pair<int,int>> que {};// <i,j>
    int h {};
    int w {};

public:

    void handle_singleDir( int i, int j ){
        if( datas.at(j).at(i)!=1 ){
            datas.at(j).at(i) = 1; // 做标记
            que.push_back({ i,j });
        }
    }

    // 把所有 沾到边缘的O元素，都做好标记
    void bfs( std::vector<std::vector<char>>& board_, int i_, int j_ ){

        if( datas.at(j_).at(i_) == 1 ){ return; }// 已经标注过了

        que.clear();
        que.push_back({ i_, j_ });
        datas.at(j_).at(i_) = 1;
        while( !que.empty() ){
            auto [tmpI, tmpJ] = que.front();
            que.pop_front();

            int ti = tmpI;
            int tj = tmpJ-1;
            bool isTopO = (tmpJ==0) ? false : board_.at(tj).at(ti)=='O';
            if( isTopO ){ handle_singleDir( ti,tj ); }

            ti = tmpI;
            tj = tmpJ+1;
            bool isBottomO = (tmpJ==h-1) ? false : board_.at(tj).at(ti)=='O';
            if( isBottomO ){ handle_singleDir( ti,tj ); }

            ti = tmpI-1;
            tj = tmpJ;
            bool isLeftO = (tmpI==0) ? false : board_.at(tj).at(ti)=='O';
            if( isLeftO ){ handle_singleDir( ti,tj ); }

            ti = tmpI+1;
            tj = tmpJ;
            bool isRightO = (tmpI==w-1) ? false : board_.at(tj).at(ti)=='O';
            if( isRightO ){ handle_singleDir( ti,tj ); }
        }
    }
    

    
    void solve( std::vector<std::vector<char>>& board ){

        if( board.empty() || board.at(0).empty() ){ return; } // do nothing
        this->h = static_cast<int>(board.size());
        this->w = static_cast<int>(board.at(0).size());
        // 初始化容器
        this->datas.resize( h );
        for( auto &c : datas ){
            c.resize( w, 0 );
        }
        // 遍历周围4条边
        // 把所有 沾到边缘的O元素，都做好标记
        for( int i=0; i<w; i++ ){
            if( board.at(0).at(i) == 'O' ){ // top
                bfs( board, i, 0 );
            }
            if( board.at(h-1).at(i) == 'O' ){ // down
                bfs( board, i, h-1 );
            }
        }
        for( int j=1; j<h-1; j++ ){
            if( board.at(j).at(0) == 'O' ){ // left
                bfs( board, 0, j );
            }
            if( board.at(j).at(w-1) == 'O' ){ // right
                bfs( board, w-1, j );
            }
        }
        for( int j=0; j<h; j++ ){
            for( int i=0; i<w; i++ ){
                if( datas.at(j).at(i)!=1 && board.at(j).at(i)=='O' ){
                    board.at(j).at(i) = 'X';
                }
            }
        }
    }


};



//=========================================================//
void main_(){

    

    std::vector<std::vector<char>> v1 {
        { 'X','O','X','X' },
        { 'X','X','O','O' },
        { 'O','X','O','X' },
        { 'X','O','X','X' }
    };

    S_BFS{}.solve( v1 );

    for( const auto &cc : v1 ){
        for( const char c : cc ){
            cout << c << ", ";
        }
        cout << endl;
    }


    //cout << "ret = " << ret << endl;




    
    


    debug::log( "\n~~~~ leet: 130 :end ~~~~\n" );
}
}//~

