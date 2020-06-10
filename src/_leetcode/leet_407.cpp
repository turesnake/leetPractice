/*
 * ====================== leet_407.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 407. 接雨水 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_407 {//~


// 3D版的，非常变态

// 思路其实也与 2D版相同。
// 只不过，这次不再是两个判断点，而是一整圈
// 将外围一整圈点，都排进一个 小顶堆中，然后取出最小的
// 判断它的内侧相邻点，选择注水or不注
// 然后将自己删除，将自己的那个 新的相邻点，记做最新的围栏点
// 压入 小顶堆中



//   26%   100%
class S{

struct Elem{
    struct Greater{
        bool operator()( Elem a, Elem b ){
            return a.height > b.height;            
        }
    };
    int height {};
    int h {};// idx
    int w {};// idx
}; 

    const std::vector<std::pair<int,int>> nearOff {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };


public:
    // 1 <= m, n <= 110
    // 0 <= [i][j] <= 20000
    int trapRainWater( std::vector<std::vector<int>>& heightMap ){

        int H = static_cast<int>(heightMap.size());
        int W = static_cast<int>(heightMap.at(0).size());
        if( H<3 || W<3 ){ return 0; }

        // 1: 已处理  0:未处理
        std::vector<std::vector<char>> states (H, std::vector<char>(W,0));
        std::priority_queue<Elem,std::vector<Elem>,Elem::Greater> minHeap {};

        // 把4边元素都压入 minheap
        // - top/down -
        for( int w=0; w<W; w++ ){
            minHeap.push( Elem{heightMap.at(0).at(w), 0, w} );
            states.at(0).at(w) = 1;
            minHeap.push( Elem{heightMap.at(H-1).at(w), H-1, w} );
            states.at(H-1).at(w) = 1;
        }
        // - left/right -
        for( int h=1; h<H-1; h++ ){
            minHeap.push( Elem{heightMap.at(h).at(0), h, 0} );
            states.at(h).at(0) = 1;
            minHeap.push( Elem{heightMap.at(h).at(W-1), h, W-1} );
            states.at(h).at(W-1) = 1;
        }

        int sum = 0; //

        while( !minHeap.empty() ){
            auto elem = minHeap.top();
            minHeap.pop();
            for( const auto [offW,offH] : nearOff ){
                int newW = elem.w + offW;
                int newH = elem.h + offH;
                if( newW<0 || newW>=W || newH<0 || newH>=H ){ continue; }
                if( states.at(newH).at(newW)==1 ){ continue; }
                //--//
                states.at(newH).at(newW) = 1;
                int newHeight = heightMap.at(newH).at(newW);
                if( newHeight < elem.height ){
                    sum += elem.height - newHeight;
                    minHeap.push(Elem{ elem.height, newH, newW });
                }else{
                    minHeap.push(Elem{ newHeight, newH, newW });
                }
            }
        }
        return sum;
    }
};




//=========================================================//
void main_(){

    /*
    std::vector<std::vector<int>> v {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    */

    std::vector<std::vector<int>> v {
        {4,4,4,4,4,4},
        {4,0,0,0,0,4},
        {4,4,4,4,1,4}
    };

    cout<<"ret: "<<S{}.trapRainWater(v)<<endl;



    
    debug::log( "\n~~~~ leet: 407 :end ~~~~\n" );
}
}//~
