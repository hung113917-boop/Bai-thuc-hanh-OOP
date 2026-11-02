#include<strings>
#include<iostream>
#include<algorithm>
class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;
    double phi_do_xe;

public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg, double phi);
    int lay_gio_vao() {return gio_vao;}
    int lay_ma_xe() const { return ma_xe;};
    string lay_loai_xe() const {return loai_xe;} ;
    void tinh_phi() const { return phi_do_xe; };
    void hien_thi() const;
};
phuong_tien :: phuong_tien(){
	ma_xe = 0;
	loai_xe = "";
	gio_vao = 0;
	tg_do = 0;
	phi_do_xe = 0.0;
}
phuong_tien::phuong_tien(int ma, string loai, int gio, int tg,double phi){
	ma_xe = ma;
	loai_xe = loai;
	gio_vao = gio;
	tg_do = tg;
	phi_do_xe = phi;
}
void tinh_phi(){
	double tien = 0.0;
	string loaixe = loai_xe;
	if(loaixe == "car"){
		tien = 6.0;
	}
	if ( loaixe == "motorbike"){
		tien = 3.0;
	}
	if (loaixe == "bicycle" ){
		tien = 2.0;
	}
	tongPhi = 0.0;
	bool laGioCaoDiem  = (())
	for ( int i = 0; i < tg_do; i++){
		int tg_hientai = (gio_vao  + i - 1) %24;
		bool laGioCaoDiem  = (((tg_hientai >= 6) && (tg_hientai <= 9 )) ||((tg_hientai >= 15) && (tg_hientai <= 18)));
		if ( i < 2){
			if(laGioCaoDiem){
				tongPhi *= 1.30;
			}
			else{
				tongPhi *= 0.95;
			}
		}
	}
	tongPhi = phi_do_xe;	
}
void Xe::hienThi(){
	cout << "Ma xe: " << ma_xe << " Loai: " << loai_xe << " Gio vao: "
	<< gio_vao << " Thoi gian do: " << tg_do << " Phi Do Xe: "
	<< phi_do_xe;
};

class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;
    phuong_tien pt1, pt2, pt3;
    bool co1, co2, co3;

public:
    bai_xe();
    bai_xe(int ma, char kt);

    int lay_ma() const;
    bool them(phuong_tien v);
    bool xoa(int ma_xe);
    bool chua(int ma_xe) const;
    void hien_thi() const;
    bool co_loai(string loai, int& dem, double& tong) const;
};
bai_xe::bai_xe(){
	ma_bai = 0;
	kich_thuoc = "";
	co1 = false;
	co2 = false;
	co3 = false;
}
bai_xe::bai_xe(int ma, char kt){
	ma_bai = ma;
	kich_thuoc = kt;
	co1= false;
	co2 = false;
	co3 = false;	
}
bool bai_xe::them(phuong_tien v){
	if (kich_thuoc = "S"){
		if (!co1){
			pt1= v;
			co1 = true;
		}
	}
	else if( kich_thuoc = "M"){
		if(!co1){
			pt1 = v;
			co1 = true;
		}
		if(!co2){
			pt2 = v;
			co2 = true;
		}
	}
	else if (kich_thuoc = "L" ){
		if (!co1){
			pt1 = v;
			co1 = true;
		}
		if (!co2){
			pt2 = v;
			co2 = true;
		}
		if (!co3){
			pt3 = v;
			co3 = truel
		}
	}
}
bool bai_xe::xoa( int ma_xe){
	if (co1 && pt1.lay_ma_xe() == ma_xe){
		pt1 = phuong_tien();
		co1 = false;
		return true;
	}
	if (kich_thuoc != "S" && co2 && pt2.lay_ma_xe() == ma_xe){
		pt2 = phuong_tien();
		co2 = false;
		return true;
	}
	if (kich_thuoc == "L" && co3 && pt3.lay_ma_xe() == ma_xe){
		pt3 = phuong_tien();
		co3 = false;
		return true;
	}
}
void BaiDo::hien_thi() const {
	cout << "Ma bai do: " << ma_bai << " Kich thuoc: " << kich_thuoc << endl;
	int demxe = 0;
	if (co1){
		xe1.hienthi();
		demxe++;
	}
	if (co2){
		xe2.hienthi();
		demxe++;
	}
	if(co3){
		xe3.hienthi();
		demxe++;
	}
	if(demxe == 0){
		cout << "Bai dang trong";
	}
	else cout << "Trong bai co " << demxe <<"xe";
}
class SystemInterface {
private:
    bai_xe bai1, bai2, bai3;   // sau này dùng m?ng
    bool co1, co2, co3; //có bãi xe 1, 2, 3 hay chua? 

public:
    SystemInterface();
    void runMenu();// cho phép ng dung ch?n 1, 2, 3, 4, ...
    //1 t?o bãi, 2 thêm xe, 3 xoá bãi, 4 l?y xe ra (xoá xe), 5 hi?n thi, ...
};
