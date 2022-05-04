 #include<iostream>
 #include<fstream>
 #include<string>
 #include<vector>
 using namespace std;

 void ReadGrammar(string file, vector<string>& pro)
 {
       string line;
       ifstream myfile;
       myfile.open(file);
       while (getline(myfile, line))
       {
             pro.push_back(line);
       }
 }

 bool RecognizeString(vector<string>& pro, string str)
 {
  
       int n, v, s, p, i, l;
  
       n = str.length();
       v = pro.size();
  
       vector< vector< vector<bool> > > dp(n + 1, vector< vector <bool> >(n + 1, vector<bool>(26, false)));
  
       for (s = 0; s < n; ++s)
       {
             for (i = 0; i < v; ++i)
             {
                   if (pro[i].length() == 4 && pro[i][3] == str[s])
                   {
                         dp[1][s][pro[i][0] - 'A'] = true;
                   }
             }
       }
  
       for (l = 2; l <= n; ++l)
       {
             for (s = 0; s < n - l + 1; ++s)
             {
                   for (p = 1; p <= l - 1; ++p)
                   {
                         for (i = 0; i < v; ++i)
                         {
                               if (pro[i].length() == 5 && dp[p][s][pro[i][3] - 'A'] && dp[l - p][s + p][pro[i][4] - 'A'])
                               {
                                     dp[l][s][pro[i][0] - 'A'] = true;
                               }
                         }
                   }
             }
       }
  
       return dp[n][0]['S' - 'A'];
  
 }
  
 int main()
 {
  
       vector<string> pro;
       string str;
  
       ReadGrammar("text.txt", pro);
  
       cout << "A nyelvtani szabályok:" << endl;
  
       for (int i = 0; i < pro.size(); ++i)
       {
             cout << pro[i] << endl;
       }
  
       cout << "Adjon meg egy szót(feladatban: aabbaba): ";
       cin >> str;
  
       if (RecognizeString(pro, str))
             cout << "A szó levezethető" << endl;
       else
             cout << "A szó nem vezethető le" << endl;
  
 }
