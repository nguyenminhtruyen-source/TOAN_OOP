#pragma once

#include "geometry/Diem.hpp"

#include <string>

namespace toan::geometry {

class DoanThang {
public:
    DoanThang() = default;
    DoanThang(const Diem& dau, const Diem& cuoi);

    const Diem& dau() const noexcept;
    const Diem& cuoi() const noexcept;
    void setDau(const Diem& dau) noexcept;
    void setCuoi(const Diem& cuoi) noexcept;

    double doDai() const noexcept;
    Diem trungDiem() const noexcept;
    bool laSuyBien() const noexcept;
    bool chuaDiem(const Diem& diem, double epsilon = 1e-9) const noexcept;
    std::string toString(int precision = 2) const;

private:
    Diem dau_;
    Diem cuoi_;
};

} // namespace toan::geometry
