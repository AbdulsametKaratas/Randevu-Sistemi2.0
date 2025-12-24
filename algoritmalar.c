#include "yapilar.h"

// --- AVL YARDIMCI VE ROTASYONLAR ---
int maksimum(int a, int b) { return (a > b) ? a : b; }
int yukseklikAl(IntervalNode *n) { return (n == NULL) ? 0 : n->yukseklik; }

void maxBitisGuncelle(IntervalNode *n) {
    if (n == NULL) return;
    int m = n->veri->bitis;
    if (n->sol != NULL && n->sol->max_bitis > m) m = n->sol->max_bitis;
    if (n->sag != NULL && n->sag->max_bitis > m) m = n->sag->max_bitis;
    n->max_bitis = m;
}

IntervalNode* sagaDondur(IntervalNode *y) {
    IntervalNode *x = y->sol; IntervalNode *T2 = x->sag;
    x->sag = y; y->sol = T2;
    y->yukseklik = maksimum(yukseklikAl(y->sol), yukseklikAl(y->sag)) + 1;
    x->yukseklik = maksimum(yukseklikAl(x->sol), yukseklikAl(x->sag)) + 1;
    maxBitisGuncelle(y); maxBitisGuncelle(x);
    return x;
}

IntervalNode* solaDondur(IntervalNode *x) {
    IntervalNode *y = x->sag; IntervalNode *T2 = y->sol;
    y->sol = x; x->sag = T2;
    x->yukseklik = maksimum(yukseklikAl(x->sol), yukseklikAl(x->sag)) + 1;
    y->yukseklik = maksimum(yukseklikAl(y->sol), yukseklikAl(y->sag)) + 1;
    maxBitisGuncelle(x); maxBitisGuncelle(y);
    return y;
}



// --- DIJKSTRA (Kısa Yol) ---
void enKisaYolBul(int grafik[MAX_SALON][MAX_SALON], int baslangic) {
    int mesafe[MAX_SALON], ziyaret[MAX_SALON];
    for (int i = 0; i < MAX_SALON; i++) { mesafe[i] = INF; ziyaret[i] = 0; }
    mesafe[baslangic] = 0;
    for (int s = 0; s < MAX_SALON - 1; s++) {
        int min = INF, u;
        for (int v = 0; v < MAX_SALON; v++)
            if (!ziyaret[v] && mesafe[v] <= min) { min = mesafe[v]; u = v; }
        ziyaret[u] = 1;
        for (int v = 0; v < MAX_SALON; v++)
            if (!ziyaret[v] && grafik[u][v] && mesafe[u] + grafik[u][v] < mesafe[v])
                mesafe[v] = mesafe[u] + grafik[u][v];
    }
    printf("\nSalon %d'den Digerlerine En Kisa Ulasim (Dijkstra):\n", baslangic);
    for (int i = 0; i < MAX_SALON; i++) printf("Salon %d: %d dk\n", i, mesafe[i]);
}



// --- QUICKSORT VE BINARY SEARCH ---
void quicksort(Randevu dizi[], int d, int y) {
    if (d < y) {
        int pivot = dizi[y].id, i = d - 1;
        for (int j = d; j <= y - 1; j++) {
            if (dizi[j].id < pivot) { i++; Randevu t = dizi[i]; dizi[i] = dizi[j]; dizi[j] = t; }
        }
        Randevu t = dizi[i+1]; dizi[i+1] = dizi[y]; dizi[y] = t;
        quicksort(dizi, d, i); quicksort(dizi, i + 2, y);
    }
}

int ikiliArama(Randevu dizi[], int d, int y, int id) {
    while (d <= y) {
        int o = d + (y - d) / 2;
        if (dizi[o].id == id) return o;
        if (dizi[o].id < id) d = o + 1; else y = o - 1;
    }
    return -1;
}