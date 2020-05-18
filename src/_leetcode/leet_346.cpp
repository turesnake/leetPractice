/*
 * ====================== leet_346.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 346. 数据流中的移动平均值
 */
#include "innLeet.h"


namespace leet_346 {//~



class MovingAverage{

    std::deque<int> que {};
    int sum {};
    int len {};
    double dlen {};

public:

    MovingAverage(int size) {
        len = size;
        dlen = static_cast<double>(len);
    }
    
    double next(int val) {
        que.push_back( val );
        sum += val;
        if( static_cast<int>(que.size()) > len ){
            int v = que.front();
            que.pop_front();
            sum -= v;
        }
        double dsum = static_cast<double>(sum);
        return (static_cast<int>(que.size())==len) ?
                dsum / dlen :
                dsum / static_cast<double>(que.size());
    }
};





//=========================================================//
void main_(){

    MovingAverage obj ( 3 );

    cout << obj.next(1) << endl;
    cout << obj.next(10) << endl;
    cout << obj.next(3) << endl;
    cout << obj.next(5) << endl;

    


    debug::log( "\n~~~~ leet: 346 :end ~~~~\n" );
}
}//~
