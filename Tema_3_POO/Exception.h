//
// Created by zamfirescu on 08.05.2020.
//

#ifndef TEMA_3_POO_EXCEPTION_H
#define TEMA_3_POO_EXCEPTION_H

#include <string>
#include <utility>
class Exception {
    std::string msg;
public:
    Exception(std::string  msg)
            : msg(std::move(msg))
    {}
    std::string getMessage() const {
        return msg;
    }
};


#endif //TEMA_3_POO_EXCEPTION_H
