/*
 * ====================== leet_945.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 矩阵置零
 */
#include "innLeet.h"


namespace leet_945 {//~




int minIncrementForUnique( std::vector<int>& A ) {

    if( A.size()<2 ){ return 0; }
    std::sort( A.begin(), A.end() );
    
    auto slow = A.begin();
    auto fast = slow;

    int num {0};
    int sum {0};
    int curVal {0};
    int nextVal {0}; // next elem or INT_MAX

    for( ; slow!=A.end(); slow=fast ){
        // search next elem or end
        if( (slow+1)==A.end() ){ // slow is last elem
            fast = A.end();
            nextVal = INT_MAX;
        }else{
            fast = slow+1;
            while( true ){
                if( fast == A.end() ){
                    nextVal = INT_MAX;
                    break;
                }
                if( *fast == *slow ){
                    num++;
                    sum -= *fast; // 负数形式存储 base
                }else{
                    nextVal = *fast;
                    break;
                }
                fast++;
            }
        }
        // 处理元素
        curVal = *slow;
        for( ; (num>0) && (nextVal>curVal+1) ; num-- ){
            curVal++;
            sum += curVal; // 正数形式存储 targetVal       
        }
    }
    return sum;
}


int minIncrementForUnique_2( std::vector<int>& A ) {

    if( A.size()<2 ){ return 0; }
    std::sort( A.begin(), A.end() );
    
    int sum {0};
    for( auto it = A.begin()+1; it!=A.end(); it++ ){
        if( *it <= *(it-1) ){
            int newVal = *(it-1) + 1;
            sum += newVal - *it;
            *it = newVal;
        }
    }
    return sum;
}



// 返回找到的 位置
int findPos( int pos_, std::vector<int> &poses_ ){

    int curVal = poses_.at(pos_);
    if( curVal == -1 ){ // slot empty
        poses_.at(pos_) = pos_;
        return pos_;
    }else{
        int ret = findPos( curVal+1, poses_ );
        poses_.at(pos_) = ret;
        return ret;
    }
}



int minIncrementForUnique_3( std::vector<int>& A ) {

    if( A.size()<2 ){ return 0; }

    std::vector<int> poses ( 8000, -1 );
    int sum {0};

    for( const auto i : A ){
        int ret = findPos( i, poses );
        sum += ret - i;
    }
    return sum;
}








//=========================================================//
void main_(){

    std::vector<int> v {
        2,2,2,1
    };

    auto ret = minIncrementForUnique_3( v );

    cout << "ret = " << ret << endl;



    debug::log( "\n~~~~ leet: 945 :end ~~~~\n" );
}
}//~
