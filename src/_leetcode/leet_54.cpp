/*
 * ====================== leet_54.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 54. 螺旋矩阵
 */
#include "innLeet.h"


namespace leet_54 {//~

//class Solution_54 {
//public:




std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {

    std::vector<int> out {};

    if( matrix.empty() ){ return out; }

    int weight = matrix.at(0).size();
    int high   = matrix.size();

    if( weight == 0 ){ return out; }

    out.reserve( weight * high );

    int Wlo = 0;
    int Whi = weight-1;
    int Hlo = 0;
    int Hhi = high-1;
    
    while( true ){
        for( int w=Wlo; w<=Whi; w++ ){
            out.push_back( matrix.at(Hlo).at(w) );
        }
        if( Hhi <= Hlo ){ break; }
        for( int h=Hlo+1; h<=Hhi; h++ ){
            out.push_back( matrix.at(h).at(Whi) );
        }
        if( Whi <= Wlo ){ break; }
        for( int w=Whi-1; w>=Wlo; w-- ){
            out.push_back( matrix.at(Hhi).at(w) );
        }
        for( int h=Hhi-1; h>=Hlo+1; h-- ){
            out.push_back( matrix.at(h).at(Wlo) );
        }
        
        if( (Whi-Wlo) >= 2 ){
            Wlo++;
            Whi--;
        }else{
            break;
        }
        if( (Hhi-Hlo) >= 2 ){
            Hlo++;
            Hhi--;
        }else{
            break;
        }
    }
    return out;
}


//};




//=========================================================//
void main_(){

    /*
    std::vector<std::vector<int>> v {
        { 1,2,3 },
        { 5,6,7 },
        { 9,10,11 },
        { 13,14,15 }
    };
    */

    std::vector<std::vector<int>> v {
        {},
        {},
        {}
    };

    auto ret = spiralOrder( v );

    for( const auto &i : ret ){
        cout << i << ", ";
    }
    cout << endl;


    debug::log( "\n~~~~ leet: 54 :end ~~~~\n" );
}
}//~
