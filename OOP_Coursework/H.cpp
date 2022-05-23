//#include "H.h"
//#include <iostream>
//#include <string>
//#include <exception>
//#include <stdexcept>
//
//State& H::getInstance()
//{
//    static H self;
//    return self;
//}
//
//void H::proceed(std::string::const_iterator& it, Interpreter* interp)
//{
//    std::string pattern = "http://";
//    for (int i = 0; i < 7; i++) {
//        if (*it == pattern[i]) {
//            //std::cout << *it;
//            if (interp->isLast())
//            {
//                std::cout << *it;
//            }
//            if (i != 6) it++;
//            continue;
//        }
//        //else {
//        //    throw StateException(std::string("Invalid symbol: ") + *it);
//        //}
//    }
//    //interp->setState(D::getInstance());
//}