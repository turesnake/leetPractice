/*
 * ====================== leet_1252.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"


namespace leet_1252 {//~



//   56%   100%
class S{
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices ){

        std::vector<int> vn ( n, 0 );
        std::vector<int> vm ( m, 0 );

        for( auto &c : indices ){
            vn[c[0]]++;
            vm[c[1]]++;
        }

        int sum = 0;
        for( int h=0; h<n; h++ ){
            for( int w=0; w<m; w++ ){
                int e = vn[h] + vm[w];
                if( (e&1)==1 ){ sum++; }
            }
        }
        return sum;


    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1252 :end ~~~~\n" );
}
}//~
