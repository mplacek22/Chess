//
// Created by User on 10.03.2025.
//

#ifndef HANDLER_H
#define HANDLER_H

#include <memory>
#include <utility>

template<typename... Args>
class Handler {
protected:
    std::unique_ptr<Handler<Args...> > nextHandler;

public:
    Handler() = default;

    void setNext(std::unique_ptr<Handler<Args...> > next) {
        nextHandler = std::move(next);
    }

    virtual bool handle(Args... args) {
        if (nextHandler) {
            return nextHandler->handle(std::forward<Args>(args)...);
        }
        return true;
    }

    virtual ~Handler() = default;
};

#endif // HANDLER_H
