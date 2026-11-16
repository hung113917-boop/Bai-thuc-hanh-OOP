#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

class PhuongTien {
private:
    int maXe;
    string loaiXe;
    int gioVao;
    int thoiGianDo;
    double phiDo;

public:
    PhuongTien() {
        maXe = 0;
        loaiXe = "";
        gioVao = 0;
        thoiGianDo = 0;
        phiDo = 0;
    }

    PhuongTien(int ma, string loai, int gio, int thoiGian) {
        maXe = ma;
        loaiXe = loai;
        gioVao = gio;
        thoiGianDo = thoiGian;
        phiDo = 0;
        tinhPhi();
    }

    int layMaXe() const {
        return maXe;
    }

    string layLoaiXe() const {
        return loaiXe;
    }

    int layGioVao() const {
        return gioVao;
    }

    int layThoiGianDo() const {
        return thoiGianDo;
    }

    double layPhiDo() const {
        return phiDo;
    }

    void datMaXe(int ma) {
        maXe = ma;
    }

    void datLoaiXe(string loai) {
        loaiXe = loai;
    }

    void datGioVao(int gio) {
        gioVao = gio;
    }

    void datThoiGianDo(int thoiGian) {
        thoiGianDo = thoiGian;
    }

    void datPhiDo(double phi) {
        phiDo = phi;
    }

    void tinhPhi() {
        double gia = 0;

        if (loaiXe == "Oto")
            gia = 6.0;
        else if (loaiXe == "XeMay")
            gia = 4.0;
        else if (loaiXe == "XeDap")
            gia = 2.0;

        phiDo = 0;

        bool caoDiem = (gioVao >= 6 && gioVao < 10) ||
                       (gioVao >= 15 && gioVao < 19);

        for (int i = 0; i < thoiGianDo; i++) {
            if (i < 2) {
                if (caoDiem)
                    phiDo += gia * 1.30;
                else
                    phiDo += gia * 0.95;
            }
            else {
                phiDo += gia * 0.90;
            }
        }
    }

    void hienThi() const {
        cout << "Ma xe: " << maXe << endl;
        cout << "Loai xe: " << loaiXe << endl;
        cout << "Gio vao: " << gioVao << endl;
        cout << "Thoi gian do: " << thoiGianDo << " gio" << endl;
        cout << fixed << setprecision(2);
        cout << "Phi do: " << phiDo << " VND" << endl;
    }
};
class BaiDoXe {
private:
    int maBai;
    char kichThuoc;

    static const int MAXXE = 3;
    PhuongTien danhSachXe[MAXXE];
    int soLuongXe;

public:
    BaiDoXe() {
        maBai = 0;
        kichThuoc = 'S';
        soLuongXe = 0;
    }

    BaiDoXe(int ma, char kichThuocBai) {
        maBai = ma;
        kichThuoc = toupper(kichThuocBai);
        soLuongXe = 0;
    }

    int layMaBai() const {
        return maBai;
    }

    char layKichThuoc() const {
        return kichThuoc;
    }

    int laySoLuongXe() const {
        return soLuongXe;
    }

    int laySucChua() const {
        if (kichThuoc == 'S')
            return 1;
        if (kichThuoc == 'M')
            return 2;
        if (kichThuoc == 'L')
            return 3;

        return 0;
    }

    bool day() const {
        return soLuongXe >= laySucChua();
    }

    int timXe(int ma) const {
        for (int i = 0; i < soLuongXe; i++) {
            if (danhSachXe[i].layMaXe() == ma)
                return i;
        }

        return -1;
    }

    bool coXe(int ma) const {
        return timXe(ma) != -1;
    }

    bool themXe(const PhuongTien& xe) {
        if (day())
            return false;

        if (coXe(xe.layMaXe()))
            return false;

        danhSachXe[soLuongXe] = xe;
        soLuongXe++;

        return true;
    }

    bool xoaXe(int ma) {
        int viTri = timXe(ma);

        if (viTri == -1)
            return false;

        for (int i = viTri; i < soLuongXe - 1; i++) {
            danhSachXe[i] = danhSachXe[i + 1];
        }

        soLuongXe--;

        return true;
    }

    void hienThi() const {
        cout << "\nMa bai: " << maBai << endl;
        cout << "Kich thuoc: " << kichThuoc << endl;
        cout << "So xe: " << soLuongXe
             << "/" << laySucChua() << endl;

        if (soLuongXe == 0) {
            cout << "Bai dang trong!" << endl;
            return;
        }

        for (int i = 0; i < soLuongXe; i++) {
            cout << "\nXe thu " << i + 1 << ":" << endl;
            danhSachXe[i].hienThi();
        }
    }

    int demLoaiXe(string loai) const {
        int dem = 0;

        for (int i = 0; i < soLuongXe; i++) {
            if (danhSachXe[i].layLoaiXe() == loai)
                dem++;
        }

        return dem;
    }

    double tongPhiLoaiXe(string loai) const {
        double tong = 0;

        for (int i = 0; i < soLuongXe; i++) {
            if (danhSachXe[i].layLoaiXe() == loai)
                tong += danhSachXe[i].layPhiDo();
        }

        return tong;
    }

    void hienThiLoaiXe(string loai) const {
        for (int i = 0; i < soLuongXe; i++) {
            if (danhSachXe[i].layLoaiXe() == loai) {
                danhSachXe[i].hienThi();
                cout << endl;
            }
        }
    }
};
class GiaoDienHeThong {
private:
    static const int MAXBAI = 10;

    BaiDoXe danhSachBai[MAXBAI];
    int soLuongBai;

    bool nhapSo(int& so) {
        cin >> so;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }

        return true;
    }

    string chuanHoaLoaiXe(string loai) {
        for (int i = 0; i < (int)loai.length(); i++) {
            loai[i] = tolower(loai[i]);
        }

        if (loai == "oto")
            return "Oto";

        if (loai == "xemay")
            return "XeMay";

        if (loai == "xedap")
            return "XeDap";

        return "";
    }

public:
    GiaoDienHeThong() {
        soLuongBai = 0;
        srand((unsigned)time(0));
    }

    bool tonTaiMaBai(int ma) const {
        for (int i = 0; i < soLuongBai; i++) {
            if (danhSachBai[i].layMaBai() == ma)
                return true;
        }

        return false;
    }

    bool tonTaiMaXe(int ma) const {
        for (int i = 0; i < soLuongBai; i++) {
            if (danhSachBai[i].coXe(ma))
                return true;
        }

        return false;
    }

    int taoMaNgauNhien() const {
        int ma;

        do {
            ma = 100 + rand() % 900;
        } while (tonTaiMaBai(ma) || tonTaiMaXe(ma));

        return ma;
    }
    void taoBaiDo() {
        if (soLuongBai >= MAXBAI) {
            cout << "Da dat toi da 10 bai do!" << endl;
            return;
        }

        int ma;
        char kichThuoc;

        cout << "Nhap ma bai: ";

        if (!nhapSo(ma)) {
            cout << "Ma bai khong hop le!" << endl;
            return;
        }

        if (tonTaiMaBai(ma)) {
            cout << "Ma bai da ton tai!" << endl;
            ma = taoMaNgauNhien();
            cout << "Ma bai moi: " << ma << endl;
        }

        cout << "Nhap kich thuoc S/M/L: ";
        cin >> kichThuoc;

        kichThuoc = toupper(kichThuoc);

        if (kichThuoc != 'S' &&
            kichThuoc != 'M' &&
            kichThuoc != 'L') {
            cout << "Kich thuoc khong hop le!" << endl;
            return;
        }

        danhSachBai[soLuongBai] = BaiDoXe(ma, kichThuoc);
        soLuongBai++;

        cout << "Tao bai do thanh cong!" << endl;
    }

    void themXe() {
        if (soLuongBai == 0) {
            cout << "Chua co bai do!" << endl;
            return;
        }

        int ma, gio, thoiGian;
        string loai;

        cout << "Nhap ma xe: ";

        if (!nhapSo(ma)) {
            cout << "Ma xe khong hop le!" << endl;
            return;
        }

        if (tonTaiMaXe(ma)) {
            cout << "Ma xe da ton tai!" << endl;
            ma = taoMaNgauNhien();
            cout << "Ma xe moi: " << ma << endl;
        }

        cout << "Nhap loai xe (Oto/XeMay/XeDap): ";
        cin >> loai;

        loai = chuanHoaLoaiXe(loai);

        if (loai == "") {
            cout << "Loai xe khong hop le!" << endl;
            return;
        }

        cout << "Nhap gio vao: ";

        if (!nhapSo(gio)) {
            cout << "Gio vao khong hop le!" << endl;
            return;
        }

        if (gio < 0 || gio > 23) {
            cout << "Gio vao khong hop le!" << endl;
            return;
        }

        cout << "Nhap thoi gian do: ";

        if (!nhapSo(thoiGian)) {
            cout << "Thoi gian do khong hop le!" << endl;
            return;
        }

        if (thoiGian < 1 || thoiGian > 23) {
            cout << "Thoi gian do khong hop le!" << endl;
            return;
        }

        PhuongTien xe(ma, loai, gio, thoiGian);

        for (int i = 0; i < soLuongBai; i++) {
            if (!danhSachBai[i].day()) {
                danhSachBai[i].themXe(xe);

                cout << "Da them xe vao bai "
                     << danhSachBai[i].layMaBai() << endl;

                cout << fixed << setprecision(2);
                cout << "Phi do xe: "
                     << xe.layPhiDo() << " VND" << endl;

                return;
            }
        }

        cout << "Tat ca bai do da day!" << endl;
    }

    void xoaBaiDo() {
        int ma;

        cout << "Nhap ma bai can xoa: ";

        if (!nhapSo(ma)) {
            cout << "Ma bai khong hop le!" << endl;
            return;
        }

        int viTri = -1;
        for (int i = 0; i < soLuongBai; i++) {
            if (danhSachBai[i].layMaBai() == ma) {
                viTri = i;
                break;
            }
        }

        if (viTri == -1) {
            cout << "Khong tim thay bai!" << endl;
            return;
        }

        for (int i = viTri; i < soLuongBai - 1; i++) {
            danhSachBai[i] = danhSachBai[i + 1];
        }

        soLuongBai--;

        cout << "Da xoa bai do!" << endl;
    }

    void xoaXe() {
        int ma;

        cout << "Nhap ma xe can xoa: ";

        if (!nhapSo(ma)) {
            cout << "Ma xe khong hop le!" << endl;
            return;
        }

        for (int i = 0; i < soLuongBai; i++) {
            if (danhSachBai[i].coXe(ma)) {
                danhSachBai[i].xoaXe(ma);
                cout << "Da xoa xe!" << endl;
                return;
            }
        }

        cout << "Khong tim thay xe!" << endl;
    }

    void hienThiTatCa() const {
        if (soLuongBai == 0) {
            cout << "Chua co bai do!" << endl;
            return;
        }

        for (int i = 0; i < soLuongBai; i++) {
            danhSachBai[i].hienThi();
        }
    }

    void hienThiTheoBai()  {
        int ma;
        cout << "Nhap ma bai: ";
        if (!nhapSo(ma)) {
            cout << "Ma bai khong hop le!" << endl;
            return;
        }
        for (int i = 0; i < soLuongBai; i++) {
            if (danhSachBai[i].layMaBai() == ma) {
                danhSachBai[i].hienThi();
                return;
            }
        }
        cout << "Khong tim thay bai!" << endl;
    }

    void lietKeTheoLoai()  {
        string loai;
        cout << "Nhap loai xe (Oto/XeMay/XeDap): ";
        cin >> loai;
        loai = chuanHoaLoaiXe(loai);
        if (loai == "") {
            cout << "Loai xe khong hop le!" << endl;
            return;
        }

        bool timThay = false;

        for (int i = 0; i < soLuongBai; i++) {
            if (danhSachBai[i].demLoaiXe(loai) > 0) {
                cout << "\nBai "
                     << danhSachBai[i].layMaBai()
                     << ":" << endl;

                danhSachBai[i].hienThiLoaiXe(loai);
                timThay = true;
            }
        }

        if (!timThay)
            cout << "Khong tim thay xe!" << endl;
    }

    void baoCaoPhi() const {
        double tongOto = 0;
        double tongXeMay = 0;
        double tongXeDap = 0;

        int soOto = 0;
        int soXeMay = 0;
        int soXeDap = 0;

        for (int i = 0; i < soLuongBai; i++) {
            tongOto += danhSachBai[i].tongPhiLoaiXe("Oto");
            tongXeMay += danhSachBai[i].tongPhiLoaiXe("XeMay");
            tongXeDap += danhSachBai[i].tongPhiLoaiXe("XeDap");

            soOto += danhSachBai[i].demLoaiXe("Oto");
            soXeMay += danhSachBai[i].demLoaiXe("XeMay");
            soXeDap += danhSachBai[i].demLoaiXe("XeDap");
        }

        cout << fixed << setprecision(2);
        cout << "\n===== BAO CAO PHI TRUNG BINH =====" << endl;

        if (soOto > 0)
            cout << "Oto: "
                 << tongOto / soOto << " VND" << endl;
        else
            cout << "Oto: Chua co du lieu" << endl;

        if (soXeMay > 0)
            cout << "XeMay: "
                 << tongXeMay / soXeMay << " VND" << endl;
        else
            cout << "XeMay: Chua co du lieu" << endl;

        if (soXeDap > 0)
            cout << "XeDap: "
                 << tongXeDap / soXeDap << " VND" << endl;
        else
            cout << "XeDap: Chua co du lieu" << endl;

        cout << "\n===== PHI THEO TUNG BAI =====" << endl;

        for (int i = 0; i < soLuongBai; i++) {
            cout << "\nBai "
                 << danhSachBai[i].layMaBai()
                 << ":" << endl;

            int soLuong = danhSachBai[i].demLoaiXe("Oto");

            if (soLuong > 0)
                cout << "Oto: "
                     << danhSachBai[i].tongPhiLoaiXe("Oto") / soLuong
                     << " VND" << endl;

            soLuong = danhSachBai[i].demLoaiXe("XeMay");

            if (soLuong > 0)
                cout << "XeMay: "
                     << danhSachBai[i].tongPhiLoaiXe("XeMay") / soLuong
                     << " VND" << endl;

            soLuong = danhSachBai[i].demLoaiXe("XeDap");

            if (soLuong > 0)
                cout << "XeDap: "
                     << danhSachBai[i].tongPhiLoaiXe("XeDap") / soLuong
                     << " VND" << endl;
        }
    }

    void chayMenu() {
        int luaChon;

        do {
            cout << "\n========== QUAN LY BAI DO XE ==========" << endl;
            cout << "1. Tao bai do xe" << endl;
            cout << "2. Them xe vao bai" << endl;
            cout << "3. Xoa bai do xe" << endl;
            cout << "4. Xoa xe khoi bai" << endl;
            cout << "5. Hien thi tat ca bai do" << endl;
            cout << "6. Hien thi xe theo bai" << endl;
            cout << "7. Liet ke xe theo loai" << endl;
            cout << "8. Bao cao phi do xe" << endl;
            cout << "9. Thoat" << endl;
            cout << "=======================================" << endl;

            cout << "Nhap lua chon: ";

            if (!nhapSo(luaChon)) {
                cout << "Vui long nhap so tu 1 den 9!" << endl;
                continue;
            }

            switch (luaChon) {
            case 1:
                taoBaiDo();
                break;

            case 2:
                themXe();
                break;

            case 3:
                xoaBaiDo();
                break;

            case 4:
                xoaXe();
                break;

            case 5:
                hienThiTatCa();
                break;

            case 6:
                hienThiTheoBai();
                break;

            case 7:
                lietKeTheoLoai();
                break;

            case 8:
                baoCaoPhi();
                break;
                case 9:
                cout << "Da thoat chuong trinh!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
            }

        } while (luaChon != 9);
    }
};

int main() {
    GiaoDienHeThong heThong;
    heThong.chayMenu();

    return 0;
}
