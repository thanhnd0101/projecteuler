#include "xuly.h"
#define max 50
int main()
{
	//sinhvien sv[max], timsv, sosanh;
	//int n, mssv, flag1 = 0, flag2 = 0, m, vt;
	//char s[50];
	//// Bai 1 
	//nhap_ds(sv,n);
	// Bai 2
	/*xuat_ds(sv,n);*/
	// Bai 3
	/*printf("Sinh vien co diem cao nhat: \n");
	xuat_sv(tb_caonhat(sv,n));*/
	// Bai 7
	/*printf("Nhap mssv cam tim: ");
	scanf_s("%d%*c", &mssv);
	timsv=tim_sv(sv,mssv,n,flag1);
	if (flag1 == 0) printf("Khong co sinh vien trung khop.\n");
	else xuat_sv(timsv);
	// Bai 8
	printf("Nhap ho ten sinh vien can tim: ");
	gets_s(s);
	sosanh=so_sanh(sv,n,s,flag2);
	if (flag2 == 0) printf("Khong co sinh vien trung khop.\n");
	else xuat_sv(sosanh);*/
	// Bai 4
	/*printf("Danh sach sinh vien duoi trung binh:\n");
	ds_duoi_tb(sv, n);*/
	// Bai 5
	/*printf("Xep loai sinh vien.\n");
	xeploai(sv, n);*/
	// Bai 6
	//printf("Xep loai sinh vien theo khoa hoc.\n");
	//xep_khoahoc(sv, n);
	// Bai 9
	/*printf("Them sinh vien vao danh sach.\n");
	them_sv(sv, n, m);
	xuat_ds(sv, n);*/
	// Bai 10
	/*printf("Xoa mot sinh vien.\n");
	xoa_sv(sv, n, vt);
	xuat_ds(sv, n);*/
	// Bai 11
	/*printf("\n");
	printf("Danh sach sinh vien nu.\n");
	ds_nu(sv, n);*/
	// Bai 12
	/*printf("\n");
	printf("Danh sach sinh vien nam.\n");
	ds_nam(sv, n);*/
	// Bai 13
	/*printf("Nhap mssv cam can hieu chinh: ");
	scanf_s("%d%*c", &mssv);
	hieu_chinh(sv, mssv, n);
	xuat_ds(sv, n);*/
	// Bai 14
	/*printf("Sap xep sinh vien theo thu tu MSSV tang dan.\n");
	sap_xep_tangmssv(sv, n);
	xuat_ds(sv, n);*/
	// Bai 16
	/*printf("Sap xep sinh vien theo thu tu diem trung binh giam dan.\n");
	sap_xep_diemgiam(sv, n);
	xuat_ds(sv, n);*/
	// Bai 17
	/*sap_xep_tangmssv(sv, n);
	capnhat(sv, n, mssv);
	xuat_ds(sv, n);*/
	// Bai 18
	/*sinhvien tuoimax;
	printf("Sinh vien tuoi lon nhat la: ");
	tuoimax = tuoi_lonnhat(sv, n);
	xuat_sv(tuoimax);*/
	// Bai 19
	/*sap_xep_diemgiam(sv, n);
	xuat_ds(sv, 5);*/
	// Bai 20
	/*sinhvien timcmnd;
	int flag=0, cmnd;
	printf("Nhap cmnd: ");
	scanf_s("%d", &cmnd);
	timcmnd = tim_cmnd(sv, n, cmnd, flag);
	if (flag == 0) printf("Khong co sinh vien trung khop.\n");
	else xuat_sv(timcmnd);*/
	// Bai 21
	/*int k = 0;
	sinhvien ds_tphcm[max];
	ds_que_tphcm(sv, n, ds_tphcm, k);
	xuat_ds(ds_tphcm, k--);*/
	// Bai 28, Bai 30
	sinhvien *ds ;
	int n;
	FILE *danhsach = fopen("danhsach.txt", "r");
	if (danhsach == NULL)
	{
		printf("Loi trong qua trinh mo danh sach sinh vien.\n");
		exit(1);
	}
	docfile(ds, n, danhsach);
	
	// Bai 29
	/*xuat_ds(ds, n);*/
	// Bai 31
	inthongke_khoa(ds, n);
	// Bai 32
	inthongke_ho(ds,n);
	// Bai 33
	inthongke_tinh(ds, n);
	// Bai 34
	inthongke_thang(ds, n);

	free(ds);
	fclose(danhsach);
	return 0;
}