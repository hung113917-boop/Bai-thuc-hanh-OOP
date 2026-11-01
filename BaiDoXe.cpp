#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

class Vehicle {
private:
	int vehicleID;
	string vehicleType;
	int entryTime;
	int parkingDuration;
	double parkingFee;
	bool isOccupied;

public:
	Vehicle() {
		vehicleID = 0;
		vehicleType = "";
		entryTime = 0;
		parkingDuration = 1;
		parkingFee = 0;
		isOccupied = false;
	}

	Vehicle(int id, const string& type, int time, int duration) {
		vehicleID = id;
		vehicleType = normalizeType(type);
		entryTime = time;
		parkingDuration = duration;
		parkingFee = 0;
		isOccupied = true;
		calculateFee();
	}

	static string normalizeType(const string& type) {
		string lower = type;
		for (size_t i = 0; i < lower.length(); i++)
			lower[i] = static_cast<char>(tolower(static_cast<unsigned char>(lower[i])));

		if (lower == "car") return "Car";
		if (lower == "motorcycle") return "Motorcycle";
		if (lower == "bicycle") return "Bicycle";
		return "";
	}

	int getVehicleID() const { return vehicleID; }
	string getVehicleType() const { return vehicleType; }
	int getEntryTime() const { return entryTime; }
	int getParkingDuration() const { return parkingDuration; }
	double getParkingFee() const { return parkingFee; }
	bool getIsOccupied() const { return isOccupied; }

	void setVehicleID(int id) { vehicleID = id; }
	void setVehicleType(const string& type) { vehicleType = normalizeType(type); }
	void setEntryTime(int time) { entryTime = time; }
	void setParkingDuration(int duration) { parkingDuration = duration; }
	void setParkingFee(double fee) { parkingFee = fee; }
	void setIsOccupied(bool occupied) { isOccupied = occupied; }

	void calculateFee() {
		double rate = 0;

		if (vehicleType == "Car")
			rate = 6.0;
		else if (vehicleType == "Motorcycle")
			rate = 4.0;
		else if (vehicleType == "Bicycle")
			rate = 2.0;

		parkingFee = 0;

		for (int i = 0; i < parkingDuration; i++) {
			if (i < 2) {
				bool peak = (entryTime >= 6 && entryTime < 10) ||
					(entryTime >= 15 && entryTime < 19);
				if (peak)
					parkingFee += rate * 1.30;
				else
					parkingFee += rate * 0.95;
			}
			else {
				parkingFee += rate * 0.90;
			}
		}
	}

	void display() const {
		cout << "Ma xe: " << vehicleID << endl;
		cout << "Loai xe: " << vehicleType << endl;
		cout << "Gio vao: " << entryTime << endl;
		cout << "Thoi luong do: " << parkingDuration << " gio" << endl;
		cout << fixed << setprecision(2);
		cout << "Phi do xe: " << parkingFee << " VND" << endl;
	}
};

class ParkingLot {
private:
	int parkID;
	char size;
	Vehicle vehicle1;
	Vehicle vehicle2;
	Vehicle vehicle3;
	bool hasVehicle1;
	bool hasVehicle2;
	bool hasVehicle3;

public:
	ParkingLot() {
		parkID = 0;
		size = 'S';
		hasVehicle1 = false;
		hasVehicle2 = false;
		hasVehicle3 = false;
	}

	ParkingLot(int id, char s) {
		parkID = id;
		size = static_cast<char>(toupper(static_cast<unsigned char>(s)));
		hasVehicle1 = false;
		hasVehicle2 = false;
		hasVehicle3 = false;
	}

	int getParkID() const { return parkID; }
	char getSize() const { return size; }
	bool getHasVehicle1() const { return hasVehicle1; }
	bool getHasVehicle2() const { return hasVehicle2; }
	bool getHasVehicle3() const { return hasVehicle3; }
	Vehicle getVehicle1() const { return vehicle1; }
	Vehicle getVehicle2() const { return vehicle2; }
	Vehicle getVehicle3() const { return vehicle3; }

	int getCapacity() const {
		if (size == 'S') return 1;
		if (size == 'M') return 2;
		if (size == 'L') return 3;
		return 0;
	}

	int getVehicleCount() const {
		int count = 0;
		if (hasVehicle1) count++;
		if (hasVehicle2) count++;
		if (hasVehicle3) count++;
		return count;
	}

	bool containsVehicle(int id) const {
		if (hasVehicle1 && vehicle1.getVehicleID() == id) return true;
		if (hasVehicle2 && vehicle2.getVehicleID() == id) return true;
		if (hasVehicle3 && vehicle3.getVehicleID() == id) return true;
		return false;
	}

	bool addVehicle(const Vehicle& v) {
		if (getVehicleCount() >= getCapacity() || containsVehicle(v.getVehicleID()))
			return false;

		if (!hasVehicle1) {
			vehicle1 = v;
			hasVehicle1 = true;
		}
		else if (!hasVehicle2 && getCapacity() >= 2) {
			vehicle2 = v;
			hasVehicle2 = true;
		}
		else if (!hasVehicle3 && getCapacity() >= 3) {
			vehicle3 = v;
			hasVehicle3 = true;
		}
		else {
			return false;
		}

		return true;
	}

	bool removeVehicle(int id) {
		if (hasVehicle1 && vehicle1.getVehicleID() == id) {
			vehicle1 = vehicle2;
			hasVehicle1 = hasVehicle2;
			vehicle2 = vehicle3;
			hasVehicle2 = hasVehicle3;
			vehicle3 = Vehicle();
			hasVehicle3 = false;
			return true;
		}

		if (hasVehicle2 && vehicle2.getVehicleID() == id) {
			vehicle2 = vehicle3;
			hasVehicle2 = hasVehicle3;
			vehicle3 = Vehicle();
			hasVehicle3 = false;
			return true;
		}

		if (hasVehicle3 && vehicle3.getVehicleID() == id) {
			vehicle3 = Vehicle();
			hasVehicle3 = false;
			return true;
		}

		return false;
	}

	void displaySummary() const {
		cout << "Bai " << parkID
			<< " | Kich thuoc: " << size
			<< " | So xe: " << getVehicleCount()
			<< "/" << getCapacity() << endl;
	}

	void displayLotInfo() const {
		cout << "\nMa bai: " << parkID
			<< "\nKich thuoc: " << size
			<< "\nSo xe: " << getVehicleCount()
			<< "/" << getCapacity() << endl;

		if (hasVehicle1) {
			cout << "\nXe thu nhat:\n";
			vehicle1.display();
		}
		if (hasVehicle2) {
			cout << "\nXe thu hai:\n";
			vehicle2.display();
		}
		if (hasVehicle3) {
			cout << "\nXe thu ba:\n";
			vehicle3.display();
		}
	}

	void displayVehiclesByType(const string& type, bool& found) const {
		if (hasVehicle1 && vehicle1.getVehicleType() == type) {
			cout << "\nBai do " << parkID << ":\n";
			vehicle1.display();
			found = true;
		}
		if (hasVehicle2 && vehicle2.getVehicleType() == type) {
			cout << "\nBai do " << parkID << ":\n";
			vehicle2.display();
			found = true;
		}
		if (hasVehicle3 && vehicle3.getVehicleType() == type) {
			cout << "\nBai do " << parkID << ":\n";
			vehicle3.display();
			found = true;
		}
	}
};

class SystemInterface {
private:
	ParkingLot parkingLot1;
	ParkingLot parkingLot2;
	ParkingLot parkingLot3;
	bool hasLot1;
	bool hasLot2;
	bool hasLot3;

	int readInt(const string& prompt) const {
		int x;
		while (true) {
			cout << prompt;
			if (cin >> x) {
				cin.ignore(10000, '\n');
				return x;
			}
			if (cin.eof()) exit(0);
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Vui long nhap so nguyen!\n";
		}
	}

	bool lotIDExists(int id) const {
		return (hasLot1 && parkingLot1.getParkID() == id) ||
			(hasLot2 && parkingLot2.getParkID() == id) ||
			(hasLot3 && parkingLot3.getParkID() == id);
	}

	bool vehicleIDExists(int id) const {
		return (hasLot1 && parkingLot1.containsVehicle(id)) ||
			(hasLot2 && parkingLot2.containsVehicle(id)) ||
			(hasLot3 && parkingLot3.containsVehicle(id));
	}

	void addFee(const Vehicle& v,
		double& carTotal, int& carCount,
		double& motorcycleTotal, int& motorcycleCount,
		double& bicycleTotal, int& bicycleCount) const {
		if (v.getVehicleType() == "Car") {
			carTotal += v.getParkingFee();
			carCount++;
		}
		else if (v.getVehicleType() == "Motorcycle") {
			motorcycleTotal += v.getParkingFee();
			motorcycleCount++;
		}
		else if (v.getVehicleType() == "Bicycle") {
			bicycleTotal += v.getParkingFee();
			bicycleCount++;
		}
	}

	void accumulateLot(const ParkingLot& lot,
		double& carTotal, int& carCount,
		double& motorcycleTotal, int& motorcycleCount,
		double& bicycleTotal, int& bicycleCount) const {
		if (lot.getHasVehicle1())
			addFee(lot.getVehicle1(), carTotal, carCount, motorcycleTotal,
				motorcycleCount, bicycleTotal, bicycleCount);
		if (lot.getHasVehicle2())
			addFee(lot.getVehicle2(), carTotal, carCount, motorcycleTotal,
				motorcycleCount, bicycleTotal, bicycleCount);
		if (lot.getHasVehicle3())
			addFee(lot.getVehicle3(), carTotal, carCount, motorcycleTotal,
				motorcycleCount, bicycleTotal, bicycleCount);
	}

	void printAverages(double carTotal, int carCount,
		double motorcycleTotal, int motorcycleCount,
		double bicycleTotal, int bicycleCount) const {
		cout << fixed << setprecision(2);

		if (carCount > 0)
			cout << "  Car: " << carTotal / carCount << " VND (" << carCount << " xe)\n";
		else
			cout << "  Car: Chua co du lieu\n";

		if (motorcycleCount > 0)
			cout << "  Motorcycle: " << motorcycleTotal / motorcycleCount
			<< " VND (" << motorcycleCount << " xe)\n";
		else
			cout << "  Motorcycle: Chua co du lieu\n";

		if (bicycleCount > 0)
			cout << "  Bicycle: " << bicycleTotal / bicycleCount
			<< " VND (" << bicycleCount << " xe)\n";
		else
			cout << "  Bicycle: Chua co du lieu\n";
	}

	void reportLot(const ParkingLot& lot) const {
		double carTotal = 0, motorcycleTotal = 0, bicycleTotal = 0;
		int carCount = 0, motorcycleCount = 0, bicycleCount = 0;

		accumulateLot(lot, carTotal, carCount, motorcycleTotal,
			motorcycleCount, bicycleTotal, bicycleCount);

		cout << "\nBai do " << lot.getParkID()
			<< " (kich thuoc " << lot.getSize() << ")"
			<< " - So xe: " << lot.getVehicleCount() << endl;
		printAverages(carTotal, carCount, motorcycleTotal,
			motorcycleCount, bicycleTotal, bicycleCount);
	}

public:
	SystemInterface() {
		hasLot1 = false;
		hasLot2 = false;
		hasLot3 = false;
	}

	void createLot() {
		if (hasLot1 && hasLot2 && hasLot3) {
			cout << "He thong da co toi da 3 bai do!\n";
			return;
		}

		int id = readInt("Nhap ma bai do: ");

		if (lotIDExists(id)) {
			cout << "Ma bai do da ton tai!\n";
			return;
		}

		char size;
		cout << "Nhap kich thuoc (S/M/L): ";
		cin >> size;
		cin.ignore(10000, '\n');
		size = static_cast<char>(toupper(static_cast<unsigned char>(size)));

		if (size != 'S' && size != 'M' && size != 'L') {
			cout << "Kich thuoc khong hop le!\n";
			return;
		}

		if (!hasLot1) {
			parkingLot1 = ParkingLot(id, size);
			hasLot1 = true;
		}
		else if (!hasLot2) {
			parkingLot2 = ParkingLot(id, size);
			hasLot2 = true;
		}
		else {
			parkingLot3 = ParkingLot(id, size);
			hasLot3 = true;
		}

		cout << "Tao bai do thanh cong!\n";
	}

	void addVehicleToLot() {
		int id = readInt("Nhap ma xe: ");

		if (vehicleIDExists(id)) {
			cout << "Ma xe da ton tai!\n";
			return;
		}

		string typeInput;
		cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
		cin >> typeInput;
		cin.ignore(10000, '\n');

		string type = Vehicle::normalizeType(typeInput);
		if (type == "") {
			cout << "Loai xe khong hop le!\n";
			return;
		}

		int time = readInt("Nhap gio vao (0-23): ");
		if (time < 0 || time > 23) {
			cout << "Gio vao khong hop le!\n";
			return;
		}

		int duration = readInt("Nhap thoi luong do (1-23): ");
		if (duration < 1 || duration > 23) {
			cout << "Thoi luong do khong hop le!\n";
			return;
		}

		if (time + duration > 24) {
			cout << "Xe phai roi bai trong cung mot ngay (gio vao + thoi luong <= 24)!\n";
			return;
		}

		Vehicle v(id, type, time, duration);

		if (hasLot1 && parkingLot1.addVehicle(v)) {
			cout << "Da them xe vao bai " << parkingLot1.getParkID() << ".\n";
		}
		else if (hasLot2 && parkingLot2.addVehicle(v)) {
			cout << "Da them xe vao bai " << parkingLot2.getParkID() << ".\n";
		}
		else if (hasLot3 && parkingLot3.addVehicle(v)) {
			cout << "Da them xe vao bai " << parkingLot3.getParkID() << ".\n";
		}
		else {
			cout << "Khong co bai do con cho phu hop!\n";
			return;
		}

		cout << fixed << setprecision(2)
			<< "Phi do xe: " << v.getParkingFee() << " VND\n";
	}

	void deleteLot() {
		int id = readInt("Nhap ma bai do can xoa: ");

		if (hasLot1 && parkingLot1.getParkID() == id) {
			parkingLot1 = ParkingLot();
			hasLot1 = false;
			cout << "Da xoa bai do!\n";
		}
		else if (hasLot2 && parkingLot2.getParkID() == id) {
			parkingLot2 = ParkingLot();
			hasLot2 = false;
			cout << "Da xoa bai do!\n";
		}
		else if (hasLot3 && parkingLot3.getParkID() == id) {
			parkingLot3 = ParkingLot();
			hasLot3 = false;
			cout << "Da xoa bai do!\n";
		}
		else {
			cout << "Khong tim thay bai do!\n";
		}
	}

	void removeVehicleFromLot() {
		int id = readInt("Nhap ma xe can lay ra: ");

		if (hasLot1 && parkingLot1.removeVehicle(id)) {
			cout << "Da lay xe ra khoi bai do!\n";
		}
		else if (hasLot2 && parkingLot2.removeVehicle(id)) {
			cout << "Da lay xe ra khoi bai do!\n";
		}
		else if (hasLot3 && parkingLot3.removeVehicle(id)) {
			cout << "Da lay xe ra khoi bai do!\n";
		}
		else {
			cout << "Khong tim thay xe!\n";
		}
	}

	void displayAllLots() const {
		if (!hasLot1 && !hasLot2 && !hasLot3) {
			cout << "He thong chua co bai do nao!\n";
			return;
		}
		if (hasLot1) parkingLot1.displaySummary();
		if (hasLot2) parkingLot2.displaySummary();
		if (hasLot3) parkingLot3.displaySummary();
	}

	void displaySpecificLot() const {
		int id = readInt("Nhap ma bai do: ");

		if (hasLot1 && parkingLot1.getParkID() == id)
			parkingLot1.displayLotInfo();
		else if (hasLot2 && parkingLot2.getParkID() == id)
			parkingLot2.displayLotInfo();
		else if (hasLot3 && parkingLot3.getParkID() == id)
			parkingLot3.displayLotInfo();
		else
			cout << "Khong tim thay bai do!\n";
	}

	void listVehiclesByType() const {
		string typeInput;
		cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
		cin >> typeInput;
		cin.ignore(10000, '\n');

		string type = Vehicle::normalizeType(typeInput);
		if (type == "") {
			cout << "Loai xe khong hop le!\n";
			return;
		}

		bool found = false;

		if (hasLot1) parkingLot1.displayVehiclesByType(type, found);
		if (hasLot2) parkingLot2.displayVehiclesByType(type, found);
		if (hasLot3) parkingLot3.displayVehiclesByType(type, found);

		if (!found)
			cout << "Khong tim thay xe thuoc loai nay!\n";
	}

	void parkingFeeReport() const {
		if (!hasLot1 && !hasLot2 && !hasLot3) {
			cout << "He thong chua co bai do nao!\n";
			return;
		}

		double carTotal = 0, motorcycleTotal = 0, bicycleTotal = 0;
		int carCount = 0, motorcycleCount = 0, bicycleCount = 0;

		if (hasLot1)
			accumulateLot(parkingLot1, carTotal, carCount, motorcycleTotal,
				motorcycleCount, bicycleTotal, bicycleCount);
		if (hasLot2)
			accumulateLot(parkingLot2, carTotal, carCount, motorcycleTotal,
				motorcycleCount, bicycleTotal, bicycleCount);
		if (hasLot3)
			accumulateLot(parkingLot3, carTotal, carCount, motorcycleTotal,
				motorcycleCount, bicycleTotal, bicycleCount);

		cout << "\n===== PHI DO XE TRUNG BINH TOAN HE THONG =====\n";
		printAverages(carTotal, carCount, motorcycleTotal,
			motorcycleCount, bicycleTotal, bicycleCount);

		cout << "\n===== CHI TIET THEO TUNG BAI DO =====";
		if (hasLot1) reportLot(parkingLot1);
		if (hasLot2) reportLot(parkingLot2);
		if (hasLot3) reportLot(parkingLot3);
	}

	void runMenu() {
		int choice;

		do {
			cout << "\n========== QUAN LY BAI DO XE ==========\n";
			cout << "1. Tao bai do xe moi\n";
			cout << "2. Them xe vao bai do\n";
			cout << "3. Xoa mot bai do xe\n";
			cout << "4. Lay xe ra khoi bai do\n";
			cout << "5. Hien thi danh sach tat ca bai do\n";
			cout << "6. Hien thi xe theo bai do\n";
			cout << "7. Liet ke xe theo loai phuong tien\n";
			cout << "8. Bao cao phi do xe trung binh\n";
			cout << "9. Thoat chuong trinh\n";
			choice = readInt("Nhap lua chon: ");

			switch (choice) {
			case 1: createLot(); break;
			case 2: addVehicleToLot(); break;
			case 3: deleteLot(); break;
			case 4: removeVehicleFromLot(); break;
			case 5: displayAllLots(); break;
			case 6: displaySpecificLot(); break;
			case 7: listVehiclesByType(); break;
			case 8: parkingFeeReport(); break;
			case 9: cout << "Da thoat chuong trinh!\n"; break;
			default: cout << "Lua chon khong hop le!\n";
			}
		} while (choice != 9);
	}
};

int main() {
	SystemInterface system;
	system.runMenu();
	return 0;
}