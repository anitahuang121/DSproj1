#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
bool isPeak(int i,int j,int *matrix,int row,int col);
vector <int> PEAK;
int main(int argc,char *argv[]){
    fstream testcase;
    int i,j,row,col;
    int count = 0;
    string A,B,path1,path2;
    A = "/matrix.data";
    B = "/final.peak";
    if(argc!=2){
        cout<<"fail";
    }
    path1 = argv[1] + A;
    path2 = argv[1] + B;
    cout<<path1;
    testcase.open(path1,ios::in);
    if(!testcase) {
            cout<<"fail"<<endl;
            return 0;
    }
    testcase>>row;
    testcase>>col;
    int *matrix = new int [row*col];
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            testcase>>*(matrix+col*i+j);
        }
    }
    testcase.close();
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
                if(isPeak(i,j,matrix,row,col)) {
                PEAK.push_back(i+1);
                PEAK.push_back(j+1);
                count++;
            }
        }
    }
    //cout<<count<<endl;
    /*for(auto i=0;i<PEAK.size();i=i+2){
        cout<<PEAK.at(i)<<' ';
        cout<<PEAK.at(i+1)<<endl;
    }*/
    testcase.open(path2,ios::out);
    if(testcase.fail()) cout<<"fail2";
    else{
        testcase<<count<<endl;
        for(i=0;i<PEAK.size();i=i+2){
            testcase<<PEAK.at(i)<<' ';
            testcase<<PEAK.at(i+1)<<endl;
        }
    }
    testcase.close();
    return 0;
}
bool isPeak(int i,int j,int *matrix,int row,int col){
    if(i==0) {
            if (j==0) return(*(matrix+col*i+j)>=*(matrix+col*(i+1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j+1)));
            else if (j==col-1) return(*(matrix+col*i+j)>=*(matrix+col*(i+1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j-1)));
            else return(*(matrix+col*i+j)>=*(matrix+col*(i+1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j+1))&&*(matrix+col*i+j)>=*(matrix+col*i+(j-1)));
    }
    else if(i==row-1) {
            if (j==0) return(*(matrix+col*i+j)>=*(matrix+col*(i-1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j+1)));
            else if (j==col-1) return(*(matrix+col*i+j)>=*(matrix+col*(i-1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j-1)));
            else return(*(matrix+col*i+j)>=*(matrix+col*(i-1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j+1))&&*(matrix+col*i+j)>=*(matrix+col*i+(j-1)))  ;
    }
    else if (j==0) return(*(matrix+col*i+j)>=*(matrix+col*(i+1)+j)&&*(matrix+col*i+j)>=*(matrix+col*(i-1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j+1))) ;
    else if (j==col-1) return(*(matrix+col*i+j)>=*(matrix+col*(i+1)+j)&&*(matrix+col*i+j)>=*(matrix+col*(i-1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j-1)));
    else return (*(matrix+col*i+j)>=*(matrix+col*(i+1)+j)&&*(matrix+col*i+j)>=*(matrix+col*(i-1)+j)&&*(matrix+col*i+j)>=*(matrix+col*i+(j+1))&&*(matrix+col*i+j)>=*(matrix+col*i+(j-1)));
}
