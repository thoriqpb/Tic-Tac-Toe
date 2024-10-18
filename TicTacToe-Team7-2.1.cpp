/*
Team 7
Fajari Ani Novita Sari (23/514330/SV/22319)
Zaldy Ahmad Fahrizi (23/515511/SV/22560)
Thoriq Putra Belligan (23/515052/SV/22466)
*/
#include <iostream>
using namespace std;

char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; //Variabel array

char pemainSekarang= 'X';

int main() {
    int baris, kolom;
    int skorX = 0, skorO = 0;
    char px[50], po[50], pilihan;
    bool lanjut = false;
    bool gerakanValid = false;
    bool permainanSelesai = false;
	
    while (!lanjut) { // Loop Utama dimana akan terus mengulang ketika pemain ingin melanjutkan permainan.
        while (!permainanSelesai) { // loop untuk satu putaran permainan
            system("cls"); // Hapus layar

            // ---- Buat program tampilkan papan permainan ----
            cout << "-+-+-Tic-Tac-Toe Game-+-+-\n" << endl;
            cout << "||  \x1B[34mX\x1B[0m  || " << skorX << " - " << skorO << " ||  \x1B[31mO\x1B[0m  ||\n" << endl;
            for (int i = 0; i < 3; i++) { //Loop untuk membuat papan (menggunakan struktur for)
                for (int j = 0; j < 3; j++) {
                    if (j == 0) {
                        cout << "        ";
                    }
                    char karakter = papan[i][j];
                    if (karakter == 'X') { //Menggunakan if else agar karakter dapat berbeda warna
                        cout << "\x1B[34m" << karakter << "\x1B[0m"; 
                    } else if (karakter == 'O') {
                        cout << "\x1B[31m" << karakter << "\x1B[0m";
                    } else {
                        cout << karakter;
                	}
                    if (j < 2) {
                        cout << " | ";
                    }
                    if (j == 2) {
                        cout << " ";
                    }
                }
                cout << endl;
                if (i < 2) {
                    cout << "       ---+---+---" << endl;
                }
            }
            cout << endl;

            // ---- Buat program untuk memasukkan baris dan kolom Tic Tac Toe ----
				if (pemainSekarang == 'X') {
					cout << "Pemain \x1B[34m" << pemainSekarang << "\x1B[0m, masukkan baris (0-2): ";
            		cin >> baris;
            		cout << "Pemain \x1B[34m" << pemainSekarang << "\x1B[0m, masukkan kolom (0-2): ";
            		cin >> kolom;
                }else{
                	cout << "Pemain \x1B[31m" << pemainSekarang << "\x1B[0m, masukkan baris (0-2): ";
            		cin >> baris; 
            		cout << "Pemain \x1B[31m" << pemainSekarang << "\x1B[0m, masukkan kolom (0-2): ";
            		cin >> kolom;                	
				}
				
            // Program periksa apakah langkah valid
            if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3 && papan[baris][kolom] == ' ') {
                papan[baris][kolom] = pemainSekarang;
                gerakanValid = true;
            } else {
                cout << "\nSalah !! Ulangi kembali\n";
                cin.ignore();
                cin.get();
                gerakanValid = false;
            }

            // Program periksa kemenangan atau seri
            if ((papan[0][0] == pemainSekarang && papan[0][1] == pemainSekarang && papan[0][2] == pemainSekarang) ||
                (papan[1][0] == pemainSekarang && papan[1][1] == pemainSekarang && papan[1][2] == pemainSekarang) ||
                (papan[2][0] == pemainSekarang && papan[2][1] == pemainSekarang && papan[2][2] == pemainSekarang) ||
                (papan[0][0] == pemainSekarang && papan[1][0] == pemainSekarang && papan[2][0] == pemainSekarang) ||
                (papan[0][1] == pemainSekarang && papan[1][1] == pemainSekarang && papan[2][1] == pemainSekarang) ||
                (papan[0][2] == pemainSekarang && papan[1][2] == pemainSekarang && papan[2][2] == pemainSekarang) ||
                (papan[0][0] == pemainSekarang && papan[1][1] == pemainSekarang && papan[2][2] == pemainSekarang) ||
                (papan[0][2] == pemainSekarang && papan[1][1] == pemainSekarang && papan[2][0] == pemainSekarang)) {
                system("cls");

                // ---- Buat program memberitahu kemenangan player dan logika selesai ----
                if (pemainSekarang == 'X') {
                	cout << "Pemain \x1B[34m" << pemainSekarang << "\x1B[0m Menang!" << endl;
                    skorX++;
                }else{
                	cout << "Pemain \x1B[31m" << pemainSekarang << "\x1B[0m Menang!" << endl; 
                    skorO++;
                }
                permainanSelesai = true;
            } else if (papan[0][0] != ' ' && papan[0][1] != ' ' && papan[0][2] != ' ' &&
                       papan[1][0] != ' ' && papan[1][1] != ' ' && papan[1][2] != ' ' &&
                       papan[2][0] != ' ' && papan[2][1] != ' ' && papan[2][2] != ' ') {
                system("cls");

                // --- Buat program memberitahu saat permainan seri dan memberi logika selesai ----
                cout << "Permainan Seri!" << endl;
                permainanSelesai = true;
            }

            // ---- Buat program untuk mengganti pemain ----
            if (gerakanValid) {
                pemainSekarang = (pemainSekarang == 'X') ? 'O' : 'X'; // Ganti pemain
            }            
			/*	Dapat menggunakan kode program if else
				if (gerakanValid) {
                if (pemainSekarang == 'X') {
                    pemainSekarang = 'O';
                } else {
                    pemainSekarang = 'X';
                }
            }*/
        }
        // ---- Buat program menampilkan skor sementara dari player X dan player O ----
        cout << "Pemain \x1B[34mX\x1B[0m : " << skorX << endl;
        cout << "Pemain \x1B[31mO\x1B[0m : " << skorO << endl;

        // ---- Buat program menanyakan ke pemain apakah akan melanjutkan atau tidak ----
        // #### Ket : Jika Ya maka permainan akan berlanjut
        //          Jika Tidak maka akan menampilkan skor akhir dari seluruh fase permainan
		// ---- Buat program menanyakan ke pemain apakah akan melanjutkan atau tidak ----
		
		do { //Menggunakan do while agar mengulang ketika input salah.
		    cout << "------------------------------------------------------\n";
			cout << "Apakah Anda ingin melanjutkan permainan (Y/N) : ";
		    cin >> pilihan;
		    if (pilihan == 'Y' || pilihan == 'y') { //Menggunakan struktur If Else If agar ketika input salah, mengeluarkan pemberitahuan
		        // Reset papan untuk permainan baru
		        for (int i = 0; i < 3; i++) {
		            for (int j = 0; j < 3; j++) {
		                papan[i][j] = ' ';
		            }
		        }
		        permainanSelesai = false;
		    } else if (pilihan == 'N' || pilihan == 'n') {
		        lanjut = true;
		
		        cout << "Masukkan nama player \x1B[34mX\x1B[0m : ";
		        cin >> px;
		        cout << "Masukkan nama player \x1B[31mO\x1B[0m : ";
		        cin >> po;
		
		        cout << "\n------- SKOR AKHIR -------\n";
		        cout << px << " : " << skorX << endl;
		        cout << po << " : " << skorO << endl;
		        cout << endl;
		        if (skorX > skorO) {
		            cout << "Selamat " << px << " Kamu Menang!";
		        } else if (skorO > skorX) {
		            cout << "Selamat " << po << " Kamu Menang";
		        } else {
		            cout << "Permainan Berakhir SERI!";
		        }
		        
		        cout << "\nApakah Anda ingin mereset skor dan memulai permainan dari awal? (Y/N) "; cin >> pilihan;
				skorX = 0;
				skorO = 0;
				if (pilihan == 'Y' || pilihan == 'y') {
		        // Reset papan untuk permainan baru
		        for (int i = 0; i < 3; i++) {
		            for (int j = 0; j < 3; j++) {
		                papan[i][j] = ' ';
		            }
		        }
		        permainanSelesai = false;
		        lanjut = false;
				}
		    } else {
		        cout << "Input tidak valid. Harap masukkan 'Y' atau 'N'." << endl;
		    }	
		} while (pilihan != 'Y' && pilihan != 'y' && pilihan != 'N' && pilihan != 'n');
    }
    return 0;
}
