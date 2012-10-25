//
//  Factorial.h
//  chapter4
//
//  Created by Young sun Kim on 12. 10. 26..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#ifndef chapter4_Factorial_h
#define chapter4_Factorial_h

template<int VAL>

class Factorial {
public:
    int GetFactorial() {
        int num = 1;
        for (int i = 2; i <= VAL; i++) {
            num *= i;
        }
        return num;
    }
};

#endif
