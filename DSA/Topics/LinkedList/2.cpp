#include<iostream>
#include<vector>

using namespace std;
/*
Doubly linked list

Dll
*/

class Node{
    public:
    int data;
    Node* next;
    Node* prev;


    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev  = nullptr;
    }
};

Node* createADLLFromArray(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i =1;i<arr.size();i++){
        Node* mm = new Node(arr[i]);
        temp->next = mm;
        mm->prev = temp;
        temp = temp->next;
    }

    return head;

}

int LenghtOfDLL(Node* head){
    int o =0;
    Node* m = head;
    while(m){o++;m=m->next;}
    return o;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}

Node* deleteHeadOfDLL(Node* head){
    if(head==NULL || head->next ==NULL){return NULL;}

    Node* temp = head;
    Node* mm = head->next; 
    temp->next->prev =nullptr;
    temp->next = nullptr;
    delete temp;
    return mm;
}

Node* deleteTailofDLL(Node* head){
    if(head==NULL || head->next == NULL){return NULL;}

    Node* mover = head;
    while(mover->next->next){
        mover=mover->next;
    }

    Node* tp = mover->next;
    mover->next = nullptr;
    tp->prev = nullptr;
    delete tp;
    return head;

}


Node* deleteTheKthElement(Node* head ,int k){
    if(head==NULL || k>LenghtOfDLL(head)){return NULL;}
    Node* m = head;
    int count =0;
    while(m){
        count++;
        if(count==k){break;}
        m=m->next;
    }
    Node* pn = m->prev;
    Node* fn = m->next;
    if(pn==nullptr && fn==nullptr){delete m;return NULL;}
    else if(pn==nullptr){
        fn->prev = nullptr;
        m->next = nullptr;
        delete m;
        return fn;
    }
    else if(fn==nullptr){
        pn->next = nullptr;
        m->prev = nullptr;
        delete m;
        return head;
    }

    pn->next = fn;
    m->next = nullptr;
    fn->prev = pn;
    m->prev = nullptr;
    delete m;
    return head;
}
void deleteThegivenNode(Node* m){
    Node* pn  = m->prev;
    Node* fn = m->next;

    if(fn==nullptr){
        pn->next = nullptr;
        m->prev = nullptr;
        delete m;
    }


    pn->next = fn;
    fn->prev = pn;
    m->next = nullptr;
    m->prev = nullptr;
    delete m;


}

Node* insertAtHead(Node* head ,int v ){
    Node* m  = new Node(v);
    m->next = head;
    head->prev = m;
    return m;
}
Node* insertBeforeTail(Node* head ,int v ){
    Node* m  = new Node(v);
    Node* mm = head;
    while(mm->next){
        mm = mm->next;
    }
    Node* pn  = mm->prev;
    if(pn==nullptr){
        return insertAtHead(head,v);
    }
    pn->next = m;
    m->prev  = pn;
    m->next = mm;
    mm->prev =m;
    return head;
}
Node* insertBeforeKthNode(Node* head ,int k,int v ){
    if(k>LenghtOfDLL(head) || k<1)return NULL;
    Node* m  = new Node(v);
    Node* mm = head;
    int count = 0;
    while(mm->next){ 
        count++;
        if(count==k){break;}
        mm = mm->next;
    }

    Node* pn  = mm->prev;
    if(pn==nullptr){
        return insertAtHead(head,v);
    }
    pn->next = m;
    m->prev  = pn;
    m->next = mm;
    mm->prev =m;
    return head;
}


Node* revserseDLL(Node* head){
    if(head==NULL || head->next == NULL){return NULL;}
    Node* c = head;
    Node* l = nullptr;
    while(c){
        l = c->prev;
        c->prev = c->next;
        c->next = l;
        c=c->prev;
        
    }
    return l->prev;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<int> arr = {1,2,3,34,35,325,32,5,353,53,5};
    Node* head = createADLLFromArray(arr);
    printDLL(head);
    printDLL(revserseDLL(head));
    

     
    

    return 0;
}