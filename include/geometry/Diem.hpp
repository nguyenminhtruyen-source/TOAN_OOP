#pragma once

#include <string>

namespace toan::geometry {

class Diem {
public:
    Diem() = default;
    Diem(double x, double y) noexcept;

    double x() const noexcept;
    double y() const noexcept;
    void setX(double x) noexcept;
    void setY(double y) noexcept;

    double khoangCachDen(const Diem& other) const noexcept;
    Diem trungDiem(const Diem& other) const noexcept;
    void tinhTien(double dx, double dy) noexcept;

    std::string toString(int precision = 2) const;

    bool operator==(const Diem& other) const noexcept;
    bool operator!=(const Diem& other) const noexcept;

private:
    double x_{0.0};
    double y_{0.0};
};

} // namespace toan::geometry
