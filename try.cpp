#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
bool isPeak(int i,int j,int *matrix,int row,int col);
vector <int> PEAK;
int main(int argc,char *argv[]){
    fstream testcase;
    int i,j,row,col,nowi,ju,a=0,b;
    int A1;
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
    int *matrix = new int [2*col];
    for(i=0;i<row;i++){
        nowi = i%2;
        for(j=0;j<col;j++){
            testcase>>A1;
            if(i==0) matrix[j] = A1;
            else if(i==1){
                if(j==0) {if(*(matrix+j)>=A1 && *(matrix+j)>=*(matrix+j+1))  {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}}
                else if(j==col-1) {if(*(matrix+j)>=A1 && *(matrix+j)>=*(matrix+j-1))   {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
                }
                else {if(*(matrix+j)>=A1 && *(matrix+j)>=*(matrix+j+1) && *(matrix+j)>=*(matrix+j-1))   {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
                }
                matrix[col+j] = A1; 
            }
            else if(i>1&&i<row-1){
                ju=(nowi+1)%2;
                if(j==0) {if(*(matrix+col*ju+j)>=A1&&*(matrix+col*ju+j)>=*(matrix+col*ju+j+1)&&*(matrix+col*ju+j)>=*(matrix+col*nowi+j))  {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
            }
                else if(j==col-1) {if(*(matrix+col*ju+j)>=A1&&*(matrix+col*ju+j)>=*(matrix+col*ju+j-1)&&*(matrix+col*ju+j)>=*(matrix+col*nowi+j))  {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
            }
                else {if(*(matrix+col*ju+j)>=A1 && *(matrix+col*ju+j)>=*(matrix+col*ju+j+1) && *(matrix+col*ju+j)>=*(matrix+col*ju+j-1)&&*(matrix+col*ju+j)>=*(matrix+col*nowi+j))   {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
            }
                matrix[col*nowi+j] = A1;
            }
            else if(i==row-1){
                ju=(nowi+1)%2;
                if(j==0) {if(*(matrix+col*ju+j)>=A1 && *(matrix+col*ju+j)>=*(matrix+col*ju+j+1) &&*(matrix+col*ju+j)>=*(matrix+col*nowi+j) )  {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
            }
                else if(j==col-1) {if(*(matrix+col*ju+j)>=A1 && *(matrix+col*ju+j)>=*(matrix+col*ju+j-1) && *(matrix+col*ju+j)>=*(matrix+col*nowi+j) )  {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;}
            }
                else { if(*(matrix+col*ju+j)>=A1 && *(matrix+col*ju+j)>=*(matrix+col*ju+j+1) && *(matrix+col*ju+j)>=*(matrix+col*ju+j-1) && *(matrix+col*ju+j)>=*(matrix+col*nowi+j))  {
                PEAK.push_back(i);
                PEAK.push_back(j+1);
                count++;
            }}
                matrix[col*nowi+j] = A1;
                }
                
        }
        
    }
    nowi=(row-1)%2;
    ju = (nowi+1)%2;
    for(a=0;a<col;a++){
                if(a==0) {if( *(matrix+col*nowi+a)>=*(matrix+col*ju+a) && *(matrix+col*nowi+a)>=*(matrix+col*nowi+a+1))  {
                PEAK.push_back(row);
                PEAK.push_back(a+1);
                count++;}
            }
                else if(a==col-1) {if(*(matrix+col*nowi+a)>=*(matrix+col*ju+a) && *(matrix+col*nowi+a)>=*(matrix+col*nowi+a-1))  {
                PEAK.push_back(row);
                PEAK.push_back(a+1);
                count++;}
            }
                else {if( *(matrix+col*nowi+a)>=*(matrix+col*ju+a) && *(matrix+col*nowi+a)>=*(matrix+col*nowi+a+1) && *(matrix+col*nowi+a)>=*(matrix+col*nowi+a-1))  {
                PEAK.push_back(row);
                PEAK.push_back(a+1);
                count++;;
            }}
                }
    testcase.close();
   /* for(auto i=0;i<PEAK.size();i=i+2){
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