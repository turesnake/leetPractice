/*
 * ====================== leet_1111.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1111. 有效括号的嵌套深度
 */
#include "innLeet.h"


namespace leet_1111 {//~

// 先用数字表示 嵌套深度，比如 321123 11 2112
// 然后，将一半数字写0，一半写1


//   100%  100%
class S{
public:
    std::vector<int> maxDepthAfterSplit( std::string seq ){

        if( seq.empty() ){ return {}; }

        int N = static_cast<int>(seq.size());
        std::vector<int> out (N, 0);
        std::stack<std::pair<int,int>> stk {};// <val,idx>

        int maxDeep = 0;

        for( int i=0; i<N; i++ ){
            if( seq[i]=='(' ){
                stk.emplace( 0,i );
            }else{
                // 收集并算出 当前括号内的 最大deep
                int tDeep = 0;
                while( !stk.empty() && stk.top().second==-1 ){
                    tDeep = std::max( tDeep, stk.top().first );
                    stk.pop();
                }
                int curDeep = tDeep + 1;
                maxDeep = std::max( maxDeep, curDeep );
                    //assert( !stk.empty() );
                    //assert( stk.top().second != -1 );
                out[stk.top().second] = curDeep;
                out[i] = curDeep;
                stk.pop();
                stk.emplace( curDeep, -1 );
            }
        }

        int mid = (maxDeep+1)/2;// mid-left
        for( int &i : out ){
            i = i>mid ? 1 : 0;
        }
        return out;

    }
};



//=========================================================//
void main_(){

    std::string s = "(())()";

    auto ret = S{}.maxDepthAfterSplit( s );

    cout<<"ret: "<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;


    
    debug::log( "\n~~~~ leet: 1111 :end ~~~~\n" );
}
}//~
