#include <iostream>

using namespace std;

struct node {
   int id;
   node *left;
   node *right;
};

class Tree {
private:
    node *T;
public:
    Tree() {
        T = NULL;
    }
    node * make_node();
    void make_root();
    void insert_left(node *root, int value);
    void insert_right(node *root, int value);
    void remove_left(node *root, int value);
    void remove_right(node *root, int value);
    void clearall(node *root);
    void seeall(node *root);
    void functionT();
};

node * Tree::make_node() {
   node *tp = new node;
   cout<<"Nhap id:";
   cin>>tp->id;
   cout<<tp->left<<endl;
   tp->left = NULL;
   tp->right = NULL;
   return tp;
}

void Tree::make_root() {
   if(T!=NULL) {
    cout<<"Cay da co goc"<<endl;
   }
   else {
    T = make_node();
    }
}

void Tree::insert_left(node *root, int value) {
    if(root != NULL) {
        if(root->id == value) {
            if(root->left == NULL) {
                root->left = make_node();
                return;
            }
            else {
                cout<<"Node da co nhanh trai"<<endl;
                return;
            }
        }
        insert_left(root->left, value);
        insert_left(root->right, value);
    }
}

void Tree::insert_right(node *root, int value) {
     if(root!=NULL) {
        if(root->id == value) {
            if(root->right == NULL) {
                node *pt = make_node();
                root->right = pt;
                return;
            }else {
                cout<<"Node da co nhanh phai"<<endl;
                return;
            }
        }
        insert_right(root->left,value);
        insert_right(root->right, value);
     }
}
void Tree::remove_left(node *root, int value) {
    if(root!=NULL) {
        if(root->id == value) {
            if(root->left == NULL) {
                cout<<"Ko co la trai"<<endl;
            }
            else {
                if((root->left)->left != NULL || (root->left)->right !=NULL) {
                    cout<<"Node co la con"<<endl;
                }
                else {
                    node *rp = root->left;
                    root->left = NULL;
                    delete(rp);
                }
            }
        }
        remove_left(root->left,value);
        remove_left(root->right,value);
    }
}

void Tree::remove_right(node *root, int value) {
      if(root!=NULL) {
        if(root->id == value) {
            if(root->right == NULL) {
                cout<<"node chua co nhanh phai"<<endl;
            }
            else {
                if((root->right)->left != NULL || (root->right)->right != NULL) {
                    cout<<"Nhanh phai co la con"<<endl;
                }
                else {
                    node *rp = root->right;
                    root->right = NULL;
                    delete(rp);
                }
            }
        }
        remove_right(root->left,value);
        remove_left(root->right,value);
      }
}

void Tree::clearall(node *root) {
      if(root!=NULL) {
        clearall(root->left);
        clearall(root->right);
        if(root == T) {
            node *p;
            T = p;
            delete(root);
        }
        else {
             delete(root);
        }

      }

}

void Tree::seeall(node *root) {
    if(root == T) {

       if(T==NULL) {
        cout<<"No Tree"<<endl;
        return;
       }
      }
      if(root!=NULL) {
        cout<<root->id<<endl;
        seeall(root->left);
        seeall(root->right);
        return;
      }


}

void Tree::functionT() {
    int m;
    make_root();
    int value;
    while(1) {
     cout<<"Muon lam ji: ";
    cin>>m;
        switch(m) {
      case 1:
        {
            cout<<"Nhap gia tri: ";
            cin>>value;
            insert_left(T, value);
            break;
        }
      case 2:
        {
            cout<<"Nhap gia tri: ";
            cin>>value;
            insert_right(T, value);
            break;
        }
      case 3:
        {
            cout<<"Nhap gia tri: ";
            cin>>value;
            remove_left(T, value);
            break;
        }
      case 4:
        {
            cout<<"Nhap gia tri: ";
            cin>>value;
            remove_right(T, value);
            break;
        }
      case 5:
        {

            clearall(T);
            break;
        }
      case 6:
        {
            seeall(T);
            break;
        }
        }
    }
}

int main() {



    return 0;
}
