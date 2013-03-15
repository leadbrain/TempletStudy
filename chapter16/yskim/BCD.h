//
//  BCD.h
//  chapter17
//
//  Created by Young sun Kim on 13. 3. 15..
//  Copyright (c) 2013년 Young sun Kim. All rights reserved.
//

#ifndef chapter17_BCD_h
#define chapter17_BCD_h



template <int NUM, int MUL>
class Square {
public:
    enum { result = NUM * Square<NUM, MUL - 1>::result };
};

template <int NUM>
class Square<NUM, 0> {
public:
    enum { result = 1 };
};

template <int INDEX>
class SubBCD {
public:
    static int convert(int* binary) {
        return *binary * Square<2,INDEX>::result + SubBCD<INDEX - 1>::convert(binary+1);
    }
};

template<>
class SubBCD<0> {
public:
    static int convert(int* binary) {
        return *binary;
    }
};

template <int INDEX>
class BCD {
public:
    static int convert(int* binary) {
        return SubBCD<3>::convert(binary) * Square<10, INDEX - 1>::result + BCD<INDEX-1>::convert(binary+4);
    }
};

template <>
class BCD<1> {
public:
    static int convert(int* binary) {
        return SubBCD<3>::convert(binary);
    }
};

int main(int argc, const char * argv[]) {
    
    int a[] = {0,0,1,1,0,0,1,0};
    int res = BCD<2>::convert(a);
    std::cout<<"res : "<<res<<std::endl;
    return 0;
}

#endif
