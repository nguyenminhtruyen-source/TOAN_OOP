#pragma once

#include <string>

namespace toan::core {

class BaiToan {
public:
    BaiToan() = default;
    BaiToan(std::string tieuDe, std::string deBai, int mucDo = 1);
    virtual ~BaiToan() = default;

    const std::string& tieuDe() const noexcept;
    const std::string& deBai() const noexcept;
    int mucDo() const noexcept;

    void setTieuDe(std::string tieuDe);
    void setDeBai(std::string deBai);
    void setMucDo(int mucDo) noexcept;

    virtual bool hopLe() const;
    virtual std::string giai() const;
    virtual std::string toLatex() const;

protected:
    static std::string escapeLatex(const std::string& text);

private:
    std::string tieuDe_;
    std::string deBai_;
    int mucDo_{1};
};

} // namespace toan::core
