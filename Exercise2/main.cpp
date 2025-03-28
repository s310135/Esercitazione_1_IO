#include <iostream>					//includo le librerie
#include <fstream>
#include <iomanip> 					

double valore; 						//è il valore mappato nella funzione
double somma=0;						//è la somma di n valori
double min = 1.0;	
double max = 5.0;
double intervallomin = -1.0;		//è l'intervallo in cui devo mappare i nuovi valori
double intervallomax = 2.0;			//è l'intervallo in cui devo mappare i nuovi valori
double media=0;						//è la media di n valori
int n=1;							//è il numero intero che utilizzo per fare i calcoli
int main()
{
	std::ifstream file("data.txt");									//apro il file
	std::ofstream soluzione("result.txt", std::ofstream::trunc);  	//apro il file result, se non esiste lo crea
	soluzione << "# \N Mean\n";										//scrivo la prima riga con le "definizioni"
	
	if (file.fail())												//se non riesce ad aprire il file la risposta è true quindi esegue l'if
	{
        std::cerr << "Il file non esiste" << std::endl;
		return 1;													//cioè c'è un errore
	}
    else															//è riuscito ad aprire il file
		std::cerr << "Ho trovato il file!" << std::endl;
	
	std::string riga;												//crea la variabile riga
	while(std::getline(file, riga))									//legge una riga del file alla volta finchè le righe non finiscono
	{	
		double numero =std::stod(riga);								//trasforma la stringa in un numero double
		if (numero == min){
			std::cout << "il valore " << numero << std::setprecision(16) << std::scientific << " corrisponde a: " << intervallomin << std::endl;
			valore = numero ;
			//stampa il nuovo valore mappato con una precisione di macchina di 16 e la notazione scientifica
		}else if (numero == max){
			std::cout << "il valore " << numero << std::setprecision(16) << std::scientific <<" corrisponde a: " << intervallomax << std::endl;
			valore = numero;
		}else{
			valore = (intervallomin + ((numero - min) * (intervallomax - intervallomin) / (max - min)));
			//calcolo per mappare il nuovo valore in un intervallo
			std::cout << "il valore " << numero << std::setprecision(16) <<std::scientific << " corrisponde a: " << valore << std::setprecision(16)<<std::scientific << std::endl;
		}
		somma = valore + somma;										//dove somma a destra è il valore precedente che viene poi aggiornato
		media = (somma)/n;
		soluzione << n << " "  << std::setprecision(16) << std::scientific << media << std::endl;			//stampo nel file il nuovo valore
		//std::cout << n << " " << std::setprecision(16) << std::scientific << media  << std::endl;

		n=n+1;				//aggiorno il valore di n
	}
	
	   
	soluzione.close();
			
	file.close();				//chiudo i file
    return 0;					//se non ci sono errori mi restituisce il valore 0, altrimenti 1
}