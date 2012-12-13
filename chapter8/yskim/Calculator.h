//
//  Calculator.h
//  chapter8
//
//  Created by Young sun Kim on 12. 12. 14..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#ifndef chapter8_Calculator_h
#define chapter8_Calculator_h

template<int FIRST, int SECOND>
class BasicOperator {
public:
    enum {
        result = FIRST + SECOND
    };
};

template<int FIRST, int SECOND, template<int OP_FIRST, int OP_SECOND> class OPERATOR = BasicOperator>
class Calculator {
public:
    enum {
        result = OPERATOR<FIRST, SECOND>::result
    };
};

template<int FIRST, int SECOND>
class Sub {
public:
    enum {
        result = FIRST - SECOND
    };
};

template<int FIRST, int SECOND>
class Div {
public:
    enum {
        result = SECOND == 0 ? 1 : FIRST / SECOND
    };
};


template<int FIRST, int SECOND>
class Mul {
public:
    enum {
        result = FIRST * SECOND
    };
};


#endif
