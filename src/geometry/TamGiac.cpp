#include "geometry/TamGiac.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>

namespace toan::geometry {
namespace {
constexpr double EPSILON = 1e-9;
}

TamGiac::TamGiac(const Diem& a, const Diem& b, const Diem& c) : a_(a), b_(b), c_(c) {}
const Diem& TamGiac::a() const noexcept { return a_; }
const Diem& TamGiac::b() const noexcept { return b_; }
const Diem& TamGiac::c() const noexcept { return c_; }
void TamGiac::setDinh(const Diem& a, const Diem& b, const Diem& c) noexcept { a_ = a; b_ = b; c_ = c; }
DoanThang TamGiac::canhAB() const noexcept { return {a_, b_}; }
DoanThang TamGiac::canhBC() const noexcept { return {b_, c_}; }
DoanThang TamGiac::canhCA() const noexcept { return {c_, a_}; }

bool TamGiac::hopLe() const noexcept { return dienTich() > EPSILON; }

double TamGiac::dienTich() const noexcept {
    return std::abs((b_.x() - a_.x()) * (c_.y() - a_.y())
                  - (b_.y() - a_.y()) * (c_.x() - a_.x())) / 2.0;
}

double TamGiac::chuVi() const noexcept {
    return canhAB().doDai() + canhBC().doDai() + canhCA().doDai();
}

Diem TamGiac::trongTam() const noexcept {
    return {(a_.x() + b_.x() + c_.x()) / 3.0, (a_.y() + b_.y() + c_.y()) / 3.0};
}

LoaiTamGiac TamGiac::loai() const noexcept {
    if (!hopLe()) return LoaiTamGiac::KhongHopLe;
    const double ab2 = std::pow(canhAB().doDai(), 2);
    const double bc2 = std::pow(canhBC().doDai(), 2);
    const double ca2 = std::pow(canhCA().doDai(), 2);
    const bool deu = std::abs(ab2 - bc2) < EPSILON && std::abs(bc2 - ca2) < EPSILON;
    const bool can = std::abs(ab2 - bc2) < EPSILON || std::abs(bc2 - ca2) < EPSILON || std::abs(ca2 - ab2) < EPSILON;
    const double longest = std::max({ab2, bc2, ca2});
    const double sumOthers = ab2 + bc2 + ca2 - longest;
    const bool vuong = std::abs(longest - sumOthers) < EPSILON;
    if (deu) return LoaiTamGiac::Deu;
    if (vuong && can) return LoaiTamGiac::VuongCan;
    if (vuong) return LoaiTamGiac::Vuong;
    if (can) return LoaiTamGiac::Can;
    return LoaiTamGiac::Thuong;
}

std::string TamGiac::tenLoai() const {
    switch (loai()) {
        case LoaiTamGiac::Deu: return "tam giac deu";
        case LoaiTamGiac::Can: return "tam giac can";
        case LoaiTamGiac::Vuong: return "tam giac vuong";
        case LoaiTamGiac::VuongCan: return "tam giac vuong can";
        case LoaiTamGiac::Thuong: return "tam giac thuong";
        default: return "tam giac khong hop le";
    }
}

std::string TamGiac::toString(int precision) const {
    std::ostringstream out;
    out << "TamGiac A=" << a_.toString(precision) << ", B=" << b_.toString(precision)
        << ", C=" << c_.toString(precision);
    return out.str();
}

} // namespace toan::geometry
