/*
 * ====================== leet_m29.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题29. 顺时针打印矩阵
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m29 {//~


// 这题容易把边界和细节写错


// 42% 100%
class S{
public:
    std::vector<int> spiralOrder( std::vector<std::vector<int>>& matrix ){

        if( matrix.empty() || matrix.at(0).empty() ){ return {}; }
        int H = static_cast<int>(matrix.size());
        int W = static_cast<int>(matrix.at(0).size());
        std::vector<int> outs {};
        int wl = 0;
        int wr = W-1;
        int hu = 0;
        int hd = H-1;
        for( ; wl<=wr && hu<=hd; wl++,wr--,hu++,hd-- ){
            if( wl==wr ){
                for( int h=hu; h<=hd; h++ ){
                    outs.push_back( matrix.at(h).at(wl) );
                }
                break;
            }
            if( hu==hd ){
                for( int w=wl; w<=wr; w++ ){
                   outs.push_back( matrix.at(hu).at(w) ); 
                }
                break;
            }
            // up line
            for( int w=wl; w<wr; w++ ){
                outs.push_back( matrix.at(hu).at(w) );
            }
            // right line
            for( int h=hu; h<hd; h++ ){
                outs.push_back( matrix.at(h).at(wr) );
            }
            // down line (逆向)
            for( int w=wr; w>wl; w-- ){
                outs.push_back( matrix.at(hd).at(w) );
            }
            // left line (逆向)
            for( int h=hd; h>hu; h-- ){
                outs.push_back( matrix.at(h).at(wl) );
            }
        }
        return outs;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m29 :end ~~~~\n" );
}
}//~
