#include "Snake.h"
#include "Point.h"

#include <algorithm>
#include <utility>
#include <iostream>

namespace allegory::snake {

    Snake::Snake(std::deque<Point> body) : body(std::move(body)) {}

    const std::deque<Point> &allegory::snake::Snake::getBody() const {
        return body;
    }

    bool Snake::walk(Direction direction, std::unordered_set<Point> &food, Geometry geometry) {
        const Point &head = this->head();

        if ((head.getY() == 0 && direction == Direction::NORTH) ||
            (head.getX() == 0 && direction == Direction::WEST) ||
            (head.getY() == geometry.height - 1 && direction == Direction::SOUTH) ||
            (head.getX() == geometry.width - 1 && direction == Direction::EAST)) {
            std::cout << "Snake reached edge of screen! GAME OVER." << std::endl;
            return false;
        }

        const Point &newHead = head.computeNeighbor(direction);

        if (std::find(body.begin(), body.end(), newHead) != body.end()) {
            std::cout << "Snake reached herself! GAME OVER." << std::endl;
            return false;
        }

        if (food.find(newHead) == food.end()) {
            body.pop_back();
        } else {
            food.erase(newHead);
        }
        body.push_front(newHead);

        return true;
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
