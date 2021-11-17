
/* Màxim i mínim d'un vector (no main) */

#include <iostream>
#include <vector>
using namespace std;

struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    parint max_and_min1;
    
    max_and_min1.prim = v[0];
    max_and_min1.seg = v[0];
    
    int size = v.size();
    
    for (int i = 1; i < size; ++i) {
        
        if (v[i] > max_and_min1.prim) max_and_min1.prim = v[i];
        else if (v[i] < max_and_min1.seg) max_and_min1.seg = v[i];
    }
    return max_and_min1;
}
 
pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int, int> max_and_min2;
    
    max_and_min2.first = v[0];
    max_and_min2.second = v[0];
    
    int size = v.size();
    
    for (int i = 1; i < size; ++i) {
        
        if (v[i] > max_and_min2.first) max_and_min2.first = v[i];
        else if (v[i] < max_and_min2.second) max_and_min2.second = v[i];
    }
    
    return max_and_min2;
}
 
void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    int size = v.size();
    
    x = v[0];
    y = v[0];
    for (int i = 1; i < size; ++i) {
        
        if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    }
}

