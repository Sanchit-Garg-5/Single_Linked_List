#include <bits/stdc++.h>
using namespace std;
// --- Companion macros required for this debugger ---
typedef long long ll;
#define f first
#define s second
// --- Master Debugger Block ---
// Debug Overloads
#ifdef SanG_05
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class... Args> void _print(unordered_set <Args...> v);
template <class... Args> void _print(unordered_multiset <Args...> v);
template <class... Args> void _print(unordered_map <Args...> v);
template <class... Args> void _print(unordered_multimap <Args...> v);
template <class... Args> void _print(list <Args...> v);
template <class... Args> void _print(forward_list <Args...> v);
template <class... Args> void _print(stack <Args...> v);
template <class... Args> void _print(queue <Args...> v);
template <class... Args> void _print(priority_queue <Args...> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_set <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multiset <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_map <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multimap <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(forward_list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(stack <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(priority_queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}

class node{
    public:
    ll data; node* next;
    node(ll data1, node* next1):data(data1), next(next1){}
    node(ll data1): data(data1),next(nullptr){}
    node(): data(0), next(nullptr){}

};
node* createll(vector<ll>&me){
    if(me.empty()){return nullptr;}
    node* head=new node(me[0]);
    node* mover=head;
    for(int i=1;i<me.size();i++){
        node* temp=new node(me[i]);
        mover->next=temp;
        mover=mover->next; // or mover=temp;
    }
    return head;
}
int lengthll(node* temp){
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
node* deletehead(node* head){
    if(head==nullptr){return head;}
    node* temp=head;
    head=head->next;
    delete temp; // also delete previous head data
    return head;
}
node* deletetail(node* head){
    if(head==nullptr || head->next==nullptr){return nullptr;}
    node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    node *temp1=temp->next;
    delete temp1;
    temp->next=nullptr;
    return head;
}

node* deletek(node *head, int k){
    if(head==nullptr){return nullptr;}
    else if(k>lengthll(head)){return head;}
    else if(k==1){//  handles deletion of head
        node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    else{//handles deletion of tale and kth element
        node*temp =head; int count=0;
        while(temp){
            count++;
            if(count==k-1){break;}
            temp=temp->next;
        }
        node*temp1=temp->next;
        temp->next=temp->next->next;
        delete temp1;
        return head;
    }
}

node* addhead(node*head, ll x){
    if(head==nullptr){// if no head right now
        node* temp1=new node(x,nullptr); return temp1;
    }
    node* temp1=new node(x,nullptr);
    temp1->next=head;
    head=temp1;
    return head;
}

node* addk(node*head, ll x,ll k){// add element at some k posi
    if(head==nullptr && k!=1){return nullptr;}
    else if(k>lengthll(head)+1){return head;}
    else if(k==1){return addhead(head,x);}//if k is head
    else{// if k is not head
        int length=lengthll(head);
        node* temp=head; int count=0;
        node* temp1=new node(x,nullptr);
        while(temp){
            count++;
            if(count==k-1){
                node*temp2=temp->next;
                temp->next=temp1;
                temp1->next=temp2;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
}

void traversal(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    } // for traversal
    cout<<"\n";
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    vector<ll>me={1,2,3,4,5,6,69,67};
    node* head=createll(me);

    cout<<lengthll(head)<<"\n"; // for length

    head= deletehead(head);// for new head
    traversal(head);
    head=deletetail(head);
    traversal(head);
    head=deletek(head,4); // deleting 4rth element
    traversal(head);
    head=addhead(head,0);// adding element at head
    traversal(head);
    head=addk(head,-69,5); //add element at kth position
    traversal(head);
}
