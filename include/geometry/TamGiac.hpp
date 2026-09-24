#pragma once

#include "geometry/Diem.hpp"
#include "geometry/DoanThang.hpp"

#include <string>

namespace toan::geometry {

enum class LoaiTamGiac {
    KhongHopLe,
    Deu,
    Can,
    Vuong,
    VuongCan,
    Thuong
};

class TamGiac {
public:
    TamGiac() = default;
    TamGiac(const Diem& a, const Diem& b, const Diem& c);

    const Diem& a() const noexcept;
    const Diem& b() const noexcept;
    const Diem& c() const noexcept;
    void setDinh(const Diem& a, const Diem& b, const Diem& c) noexcept;

    DoanThang canhAB() const noexcept;
    DoanThang canhBC() const noexcept;
    DoanThang canhCA() const noexcept;
    bool hopLe() const noexcept;
    double chuVi() const noexcept;
    double dienTich() const noexcept;
    Diem trongTam() const noexcept;
    LoaiTamGiac loai() const noexcept;
    std::string tenLoai() const;
    std::string toString(int precision = 2) const;

private:
    Diem a_;
    Diem b_;
    Diem c_;
};

} // namespace toan::geometry
