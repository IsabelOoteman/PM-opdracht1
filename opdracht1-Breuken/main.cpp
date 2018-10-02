//Eerste programmeeropgave: Breuken
//Isabel Ooteman (s2173182) en Leonie (s1957082)
//24 September 2018

#include <iostream>

using namespace std;

void infoblokje (){
    cout << "Dit programma is gemaakt door Isabel Ooteman & Leonie Jonkman" << endl;
    cout << "september 2018" << endl;
    cout << "In dit programma wordt eerst aan de hand van uw geboortedatum uw" << endl;
    cout << "geboortedag berekend. Vervolgens wordt getest of u geschikt bent" << endl;
    cout << "voor een beta of alpha studie" << endl;
}

int main (){
    infoblokje();
    int jaarNu = 2018; // reken datum
    int maandNu = 9; // reken datum
    int dagNu = 24;    // reken datum
    
    // 0 betekent maandag, 1 dinsdag, etc..
    int datumStart = 1; // 1 januari 1901 is een dinsdag, dinsdag wordt aangegeven met 1
    int jaarStart = 1901; // peildatum
    
    int jaar; // jaar waarin gebruiker geboren is
    int maand; // maand waarin gebruiker geboren is
    int dag; // dag waarop gebruiker geboren is
    
    cout << "In welk jaar ben je geboren?" << endl;
    cin >> jaar;
    if (jaar < (jaarNu - 100) || jaar > (jaarNu - 10)){
        cout << "Sorry je mag niet meedoen" << endl; //te jong of te oud
        return 1;
    }
    
    cout << "Wat is je geboortemaand in getallen?" << endl;
    cin >> maand;
    
    if (maand > 12 || maand < 0){ // getal hoger dan aantal maanden die in een jaar kunnen zitten of negatief
        cout << "Dit is niet mogelijk" << endl;
        return 1;
    }
    
    if (maand > maandNu || (maand == maandNu && dag > dagNu)){ // gebruiker is nog niet jarig geweest in het huidige jaar, dus 1 jaar minder moet er geteld worden
        jaar += 1;
        maand +=1;
    }
    
    if ((jaar == (jaarNu - 10) && maand > maandNu)){ // later geboren dan huidige maand, dus nog niet jarig geweest
        cout << "Sorry je mag niet meedoen, je bent te jong"<< endl; //te jong
        return 1;
    }
    
    if ((jaar == (jaarNu - 100) && maand < maandNu)){ // eerder geboren dan huidige maand, dus al jarig geweest
        cout << "Sorry u mag niet meedoen, u bent te oud"<< endl; //te oud
        return 1;
    }
    
    cout << "Wat is je geboortedag?" << endl;
    cin >> dag;
    
    if (dag > 31 || dag < 0){ // getal hoger dan aantal dagen die in een maand kunnen zitten
        cout << "Dit is niet mogelijk" << endl;
        return 1;
    }
    
    if ((jaar == (jaarNu - 10) && maand == maandNu && dag > dagNu) ){ // gebruiker later geboren in het jaar dan de huidige datum, dus nog niet jarig geweest; te jong
        cout << "Sorry je mag niet meedoen, je bent te jong"<< endl; //te jong
        return 1;
    }
    
    if ((jaar == (jaarNu - 100) && maand == maandNu && dag < dagNu) ){ // gebruiker eerder geboren in het jaar dan de huidige datum, dus al jarig geweest; te oud
        cout << "Sorry u mag niet meedoen, u bent te oud"<< endl; //te oud
        return 1;
    }
    
    if (maand == maandNu && dag == dagNu){ //huidige dag jarig
        cout << "Gefeliciteerd!" << endl;
    }
    
    int jaren = jaarNu - jaar; // aantal jaren dat gebruiker oud is
    int maanden = maandNu - maand; // aantal maanden dat gebruiker oud is
    
    if (maanden < 0) { // als maanden negatief is moet er weer 12 (aantal maanden in jaar) bij opgeteld worden)
        maanden += 12;
    }
    
    cout << jaren
    << " jaar"
    << " en "
    << maanden
    << " maanden" << endl;
    cout << jaren * 12 + maanden
    << " maanden"    << endl;
    
    if (maand > maandNu || (maand == maandNu && dag > dagNu)){ // de er bijgetelde jaar en dag moet er weer af voor de berekening van de geboorte dag
        jaar -= 1; // 1 er af zodat weer in het door de gebruiker ingevoerde jaar zit
        maand -=1; // 1 er af zodat weer in het door de gebruiker ingevoerde maand zit
    }
    
    char geboorteDag; // vult gebruiker zelf in
    char geboorteDagExtra; // als de eerste letter van de dag een d of een z is, moet er een extra letter ingevuld worden om te weten of de gebruiker de goede dag bedoelt
    char werkelijkeDag; // de dag berekent waarop gebruiker werkelijk geboren is
    
    cout << "Wat is de letter van je geboortedag?"<< endl;
    cin >> geboorteDag;
    if (!(geboorteDag == 'm' || geboorteDag == 'd' || geboorteDag == 'w' || geboorteDag == 'v' || geboorteDag == 'z')){ // als er een andere letter dan de begin letters van de dagen van de week wordt ingevoerd, wordt het programma gestopt
        cout << "Dit is niet mogelijk" << endl;
        return 1;
    }
    if (geboorteDag == 'z' || geboorteDag == 'd') { // z en d komen dubbel voor als eerste letter van de dag van de week, dus moet ook de tweede letter ingegeven worden
        cout << "Geef ook de tweede letter van je geboortedag" << endl;
        cin >> geboorteDagExtra;
    }
    if (!(geboorteDagExtra == 'i' || geboorteDagExtra == 'o' || geboorteDagExtra == 'a' || geboorteDagExtra == '\0')){ // als er een andere letter dan de tweede letters van z of d of niks ingevuld wordt, wordt het programma gestopt
        cout << "Dit is niet mogelijk" << endl;
        return 1;
    }
    
    int dagenTotGeboorte; // hoeveel dagen tussen de peildatum en geboortedatum van de gebruiker
    // moet berekent worden met aantal dagen per maand en schrikkeljaren
    
    int schrikkeljaar;
    if (jaarNu%4 == 0){
        schrikkeljaar = 1; // als het een schrikkeljaar is moet er 1 opgeteld worden bij de dagenInHetJaar vanaf de 3e maand
    }
    else{
        schrikkeljaar = 0; // als het geen schrikkeljaar is, is dit niet nodig dus blijft het 0
    }
    
    int verschilInJaren = jaar - jaarStart; // aantal jaren tussen geboorte en 1901
    int aantalSchrikkeljaren = verschilInJaren/4; // aantal schrikkeljaren sinds 1901 tot geboorte
    if (jaar%4 == 0){
        aantalSchrikkeljaren += 1;
    }
    
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
    
    dagenTotGeboorte = (verschilInJaren * 365) + (dagenInHetJaar - 1) + aantalSchrikkeljaren;
    // aantal jaren tussen peildatum en je geboorte
    // dagenInHetJaar -1. omdat 1 januari al meegerekent is in 1901 en wordt hierboven in de berekening van de dagen opnieuw geteld, dus dubbel
    
    int dagenVerschil = dagenTotGeboorte%7; // dagen verschil met de peildatum
    
    werkelijkeDag = datumStart + dagenVerschil;
    if (werkelijkeDag > 6){ // groter dan 6 kan werkelijkeDag niet zijn, want dan bestaat de dag niet meer (in dit geval, omdat maandag == 0 dus zondag == 6
        werkelijkeDag -= 7; // er moet dan een week van af gehaald worden, zodat de week weer opnieuw begint
    }
    
    char echteDag[2]; // dag in letter waarop persoon echt geboren is, zodat kan checken met invoer van de gebruiker
    if (werkelijkeDag == 0) {
        echteDag[0] = 'm';
        echteDag[1] = '\0'; // \0 wanneer geen invoer is
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
    
    
    if (echteDag[0] == geboorteDag && echteDag[1] == geboorteDagExtra) { // controleren of input van de gebruiker hetzelfde is als wat de geboortedag werkelijk is
        cout << "Goed!" << endl; // zo ja; goed
    }
    else{ // zo nee; dit is het wel
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
    
    int A, B, C, D;
    int deel1antw1, deel1antw2, deel2antw1, deel2antw2, antwoord;
    
    A = rand() % 20 + 1; // we gebruiken waardes tussen 1 en 20
    B = rand() % 20 + 1;
    C = rand() % 20 + 1;
    D = rand() % 20 + 1;
    
    cout << "Nu gaan we met de test beginnen" << endl;
  
    cout << "Wat is " << A << "/" << B << " + " << C << "/" << D << "?" << endl; //breuken optellen
    cout << "Vereenvoudig de breuk niet!" << endl;
    cout << "Geef eerst de bovenkant van de breuk" << endl; //geef antwoord in 2 delen
    cin >> deel1antw1;
    cout << "Geef nu de onderkant van de breuk" << endl;
    cin >> deel1antw2;
        
    cout << "Wat is " << A << "/" << B << " - " << C << "/" << D << "?" << endl; //breuken aftrekken
    cout << "Vereenvoudig de breuk niet!" << endl;
    cout << "Geef eerst de bovenkant van de breuk" << endl;
    cin >> deel2antw1;
    cout << "Geef nu de onderkant van de breuk" << endl;
    cin >> deel2antw2;
    
    if ((jaar > 1988) || (jaar == 1988 && maand < 9) || (jaar > 1988 && maand == 9 && dag <= 24)){
        //jonger dan 30 met jij aanspreken + andere alphavraag
        if (((deel1antw1 == (A*D) + (B*C)) && (deel1antw2 == (B*D))) && (deel2antw1 == (A*D) + (B*C)) && (deel2antw2 == (B*D))){ //wanneer het antwoord goed is
            cout << "Gefeliciteerd je bent toegelaten tot de betastudie." << endl;
        }
        else if (((deel1antw1 != ((A*D) + (B*C))) || (deel1antw2 != (B*D))) || (deel2antw1 != (A*D) + (B*C)) || (deel2antw2 != (B*D))){ //wanneer het antwoord fout is
            cout << "Helaas je bent niet toegelaten tot de betastudie." << endl;
            cout << "Misschien is een alphastudie beter voor jou." <<endl;
            cout << "Wie heeft de nachtwacht geschilderd?" << endl;
            cout << "1) Rembrandt van Rijn, 2) Vincent van Gogh" << endl;
            cout << "3) Pablo Picasso, 4) Jan Steen" << endl;
            cin >> antwoord;

            if (antwoord == 1){
                cout << "Gefeliciteerd je bent toegelaten tot de alphastudie" << endl;
            }
            else if (antwoord != 1){
                cout << "Helaas, je bent ook niet toegelaten tot de alphastudie" << endl;
            }
        }
    }
    else if ((jaar > 1988) || (jaar == 1988 && maand < 9) || (jaar > 1988 && maand == 9 && dag <= 24)){
        //ouder dan 30 met u aanspreken & andere alphavraag
        if (((deel1antw1 == (A*D) + (B*C)) && (deel1antw2 == (B*D))) && (deel2antw1 == (A*D) + (B*C)) && (deel2antw2 == (B*D))){ // wanneer het antwoord goed is
            cout << "Gefeliciteerd u bent toegelaten tot de betastudie." << endl;
        }
        else if (((deel1antw1 != ((A*D) + (B*C))) || (deel1antw2 != (B*D))) || (deel2antw1 != (A*D) + (B*C)) || (deel2antw2 != (B*D))){ //wanneer het antwoord fout is.
            cout << "Helaas u bent niet toegelaten tot de betastudie." << endl;
            cout << "Misschien is een alphastudie beter voor u." <<endl;
            cout << "Wie heeft de aanslag geschreven?" << endl;
            cout << "1) Harry Mulisch, 2) Herman Koch " << endl;
            cout << "3) Kees van Kooten, 4) Joke van Leeuwen" << endl;
            cin >> antwoord;
            
            if (antwoord == 1){
                cout << "Gefeliciteerd u bent toegelaten tot de alphastudie" << endl;
            }
            else if (antwoord != 1){
                cout << "Helaas, u bent ook niet toegelaten tot de alphastudie" << endl;
            }
        }
    }
    return 0;
}//main

