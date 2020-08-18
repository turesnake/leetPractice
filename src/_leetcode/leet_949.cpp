/*
 * ====================== leet_949.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 949. 给定数字能组成的最大时间
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_949 {//~


// 笨办法
//   65%  84%
class S{

    std::vector<int> *ap {nullptr};
    std::vector<char> vis {};
    std::string ans {};


    void big(){
        for( int i=3; i>=0; i-- ){
            if( ap->at(i)>2 || vis[i]==1 ){ continue; }

            int l = ap->at(i);
            vis[i] = 1;// 登记
            ans.push_back( '0'+l );

            for( int j=3; j>=0; j-- ){
                if( vis[j]==1 ){ continue; }
                if( l==2 && ap->at(j)>3 ){ continue; }

                int r = ap->at(j);
                vis[j]=1;
                ans.push_back( '0'+r );
                ans.push_back( ':' );

                if( sml() ){ return; }// find

                vis[j]=0;
                ans.pop_back();
                ans.pop_back();
            }
            //-- release --//
            vis[i]=0;
            ans.pop_back();
        }
    }


    bool sml(){
        for( int i=3; i>=0; i-- ){
            if( vis[i]==1 || ap->at(i)>5 ){ continue; }
            ans.push_back( '0'+ap->at(i) );
            vis[i]=1;
            //--//
            int j=3;
            for(; j>=0 && vis[j]==1; j-- ){}
            ans.push_back( '0'+ap->at(j) );
            return true;
        }
        return false;
    }


public:
    // A.length == 4
    // 0 <= A[i] <= 9
    std::string largestTimeFromDigits( std::vector<int>& A ){

        std::sort( A.begin(), A.end() );
        ap = &A;
        vis.assign( 4,0 );

        big();
        return ans;
    }
};





//=========================================================//
void main_(){

    std::vector<int> a { 1,2,3,4 };

    auto ret = S{}.largestTimeFromDigits( a );
    cout<<"ret:"<<ret<<endl;




    

    debug::log( "\n~~~~ leet: 949 :end ~~~~\n" );
}
}//~
