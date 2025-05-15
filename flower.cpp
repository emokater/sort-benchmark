/// \file  flower.cpp
/// \brief Implementation of the Flower class methods and operator overloading.

#include "flower.h"

/// \brief Primary constructor of the Flower class.
Flower::Flower(string name, string color, string smell, vector<string> regions) {
    name_ = name;
    color_ = color;
    smell_ = smell;
    regions_ = regions;
}

bool Flower::EqFlowers(const Flower& other) const {
    if (name_ == other.name_ && color_ == other.color_ && smell_ == other.smell_) {
        return true;
    }
    return false;
}

/// \brief "Greater than" operator based on key fields.
bool Flower::operator>(const Flower& other) const {
    if (name_ != other.name_) {
        return name_ > other.name_;
    } else if (color_ != other.color_) {
        return color_ > other.color_;
    } else if (smell_ != other.smell_) {
        return smell_ > other.smell_;
    } else {
        return false;
    }
}

/// \brief "Less than" operator based on key fields.
bool Flower::operator<(const Flower& other) const {
    if (name_ != other.name_) {
        return name_ < other.name_;
    } else if (color_ != other.color_) {
        return color_ < other.color_;
    } else if (smell_ != other.smell_) {
        return smell_ < other.smell_;
    } else {
        return false;
    }
}

/// \brief "Greater than or equal to" operator based on key fields.
bool Flower::operator>=(const Flower& other) const {
    if (EqFlowers(other) || (*this > other)) {
        return true;
    }
    return false;
}

/// \brief "Less than or equal to" operator based on key fields.
bool Flower::operator<=(const Flower& other) const {
    if (EqFlowers(other) || (*this < other)) {
        return true;
    }
    return false;
}

/// \brief Copy assignment operator.
Flower& Flower::operator=(const Flower& other) {
    name_ = other.name_;
    color_ = other.color_;
    smell_ = other.smell_;
    regions_ = other.regions_;

    return *this;
}