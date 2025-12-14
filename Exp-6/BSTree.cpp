#include <iostream>
#include <vector>
using namespace std;

template <typename T1, typename T2>
struct BSTNode											//BST结点类模板 
{
    T1 key;							        			//存放关键字,假设关键字为T1类型
    T2 data;                                 			//存放数据项,假设数据项为T2类型
    BSTNode* lchild;						   			//存放左孩子指针
    BSTNode* rchild;						   			//存放右孩子指针
    BSTNode(T1 k, T2 d)    								//构造方法
    {
        key = k;
        data = d;
        lchild = rchild = NULL;
    }
};
template <typename T1, typename T2>
class BSTClass								  			//BST类
{
public:
    BSTNode<T1, T2>* r;  								//BST根结点
    BSTNode<T1, T2>* f;    								//用于存放待删除结点的双亲结点
    BSTClass()                             				//构造方法
    {
        r = NULL;  						        		//BST根结点
        f = NULL;    						        		//用于存放待删除结点的双亲结点
    }
    ~BSTClass()											//析构函数
    {
        DestroyBTree(r);								//调用DestroyBTree()函数
        r = NULL;
    }
    void DestroyBTree(BSTNode<T1, T2>* b)				//释放所有的结点空间
    {
        if (b != NULL)
        {
            DestroyBTree(b->lchild);					//递归释放左子树
            DestroyBTree(b->rchild);					//递归释放右子树
            delete b;									//释放根结点
        }
    }

    //BST的基本运算算法
    void InsertBST(T1 k, T2 d)			    			//插入一个(k,d)结点
    {
        r = _InsertBST(r, k, d);
    }

    BSTNode<T1, T2>* _InsertBST(BSTNode<T1, T2>* p, T1 k, T2 d)
    {
        if (p == NULL) {
            p = new BSTNode<T1, T2>(k, d);
        }
        else if (k < p->key) {
            p->lchild = _InsertBST(p->lchild, k, d);
        }
        else if (k > p->key) {
            p->rchild = _InsertBST(p->rchild, k, d);
        }
        else {
            p->data = d;
        }
        return p;
    }

    void CreateBST(vector<T1>& a, vector<T2>& b)			//由a和b向量创建一棵BST
    {
        r = new BSTNode<T1, T2>(a[0], b[0]);
        for (int i = 1; i < a.size(); i++) {
            InsertBST(a[i], b[i]);
        }
    }
    BSTNode<T1, T2>* SearchBST(T1 k)		        		//在BST中查找关键字为k的结点
    {
        return _SearchBST(r, k);                           				//r为BST的根结点
    }

    BSTNode<T1, T2>* _SearchBST(BSTNode<T1, T2>* p, T1 k)		        		//在BST中查找关键字为k的结点
    {
        if (p == NULL) {
            return NULL;
        }
        if (k == p->key) {
            return p;
        }
        if (k < p->key) {
            return _SearchBST(p->lchild, k);
        }
        else {
            return _SearchBST(p->rchild, k);
        }
    }

    bool DeleteBST(T1 k)					        	//删除关键字为k的结点
    {
        f = NULL;
        return _DeleteBST(r, k, -1);
    }
    bool _DeleteBST(BSTNode<T1, T2>* p, T1 k, int flag)
    {
        if (p == NULL) {
            return false;
        }
        if (k == p->key) {
            return DeleteNode(p, f, flag);
        }
        if (k < p->key) {
            f = p;
            return _DeleteBST(p->lchild, k, 0);
        }
        else {
            f = p;
            return _DeleteBST(p->rchild, k, 1);
        }
    }

    bool DeleteNode(BSTNode<T1, T2>* p, BSTNode<T1, T2>* f, int flag)
    {
        if (p->rchild == NULL) {
            if (flag == -1) {
                r = p->lchild;
            }
            else if (flag == 0) {
                f->lchild = p->lchild;
            }
            else {
                f->rchild = p->lchild;
            }
            delete p;
        }
        else if (p->lchild == NULL) {
            if (flag == -1) {
                r = p->rchild;
            }
            else if (flag == 0) {
                f->lchild = p->rchild;
            }
            else {
                f->rchild = p->rchild;
            }
            delete p;
        }
        else {
            BSTNode<T1, T2>* f1 = p;
            BSTNode<T1, T2>* q = p->lchild;
            if (q->rchild == NULL) {
                p->key = q->key;
                p->data = q->data;
                p->lchild = q->lchild;
            }
            else {
                while (q->rchild != NULL) {
                    f1 = q;
                    q = q->rchild;
                }
                p->key = q->key;
                p->data = q->data;
                f1->rchild = q->lchild;
                delete q;
            }
        }
        return true;
    }

    void DispBST()						        		//输出BST的括号表示串(不含data)
    {
        _DispBST(r);
    }
    void  _DispBST(BSTNode<T1, T2>* p)           		//被DispBST方法调用
    {
        if (p != NULL)
        {
            cout << p->key;								//输出根结点值
            if (p->lchild != NULL || p->rchild != NULL)
            {
                cout << "(";   			    			//有孩子结点时才输出"("
                _DispBST(p->lchild);			    	//递归处理左子树
                if (p->rchild != NULL)
                    cout << ",";   		    			//有右孩子结点时才输出","
                _DispBST(p->rchild);			    	//递归处理右子树
                cout << ")";   			    			//有孩子结点时才输出")"
            }

        }
    }
    void DispBST1()						        		//输出BST的括号表示串(含data)
    {
        _DispBST1(r);
    }
    void  _DispBST1(BSTNode<T1, T2>* p)           		//被DispBST方法调用
    {
        if (p != NULL)
        {
            cout << p->key << "[" << p->data << "]";	//输出根结点值
            if (p->lchild != NULL || p->rchild != NULL)
            {
                cout << "(";   			    			//有孩子结点时才输出"("
                _DispBST1(p->lchild);			    	//递归处理左子树
                if (p->rchild != NULL)
                    cout << ",";   		    			//有右孩子结点时才输出","
                _DispBST1(p->rchild);			    	//递归处理右子树
                cout << ")";   			    			//有孩子结点时才输出")"
            }
        }
    }

    void deleteMin()                                    //删除BST中的最小值
    {
        BSTNode<T1, T2>* cur = r;
        BSTNode<T1, T2>* pre = NULL;

        while (cur->lchild != NULL) {
            pre = cur;
            cur = cur->lchild;
        }
        if (cur->rchild == NULL) {
            pre->lchild = NULL;
        }
        else if (pre != NULL) {
            pre->lchild = cur->rchild;
        }
        else {
            r = cur->rchild;
        }
        delete cur;
    }

    int findKsmaller(T1 k)                              //返回小于该结点值的数量
    {
        return _findKsmaller(r, k);
    }

    int _findKsmaller(BSTNode<T1, T2>* p, T1 k)
    {
        if (p == NULL) {
            return 0;
        }
        if (p->key >= k) {
            return _findKsmaller(p->lchild, k);
        }
        return _findKsmaller(p->lchild, k) + _findKsmaller(p->rchild, k) + 1;
    }

    void exchange()                                     //使该BST树所有左子树结点关键字大于根结点，右子树小于根结点
    {
        _exchange(r);
    }

    void _exchange(BSTNode<T1, T2>* p) {
        if (p == NULL) {
            return;
        }
        swap(p->lchild, p->rchild);
        _exchange(p->lchild);
        _exchange(p->rchild);
    }
};
