#include "core/BaiToan.hpp"

#include <algorithm>
#include <sstream>
#include <utility>

namespace toan::core {

BaiToan::BaiToan(std::string tieuDe, std::string deBai, int mucDo)
    : tieuDe_(std::move(tieuDe)), deBai_(std::move(deBai)), mucDo_(mucDo) {}

const std::string& BaiToan::tieuDe() const noexcept { return tieuDe_; }
const std::string& BaiToan::deBai() const noexcept { return deBai_; }
int BaiToan::mucDo() const noexcept { return mucDo_; }
void BaiToan::setTieuDe(std::string tieuDe) { tieuDe_ = std::move(tieuDe); }
void BaiToan::setDeBai(std::string deBai) { deBai_ = std::move(deBai); }
void BaiToan::setMucDo(int mucDo) noexcept { mucDo_ = std::max(1, mucDo); }

bool BaiToan::hopLe() const { return !tieuDe_.empty() && !deBai_.empty() && mucDo_ >= 1; }
std::string BaiToan::giai() const { return "Chua co loi giai cho bai toan nay."; }

std::string BaiToan::escapeLatex(const std::string& text) {
    std::string result;
    for (const char character : text) {
        switch (character) {
            case '&': case '%': case '$': case '#': case '_': case '{': case '}': case '~': case '^': case '\\':
                result += '\\';
                break;
            default: break;
        }
        result += character;
    }
    return result;
}

std::string BaiToan::toLatex() const {
    std::ostringstream out;
    out << "\\subsection*{" << escapeLatex(tieuDe_) << "}\n"
        << "\\textbf{Muc do:} " << mucDo_ << "\\par\n"
        << escapeLatex(deBai_) << "\\par\n"
        << "\\textbf{Loi giai:} " << escapeLatex(giai()) << "\n";
    return out.str();
}

} // namespace toan::core
