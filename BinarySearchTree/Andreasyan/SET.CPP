#include "BinSTree.h"


class set {
friend set Union(set& s1, set& s2);
public:
set(){t->setRoot();}
~set(){ delete t;}
set(set& s){

	t=new binSTree<int>(*(s.t));
}
private:
binSTree<int> *t;

};//end of class

//////////////////////////////////// IMPLEMENTATION ////////////////////////////////////
set Union(set& s1, set& s2){
	set s3;
	for (TreeNode<int>* r=s1.t->begin(); r!=s1.t->end(); r=s1.t->inorderNext(r) ){
		s3.t->insert(r->info);
	}

	for ( r=s2.t->begin(); r!=s2.t->end(); r=s2.t->inorderNext(r) ){
		//petq e ajnpes anel, worpeszi *r-y veradardzni hents gagati arjeqy` *r=r->info		
		s3.t->insert(r->info);
	}

	return s3;
}

int main(){
	set S;
	return 0;
}