/*
 * ====================== leet_657.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 657. 机器人能否返回原点
 */
#include "innLeet.h"


namespace leet_657 {//~



//  82%  100%
class S{
public:
    bool judgeCircle( std::string moves ){

        if( moves.empty() ){ return true; }
        int h = 0;
        int w = 0;
        for( char c : moves ){
            switch (c){
                case 'L': w--; break;
                case 'R': w++; break;
                case 'U': h++; break;
                case 'D': h--; break;
                default: assert(0); break;
            }
        }
        return (w==0 && h==0);



    }
};








//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 657 :end ~~~~\n" );
}
}//~
