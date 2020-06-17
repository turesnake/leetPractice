/*
 * ===================== leet_716.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 716. 最大栈
 */
#include "innLeet.h"


namespace leet_716 {//~



//  8%   100%
class MaxStack {

    std::vector<int> data {};
    std::map<int,std::set<int>> mmap {};

public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x){
        data.push_back(x);
        int idx = static_cast<int>(data.size())-1;
        auto [it,bl] = mmap.emplace( x, std::set<int>{} );
        it->second.insert(idx);
    }
    
    int pop(){
        int v = top();
        int idx = static_cast<int>(data.size())-1;
        mmap.at(v).erase(idx);
        if( mmap.at(v).empty() ){
            mmap.erase(v);
        }
        data.pop_back();
        return v;
    }

    
    int top(){
        while( !data.empty() && data.back()==INT_MIN ){ 
            data.pop_back(); //删除空洞
        }
        return data.back();
    }

    
    int peekMax(){
        return mmap.rbegin()->first;
    }
    

    int popMax(){

        auto fit = mmap.rbegin();
        int v = fit->first;
        int idx = *(fit->second.rbegin());
        //--
        fit->second.erase(idx);
        if( fit->second.empty() ){
            mmap.erase( v );
        }
        data.at(idx) = INT_MIN; // 表示不存在了
        return v;

    }
};





//=========================================================//
void main_(){

    MaxStack ms {};
    ms.push( 5 );
    ms.push( 1 );
    ms.push( 5 );
    ms.push( 6 );
    ms.push( 3 );
    ms.push( 4 );
    ms.push( 2 );

    cout<<"1 top:"<<ms.top()<<endl;
    cout<<"1 pop:"<<ms.pop()<<endl;

    cout<<"2 peekMax:"<<ms.peekMax()<<endl;
    cout<<"2 popMax:"<<ms.popMax()<<endl;

    cout<<"3 peekMax:"<<ms.peekMax()<<endl;
    cout<<"3 popMax:"<<ms.popMax()<<endl;

    cout<<"4 peekMax:"<<ms.peekMax()<<endl;
    cout<<"4 popMax:"<<ms.popMax()<<endl;

    cout<<"5 peekMax:"<<ms.peekMax()<<endl;
    cout<<"5 popMax:"<<ms.popMax()<<endl;

    cout<<"6 top:"<<ms.top()<<endl;
    cout<<"6 pop:"<<ms.pop()<<endl;

    cout<<"7 top:"<<ms.top()<<endl;
    cout<<"7 pop:"<<ms.pop()<<endl;




    debug::log( "\n~~~~ leet: 716 :end ~~~~\n" );
}
}//~
