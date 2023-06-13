#include <vector>
#include <algorithm>  //shuffle
#include <iostream>

using namespace std;

void Nosaukums(){
  cout<<"\x1b[38;5;0m  <<  \x1b[38;5;221mC++ Viendimensiju Masīvi Test\x1b[38;5;221m\x1b[38;5;0m >> \x1b[0m\n\n\n";
}

void Jautajumi(){
  int punkti=0;
  int CikJautajumusParadit = 10;    //Cik jautājumus paradīt testā?
  int KopJautajumuSkaits = 15;      //Kopējais jautājumu skaits


  //-----------------------------Jautājumu teksts
  vector<string> VisiJautajumi = {      
  "Ja masīva pēdējam elementam indekss ir 4, kāds ir masīva lielums?", 
  "Kā nomainīt masīva otro elementu uz 4?", 
  "Dati masīva tiek izvietoti ___.", 
  "Viendimensiju masīvu var iedomāties kā ___.", 
  "Viendimensiju masīva var ievietot ___ ___ ___.", 
  "Viendimensiju masīva katram elementam ir savs ___, sākot no ___.", 
  "Kad mēs veidojam masīvu, datu tipam seko tā ___.", 
  "Kā pareizi definēt masīva lielumu? (x - masīva lielums)", 
  "Ja masīva int datu tipa mēs ierakstām mazāk elementu, nekā ir mūsu masīva lielums, tad elementi, kurus neesam definējuši, būs ___.", 
  "Lai izvadītu lielu elementu skaitu, mēs izmantojam ciklu ___.", 
  "Lai masīvu, kas sakārtots augošā secībā, sakārtotu dilstošā secībā, vajag nomainīt zīmi ___ uz zīmi___.", 
  "Lai izveidotu masīvu, vispirms ir jānorāda, kāda veida ___ tajā glabāsim", 
  "Kā masīvam pievienot elementus?", 
  "Kurā rindā ir kļūda?\n\na. atzimes[4] = {1, 3, 5, 2};\nb. for (int i=0; i<4; i+){\nc.   cout<<atzimes[i]<<endl;}", 
  "Izvēlēties pareizu apgalvojumu!"};

  //-----------------------------Atbildes varianti
  vector<vector<string>> VisasAtbildes(15, vector<string>(4));
  VisasAtbildes[0] = {"4", "5", "3", "4.0"};
  VisasAtbildes[1] = {"masivs[0] = 4", "masivs[1] = 3", "masivs[2] = 4", "masivs[1] = 4"};
  VisasAtbildes[2] = {"secīgi", "nejauši", "palielināti", "kārtīgi"};
  VisasAtbildes[3] = {"plāksni", "lodziņu", "plauktu", "skapi"};
  VisasAtbildes[4] = {"divu tipu datus", "viena tipa datus", "vairāku tipu datus", "dažādus datus"};
  VisasAtbildes[5] = {"elements, indekss", "indekss, 1", "0", "indekss, 0"};
  VisasAtbildes[6] = {"datu tips", "indekss", "elements", "nosaukums"};
  VisasAtbildes[7] = {"int masivs[x];", "int masivs{x}", "string masivs[x-1]", "int masivs[] = {x}"};
  VisasAtbildes[8] = {"neviens atbilžu variants nav pareizs", "1", "0", "null"};
  VisasAtbildes[9] = {"if", "cout<<", "int", "for"};
  VisasAtbildes[10] = {"vairāk, mazāk", "mazāk, vairāk", "vairāk, ==", "vairāk, lielāk"};
  VisasAtbildes[11] = {"datus", "skaitļus", "burtus", "indeksus"};
  VisasAtbildes[12] = {"string skaitli[3] = {1,2,3}", "int skaitli[3] = {1,2,3}", "skaitli int[3] = {1,2,3}", "int skaitli[1,2,3]"};
  VisasAtbildes[13] = {"a", "b un c", "a un c", "b"};
  VisasAtbildes[14] = {"Viendimensiju masīvam ir fiksēts izmērs", "Viendimensiju masīvam nav fiksēts izmērs", "Viendimensiju masīviem ir tads nosaukums jo viņi var glabāt tikai vienu datu tipu", "Viendimensiju masīvi ir grūti"};

  //-----------------------------Pareizas atbildes indekss
  vector<int> AtbildesIndekss = {
  2, 4, 1, 3, 2, 4, 4, 1, 3, 4, 1, 1, 2, 4, 1 };
//                           10
  vector<int> NepareizasAtbildes;    //Vektors kurš glabās neparezas atbildes indeksu

  vector<int> NepareizasAtbildesNr;
  
  vector<int> randSk;        //Vektors ar skaitļiem nejaušā secībā
  for(int i=0; i<KopJautajumuSkaits; i++){
    randSk.push_back(i);
  }
  random_shuffle(randSk.begin(), randSk.end());    //Sajaukt skaitļus vektorā
  
  int nejausausIndekss;
  int lietotajaAtbilde;
  for(int i=0; i<CikJautajumusParadit; i++){
    system("clear");
    Nosaukums();
    
    //cout<<"\t\t\trandSk tagad ir = "<<randSk[i]<<endl<<endl;  //parbaudijums*
    
    cout<<i+1<<". Jautājums\n"<<VisiJautajumi[randSk[i]]<<endl<<endl;
    for(int j=0; j<4; j++){
      cout<<j+1<<". "<<VisasAtbildes[randSk[i]][j]<<endl;
    }
    cout<<endl<<"~ ";
    cin>>lietotajaAtbilde;

    //-----------------------------Pārbaude vai atbilde ir diapazona no 1 līdz 4 
    do{
      if(lietotajaAtbilde<1 || lietotajaAtbilde>4){
        cout<<"\n\e[0;31mDarbība nepastāv!\e[0m\n\nIzvēlies atbildi diapazonā no 1 līdz 4!\n\n~ ";
        cin>>lietotajaAtbilde;
      }
    }while(lietotajaAtbilde<1 || lietotajaAtbilde>4);
    //-----------------------------Pārbaude vai atbilde ir pareiza
    if(lietotajaAtbilde==AtbildesIndekss[randSk[i]]){
      cout<<"\n\e[0;32mPareizi! :)\e[0m";
      punkti++;
    }else{
      cout<<"\n\e[0;31mNepareizi! :(\e[0m";
      NepareizasAtbildes.push_back(randSk[i]);
      NepareizasAtbildesNr.push_back(i+1);
    }
    //-----------------------------Ievadi 1 lai turpināt
    int talak;
    do{
      cout<<"\n\n\e[1;37mIevadi '1' lai turpināt pildīt testu:\n\n\e[0m~ ";
      cin>>talak;
      if(talak!=1){
        cout<<"\n\e[0;31mDarbība nepastāv!\e[0m";
      }
    }while(talak!=1);
  }
  
  //-----------------------------Rezultāts
  system("clear");
  Nosaukums();
  cout<<"\n\nTavs punktu skaits: \x1b[38;5;10m"<<punkti<<"\x1b[0m\n\n";
  int uzSakumu;
  if(!NepareizasAtbildes.empty()){
    
    cout<<"Jautājumi, uz kuriem tu atbildēji nepareizi:\n\n\n";
    for(int i=0; i<NepareizasAtbildes.size(); i++){
      cout<<NepareizasAtbildesNr[i]<<". "<<VisiJautajumi[NepareizasAtbildes[i]]<<endl<<endl;
    }
  }else{
    cout<<"\n\nMalacis!\n\nTu atbildēji uz visiem jautājumiem bez nevienas kļūdas!";
  }
  
  do{
    cout<<"\n\nIevadi '2' lai atgriezties uz sākumu: \n\n";
    cin>>uzSakumu;
    if(uzSakumu!=2){
      cout<<"\nDarbība nepastāv!";
    }
  }while(uzSakumu!=2);
}


//-----------------------------Main daļa
int main() {
  srand(time(0));
  
  int izvele;
  bool apturet=false;

  //---------------Sākumlogs
  do{
    system("clear");
    Nosaukums();
    cout<<"Sveicināti testā par viendimensiju masīviem programmēšanas valodā C++! \n\nTestā ir 10 jautājumi, kas ir sakārtoti nejaušā secībā. Katram jautājumam ir 4 iespējamās atbildes, bet tikai 1 no tām ir pareiza. \n\nPēc tam, kad atbildēsiet uz jautājumus, programma parādīs, vai jūs atbildējāt pareizi vai nē. Testa beigās jums tiks sniegts jūsu punktu skaits un jautājumu saraksts, uz kuriem jūs atbildējāt nepareizi!\n\nIzvēlies darbību:\n\n";
    cout<<"\x1b[38;5;10m1 - Sākt testu\n";
    cout<<"\x1b[38;5;202m0 - Apturēt programmu\n\n\x1b[0m~ \x1b[0m";
    cin>>izvele;

    switch(izvele){
      case 1:
        Jautajumi();
      break;
      
      case 0:
        system("clear");
        cout<<"\x1b[38;5;202m!Programma ir apturēta!";
        apturet=true;
      break;

      default:
        int atpakal=0;
        do{
          system("clear");
          cout<<"\x1b[38;5;202m!Darbība nepastāv, rādas kļūda!\n\n\n\x1b[0mIevadi '\x1b[38;5;10m1\x1b[0m' lai atgriezties!\n\n~ ";
          cin>>atpakal;
          system("clear");
        }while(atpakal!=1);
    }
  }while(apturet==false);
}