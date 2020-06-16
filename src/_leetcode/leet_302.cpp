/*
 * ===================== leet_302.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 302. 包含全部黑色像素的最小矩形
 */
#include "innLeet.h"


namespace leet_302 {//~


// 中等难度的 困难题


// 朴素法：用 bfs 查找每个像素   36%  100%
// 统计两侧边界
class S{

struct Elem{
    int x {};
    int y {};
};

    const std::vector<Elem> nearOffs {
        Elem{-1,0}, Elem{1,0}, Elem{0,-1}, Elem{0,1}
    };

public:
    // image: 0:白，1:黑，未检查 2:黑，已经检查
    int minArea(std::vector<std::vector<char>>& image, int x, int y) {

        if( image.empty() || image.at(0).empty() ){ return 1; }

        std::swap(x,y);
        int H = static_cast<int>(image.size());
        int W = static_cast<int>(image.at(0).size());

        int minX = x;
        int maxX = x;
        int minY = y; 
        int maxY = y;

        std::deque<Elem> que { Elem{x,y} };
        image.at(y).at(x) = '2';
        while( !que.empty() ){
            auto elem = que.front();
            que.pop_front();
            if( elem.x < minX ){ minX = elem.x; }
            else if( elem.x > maxX ){ maxX = elem.x; }
            if( elem.y < minY ){ minY = elem.y; }
            else if( elem.y > maxY ){ maxY = elem.y; }
            for( const auto &o : nearOffs ){
                int tx = elem.x + o.x;
                int ty = elem.y + o.y;
                if( tx<0 || tx>=W || ty<0 || ty>=H){ continue; }
                if( image.at(ty).at(tx)=='1' ){
                    image.at(ty).at(tx) = '2';
                    que.push_back( Elem{tx,ty} );
                }
            }
        }
        return (maxX-minX+1) * (maxY-minY+1);


    }
};




//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 302 :end ~~~~\n" );
}
}//~
