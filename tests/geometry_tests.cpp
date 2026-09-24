#include "geometry/DoanThang.hpp"
#include "geometry/TamGiac.hpp"

#include <cassert>
#include <cmath>

int main() {
    using namespace toan::geometry;
    constexpr double epsilon = 1e-9;

    const Diem a(0, 0), b(3, 0), c(0, 4);
    const DoanThang ab(a, b);
    assert(std::abs(ab.doDai() - 3.0) < epsilon);
    assert(ab.chuaDiem(Diem(1.5, 0)));
    assert(!ab.chuaDiem(Diem(1.5, 1)));

    const TamGiac tamGiac(a, b, c);
    assert(tamGiac.hopLe());
    assert(std::abs(tamGiac.dienTich() - 6.0) < epsilon);
    assert(std::abs(tamGiac.chuVi() - 12.0) < epsilon);
    assert(tamGiac.loai() == LoaiTamGiac::Vuong);

    const TamGiac khongHopLe(a, b, Diem(6, 0));
    assert(!khongHopLe.hopLe());
    return 0;
}
