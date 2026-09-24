#include "geometry/Diem.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>

namespace toan::geometry {

Diem::Diem(double x, double y) noexcept : x_(x), y_(y) {}

double Diem::x() const noexcept { return x_; }
double Diem::y() const noexcept { return y_; }
void Diem::setX(double x) noexcept { x_ = x; }
void Diem::setY(double y) noexcept { y_ = y; }

double Diem::khoangCachDen(const Diem& other) const noexcept {
    return std::hypot(x_ - other.x_, y_ - other.y_);
}

Diem Diem::trungDiem(const Diem& other) const noexcept {
    return {(x_ + other.x_) / 2.0, (y_ + other.y_) / 2.0};
}

void Diem::tinhTien(double dx, double dy) noexcept {
    x_ += dx;
    y_ += dy;
}

std::string Diem::toString(int precision) const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << '(' << x_ << ", " << y_ << ')';
    return out.str();
}

bool Diem::operator==(const Diem& other) const noexcept {
    constexpr double epsilon = 1e-9;
    return std::abs(x_ - other.x_) <= epsilon && std::abs(y_ - other.y_) <= epsilon;
}

bool Diem::operator!=(const Diem& other) const noexcept { return !(*this == other); }

} // namespace toan::geometry
