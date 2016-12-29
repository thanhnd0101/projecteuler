#include "xuly.h"

void nhap_sv(sinhvien &sv)
{
		printf("MSSV: ");
		scanf_s("%d%*c",&sv.mssv);
		printf("Ho: ");
		gets_s(sv.ho);
		printf("Ten lot: ");
		gets_s(sv.tenlot);
		printf("Ten: ");
		gets_s(sv.ten);
		printf("CMND: ");
		scanf_s("%d",&sv.cmnd);
		printf("Ngay thang nam sinh: ");
		scanf_s("%d %d %d", &sv.ngays.ngaysinh, &sv.ngays.thangsinh, &sv.ngays.namsinh);
		printf("Gioi tinh:(1 la nam, 0 la nu) ");
		scanf_s("%d%*c",&sv.gioit);
		printf("Dia chi thuong tru: ");
		gets_s(sv.diachi);
		printf("Diem trung binh: ");
		scanf_s("%f",&sv.diemtb);
}
void xuat_sv(sinhvien sv)
{
	printf("MSSV: %d\n", sv.mssv);
	printf("Ho: ");
	puts(sv.ho);
	printf("Ten lot: ");
	puts(sv.tenlot);
	printf("Ten: ");
	puts(sv.ten);
	printf("CMND: %d\n",sv.cmnd);
	printf("Ngay thang nam sinh: %d %d %d\n", sv.ngays.ngaysinh, sv.ngays.thangsinh, sv.ngays.namsinh);
	{
		printf("Gioi tinh: ");
		if (sv.gioit == nam) printf("Nam\n");
		else printf("Nu.\n");
	}
	printf("Dia chi thuong tru: ");
	puts(sv.diachi);
	printf("Diem trung binh: %f\n", sv.diemtb);
	printf("Email: ");
	{
		int k = 2;
		sv.email[0] = sv.ho[0];
		sv.email[1] = sv.tenlot[0];
		int len = strlen(sv.ten);
		for (int j = 0; j < len; j++)
		{
			sv.email[k++] = sv.ten[j];
		}
		sv.email[k] = '\0';
		strcat(sv.email, "@student.hcmus.edu.vn");
	}
	puts(sv.email);
	printf("Nam tuoi: ");
	{
		switch (sv.ngays.namsinh%12)
		{
		case (than) :
			printf("Nam Than\n");
			break;
		case (dau) :
			printf("Nam Dau\n");
			break;
		case (tuat) :
			printf("Nam Tuat\n");
			break;
		case (hoi) :
			printf("Nam Hoi\n");
			break;
		case (ty) :
			printf("Nam ty\n");
			break;
		case (suu) :
			printf("Nam Suu\n");
			break;
		case (dan) :
			printf("Nam dan\n");
			break;
		case (meo) :
			printf("Nam Meo\n");
			break;
		case (thin) :
			printf("Nam Thin\n");
			break;
		case (ty5) :
			printf("Nam Ty.\n");
			break;
		case (ngo) :
			printf("Nam Ngo\n");
			break;
		case (mui) :
			printf("Nam Mui\n");
			break;
		}
	}
}
void nhap_ds(sinhvien sv[50], int &n)
{
	printf("So luong sinh vien: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("**********\n");
		printf("Nhap sinh vien thu %d\n", i + 1);
		nhap_sv(sv[i]);
	}
}
void xuat_ds(sinhvien sv[50], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("------------\n");
		printf("Sinh vien thu %d\n",i+1);
		xuat_sv(sv[i]);
	}
}
sinhvien tb_caonhat(sinhvien sv[50], int n)
{
	sinhvien max;
	max.diemtb= sv[0].diemtb;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb>max.diemtb)
			max = sv[i];
	}
	return max;
}
sinhvien tim_sv(sinhvien sv[50], int mssv, int n,int &flag)
{
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv == mssv) {
			flag = 1;
			return sv[i];
		}

	}
}
sinhvien so_sanh(sinhvien sv[50], int n, char s[50], int &flag)
{
	char tam[50];
	for (int i = 0; i < n; i++)
	{
		strcpy(tam, sv[i].ho);
		strcpy(tam," ");
		strcat(tam, sv[i].tenlot);
		strcpy(tam, " ");
		strcat(tam, sv[i].ten);
		if (strcmp(tam, s) == 0)
		{
			flag = 1;
			return sv[i];
		}
	}
}
bool sv_duoi_tb(sinhvien sv)
{
	if (sv.diemtb < 5) return true;
	return false;
}
void ds_duoi_tb(sinhvien sv[50], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (sv_duoi_tb(sv[i]) == true)
		{
			printf("``````````````````");
			xuat_sv(sv[i]);
		}
	}
}
void xeploai(sinhvien sv[50], int n)
{
	int yeu = 0, tb = 0, kha = 0, gioi = 0;
	printf("Danh sach hoc sinh xep loai yeu: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb < 5)
		{
			xuat_sv(sv[i]);
			printf("\n");
			yeu = 1;
		}
	}
	if (yeu == 0) printf("Khong co sinh vien xep loai yeu.\n");
	printf("Danh sach hoc sinh xep loai trung binh: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb < 6.5 && sv[i].diemtb>=5)
		{
			xuat_sv(sv[i]);
			printf("\n");
			tb = 1;
		}
	}
	if (tb == 0) printf("Khong co sinh vien xep loai trung binh.\n");
	printf("Danh sach hoc sinh xep loai kha: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb < 8 && sv[i].diemtb>6.5)
		{
			xuat_sv(sv[i]);
			printf("\n");
			kha = 1;
		}
	}
	if (kha == 0) printf("Khong co sinh vien xep loai kha.\n");
	printf("Danh sach hoc sinh xep loai gioi: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb <= 10 && sv[i].diemtb >= 8)
		{
			xuat_sv(sv[i]);
			printf("\n");
			gioi = 1;
		}
	}
	if (gioi == 0) printf("Khong co sinh vien xep loai gioi.\n");
}
void xep_khoahoc(sinhvien sv[50], int n)
{
	int k12 = 0, k13 = 0, k14 = 0, k15 = 0, k16 = 0;
	printf("Sinh vien khoa 2012: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv / 100000 == 12)
		{
			xuat_sv(sv[i]);
			printf("\n");
			k12 = 1;
		}
	}
	if (k12 == 0) printf("Khong co sinh vien khoa 2012.\n");
	printf("Sinh vien khoa 2013: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv / 100000 == 13)
		{
			xuat_sv(sv[i]);
			printf("\n");
			k12 = 1;
		}
	}
	if (k12 == 0) printf("Khong co sinh vien khoa 2013.\n");
	printf("Sinh vien khoa 2014: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv / 100000 == 14)
		{
			xuat_sv(sv[i]);
			printf("\n");
			k12 = 1;
		}
	}
	if (k12 == 0) printf("Khong co sinh vien khoa 2014.\n");
	printf("Sinh vien khoa 2015: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv / 100000 == 15)
		{
			xuat_sv(sv[i]);
			printf("\n");
			k12 = 1;
		}
	}
	if (k12 == 0) printf("Khong co sinh vien khoa 2015.\n");
	printf("Sinh vien khoa 2016: \n");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv / 100000 == 16)
		{
			xuat_sv(sv[i]);
			printf("\n");
			k12 = 1;
		}
	}
	if (k12 == 0) printf("Khong co sinh vien khoa 2016.\n");
}
void them_sv(sinhvien sv[50], int &n, int &m)
{
	printf("So luong sinh vien can them: ");
	scanf_s("%d%*c", &m);
	for (int i = 0; i < m; i++)
	{
		printf("**********\n");
		printf("Nhap sinh vien thu %d\n", i + n+1);
		nhap_sv(sv[i+n]);
	}
	n += m;
}
void xoa_sv(sinhvien sv[50], int &n, int &vt)
{
	printf("Ban muon xoa sinh vien thu : ");
	scanf_s("%d", &vt);
	for (int i = vt-1; i < n-1; i++)
	{
		sv[i] = sv[i + 1];
	}
	n--;
}
void ds_nu(sinhvien sv[50], int n)
{
	int ktnu = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].gioit == nu)
		{
			printf("--------------\n");
			xuat_sv(sv[i]);
			ktnu = 1;
		}
	}
	if (ktnu == 0) printf("Khong co sinh vien nu.\n");
}
void ds_nam(sinhvien sv[50], int n)
{
	int ktnam = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].gioit == nam)
		{
			printf("--------------\n");
			xuat_sv(sv[i]);
			ktnam = 1;
		}
	}
	if (ktnam == 0) printf("Khong co sinh vien nam.\n");
}
void hieu_chinh(sinhvien sv[50], int mssv, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv == mssv) {
			flag = 1;
			nhap_sv(sv[i]);
		}
	}
	if (flag == 0) printf("Khong co sinh vien trung khop.\n");
}
void sap_xep_tangmssv(sinhvien sv[50], int n)
{
	sinhvien tam;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sv[j].mssv < sv[i].mssv)
			{
				tam = sv[j];
				sv[j] = sv[i];
				sv[i] = tam;
			}
		}
	}
}
void sap_xep_diemgiam(sinhvien sv[50], int n)
{
	sinhvien tam;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sv[j].diemtb > sv[i].diemtb)
			{
				tam = sv[j];
				sv[j] = sv[i];
				sv[i] = tam;
			}
		}
	}
}
void capnhat(sinhvien sv[50], int &n,int &mssv)
{
	sinhvien timsv;
	int flag1=0,m;
	printf("Nhap mssv: ");
	scanf_s("%d%*c", &mssv);
	timsv = tim_sv(sv, mssv, n, flag1);
	if (flag1 == 1)
	{
		hieu_chinh(sv, mssv, n);
		sap_xep_tangmssv(sv, n);
	}
	else
	{
		them_sv(sv, n, m);
		sap_xep_tangmssv(sv, n);
	}
}
sinhvien tuoi_lonnhat(sinhvien sv[50], int n)
{
	sinhvien max;
	max = sv[0];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sv[j].ngays.namsinh > max.ngays.namsinh)
			{
				max = sv[j];
			}
		}
	}
	return max;
}
sinhvien tim_cmnd(sinhvien sv[50], int n, int cmnd,int &flag)
{
	for (int i = 0; i < n; i++)
	{
		if (sv[i].cmnd == cmnd) {
			flag = 1;
			return sv[i];
		}
	}
}
bool sv_que_tphcm(sinhvien sv)
{
	char tam[10];
	int k = 0;
	
		for (int j = strlen(sv.diachi) - 1; j > strlen(sv.diachi) - 7; j--)
		{
			tam[k++] = sv.diachi[j];
		}
		if (strcmp(tam,"TP.HCM") == 0) return true;
		return false;
}
void ds_que_tphcm(sinhvien sv[50], int n, sinhvien ds_tphcm[50], int &k)
{
	for (int i = 0; i < n; i++)
	{
		if (sv_que_tphcm(sv[i]) == true)
		{
			ds_tphcm[k++] = sv[i];
		}
	}
}
void chuoi_thanh_so(int &n, char s[50])
{
	int len = strlen(s);
	n = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
		{
			n = n * 10 + (s[i] - '0');
		}

	}
	if (s[0] == '-')
		n = -n;
}
void docfile(sinhvien *&ds,int &n, FILE *danhsach)
{
	char s[256];
	char *string;
	fscanf(danhsach, "%d%*c", &n);
	ds = (sinhvien*)malloc(n * sizeof(sinhvien));
	for (int i = 0; i < n; i++)
	{
		
		fgets(s, sizeof(s), danhsach);// Lay vao chuoi thong tin sinh vien
		string = strtok(s, "|");//lay mssv
		chuoi_thanh_so(ds[i].mssv, string);
		string = strtok(NULL, "|");// lay ho
		strcpy(ds[i].ho, string);
		string = strtok(NULL, "|");// lay ten lot
		strcpy(ds[i].tenlot, string);
		string = strtok(NULL, "|");// lay ten
		strcpy(ds[i].ten, string);
		string = strtok(NULL, "|");// lay chung minh nhan dan
		chuoi_thanh_so(ds[i].cmnd, string);
		string = strtok(NULL, "|");// Lay ngay sinh
		chuoi_thanh_so(ds[i].ngays.ngaysinh, string);
		string = strtok(NULL, "|");// Lay thang sinh
		chuoi_thanh_so(ds[i].ngays.thangsinh, string);
		string = strtok(NULL, "|");// Lay nam sinh
		chuoi_thanh_so(ds[i].ngays.namsinh, string);
		{
			string = strtok(NULL, "|");// Lay gioi tinh
			if (*string == '1') ds[i].gioit = nam;
			if (*string == '0') ds[i].gioit = nu;
		}
		string = strtok(NULL, "|");//lay dia chi
		strcpy(ds[i].diachi, string);
		string = strtok(NULL, "\n");// lay diem
		chuoi_thanh_so(ds[i].diemtb, string);
	}
}
int thongke_khoa(sinhvien *ds, int n, int khoa)
{
	int count=0;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].mssv / 100000 == khoa)
			count++;
	}
	return count;
}
void inthongke_khoa(sinhvien *ds, int n)
{
	printf("Thong ke so luong sinh vien theo khoa.\n");
	printf("|%-5s|%-10s|%-10s|\n", "STT", "Khoa", "So luong");
	printf("|%-5d|%-10d|%-10d|\n", 1, 2013, thongke_khoa(ds, n, 13));
	printf("|%-5d|%-10d|%-10d|\n", 2, 2014, thongke_khoa(ds, n, 14));
	printf("|%-5d|%-10d|%-10d|\n", 3, 2015, thongke_khoa(ds, n, 15));
	printf("|%-5d|%-10d|%-10d|\n", 4, 2016, thongke_khoa(ds, n, 16));
}
int thongke_ho(sinhvien *ds, int n, char ho[20])
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ds[i].ho,ho)==0)
			count++;
	}
	return count;
}
void inthongke_ho(sinhvien *ds,int n)
{
	printf("Thong ke so luong sinh vien theo ho.\n");
	printf("|%-5s|%-10s|%-10s|\n", "STT", "Ho", "So luong");
	printf("|%-5d|%-10s|%-10d|\n", 1, "Ho", thongke_ho(ds, n,"Ho"));
	printf("|%-5d|%-10s|%-10d|\n", 2, "Tran", thongke_ho(ds, n,"Tran"));
	printf("|%-5d|%-10s|%-10d|\n", 3, "Tang", thongke_ho(ds, n,"Tang"));
	printf("|%-5d|%-10s|%-10d|\n", 4, "Nguyen", thongke_ho(ds, n,"Nguyen"));
}
int thongke_tinh(sinhvien *ds, int n, char tinh[20])
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ds[i].diachi, tinh) == 0)
			count++;
	}
	return count;
}
void inthongke_tinh(sinhvien *ds, int n)
{
	printf("Thong ke so luong sinh vien theo tinh/TP.\n");
	printf("|%-5s|%-10s|%-10s|\n", "STT", "Tinh/TP", "So luong");
	printf("|%-5d|%-10s|%-10d|\n", 1, "Quang Ngai", thongke_tinh(ds, n, "Quang Ngai"));
	printf("|%-5d|%-10s|%-10d|\n", 2, "Dong Thap", thongke_tinh(ds, n, "Dong Thap"));
	printf("|%-5d|%-10s|%-10d|\n", 3, "Lam Dong", thongke_tinh(ds, n, "Lam Dong"));
	printf("|%-5d|%-10s|%-10d|\n", 4, "TPHCM", thongke_tinh(ds, n, "TPHCM"));
	printf("So hoi dong huong:%d\n",thongke_tinh(ds, n, "Quang Ngai") + thongke_tinh(ds, n, "Dong Thap") + thongke_tinh(ds, n, "Lam Dong"));
}
int thongke_thang(sinhvien *ds, int n, int thang)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].ngays.thangsinh==thang)
			count++;
	}
	return count;
}
void inthongke_thang(sinhvien *ds, int n)
{
	printf("Thong ke so luong sinh vien theo thang sinh.\n");
	printf("|%-6s|%-10s|\n", "Thang","So luong");
	printf("|%-6d|%-10d|\n", 1, thongke_thang(ds, n, 1));
	printf("|%-6d|%-10d|\n", 2, thongke_khoa(ds, n, 2));
	printf("|%-6d|%-10d|\n", 3, thongke_khoa(ds, n, 3));
	printf("|%-6d|%-10d|\n", 4, thongke_khoa(ds, n, 4));
	printf("|%-6d|%-10d|\n", 5, thongke_thang(ds, n, 5));
	printf("|%-6d|%-10d|\n", 6, thongke_thang(ds, n, 6));
	printf("|%-6d|%-10d|\n", 7, thongke_thang(ds, n, 7));
	printf("|%-6d|%-10d|\n", 8, thongke_thang(ds, n, 8));
	printf("|%-6d|%-10d|\n", 9, thongke_thang(ds, n, 9));
	printf("|%-6d|%-10d|\n", 10, thongke_thang(ds, n, 10));
	printf("|%-6d|%-10d|\n", 11, thongke_thang(ds, n, 11));
	printf("|%-6d|%-10d|\n", 12, thongke_thang(ds, n, 12));

}