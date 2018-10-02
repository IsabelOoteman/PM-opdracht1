#include <iostream>

using namespace std;
int main (){
	int jaarNu = 2018;
	int maandNu = 9;
	int dagNu = 24;
	// 0 betekent maandag, 1 dinsdag, etc..
	int vandaag = 0;

	int datumStart = 1; // 1 januari 1901 is een dinsdag, dinsdag wordt aangegeven met 1
	int dagStart = 1; // peildatum
	int maandStart = 1; // peildatum
	int jaarStart = 1901; // peildatum

	int jaar;
	int maand;
	int dag;

	cout << "In welk jaar ben je geboren?" << endl;
	cin >> jaar;
	if (jaar < (jaarNu - 100) || jaar > (jaarNu - 10)){
		cout << "Sorry je mag niet meedoen"<< endl; //te jong of te oud
		return 1;
	}	

	cout << "Wat is je geboortemaand in getallen?" << endl;
	cin >> maand;
	if (jaar == (jaarNu - 10) && maand > maandNu){
		cout << "Sorry je mag niet meedoen, je bent te jong"<< endl; //te jong
		return 1;
	} 

	if (jaar == (jaarNu - 100) && maand < maandNu){
		cout << "Sorry u mag niet meedoen, u bent te oud"<< endl; //te oud
		return 1;
	}

	if (maand > 12){ // getal hoger dan aantal maanden die in een jaar kunnen zitten
		cout << "Dit is niet mogelijk" << endl;
		return 1;
	}

	cout << "Wat is je geboortedag?" << endl;
	cin >> dag;
	if (jaar == (jaarNu - 10) && maand == maandNu && dag >= dagNu){
		cout << "Sorry je mag niet meedoen, je bent te jong"<< endl; //te jong
		return 1;
	}
	if (jaar == (jaarNu - 100) && maand == maandNu && dag <= dagNu){
		cout << "Sorry u mag niet meedoen, u bent te oud"<< endl; //te oud
		return 1;
	}

	if (dag > 31){ // getal hoger dan aantal dagen die in een maand kunnen zitten
		cout << "Dit is niet mogelijk" << endl;
		return 1;
	}

	if (maand == maandNu && dag == dagNu){ //huidige dag jarig
		cout << "Gefeliciteerd!" << endl;
	}

	if (maand == maandNu && dag < dagNu){ // jarig in huidige maand, maar nog niet jarig geweest
		maand += 1; // zodat er 1 maand minder wordt geteld
		jaar += 1; // zodat er 1 jaar minder wordt geteld
					// omdat de persoon nog niet jarig is geweest
	}

	int jaren = jaarNu - jaar; // aantal jaren dat persoon oud is
	int maanden = maandNu - maand; // aantal maanden dat persoon oud is
	if (maanden < 0) {
		maanden += 12;
	}

	cout << jaren
		<< " jaar" 
		<< " en "
		<< maanden
		<< " maanden" << endl;
	cout << jaren * 12 + maanden 
		<< " maanden"	<< endl;

	char geboorteDag; // vult persoon zelf in
	char geboorteDagExtra; // als de eerste letter van de dag een d of een z is, moet er een extra letter ingevuld worden om te weten of de persoon de goede dag bedoelt
	char werkelijkeDag; // de dag berekent waarop persoon werkelijk geboren is

	cout << "Wat is de letter van je geboortedag?"<< endl;
	cin >> geboorteDag;
	if (!(geboorteDag == 'm' || geboorteDag == 'd' || geboorteDag == 'w' || geboorteDag == 'v' || geboorteDag == 'z')){
		cout << "Dit is niet mogelijk" << endl;
		return 1;
	}
	if (geboorteDag == 'z' || geboorteDag == 'd') {
		cout << "geef ook de tweede letter van je geboortedag" << endl;
		cin >> geboorteDagExtra;
	}
	if (!(geboorteDagExtra == 'i' || geboorteDagExtra == 'o' || geboorteDagExtra == 'a')){
		cout << "Dit is niet mogelijk" << endl;
		return 1;
	}

	int dagenSindsGeboorte;
		// moet berekent worden met aantal dagen per maand en schrikkeljaren

	int schrikkeljaar;
		if (jaarNu%4 == 0){
			schrikkeljaar = 1;
		}
		else{
			schrikkeljaar = 0;
		}
	cout << schrikkeljaar << endl;

	int verschilInJaren = jaarNu - jaar;
	int aantalSchrikkeljaren = verschilInJaren%4;

	int dagenInHetJaar; // dagen die na je verjaardag al zijn geweest tot de dag dat het nu is
		if (maand == 1){
			dagenInHetJaar = dag;
		}
		if (maand == 2){
			dagenInHetJaar = 31 + dag;
		}
		if (maand == 3){
			dagenInHetJaar = 59 + dag + schrikkeljaar;
		}
		if (maand == 4){
			dagenInHetJaar = 90 + dag + schrikkeljaar;
		}
		if (maand == 5){
			dagenInHetJaar = 120 + dag + schrikkeljaar;
		}
		if (maand == 6){
			dagenInHetJaar = 151 + dag + schrikkeljaar;
		}
		if (maand == 7){
			dagenInHetJaar = 181 + dag + schrikkeljaar;
		}
		if (maand == 8){
			dagenInHetJaar = 212 + dag + schrikkeljaar;
		}
		if (maand == 9){
			dagenInHetJaar = 243 + dag + schrikkeljaar;
		}
		if (maand == 10){
			dagenInHetJaar = 273 + dag + schrikkeljaar;
		}
		if (maand == 11){
			dagenInHetJaar = 304 + dag + schrikkeljaar;
		}
		if (maand == 12){
			dagenInHetJaar = 334 + dag + schrikkeljaar;
		}

	dagenSindsGeboorte = (verschilInJaren * 365) + dagenInHetJaar + aantalSchrikkeljaren;
		// aantal jaren dat je leeft plus de dagen in het huidige jaar

	int dagenVerschil = dagenSindsGeboorte%7; // dagen verschil met de dag van de persoons geboorte
// ----- 
	//int dagenVerder = (vandaag + dagenVerschil)%7; // dagen verschil met de dag van vandaag
	cout << dagenVerschil << endl;
	//cout << dagenVerder << endl;

	werkelijkeDag = vandaag + dagenVerschil;
	if (werkelijkeDag < 0){
		werkelijkeDag += 6;
	}

	char echteDag[2]; // dag in letter waarop persoon echt geboren is, zodat kan checken met invoer van de gebruiker
	if (werkelijkeDag == 0) {
		echteDag[0] = 'm';
		echteDag[1] = '\0';
	}
	if (werkelijkeDag == 1) {
		echteDag[0] = 'd';
		echteDag[1] = 'i';
	}
	if (werkelijkeDag == 2) {
		echteDag[0] = 'w';
		echteDag[1] = '\0';
	}
	if (werkelijkeDag == 3) {
		echteDag[0] = 'd';
		echteDag[1] = 'o';
	}
	if (werkelijkeDag == 4) {
		echteDag[0] = 'v';
		echteDag[1] = '\0';
	}
	if (werkelijkeDag == 5) {
		echteDag[0] = 'z';
		echteDag[1] = 'a';
	}
	if (werkelijkeDag == 6) {
		echteDag[0] = 'z';
		echteDag[1] = 'o';
	}


	if (echteDag[0] + echteDag[1] == geboorteDag + geboorteDagExtra) {
		cout << "Goed!" << endl;
	}
	else{ 
		cout << "Je geboortedag is";

		if (werkelijkeDag == 0){
			cout << " maandag" << endl;
		}	
		else if (werkelijkeDag == 1){
			cout << " dinsdag" << endl;
		}	
		else if (werkelijkeDag == 2){
			cout << " woensdag" << endl;
		}	
		else if (werkelijkeDag == 3){
			cout << " donderdag" << endl;
		}	
		else if (werkelijkeDag == 4){
			cout << " vrijdag" << endl;
		}	
		else if (werkelijkeDag == 5){
			cout << " zaterdag" << endl;
		}	
		else if (werkelijkeDag == 6){
			cout << " zondag" << endl;
		}
	} // else

	return 0;
}//main
