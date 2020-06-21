/*
 * ====================== leet_38.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 38. 外观数列
 */
#include "innLeet.h"


namespace leet_38 {//~



//   47%   100%
class S{
public:
    // 1<= n <= 30
    std::string countAndSay( int n ){

        if(n==1){ return "1"; }

        std::string s1 { "1" }; // [1]

        for( int i=2; i<=n; i++ ){

            std::string s2 {};
            size_t N = s1.size();
            //int l = 0;
            char lstC = s1.at(0);
            int cNum = 1;

            for( size_t l=1; l<N; l++ ){
                if( s1[l]==lstC ){
                    cNum++;
                }else{
                    s2 += std::to_string(cNum);
                    s2.push_back( lstC );
                    //---//
                    lstC = s1[l];
                    cNum = 1;
                }
            }
            s2 += std::to_string(cNum);
            s2.push_back( lstC );
            //===//
            s1 = std::move( s2 );
        }
        return s1;
        
    }
};





//=========================================================//
void main_(){

    cout<<S{}.countAndSay( 7 )<<endl;



    
    debug::log( "\n~~~~ leet: 38 :end ~~~~\n" );
}
}//~
