#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void docFile(ifstream& f1,string fname,int arr[10][10],int &n){
	char c;
	f1.open(fname.c_str(),ios::in);// bat dau mo file de doc, khac nhau chu i dau
	f1>>n;//doc tu file gan vao n
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
void luuFile(ofstream& f,string fname,int arr[10][10],int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			cout<<"arr["<<j<<"]["<<i<<"]=";
			cin>>arr[j][i];
		}
	}
	f.open(fname.c_str(),ios::out);
	f<<n<<endl;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			f<<arr[j][i]<<" ";
		}
		f<<endl;
	}
	f.close();
}
int main(){
	int arr1[10][10],n1;
	ifstream fileIn1;//doc tu file
	docFile(fileIn1,"input1.txt",arr1,n1);
	printMT(arr1,n1);
	cout<<endl;
	//----------------------DS ke
	for(int i=0;i<n1;i++){
		for(int j=0;j<n1;j++){
			if(arr1[i][j]==1&&i<j)
				cout<<i+1<<"	"<<j+1<<endl;
		}
	}
	//-------------------luu DS ke
	ofstream fileOut1;
	fileOut1.open("input1_2.txt",ios::out);
	fileOut1<<n1<<endl;
	for(int i=0;i<n1;i++){
		for(int j=0;j<n1;j++){
			if(arr1[i][j]==1&&i<j)
				fileOut1<<i+1<<" "<<j+1<<endl;
		}
	}
	fileOut1.close();
	//---------------------DS canh
	vector<int> arr2[100];
	for(int i=0;i<n1;i++){
		for(int j=0;j<n1;j++){
			if(arr1[i][j]==1&&i<j){
				arr2[i+1].push_back(j+1);
				arr2[j+1].push_back(i+1);
			}
		}
	}
	cout<<endl;
	for(int i=1;i<=n1;i++){
		cout<<i<<" : ";
		for(int x=0;x<arr2[i].size();x++){
			cout<<arr2[i][x]<<" ";
		}
		cout<<endl;
	}
	//--------------luu file DS canh
	ofstream fileOut2;
	fileOut2.open("input1_1.txt",ios::out);
	fileOut2<<n1<<endl;
	for(int i=1;i<=n1;i++){
		for(int x=0;x<arr2[i].size();x++){
			fileOut2<<arr2[i][x];
		}
		fileOut2<<endl;
	}
	fileOut2.close();
}
