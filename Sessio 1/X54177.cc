
/* Suma de secuencias de enteros */

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        
        int next, sum = 0;
        while (cin >> next and next != m) {
            
            sum += next;
        }
        string s;
        getline(cin,s);
        cout << "La suma de la secuencia " << i << " es " << sum << endl;
    }
}

