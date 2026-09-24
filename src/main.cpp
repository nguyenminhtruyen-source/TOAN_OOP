#include "core/BaiToan.hpp"
#include "geometry/TamGiac.hpp"

#include <iostream>

int main() {
    using toan::core::BaiToan;
    using toan::geometry::Diem;
    using toan::geometry::TamGiac;

    const TamGiac tamGiac(Diem(0, 0), Diem(3, 0), Diem(0, 4));
    std::cout << tamGiac.toString() << '\n';
    std::cout << "Loai: " << tamGiac.tenLoai() << '\n';
    std::cout << "Chu vi: " << tamGiac.chuVi() << '\n';
    std::cout << "Dien tich: " << tamGiac.dienTich() << '\n';

    const BaiToan baiToan(
        "Dien tich tam giac",
        "Cho tam giac co cac dinh A(0,0), B(3,0), C(0,4). Tinh dien tich.",
        1);
    std::cout << "\n" << baiToan.tieuDe() << '\n' << baiToan.deBai() << '\n';
    std::cout << baiToan.toLatex();
    return 0;
}
