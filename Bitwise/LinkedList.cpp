Node* copyRandomList(Node* curr)
{
  if(!head)
    return NULL;

  unordered_map <Node*, Node*> mp;
  Node* curr = head;
  while(curr != NULL)
    mp[curr] = new Node(curr->val);
    curr = curr->next;

  curr= head;
  while(curr != NULL)
    //mp[curr] represents the cloned node
    //we have further not performed the linkage
    mp[curr]->next = mp[curr->next];
    mp[curr]->random = mp[curr->random];
    curr = curr->next;

   return mp[head];
}
