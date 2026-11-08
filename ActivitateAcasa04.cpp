/*
// 1. O funcție care calculează prețul final după un discount procentual.

#include <iostream>
using namespace std;

// functia: primeste pretul si procentul, returneaza pretul dupa discount

float pretRedus(float pret, float procent) {
    return pret - pret * procent / 100;
}


int main() {
    float pret;
    float procent;

    cout << "Introdu pretul: ";
    cin >> pret;

    cout << "Introdu procentul de discount: ";
    cin >> procent;

    float rezultat = pretRedus(pret, procent);

    cout << "Pretul dupa discount este: " << rezultat << " lei" << endl;

    return 0;
}
*/


/*
// 2. Patratul unui numar
#include <iostream>
using namespace std;

int patrat(int n) {
    return n * n;
}

int main() {
    int numar;
    cout << "Introdu un numar: ";
    cin >> numar;

    cout << "Patratul este: " << patrat(numar) << endl;
    return 0;
}
*/



/*

// 3. Aria dreptunghiului

#include <iostream>
using namespace std;

float arieDreptunghi(float lungime, float latime) {
    return lungime * latime;
}

int main() {
    float lungime, latime;
    cout << "Lungimea: ";
    cin >> lungime;
    cout << "Latimea: ";
    cin >> latime;

    cout << "Aria este: " << arieDreptunghi(lungime, latime) << endl;
    return 0;
}

*/

/*
// 4. Perimetrul dreptunghiului

#include <iostream>
using namespace std;

float perimetruDreptunghi(float lungime, float latime) {
    return 2 * (lungime + latime);
}

int main() {
    float lungime, latime;
    cout << "Lungimea: ";
    cin >> lungime;
    cout << "Latimea: ";
    cin >> latime;

    cout << "Perimetrul este: " << perimetruDreptunghi(lungime, latime) << endl;
    return 0;
}

*/




/*

// 5. Minimul dintre 2 numere

#include <iostream>
using namespace std;

int minim(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    int x, y;
    cout << "Primul numar: ";
    cin >> x;
    cout << "Al doilea numar: ";
    cin >> y;

    cout << "Minimul este: " << minim(x, y) << endl;
    return 0;
}

*/




/*
// 6. Pret cu discount fix

#include <iostream>
using namespace std;

float pretMinusDiscount(float pret, float discount) {
    return pret - discount;
}

int main() {
    float pret, discount;
    cout << "Pretul: ";
    cin >> pret;
    cout << "Discountul (in lei): ";
    cin >> discount;

    cout << "Pret final: " << pretMinusDiscount(pret, discount) << " lei" << endl;
    return 0;
}

*/


/*
// 7. Transformare grade Celsius în Fahrenheit

#include <iostream>
using namespace std;

float celsiusInFahrenheit(float c) {
    return c * 9 / 5 + 32;
}

int main() {
    float grade;
    cout << "Temperatura in Celsius: ";
    cin >> grade;

    cout << grade << " C = " << celsiusInFahrenheit(grade) << " F" << endl;
    return 0;
}

*/