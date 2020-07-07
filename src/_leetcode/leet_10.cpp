/*
 * ====================== leet_10.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 10. 正则表达式匹配
 */
#include "innLeet.h"


namespace leet_10 {//~


// 和 44 题有点类似，也存在差异：
// "h*"，中，* 表示 0或n个 ‘h’
// ".*" 则能表达 任何字符串，它意味着 0或多个 '.'
// 而 '.' 表示 任意字符

// 不存在 "a**" 这个写法，官方测试自己不能执行
// 不存在 "..**"
// 不存在 "*"，
// 也就是说，在本题中，'*' 的使用是很谨慎的

// 一个 '*' 前面一定跟一个 字母 or '.'






// 这题要比 44 题难 ......







class S{

struct Elem{
    char c {}; // 字母 or '.'
    bool isWildcard {false};// *
};


public:
    bool isMatch( std::string s, std::string p ){


        std::vector<Elem> pp {};
        for( size_t i=0; i<p.size(); ){
            Elem elem {};
            elem.c = p[i++];
            if( p[i]=='*' ){
                elem.isWildcard = true;
                i++;
            }
            pp.push_back(std::move(elem));
        }
        //cout<<"pp:\n";for( auto &e:pp ){ debug::log(" {},{}",e.c,e.isWildcard );}

        int Ns = static_cast<int>(s.size());
        int Npp = static_cast<int>(pp.size());

        std::vector<std::vector<char>> dp (Npp, std::vector<char>(Ns, 0));

        bool isLstMegaCard {false}; // 上一回合是否为 ".*"，需要特别处理

        // dp[0][w]
        int w=0;
        int h=0;
        if( !pp[h].isWildcard ){
            if( pp[h].c==s[0] || pp[h].c=='.' ){
                dp[h][0] = 1;
            }else{
                return false;
            }
            w++;
            h++;
        }else{// '*'
            // 找到第一个 匹配 的组
            while( h<Npp ){
                if( pp[h].c==s[0] || pp[h].c=='.' ){// 此组匹配
                    break;
                }else if( pp[h].isWildcard ){// 字符不符，但有'*',此组可以跳过
                    h++;
                    continue;
                }else{
                    return false;
                }
            }
            if( h>=Npp ){ return false; }
            // 现在，字符要么是 s[0], 要么是 '.'
            if( !pp[h].isWildcard ){
                dp[h][0] = 1;
                w++; // w==1
            }else{// '*'
                if( pp[h].c==s[0] ){
                    for( int i=0; i<Ns; i++ ){
                        if( s[i]==pp[h].c ){ dp[h][i] = 1; }
                    }
                }else{// '.'
                    for( int i=0; i<Ns; i++ ){ dp[h][i] =1; }
                    isLstMegaCard = true;
                }
                // w==0
            }
            h++;
        }


        // dp[h][w]
        for(; h<Npp; h++ ){
            
            // 上一回合为 '.*' 时，本回合要特殊处理 
            if( isLstMegaCard ){





            }







        }



        
        
        return true;
    }
};






//=========================================================//
void main_(){

    std::string s = "aaaa";
    std::string p = "a*.*";

    auto ret = S{}.isMatch( s,p );
    debug::log( "ret:{}",ret );
    


    debug::log( "\n~~~~ leet: 10 :end ~~~~\n" );
}
}//~
