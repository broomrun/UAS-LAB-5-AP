#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

const string namaPT = "PT Rizz Party";
const int maxTahun = 2030; //maksimal tahun pemesanan
const int maxBanyakTempat = 5; // maksimal tempat
const int maxKamar = 3; // maksimal tipe kamar di satu (penginapan/villa/airbnb)

struct InfoKamar { //
    string tipe;
    long harga;
    string fasilitas;
};

struct InfoPenginapan {
    string nama;
    int bintang;
    string deskripsi, deskripsi2, deskripsi3;
    InfoKamar kamar[maxKamar + 1];
};

struct Penginapan {
    string nama;
    InfoPenginapan penginapan[maxBanyakTempat + 1];
};

vector<string> tipeKamar(int bintang) {
    vector<string> kamar;
    switch (bintang) {
        case 1: 
            kamar.push_back("Single Room");
            kamar.push_back("Twin Room");
            break;
        case 2: 
            kamar.push_back("Single Room");
            kamar.push_back("Twin Room");
            break;
        case 3: 
            kamar.push_back("Single Room");
            kamar.push_back("Deluxe Room");
            kamar.push_back("Family Room");
            break;
        case 4: 
            kamar.push_back("Junior Suite Room");
            kamar.push_back("Suite Room");
            break;
        case 5: 
            kamar.push_back("Deluxe Room");
            kamar.push_back("Family Room");
            break;
        default:
            kamar = vector<string>();
    }
    return kamar;
}

string fasilitasKamar(int bintang, const string& tipe) {  
    if (bintang == 1) {
        if (tipe == "Single Room") return "single bed, ac, tv, toiletries, wifi, shower, breakfast (additional charge)";
        if (tipe == "Twin Room") return "twin bed or double bed, ac, tv, bathtub, toilet, shower, wifi, breakfast (additional charge), tea maker, mini refrigerator";
    } else if (bintang == 2) {
        if (tipe == "Single Room") return "single bed, ac, tv, toiletries, wifi, shower, breakfast (additional charge)";
        if (tipe == "Twin Room") return "twin bed or double bed, ac, tv, bathtub, toilet, shower, wifi, breakfast (additional charge), tea maker, mini refrigerator";
    } else if (bintang == 3) {
        if (tipe == "Single Room") return "single bed, ac, tv, toiletries, wifi, shower, breakfast (additional charge)";
        if (tipe == "Deluxe Room") return "twin bed or double bed, ac, tv, bathtub, toilet, shower, wifi, breakfast (additional charge), tea maker, mini refrigerator";
        if (tipe == "Family Room") return "double king bed, ac, tv, bathtub, toilet, shower, wifi, breakfast (additional charge), tea maker, mini refrigerator, mini bar, telephones, hair dryer";
    } else if (bintang == 4) {
        if (tipe == "Junior Suite Room") return "queen size bed, living room, ac, tv, toiletries, shower, wifi, hair dryer, tea maker, telephones, breakfast";
        if (tipe == "Suite Room") return "king size bed, living room, ac, tv, toiletries, shower, bathtub, wifi, hair dryer, tea maker, telephones, mini refrigerator, mini kitchen, breakfast";
        if (tipe == "Family Room") return "double king bed, ac, tv, bathub, toilet, shower, wifi, breakfast (additional charge), tea maker, mini refrigerator, mini bar, telephones, hair dryer";
    } else if (bintang == 5) {
        if (tipe == "Super Suite Room") return "single bed, ac, tv, toiletries, wifi, shower, hairdryer, refrigerator, breakfast (additional charge)";
        if (tipe == "Deluxe Room") return "queen size bed, ac, tv, toilet, bathtub, shower, living room, wifi, tea maker, telephones, wardrobes, mini refrigerator, breakfast (additional charge)";
        if (tipe == "Family Room") return "double king bed, ac, tv, toilet, shower, bathtub, living room, kitchen mini, wifi, tea maker, telephones, hair dryer, wardrobes, breakfast (additional charge), mini refrigerator, gym, mini bar, swimming pool";
    }
    return "";
}


void dataWisata(vector<Penginapan>& wisata) { 
    wisata.resize(3);

    wisata[0].nama = "Hotel";
    wisata[0].penginapan[0].nama = "Rizz Haven";
    wisata[0].penginapan[0].bintang = 3;
    wisata[0].penginapan[0].deskripsi = "Dekat dengan pusat belanja, cocok buat kamu si jompo yang suka shopping. ";
    wisata[0].penginapan[0].deskripsi2 = "Kisaran harga: 500.000-850.000";
    wisata[0].penginapan[0].deskripsi3 = "Rating: 4.3";
    wisata[0].penginapan[0].kamar[0] = {"Single Room", 500000, fasilitasKamar(3, "Single Room")};
    wisata[0].penginapan[0].kamar[1] = {"Deluxe Room", 700000, fasilitasKamar(3, "Deluxe Room")};
    wisata[0].penginapan[0].kamar[2] = {"Family Room", 850000, fasilitasKamar(3, "Family Room")};

    wisata[0].penginapan[1].nama = "Rizz King Palace";
    wisata[0].penginapan[1].bintang = 4;
    wisata[0].penginapan[1].deskripsi = "Bangun pagi dengan pemandangan sunrise yang sangat indah. Cocok buat kamu sang early bird.  ";
    wisata[0].penginapan[1].deskripsi2 = "Kisaran harga: 1.000.000-2.500.000";
    wisata[0].penginapan[1].deskripsi3 = "Rating: 4.6";
    wisata[0].penginapan[1].kamar[0] = {"Junior Suite Room", 1000000, fasilitasKamar(4, "Junior Suite Room")};
    wisata[0].penginapan[1].kamar[1] = {"Suite Room", 1750000, fasilitasKamar(4, "Suite Room")};
    wisata[0].penginapan[1].kamar[2] = {"Family Room", 2500000, fasilitasKamar(4, "Family Room")};

    wisata[0].penginapan[2].nama = "Sigma Sanctuary";
    wisata[0].penginapan[2].bintang = 5;
    wisata[0].penginapan[2].deskripsi = "Tidur dengan pemandangan laut sejauh mata memandang? Kapan lagi?  ";
    wisata[0].penginapan[2].deskripsi2 = "Kisaran harga: 1.500.000-3.500.000";
    wisata[0].penginapan[2].deskripsi3 = "Rating: 4.8";
    wisata[0].penginapan[2].kamar[0] = {"Super Suite Room", 1500000, fasilitasKamar(4, "Super Suite Room")};
    wisata[0].penginapan[2].kamar[1] = {"Deluxe Room", 2500000, fasilitasKamar(4, "Deluxe Room")};
    wisata[0].penginapan[2].kamar[2] = {"Family Room", 3500000, fasilitasKamar(4, "Family Room")};

    wisata[1].nama = "Villa";
    wisata[1].penginapan[0].nama = "Skibidi Resort";
    wisata[1].penginapan[0].bintang = 4;
    wisata[1].penginapan[0].deskripsi = "Nikmatin sunrise dari atas kasur, ngemil sepanjang hari tanpa di-judge, dan foto-foto tanpa harus edit karena semuanya udah perfect. Kapan nih?";
    wisata[1].penginapan[0].deskripsi2 = "Kisaran harga: 1.000.000-2.500.000";
    wisata[1].penginapan[0].deskripsi3 = "Rating: 4.7";
    wisata[1].penginapan[0].kamar[0] = {"Deluxe Room", 1000000, fasilitasKamar(4, "Deluxe Room")};
    wisata[1].penginapan[0].kamar[1] = {"Family Room", 2500000, fasilitasKamar(4, "Family Room")};

    wisata[1].penginapan[1].nama = "Rizz King Empire";
    wisata[1].penginapan[1].bintang = 5;
    wisata[1].penginapan[1].deskripsi = "Main PS bareng, kolam renang buat nge-cannonball, dan rooftop buat nongkrong sambil ngeliat bintang. Ayo nginap disini";
    wisata[1].penginapan[1].deskripsi2 = "Kisaran harga: 1.000.000-1.500.000";
    wisata[1].penginapan[1].deskripsi3 = "Rating: 4.9";
    wisata[1].penginapan[1].kamar[0] = {"Deluxe Room", 2500000, fasilitasKamar(4, "Deluxe Room")};
    wisata[1].penginapan[1].kamar[1] = {"Family Room", 3500000, fasilitasKamar(4, "Family Room")};

    wisata[2].nama = "Airbnb";
    wisata[2].penginapan[0].nama = "Skibidi Chill";
    wisata[2].penginapan[0].bintang = 1;
    wisata[2].penginapan[0].deskripsi = "Ada area khusus untuk skibidi dance, kolam renang untuk chillax, dan tempat tidur yang nyaman buat rebahan maksimal. ";
    wisata[2].penginapan[0].deskripsi2 = "Kisaran harga: 1.000.000-1.500.000";
    wisata[2].penginapan[0].deskripsi3 = "Rating: 3.9";
    wisata[2].penginapan[0].kamar[0] = {"Deluxe Room", 1000000, fasilitasKamar(5, "Deluxe Room")};
    wisata[2].penginapan[0].kamar[1] = {"Family Room", 1500000, fasilitasKamar(5, "Family Room")};

    wisata[2].penginapan[1].nama = "Skibidi Hideaway";
    wisata[2].penginapan[1].bintang = 3;
    wisata[2].penginapan[1].deskripsi = "Dengan dekorasi yang funky dan speaker di kamar mandi untuk shower karaoke, tempat ini akan membuat setiap harimu penuh dengan energi skibidi. ";
    wisata[2].penginapan[1].deskripsi2 = "Kisaran harga: 2.000.000-3.500.000";
    wisata[2].penginapan[1].deskripsi3 = "Rating: 4.7";
    wisata[2].penginapan[1].kamar[0] = {"Deluxe Room", 2000000, fasilitasKamar(5, "Deluxe Room")};
    wisata[2].penginapan[1].kamar[1] = {"Family Room", 3500000, fasilitasKamar(5, "Family Room")};

    wisata[2].penginapan[2].nama = "Alpha Male Hideout";
    wisata[2].penginapan[2].bintang = 5;
    wisata[2].penginapan[2].deskripsi = "Dilengkapi dengan ruang gym pribadi, area BBQ untuk berkumpul, dan kamar tidur yang mewah, tempat ini memastikan kamu bisa bersantai dengan gaya alpha. Bersiaplah untuk hidup seperti alpha!";
    wisata[2].penginapan[2].deskripsi2 = "Kisaran harga: 3.000.000-4.500.000";
    wisata[2].penginapan[2].deskripsi3 = "Rating: 4.9";
    wisata[2].penginapan[2].kamar[0] = {"Deluxe Room", 3000000, fasilitasKamar(5, "Deluxe Room")};
    wisata[2].penginapan[2].kamar[1] = {"Family Room", 4500000, fasilitasKamar(5, "Family Room")};

    // Isi tipe kamar dan fasilitas
    for (size_t i = 0; i < wisata.size(); ++i) {
        for (size_t j = 0; j < maxBanyakTempat; ++j) {
            InfoPenginapan& h = wisata[i].penginapan[j];
            if (h.bintang == 0) break;
            vector<string> tipeKamarList = tipeKamar(h.bintang);
            for (size_t k = 0; k < tipeKamarList.size(); ++k) {
                h.kamar[k].tipe = tipeKamarList[k];
                h.kamar[k].fasilitas = fasilitasKamar(h.bintang, h.kamar[k].tipe);
            }
        }
    }
}

void garis() {
    for (int i = 0; i < 60; ++i) cout << "=";
    cout << endl;
}

void clear() {
    cout << string(2, '\n');
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char waktu[20];
    strftime(waktu, 20, "%Y-%m-%d %H:%M:%S", ltm);
    cout << "Selamat Datang di " << namaPT << "        " << waktu << endl;
    garis();
}

int stringToInt(const string& str) {
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}



int main() {
    vector<Penginapan> wisata;
    string jadwal;
    int tahun;
    int tujuanWisata;
    int tujuanBintang;
    int tujuanpenginapan;
    int tujuanKamar;
    int jumlahKamar;
    string namaorang;
    string nohp;
    double total, diskon;
    string ulang;
    bool found;

    do {
        clear();
        cout << "Masukkan nama anda: ";
        getline(cin,namaorang);
        cout << "Masukkan No.Hp: ";
        getline(cin,nohp);

        x:
        clear();
        cout << "Masukkan jadwal pemesanan (Max: 31 Desember " << maxTahun << "): ";
        getline(cin,jadwal);

        tahun = stringToInt(jadwal.substr(jadwal.find_last_of(' ') + 1));

        if (tahun > maxTahun) {
            cout << "Maaf, kami tidak bisa memprediksi keadaan " << namaPT << " di tahun " << tahun << endl;
            goto x;
            return 0;
        } else if (tahun <= 2023) {
            cout << "Maaf, sudah tanggal yang anda masukkan sudah lewat" << endl;
            goto x;
        }

        clear();
        cout << "Berikut beberapa pilihan tempat di " << namaPT << " ^-^!: " << endl;
        dataWisata(wisata);
        for (size_t i = 0; i < wisata.size(); ++i) {
            if (wisata[i].nama.empty()) break;
            cout << i << ". " << wisata[i].nama << endl;
        }
        do {
            cout << "Masukkan Lokasi yang ingin anda tuju (Contoh: 0): ";
            cin >> tujuanWisata;
        } while (tujuanWisata < 0 || static_cast<size_t>(tujuanWisata) >= wisata.size());

        string Penginapan = wisata[tujuanWisata].nama;

        do {
            cout << Penginapan << " Bintang berapa? (1 - 5): ";
            cin >> tujuanBintang;

            clear();
            cout << "Berikut adalah daftar " << Penginapan << " bintang " << tujuanBintang << " di " << ":" << endl;
            found = false;
            for (size_t i = 0; i < maxBanyakTempat; ++i) {
                const InfoPenginapan& h = wisata[tujuanWisata].penginapan[i];
                if (h.bintang == tujuanBintang) {
                    found = true;
                    cout << i << ". " << h.nama << endl;
                    cout << "   -> " << h.deskripsi << endl;
                    cout << "   -> " << h.deskripsi2 << endl;
                    cout << "   -> " << h.deskripsi3 << endl;
                }
            }
            if (!found) {
                cout << "Ups.. kami tidak menemukan " << Penginapan << " bintang " << tujuanBintang << " di sini" << endl;
            }
        } while (!found);

        do {
            cout << "Pilih " << Penginapan << " (Contoh: 0): ";
            cin >> tujuanpenginapan;
        } while (tujuanpenginapan < 0 || static_cast<size_t>(tujuanpenginapan) >= maxBanyakTempat);

        clear();
        cout << "Tipe Kamar:" << endl;
        for (int i = 0; i <= maxKamar; ++i) {
            const InfoKamar& k = wisata[tujuanWisata].penginapan[tujuanpenginapan].kamar[i];
            if (!k.tipe.empty()) {
                cout << i << ". " << k.tipe << endl;
                cout << "   -> Fasilitas: " << k.fasilitas << endl;
                cout << "   -> harga: " << k.harga << endl;
            }
        }
        do {
            cout << endl << "Pilih Tipe Kamar (Contoh: 0): ";
            cin >> tujuanKamar;
        } while (tujuanKamar < 0 || tujuanKamar > maxKamar);

        cout << endl << "Jumlah Kamar yang ingin anda pesan: ";
        cin >> jumlahKamar;

        total = jumlahKamar * wisata[tujuanWisata].penginapan[tujuanpenginapan].kamar[tujuanKamar].harga;
        diskon = total >= 500000 ? 0.25 : 0;

        clear();
        const InfoPenginapan& h = wisata[tujuanWisata].penginapan[tujuanpenginapan];
        const InfoKamar& k = h.kamar[tujuanKamar];
        cout << "Kamu memesan " << Penginapan << " di " << h.nama << ":" << endl;
        cout << "Nama   : " << namaorang << endl;
        cout << "No.Hp  : " << nohp << endl;
        cout << "Tanggal: " << jadwal << endl;
        cout << "Tipe   : " << k.tipe << endl;
        cout << "Harga  : Rp." << k.harga << endl;
        cout << "Jumlah : " << jumlahKamar << " kamar" << endl;
        cout << "Total  : Rp." << fixed << setprecision(0) << total << endl;
        cout << "Diskon : Rp." << fixed << setprecision(0) << (diskon * total) << endl;
        garis();
        cout << "Total yang harus dibayar: Rp." << fixed << setprecision(0) << (total - (diskon * total)) << endl;
        garis();

        cout << "Ingin memesan lagi? (Y/N): ";
        cin >> ulang;
    } while (toupper(ulang[0]) != 'N');
    
    cout << "Terima kasih sudah memakai layanan kami ^-^!!" << endl;
    return 0;
}