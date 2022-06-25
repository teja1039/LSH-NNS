#include <bits/stdc++.h>

using namespace std;

/* function for dot product*/
double dot(int* a,double* b,int d){
  double res=0;
  for(int i=0;i<d;i++){
      res=res+(a[i]*b[i]);
  }
  return res;
}

/*hamming distance between two points*/
int dist(int* a,int* b,int n){
  int d=0;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      d++;
    }
  }
  return d;
}

/* data stucture*/
struct Node{
    int* num;
    struct Node* next;
}node;

class linked_list
{
  public:
  Node* H=NULL;
  Node* T=NULL;
  int s=-1;
  void push(int* n,int d){
    Node* l;
    l = new Node();
    l->num=new int[d];
    for(int i=0;i<d;i++){
      l->num[i]=n[i];
    }
    l->next=NULL;
    if(s!= -1){
      l->next=H;
      H=l;
    }
    else{
      H=T=l;
    }
    s++;
  }
  void print(int d){
    Node* l = H;
    if(s!=-1){
      cout<<"| ";
      for(int i=0;i<=s;i++){
       for(int j=0;j<d;j++){
         cout<<l->num[j];
       }
       cout<<" | ";
       l = l->next;
      }
      cout<<endl;
    }
  }
  int* search(int* n,int d,int min_dis){
    Node* l=H;int* m = new int[d+1];int min_d=min_dis,dis=0;
    m[0]=min_d;
    if(s==-1){
      return m;
    }
    while(l!=NULL){
      dis = dist(n,l->num,d);
      if(dis<min_d){ 
        min_d=dis;m[0]=min_d;
        for(int i=1;i<=d;i++){
          m[i]=l->num[i-1];   
        }
      }
      l = l->next;
    }
    return m;
  }
}list;

/*hash table data structure*/
struct hashTable{
  class linked_list* l;
  int size;
};
typedef struct hashTable ht;

/*function for creating a hash table of size s*/
void createHashTable(ht* h,int s ){
    h->size=s;
    h->l = new linked_list[h->size];
}

/*function for generating n d-dimensional random numbers*/
int** random_generator(int d,int n){
  int** a=new int*[n];
  for(int i=0;i<n;i++){
    a[i] = new int[d];
    for(int j=0;j<d;j++){
      a[i][j]=(rand()%2);
    }
  }
  return a;
}

/*generating k-random hyperplanes for each of the l hashtables*/
double*** random_hyperplanes(int l,int d,int k){
  double*** h = new double**[l];
  for(int i=0;i<l;i++){
    h[i]=new double*[k];
    for(int j=0;j<k;j++){
      h[i][j]= new double[d];
      for(int m=0;m<d;m++){
        h[i][j][m]=(2*double(rand()%1000))/1000.00 - 1;
      }
    }
  }
  return h;
}

/*Function to return the key(Hash Function)*/
int hashFunc(int* a,double** h,int d,int k){
  int key=0;
  for(int j=0;j<k;j++){
    if(dot(a,h[j],d)>0){
      key=key+pow(2,j);
    }
  }
  return key;
}

/*inserting the 'n' d-dimensional random numbers into l-hash tables according to k-random hyperplanes*/
void insert(ht* ht1,int** a,double** h,int n,int d,int k){
  for(int i=0;i<n;i++){
    ht1->l[hashFunc(a[i],h,d,k)].push(a[i],d);
  }
  // for(int i=0;i<pow(2,k);i++){  /*uncomment here*/                           
  //   ht1->l[i].print(d);         /*for hashtables*/
  // }
  // cout<<endl;
}

int main() {
  /*
    d -> dimension
    n -> number of points 
    L -> number of hashtables
    k -> number of hyperplanes in a hashfunction
  */
  int L=10,d=10,n=200,k=log2(n);
  int** a = random_generator(d,n);
  double*** h = random_hyperplanes(L,d,k);
  ht** hti = new ht*[L];
  for(int i=0;i<L;i++){
     hti[i]=new ht;
     createHashTable(hti[i],n);
     insert(hti[i],a,h[i],n,d,k);
  }
  char c;
  int num[d];int NN[d];int min_dis=d,dis,z;
  cout<<"Enter the point: ";
  for(int i=0;i<d;i++){
    c=getchar(); num[i]=int(c)-48; /*If the input is in the form of string*/
    // cin>>num[i];   /* If the input is in the form of numbers separated by spaces*/
  }
  for(int i=0;i<L;i++){
    dis=(hti[i]->l[hashFunc(num,h[i],d,k)].search(num,d,min_dis))[0];
    if(min_dis>dis){
      for(int j=1;j<=d;j++){
        NN[j-1]=(hti[i]->l[hashFunc(num,h[i],d,k)].search(num,d,min_dis))[j];
      }
      min_dis=dis;
    }
  }
  cout<<"Nearst Neighbour of given point is:";
  for(int i=0;i<d;i++){
    cout<<NN[i];
  }
} 