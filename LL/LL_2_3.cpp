Node* reverseList(Node *head)
{
  Node *c,*n,*p;
  p=NULL;
  c=head;
  
  while(c!=NULL) {
      n=c->next;
      c->next=p;
      p=c;
      c=n;
  }
  // store previous in head
  head=p;
  return head;
  // Your code here
}