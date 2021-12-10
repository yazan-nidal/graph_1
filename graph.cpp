#include<iostream>
using namespace std;

template<typename T>
	class node
	{ 
	private :
	T data;
	node<T> *Next;
	template<typename T>
	friend class sList;
	public :


T&  getD()const
{
	//if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	return this->data;
}


node<T>*  getN()const
{
	//if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	return this->Next;
}
	};

template<typename T>
class sList
{
private :

	node<T> *head;
	int n;
	
public :


sList()
{
	(*this).head=NULL;
	(*this).n=0;	
}


bool  isEmpty()
{
	return(((*this).head == NULL));
}


int  sizE(){return(*this).n;}


node<T>*  findItem(const T &item)
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	node<T> *p=(*this).head;
	while((p != NULL) && (p->data != item))p=p->Next;
	if(p==NULL)cout<<"Not found item \n";
	return p;
}


node<T>*  getH()const
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	return (*this).head;
}


void  insert(T const & item)
{
	node<T> *p=new node<T>;
	p->data=item;
	p->Next=NULL;
	(*this).n++;
	if( (*this).isEmpty() )
	{
		(*this).head=p;
		return;
	}
	
	node<T> *pre=NULL;
	node<T>*cur=(*this).head;
	while((cur != NULL) && (cur->data < item))
	{
		pre=cur;
		cur=cur->Next;
	}
	if(pre == NULL)
	{
		p->Next=(*this).head;
		(*this).head=p;
		return;
	}
	if(cur == NULL)
	{
		pre->Next=p;
		return;
	}
	if(cur && pre)
	{
		p->Next=cur;
		pre->Next=p;
		return;
	}
	//cout<<" f \n";
	return;
}

T  getFront()
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return '\0';}
	return (*this).head->data;
}

bool  removeF()
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return false;}
	node<T> *p=(*this).head;
	(*this).head=p->Next;
	p->Next=NULL;
	delete p;
	p=NULL;
	(*this).n--;
	return true;
}


bool  remove(T const &item)
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return false;}
	node<T> *p=(*this).findItem(item);
	if(p==NULL){return false;}
	if(p == (*this).head){return (*this).removeF(); }
	node<T> *w=(*this).head;
	while((w->Next != p)){w=w->Next;}
	w->Next=p->Next;
	p->Next=NULL;
	delete p;
	p=NULL;
	(*this).n--;
	
	return true;
}

 ~sList()
{
	while(!(*this).isEmpty())(*this).removeF();
	(*this).head=NULL;
	(*this).n=0;
	//cout<<"thi\n";
}

void  print()
{
	node<nodeN> *p=(*this).head;
	while(p!=NULL)
	{
		(*p).data.printNode();
		cout<<"********************\n";
		p=p->Next;
	}
	

}
};


class nodeN
{
private:
	int vertex;
	int weight;
public:

nodeN(int v=0, int w=0)
{ setNodeN(v,w); }

void setNodeN(int v,int w)
{
	(*this).vertex=v;
	(*this).weight=w;
}

void operator<<(int){(*this).printNode();}

bool operator < (const nodeN &obj)
{ 
	if((*this).vertex == obj.vertex)return ((*this).weight < obj.weight);
	return ((*this).vertex < obj.vertex);
}

void printNode()
{
	cout<<"vertex : "<<(*this).vertex<<"\n";
	cout<<"weight : "<<weight<<"\n";
}

~nodeN(){/* nothing to do */}

};

int maxEdges(int num){return((num*(num-1))/2);}

void proce(int **&graph_matrix,sList <nodeN> *&bs,int numN,int numE)
{
	// intlaize
	graph_matrix=new int* [numN+1];
	for(int i=0;i<numN+1;i++)
	{
		*( graph_matrix+i)=new int[numN+1];
		**( graph_matrix+i)=i;
		*(*( graph_matrix)+i)=i;
		for(int j=1;j<=numN;j++){ *(*( graph_matrix+i)+j)=0; }
	}

	

	 bs= new sList<nodeN>[numN+1];

	 // /intlaize

	//proce
	int x,y,z;
	for(int i=1;i<=numE;i++)
	{
		do{cout<<"Please enter edge"<<i<<" and its weight in the order (vertex1, vertex1, weight): ";
		cin>>x; cin>>y; cin>>z;
		//x--; y-=1; z=z-1;
		if((x>numN) || (x<1) || (y>numN) || (y<1) || (x==y) || (graph_matrix[x][y]) || (graph_matrix[y][x]==1))
			{cout<<"Error : invalid input of edge !!!\n";}
		}
		while((x>numN) || (x<1) || (y>numN) || (y<1) || (x==y) || (graph_matrix[x][y]!=0));
		while(z<=0){cout<<"Error : weight  must be greater than 0 !!! \n"<<"Please enter weight for edge : "; cin>>z;}
		
		*(*( graph_matrix+x)+y)=z;
		*(*( graph_matrix+y)+x)=z;

		//bs
		nodeN *p=new nodeN;
		(*p).setNodeN(y,z);
		bs[x].insert((*p));
		//bs
		p=new nodeN;
		(*p).setNodeN(x,z);
		bs[y].insert((*p));
	}

	 // /proce
}

void printMTX(int **&graph_matrix,int numN)
{
	//print
	cout<<"\n print Matrix : \n\n";
	cout<<"	";
	for(int i=1;i<=numN;i++){cout<<*(*( graph_matrix)+i)<<"	";}cout<<endl<<endl;
	for(int i=1;i<=numN;i++)
	{cout<<*(*( graph_matrix+i))<<"	";
	for(int j=1;j<=numN;j++)
	{cout<<*(*( graph_matrix+i)+j)<<"	";}
	cout<<"\n";
	}
}

void printALIST(sList <nodeN> *&bs,int numN)
{
	cout<<"/n Print array of lists  :\n\n";
	for(int i=1;i<=numN;i++)
	{ cout<<" List "<<i<<" : \n";
	bs[i].print();
	cout<<'\n';
	}
}


int found(int v1,int v2 ,int w ,int **&graph_matrix,int numN)
{
	// : return -1 error
    // : return 0 not found
	// : return 1 found

	if(w <= 0)return -1;

	if((v1 > numN)||(v1 < 1)||(v2 > numN)||(v2 < 1))return -1;

	return(graph_matrix[v1][v2]!=0);
}

int count_edges(int **&graph_matrix,int numN)
{
	if(numN <=0)return -1;
	int sum =0;
	for(int i=1;i<=numN;i++)
	for(int j=1;j<=numN;j++)if(graph_matrix[i][j] >= 1)sum++;

	return sum;
}

int outdegree(int **&graph_matrix,int numN,int numE)
{
	if(numN <=0)return -1;
	int sum =0;
	for(int j=1;j<=numN;j++)if(graph_matrix[j][numE] >= 1)sum++;
	return sum;
}

int indegree (int **&graph_matrix,int numN,int numE)
{
	if(numN <=0)return -1;
	int sum =0;
	for(int j=1;j<=numN;j++)if(graph_matrix[numE][j] >= 1)sum++;
	return sum;
}
void main()
{
	// graph A
	//parametaer graph A
	int **graph_matrixA;
	sList <nodeN> *bsA;

	//intlaize
	int t1,t2;
	do{cout<<"Please enter the number of nodes in graph : "; cin>>t1;
	if(t1<=1){cout<<"Error : input Number of Node !!! \n";}}
	while(t1<=1);

	do{cout<<"Please enter the number of edges in Graph : ";cin>>t2; if(t2>maxEdges(t1) || t2<=0){cout<<"Error : input number of edges !!!\n";}}
	while(t2>maxEdges(t1) || t2<=0);
	
	//nodes and edges graph A
    const int numN1=t1;
	const int numE1=t2;
	//proce graph A

	
	proce(graph_matrixA,bsA,numN1,numE1);

	printMTX(graph_matrixA,numN1);

	printALIST(bsA,numN1);

	cout<<found(8,6,14,graph_matrixA,numN1)<<"\n";
	cout<< outdegree(graph_matrixA,numN1,5)<<"\n";
	cout<<indegree(graph_matrixA,numN1,5)<<"\n";
}