#include "geometry/DoanThang.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>

namespace toan::geometry {

DoanThang::DoanThang(const Diem& dau, const Diem& cuoi) : dau_(dau), cuoi_(cuoi) {}
const Diem& DoanThang::dau() const noexcept { return dau_; }
const Diem& DoanThang::cuoi() const noexcept { return cuoi_; }
void DoanThang::setDau(const Diem& dau) noexcept { dau_ = dau; }
void DoanThang::setCuoi(const Diem& cuoi) noexcept { cuoi_ = cuoi; }

double DoanThang::doDai() const noexcept { return dau_.khoangCachDen(cuoi_); }
Diem DoanThang::trungDiem() const noexcept { return dau_.trungDiem(cuoi_); }
bool DoanThang::laSuyBien() const noexcept { return dau_ == cuoi_; }

bool DoanThang::chuaDiem(const Diem& diem, double epsilon) const noexcept {
    const double cross = (cuoi_.x() - dau_.x()) * (diem.y() - dau_.y())
                       - (cuoi_.y() - dau_.y()) * (diem.x() - dau_.x());
    if (std::abs(cross) > epsilon) return false;
    const double dot = (diem.x() - dau_.x()) * (diem.x() - cuoi_.x())
                     + (diem.y() - dau_.y()) * (diem.y() - cuoi_.y());
    return dot <= epsilon;
}

std::string DoanThang::toString(int precision) const {
    std::ostringstream out;
    out << "[" << dau_.toString(precision) << " - " << cuoi_.toString(precision) << ']';
    return out.str();
}

} // namespace toan::geometry
