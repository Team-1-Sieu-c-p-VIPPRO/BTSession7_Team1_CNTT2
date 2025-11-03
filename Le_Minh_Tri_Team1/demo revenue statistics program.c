#include <stdio.h>

#define thangs 12

// Ham de tinh tien lai cho 1 thang
void tinhlaithang(double von[], double thu[], double lai [], int thang) {
	lai[thang] = thu[thang] - von[thang];
}

// Ham hien thi trang lai/lo
void trangthailai(double giatrilai) {
	if (giatrilai > 0) {
		printf("Trang thai: loi\n");
	} else if (giatrilai < 0) {
		printf("Trang thai: lo\n");
	} else {
		printf("Trang thai hoa von (khong loi cung khonng lai)\n");
	}
}

int main() {
	double von[thangs] = {0}; 		// Von tung thang
	double tongthu[thangs] = {0}; 	// Tong thu nhap tung thang
	double lai[thangs] = {0};		// Lai tung thang
	
	int choice;
	
	do {
		printf("\n=============== MENU QUAN LY DOANG THU NAM ===============\n");
		printf("1. Chinh sua thong tin 1 thang\n");
		printf("2. Xem thong tin tien lai 1 thang\n");
		printf("3. Tinh tong doanh thu ca nam\n");
		printf("4. Thoat\n");
		printf("------------------------------------------------------------\n");
		printf("Moi ban chon chuc nang (1 - 4): ");
		
		if (scanf("%d", &choice) != 1) {
			printf("Nhap khong hop le! Vui long nhap so.\n");
			while(getchar() != '\n'); // Xoa bo dem
			continue;
		}
		
		switch (choice) {
		case 1: {
			// chinh sua thong tin thang
			int thang;
			int subchoice;
			double newvalue;
			
			printf("\n--- CHINH SUA THONG TIN THANG ---\n");
			printf("Nhap thang muon chinh sua (1 - 12): ");
			if (scanf("%d", &thang) != 1) {
				printf("Nhap khong hop le!\n");
				while (getchar() != '\n');
				break;
			}
			
			if (thang < 1 || thang > 12) {
				printf("Thang khong hop le! Chi duoc nhap tu 1 den 12.\n");
				break;
			}
			
			// Doi ve chi so mang [0..11]	
			thang = thang - 1;
			
			do {
				printf("\n---THANG %d ---\n", thang + 1);
				printf("1. Chinh sua von (hien tai: %.2lf)\n", von[thang]);
				printf("2. Chinh sua tong thu nhap (hien tai: %.2lf)\n", tongthu[thang]);
				printf("3. Thoat ve menu chinh\n");
				printf("Chon (1 - 3): ");
				
				if (scanf("%d", &subchoice) != 1) {
					printf("Nhap khong hop le!\n");
					while (getchar() != '\n');
					subchoice = 3; // ep thoat de tranh ket
				}
				
				switch (subchoice) {
				case 1:
					printf("Nhap von moi (>= 0): ");
					if (scanf("%d", &newvalue) != 1) {
						printf("Nhap khong hop le!\n");
						while (getchar() != '\n');
						break;
					}
					if(newvalue < 0) {
						printf("Von khong duoc am!\n");
						break;
					}
					von[thang] = newvalue;
					tinhlaithang(von, tongthu, lai, thang);
					printf("Cap nhat von thanh cong. Lai thang %d = %.2lf\n", thang + 1, lai[thang]);
					break;
				
				case 2:
					printf("Nhap tong thu nhap moi (>= 0): ");
					if (scanf("%lf", &newvalue) != 1) {
						printf("Nhap khong hop le!\n");
						while (getchar() != '\n');
						break;
					}
					tongthu[thang] = newvalue;
					tinhlaithang(von, tongthu, lai, thang);
					printf("Cap nhat tong thu nhap thanh cong. Lai thang %d = %.2lf\n", thang + 1, lai[thang]);
					break;
					
				case 3:
					printf("Thoat chinh sua thang %d.\n", thang + 1);
					break;
					
				default:
					printf("Thoat chinh sua thang %d.\n", thang + 1);
					break;
				}
			} while (subchoice != 3);
			
			break;
		}
		
		case 2: {
			// Xem lai cua 1 thang 
			int thangxem;
			printf("--- XEM TIEN LAI THEO THANG ---\n");
			printf("Nhap thang muon xem (1 - 12): ");
			if (scanf("%d", &thangxem) != 1) {
				printf("Nhap khong hop le!\n");
				while (getchar() != '\n');
				break;
			}
			
			if (thangxem < 1 || thangxem > 12) {
				printf("Thang khong hop le! Chi duoc nhap tu 1 den 12.\n");
				break;
			}
			
			thangxem = thangxem - 1;
			
			// Lai da duoc cap nhat moi lan sua nen chi can in ra
			printf("\nThang %d\n", thangxem + 1);
			printf("Von           : %.2lf\n", von[thangxem]);
			printf("Tong thu nhap : %.2lf\n", tongthu[thangxem]);
			printf("Tien lai      : %.2lf\n", lai[thangxem]);
			trangthailai(lai[thangxem]);
			
			break;
		}
		
		case 3: {
			// Tinh tong doanh thu ca nam
			double tongdoanhthunam = 0;
			int i;
			for (i = 0; i < thangs; i++) {
				tongdoanhthunam += tongthu[i];
			}
			
			printf("\n--- TONG DOANH THU CA NAM ---\n");
			printf("Tong doanh thu (tong tat ca 12 thang): %.2lf\n", tongdoanhthunam);
			break;
		}
		
		case 4:
			printf("Tam biet!\n");
			break;
			
		default:
			printf("Lua chon khong hop le! Vui long chon 1-4.\n");
			break;		
		}
	} while (choice != 4);
	
	return 0;
}
