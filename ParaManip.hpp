#ifndef __PARAMANIP_HPP
#define __PARAMANIP_HPP

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;


template<class T>
class smanip{
        ostream& (*function)(ostream&,T);
        T arg;
    public:
        smanip(ostream& (*pf)(ostream&,T) , T arg ){
            function = pf;
            this->arg = arg;
        }
        ostream& call( ostream& stream ){
            return function( stream , arg);
        }
        // friend ostream& operator<<( ostream& , smanip<T>& );
};

template <class T>
ostream& operator<<( ostream& stream , smanip<T> manip ){
    manip.call( stream );

    return stream;
}

ostream& f_manip_tab( ostream& stream , int n ){
    for( int i = n ; n ; n-- )
        stream << '\t';
    return stream;
}

smanip<int> tab( int n ){
    return smanip<int>(f_manip_tab,n);
}

ostream& tab( ostream& stream ){
    stream << "\t";

    return stream;
}

ostream& endlT( ostream& stream ){
    stream << endl << "\t";

    return stream;
}


#endif  //__PARAMANIP_HPP