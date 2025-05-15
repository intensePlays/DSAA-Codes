#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

Node* insert(Node* root, int value) {
    if(root==nullptr) {
        return new Node(value);
    }
    if(value<root->data) {
        root->left=insert(root->left, value);
    }
    else {
        root->right=insert(root->right, value);
    }
    return root;
}

void InorderTraversal (Node* root) {
    if(root!=nullptr) {
        InorderTraversal(root->left);
        cout<<root->data<<" ";
        InorderTraversal(root->right);
    }
}

Node* search (Node* root, int value) {
    if(root==nullptr || root->data == value) {
        return root;
    }
    if(value<root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

int height(Node* root) {
    if(root==nullptr) {
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight, rightheight) + 1;
}

Node* deleteNode (Node* root, int value) {
    if(root==nullptr) {
        return root;
    }
    if(value<root->data) {
        root->left=deleteNode(root->left, value);
    }
    else if (value>root->data) {
        root->right=deleteNode(root->right, value);
    }
    else {
        if(root->left==nullptr) {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if (root->right==nullptr) {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* temp=root->right;
        while (temp && temp->left!=nullptr) {
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root=nullptr;
    int n, val;
    
    cout<<"Entr the number of elements in the BST: ";
    cin>>n;
    
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;++i) {
        cin>>val;
        root=insert(root, val);
    }
    
    cout<<"BST Inorder Traversal: ";
    InorderTraversal(root);
    cout<<endl;
    
    cout<<"Enter a value to be searched from the BST: ";
    cin>>val;
    if(search(root, val)) {
        cout<<"Node "<<val<<" found!";
    }
    else {
        cout<<"Node "<<val<<" not found!!";
    }
    
    cout<<"\nHeight of the BST: "<<height(root);
    
    cout<<"\nEnter the element you want to delete: ";
    cin>>val;
    root=deleteNode(root, val);
    
    cout<<"\nInorder Traversal after deletion of node "<<val<<": ";
    InorderTraversal(root);
    cout<<endl;
    
    return 0;
    
}