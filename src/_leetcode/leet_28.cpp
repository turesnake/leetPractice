/*
 * ====================== leet_28.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 28. 实现 strStr()
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_28 {//~

// kmp   78%   100%


// 在这个版本中，并没有设置 next 集体 后移的操作


class S{

    std::string *sp {nullptr};
    std::string *pp {nullptr};
    std::vector<int> next {};
    int Ns {};
    int Np {};

    void build_next(){

        next.resize( Np, 0 );
        int i=1;
        int now = 0;
        while( i<Np ){
            if( pp->at(i)==pp->at(now) ){
                now++;
                next[i]=now;
                i++;
            }else{
                if( now>0 ){
                    now = next[now-1];// 反复下探，直到找到合适的
                }else{
                    next[i] = now;
                    i++;
                }
            }
        }
        //next.insert( next.begin(), -1 );
        cout<<"next: "; for( int i:next ){ cout<<i<<", "; }cout<<endl;
    }

public:
    // 若 needle 为空，返回 0
    int strStr( std::string haystack, std::string needle ){

        if( needle.empty() ){ return 0; }

        sp = &haystack;
        pp = &needle;
        Ns = static_cast<int>(haystack.size());
        Np = static_cast<int>(needle.size());

        build_next();

        //=== search ===//
        int si = 0;
        int pi = 0;

        while( si < Ns ){
            if( sp->at(si)==pp->at(pi) ){//两字符相等，下一位
                si++;
                pi++;
            }else{
                if( pi==0 ){// pi到头了，改为步进 si
                    si++;
                }else{      // 两字符不相等，根据 next 移动 pi
                    pi = next[pi-1];
                }
            }
            if( pi == Np ){// 成功匹配到一个 p
                return si-Np; // find !!!
                //pi = next[pi-1]; // 继续寻找，本题不需要
            }
        }

        return -1; // 没找到
        
    }
};



//=========================================================//
void main_(){

    std::string s = "hellow";
    std::string p = "ll";

    auto ret = S{}.strStr( s,p );

    cout<<"ret:"<<ret<<endl;





    debug::log( "\n~~~~ leet: 28 :end ~~~~\n" );
}
}//~
