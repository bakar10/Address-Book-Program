#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PhoneDirectory{
private:
    string Fname,Lname;
    int Phonenum;
public:
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;
    vector <string> sortedv;
    vector <string> sortedp;
    vector <string> sortedf;
    void Addentry(){
        string Fi,La,fu;
        string P;
        cout<<"Enter First name: "<<endl;
        cin>>Fi;
        cout<<"Enter Last name: "<<endl;
        cin>>La;
        cout<<"Enter Phone number: "<<endl;
        cin>>P;
        fu=Fi+" "+La;
        v1.push_back(fu);
        v2.push_back(P);
        v3.push_back(Fi);
        sortedv.push_back(fu);
        sortedp.push_back(P);
        sortedf.push_back(Fi);


    }
    void LookupPhonenumber(string num){ int a=-1;
        for(int i=0;i<v2.size();i++){
            if(v2[i]==num){
                cout<<"Name: "<<v1[i]<<endl;
                cout<<"Phone number: "<<v2[i]<<endl;
                a=1;
                break;
            }
        }
        if(a==-1){
            cout<<"Not Found"<<endl;
        }
    }
    void LookupFirstName(string name){ int a=-1;
        for(int i=0;i<v3.size();i++){
            if(v3[i]==name){
                cout<<"Name: "<<v1[i]<<endl;
                cout<<"Phone number: "<<v2[i]<<endl;
                a=1;
                break;
            }
        }
        if(a==-1){
            cout<<"Not Found"<<endl;
        }
    }
    void DeleteByFirstName(string nam){ int a=-1;
        for(int i=0;i<v3.size();i++){
            if(v3[i]==nam){
                v3.erase(v3.begin()+i);
                v2.erase(v2.begin()+i);
                v1.erase(v1.begin()+i);

                a=1;


            }
            if(sortedf[i]==nam){
                sortedv.erase(sortedv.begin()+i);
                sortedp.erase(sortedp.begin()+i);
                sortedf.erase(sortedf.begin()+i);

            }
        }

        if(a==-1){cout<<"Not Found\n";}
    }
    void insertionSort () {

        for (int i = 1, j; i < sortedv.size(); i++){
            string tmp = sortedv [i];
            string tmp2 = sortedp[i];
            string tmp3 = sortedf[i];
            for (j = i; j > 0 && tmp < sortedv [j-1]; j--){
                sortedv[j]=sortedv[j-1];
                sortedf[j]=sortedf[j-1];
                sortedp[j]=sortedp[j-1];
            }
            sortedv[j] = tmp;
            sortedf[j] = tmp3;
            sortedp[j] =tmp2;
        }


    }
    void SelectionSort(){
        for (int i = 0, j, least; i < sortedv.size()-1; i++){
            for (j = i+1, least = i; j < sortedv.size(); j++){
                if (sortedv [j] < sortedv [least]){
                    least = j;
                }
                swap(sortedv[least],sortedv[i]);
                swap(sortedp[least],sortedp[i]);
                swap(sortedf[least],sortedf[i]);
            }

        }
    }
    void BubbleSort(){
        for (int i = 0; i < sortedv.size() - 1; i++){
            for (int j = 0; j < sortedv.size()- i-1; j++) {
                if (sortedv [j] > sortedv[j + 1]) {
                    swap(sortedv [j], sortedv [j + 1]);
                    swap (sortedp [j], sortedp [j + 1]);
                    swap (sortedf [j], sortedf [j + 1]);

                }
            }
        }
    }



    void PrintSorted(){
        for(int i=0;i<sortedv.size();i++){
            cout<<"Name: "<<sortedv[i]<<endl;
            cout<<"Phone number: "<<sortedp[i]<<endl;
        }
    }

};
int main() {
    PhoneDirectory obj;
    int n;
    while (1){
        cout<<"Enter number:"
              "1. Add an entry to the directory\n"
              "2. Look up a phone number\n"
              "3. Look up by first name\n"
              "4. Delete an entry from the directory\n"
              "5. List All entries in phone directory\n"
              "6. Exit form this program\n";
        cin>>n;
        if(n==1){obj.Addentry();}
        else if(n==2){   cout<<"Enter number: \n";
            string m;
            cin>>m;
            obj.LookupPhonenumber(m);}
        else if(n==3){     cout<<"Enter First Name: \n";
            string b;
            cin>>b;
            obj.LookupFirstName(b);}
        else if(n==4)     {   cout<<"Enter Name you want to delete: \n";
            string a;
            cin>>a;
            obj.DeleteByFirstName(a);
        }
        else if(n==5){
            obj.insertionSort();
            obj.PrintSorted();
        }


        else if(n==6){break;}








    }
}