#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int d = 0, TreeNode *l = NULL, TreeNode *r = NULL)
	{
		data = d;
		left = l;
		right = r;
	}
};
int levelr(TreeNode *a, int lv)
{
	if (!a) return 0;
	if (!lv) return 1;
	return levelr(a->left, lv - 1) + levelr(a->right, lv - 1);
}
void prr(TreeNode *a, int lv)
{
	if (!a) return;
	if (!lv) { cout << a->data << " "; return; }
	prr(a->left, lv - 1); prr(a->right, lv - 1); return;
}
int r_t(TreeNode *a)
{
	if (!a) return 0;
	return r_t(a->left) + r_t(a->right) + 1;
}

int terev(TreeNode *a)
{
	if (a == NULL) return 0;
	int k = 0;
	if (!a->left && !a->right) k++;
	return terev(a->left) + terev(a->right) + k;
}

int iterlevel(TreeNode *a)
{
	stack <TreeNode *> A;
	TreeNode *p = a;
	bool b = true; int q = 0;
	while (b)
	{
		while (p != NULL)
		{
			if (!p->left && !p->right) q++;
			A.push(p);
			p = p->left;
		}
		if (A.empty()) b = false;
		else {
			p = A.top();
			A.pop();
			p = p->right;
		}
	}
	return q;
}

int leveltree (TreeNode *a)
{
	if (a == NULL) return -1;
	return max(leveltree(a->left), leveltree(a->right))+1;
}

//օժանդակ ֆունկցիա, որը հաշվում է ծառի բարձրությունը ոչ ռեկուրսիվ եղանակով
int laynaki(TreeNode *a, TreeNode *q)
{
	TreeNode *p = a;
	queue <TreeNode *> A;
	int level = 0, t = 1, k;
	A.push(p);
	while (!A.empty())
	{
		k = 0;
		for (int i = 0; i < t; i++)
		{
			p = A.front(); if (q == p) return level;
			A.pop();
			if (p->left) { A.push(p->left); k++; }
			if (p->right) { A.push(p->right); k++; }
		}
		level++;
		t = k;
	}
	return -1;
}
int max(int x, int y)
{
	return (x > y) ? x : y;
}


void inorder(TreeNode *a)
{
	stack <TreeNode *> A, B;
	TreeNode *p = a;
	bool b = true; 
	while (b)
	{
		while (p != NULL)
		{
			A.push(p); B.push(p);
			p = p->right;
		}
		if (A.empty()) b = false;
		else {
			p = A.top(); 
			A.pop(); 
			p = p->left;
		}
	}

	p = B.top();
	while (!B.empty()) { cout << p->data << endl; B.pop();
	if (B.empty()) break;
	p = B.top();
	}
}

/*int f(TreeNode *a)
{
	if (a == NULL) return 0;
	a->data = terev(a); cout << a->data << endl;
	f(a->left); f(a->right);
	return 0;
}
*/

//տպել տերևների արժեքները ռեկուրսիվ և ոչ ռեկուրսիվ (սիմետրիկ)
//ռեկուրսիվ
void f1(TreeNode *a)
{
	if (a == NULL) return;
	f1(a->left);
	if (!a->left && !a->right)
		cout << a->data << endl;
	f1(a->right);
}

//ոչ ռեկուրսիվ
void inorder1(TreeNode *a)
{
	stack <TreeNode *> A;
	TreeNode *p = a;
	bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			A.push(p);
			p = p->left;
		}
		if (A.empty()) b = false;
		else {
			p = A.top();
			A.pop();
			cout << p->data << endl;
			p = p->right;
		}
	}
}

//տպել գագաթների արժեքները (հակադարձ)
//ռեկուրսիվ
void f3(TreeNode *a)
{
	if (a == NULL) return;
	f3(a->left); f3(a->right);
	if (!a->left && !a->right) return;
	else	cout << a->data << endl;
}

//ոչ ռեկուրսիվ
void inorder3(TreeNode *a)
{
	stack <TreeNode *> A;
	stack <TreeNode *> B;
	TreeNode *p = a;
	bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			A.push(p); B.push(p); p = p->right;
		}
		if (A.empty()) b = false;
		else {
			p = A.top();
			A.pop();
			p = p->left;
		}
	}
	p = B.top();
	while (!B.empty())
	{
		cout << p->data << endl; B.pop();
		if (B.empty()) break; p = B.top();
	}
}

// Տերևների քանակը  ռեկուրսիվ (ուղիղ)
int f7(TreeNode *a)
{
	if (a == NULL) return 0;
	int k = 0;
	if (!a->left && !a->right) k++;
	return f7(a->left) + f7(a->right) + k;
}

// Ոչ ռեկուրսիվ
int inorder7(TreeNode *a)
{
	int q = 0;
	stack <TreeNode *> A;
	TreeNode *p = a;
	bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			if (!p ->left && !p->right) q++;
			A.push(p);  p = p->left;
		}
		if (A.empty()) b = false;
		else {
			p = A.top();
			A.pop();
			p = p->right;
		}
	}
	return q;
}

//Ծառի բարձրությունը (ուղիղ)
//ռեկուրսիվ
int f8(TreeNode *a)
{
	if (a == NULL) return -1;
	
	return max(f8(a->left), f8(a->right)) + 1;
}
//ոչ ռեկուրսիվ (ուղիղ)
int inorder8(TreeNode *a)
{
	int x, y = -1;
	stack <TreeNode *> A;
	TreeNode *p = a;
	bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			A.push(p);  p = p->left;
		}
		if (A.empty()) b = false;
		else {
			p = A.top(); x = laynaki(a, p);
			if (y < x) y = x; 
			A.pop();
			p = p->right;
		}
	}
	return y;
}

//տպել յուրաքանչյուր մակարդակի max տարրը
void laynaki10(TreeNode *a)
{
	int m = 0;
	TreeNode *p = a;
	queue <TreeNode *> A;
	int level = 0, t = 1, k;
	A.push(p);
	while (!A.empty())
	{
		m = A.front()->data;
		k = 0;
		for (int i = 0; i < t; i++)
		{
			p = A.front(); A.pop();
			if (m < p->data) m = p->data;
			if (p->left) { A.push(p->left); k++; }
			if (p->right) { A.push(p->right); k++; }
		}
		cout << m << endl;
		level++;
		t = k;
	}
}

//ծառի բարձրություն։ (լայնակի շրջանցում)
void laynaki11(TreeNode *a)
{
	TreeNode *p = a;
	queue <TreeNode *> A;
	int level = 0, t = 1, k;
	A.push(p);
	while (!A.empty())
	{
		k = 0;
		for (int i = 0; i < t; i++)
		{
			p = A.front(); A.pop();
			if (p->left) { A.push(p->left); k++; }
			if (p->right) { A.push(p->right); k++; }
		}
		level++;
		t = k;
	}
	cout << level;
}

//Տպել ամենաշատ գագաթ ունեցող մակարդակները
void laynaki12(TreeNode *a)
{
	TreeNode *p = a;
	queue <TreeNode *> A;
	int level = 0, t = 1, k, m = 0;
	A.push(p);
	while (!A.empty())
	{
		k = 0;
		for (int i = 0; i < t; i++)
		{
			p = A.front(); A.pop();
			if (p->left) { A.push(p->left); k++; }
			if (p->right) { A.push(p->right); k++; }
		}
		level++; if (m < t) m = t; t = k;
	}
	t = 1; p = a; A.push(p); level = 0;
	while (!A.empty())
	{
		k = 0; for (int i = 0; i < t; i++)
		{
			p = A.front(); A.pop();
			if (p->left) { A.push(p->left); k++; }
			if (p->right) { A.push(p->right); k++; }
		} 
		level++;
		if (t == m) cout << level << endl;
		t = k;
	}
}





//0 արժեք ունեցող հանգույցների մակարդակների № տպել
void inorder19(TreeNode *a)
{
	stack <TreeNode *> A;
	TreeNode *p = a;
	bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			A.push(p); p = p->left;
		}
		if (A.empty()) b = false;
		else {
			p = A.top();
			if (p->data == 0) cout << laynaki(a, p) << endl;
			A.pop();
			p = p->right;
		}	
	}
}

//օժանդակ ֆունկցիաներ
int leveltree19(TreeNode *a)
{
	if (a == NULL) return -1;
	return max(leveltree(a->left), leveltree(a->right)) + 1;
}
//Ռեկուրսիվ
void f19(TreeNode *q, TreeNode *a)
{
	if (a == NULL) return;
	if (a->data == 0)
		cout << (leveltree19(q) - leveltree19(a)) << endl;
	f19(q, a->left); f19(q, a->right);
}
// main-ում f19-ը ֆունկցիան կանչելիս որպես պարամետր փոխանցել
// նույն հանգույցը 2 անգամ՝ f19(a,a);

//ստուգել լրիվությունը
bool f21(TreeNode *a)
{
	if (a == NULL) return true;
	bool k = false;
	if ((a->left && a->right) || (!a->left && !a->right))
		k = true;
	return f21(a->left) && f21(a->right) && k;
}

//Ոչ ռեկուրսիվ
int inorder21(TreeNode *a)
{
	stack <TreeNode *> A;
	TreeNode *p = a;
	int x = 1;
	bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			A.push(p); p = p->left;
		}
		if (A.empty()) b = false;
		else {
			p = A.top();
			if ((!p->left && p->right) || (p->left && !p->right))
				x = 0;
			A.pop();
			p = p->right;
		}
	}
	return x;
}

//Ցանկացած գագաթում գրել իրենով որոշվող ենթածառի բարձրությունը
// Օժանդակ ֆունկցիա, որը վերադարձնում է տվյալ ծառի տերևների քանակը
int f_o(TreeNode *a)
{
	if (a == NULL) return 0;
	int k = 0;
	if (!a->left && !a->right) k++;
	return f_o(a->left) + f_o(a->right) + k;
}

void f29(TreeNode *a)
{
	if (a == NULL) return;
	a->data = f_o(a); cout << a->data << endl;
	f29(a->left); f29(a->right);
}

//Ոչ ռեկուրսիվ
//Օժանդակ ֆունկցիա, որը հաշվում է ծառի տերևների քանակը
int iterlevel(TreeNode *a)
{
	stack <TreeNode *> A;
	TreeNode *p = a;
	bool b = true; int q = 0;
	while (b)
	{
		while (p != NULL)
		{
			if (!p->left && !p->right) q++;
			A.push(p); p = p->left;
		}
		if (A.empty()) b = false;
		else { p = A.top(); A.pop(); p = p->right; }
	}
	return q;
}

void inorder29(TreeNode *a)
{
	stack <TreeNode *> A;
	TreeNode *p = a; bool b = true;
	while (b)
	{
		while (p != NULL)
		{
			p->data = iterlevel(p);
			cout << p->data << endl;
			A.push(p); p = p ->left;
		}
		if (A.empty()) b = false;
		else { p = A.top(); A.pop();
		p = p->right;
		}
	}
}

int main()
{
	TreeNode *g = new TreeNode(0);
	TreeNode *n = new TreeNode(4, g, NULL);
	TreeNode *k = new TreeNode(3);
	TreeNode *r = new TreeNode(2, k, NULL);
	TreeNode *d = new TreeNode(6);
	TreeNode *e = new TreeNode(9);
	TreeNode *c = new TreeNode(5, r, n);
	TreeNode *b = new TreeNode(7, e, d);
	TreeNode *a = new TreeNode(1, b, c);
	//inorder(a);
	//cout<<f(a);
	//laynaki(a);
	system("pause");
	return 0;
}
