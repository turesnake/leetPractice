/*
 * ====================== leet_m17_17.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.17. 多次搜索
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_17 {//~


// kmp


//  84%  100%
class S{

    std::vector<std::vector<int>> outs {};
    int Nb {};
    int N {};


    void kmp( const std::string &b, const std::string &s, int idx ){

        int Ns = static_cast<int>(s.size());
        //== build next ==/
        std::vector<int> next (Ns, 0);// next[0]=0
        int now = 0;
        int i=1;
        while( i<Ns ){
            if( s[now]==s[i] ){
                next[i] = now+1;
                now++;
                i++;
            }else{
                if( now==0 ){
                    next[i] = 0;
                    i++;
                }else{
                    now = next[now-1];
                }
            }
        }
        //== check ==//
        i = 0;
        int j = 0;
        while( j<Nb ){

            if( b[j]==s[i] ){
                j++;
                i++;
            }else{
                if( i==0 ){
                    j++;
                }else{
                    i = next[i-1];
                }
            }
            if( i==Ns ){// 找到一个匹配项
                outs[idx].push_back( j-Ns );// 登记首字符下标
                i = next[i-1];
            }
        }
    }




public:
    // 0 <= len(big) <= 1000
    // 0 <= len(smalls[i]) <= 1000
    // smalls的总字符数不会超过 100000
    // 你可以认为smalls中没有重复字符串。
    // 所有出现的字符均为英文小写字母。
    std::vector<std::vector<int>> multiSearch( std::string big, std::vector<std::string>& smalls) {

        Nb = static_cast<int>(big.size());
        N = static_cast<int>(smalls.size());
        outs.resize( N, std::vector<int>{} );
        for( int i=0; i<N; i++ ){
            if( !smalls[i].empty() ){
                kmp( big, smalls[i], i );
            }
        }
        return outs;



    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: m17_17 :end ~~~~\n" );
}
}//~
