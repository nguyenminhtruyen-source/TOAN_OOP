# TOAN OOP

Hệ thống mô hình hóa và sinh bài toán Toán bằng C++ theo nguyên tắc lập trình hướng đối tượng.

## Cấu trúc

```text
TOAN_OOP/
├── CMakeLists.txt
├── include/
│   ├── core/BaiToan.hpp
│   └── geometry/
│       ├── Diem.hpp
│       ├── DoanThang.hpp
│       └── TamGiac.hpp
├── src/
│   ├── core/BaiToan.cpp
│   ├── geometry/
│   │   ├── Diem.cpp
│   │   ├── DoanThang.cpp
│   │   └── TamGiac.cpp
│   └── main.cpp
└── tests/geometry_tests.cpp
```

## Biên dịch và chạy

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/toan_app

# Chạy kiểm thử
ctest --test-dir build --output-on-failure
```

Dự án dùng C++17 và không phụ thuộc thư viện bên ngoài. Các lớp hình học minh họa đóng gói, composition (`TamGiac` sử dụng `Diem` và `DoanThang`) và đa hình thông qua `BaiToan`.
