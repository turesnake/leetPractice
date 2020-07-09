/*
 * ====================== leet_1450.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1450. 在既定时间做作业的学生人数
 */
#include "innLeet.h"


namespace leet_1450 {//~


//   47%   100%
class S{
public:
    // 1 <= startTime.length <= 100
    // 1 <= startTime[i] <= endTime[i] <= 1000
    // 1 <= queryTime <= 1000
    int busyStudent( std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {

        int N = static_cast<int>(startTime.size());
        int sum = 0;
        for( int i=0; i<N; i++ ){
            if( queryTime>=startTime[i] && queryTime<=endTime[i] ){ sum++; }
        }
        return sum;

    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1450 :end ~~~~\n" );
}
}//~
