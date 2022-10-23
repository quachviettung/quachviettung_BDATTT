#include<iostream>
#include<fstream>
using namespace std;

void docFile(ifstream& f1,string fname,int arr[10][10],int &n){
	char c;
	f1.open(fname.c_str(),ios::in);
	f1>>n;
	int j=0;
	while(!f1.eof()){
		for(int i=0;i<n;i++){
			f1>>arr[j][i];
		}
		j++;
	}
	
	f1.close();
}
void printMT(int arr[10][10],int n){
	for(int k=0;k<n;k++){
		for(int l=0;l<n;l++){
			cout<<arr[k][l]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int arr1[10][10],arr2[10][10],n1,n2;
	ifstream fileIn1;
	docFile(fileIn1,"input1.txt",arr1,n1);
	printMT(arr1,n1);
}
