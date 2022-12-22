#include "tree.h"
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////CLASS BINARY SEARCH TREE/////////////////////////////////////////////

template <class T>
class binSTree:public Tree<T>{
public:
	binSTree(){setRoot();}
	binSTree(T*,int);
	void insert(T&);
	void Delete(T&); //??????????????????
	bool find(T&);
//	binSTree(binSTree<T>& STree){
//		Tree<int>::Tree<int>(STree);
//			}
		
};

//////////////////////////////IMPLEMENTATION/////////////////////////////////
template <class T>
 binSTree<T>::binSTree(T* A, int n ){
	//Tree<T>();
	setRoot();
	for(int i=0; i<n; i++){
		insert(A[i]);

	}


}

template <class T>
void binSTree<T>::insert(T& x ){
	if (getRoot()==NULL){
		TreeNode<T>* P=new TreeNode<T>(x);
		setRoot(P);
		return;
	}
	TreeNode<T> *t=getRoot(),*parent;
	while(t){
		parent=t;
		if(x<=t->info)
				t=t->left;
		else	
				t=t->right;

	}
	if (x<=parent->info)
		parent->left=new TreeNode<T>(x);
	else 
		parent->right=new TreeNode<T>(x);

	

}
///////////////////////////////   DELETE KATARMAN SXAL KA PETQ E UXXEL/////
template <class T>
void binSTree<T>::Delete(T& x){
	TreeNode<T>* t=getRoot(), *parent=NULL;
	bool b=false;
	while(t){
		if(x==t->info) {
			b=true;//gtel enq heratsvox gagati hascen
			break;}
		parent=t;
		if(x<t->info)
				t=t->left;
			else
				t=t->right;
	}//WHILI PAKUM
		if(b)				//heratsvox gagaty tsarum ka
			if(!t->left && !t->right )//heratsvwxy terev e
		
			{
				if (parent==NULL)//mek gagat unecwx tsar e
					setRoot(NULL);
				else //mekic avel gagat ka
					if(t==parent->left) 
						parent->left=NULL;
					else				
						parent->right=NULL;

			delete t; //terevy heratsvets
			}  //
			else //heratsvwxy terev che
			{
				//minch ajs erevi eli depqet kan arandznatsnelu` erb t-i mi chjuxsy chka` ajy kam dzaxy
				TreeNode<T>* temp=t->left,*tempParent;//tempi mej kpahenq x-ic poqreri mej amenametsy
				while(temp->right){
					tempParent=temp;
					temp=temp->right;
				}//while-i pakum
				t->info=temp->info;
				 if(temp)
					 delete temp;
				tempParent=NULL;
			}//else-i pakum
		else //hertatsvox gagaty chka
			cout<<endl<<"GAGATY, WORN UZUM EQ HERATSNEL TSARUM CHKA";



	}


///////////////////////////////// FIND ////////////////////////////
template <class T>
bool binSTree<T>::find(T& x){ 
	TreeNode<T>* t=getRoot();
	while(t){
		if(x==t->info)
			return true;
		else
			if(x<t->info)
				t=t->left;
			else
				t=t->right;
	}
	return false;
}




//////////////////////////////////////////////////
/*int main(){
	binSTree<int> T;
	int x=3;
	T.insert(x);
	x=7;
	T.insert(x);
	x=5;
	T.insert(x);
	x=3;
	T.insert(x);
	T.inorderTransferR();
	x=99;
	cout<<endl;
	T.find(x)? cout<<"YES":cout<<"NO";

	//////////////////// SECOND CONSTRUCTOR TESTING ////////////
	cout<<endl<<"   SECOND CONSTRUCTOR TESTING     ";
	int A[7]={9,4,7,8,1,2,3};
	binSTree<int> T1(A,7);
	T1.inorderTransferR();
	x=4;
	T1.Delete(x);
	cout<<endl;
	T1.inorderTransferR();




return 0;
}*/