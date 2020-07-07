/*
 * ====================== leet_44.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 44. 通配符匹配
 */
#include "innLeet.h"


namespace leet_44 {//~


// 回溯法
// 通过了 1707/1809 个案例，但是超时了
// 说明解题思路是对的，但是要用 dp 来取代 回溯
class S{

struct Elem{
    int  qmarkNum   {0}; // ? num
    char c          {'a'};
    bool isWildcard {false};// *
};

struct SElem{ // 记录的下标是：从 is,ipp 开始检查
    int is {0};
    int ipp {0};
};

public:
    // s,P 都可空
    bool isMatch( std::string s, std::string p ){

        if( s.empty() ){ return p.empty() || p=="*";  }
        if( p.empty() ){ return false; }

        // 避免 p尾部是 *, 统一格式
        s.push_back('z');
        p.push_back('z');

        std::vector<Elem> pp {};

        for( size_t i=0; i<p.size(); ){
            Elem elem {};
            while( i<p.size() ){
                char curC = p[i++];
                if( curC=='*' ){
                    elem.isWildcard = true;
                }else if( curC=='?' ){
                    elem.qmarkNum++;
                }else{
                    elem.c = curC;
                    break;
                }
            }
            pp.push_back( std::move(elem) );
        }

        cout<<"pp:"<<endl;for( auto &e : pp ){ debug::log( "  {}, qmarkNum={}, isWildcard={}", e.c, e.qmarkNum, e.isWildcard );}

        int Ns = static_cast<int>(s.size());
        int Npp = static_cast<int>(pp.size());

        std::stack<SElem> stk {};
        stk.push( SElem{0,0} );

        while( !stk.empty() ){
            SElem se = stk.top();
            stk.pop();

            if( se.is==Ns && se.ipp==Npp ){ return true; }
            if( se.is>=Ns || se.ipp>=Npp ){ continue; }

            Elem &elem = pp[se.ipp];
            int tgtIs = se.is+elem.qmarkNum;

            if( !elem.isWildcard ){
                if( tgtIs<Ns && s[tgtIs]==elem.c ){
                    stk.push(SElem{ tgtIs+1, se.ipp+1 });
                }
            }else{// need *
                for( int i=tgtIs; i<Ns; i++ ){
                    if( s[i] == elem.c ){
                        stk.push(SElem{ i+1, se.ipp+1 });
                    }
                }
            }
        }
        return false;
        
    
        
    }
};





// dp    77%   58%
class S2{

struct Elem{
    int  qmarkNum   {0}; // ? num
    char c          {'a'};
    bool isWildcard {false};// *
};

struct SElem{ // 记录的下标是：从 is,ipp 开始检查
    int is {0};
    int ipp {0};
};

public:
    // s,P 都可空
    bool isMatch( std::string s, std::string p ){

        if( s.empty() ){ return p.empty() || p=="*";  }
        if( p.empty() ){ return false; }

        // 避免 p尾部是 *, 统一格式
        s.push_back('z');
        p.push_back('z');

        std::vector<Elem> pp {};
        for( size_t i=0; i<p.size(); ){
            Elem elem {};
            while( i<p.size() ){
                char curC = p[i++];
                if( curC=='*' ){
                    elem.isWildcard = true;
                }else if( curC=='?' ){
                    elem.qmarkNum++;
                }else{
                    elem.c = curC;
                    break;
                }
            }
            pp.push_back( std::move(elem) );
        }
        //cout<<"pp:"<<endl;for( auto &e : pp ){ debug::log( "  {}, qmarkNum={}, isWildcard={}", e.c, e.qmarkNum, e.isWildcard );}

        int Ns = static_cast<int>(s.size());
        int Npp = static_cast<int>(pp.size());

        std::vector<std::vector<char>> dp (Npp, std::vector<char>(Ns, 0));

        // dp[0][w]
        if( !pp[0].isWildcard ){
            int tgtIdx = pp[0].qmarkNum;
            if( s[tgtIdx] == pp[0].c ){
                dp[0][tgtIdx] = 1;
            }else{
                return false;
            }
        }else{// *
            bool isFind = false;
            for( int w=pp[0].qmarkNum; w<Ns; w++ ){
                if( s[w] == pp[0].c ){
                    dp[0][w] = 1;
                    isFind = true;
                }
            }
            if( !isFind ){ return false; }
        }

        // dp[h][w]
        for( int h=1; h<Npp; h++ ){

            bool isFind = false;

            if( !pp[h].isWildcard ){
                for( int w=pp[h].qmarkNum+h; w<Ns; w++ ){
                    if( dp[h-1][w-pp[h].qmarkNum-1]==1 && s[w] == pp[h].c ){
                        dp[h][w] = 1;
                        isFind = true;
                    }
                }
                
            }else{// *
                int fst = 0;
                for(; fst<Ns; fst++ ){
                    if( dp[h-1][fst]==1 ){ break; }
                }
                if( fst>=Ns ){ return false; }
              
                for( int w=fst+pp[h].qmarkNum+1; w<Ns; w++ ){
                    if( s[w]==pp[h].c ){
                        dp[h][w] = 1;
                        isFind = true;
                    }
                }
            }
            if( !isFind ){ return false; }
        }
        //cout<<"dp:"<<endl; for( auto &c : dp ){for( int i : c ){ cout<<i<<", ";}cout<<endl;}
        return dp[Npp-1][Ns-1]==1;
    
        
    }
};



//=========================================================//
void main_(){

    std::string s = "mississippi";
    std::string p = "m??*ss*?i*pi";

    auto ret = S2{}.isMatch( s,p );

    debug::log( "ret: {}", ret );

    


    debug::log( "\n~~~~ leet: 44 :end ~~~~\n" );
}
}//~
