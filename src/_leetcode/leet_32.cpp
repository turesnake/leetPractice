/*
 * ===================== leet_32.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 32. 最长有效括号
 */
#include "innLeet.h"


namespace leet_32 {//~


// 自创法：  19%   100%
// stk:
// -2: (
// -1: )
// >0: 已经计算好的区间字符数

// 其思路就是，在栈中及时 合并组装数据，
// 缺点就是 很容易写错

class S1{
public:
    int longestValidParentheses( std::string s ){

        if(s.empty()){ return 0; }
        std::stack<int> stk {};
        int outMax = 0;

        for( char c : s ){
            if( c=='(' ){
                stk.push(-2);
            }else{// ')'

                if( stk.empty() ){ continue; }//本字符是无效的

                // 取出 stk 第一个值
                int e = stk.top();
                if( e==-2 ){//'('
                    stk.pop();//pop '('
                    int val = 2; // 初步获得有效区间
                    while(  !stk.empty() && stk.top()>0 ){
                        val += stk.top();
                        stk.pop();
                    }
                    stk.push(val);

                }else if( e>0 ){// 数字
                    stk.pop();// pop 数字
                    int val = e;// 获得的数字
                    // 2次 搜索
                    if( stk.empty() ){
                        // 说明本回合自身的 ')'也是非法的
                        outMax = std::max( outMax, val );
                        continue;
                    }

                    int e2 = stk.top();
                    if( e2==-2 ){//'('
                        stk.pop();
                        val += 2;
                        while( !stk.empty() && stk.top()>0 ){
                            val += stk.top();
                            stk.pop();
                        }
                        stk.push(val);
                        continue;

                    }else{
                        assert(0);//检测用
                    }
                }else{
                    assert(0);//检测用
                }
            }
        }
        while( !stk.empty() ){
            int v = stk.top();
            stk.pop();
            if( v>0 ){ outMax = std::max( outMax, v ); }
        }
        return outMax;
    }
};






// 官方 dp 法    94%   100%
// 也是个 一维dp
// dp[i] 表示，以此位终结的 最长区间的长度

// 若 s[i]=='('; dp[i]=0; 因为不可能有区间是以 '(' 结尾的
// 若 s[i]==')'; 可以查看 s[i-1]
//   若 s[i-1]=='('; 说明能立即构成一个小括号，此时用2，累加 dp[i-2] 即可
//   若 s[i-1]==')'; 说明内含一个子区间...

// 就算是这个方法，也很容易写漏

class S2{
public:
    int longestValidParentheses( std::string s ){

        if(s.empty()){ return 0; }
        int N = static_cast<int>(s.size());
        std::vector<int> dp (N,0); // dp[0]=0;
        int outMax = 0;

        for( int i=1; i<N; i++ ){//[i-1],[i]
            if( s.at(i)=='(' ){
                dp.at(i) = 0;
            }else{
                if( s.at(i-1)=='(' ){//可以构成一个小 "()"
                    dp.at(i) = (i<2) ? 2 : 2+dp.at(i-2);
                    outMax = std::max( outMax, dp.at(i) );

                }else{//')' 说明嵌套了 子区间
                    if( dp.at(i-1)==0 ){
                        dp.at(i)=0;
                    }else{
                        int lIdx = i-1-dp.at(i-1); //被嵌套的子区间之前的一位
                        if( lIdx<0 || s.at(lIdx)==')'  ){
                            dp.at(i) = 0;
                            continue;
                        }
                        // 现在，确认 s.at(lIdx)=='('
                        dp.at(i) = (lIdx-1<0) ? 
                                (dp.at(i-1)+2) : 
                                (dp.at(i-1)+2+dp.at(lIdx-1));
                        outMax = std::max( outMax, dp.at(i) );
                    }
                }
            }
        }   
        //cout<<"dp:"<<endl; for( int i : dp ){ cout<<i<<", "; }cout<<endl;
        return outMax;

    }
};




//=========================================================//
void main_(){

    //std::string s { "))()((()(()()(()())()()(()()()))" };
    //std::string s { "))()((()(()()(()" };
    //std::string s { "))()((()(()()(()())" };
    //std::string s { "))()((()(()()(()())()()" };
    //std::string s { "))()((()(()()(()())()()(()" };
    //std::string s { "2((2(14 (()()()) )" };

    std::string s { ")())(())(()()())()(())(())(())))())((" };



    auto ret = S1{}.longestValidParentheses( s );
    cout<<"\nS1 ret:"<<ret<<endl;

    auto ret2 = S2{}.longestValidParentheses( s );
    cout<<"\nS2 ret:"<<ret2<<endl;


    debug::log( "\n~~~~ leet: 32 :end ~~~~\n" );
}
}//~
