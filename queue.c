#ifndef QUEUE_C
#define QUEUE_C

#include "queue.h"

//////////// VARIABEL GLOBAL //////////////

char *jenisPenyakit[9] = { // Daftar Jenis Penyakit //
	"Penyakit Kulit",
	"Luka Ringan",
	"Bersin",
	"Cacingan",
	"Diare",
	"Luka Dalam",
	"Kerongkongan Berlendir & Berbau Busuk",
	"Penyakit Kuning",
	"Terkena Virus"
};
TIME tempWaktuDatangPertama; // variabel untuk menyimpan waktu datang pasien pertama
TIME tempWaktuDatangSebelum; // variabel untuk menyimpan waktu datang pasien sebelumnya
infoPasien latest; // info pasien yang sudah dihapus

////////////////////////////////////////////


// Author    : Raihan Shidqi Pangestu
/* Deksripsi : Modul Procedure yang berfungsi untuk membuat Queue, dengan
               menginisialisasikan HEAD(*Q) dan TAIL(*Q) sebagai NULL */
void CreateQueue (Queue *Q){
	// Algoritma
	HEAD(*Q) = NULL;
	TAIL(*Q) = NULL;
}

// Author    : Muhammad Fadhil
/* Deksripsi : Modul Function yang berfungsi untuk mengalokasikan
               sebuah node */
addrQ Alokasi (infoPasien X){
	// Kamus Lokal
	addrQ P;
	P = (addrQ)malloc(sizeof(NodeQueue));
	
	// Algoritma
	if (P!=NULL){
		Info(P) = X;
		Next(P) = NULL;
		return P;
	}else{
		return NULL;
	}
}

// Author    : Raihan Shidqi Pangestu
/* Deksripsi : Modul Procedure yang berfungsi untuk meng dealokasi kan
               sebuah pointer address */
void Dealokasi (addrQ P){
	// Algoritma
	Next(P) = NULL;
	free(P);
}

// Author    : Muhammad Fadhil
/* Deksripsi : Modul Functioin untuk mengecek apakah isi dari Queue itu kosong atau tidak */
boolean IsQueueEmpty(Queue Q){
	// Algoritma
	return (HEAD(Q)==NULL && TAIL(Q)==NULL);
}

// Author    : Muhamad Naufal Al.Ghani
/* Deksripsi : Modul procedure untuk menghapus sebuah node di dalam antrian (Queue) */
void DelQueue (Queue *Q){
	// Kamus Lokal
	addrQ P;
	
	// Algoritma
	if (!IsQueueEmpty(*Q)){
		P = HEAD(*Q);
		HEAD(*Q) = Next(HEAD(*Q));
		Next(P) = NULL;
		Dealokasi (P);
	}else{
		printf("Antrian Kosong!");
	}
}

// Author    : Muhamad Naufal Al.Ghani
/* Deksripsi : Modul procedure untuk menambah sebuah node ke dalam antrian (Queue) 
               Lalu setelah di input akan ada proses sorting berdasarkan nilai prioritas pasien */

void AddQue(Queue *Q, infoPasien X){ 
	// kamus lokal //
	addrQ P,last;
	
	// algoritma //
	P = Alokasi (X);
	if (IsQueueEmpty(*Q)){
		Next(P) = HEAD(*Q);
		HEAD(*Q) = P;
	}else{
		last = HEAD(*Q);
		while (Next(last) != NULL){
			last = Next(last);
		} 
		Next(last) = P;
		TAIL(*Q) = P;
		SortByValuePriority(*Q);
	}
}

// Author    : Raihan Shidqi Pangestu
/* Deksripsi : Modul Procedure yang berfungsi pada fitur lihat daftar antrian */
void LihatDaftarAntrian(Queue Q){
	// kamus lokal //
	addrQ P;
	int i=0;
	
	// algoritma //
	system("cls");
	P = HEAD(Q);
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("                        ____        ______                ___          __       _           \n");
	printf("                       / __ %c____ _/ __/ /_____ ______   /   |  ____  / /______(_)___ _____ \n",92);
	printf("                      / / / / __ `/ /_/ __/ __ `/ ___/  / /| | / __ %c/ __/ ___/ / __ `/ __ %c\n",92,92);
	printf("                     / /_/ / /_/ / __/ /_/ /_/ / /     / ___ |/ / / / /_/ /  / / /_/ / / / /\n");
	printf("                    /_____/%c__,_/_/  %c__/%c__,_/_/     /_/  |_/_/ /_/%c__/_/  /_/%c__,_/_/ /_/ \n",92,92,92,92,92);
	printf("\n				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	if (P == NULL){
		printf("\n	                               ** ANTRIAN MASIH KOSONG! **\n");
	}else{
		while (P != NULL){
			i++;
			printf("				    		   NO.%d\n", i);
			printf("				    Nama Hewan              : %s\n", Info(P).nama);
			printf("				    Datang Pukul            : ");PrintJam(Info(P).waktuDatang);
			printf("				    Waktu Layanan           : %d Menit\n", Info(P).waktuPelayanan);
			printf("				    Jenis Penyakit          :\n");
			PrintInfo(Info(P).listPenyakit, jenisPenyakit);
			printf("				    Waktu Tunggu Pelayanan  : %d Menit\n", Info(P).waktuTunggu);
			printf("				    Nilai Prioritas         : %d\n", Info(P).nilaiPrioritas);
			printf("				    Waktu Mulai Pelayanan   : ");PrintJam(Info(P).waktuMulai);
			printf("				    Waktu Selesai Pelayanan : ");PrintJam(Info(P).waktuAkhir);
			printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
			P = Next(P);
		}
	}
}
			
// Author    : Muhamad Naufal Al.Ghani
// Deksripsi : Modul Procedure yang berfungsi untuk meng sorting record info pasien berdasarkan nilai prioritas
void SortByValuePriority(Queue Q){
	// Kamus Lokal
	addrQ P,setelah;
	infoPasien temp;
	
	// Algoritma
	if (IsPasienPertama(Q)){
		P = Next(HEAD(Q));
	}else{
		P = HEAD(Q);
	}
	while (P!=NULL){
		setelah = Next(P);
		
		while (setelah!=NULL){
			if (Info(P).nilaiPrioritas < Info(setelah).nilaiPrioritas && TimeToMenit (Info(P).waktuAkhir) > TimeToMenit (Info(setelah).waktuDatang)){
				//swap Info
				temp = Info(P);
				Info(P) = Info(setelah);
				Info(setelah) = temp;		
			}
			setelah = Next(setelah);
		}
		P = Next(P);
	}
	
}

// Author    : Muhammad Fadhil
// Deskripsi : Function yang berfungsi untuk menentukan kategori penyakit berdasarkan jenis penyakit yang dipilih
char *kategoriPenyakit(int Penyakit){
	// Algoritma 
	if (Penyakit >= 1 && Penyakit <= 3 ){
		return "Ringan";
	} else if (Penyakit >= 4 && Penyakit <= 6){
		return "Sedang";
	} else if (Penyakit >= 7 && Penyakit <= 9){
		return "Berat";
	}	
}

// Author     : Raihan Shidqi Pangestu
// Deksripsi  : Function yang berfungsi menghitung nilai prioritas
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat){
	// Kamus lokal
	int nilai = 1;
	
	// Algoritma 
	if (Berat >= 1){
		nilai += 3;
	}
	else if (Sedang >= 2){
		nilai += 2;
	}
	else if (Ringan >= 3){
		nilai += 1;
	}
	
	return nilai;
}

// Author    : Muhamad Naufal Al.Ghani
// Deskripsi  : Function yang berfungsi untuk mengecek waktu Pelayanan berdasarkan jenis penyakit yang dipilih
int CekWaktuPelayanan(int Penyakit){	
	// Algoritma 
	if (Penyakit >= 1 && Penyakit <= 3 ){
		return 15;
	} else if (Penyakit >= 4 && Penyakit <= 6){
		return 30;
	} else if (Penyakit >= 7 && Penyakit <= 9){
		return 45;
	}
}

// Author    : Muhamad Naufal Al.Ghani
// Deksripsi : Function yang berfungsi untuk menghitung waktu Pelayanaan
int HitungWaktuPelayanan(int Ringan, int Sedang, int Berat){
	// Algoritma
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}


// Author    : Muhamad Naufal Al.Ghani
/* Deskripsi : Procedure yang berfungsi untuk menghitung Nilai (waktu) yang dinamis
               Maksud dinamis disini yaitu Nilai yang berubah karena Kondisi Queue yang di sorting.
               Nilai (waktu) dinamisnya yaitu : Waktu Tunggu, Wwaktu Mulai, dan Waktu Akhir */

void HitungWaktuMulaiAkhirTunggu(Queue *Q){
	// Kamus Lokal 
	addrQ P,sebelum;
	
	// Algoritma
	P = HEAD(*Q);
	
	// Inisialisasi waktu Tunggu, waktu Mulai, dan waktu Akhir Untuk Info di HEAD.
	if (IsPasienPertama(*Q) ){ //Menghitung waktu tunggu, mulai, dan akhir di head jika pasien pertama
		Info(P).waktuTunggu = 0;
		Info(P).waktuMulai = Info(P).waktuDatang;
		Info(P).waktuAkhir = NextNMenit (Info(P).waktuDatang, Info(P).waktuPelayanan);
	}else if (P == HEAD(*Q)){ //Menghitung waktu tunggu, mulai, dan akhir di head jika bukan pasien pertama
		Info(P).waktuTunggu = (TimeToMenit (latest.waktuAkhir) - TimeToMenit (Info(P).waktuDatang));
		Info(P).waktuMulai = NextNMenit ((Info(P).waktuDatang), Info(P).waktuTunggu);
		Info(P).waktuAkhir = NextNMenit (Info(P).waktuMulai, Info(P).waktuPelayanan);
	}
	// Inisialisasi waktu Tunggu, waktu Mulai, dan waktu Akhir Untuk Info bukan di HEAD.
		sebelum = P;
		P = Next(P);
		while(P != NULL){ // Jika Isi Queue nya lebih dari satu node
			if (TimeToMenit (Info(P).waktuDatang) > TimeToMenit (Info(sebelum).waktuAkhir)){
				Info(P).waktuTunggu = 0;
				Info(P).waktuMulai = Info(P).waktuDatang;
				Info(P).waktuAkhir = NextNMenit (Info(P).waktuDatang, Info(P).waktuPelayanan);
			}else{
				Info(P).waktuTunggu = (TimeToMenit (Info(sebelum).waktuAkhir) - TimeToMenit (Info(P).waktuDatang));
				Info(P).waktuMulai = NextNMenit ((Info(P).waktuDatang), Info(P).waktuTunggu);
				Info(P).waktuAkhir = NextNMenit (Info(P).waktuMulai, Info(P).waktuPelayanan); 	
			}
			sebelum = P;
			P = Next(P);
		}	
	
}

// Author    : Raihan Shidqi Pangestu
// Deskripsi : Modul Procedure yang berfungsi untuk menampilkan daftar penyakit 

void PrintDaftarPenyakit(){
	// kamus lokal
	int i;
	
	// algoritma 
	printf("\n				___________________________________________\n");
	printf("			       |	    - DAFTAR PENYAKIT -            |\n");
	printf("                               |                                           |\n");
	for (i=0;i<9;i++){
		printf("			       |%d. %-40s|\n", i+1, jenisPenyakit[i]);
	}
	printf("			       |___________________________________________|\n");
}

// Author    : Muhamad Naufal Al.Ghani
/* Deksripsi : Modul Procedure yang berfungsi sebagai fitur registrasi pasien, dan hasil registrasinya
               akan di add ke queue */
void Registrasi (Queue *Q){
	system("cls");
	// Kamus lokal 
	infoPasien X;
	infoPenyakit Y;
	int jumlahPenyakit,i;
	int CountRingan = 0;
	int CountSedang = 0;
	int CountBerat = 0;
	
	// Algoirtma
	CreateList(&X.listPenyakit);
	
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("           ______     ______     ______     __     ______     ______   ______     ______     ______     __    \n");
	printf("          /%c  == %c   /%c  ___%c   /%c  ___%c   /%c %c   /%c  ___%c   /%c__  _%c /%c  == %c   /%c  __ %c   /%c  ___%c   /%c %c   \n",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
	printf("          %c %c  __<   %c %c  __%c   %c %c %c__ %c  %c %c %c  %c %c___  %c  %c/_/%c %c/ %c %c  __<   %c %c  __ %c  %c %c___  %c  %c %c %c  \n",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
	printf("           %c %c_%c %c_%c  %c %c_____%c  %c %c_____%c  %c %c_%c  %c/%c_____%c    %c %c_%c  %c %c_%c %c_%c  %c %c_%c %c_%c  %c/%c_____%c  %c %c_%c \n",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
	printf("            %c/_/ /_/   %c/_____/   %c/_____/   %c/_/   %c/_____/     %c/_/   %c/_/ /_/   %c/_/%c/_/   %c/_____/   %c/_/ \n",92,92,92,92,92,92,92,92,92,92,92);

	printf("               \n				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("				    Nama Hewan\t\t : ");
	scanf("%s", &X.nama); fflush(stdin);
	
	do{
		printf("				    Waktu Datang [HH MM] : ");
		scanf("%d %d", &X.waktuDatang.Hour, &X.waktuDatang.Minute); fflush(stdin);
		if (!IsJamValid(X.waktuDatang)){
			printf("\nERROR!");
			printf("\nInput Waktu Datang Tidak Valid!\n");
			printf("Mohon Coba Lagi!\n\n");
			system("pause");
		}
		if (!IsTimeArriveHigherThanBefore (X.waktuDatang, *Q)){
			printf("\nERROR!");
			printf("\nInput Waktu Datang Harus Sesudah Pasien Sebelumnya! --> ");PrintJam(tempWaktuDatangSebelum);
			printf("Mohon Coba Lagi!\n\n");
			system("pause");
		}
	}while (!IsJamValid(X.waktuDatang) || !IsTimeArriveHigherThanBefore (X.waktuDatang, *Q));
	

	if (IsQueueEmpty(*Q)){
		tempWaktuDatangPertama = X.waktuDatang; // inisialisasi pasien pertama, berdasarkan field waktu datang nya.
	}
	
	PrintDaftarPenyakit();
	printf("\n					Jumlah Penyakit\t\t: ");
	scanf("%d", &jumlahPenyakit);
	printf("					Pilih No.Jenis Penyakit\t: \n");
	for (i=0;i<jumlahPenyakit;i++){
		printf("					                          ");
		scanf("%d", &Y.Penyakit); fflush(stdin);
		strcpy(Y.kategori, kategoriPenyakit(Y.Penyakit));
		Y.waktuEstimasi = CekWaktuPelayanan(Y.Penyakit);
		InsertLast(&X.listPenyakit, Y);
		if (Y.Penyakit > 0 && Y.Penyakit < 4){
			CountRingan++;
		}else if (Y.Penyakit > 3 && Y.Penyakit < 7){
			CountSedang ++;
		}else if (Y.Penyakit > 6 && Y.Penyakit < 10){
			CountBerat ++;
		}
	}
	X.nilaiPrioritas = HitungNilaiPrioritas (CountRingan,CountSedang,CountBerat);
	X.waktuPelayanan = HitungWaktuPelayanan (CountRingan,CountSedang,CountBerat);
	AddQue (&(*Q),X);
	HitungWaktuMulaiAkhirTunggu (&(*Q));
	tempWaktuDatangSebelum = X.waktuDatang;
	printf("\n\n");
	printf("	                          ======= HEWAN ANDA TELAH TERDAFTAR! ========\n");
	
}

// Author    : Muhamad Naufal Al.Ghani
/* Deskripsi : Modul procedure yang berfungsi pada fitur proses antrian, dan 
               jika user input 'yes' maka antrian di head akan keluar, dan jika
               user input 'no' maka akan kembali ke menu */
               
void ProsesAntrian(Queue *Q){
	system("cls");
	// Kamus //
	addrQ P;
	char inputProses[5];
	
	// Algoritma //
	P = HEAD(*Q);
	
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("                                                             _       _           \n");
	printf("                          _ __ _ _ ___ ___ ___ ___  __ _ _ _| |_ _ _(_)__ _ _ _  \n");
	printf("                         | '_ %c '_/ _ (_-</ -_|_-< / _` | ' %c  _| '_| / _` | ' %c \n",92,92);
	printf("                         | .__/_| %c___/__/%c___/__/ %c__,_|_||_%c__|_| |_%c__,_|_||_|\n",92,92,92,92,92);
	printf("                         |_|\n");
	printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	if (P == NULL){
		printf("\n	                               ** ANTRIAN MASIH KOSONG! **\n");
	}else{
			printf("				    Nama Hewan              : %s\n", Info(P).nama);
			printf("				    Datang Pukul            : ");PrintJam(Info(P).waktuDatang);
			printf("				    Waktu Layanan           : %d Menit\n", Info(P).waktuPelayanan);
			printf("				    Jenis Penyakit          :\n");
			PrintInfo(Info(P).listPenyakit, jenisPenyakit);
			printf("				    Waktu Tunggu Pelayanan  : %d Menit\n", Info(P).waktuTunggu);
			printf("				    Nilai Prioritas         : %d\n", Info(P).nilaiPrioritas);
			printf("				    Waktu Mulai Pelayanan   : ");PrintJam(Info(P).waktuMulai);
			printf("				    Waktu Selesai Pelayanan : ");PrintJam(Info(P).waktuAkhir);
			printf("				    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
			printf("\n\n				    Memulai Proses untuk %s? [YES/NO] ", Info(P).nama);
			P = Next(P);
			scanf("%s", inputProses);
			if (strcmp(inputProses, "YES") == 0 || strcmp(inputProses, "yes") == 0){
				latest = Info(HEAD(*Q));
				DelQueue (&(*Q));
				printf("\n				** SABAR YA KUCING MU SEDANG PROSES PENGOBATAN **\n");
				printf("				                       ^_^\n");
			}else if (strcmp(inputProses, "NO") == 0 || strcmp(inputProses, "no") == 0){
				printf("\n				            ** KEMBALI KE MENU **\n");
			}			
	}
}

// Author    : Muhamad Naufal Al.Ghani
/* Deksripsi : Modul Function yang berfungsi untuk mengecek sebuah node, apakah
               info pasien yang mau di cek itu merupakan pasien pertama atau tidak ,
			   yang proses pengecekan nya berdasarkan waktu kedatangan nya*/             
boolean IsPasienPertama(Queue Q){
	return (tempWaktuDatangPertama.Hour == Info(HEAD(Q)).waktuDatang.Hour && tempWaktuDatangPertama.Minute == Info(HEAD(Q)).waktuDatang.Minute);
}

// Author    : Muhamad Naufal Al.Ghani
/* Deskripsi : Modul Function yang berfungsi untuk mengecek apakah input 
               waktu datang lebih besar dari pada waktu datang sebelum
               atau tidak */
boolean IsTimeArriveHigherThanBefore (TIME input, Queue Q){
	if (IsQueueEmpty (Q)){
		return true;
	}
	return (TimeToMenit (input) > TimeToMenit (tempWaktuDatangSebelum));
}
#endif
