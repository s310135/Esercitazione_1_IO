#include <iostream>
#include <fstream>
#include <iomanip> //includo le librerie

double valore;
double somma=0;
double min = 1.0;
double max = 5.0;
double intervallomin = -1.0;
double intervallomax = 2.0;
double media=0;
int n=1;
int main()
{
	std::ifstream file("data.txt");
	std::ofstream soluzione("result.txt", std::ofstream::trunc);  //se non esiste lo crea
	soluzione << "# \N Mean\n";
	
	if (file.fail())
	{
        std::cerr << "Il file non esiste" << std::endl;
		return 1;
	}
    else
		std::cerr << "Ho trovato il file!" << std::endl;
	
	std::string riga;
	while(std::getline(file, riga))
	{	
		double numero =std::stod(riga);
		if (numero == min){
			std::cout << "il valore " << numero << std::setprecision(16) <<std::scientific << " corrisponde a: " << intervallomin << std::endl;
			valore = numero ;
		}else if (numero == max){
			std::cout << "il valore " << numero << std::setprecision(16) << std::scientific <<" corrisponde a: " << intervallomax << std::endl;
			valore = numero;
		}else{
			valore = (intervallomin + ((numero - min) * (intervallomax - intervallomin) / (max - min)));
			std::cout << "il valore " << numero << std::setprecision(16) <<std::scientific << " corrisponde a: " << valore << std::setprecision(16)<<std::scientific << std::endl;
		}
		somma = valore + somma;
		media = (somma)/n;
		soluzione << n << " "  << std::setprecision(16) << std::scientific << media << std::endl;
		//std::cout << n << " " << std::setprecision(16) << std::scientific << media  << std::endl;

		n=n+1;
	}
	
	   
	soluzione.close();
			
	file.close();
    return 0;
}
