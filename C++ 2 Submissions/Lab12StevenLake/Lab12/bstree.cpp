#include "bstree.h"
#include <iostream>
#include <cassert>
using namespace std;


bstree::bstree() : rootp(nullptr){}

void bstree::insert(int data){
    rootp = insert(rootp, data);
}

node* bstree::insert(node* r, int data){
    if(r == nullptr){
        r = new node(data);
    }
    else if(data < r->data){
        r->left = insert(r->left, data);
    }
    else if(data > r->data){
        r-> right = insert(r->right, data);
    }
    else{
        //data == r->data;
    }

    return r;
}

void bstree::print() const{
    print(rootp);
}

void bstree::print(node* r) const{
    if(r == nullptr){
        return;         
    }
    cout << r-> data << " => ";

    if(r->left == nullptr) cout << "(empty)";
    else cout << "(" << r->left->data << ")";
        
    if(r->right == nullptr) cout << "(empty)" << endl;
    else cout << "(" << r->right->data << ")" << endl;  
    
    if(r->left != nullptr) print(r->left);
    if(r->right != nullptr) print(r->right);
}

int bstree::find_min() const{
    return find_min(rootp);
}

int bstree::find_min(node* r) const{
    assert(r != nullptr);
    if(r->left == nullptr) return r->data;
    else return find_min(r->left);
}

void bstree::erase(int data){
    assert(rootp != nullptr);
    rootp = erase(rootp, data);
}

node* bstree::erase(node* r, int data){
    if(r == nullptr) return nullptr;

    if(data < r->data){
        r-> left = erase(r->left, data);
    } 
    else if(data > r->data){
        r-> right = erase(r->right, data);
    }
    else{
        //data == r->data;
        if(r->left != nullptr && r->right != nullptr){
            //both L and R subtrees exist
            int mindata = find_min(r->right);
            r->data = mindata;
            r->right = erase(r->right, mindata);
        }
        else {
            //only one subtree OR no subtree
            node* discard = r;
            r = (r->left != nullptr) ? r->left : r->right;
            delete discard;
        }
    }
    return r;
}