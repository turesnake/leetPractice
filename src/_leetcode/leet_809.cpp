/*
 * ====================== leet_809.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 809. 情感丰富的文字
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_809 {//~


// 烂题



//   92%   100%
class S{

struct Elem{
    Elem( char c_ ):c(c_),num(1){}
    char c;
    int num;
};

    void prepare( std::vector<Elem> &v, const std::string &s ){

        v.clear();
        v.emplace_back( s[0] );
        int N = static_cast<int>(s.size());
        int lstC = s[0];
        for( int i=1; i<N; i++ ){
            if( lstC == s[i] ){
                v.back().num++;
            }else{
                lstC = s[i];
                v.emplace_back( s[i] );
            }
        }
    }


public:
    // 0 <= len(S) <= 100
    // 0 <= len(words) <= 100
    // 0 <= len(words[i]) <= 100
    // S 和所有在 words 中的单词都只由小写字母组成
    int expressiveWords( std::string S, std::vector<std::string>& words ){

        if( words.empty() ){ return 0; }

        int sum = 0;
        if( S.empty() ){
            for( const auto &word : words ){
                if( word.empty() ){ sum++; }
            }
            return sum;
        }

        std::vector<Elem> elems {};
        prepare( elems, S );
        //---//
        int Ne = static_cast<int>(elems.size());

        std::vector<Elem> bv {};
        for( const auto &word : words ){
            if( word.empty() ){ continue; }
            prepare( bv, word );

            if( elems.size() != bv.size() ){ continue; }

            bool isLegal = true;
            for( int i=0; i<Ne; i++ ){
                if( elems[i].c != bv[i].c ){
                    isLegal = false;
                    break;
                }
                if( (elems[i].num<3 && elems[i].num==bv[i].num) ||
                    (elems[i].num>=3 && elems[i].num>=bv[i].num) 
                ){
                    continue;
                }else{
                    isLegal = false;
                    break;
                }
            }
            if( isLegal ){ sum++; }
        }
        return sum;



    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 809 :end ~~~~\n" );
}
}//~
