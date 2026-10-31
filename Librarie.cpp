#include<iostream>
#include<string>

using namespace std;

enum Tip { FIZICA = 1, ONLINE = 2 };

class Librarie {
private:
	const int id;
	Tip tip;
	string denumire;
	float incasariTotale;
	int nrCarti;
	float* preturi;
public:
	static int nrLibrarii;


	Librarie() :id(++nrLibrarii) {
		this->denumire = "Librarie generala";
		this->incasariTotale = 0;
		this->tip = FIZICA;
		this->nrCarti = 0;
		this->preturi = nullptr;
	}


	Librarie(int id, string denumire, float incasariTotale, int nrCarti, float* preturi, Tip tip) :id(id) {
		nrLibrarii++;
		this->denumire = denumire;
		this->incasariTotale = incasariTotale;
		this->tip = tip;
		this->nrCarti = nrCarti;
		if (preturi != nullptr && nrCarti > 0) {
			this->preturi = new float[nrCarti];
			for (int i = 0; i < this->nrCarti; i++) {
				this->preturi[i] = preturi[i];
			}
		}
		else {
			this->nrCarti = 0;
			this->preturi = nullptr;
		}
	}


	Librarie(const Librarie& copie) :id(++nrLibrarii) {
		this->denumire = copie.denumire;
		this->incasariTotale = copie.incasariTotale;
		this->tip = copie.tip;
		this->nrCarti = copie.nrCarti;

		if (copie.preturi != nullptr) {
			this->preturi = new float[this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		else {
			this->preturi = nullptr;
		}
	}


	Librarie& operator=(const Librarie& copie) {
		if (this == &copie) {
			return *this;
		}
		this->denumire = copie.denumire;
		this->incasariTotale = copie.incasariTotale;
		this->tip = copie.tip;
		this->nrCarti = copie.nrCarti;

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}

		if (copie.preturi != nullptr) {
			this->preturi = new float[this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++) {
				this->preturi[i] = copie.preturi[i];
			}
		}
		return *this;
	}


	int getNrCarti() {
		return this->nrCarti;
	}

	void setNrCarti(int valoareNoua) {
		if (valoareNoua >= 0) {
			this->nrCarti = valoareNoua;
		}
		else {
			throw exception();
		}
	}



	float* getPreturi() {
		if (this->preturi == nullptr) {
			return nullptr;
		}
		float* vPreturi = new float[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			vPreturi[i] = this->preturi[i];
		}
		return vPreturi;
	}

	void setPreturi(float* vPreturi, int dim) {
		if (dim < 0) {
			throw exception();
		}

		if (this->preturi != nullptr) {
			delete[] this->preturi;
			this->preturi = nullptr;
		}

		if (vPreturi != nullptr && dim > 0) {
			this->nrCarti = dim;
			this->preturi = new float[dim];
			for (int i = 0; i < dim; i++) {
				this->preturi[i] = vPreturi[i];
			}
		}
		else {
			this->nrCarti = 0;
		}
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Incasari totale: " << this->incasariTotale;
		cout << endl << "Tip: ";
		if (this->tip == FIZICA) {
			cout << "FIZICA";
		}
		else {
			cout << "ONLINE";
		}
		cout << endl << "Nr. carti: " << this->nrCarti;
		if (this->nrCarti > 0) {
			cout << " cu urmatoarele preturi: ";
			for (int i = 0; i < this->nrCarti - 1; i++) {
				cout << this->preturi[i] << " lei, ";
			}
			cout << this->preturi[this->nrCarti - 1] << " lei.";
		}
	}


	bool operator<(const Librarie& l) {
		return this->nrCarti < l.nrCarti;
	}


	~Librarie() {
		cout << endl << "S-a apelat destructorul!";
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}


	void operator+=(float sumaDeAdunat) {
		this->incasariTotale += sumaDeAdunat;
	}


	bool operator!() {
		return this->incasariTotale > 0;
	}


	float operator()(float valoareDeAdaugat) {
		return this->incasariTotale + valoareDeAdaugat;
	}


	float& operator[](int index) {
		if (index >= 0 && index < this->nrCarti) {
			return this->preturi[index];
		}
		else {
			throw exception();
		}
	}


	friend ostream& operator<<(ostream& out, const Librarie& l) {
		out << endl << "Operator de afisare: ";
		out << endl << "Id: " << l.id;
		out << endl << "Denumire: " << l.denumire;
		out << endl << "Incasari totale: " << l.incasariTotale;
		out << endl << "Tip: ";
		if (l.tip == FIZICA) out << "FIZICA";
		if (l.tip == ONLINE) out << "ONLINE";
		out << endl << "Nr. carti: " << l.nrCarti;
		if (l.preturi != nullptr && l.nrCarti > 0) {
			out << endl << "Preturi: ";
			for (int i = 0; i < l.nrCarti - 1; i++) {
				out << l.preturi[i] << " lei, ";
			}
			out << l.preturi[l.nrCarti - 1] << " lei.";
		}
		return out;
	}


	friend istream& operator>>(istream& in, Librarie& l);


	Librarie operator++(int) {
		Librarie copie = *this;
		this->incasariTotale++;
		return copie;
	}


	Librarie& operator++() {
		this->incasariTotale++;
		return *this;
	}


	explicit operator int() {
		return this->nrCarti;
	}
};

istream& operator>>(istream& in, Librarie& l) {
	cout << endl << "Incasari totale: ";
	in >> l.incasariTotale;

	cout << endl << "Denumire: ";
	in >> l.denumire;

	cout << endl << "Tip (1 = FIZICA, 2 = ONLINE): ";
	int tip;
	in >> tip;
	if (tip == 1) l.tip = FIZICA;
	if (tip == 2) l.tip = ONLINE;

	cout << endl << "Nr. carti: ";
	in >> l.nrCarti;

	if (l.preturi != nullptr) {
		delete[] l.preturi;
		l.preturi = nullptr;
	}

	if (l.nrCarti > 0) {
		l.preturi = new float[l.nrCarti];
		for (int i = 0; i < l.nrCarti; i++) {
			cout << endl << "preturi[" << i << "]: ";
			in >> l.preturi[i];
		}
	}
	return in;
}

int Librarie::nrLibrarii = 0;

int main() {
	Librarie librarieGenerala;

	if (!librarieGenerala) {
		cout << endl << "Incasarile totale sunt pozitive!";
	}
	else {
		cout << endl << "Nu exista incasari!";
	}

	cout << endl << librarieGenerala(100);

	cout << librarieGenerala;

	float preturi[] = { 35.5f, 49.9f, 22.0f };
	Librarie* librarieCentrala = new Librarie(7, "Librarie Centrala", 85000, 3, preturi, FIZICA);
	(*librarieCentrala) += 150;

	if (librarieGenerala < *librarieCentrala) {
		cout << endl << "Libraria Generala are mai putine carti decat libraria Centrala!";
	}
	else {
		cout << endl << "Libraria Centrala are mai putine carti decat libraria Generala!";
	}

	(*librarieCentrala)[0] = 40;
	cout << endl << (*librarieCentrala)[0];

	cout << *librarieCentrala;



	Librarie librarie1 = librarieGenerala++;
	cout << librarie1;
	cout << librarieGenerala;

	Librarie librarie2 = ++librarieGenerala;
	cout << librarie2;
	cout << librarieGenerala;

	cout << endl << "Cast librarie -> int: " << int(*librarieCentrala);

	try {
		(*librarieCentrala)[10] = 5;
	}
	catch (...) {
		cout << endl << "Index invalid!";
	}

	delete librarieCentrala;

	cout << endl << "Numar librarii: " << Librarie::nrLibrarii << endl;
	return 0;
}