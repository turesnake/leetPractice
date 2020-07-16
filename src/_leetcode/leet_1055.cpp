/*
 * ====================== leet_1055.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1055. 形成字符串的最短路径
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1055 {//~


// 这确实是个 贪心算法题
// 不太像 dp 题...


//   92%  100%
class S{
public:
    // 只有 小写字母
    // 1 <= len <= 1000
    int shortestWay( std::string source, std::string target ){

        std::vector<char> chars (26,0);
        for( char c : source ){
            chars[c-'a'] = 1;
        }

        int Ns = static_cast<int>(source.size());
        int out = 1;
        int i = 0;
        for( char c : target ){
            if( chars[c-'a']==0 ){ return -1; }
            bool isFind = false;
            for(; i<Ns; i++ ){
                if( source[i]==c ){
                    isFind = true;
                    i++;
                    break;
                }
            }
            if( !isFind ){
                out++;
                for( i=0; i<Ns; i++ ){
                    if( source[i]==c ){
                        i++;
                        break;
                    }
                }
            }
        }
        return out;

        
    }
};



//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: 1055 :end ~~~~\n" );
}
}//~
