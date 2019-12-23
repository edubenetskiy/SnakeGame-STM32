#include "Snake.h"
#include "Point.h"

#include <utility>

namespace allegory::snake {

    Snake::Snake(std::deque<Point> body) : body(std::move(body)) {}

    const std::deque<Point> &allegory::snake::Snake::getBody() const {
        return body;
    }

    void Snake::walk(Direction direction) {
        body.pop_back();
        const Point &head = this->head();
        const Point &newHead = head.computeNeighbor(direction);
        body.push_front(newHead);
    }

    size_t Snake::length() {
        return body.size();
    }

    Point Snake::head() {
        return body.front();
    }

    Point Snake::tail() {
        return body.back();
    }

    Snake::Snake() {
        std::deque<Point> newBody{};
        newBody.emplace_back(64, 30);
        newBody.emplace_back(64, 31);
        newBody.emplace_back(64, 32);
        newBody.emplace_back(64, 33);
        newBody.emplace_back(64, 34);
        this->body = newBody;
    }
}
