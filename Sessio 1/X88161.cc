
/* Classificació de la lliga */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <vector<pair<int,int> >> matrix;

struct teams{
    
    int number;
    int total = 0;
    int gols_marcats = 0;
    int gols_rebuts = 0;
    int dif_gols;
};

matrix read_matrix(int n) {
    
    matrix m(n, vector<pair<int,int>>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            cin >> m[i][j].first;
            cin >> m[i][j].second;
        }
    }
    return m;
}

void team_names(vector<teams>& v) {
    
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
        
        v[i].number = i+1;
    }
}

void result(const matrix& m, vector<teams>& v) {
    
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            if (i != j) {
                
                if (m[i][j].first > m[i][j].second) {
                    
                    v[i].total += 3;
                }
                else if (m[i][j].first < m[i][j].second){
                    
                    v[j].total += 3;
                }
                else {
                    
                    v[i].total += 1;
                    v[j].total += 1;
                }
                
                v[i].gols_marcats += m[i][j].first;
                v[i].gols_rebuts += m[i][j].second;
                
                v[j].gols_rebuts += m[i][j].first;
                v[j].gols_marcats += m[i][j].second;
            }
        }
    }
}

void print_vector(const vector<teams>& v) {
    
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
        
        cout << v[i].number << ' ';
        cout << v[i].total << ' ';
        cout << v[i].gols_marcats << ' ';
        cout << v[i].gols_rebuts << endl;
    }
}

bool cmp(const teams& a, const teams& b) {
    
    if (a.total == b.total) {
        
        if (a.dif_gols == b.dif_gols) {
            
            return a.number < b.number;
        }
        else return a.dif_gols > b.dif_gols;
    }
    else return a.total > b.total;
}

void dif_gols(vector<teams>& v) {
    
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
        
        v[i].dif_gols = v[i].gols_marcats - v[i].gols_rebuts;
    }
}

int main() {
    
    int n;
    cin >> n;
    
    matrix m = read_matrix(n);
    
    vector<teams> v(n);
    
    team_names(v);
    result(m, v);
    
    dif_gols(v);
    
    sort(v.begin(), v.end(), cmp);
    print_vector(v);
}

