#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// Proje kurali: vize %40, final %60, gecme siniri 50.
struct Ogrenci {
    int numara;
    string ad;
    double vize;
    double finalNotu;

    double ortalama() const {
        return vize * 0.40 + finalNotu * 0.60;
    }

    bool gectiMi() const {
        return ortalama() >= 50.0;
    }
};

class NotSistemi {
private:
    vector<Ogrenci> ogrenciler;

public:
    bool ogrenciEkle(int numara, const string& ad, double vize, double finalNotu) {
        if (numara <= 0 || ad.empty() || vize < 0 || vize > 100 ||
            finalNotu < 0 || finalNotu > 100) {
            return false;
        }
        for (const Ogrenci& ogrenci : ogrenciler) {
            if (ogrenci.numara == numara) {
                return false; // Ayni numara ikinci kez eklenmez.
            }
        }
        ogrenciler.push_back({numara, ad, vize, finalNotu});
        return true;
    }