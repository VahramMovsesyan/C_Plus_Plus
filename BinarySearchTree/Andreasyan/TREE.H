#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T>
struct elem1
{
	T info;
	int N1;
	int N2;
	elem1():info(){}
};
template <class T>
struct elem2
{
	T info;
	int mark;
	elem2():info(){}
	elem2(T d,int m):info(d),mark(m){}

	
};
template <class T>
struct TreeNode
{
	T info;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode(T inf,TreeNode<T>* lPtr=NULL,  TreeNode<T>* rPtr=NULL ):info(inf),left(lPtr),right(rPtr){}
};
template <class T>
class Tree
{
	private:
		TreeNode<T>* root;
		

	public:
		void setRoot(TreeNode<T>* P=NULL){root=P;}
		TreeNode<T>* getRoot(){return root;}
		TreeNode<T>* GetRoot(){return root;} //the method is usefull for testing the insert method in main
		Tree(){root=NULL;}		//lrutyamb konstruktor rootin veragrum e 0 arzheq
		Tree(Tree&);			//copy konstruktor
		Tree(elem1<T>*,int);		//masivi mijocov skzbnarzheqavorum
		Tree(elem2<T>*,int);		//masivi mijocov skzbnarzheqavorum
		int size_R(TreeNode<T>* );//the number of vertexes in given subtree
	    int size_R();//the number of vertexes in Tree
		TreeNode<T>* subtreeCopy(TreeNode<T>* );
		~Tree();		//destructor
		void Insert(TreeNode<T>*,T&,int);	//hascen talis enq, elem@ talis enq, intov el dazx kam ajn enq talis
		void Delete(TreeNode<T>*,int);		//hascen talis enq, inti mijocov talis enq, te dzax vordin petq e jnjvi, e aj@

		int TreeHeightR(TreeNode<T>*);		// the subtree height revursive counting
		int TreeHeightR();					// the tree height revursive counting
		int TreeHeightI(TreeNode<T>*);		// the subtree height iterative counting
		int TreeHeightI();					// the tree height iterative counting

		int TreeWidth_R(TreeNode<T>*,int,int* );//the subtree width(recursive solution)
		int TreeWidth_R();						//the tree width(recursive solution)
		//int TreeWidth_I(TreeNode<T>*);		//the subtree width(iterative solution)
		//int TreeWidth_I();						//the tree width(iterative solution)

		void preorderTransferR(TreeNode<T>* t);
		void preorderTransferR();
		void preorderTransferI(TreeNode<T>* t);
		void preorderTransferI();
		void inorderTransferR(TreeNode<T>* t);
		void inorderTransferR();
		void inorderTransferI(TreeNode<T>* t);
		void inorderTransferI();
		void postorderTransferR(TreeNode<T>* t);
		void postorderTransferR();
		void postorderTransferI(TreeNode<T>* t);
		void postorderTransferI();

		TreeNode<T>* inorderNext(TreeNode<T> *t); //the next vertex of t in inorderTransfer
		TreeNode<T>* begin();			  //the first vertex of t in inorderTransfer
        TreeNode<T>* end();				//the pointer after inorderTransfer last vertex pointer 
        
		


		T getMaxI(TreeNode<T>*);	//entacari max elem@
		T getMaxR(TreeNode<T>*);	//nuyn funtion@ rekuent tarberakov
		T getMaxI();				//	tree maximal element findig iterative solution
		T getMaxR();	//tree maximal element findig recursive solution

		T Max(T,T,T);		//3 tveri maxx@
		T getMaxInLevel(TreeNode<T>* ,int);
		T getMaxInLevel(int m);
		int iLevelCount_R(TreeNode<T>*, int);//the number of int-th level vertexes of subtree(recursive solution)
		int iLevelCount_R(int);				//the number of int-th level vertexes of tree (recursive solution)
		//int iLevelCount_I(TreeNode<T>*, int);//the number of int-th level vertexes of subtree(iterativ solution) 
		//int iLevelCount_I(int);//the number of int-th level vertexes of tree (iterativ solution)


	};

////////////////////////// IMPLEMENTATION ///////////////////////////////////////////////////

////////////////////////INORDER ITERATOR FUNCTIONS REALIZATIONS /////////////////////////////////

/////////////////////////////////////the next vertex of t in inorderTransfer
template <class T>
TreeNode<T>* Tree<T>::inorderNext(TreeNode<T> *t){
return  t;//the realization is not complete yet
} 


////////////////////////////the first vertex of t in inorderTransfer //////////////////	
template <class T>
TreeNode<T>* Tree<T>::begin(){
	TreeNode<T>* t=root;
return  t;				//the realization is not complete yet
} 
//////////////////////////////the pointer after inorderTransfer last vertex pointer 
   
template <class T> 
   
TreeNode<T>* Tree<T>::end(){
	TreeNode<T>* t=NULL;
return  t;				//the realization is not complete yet
} 

//////////////////////////////////////////////////////////////////				


//////////////////	SUBTREE COPY ///////////////
template <class T>
TreeNode<T>* Tree<T>::subtreeCopy(TreeNode<T>* t){
if (t==NULL) return NULL;
// if  the vertex is a leaf
if(!t->left && !t->right){
	TreeNode<T>* t1=new TreeNode<T>(t->info);
	return t1;
}
///////////if  the vertex is not a leaf/////////
 	TreeNode<T>* t1=new TreeNode<T>(t->info,subtreeCopy(t->left),subtreeCopy(t->right));

	return t1 ;
}

////////////////////////////// INSERT NEW VERTEX ///////////////////////
template <class T>
void Tree<T>::Insert(TreeNode<T>* t,T& inf,int m){
	//in case of NULL pointer to begin the construction from root
	if (t==NULL){
		root=new TreeNode<T>(inf);
		return;
	}
	if (m==0) 
		if(!t->left)
			t->left=new TreeNode<T>(inf);
			
		else
			t->left->info=inf;
	else//m==1
		if(!t->right)
			t->right=new TreeNode<T>(inf);			
		else
			t->right->info=inf;
	
	}

////////////////////////////// SUBTREE DELETION //////////////////////////
template <class T>
void  Tree<T>::Delete(TreeNode<T>* t,int m){
	if(t==NULL) return;
	if(m==0){
		//t havn't a left sun
		if(!t->left) return;
	  //else // t have a left sun
	Delete(t->left,0);
	Delete(t->left,1);
	delete t->left;
	t->left=NULL;

	}
	// deletion of right subtree

	else{
		if(!t->right)//t havn't a right sun
		return;
		Delete(t->right,0);
		Delete(t->right,1);
		delete t->right;
		t->right=NULL;

	}


}


//////////////////////////// COPY CONSTRUCTOR///////////
template <class T>
Tree<T>::Tree(Tree& T){
	root=subtreeCopy(T.root);
	
}
//////////////////////////////////////////////////
//the initialization of tree from array, in whitch the i-th element is vertex value,leftSunIndex, rightSunIndex
template <class T>
Tree<T>::Tree(elem1<T>* a,int n)
{
	//cout<<endl<<"*****tree by first array*****"<<endl;
	TreeNode<T> **ptr=new TreeNode<T>*[n];//ptr is the pointer on the treeNodePointerArray
	root=ptr[0]=new TreeNode<T>(a[0].info);
	//cout<<root->info;

	for(int i=1;i<=n;i++)
		ptr[i]=new TreeNode<T>(a[i].info);
	for( i=0;i<n;i++)
	{
		if(a[i].N1!=-1){
			ptr[i]->left=ptr[a[i].N1];
			//cout<<ptr[i]->left->info;
		}
		//else
		//	cout<<" - ";
		if(a[i].N2!=-1){
			ptr[i]->right=ptr[a[i].N2];
		    //cout<<ptr[i]->right->info;
		}
		//else
			//cout<<" - ";

	}
}

//////////////////////// DESTRUCTOR////////////////////////////////
template <class T>
Tree<T>::~Tree(){
	cout<<endl<<"I'AM A DESTRUCTOR"<<endl;
	Delete(root,0);
	Delete(root,1);
	delete root;

}
//////////////////////////////////////////////

template <class T>
Tree<T>::Tree(elem2<T>* a,int n)
{
	queue<TreeNode<T>*> Q;	//car@ datark che
	root=new TreeNode<T>(a[0].info);
	cout<<endl<<"********TREE VERTEXES**********"<<endl;
		Q.push(root);cout<<root->info;
	TreeNode<T>* t;
	for(int i=1;i<n;i+=2)
	{
		t=Q.front();Q.pop(); 
		if(a[i].mark)
		{
			t->left=new TreeNode<T>(a[i].info);cout<<t->left->info;
			if(2*i+1<n && a[2*i+1].mark || 2*i+2<n && a[2*i+2].mark)
				Q.push(t->left);
		}
		else cout<<" - ";
 		if(a[i+1].mark)
		{
			t->right=new TreeNode<T>(a[i+1].info);cout<<t->right->info;
			if(2*i+3<n && a[2*i+3].mark || 2*i+4<n && a[2*i+4].mark)
				Q.push(t->right);
		}
		else cout<<" - ";

		//if(t->left || t->right)
		//	Q.pop();
	}
}
/////////////////// ITERATIVE SOLUTION FOR SUBTREE MAXIMUM ELEMENT FINDING///////////////////////////////////


template <class T>
T Tree<T>::getMaxI(TreeNode<T>* r)	//r-ic heto exac entacari max@
{
	queue<TreeNode<T>*> Q;		//pahum enq hert, vorum dnelu enq r@
	Q.push(r);
	T max=r->info;
	TreeNode<T>* t;
	while(!Q.empty())
	{
		t=Q.front();
		if(t->left)
		{
			if(t->left->info>max)
				max=t->left->info;
			Q.push(t->left);
		}
		if(t->right)
		{
			if(t->right->info>max)
				max=t->right->info;
			Q.push(t->right);
		}
		Q.pop();
	}
	return max;
} 

////////////// RECURSIVE SOLUTION FOR SUBTREE MAXIMUM ELEMENT FINDING///////////////////
template <class T>
T Tree<T>::getMaxR(TreeNode<T>* t)
{
	T k=t->info;

	if(!t->left && !t->right)
		return k;
	if(!t->left && t->right){
		T r=getMaxR(t->right);
		return (k>r)?k:r;
	} 
	if(t->left && !t->right){
		T l=getMaxR(t->left);
		return (k>l)?k:l;
	} 	

		return Max(k,getMaxR(t->left),getMaxR(t->right));
}
/////////////////////////////////////////
template <class T>
T Tree<T>::Max(T a,T b,T c)
{
	T m;
	m=a>b ? a:b;
	m=c>m ? c:m;
	return m;
}

/////////////////// ITERATIVE SOLUTION FOR TREE MAXIMUM ELEMENT FINDING///////////////////////////////////


template <class T>
T Tree<T>::getMaxI(){
	return getMaxI(root);
}
///////////THE MAXIMUM ELEMENT IN GIVEN LEVEL ////////////////////
template <class T>
T Tree<T>::getMaxInLevel(TreeNode<T>* r,int m)
{
	queue<TreeNode<T>*>	Q;
	TreeNode<T>* t;
	int count=0;
	T max;
	if(!r)
		return 0;
	Q.push(r);
	while(count<m)
	{
		int k=Q.size();
		for(int i=0;i<k;i++)
		{
			t=Q.front();
			if(t->left)
				Q.push(t->left);
			if(t->right)
				Q.push(t->right);
		}
		Q.pop();
		count++;
	}
	//assert (!Q.empty());
	if (Q.empty()){
		cout<<"there is no this level";
		exit(1);
	}
	max=Q.front()->info; 
	Q.pop();
	while(!Q.empty())
	{
		t=Q.front();
		if(max<t->info)
			max=t->info;
		Q.pop();
	}
	return max;
}
////////////////////////////////////
template <class T>
T Tree<T>::getMaxInLevel(int m){
	return getMaxInLevel(root,m);
}
/////////////////////RECURSIVE SOLUTION FOR TREE MAXELEMENT FINDING////////
template <class T>
T Tree<T>::getMaxR(){
	return getMaxR(root);
}

//////////////////////////////RECURCIVE SUBTREE HEIGHT COUNTING////////////


template <class T> 
int Tree<T>::TreeHeightR(TreeNode<T>* t){
	if(t==NULL)
		return -1; 
	int l=TreeHeightR(t->left);
	int r=TreeHeightR(t->right);
	return 1+((l>r)?l:r);
}

//////////////////////////////RECURCIVE TREE HEIGHT COUNTING////////////
template <class T> 
int Tree<T>::TreeHeightR(){
	return TreeHeightR(root);
}
//////////////////////////////ITERATIVE SUBTREE HEIGHT COUNTING////////////
template <class T>
struct stelem{
	TreeNode<T>* Ptr;
	int			 l;
	stelem(TreeNode<T>* P=0, int length=0):Ptr(P),l(length){}
};

template <class T> 
int Tree<T>::TreeHeightI(TreeNode<T>* t){
	int h=0,hmax=0;
	stelem<T> el;
	stack<stelem<T> > S;
	while(1){
		if (t){
			el.Ptr=t;
			el.l=h;
			S.push(el);
			t=t->left;
			h++;
		}
		else
			if(S.empty())
				return hmax;
			else{
				el=S.top(); S.pop();
				t=el.Ptr;
				h=el.l;
				t=t->right;
				if(!t)
					if(h>hmax) hmax=h;
				}
	}
	
}

//////////////////////////////ITERATIVE TREE HEIGHT COUNTING////////////
template <class T>
int Tree<T>::TreeHeightI(){
	return TreeHeghtI(root);

}

///////////////////PREORDER TRANSFER ITERATIVE/////////////////////
template <class T>
void Tree<T>::preorderTransferI(TreeNode<T>* t)
{
	cout<<endl<<"****PREORDER TRANSFER ITERATIVE"<<endl;
	stack<TreeNode<T>*> s;
	while(12){
		if(t){
			cout<<t->info<<' ';
			if(t->right)
				s.push(t->right);
			t=t->left;
		}
		else{
			if(s.empty())
				return;
			t=s.top();
			s.pop();
		}
	}
}
/////////////RECURSIV COUNT OF SUBTREE I-TH LEVEL VERTEXES NUMBER //////////
template <class T>
int Tree<T>::iLevelCount_R(TreeNode<T>*	t, int i){
	if(t==NULL)
		return	0;
	if (i==0) return 1;

	int m= iLevelCount_R(t->left,i-1)+iLevelCount_R(t->right,i-1);
	return m;
}

////////////RECURSIV COUNT OF TREE i-TH LEVEL VERTEXES NUMBER //////////
template <class T>
int Tree<T>::iLevelCount_R(int i){
	return iLevelCount_R(root,i);
}

///////////////// THE SUBTREE WIDTH COUNTING: RECURSIVE SOLUTION?????????????SXAL E?????????????
template <class T>
int Tree<T>::TreeWidth_R(TreeNode<T>* t, int height, int* max){
						//we get the width in variable max, wich have the max=0 begining value

	if (t==NULL){
		return 0;
	}
	if (height==0){
		if(*max<1)
			*max=1;
		return 1;
	}
	int m=TreeWidth_R(t->left, height-1,max) + TreeWidth_R(t->right, height-1,max);
	if (*max<m)
		*max=m;
	cout<<" WIDTH  "<<*max<<" VERTEXNUMBER IN LEVEL "<<m;


	return m;
}
///////////////// THE TREE WIDTH COUNTING: RECURSIVE SOLUTION
template <class T>
int Tree<T>::TreeWidth_R(){
	int h=TreeHeightR();
	cout<<endl<<"TreeHeight= "<<h;
	int width=0;
	int k=TreeWidth_R(root,h,&width);
	return width;
}


////////////// TREE PREORDER TRANSFER ITERATIVE //////////////////
template <class T>
void Tree<T>::preorderTransferI()
{
	preorderTransferI(root);
}
////////////////////////////////////
template<class T>
void Tree<T>::preorderTransferR(TreeNode<T>* t)
{

		if(t==NULL)
		return;
		cout << t->info << " ";
    	preorderTransferR(t->left);
		preorderTransferR(t->right);
}


////////////////////////////////////
template<class T>
void Tree<T>::preorderTransferR()
{
	preorderTransferR(root);
}
//////////////////////////////////////////////
template<class T>
void Tree<T>::inorderTransferI(TreeNode<T>* t)
{

	cout<<endl<<"***  INORDER TRANSFER ITERATIVE ***"<<endl;
	stack<TreeNode<T>*> s;
	//TreeNode<T> * r;
	while(1){
		if(t){
			s.push(t);
			t=t->left;
		}
		else{
			if(s.empty()) return;
			t = s.top();
			s.pop();
			cout<<t->info<<' ';
			//if(r->right)
				//t=r->right;

				t=t->right;
		}
	}
}
//////////////////////////////////////////
template<class T>
void Tree<T>::inorderTransferI(){
	inorderTransferI(root);


}
////////////////////////////////////

template<class T>
void Tree<T>::inorderTransferR(TreeNode<T>* t)
{

		if(t==NULL)
		return;
	inorderTransferR(t->left);
	cout << t->info << " ";
	inorderTransferR(t->right);
}
/////////////////////////////////////////////////////////////
////////////////////////////////////
template<class T>
void Tree<T>::postorderTransferR(TreeNode<T>* t){

		if(t==NULL)
			return;
			postorderTransferR(t->left);
			postorderTransferR(t->right);
			cout << t->info << " ";

}
////////////////////////////////////
template<class T>
void Tree<T>::postorderTransferR(){
		postorderTransferR(root);
}

//////////////////////////////////////////////
template<class T>
void Tree<T>::postorderTransferI(TreeNode<T>* t){

	cout<<endl<<"***  POSTORDER TRANSFER ITERATIVE ***"<<endl;
	stack<TreeNode<T>*> s;
	TreeNode<T> *r,* prevPtr=NULL;
	while(1){
		if(t){
			s.push(t);
			t=t->left;
		}
		else{
			if(s.empty()) return;
			r = s.top();
			if(r->right && prevPtr!=r->right)		//ajd ach chanaparhy der chi ditarkvel 
				t=r->right;						// ijnum enq chditarkvats ach chanaparhov
			else	//kam hertakan dzax chanaparhi terev e, kam el achov arden antsel enq				 
			{
				prevPtr=r;//hishenq iren worpes naxord ditarkvats
			    cout<<r->info<<" ";// t pointer-y pahum enq NULL-i vra, worpeszi cikli hajwrd qajlin dzaxov chijni
				s.pop();
				
			}	
						
				
		}
	}
}
//////////////////////////////////////////
template<class T>
void Tree<T>::postorderTransferI(){
	postorderTransferI(root);


}
////////////////////////////////////
//////////////////////////////////////////////
template <class T>
int Tree<T>:: size_R(TreeNode<T>* t){
	if (t==0) 
		return 0;
	if(!(t->left) && !(t->right))
		return 1;
	return 1+size_R(t->left)+size_R(t->right); 


}
template <class T>
void Tree<T>::inorderTransferR(){
inorderTransferR(root);
}

template <class T>
int Tree<T>:: size_R(){
return size_R(root);
}
/*
int main()
{

////////////////////////////////MAIN SECTION OF FUNCTION///////////////////
	/////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

/*cout<<"*** tree initialization by first constructor from array ***"<<endl;
const int m=7;
elem1<char> T1[m];
for(int i=0;i<m;i++)
		 cin>>T1[i].info>>T1[i].N1>>T1[i].N2;	

/*cout<<endl<<"FIRST TREE ARRAY TESTING"<<endl;
for( i=0;i<m;i++)

		 cout<<T1[i].info<<" "<<T1[i].N1<<" "<<T1[i].N2<<endl;
		 


Tree<char> Tr1(T1,m);
cout<<endl;
cout<<"     ************* THE TREE SIZE ************   "<<Tr1.size_R();	
cout<<endl<<"INORDER TRANSFER RECURSIVE"<<endl;
Tr1.inorderTransferR();
Tr1.inorderTransferI();
cout<<endl<<"PREORDER TRANSFER RECURSIVE"<<endl;
Tr1.preorderTransferR();
Tr1.preorderTransferI();
cout<<endl<<"POSTORDER TRANSFER RECURSIVE"<<endl;
Tr1.postorderTransferR();
Tr1.postorderTransferI();
cout<<endl<<"TREE MAXIMUN ELEMENT IS    "<<Tr1.getMaxI();
cout<<endl<<"TREE MAXIMUN ELEMENT IS    "<<Tr1.getMaxR();
cout<<endl<<"RECURSIVE SOLUTION TREE HEIGHT IS    "<<Tr1.TreeHeightR();
cout<<endl;
cout<<endl<<"ITERATIVE SOLUTION TREE HEIGHT IS    "<<Tr1.TreeHeightR();
cout<<endl;

int level=2;
cout<<endl<<"the maximum value in level  "<<level<<" =  "<<Tr1.getMaxInLevel(level);
cout<<endl<<"THE NUMBER OF VERTEXES IN "<<	level<<"-th level = "<<Tr1.iLevelCount_R(level);
cout<<endl<<"THE TREE WIDTH = "<<Tr1.TreeWidth_R();

//////////////       COPY COSTRUCTOR TESTING /////////////////////////// 
cout<<endl<<"COPY COSTRUCTOR TESTING";
Tree<char> Tr3(Tr1);
Tr3.inorderTransferI();
Tr3.preorderTransferI();
//////////////////   DESTRUCTOR TESTING ///////////////////////
Tree<char>* treePtr;
treePtr=new Tree<char>(Tr3);
cout<<endl<<"THE DESTRUCTOR TESTING"<<endl;
delete treePtr;

/*
cout<<"*********** tree initialization by second constructor from array*********************";

const int n=7;
elem2<char> T2[n];
for(int i=0;i<n;i++)
		 cin>>T2[i].info>>T2[i].mark;	

//Tree ARRAY TESTING
//cout<<endl<<"TREE ARRAY TESTING"<<endl;
//for( i=0;i<n;i++)

//		 cout<<T2[i].info<<" "<<T2[i].mark<<"   ";


Tree<char> Tr2(T2,n);
cout<<endl;
cout<<"     ************* THE TREE SIZE ************   "<<Tr2.size_R();	
Tr2.inorderTransferR();



	/////////////////////INSERT FUNCTION TESTING////////////////
			Tree<char> Tr5;
			TreeNode<char>* ptr=NULL;
			char c='x';
			Tr5.Insert(ptr,c,0);
			ptr=Tr5.GetRoot();
			c='y';
			Tr5.Insert(ptr,c,0);
			ptr=ptr->left;
			c='z';
			Tr5.Insert(ptr,c,1);
			ptr=ptr->right;
			c='w';
			Tr5.Insert(ptr,c,0);
			c='v';
			Tr5.Insert(ptr,c,1);

			Tr5.inorderTransferI();
			Tr5.preorderTransferI();
			Tr5.postorderTransferI();





	return 0;
}*/