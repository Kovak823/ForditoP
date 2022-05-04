#include <iostream>
#include <vector>

using namespace std;

void Nyelvtan();
int ertek(char ch);
vector<char> jtabla(vector<string> jertek);
vector<char> btabla(vector<string> bertek);
void tabla(vector<string> boszabaly, vector<string> joszabaly);

int main(){
	cout << "Kérem adja meg a szabályokat(példa: A->bAc): \n";
	cout << "Ha nincs több szabály írja az új sorba, hogy 'vege'\n";
	Nyelvtan();
}

void Nyelvtan(){
	string szabalyok;
	vector<string> boszabaly;
	vector<string> joszabaly;

	while(szabalyok !="vege"){
		string sz = szabalyok;
		string jl = "->";
		size_t pos = 0;
		string token;
		while((pos = sz.find(jl)) != std::string::npos){
			token = sz.substr(0, pos);
			sz.erase(0,pos + jl.length());
			boszabaly.push_back(token);
			joszabaly.push_back(sz);
		}
		cin >> szabalyok;
	}
	tabla(boszabaly, joszabaly); 
}
void tabla(vector<string> boszabaly, vector<string> joszabaly){
	vector<string> joindex;
	vector<int> boindex;
	vector<char> joelemek, boelemek, elemek;

	boelemek = btabla(boszabaly);
	joelemek = jtabla(joszabaly);
	elemek = btabla(boszabaly);
	for (int n = 0; n < joelemek.size(); n++)
	{
		elemek.push_back(joelemek[n]);
	}
	cout << "Tábla:\n\t";
	for(vector<char>::iterator j = joelemek.begin(); j < joelemek.end(); ++j){
		cout << *j << "\t";
	}
	cout << "\n\n";
	for(vector<char>::iterator k = elemek.begin(); k < elemek.end(); ++k){
		cout << *k << "\t";
		for(int j = 0; j < joelemek.size(); j++){
			if(ertek(*k) >= 65 && ertek(*k) <= 90){
				for(int i= 0; i < boszabaly.size(); i++){
					if(*k == boszabaly[i][0]){
						boindex.push_back(i);
					}
				}
				for(int i = 0; i < boindex.size(); i++){
					joindex.push_back(joszabaly[boindex[i]]);
				}
				if(joelemek[j] == joindex[0][0]){
					cout << "(" << joelemek[0] << "," << boindex[0] + 1 << ")" << "\t";
				}
				else if (joelemek[j] == joindex[0][0]){
					cout << "(" << joindex[1] << "," << boindex[1] + 1 << ")" << "\t";
				}
				else {
					cout << "error" << "\t";
				}
				boindex.clear();
				joindex.clear();
			}
			else if(*k == '#' && joelemek[j] == '#'){
				cout << "accept" << "\t";
			}
			else if(*k == joelemek[j]){
				cout << "pop" << "\t";
			}
			else{
				cout << "error" << "\t";
			}
		}
		cout << endl << endl;
	}
}
vector<char> jtabla(vector<string> jertek){
	vector<char> adatok;
	for(int i = 0; i < jertek.size(); i++){
		for(int j = 0; j < jertek[i].size(); j++){
			if(ertek(jertek[i][j]) >= 97 && ertek(jertek[i][j]) <= 122){
				if(adatok.size() > 0){
					for(int m = 0; m < adatok.size(); m++){
						if(adatok[m] == jertek[i][j]){
							break;
						}
						else if(m + 1 == adatok.size()){
							adatok.push_back(jertek[i][j]);
						}
					}
				}
				else{
					adatok.push_back(jertek[i][j]);
				}
			}
		}
	}
	adatok.push_back('#');
	return adatok;
}
vector<char> btabla(vector<string> bertek){
	vector<char> adatok;
	for(int i = 0; i < bertek.size(); i++){
		for(int j = 0; j < bertek[i].size(); j++){
			if(ertek(bertek[i][j]) >= 65 && ertek(bertek[i][j]) <= 90){
				if(adatok.size() > 0){
					for(int m = 0; m < adatok.size(); m++){
						if(adatok[m] == bertek[i][j]){
							break;
						}
						else if(m + 1 == adatok.size()){
							adatok.push_back(bertek[i][j]);
						}
					}
				}
				else{
					adatok.push_back(bertek[i][j]);
				}
			}
		}
	}
	return adatok;
}
int ertek(char ch){
	int ertek = ch;
	return ertek;
}