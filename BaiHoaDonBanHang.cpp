#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SanPham
{
private:
    string tenSanPham;
    string donViTinh;
    int soLuong;
    double donGia;

public:
    SanPham()
    {
        tenSanPham = "";
        donViTinh = "";
        soLuong = 0;
        donGia = 0;
    }

    void nhap()
    {
        cout << "Ten san pham: ";
        getline(cin, tenSanPham);

        cout << "Don vi tinh: ";
        getline(cin, donViTinh);

        cout << "So luong: ";
        cin >> soLuong;

        cout << "Don gia: ";
        cin >> donGia;

        cin.ignore();
    }

    double thanhTien()
    {
        return soLuong * donGia;
    }

    void xuat(int stt)
    {
        cout << left << setw(5) << stt
             << setw(30) << tenSanPham
             << setw(12) << donViTinh
             << right << setw(10) << soLuong
             << setw(15) << fixed << setprecision(0) << donGia
             << setw(15) << thanhTien() << endl;
    }
};

class HoaDon
{
private:
    string tenCuaHang;
    string diaChi;
    string soDienThoai;

    string soHoaDon;
    string ngayLap;

    string tenKhachHang;
    string diaChiKhachHang;
    string maSoThue;

    SanPham danhSach[20];
    int soLuongSanPham;

public:
    HoaDon()
    {
        tenCuaHang = "NNC GROUP";
        diaChi = "";
        soDienThoai = "";

        soHoaDon = "";
        ngayLap = "";

        tenKhachHang = "";
        diaChiKhachHang = "";
        maSoThue = "";

        soLuongSanPham = 0;
    }

    void nhapThongTin()
    {
        cout << "========== NHAP THONG TIN HOA DON ==========\n";

        cout << "Ten cua hang: ";
        getline(cin, tenCuaHang);

        cout << "Dia chi cua hang: ";
        getline(cin, diaChi);

        cout << "So dien thoai: ";
        getline(cin, soDienThoai);

        cout << "So hoa don: ";
        getline(cin, soHoaDon);

        cout << "Ngay lap: ";
        getline(cin, ngayLap);

        cout << "Ten khach hang: ";
        getline(cin, tenKhachHang);

        cout << "Dia chi khach hang: ";
        getline(cin, diaChiKhachHang);

        cout << "Ma so thue: ";
        getline(cin, maSoThue);

        cout << "\nNhap so luong san pham: ";
        cin >> soLuongSanPham;
        cin.ignore();

        for (int i = 0; i < soLuongSanPham; i++)
        {
            cout << "\n--- San pham " << i + 1 << " ---\n";
            danhSach[i].nhap();
        }
    }

    double tinhTienHang()
    {
        double tong = 0;

        for (int i = 0; i < soLuongSanPham; i++)
        {
            tong += danhSach[i].thanhTien();
        }

        return tong;
    }

    double tinhThue()
    {
        return tinhTienHang() * 0.1;
    }

    double tinhTongThanhToan()
    {
        return tinhTienHang() + tinhThue();
    }

    void xuat()
    {
        cout << "\n\n";
        cout << "===============================================================\n";
        cout << "                    HOA DON BAN HANG\n";
        cout << "===============================================================\n";

        cout << "Cua hang: " << tenCuaHang << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Dien thoai: " << soDienThoai << endl;

        cout << "So hoa don: " << soHoaDon;
        cout << "                Ngay: " << ngayLap << endl;

        cout << "Khach hang: " << tenKhachHang << endl;
        cout << "Dia chi: " << diaChiKhachHang << endl;
        cout << "Ma so thue: " << maSoThue << endl;

        cout << "---------------------------------------------------------------\n";

        cout << left
             << setw(5) << "STT"
             << setw(30) << "Ten san pham"
             << setw(12) << "DVT"
             << right << setw(10) << "SL"
             << setw(15) << "Don gia"
             << setw(15) << "Thanh tien"
             << endl;

        cout << "---------------------------------------------------------------\n";

        for (int i = 0; i < soLuongSanPham; i++)
        {
            danhSach[i].xuat(i + 1);
        }

        cout << "---------------------------------------------------------------\n";

        cout << right << setw(55) << "Cong tien hang: "
             << fixed << setprecision(0)
             << setw(15) << tinhTienHang() << " VND\n";

        cout << right << setw(55) << "Thue GTGT (10%): "
             << setw(15) << tinhThue() << " VND\n";

        cout << right << setw(55) << "TONG THANH TOAN: "
             << setw(15) << tinhTongThanhToan() << " VND\n";

        cout << "===============================================================\n";

        cout << "\nNguoi mua hang                         Nguoi ban hang\n";
        cout << " (Ky, ghi ro ho ten)                    (Ky, ghi ro ho ten)\n";
    }
};

int main()
{
    HoaDon hoaDon;

    hoaDon.nhapThongTin();

    hoaDon.xuat();

    return 0;
}
