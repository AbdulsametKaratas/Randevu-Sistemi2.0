#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. VERİ MODELİ: Randevu bilgilerini tutan struct
typedef struct Randevu {
    int id;
    char isim[50];
    int baslangic; // Dakika cinsinden (Örn: 09:00 = 540)
    int bitis;
} Randevu;

// 2. VERİ YAPISI: AVL tabanlı Interval Tree Düğümü 
typedef struct Node {
    Randevu veri;
    int max_bitis; // Alt ağaçtaki en büyük bitiş zamanı (Çakışma kontrolü için) 
    struct Node *sol, *sag;
    int yukseklik;
} Node;

// Yardımcı Fonksiyon: Yeni bir randevu oluşturur
Randevu randevuOlustur(int id, char* isim, int bas, int bit) {
    Randevu r;
    r.id = id;
    strcpy(r.isim, isim);
    r.baslangic = bas;
    r.bitis = bit;
    return r;
}

// 3. ÇAKIŞMA KONTROLÜ (Overlap Check) 
// İki zaman aralığı çakışıyor mu? (a1 < b2 ve a2 < b1 kuralı)
int cakismaVarmi(Randevu r1, Randevu r2) {
    return (r1.baslangic < r2.bitis && r2.baslangic < r1.bitis);
}

// MAX fonksiyonu
int maksimum(int a, int b) { return (a > b) ? a : b; }

// Düğüm yüksekliğini al
int getYukseklik(Node *n) { return (n == NULL) ? 0 : n->yukseklik; }

// Max bitiş değerini güncelle [cite: 17, 63]
void updateMaxBitis(Node *n) {
    if (n == NULL) return;
    int m = n->veri.bitis;
    if (n->sol != NULL && n->sol->max_bitis > m) m = n->sol->max_bitis;
    if (n->sag != NULL && n->sag->max_bitis > m) m = n->sag->max_bitis;
    n->max_bitis = maksimum(m, n->veri.bitis);
}

// --- BURAYA AVL ROTASYONLARI GELECEK ---
// (Projenin ilerleyen aşamalarında dengeleme için ekleyeceğiz)

int main() {
    printf("--- Randevu/Salon Rezervasyon Sistemi Başlatıldı ---\n");
    printf("Hedef: Interval Tree ve AVL Entegrasyonu\n");
    
    // Test için basit bir menü [cite: 16]
    int secim;
    do {
        printf("\n1. Randevu Ekle\n2. Randevulari Listele\n0. Cikis\nSeciminiz: ");
        scanf("%d", &secim);
    } while (secim != 0);

    return 0;
}