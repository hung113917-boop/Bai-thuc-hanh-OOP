#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

class Xe
{
private:
    int maXe;
    string loaiXe;
    int gioVao;
    int thoiGianDo;
    double phiDoXe;
    bool dangCoXe;
public:
    Xe();
    Xe(int ma, string loai, int gio, int thoiGian);
    int layMaXe() const;
    string layLoaiXe() const;
    int layGioVao() const;
    int layThoiGianDo() const;
    double layPhiDoXe() const;
    bool layTrangThai() const;
    void datMaXe(int ma);
    void datLoaiXe(string loai);
    void datGioVao(int gio);
    void datThoiGianDo(int thoiGian);
    void datPhiDoXe(double phi);
    void datTrangThai(bool trangThai);
    void tinhPhiDoXe();
    void hienThi() const;
};

Xe::Xe()
{
    maXe = 0;
    loaiXe = "";
    gioVao = 0;
    thoiGianDo = 0;
    phiDoXe = 0;
    dangCoXe = false;
}
Xe::Xe(int ma, string loai, int gio, int thoiGian)
{
    maXe = ma;
    loaiXe = loai;
    gioVao = gio;
    thoiGianDo = thoiGian;
    phiDoXe = 0;
    dangCoXe = true;
    tinhPhiDoXe();
}
int Xe::layMaXe() const { return maXe; }
string Xe::layLoaiXe() const { return loaiXe; }
int Xe::layGioVao() const { return gioVao; }
int Xe::layThoiGianDo() const { return thoiGianDo; }
double Xe::layPhiDoXe() const { return phiDoXe; }
bool Xe::layTrangThai() const { return dangCoXe; }
void Xe::datMaXe(int ma) { maXe = ma; }
void Xe::datLoaiXe(string loai) { loaiXe = loai; }
void Xe::datGioVao(int gio) { gioVao = gio; }
void Xe::datThoiGianDo(int thoiGian) { thoiGianDo = thoiGian; }
void Xe::datPhiDoXe(double phi) { phiDoXe = phi; }
void Xe::datTrangThai(bool trangThai) { dangCoXe = trangThai; }

void Xe::tinhPhiDoXe()
{
    double donGia;
    if (loaiXe == "Oto")
        donGia = 6.0;
    else if (loaiXe == "XeMay")
        donGia = 4.0;
    else
        donGia = 2.0;
    bool gioCaoDiem = false;
    if ((gioVao >= 6 && gioVao <= 9) || (gioVao >= 15 && gioVao <= 18))
        gioCaoDiem = true;
    phiDoXe = 0;
    for (int i = 1; i <= thoiGianDo; i++)
    {
        if (i <= 2)
        {
            if (gioCaoDiem)
                phiDoXe += donGia * 1.30;
            else
                phiDoXe += donGia * 0.95;
        }
        else
            phiDoXe += donGia * 0.90;
    }
}

void Xe::hienThi() const
{
    cout << "Ma xe: " << maXe << endl;
    cout << "Loai xe: " << loaiXe << endl;
    cout << "Gio vao: " << gioVao << endl;
    cout << "Thoi gian do: " << thoiGianDo << " gio" << endl;
    cout << "Phi do xe: " << fixed << setprecision(2) << phiDoXe << " VND" << endl;
}

class BaiDoXe
{
private:
    int maBai;
    char kichThuoc;
    Xe xe1, xe2, xe3;
    bool coXe1, coXe2, coXe3;
public:
    BaiDoXe();
    BaiDoXe(int ma, char kichThuocBai);
    int layMaBai() const;
    char layKichThuoc() const;
    void datMaBai(int ma);
    void datKichThuoc(char kichThuocBai);
    bool themXe(const Xe& xe);
    bool xoaXe(int ma);
    bool coXe(int ma) const;
    int laySucChua() const;
    int laySoLuongXe() const;
    void hienThiThongTin() const;
    void hienThiXeTheoLoai(string loai) const;
    bool coLoaiXe(string loai) const;
    int laySoXeTheoLoai(string loai) const;
    double layTongPhiTheoLoai(string loai) const;
    double layTongPhi() const;
};

BaiDoXe::BaiDoXe()
{
    maBai = 0;
    kichThuoc = 'S';
    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}
BaiDoXe::BaiDoXe(int ma, char kichThuocBai)
{
    maBai = ma;
    kichThuoc = toupper(kichThuocBai);
    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}
int BaiDoXe::layMaBai() const { return maBai; }
char BaiDoXe::layKichThuoc() const { return kichThuoc; }
void BaiDoXe::datMaBai(int ma) { maBai = ma; }
void BaiDoXe::datKichThuoc(char kichThuocBai) { kichThuoc = toupper(kichThuocBai); }

int BaiDoXe::laySucChua() const
{
    if (kichThuoc == 'S')
        return 1;
    if (kichThuoc == 'M')
        return 2;
    return 3;
}

int BaiDoXe::laySoLuongXe() const
{
    int soLuong = 0;
    if (coXe1) soLuong++;
    if (coXe2) soLuong++;
    if (coXe3) soLuong++;
    return soLuong;
}

bool BaiDoXe::themXe(const Xe& xe)
{
    if (laySoLuongXe() >= laySucChua())
        return false;
    if (!coXe1)
    {
        xe1 = xe;
        coXe1 = true;
        return true;
    }
    if (!coXe2 && laySucChua() >= 2)
    {
        xe2 = xe;
        coXe2 = true;
        return true;
    }
    if (!coXe3 && laySucChua() >= 3)
    {
        xe3 = xe;
        coXe3 = true;
        return true;
    }
    return false;
}

bool BaiDoXe::xoaXe(int ma)
{
    if (coXe1 && xe1.layMaXe() == ma)
    {
        if (coXe2)
        {
            xe1 = xe2;
            if (coXe3)
            {
                xe2 = xe3;
                coXe3 = false;
            }
            else
                coXe2 = false;
        }
        else
            coXe1 = false;
        return true;
    }
    if (coXe2 && xe2.layMaXe() == ma)
    {
        if (coXe3)
        {
            xe2 = xe3;
            coXe3 = false;
        }
        else
            coXe2 = false;
        return true;
    }
    if (coXe3 && xe3.layMaXe() == ma)
    {
        coXe3 = false;
        return true;
    }
    return false;
}

bool BaiDoXe::coXe(int ma) const
{
    if (coXe1 && xe1.layMaXe() == ma) return true;
    if (coXe2 && xe2.layMaXe() == ma) return true;
    if (coXe3 && xe3.layMaXe() == ma) return true;
    return false;
}

void BaiDoXe::hienThiThongTin() const
{
    cout << "\n-----------------------------\n";
    cout << "Ma bai: " << maBai << endl;
    cout << "Kich thuoc: " << kichThuoc << endl;
    cout << "So xe: " << laySoLuongXe() << "/" << laySucChua() << endl;
    if (laySoLuongXe() == 0)
    {
        cout << "Bai dang trong.\n";
        return;
    }
    if (coXe1)
    {
        cout << "\nXe 1:\n";
        xe1.hienThi();
    }
    if (coXe2)
    {
        cout << "\nXe 2:\n";
        xe2.hienThi();
    }
    if (coXe3)
    {
        cout << "\nXe 3:\n";
        xe3.hienThi();
    }
}

void BaiDoXe::hienThiXeTheoLoai(string loai) const
{
    bool timThay = false;
    if (coXe1 && xe1.layLoaiXe() == loai)
    {
        xe1.hienThi();
        cout << endl;
        timThay = true;
    }
    if (coXe2 && xe2.layLoaiXe() == loai)
    {
        xe2.hienThi();
        cout << endl;
        timThay = true;
    }
    if (coXe3 && xe3.layLoaiXe() == loai)
    {
        xe3.hienThi();
        cout << endl;
        timThay = true;
    }
    if (!timThay)
        cout << "Khong co xe loai " << loai << " trong bai " << maBai << ".\n";
}

bool BaiDoXe::coLoaiXe(string loai) const
{
    if (coXe1 && xe1.layLoaiXe() == loai) return true;
    if (coXe2 && xe2.layLoaiXe() == loai) return true;
    if (coXe3 && xe3.layLoaiXe() == loai) return true;
    return false;
}

int BaiDoXe::laySoXeTheoLoai(string loai) const
{
    int soLuong = 0;
    if (coXe1 && xe1.layLoaiXe() == loai) soLuong++;
    if (coXe2 && xe2.layLoaiXe() == loai) soLuong++;
    if (coXe3 && xe3.layLoaiXe() == loai) soLuong++;
    return soLuong;
}

double BaiDoXe::layTongPhiTheoLoai(string loai) const
{
    double tongPhi = 0;
    if (coXe1 && xe1.layLoaiXe() == loai) tongPhi += xe1.layPhiDoXe();
    if (coXe2 && xe2.layLoaiXe() == loai) tongPhi += xe2.layPhiDoXe();
    if (coXe3 && xe3.layLoaiXe() == loai) tongPhi += xe3.layPhiDoXe();
    return tongPhi;
}

double BaiDoXe::layTongPhi() const
{
    double tongPhi = 0;
    if (coXe1) tongPhi += xe1.layPhiDoXe();
    if (coXe2) tongPhi += xe2.layPhiDoXe();
    if (coXe3) tongPhi += xe3.layPhiDoXe();
    return tongPhi;
}

class GiaoDienHeThong
{
private:
    BaiDoXe bai1, bai2, bai3;
    bool coBai1, coBai2, coBai3;
    bool kiemTraLoaiXe(string loai) const;
    bool kiemTraGio(int gio) const;
    bool kiemTraThoiGian(int thoiGian) const;
    bool trungMaBai(int ma) const;
    bool trungMaXe(int ma) const;
    void taoBaiDoXe();
    void themXeVaoBai();
    void xoaBaiDoXe();
    void layXeRa();
    void hienThiTatCaBai();
    void hienThiXeTheoBai();
    void lietKeXeTheoLoai();
    void baoCaoPhiTrungBinh();
public:
    GiaoDienHeThong();
    void chayChuongTrinh();
};

GiaoDienHeThong::GiaoDienHeThong()
{
    coBai1 = false;
    coBai2 = false;
    coBai3 = false;
}

bool GiaoDienHeThong::kiemTraLoaiXe(string loai) const
{
    return loai == "Oto" || loai == "XeMay" || loai == "XeDap";
}
bool GiaoDienHeThong::kiemTraGio(int gio) const
{
    return gio >= 0 && gio <= 23;
}
bool GiaoDienHeThong::kiemTraThoiGian(int thoiGian) const
{
    return thoiGian >= 1 && thoiGian <= 23;
}
bool GiaoDienHeThong::trungMaBai(int ma) const
{
    if (coBai1 && bai1.layMaBai() == ma) return true;
    if (coBai2 && bai2.layMaBai() == ma) return true;
    if (coBai3 && bai3.layMaBai() == ma) return true;
    return false;
}
bool GiaoDienHeThong::trungMaXe(int ma) const
{
    if (coBai1 && bai1.coXe(ma)) return true;
    if (coBai2 && bai2.coXe(ma)) return true;
    if (coBai3 && bai3.coXe(ma)) return true;
    return false;
}

void GiaoDienHeThong::taoBaiDoXe()
{
    if (coBai1 && coBai2 && coBai3)
    {
        cout << "Da dat toi da 3 bai do.\n";
        return;
    }
    int ma;
    char kichThuoc;
    cout << "Nhap ma bai: ";
    cin >> ma;
    if (trungMaBai(ma))
    {
        cout << "Ma bai da ton tai.\n";
        return;
    }
    cout << "Nhap kich thuoc bai (S/M/L): ";
    cin >> kichThuoc;
    kichThuoc = toupper(kichThuoc);
    if (kichThuoc != 'S' && kichThuoc != 'M' && kichThuoc != 'L')
    {
        cout << "Kich thuoc khong hop le.\n";
        return;
    }
    BaiDoXe baiMoi(ma, kichThuoc);
    if (!coBai1)
    {
        bai1 = baiMoi;
        coBai1 = true;
    }
    else if (!coBai2)
    {
        bai2 = baiMoi;
        coBai2 = true;
    }
    else
    {
        bai3 = baiMoi;
        coBai3 = true;
    }
    cout << "Tao bai do thanh cong.\n";
}

void GiaoDienHeThong::themXeVaoBai()
{
    int ma, gio, thoiGian;
    string loai;
    cout << "Nhap ma xe: ";
    cin >> ma;
    if (trungMaXe(ma))
    {
        cout << "Ma xe da ton tai.\n";
        return;
    }
    cout << "Nhap loai xe (Oto/XeMay/XeDap): ";
    cin >> loai;
    if (!kiemTraLoaiXe(loai))
    {
        cout << "Loai xe khong hop le.\n";
        return;
    }
    cout << "Nhap gio vao (0-23): ";
    cin >> gio;
    if (!kiemTraGio(gio))
    {
        cout << "Gio vao khong hop le.\n";
        return;
    }
    cout << "Nhap thoi gian do (1-23): ";
    cin >> thoiGian;
    if (!kiemTraThoiGian(thoiGian))
    {
        cout << "Thoi gian do khong hop le.\n";
        return;
    }
    Xe xe(ma, loai, gio, thoiGian);
    bool daThem = false;
    if (coBai1 && !daThem) daThem = bai1.themXe(xe);
    if (coBai2 && !daThem) daThem = bai2.themXe(xe);
    if (coBai3 && !daThem) daThem = bai3.themXe(xe);
    if (!daThem)
    {
        cout << "Khong con bai nao co cho trong.\n";
        return;
    }
    cout << "Da them xe. Phi do xe: "
         << fixed << setprecision(2)
         << xe.layPhiDoXe() << " VND\n";
}

void GiaoDienHeThong::xoaBaiDoXe()
{
    int ma;
    cout << "Nhap ma bai can xoa: ";
    cin >> ma;
    if (coBai1 && bai1.layMaBai() == ma)
    {
        if (coBai2)
        {
            bai1 = bai2;
            if (coBai3)
            {
                bai2 = bai3;
                coBai3 = false;
            }
            else
                coBai2 = false;
        }
        else
            coBai1 = false;
        cout << "Da xoa bai do.\n";
        return;
    }
    if (coBai2 && bai2.layMaBai() == ma)
    {
        if (coBai3)
        {
            bai2 = bai3;
            coBai3 = false;
        }
        else
            coBai2 = false;
        cout << "Da xoa bai do.\n";
        return;
    }
    if (coBai3 && bai3.layMaBai() == ma)
    {
        coBai3 = false;
        cout << "Da xoa bai do.\n";
        return;
    }
    cout << "Khong tim thay bai do.\n";
}

void GiaoDienHeThong::layXeRa()
{
    int ma;
    cout << "Nhap ma xe can lay ra: ";
    cin >> ma;
    bool daXoa = false;
    if (coBai1 && !daXoa) daXoa = bai1.xoaXe(ma);
    if (coBai2 && !daXoa) daXoa = bai2.xoaXe(ma);
    if (coBai3 && !daXoa) daXoa = bai3.xoaXe(ma);
    if (daXoa)
        cout << "Da lay xe ra khoi bai.\n";
    else
        cout << "Khong tim thay xe.\n";
}

void GiaoDienHeThong::hienThiTatCaBai()
{
    if (!coBai1 && !coBai2 && !coBai3)
    {
        cout << "Chua co bai do nao.\n";
        return;
    }
    if (coBai1) bai1.hienThiThongTin();
    if (coBai2) bai2.hienThiThongTin();
    if (coBai3) bai3.hienThiThongTin();
}

void GiaoDienHeThong::hienThiXeTheoBai()
{
    int ma;
    cout << "Nhap ma bai: ";
    cin >> ma;
    if (coBai1 && bai1.layMaBai() == ma)
    {
        bai1.hienThiThongTin();
        return;
    }
    if (coBai2 && bai2.layMaBai() == ma)
    {
        bai2.hienThiThongTin();
        return;
    }
    if (coBai3 && bai3.layMaBai() == ma)
    {
        bai3.hienThiThongTin();
        return;
    }
    cout << "Khong tim thay bai do.\n";
}

void GiaoDienHeThong::lietKeXeTheoLoai()
{
    string loai;
    cout << "Nhap loai xe (Oto/XeMay/XeDap): ";
    cin >> loai;
    if (!kiemTraLoaiXe(loai))
    {
        cout << "Loai xe khong hop le.\n";
        return;
    }
    bool timThay = false;
    if (coBai1 && bai1.coLoaiXe(loai))
    {
        cout << "\nBai " << bai1.layMaBai() << ":\n";
        bai1.hienThiXeTheoLoai(loai);
        timThay = true;
    }
    if (coBai2 && bai2.coLoaiXe(loai))
    {
        cout << "\nBai " << bai2.layMaBai() << ":\n";
        bai2.hienThiXeTheoLoai(loai);
        timThay = true;
    }
    if (coBai3 && bai3.coLoaiXe(loai))
    {
        cout << "\nBai " << bai3.layMaBai() << ":\n";
        bai3.hienThiXeTheoLoai(loai);
        timThay = true;
    }
    if (!timThay)
        cout << "Khong co xe loai " << loai << ".\n";
}

void GiaoDienHeThong::baoCaoPhiTrungBinh()
{
    int soOto = 0, soXeMay = 0, soXeDap = 0;
    double phiOto = 0, phiXeMay = 0, phiXeDap = 0;
    if (coBai1)
    {
        soOto += bai1.laySoXeTheoLoai("Oto");
        soXeMay += bai1.laySoXeTheoLoai("XeMay");
        soXeDap += bai1.laySoXeTheoLoai("XeDap");
        phiOto += bai1.layTongPhiTheoLoai("Oto");
        phiXeMay += bai1.layTongPhiTheoLoai("XeMay");
        phiXeDap += bai1.layTongPhiTheoLoai("XeDap");
    }
    if (coBai2)
    {
        soOto += bai2.laySoXeTheoLoai("Oto");
        soXeMay += bai2.laySoXeTheoLoai("XeMay");
        soXeDap += bai2.laySoXeTheoLoai("XeDap");
        phiOto += bai2.layTongPhiTheoLoai("Oto");
        phiXeMay += bai2.layTongPhiTheoLoai("XeMay");
        phiXeDap += bai2.layTongPhiTheoLoai("XeDap");
    }
    if (coBai3)
    {
        soOto += bai3.laySoXeTheoLoai("Oto");
        soXeMay += bai3.laySoXeTheoLoai("XeMay");
        soXeDap += bai3.laySoXeTheoLoai("XeDap");
        phiOto += bai3.layTongPhiTheoLoai("Oto");
        phiXeMay += bai3.layTongPhiTheoLoai("XeMay");
        phiXeDap += bai3.layTongPhiTheoLoai("XeDap");
    }
    cout << "\n========== BAO CAO PHI TRUNG BINH ==========\n";
    cout << "Oto: ";
    if (soOto == 0) cout << "Khong co xe\n";
    else cout << fixed << setprecision(2) << phiOto / soOto << " VND/xe\n";
    cout << "XeMay: ";
    if (soXeMay == 0) cout << "Khong co xe\n";
    else cout << fixed << setprecision(2) << phiXeMay / soXeMay << " VND/xe\n";
    cout << "XeDap: ";
    if (soXeDap == 0) cout << "Khong co xe\n";
    else cout << fixed << setprecision(2) << phiXeDap / soXeDap << " VND/xe\n";
    cout << "\n========== CHI TIET THEO TUNG BAI ==========\n";
    if (coBai1)
    {
        cout << "\nBai " << bai1.layMaBai() << ":\n";
        cout << "So xe: " << bai1.laySoLuongXe() << endl;
        cout << "Tong phi: " << fixed << setprecision(2) << bai1.layTongPhi() << " VND\n";
        if (bai1.laySoLuongXe() > 0)
            cout << "Phi trung binh: " << bai1.layTongPhi() / bai1.laySoLuongXe() << " VND/xe\n";
    }
    if (coBai2)
    {
        cout << "\nBai " << bai2.layMaBai() << ":\n";
        cout << "So xe: " << bai2.laySoLuongXe() << endl;
        cout << "Tong phi: " << fixed << setprecision(2) << bai2.layTongPhi() << " VND\n";
        if (bai2.laySoLuongXe() > 0)
            cout << "Phi trung binh: " << bai2.layTongPhi() / bai2.laySoLuongXe() << " VND/xe\n";
    }
    if (coBai3)
    {
        cout << "\nBai " << bai3.layMaBai() << ":\n";
        cout << "So xe: " << bai3.laySoLuongXe() << endl;
        cout << "Tong phi: " << fixed << setprecision(2) << bai3.layTongPhi() << " VND\n";
        if (bai3.laySoLuongXe() > 0)
            cout << "Phi trung binh: " << bai3.layTongPhi() / bai3.laySoLuongXe() << " VND/xe\n";
    }
}

void GiaoDienHeThong::chayChuongTrinh()
{
    int luaChon;
    do
    {
        cout << "\n========================================\n";
        cout << "       HE THONG QUAN LY BAI DO XE\n";
        cout << "========================================\n";
        cout << "1. Tao bai do xe moi\n";
        cout << "2. Them xe vao bai do\n";
        cout << "3. Xoa mot bai do xe\n";
        cout << "4. Lay xe ra khoi bai do\n";
        cout << "5. Hien thi danh sach tat ca bai do xe\n";
        cout << "6. Hien thi danh sach xe theo bai\n";
        cout << "7. Liet ke xe theo loai phuong tien\n";
        cout << "8. Xem bao cao tom tat phi do xe trung binh\n";
        cout << "9. Thoat chuong trinh\n";
        cout << "========================================\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        switch (luaChon)
        {
        case 1:
            taoBaiDoXe();
            break;
        case 2:
            themXeVaoBai();
            break;
        case 3:
            xoaBaiDoXe();
            break;
        case 4:
            layXeRa();
            break;
        case 5:
            hienThiTatCaBai();
            break;
        case 6:
            hienThiXeTheoBai();
            break;
        case 7:
            lietKeXeTheoLoai();
            break;
        case 8:
            baoCaoPhiTrungBinh();
            break;
        case 9:
            cout << "Da thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 9);
}

int main()
{
    GiaoDienHeThong heThong;
    heThong.chayChuongTrinh();
    return 0;
}
