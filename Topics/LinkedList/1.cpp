#include<bits/stdc++.h>
using namespace std;


/*
singly linked list 
*/

class Node{
    public: 
    int data;
    Node* next;
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    
    }
};

void printLinkedList(Node* head){
    Node* temp  = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* deleteHead(Node* head){
    if(head == NULL){return head;}

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){return NULL;}
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
Node* convertArray(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover =head;
    for (int i = 1; i < arr.size(); i++)
    {
       Node* temp = new Node(arr[i]);
       mover->next = temp;
       mover = temp;
    }
    return head;
    
}
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data==val)return 1;
        temp=temp->next;
    }

    return 0;
}

Node* addAtHead(Node* head,int v){
    Node* temp = new Node(v);
    temp->next = head;
    return temp;
}

Node* addAtTail(Node* head,int v){
    if(head == NULL){return new Node(v);}
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* mm = new Node(v);
    temp ->next = mm;
    return head;
}

int lengthofLL(Node* head){
    int count=0;
    Node* temp = head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

Node* addAtKthPostion(Node* head,int v, int k){
    if(k>1+(lengthofLL(head)) ||( k < 1 )){return NULL;}
    Node*  temp = head;
    Node* ss = temp;
    Node* mm = new Node(v);
    if(k==1){
        mm->next = head;
        return mm;
    }
    k-=2;
    while(k--){
        temp=temp->next;
    }
    mm->next = temp->next;
    temp->next = mm; 
    return head;
}

Node* addBeforeTheValue(Node* head,int v,int el){
    if(head==NULL){return NULL;}

    Node*  temp = head;
    Node* mm = new Node(v);
    while(temp->next->data!=el){
        temp=temp->next;
    }
    mm->next = temp->next;
    temp->next = mm; 
    return head;
}

Node* middleLL(Node* head){
    /*
     we hve  to return the swecond node in case of even nubmers
    */
   int nn = (lengthofLL(head)/2) + 1;
   Node* t= head;
   int c =0;
   while(t){
    c++;
    if(c==nn)break;
    t=t->next;
   }
   return t;
}

Node* middleElementUsingTortoiseNHairAlgo(Node* head){
    Node* f = head;
    Node* s = head;
    while(f && f->next){
        f=f->next->next;
        s=s->next;
    }
    return s;
}

Node* reverseLL(Node* head){
    Node* c = head;
    Node* l = nullptr;
    while(c){
        Node* f  = c->next;
        l= c;
        c = f;
    }
    return l;
}

Node* revserLLRecurrsion(Node* head){
    if(head==NULL || head->next==NULL)return head;

    Node* newNode = revserLLRecurrsion(head->next);
    Node* f = head->next;
    f->next = head;
    head->next =nullptr;
    return newNode;
}

bool detectLoopInLL(Node *head)
{

    Node *f = head;Node* s = head;
    while (f && f->next)
    {
        f = f->next->next;
        s = s->next;
        if (f == s)
            return true;
    }
    return false;
}
Node* loopStartingNodeLL(Node* head){
    Node* f = head;
    Node* s = head;
    while(f&&f->next){
        f=f->next->next;
        s= s->next;
        if(f==s){
        s=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return s;
        }
    }
    return NULL;
}

int lengthOfLoopLL(Node* head){
    int c =0;
    Node* f = head;
    Node* s = head;
    while(f&&f->next){
        f=f->next->next;
        s= s->next;
        c++;
        if(f==s){
        int d =0;
        s=head;
        while(f!=s){
            d++;
            f=f->next;
            s=s->next;
        }
        return (c+d);
        }
    }
    return 0;


}
bool isPalindrome(Node* head){
    Node* f =head;
    Node* s = head;
    while(f->next&& f->next->next){
        f=f->next->next;
        s=s->next;
    }
    Node* newHead = revserLLRecurrsion(s->next);
    f= newHead;
    s = head;
    while(f){
        if(s->data!=f->data){
            return false;
        }
        s=s->next;
        f=f->next;
    }
    revserLLRecurrsion(newHead);
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {1,2,3,4,5,6,2,6,22,463,2352};
    Node* head = convertArray(arr);
    printLinkedList(head);
   printLinkedList(revserLLRecurrsion(head->next));

    






    

    return 0;
}