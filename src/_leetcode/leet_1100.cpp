/*
 * ====================== leet_1100.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1100. 长度为 K 的无重复字符子串
 */
#include "innLeet.h"


namespace leet_1100 {//~


// 滑动窗口来实现
// 用 vector26 来维护 区间内 字符个数 



//   95%  100%
class S{
public:
    // 1 <= S.len <= 10^4   
    // [i] 小写英文字母
    // 1 <= K <= 10^4
    int numKLenSubstrNoRepeats( std::string S, int K ){

        
        int Ns = static_cast<int>(S.size());
        if( Ns<K ){ return 0; }

        std::vector<int> chars (26,0);
        int charTypes = 0;// 窗口内，字母种类个数
        int outNum = 0;
    
        int l = 0;
        for( int r=0; r<Ns; r++ ){
            char cr = S.at(r);

            if( chars.at(cr-'a')==0 ){ charTypes++; } // new
            chars.at(cr-'a')++;

            // 若 存在重复字符
            // 不停删除，直到删除所有 重复字符
            while( l<r && (r-l+1) > charTypes ){
                char cl = S.at(l++);
                if( chars.at(cl-'a')==1 ){ charTypes--; }
                chars.at(cl-'a')--;
            }            

            if( charTypes==K ){ 
                outNum++; 
                // 再主动前进 l，
                char cl = S.at(l++);
                if( chars.at(cl-'a')==1 ){ charTypes--; }
                chars.at(cl-'a')--;
            }
        }
        return outNum;

    }
};



//=========================================================//
void main_(){

    

    
    debug::log( "\n~~~~ leet: 1100 :end ~~~~\n" );
}
}//~
