/*
 * ====================== leet_test.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 复习用 测试台
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_test {//~



// 复习 马拉车
class M{
public:
    std::string manacher( std::string s ){

        int Ns = static_cast<int>(s.size());
        int Nv = Ns*2+1;

        std::string v ( Ns*2+1, '#' );
        for( int i=0; i<Ns; i++ ){
            v[i*2+1] = s[i];
        }
        
        std::vector<int> mv (Nv, 0);

        int center = 0;
        int maxR = 0;

        int maxLen = 1;
        int start = 0;

        for( int i=0; i<Nv; i++ ){
            if( i<maxR ){
                int mirror = center*2-i;
                mv[i] = std::min( maxR-i, mv[mirror] );
            }
            int l = i-mv[i]-1;
            int r = i+mv[i]+1;
            for(; l>=0 && r<Nv && v[l]==v[r]; mv[i]++,l--,r++ ){}
            // 更新数据
            if( i+mv[i]>maxR ){
                maxR = i+mv[i];
                center = i;
            }
            if( mv[i]>maxLen ){
                maxLen = mv[i];
                start = (i-mv[i])/2;
            }
        }
        return std::string( s, start, maxLen );

    }
};



// 复习
class KMP{
public:
    // 若 p 为空，返回 0
    int kmp( std::string s, std::string p ){

        if( p.empty() ){ return 0; }

        int Ns = static_cast<int>(s.size());
        int Np = static_cast<int>(p.size());

        std::vector<int> next (Np, 0);
        // next[0]=0;

        //=== next ===//
        int now = 0;
        int i = 1;
        while( i<Np ){
            if( p[now]==p[i] ){
                next[i] = now+1;
                now++;
                i++;
            }else{
                if( now==0 ){
                    next[i]=0;
                    i++;
                }else{
                    now = next[now-1];// 核心
                }
            }
        }
        cout<<"next: ";for( int i : next ){ cout<<i<<", "; }cout<<endl;

        //=== chech ===//
        std::vector<int> tgtIdxs {};// 所有匹配的 下标
        int j=0;
        i = 0;  
        while( j<Ns-Np ){
            if( s[j]==p[i] ){
                j++;
                i++;
            }else{
                if( i==0 ){// i 不能前移了，改测下一个j
                    j++;
                }else{
                    i = next[i-1];
                }
            }

            if( i==Np ){// 一次比配成功

                tgtIdxs.push_back( j-Np );

                // j 已经指向 下一位了
                i = next[i-1];
            }

        }
        return tgtIdxs.empty() ? -1 : tgtIdxs[0];
    }
};



//=========================================================//
void main_(){

    std::string s = "aba";
    std::string p = "aaaapaaa";

    auto ret = KMP{}.kmp(s,p);
    cout<<"ret:"<<ret<<endl;
    


    debug::log( "\n~~~~ leet: test :end ~~~~\n" );
}
}//~
