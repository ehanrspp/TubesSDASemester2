#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "list.h"
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void UIMenu(){
	printf ("\t\t\t ____________________________________________________________________\n");
	printf ("\t\t\t|                                                                    |\n");
	printf ("\t\t\t|                        LAYANAN APLIKASI HEWAN                      |\n");
	printf ("\t\t\t|                             HasAChance                             |\n");
	printf ("\t\t\t|                                                                    |\n");
	printf ("\t\t\t|      =======================================================       |\n");
	printf ("\t\t\t|       REGISTRASI   ANTRIAN   PROS. PELAYANAN   KREDIT   EXIT       |\n");
	printf ("\t\t\t|          (1)         (2)          (3)           (4)     (5)        |\n");
	printf ("\t\t\t|                                                                    |\n");
	printf ("\t\t\t|____________________________________________________________________|\n");
	printf ("\n\n\n\t\t\t\t Inputkan angka untuk memilih (1, 2, 3, 4 atau 5) : ");
}

void UIExit(){
	printf("\t\t\t\t\t _____________________________\n");
	printf("\t\t\t\t\t|        TERIMA KASIH !       |\n");
	printf("\t\t\t\t\t|     SAMPAI JUMPA KEMBALI    |\n");
	printf("\t\t\t\t\t|             ^_^             |\n");
	printf("\t\t\t\t\t|_____________________________|");
}

void UIKredit(){
	printf("\t\t\t\t\t\t _________________________________\n");
	printf("\t\t\t\t\t\t|                                 |\n");
	printf("\t\t\t\t\t\t|  Terima kasih telah berkunjung. |\n");
	printf("\t\t\t\t\t\t|     Semoga hewan anda sehat     |\n");
	printf("\t\t\t\t\t\t|             selalu.             |\n");
	printf("\t\t\t\t\t\t|                                 |\n");
	printf("\t\t\t\t\t\t|          -HaveAChance-          |\n");
	printf("\t\t\t\t\t\t|_________________________________|\n");
}

int main(int argc, char *argv[]) {
	Queue Q;
	CreateQueue(&Q);
	int inputMenu;
	do{
		system("cls");
		UIMenu();
		scanf("%d", &inputMenu);
		if (inputMenu == 1){
			Registrasi (&Q);
			system("pause");
		}
		else if (inputMenu == 2){
			LihatDaftarAntrian(Q);
			system("pause");
		}
		else if (inputMenu == 3){
			ProsesAntrian(&Q);
			system("pause");
		}
		else if (inputMenu == 4){
			system("cls");
			UIKredit();
			system("pause");
		}
		else if (inputMenu == 5){
			system("cls");
			UIExit();
			exit(0);
		}
		else{
			printf("\n\n\t\t\t\t      MAAF INPUT MENU SALAH! SILAHKAN COBA LAGI!\n");\
			system("pause");
		}
	}while (inputMenu != 5);
	
	
/*
	// Test Queue //
	printf("\nQUEUE\n");
	Queue Q;
	CreateQueue (&Q);
	infoPasien Y;
	
	//Disini Head//
	Y.waktuDatang = 17; 
	strcpy(Y.nama,"Sisi");
	Y.nilaiPrioritas = HitungNilaiPrioritas(2, 0, 0);
	Y.waktuPelayanan = HitungWaktuPelayanan(2, 0, 0);
	AddQue (&Q,Y);
	HitungWaktuMulaiAkhirTunggu(&Q);
	
	Y.waktuDatang = 5; 
	strcpy(Y.nama,"Inu");
	Y.nilaiPrioritas = HitungNilaiPrioritas(0, 3, 0);
	Y.waktuPelayanan = HitungWaktuPelayanan(0, 3, 0);
	AddQue (&Q,Y);
	HitungWaktuMulaiAkhirTunggu(&Q);
	
	Y.waktuDatang = 9; 
	strcpy(Y.nama,"Zuka");
	Y.nilaiPrioritas = HitungNilaiPrioritas(0, 0, 1);
	Y.waktuPelayanan = HitungWaktuPelayanan(0, 0, 1);
	AddQue (&Q,Y);
	HitungWaktuMulaiAkhirTunggu(&Q);
	
	Y.waktuDatang = 0; 
	strcpy(Y.nama,"Roni");
	Y.nilaiPrioritas = HitungNilaiPrioritas(0, 1, 0);
	Y.waktuPelayanan = HitungWaktuPelayanan(0, 1, 0);
	AddQue (&Q,Y);
	HitungWaktuMulaiAkhirTunggu(&Q);
	
	Y.waktuDatang = 17; 
	strcpy(Y.nama,"JOJO");
	Y.nilaiPrioritas = HitungNilaiPrioritas(0, 3, 0);
	Y.waktuPelayanan = HitungWaktuPelayanan(0, 3, 0);
	AddQue (&Q,Y);
	HitungWaktuMulaiAkhirTunggu(&Q);
	
	CetakQueue(Q);
	
	printf("\n\nCoba Di Delete : \n");
	DelQueue (&Q);
	CetakQueue(Q);
*/
	return 0;
}
