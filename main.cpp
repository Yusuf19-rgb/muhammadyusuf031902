#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;


struct hasil{
	string nama;
	int skor;
};


int main()
{		
	string name;
	char letter;
	char ulang = 'y';
	int nimir = 0,final, skor=100;
	string word;
	int maxsalah, MAX_TRIES = 10;
	int letterFill(char, string, string&);
	
	ofstream myfile;
	myfile.open(skor + "kota.txt");
	myfile<< "surabaya", "semarang", "bandung", "jakarta", "denpasar", "malang", "blitar", "samarinda","padang", "gresik";
	myfile<< "jawa timur", "jawa tengah","jawa barat", "ibu kota indonesia","bali","jawa timur","jawa timur","kalimantan timur","sumatra barat","dekat surabaya" ;
	
	myfile.open(skor + "fastfood.txt");
	myfile<< "kfc", "burgeking", "pizzahut", "carlsjr", "dominopizza", "flip burger", "subway", "mcd", "texas chiken","aw";
	myfile<< "ayam goreng", "burger","pizza", "pizza","burger", " burger", "sandwinch","ayam goreng","ayam goreng","ayam goreng dan root beer";
	myfile.close();
	
	string masuk;
	cout<< "Masukkan Nama :";
	cin>> masuk;
	cout << "Nilai Anda Adalah : "<< skor <<endl;
		
	srand(time(NULL));  
	while (ulang == 'y'){
	cout << "----------------Selamat Datang di Game Hangoroo---------------------"<< endl;	
	cout<<"\nSkor Anda Adalah :"<<" "<<skor<<" "<<endl;
	string level;
		cout << "\nPilih Mana Yang kamu mainkan(kota, fastfood):"<< endl;
		cin >> level;

	if (level == "kota")
	{
		string kota[] = { "surabaya","semarang", "bandung", "jakarta", "denpasar", "malang", "blitar", "samarinda","padang","gresik" };
		string word;

		int n = rand() % 11;
		word = kota[n];

		string yoi(word.length(), '-');
		cout<< " Nama Kota yang Harus ditebak:";
		cout<< " surabaya , semarang , bandung, jakarta, denpasar, malang, blitar, samarinda,padang,gresik";
		cout << "\n\nAnda hanya boleh mengetik 1 huruf.";
		cout << "\nAnda boleh Menebak " << MAX_TRIES << " dari Jawaban Anda";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		while (nimir < MAX_TRIES)
		{
			cout << "\n\n" << yoi;
			cout << "\n\nTebak huruf: ";
			cin >> letter;
			if (letterFill(letter, word, yoi) == 0)
			{
				cout << endl << "Uups! Kata itu tidak ada disana" << endl;
				skor=-10;
				nimir++;
			}
			else
			{
				cout << endl << "Anda sudah menemukannya, Bukankah itu Bagus" << endl;
				skor+=5;
			}
			cout << "Kurang dari " << MAX_TRIES - nimir;
			cout << " Kata Yang Kamu tebak" << endl;
			if (word == yoi)
			{
				cout << word << endl;
				cout << "Horee! kamu berhasil menemukannya";
				break;
			}
		}
		if (nimir == MAX_TRIES)
		{
			cout << "\nKata Tersebut Adalah : " << word << endl;
		}
		skor=skor+(maxsalah*10);
		cout<<"\nSkor Anda Adalah :"<<" "<<skor<<" "<<endl;
		cout <<" Tekan y jiak mulai ulang, jika tidak tekan t untuk selesai "<<endl;
		cin>> ulang;
		cin.ignore();
		cin.get();
	}

	else if (level == "fastfood")
	{
		string fastfood[] = { "kfc", "burgerking", "pizzahut", "dominopizza", "carlsjr", "flip burger", "subway", "mcd", "texas chiken", " aw" };

		int n = rand() % 11;
		word = fastfood[n];
		string unknown(word.length(), '-');
		cout<< " Nama Kota yang Harus ditebak:";
		cout<< "kfc, burgerking, pizzahut, dominopizza, carlsjr, flip burger, subway, mcd, texas chiken,  aw";
		cout << "\n\nAnda hanya boleh mengetik 1 huruf.";
		cout << "\nAnda boleh Menebak " << MAX_TRIES << " dari Jawaban Anda";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		while (nimir < MAX_TRIES)
		{
			cout << "\n\n" << unknown;
			cout << "\n\nTebak huruf: ";
			cin >> letter;
			if (letterFill(letter, word, unknown) == 0)
			{
				cout << endl << "Uups! Kata itu tidak ada disana" << endl;
				skor-=10;
				nimir++;
			}
			else
			{
				cout << endl << "Anda sudah menemukannya, Bukankah itu Bagus" << endl;
				skor-=10;
			}
			cout << "Kurang dari " << MAX_TRIES - nimir;
			cout << "\tKata Yang Kamu tebak" << endl;
			if (word == unknown)
			{
				cout << word << endl;
				cout << "Horee! kamu berhasil menemukannya";
				break;
			}
		}
		if (nimir == MAX_TRIES)
		{
			cout << "\nKata Tersebut Adalah :  " << word << endl;
		}
		final=skor+(maxsalah*10);
		cout<<"\nSkor Anda Adalah"<<" "<<final<<" "<<endl;
		cout <<" Tekan y jiak mulai ulang, jika tidak tekan t untuk selesai "<<endl;
		cin>> ulang;
		cin.ignore();
		cin.get();
		
	}
}
	
}


int letterFill(char guess, string secretword, string &guessword)
{
	int i;
	int ok = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{

		if (guess == guessword[i])
			return 0;
			
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			ok++;
		}
	}
	return ok;
}

