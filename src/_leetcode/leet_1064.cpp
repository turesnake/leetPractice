/*
 * ====================== leet_1064.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1064. 不动点
 */
#include "innLeet.h"


namespace leet_1064 {//~



// 遍历法 17.22%  33.33%
int fixedPoint( std::vector<int>& A ){

    int N = static_cast<int>(A.size());
    for( int i=0; i<N; i++ ){
        int v = A.at(i);
        if( v==i ){
            return i;
        }else if( v>i ){
            return -1;
        }
    }
    return -1;
}


// 一种高分思路：二分查找  演示版
int fixedPoint_2( std::vector<int>& A ){

    int N = static_cast<int>(A.size());
    int l = 0;
    int r = N-1;
    int mid = l+N/2;//中间偏右
    bool isFind {false};
    int out {};
    cout << "  begin: l="<<l <<" r="<<r<<" mid="<< mid << " N=" << N << endl;
    while( l<=r ){

        int v = A.at(mid);
        if( v==mid ){ 
            cout << "break "<<mid << endl;
            out = mid;
            isFind = true;
            break; 
        }else if( v>mid ){//寻找小区
            r = mid-1;
            mid = l+(r-l+1)/2;// 当 l，r相同，mid指向 l 自己
            cout << "  find-Sml: l="<<l <<" r="<<r<<" mid="<< mid << " N=" << (r-l+1) << endl;
        }else{// 寻找大区
            l = mid+1;
            mid = l+(r-l+1)/2;
            cout << "  find-Big: l="<<l <<" r="<<r<<" mid="<< mid << " N=" << (r-l+1) << endl;
        }
    }
    if( !isFind ){ 
        cout << "return -1" << endl;
        return -1; 
    }
    // 当前找到的 out 可能不是最左侧的那个，还需要做一次检测
    for( ; out>=0; out-- ){
        if( A.at(out)<out ){
            cout << "return out+1" << endl;
            return out+1;
        }
    }
    cout << "return 0" << endl;
    return 0;
}


// 一种高分思路：二分查找  提交版 42.23% 33.33%
int fixedPoint_3( std::vector<int>& A ){

    int N = static_cast<int>(A.size());
    int l = 0;
    int r = N-1;
    bool isFind {false};
    int out {};
    while( l<=r ){

        int mid = l+(r-l+1)/2;// 中间偏右 当 l，r相同，mid指向 l 自己

        int v = A.at(mid);
        if( v==mid ){ 
            out = mid;
            isFind = true;
            break; 
        }else if( v>mid ){//寻找小区
            r = mid-1;
        }else{// 寻找大区
            l = mid+1;
        }
    }
    if( !isFind ){ return -1; }
    // 当前找到的 out 可能不是最左侧的那个，还需要做一次检测
    for( ; out>=0; out-- ){
        if( A.at(out)<out ){ return out+1; }
    }
    return 0;
}



// 二分查找  改良版
// 边界太脏了
// 暂未好好测试...
int fixedPoint_4( std::vector<int>& A ){
    int N = static_cast<int>(A.size());
    int l = 0;
    int r = N-1;
    while( l < r ){
        //int mid = l + (r-l+1)/2 + 1;// 中间偏左
        int mid = (l+r)/2;
        if( A.at(mid) < mid ){ // 寻找大区
            l = mid+1;
        }else{//寻找小区
            r = mid;
        }
    }
    return (A.at(l)==l) ? l : -1;
}

    



//=========================================================//
void main_(){

    //std::vector<int> v { 0,1,3,7,8,9 };
    std::vector<int> v { -5,1,2,7,8,9,11,12 };

    cout << fixedPoint(v) << endl;
    cout << fixedPoint_3(v) << endl;
    cout << fixedPoint_4(v) << endl;
    



    debug::log( "\n~~~~ leet: 1064 :end ~~~~\n" );
}
}//~
