/*
 * ====================== leet_42.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 42. 接雨水
 */
#include "innLeet.h"


namespace leet_42 {//~



int trap( std::vector<int>& height) {

    if( height.size() < 3 ){ return 0; }
    // vals
    int sum {0};
    int totalH  {0};
    // ptrs
    int left = 0;
    int right =  static_cast<int>(height.size()-1);

    bool isLeft     {false};
    bool isRight    {false};

    while( left < right ){

        int leftH = height.at(left);
        int rightH = height.at(right);

        // curH, totalH
        int curH = std::min( leftH, rightH ); // min
        if( curH > totalH ){ totalH = curH; }

        // sum
        if( isLeft && (leftH<totalH) ){
            sum += totalH - leftH;
        }
        if( isRight && (rightH<totalH) ){
            sum += totalH - rightH;
        }

        if( leftH < rightH ){
            left++;
            isLeft = true;
            isRight = false;
        }else if( leftH > rightH ){
            right--;
            isLeft = false;
            isRight = true;
        }else{// equal

            if( right-left==2 ){
                left++;
                isLeft = true;
                isRight = false;
            }else{
                left++;
                right--;
                isLeft = true;
                isRight = true;
            }
        }

    
    }

    return sum;
}




//=========================================================//
void main_(){

    //std::vector<int> v { 0,1 };
    //std::vector<int> v { 2, 0, 2  };
    std::vector<int> v { 5, 2, 1, 2, 1, 5 };
    //std::vector<int> v {0,1,0,2,1,0,1,3,2,1,2,1};

    int ret = trap( v );

    cout << "ret = " << ret << endl;
    


    debug::log( "\n~~~~ leet: 42 :end ~~~~\n" );
}
}//~
