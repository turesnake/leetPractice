/*
 * ====================== leet_394.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 394. 字符串解码
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_394 {//~



// stack  40%  100%
// 选择了 最浪费的策略，每次拼好的字符串，都再次塞回 stk 中
class S{

    std::deque<char> stk {};
    std::deque<char> que {};

    bool isNum( char c ){ return c>='0' && c<='9'; }
    //bool isLetter( char c ){ return c>='a' && c<='z'; }

    // 执行一次出栈
    // 完全不关心性能，直接把生成的 字符串，再写回 stk，最简单的实现 
    void do_pop(){
        // 收集所有 字母
        que.clear();
        while( !stk.empty() ){
            char c = stk.back();
            stk.pop_back();
            if(c=='['){
                break;
            }else{
                que.push_front(c);
            }
        }
        std::string word ( que.begin(), que.end() );
        //cout<<"word:"<<word<<endl;
        // 收集所有 数字
        que.clear();
        while( !stk.empty() ){
            char c = stk.back();

            if( isNum(c) ){
                stk.pop_back();
                que.push_front(c);
            }else{
                break;
            }
        }
        int num = std::stoi( std::string(que.begin(), que.end()) );
        //cout<<"num:"<<num<<endl;
        // out 
        for( int i=0; i<num; i++ ){
            stk.insert( stk.end(), word.begin(), word.end() );
        }
    }


public:
    std::string decodeString( std::string s) {

        if(s.empty()){ return ""; }
        size_t N = s.size();
        for( size_t i =0; i<N; i++ ){
            //cout<<"i:"<<i<<endl;
            char curC = s.at(i);
            if( curC==']' ){
                do_pop();
            }else{
                stk.push_back(curC);
            }
        }
        return std::string( stk.begin(), stk.end() );
    }
};







//=========================================================//
void main_(){

    cout<<S{}.decodeString( "2[abc]3[cd]ef" )<<endl;


    

    debug::log( "\n~~~~ leet: 394 :end ~~~~\n" );
}
}//~
