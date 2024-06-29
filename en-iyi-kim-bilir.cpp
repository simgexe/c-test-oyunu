#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Soru Soru;
typedef struct skorkayit skorkayit;

struct Soru {
    char *A, *B, *C, *D;
    int ID; 
	char *soru_metni;
	char dogru_cevap;
    Soru *sonraki;
};

struct skorkayit {
    char *kullanici_adi;
    int skor;
    skorkayit *sonraki;
};

int soruID, soru_sayisi;
Soru *ilk_soru;
skorkayit *ilk_skor;
//main içindeki fonklarýmýz
void soru_ekle();
void soru_sil();
void soru_goster_guncelle();
void oyun_oyna();
void en_yuksek_skorlar();
//diger fonklarýmýz
void soru_listesine_ekle(Soru *yeni_soru);
void listeyi_temizle(Soru *soru);
void sorulari_dosyadan_oku();
char *metin_oku(char *str);
void soru_dosyasini_guncelle(); 
char *dosyadan_metin_oku(char *str, FILE *file);
void soru_silinme_kontrol(int basarili);
void skor_listesine_ekle(skorkayit *kayit);
void skorlari_dosyadan_oku();
void delay(float number_of_seconds);

int main()
 {
    soruID = 1;
    soru_sayisi = 0;
    srand(time(0));

    sorulari_dosyadan_oku();
    skorlari_dosyadan_oku();

  int secenek;
 	while(1){
 	system("color F5");
    printf("\n");
    printf("                                    ___________________________________________________                                 ");
    printf("                                   |                                                   |                                        \n");
  	printf("==================================>|(* v *)   EN IYI KIM BILIR'E HOSGELDINIZ    (* v *)|<===============================\n");
  	printf("                                   |___________________________________________________|                                         \n");
    delay(0.2);

	printf("                                        Soru eklemek istiyorsaniz");
	delay(0.2);
	printf("-->");
	delay(0.2);
	printf(" 1\n");
	delay(0.2);
	printf("                                        Soru  silmek isterseniz");
	delay(0.2);
	printf("-->");
	delay(0.2);
	printf(" 2\n");
	delay(0.2);
    printf("                                        Sorulari gostermek ve guncellemek isterseniz");
    delay(0.2);
	printf("-->");
	delay(0.2);
	printf(" 3\n");
    delay(0.2);
	printf("                                        Oyun oynamak isterseniz");
	delay(0.2);
	printf("-->");
	delay(0.2);
	printf(" 4\n");
	delay(0.2);
	printf("                                        En yuksek skorlari gormek isterseniz");
	delay(0.2);
	printf("-->");
	delay(0.2);
	printf(" 5\n");
	delay(0.2);
	printf("                                        Cikmak isterseniz");
	delay(0.2);
	printf("-->");
	delay(0.2);
	printf(" 6\n\n");
	delay(0.2);
	printf(" =======================================================================================================================\n");
	delay(0.2);
	printf("                                          Yapmak istediginiz islemi seciniz: ");
	scanf("%d",&secenek);
	printf("\n");
	delay(0.3);
	printf("\n\n\n\t\t\t\t\t   ISLEMINIZ GERCEKLESTIRILIYOR");
	delay(0.5);
	printf(".");
	delay(0.5);
	printf(".");
	delay(0.5);
	printf(".");
	delay(0.5);
	system("CLS");
system("CLS");
    switch(secenek){
	case 1: 
	//soru ekle 
	system("color F1");
	    soru_ekle();
	    system("CLS");
    break;
    case 2:
	 //soru sil
        system("color F4");
    	soru_sil();
        system("CLS");
	break;
	case 3: 
	//soru güncelle göster
	    system("color F1");
		soru_goster_guncelle();
	    system("CLS");
	break;
    case 4: 
    //oyun oyna
        system("color FD");
		oyun_oyna();
		system("CLS");
	break;
	case 5:
	//en yuksek skorlar
	    system("color 81");
		en_yuksek_skorlar();
		system("CLS");
	break;
	case 6: 
	//çýkýþ
	system("color 06");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tP");
	delay(0.3);
	printf("R");
	delay(0.3);
	printf("O");
	delay(0.3);
	printf("G");
	delay(0.3);
	printf("R");
	delay(0.3);
	printf("A");
	delay(0.3);
	printf("M");
	delay(0.3);
	printf("D");
	delay(0.3);		
	printf("A");
	delay(0.3);
	printf("N");
	delay(0.3);
	printf(" ");
	delay(0.3);
	printf("C");
	delay(0.3);
	printf("I");
	delay(0.3);
	printf("K");
	delay(0.3);
	printf("I");
	delay(0.3);
	printf("L");
	delay(0.3);
	printf("I");
	delay(0.3);
	printf("Y");
	delay(0.3);
	printf("O");
	delay(0.3);
	printf("R");
	delay(0.5);
	system("CLS");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tH");
	delay(0.3);
	printf("O");
	delay(0.3);
	printf("S");
	delay(0.3);
	printf("C");
	delay(0.3);
	printf("A");
	delay(0.3);
	printf("K");
	delay(0.3);
	printf("A");
	delay(0.3);
	printf("L");
	delay(0.3);		
	printf("I");
	delay(0.3);
	printf("N");
	delay(0.3);
	printf("I");
	delay(0.3);
	printf("Z");
	delay(0.5);
	printf("^");
	delay(0.3);
	printf(".");
	delay(0.3);
	printf("^");
	delay(1);
	system("CLS");
	break;
	default:
    //baþka bir seçenek seçersek eðer 
	system("CLS");
	system("color 04");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tYANLIS BIR ISLEM SECTINIZ LUTFEN TEKRAR DENEYINIZ.");	
	delay(2.3);
	system("CLS");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t ANA MENUYE YONLENDIRILIYORSUNUZ.");
	delay(1);
	printf(".");
	delay(1);
	printf(".");
    delay(1);
	printf(".");
	delay(1);
	system("CLS");}
	}
system("CLS");
}

void delay(float number_of_seconds) {
	int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds) ;
}

void soru_ekle() {
    Soru *yeni_soru = (Soru *) malloc(sizeof(Soru));
    yeni_soru->ID = soruID++;
    yeni_soru->sonraki = NULL;
    printf("\n\n\n\nNOT:Eklenmek istenen sorunun dogru cevabini eklerken buyuk harf kullaniniz!\n\n");
    printf("Eklenmek istenen soruyu yaziniz:  ");
    yeni_soru->soru_metni = metin_oku(yeni_soru->soru_metni);
    printf("A:");
    yeni_soru->A = metin_oku(yeni_soru->A);
    printf("B:");
    yeni_soru->B = metin_oku(yeni_soru->B);
    printf("C:");
    yeni_soru->C = metin_oku(yeni_soru->C);
    printf("D:");
    yeni_soru->D = metin_oku(yeni_soru->D);
    printf("\nDogru cevap:");
    scanf("%c", &yeni_soru->dogru_cevap);

    soru_listesine_ekle(yeni_soru);
    soru_dosyasini_guncelle();
    system("CLS");
    printf("\n\n\n\tSORU EKLENIYOR");
    delay(0.5);
    printf(".");
    delay(0.5);
    printf(".");
    delay(0.5);
    printf(".");
    delay(0.5);
    system("CLS");
    printf("\n\n\tSORU BASARIYLA EKLENDI");
    delay(0.1);
    printf("^");
    delay(0.1);
    printf(".");
    delay(0.1);
    printf("^");
    delay(1);
    system("CLS");
}

void soru_sil() {
    int silinecekID;
    Soru *soru, *temp;
    system("color F4");
    for (soru = ilk_soru; soru != NULL; soru = soru->sonraki) {
        printf("%d-) %s\n", soru->ID, soru->soru_metni);}
    if (ilk_soru == NULL) {
        system("color F4");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t+_+KAYITLI SORU BULUNAMADI +_+\n");
        return; }
    printf("\n\tSILMEK ISTEDIGINIZ SORU ID GIRINIZ:");
    scanf("%d", &silinecekID);
       if (ilk_soru->ID == silinecekID) {
        temp = ilk_soru;
        ilk_soru = ilk_soru->sonraki;
        free(temp);
        soru_silinme_kontrol(1);
        return;
    }
    for (soru = ilk_soru; soru->sonraki != NULL; soru = soru->sonraki) {
        if (soru->sonraki->ID == silinecekID) {
            temp = soru->sonraki;
            soru->sonraki = soru->sonraki->sonraki;
            free(temp);
            soru_silinme_kontrol(1);
            return;
        }
    }
    soru_silinme_kontrol(0);
}

void soru_goster_guncelle() {
    if (ilk_soru == NULL) {
        system("color F4");
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t+_+KAYITLI SORU BULUNAMADI+_+\n");
        return;
    }
	char sorular_txt[] = "Sorular.txt";
    FILE *soru_dosyasi = fopen(sorular_txt, "r");
    while (!feof(soru_dosyasi)) {
        char c;
        fscanf(soru_dosyasi, "%c", &c);
        putchar(c);
    }

    fclose(soru_dosyasi);
    
    system("color F2");
    printf("\n\tGUNCELLEMEK ISTEDIGINIZ SORU ID GIRINIZ:");
    int ID;
    scanf("%d", &ID);

    Soru *soru;
    for (soru = ilk_soru; soru != NULL; soru = soru->sonraki) {
        if (soru->ID == ID) {
            system("CLS");
		    printf("\n\n\n\tEKLEMEK ISTEDIGINIZ YENI SORU METNINI GIRINIZ:");
            soru->soru_metni = metin_oku(soru->soru_metni);
            printf("A:");
            soru->A = metin_oku(soru->A);
            printf("B:");
            soru->B = metin_oku(soru->B);
            printf("C:");
            soru->C = metin_oku(soru->C);
            printf("D:");
            soru->D = metin_oku(soru->D);
            printf("Dogru cevap:");
            scanf("%c", &soru->dogru_cevap);

            soru_dosyasini_guncelle();
            system("CLS");
            
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSORU GUNCELLENIYOR");
            delay(0.5);
            printf(".");
            delay(0.5);
            printf(".");
            delay(0.5);
            printf(".");
            delay(1);
            system("CLS");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSORU BASARIYLA GUNCELLENDI ^_^\n");
            delay(1);
            system("CLS");
            return;
            
        }
    }
    system("CLS");
    system("color 04");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t+_+ SORU BULUNAMADI +_+ \n");
     delay(1);
    system("CLS");
}

void oyun_oyna() {
    if (soru_sayisi < 5) {
        system("color 04");
        system("CLS");
        delay(1);
	    printf("\n\n\n\n\n\n\n\t\t\t\tOyun icin en az 5 soru eklemeniz gerekiyor!\t\t\n\n\n\n\n\n");
	    delay(1);
	    printf("\t\t\t\tLutfen yeterli sayida soru ekleyiniz!\n");
	    delay(1);
	    printf("ANA MENUYE YONLENDIRILIYOR");
	    delay(0.5);
        printf(".");
        delay(0.5);
        printf(".");
        delay(0.5);
        printf(".");
        delay(1);
	    system("CLS");
        return;
    }

    char cevap_anahtari[5];
    char kullanici_cevaplari[5];

    skorkayit *yeni_kayit = (skorkayit *) malloc(sizeof(skorkayit));
    yeni_kayit->sonraki = NULL;
    yeni_kayit->skor = 0;
   
   printf("\n\n\n\tNOT:CEVAP SIKLARINIZI BUYUK HARFLE GIRINIZ!\n");
    delay(1.5);
    system("CLS");
    printf("\n\n\n\n\n\tx");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.2);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
	printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
	printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    printf("     ");
    delay(0.02);
    printf("-");
    delay(0.02);
    printf("O");
    delay(0.02);
    printf("Y");
    delay(0.02);
    printf("U");
    delay(0.02);
    printf("N");
    delay(0.02);
    printf( " ");
    delay(0.02);
    printf("B");
    delay(0.02);
    printf("A");
    delay(0.02);
    printf("S");
    delay(0.02);
    printf("L");
    delay(0.02);
    printf("I");
    delay(0.02);
    printf("Y");
    delay(0.02);
    printf("O");
    delay(0.02);
    printf("R");
	delay(0.02);
    printf("-");
    delay(0.02);
    printf("     ");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
	printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    system("CLS");
    printf("\n\n\n\n\t\t3");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\t\t2");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\t\t1");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\t\t0");
    delay(1);
    system("CLS");
    
    int i, j;
    for (i = 0; i < 5; i++) {
        fflush(stdin);

        Soru *soru, *temp;
        int index = rand() % (soru_sayisi- i);

        if (index == 0) {
            temp = ilk_soru;
            ilk_soru = ilk_soru->sonraki;
        } else {
            for (j = 0, soru = ilk_soru; j < index - 1; j++, soru = soru->sonraki);
            temp = soru->sonraki;
            soru->sonraki = soru->sonraki->sonraki;
        }
        cevap_anahtari[i] = temp->dogru_cevap;
        printf("\n\n\n\n\n\n\tSoru %d-) %s?\n\t A) %s\n\t B) %s\n\t C) %s\n\t D) %s\n\t Cevap:", i + 1, temp->soru_metni, temp->A, temp->B, temp->C,
               temp->D);
        free(temp);

        scanf("%c", &kullanici_cevaplari[i]);

        if (cevap_anahtari[i] == kullanici_cevaplari[i]) yeni_kayit->skor++;
        system("CLS");
    }
    sorulari_dosyadan_oku();

    fflush(stdin);
     delay(1);
    system("CLS");
   printf("\n\n\n\n\n\tx");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.2);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
	printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
	printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    printf("     ");
    delay(0.02);
    printf("-");
    delay(0.02);
    printf("O");
    delay(0.02);
    printf("Y");
    delay(0.02);
    printf("U");
    delay(0.02);
    printf("N");
    delay(0.02);
    printf( " ");
    delay(0.02);
    printf("B");
    delay(0.02);
    printf("I");
    delay(0.02);
    printf("T");
    delay(0.02);
    printf("T");
    delay(0.02);
    printf("I");
    delay(0.02);
    printf("     ");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
	printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
    delay(0.02);
    printf("x");
	delay(0.02);
    printf("x");
    delay(0.02);
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t SKORUNUZ--->: %d\n\t\t\t\t\tKULLANICI ADINIZI GIRINIZ ^.^:", yeni_kayit->skor);
    yeni_kayit->kullanici_adi = metin_oku(yeni_kayit->kullanici_adi);

    skor_listesine_ekle(yeni_kayit);
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tS");
	delay(0.3);
	printf("k");
	delay(0.3);
	printf("o");
	delay(0.3);
	printf("r");
	delay(0.3);
	printf("u");
	delay(0.3);
	printf("n");
	delay(0.3);
	printf("u");
	delay(0.3);		
	printf("z");
	delay(0.3);
	printf(" ");
	delay(0.3);
	printf("k");
	delay(0.3);
	printf("a");
	delay(0.3);
	printf("y");
    delay(0.3);
    printf("d");
    delay(0.3);
    printf("e");
    delay(0.3);
    printf("d");
    delay(0.3);
    printf("i");
	delay(0.3);
	printf("l");
	delay(0.3);
	printf("i");
    delay(0.3);
    printf("y");
    delay(0.3);
    printf("o");
    delay(0.3);
    printf("r");
    delay(0.3);
    printf(".");
    delay(0.3);
    printf(".");
    delay(0.3);
    printf(".");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t^.^ SKOR LISTESINE BASARIYLA EKLENDI ^.^\n");
    delay(1);
    system("CLS");
}

void en_yuksek_skorlar() {
    skorkayit *kayit;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tE");
    delay(0.1);
	printf("n");
	delay(0.1);
	printf(" ");
	delay(0.1);
	printf("y");
	delay(0.1);
	printf("u");
	delay(0.1);
	printf("k");
	delay(0.1);
	printf("s");
	delay(0.1);
	printf("e");
	delay(0.1);		
	printf("k");
	delay(0.1);
	printf(" ");
	delay(0.1);
	printf("3");
	delay(0.1);
    printf(" ");
    delay(0.1);
	printf("s");
	delay(0.1);
	printf("k");
	delay(0.1);
	printf("o");
	delay(0.1);
	printf("r");
	delay(0.1);
	printf(" ");
	delay(0.1);
	printf("g");
	delay(0.1);
	printf("o");
	delay(0.1);
	printf("r");
	delay(0.1);
	printf("u");
	delay(0.1);
	printf("n");
	delay(0.1);
	printf("t");
	delay(0.1);
	printf("u");
	delay(0.1);
	printf("l");
	delay(0.1);
    printf("e");
	delay(0.1);
	printf("n");
	delay(0.1);
	printf("i");
	delay(0.1);
	printf("y");
	delay(0.1);
	printf("o");
	delay(0.1);
	printf("r");
	delay(0.5);
    printf(".");
    delay(0.5);
    printf(".");
    delay(0.5);
    printf(".");
    delay(0.5);
    system("CLS");
    delay(1);
    printf(" \n\n\n                                      \n");
    printf("\n\n\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx| EN YUKSEK 3 SKOR |xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    delay(1);
   
    int i;
    for (i = 0, kayit = ilk_skor; i < 3; i++, kayit = kayit->sonraki) {
        printf("\n\n\t\t\t\t\t  Kullanici adi: %s\n\t\t\t\t\t  Skor: %d\n\n", kayit->kullanici_adi, kayit->skor);
     delay(1);
    }
    delay(3);
    system("CLS");
    printf("\n\n\n\tEn yuksek 3 skoru goruntulediniz...");
    delay(1);
    system("CLS");
}
void soru_listesine_ekle(Soru *yeni_soru) {
    if (ilk_soru == NULL) {
        ilk_soru = yeni_soru;
    } else {
        Soru *soru;
        for (soru = ilk_soru; soru->sonraki != NULL; soru = soru->sonraki);
        soru->sonraki = yeni_soru;
    }
    soru_sayisi++;
}
void listeyi_temizle(Soru *soru) {
    if (soru == NULL) return;

    listeyi_temizle(soru->sonraki);
    free(soru);
}

void sorulari_dosyadan_oku() {
    listeyi_temizle(ilk_soru);
    soru_sayisi = 0;
    ilk_soru = NULL;

    char sorular_txt[] = "Sorular.txt";
    FILE *soru_dosyasi = fopen(sorular_txt, "r");

    if (soru_dosyasi == NULL) {
        return;
    }

    int ID;
    fscanf(soru_dosyasi, "%d-) ", &ID);

    while (!feof(soru_dosyasi)) {
        Soru *soru = (Soru *) malloc(sizeof(Soru));
        if (ID != 0) {
            soru->ID = ID;
            ID = 0;
        } else {
            fscanf(soru_dosyasi, "%d-) ", &soru->ID);
        }
        soruID = soru->ID + 1;
        soru->soru_metni = dosyadan_metin_oku(soru->soru_metni, soru_dosyasi);
        fscanf(soru_dosyasi, "A) ");
        soru->A = dosyadan_metin_oku(soru->A, soru_dosyasi);
        fscanf(soru_dosyasi, "B) ");
        soru->B = dosyadan_metin_oku(soru->B, soru_dosyasi);
        fscanf(soru_dosyasi, "C) ");
        soru->C = dosyadan_metin_oku(soru->C, soru_dosyasi);
        fscanf(soru_dosyasi, "D) ");
        soru->D = dosyadan_metin_oku(soru->D, soru_dosyasi);
        fscanf(soru_dosyasi, "Cevap: ");
        fscanf(soru_dosyasi, "%c", &soru->dogru_cevap);

        char c;
        fscanf(soru_dosyasi, "%c\n", &c);

        soru->sonraki = NULL;

        soru_listesine_ekle(soru);
    }

    fclose(soru_dosyasi);
}
char *dosyadan_metin_oku(char *str, FILE *file) {
    str = (char *)calloc(100, sizeof(char));

    int i;
    char c;
    for (i = 0; fscanf(file, "%c", &c); i++) {
        if (c == '\n') {
            if (i == 0) {
                i = -1;
                continue;
            }
            str[i] = '\0';
            break;
        } else {
            str[i] = c;
        }
    }

    return str;
}

char *metin_oku(char *str) {
    str =(char*) calloc(100, sizeof(char));

    int i;
    char c;
    for (i = 0; (c = getc(stdin)); i++) {
        if (c == '\n') {
            if (i == 0) {
                i = -1;
                continue;
            }
            str[i] = '\0';
            break;
        } else {
            str[i] = c;
        }
    }

    return str;
}

void soru_dosyasini_guncelle() {
    char sorular_txt[] = "Sorular.txt";
    FILE *soru_dosyasi = fopen(sorular_txt, "w");
    Soru *soru;

    for (soru = ilk_soru; soru != NULL; soru = soru->sonraki) {
        fprintf(soru_dosyasi, "%d-) %s\nA) %s\nB) %s\nC) %s\nD) %s\nCevap: %c\n\n",
                soru->ID, soru->soru_metni, soru->A, soru->B, soru->C, soru->D, soru->dogru_cevap);
    }

    fclose(soru_dosyasi);
}

void soru_silinme_kontrol(int basarili) {
    if (basarili) {
        soru_dosyasini_guncelle();
        soru_sayisi--;
        system("CLS");
        system("color F4");   
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSORU SILINIYOR");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        system("CLS");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSORU BASARIYLA SILINDI.");
        delay(1);
        system("CLS");
        
    } else {
    	system("CLS");
    	system("color F4");
        printf("\n\n\tSORU BULUNAMADI+_+\n");
        delay(1);
        system("CLS");
    }
}

void skor_dosyasini_guncelle() {
    char skorlar_txt[] = "Skorlar.txt";
    FILE *skor_dosyasi = fopen(skorlar_txt, "w");
    skorkayit *kayit;

    for (kayit = ilk_skor; kayit != NULL; kayit = kayit->sonraki) {
        fprintf(skor_dosyasi, "Kullanici adi: %s\nSkor: %d\n\n", kayit->kullanici_adi, kayit->skor);
    }

    fclose(skor_dosyasi);
}

void skor_listesine_ekle(skorkayit *kayit) {
    skorkayit *temp, *kontrol;
    if (ilk_skor == NULL) ilk_skor = kayit;
    else if (kayit->skor > ilk_skor->skor) {
        temp = ilk_skor;
        ilk_skor = kayit;
        kayit->sonraki = temp;
    } else {
        for (kontrol = ilk_skor; ; kontrol = kontrol->sonraki) {
            if (kontrol->sonraki == NULL) {
                kontrol->sonraki = kayit;
                break;
            } else if (kayit->skor > kontrol->sonraki->skor) {
                temp = kontrol->sonraki;
                kontrol->sonraki = kayit;
                kayit->sonraki = temp;
                break;
            }
        }
    }

    skor_dosyasini_guncelle();
}

void skorlari_dosyadan_oku() {
    ilk_skor = NULL;

    char skorlar_txt[] = "Skorlar.txt";
    FILE *skor_dosyasi = fopen(skorlar_txt, "r");

    if (skor_dosyasi == NULL) {
        return;
    }

    fscanf(skor_dosyasi, "");

    while (!feof(skor_dosyasi)) {
        skorkayit *kayit = (skorkayit *) malloc(sizeof(skorkayit));
        fscanf(skor_dosyasi, "\nKullanici adi: ");
        kayit->kullanici_adi = dosyadan_metin_oku(kayit->kullanici_adi, skor_dosyasi);
        fscanf(skor_dosyasi, "Skor: ");
        fscanf(skor_dosyasi, "%d", &kayit->skor);

        char c;
        fscanf(skor_dosyasi, "%c\n", &c);

        kayit->sonraki = NULL;

        skor_listesine_ekle(kayit);
    }

    fclose(skor_dosyasi);
}


