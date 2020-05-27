/*
 * ====================== leet_43.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 43. 字符串相乘
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_43 {//~


// 这道题的优化 在于 计算过程本身，而不在代码上
// 未实现...


// 原始版 内部用 int 来存储 17.36%， 22.22%
std::string multiply_1( std::string num1, std::string num2 ){

    if( num1=="0" || num2=="0" ){ return "0"; }
    int N1 = static_cast<int>(num1.size());
    int N2 = static_cast<int>(num2.size());
    std::deque<int> que {};
    int carry = 0;
    std::vector<int> sum {};

    for( int b=N2-1; b>=0; b-- ){//逐个位地乘

        //--- 计算 单个位的 乘积 ---//
        que.clear();
        carry = 0;
        for( int a=N1-1; a>=0; a-- ){
            int av = static_cast<int>(num1.at(a)-'0');
            int bv = static_cast<int>(num2.at(b)-'0');
            int tmp = av*bv + carry;
            carry = tmp/10;
            que.push_front(tmp%10);
        }
        if( carry>0 ){ que.push_front(carry); }
        for( int i=0; i<N2-1-b; i++ ){// 补上尾后0
            que.push_back(0);
        }
        std::vector pd ( que.begin(), que.end() );// 单个位的乘积

        //--- 将 乘积 累加进总值 ---//
        que.clear();
        carry = 0;
        int y = static_cast<int>(sum.size())-1; // sum
        int x = static_cast<int>(pd.size())-1;  // pd
        for( ; x>=0||y>=0; x--,y-- ){
            int xv = (x>=0) ? pd.at(x) : 0;
            int yv = (y>=0) ? sum.at(y) : 0;
            int tmp = xv + yv + carry;
            carry = tmp/10;
            que.push_front(tmp%10);
        }
        if( carry>0 ){ que.push_front(1); }
        sum.assign( que.begin(), que.end() );
    }

    std::string out {};
    for( int i : sum ){ out += static_cast<char>('0'+i); }
    return out;
}


// 内部使用 char 存储, 区分长短值 19.69% 40.74%
std::string multiply( std::string num1, std::string num2 ){

    if( num1=="0" || num2=="0" ){ return "0"; }
    int N1 = static_cast<int>(num1.size());
    int N2 = static_cast<int>(num2.size());
    std::string *npBig {};
    std::string *npSml {};
    int NBig {};
    int NSml {};
    if( N1>=N2 ){
        npBig = &num1;
        npSml = &num2;
        NBig = N1;
        NSml = N2;
    }else{
        npBig = &num2;
        npSml = &num1;
        NBig = N2;
        NSml = N1;
    }

    std::deque<char> que {};
    int carry = 0;
    std::string sum {};

    for( int b=NSml-1; b>=0; b-- ){//逐个位地乘

        //--- 计算 单个位的 乘积 ---//
        que.clear();
        carry = 0;
        for( int a=NBig-1; a>=0; a-- ){
            int av = static_cast<int>(npBig->at(a)-'0');
            int bv = static_cast<int>(npSml->at(b)-'0');
            int tmp = av*bv + carry;
            carry = tmp/10;
            que.push_front( static_cast<char>('0'+tmp%10) );
        }
        if( carry>0 ){ que.push_front( static_cast<char>('0'+carry) ); } 
        for( int i=0; i<NSml-1-b; i++ ){// 补上尾后0
            que.push_back('0');
        }
        std::string pd ( que.begin(), que.end() );// 单个位的乘积

        //--- 将 乘积 累加进总值 ---//
        que.clear();
        carry = 0;
        int y = static_cast<int>(sum.size())-1; // sum
        int x = static_cast<int>(pd.size())-1;  // pd
        for( ; x>=0||y>=0; x--,y-- ){
            int xv = (x>=0) ? static_cast<int>(pd.at(x)-'0') : 0;
            int yv = (y>=0) ? static_cast<int>(sum.at(y)-'0') : 0;
            int tmp = xv + yv + carry;
            carry = tmp/10;
            que.push_front( static_cast<char>('0'+tmp%10) );
        }
        if( carry>0 ){ que.push_front('1'); }
        sum.assign( que.begin(), que.end() );
    }
    return sum;
}





//=========================================================//
void main_(){

    cout << "ret: " << multiply( "123", "45" ) << " == " << 123*45 << endl;
    cout << "ret: " << multiply( "0", "45" ) << " == " << 0*45 << endl;
    cout << "ret: " << multiply( "77", "0" ) << " == " << 77*0 << endl;
    cout << "ret: " << multiply( "100", "104" ) << " == " << 100*104 << endl;
    cout << "ret: " << multiply( "1", "12345" ) << " == " << 1*12345 << endl;
    cout << "ret: " << multiply( "12345", "1" ) << " == " << 12345*1 << endl;
    cout << "ret: " << multiply( "123", "456" ) << " == " << 123*456 << endl;

    

    debug::log( "\n~~~~ leet: 43 :end ~~~~\n" );
}
}//~
