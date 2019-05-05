#include <stdio.h>
#include <assert.h>
#include <malloc.h>


typedef struct Node
{
  struct Node * left;
  struct Node * right;
  int val;
} Node;

void preorder(Node * root)
{
  if(root == NULL)
  {
    return;
  }

  printf("%d ",root->val);
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node * root)
{
  if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  printf("%d ",root->val);
  inorder(root->right);
}

void postorder(Node * root)
{
  if(root == NULL)
  {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->val);

}

Node * BuyNode(int x)
{
  Node *node = (Node*) malloc (sizeof(Node));
  assert(node);

  node->val = x;
  node->left = node->right = NULL;

  return node;
}

void test()
{
  Node *a = BuyNode(1);
  Node *b = BuyNode(2);
  Node *c = BuyNode(3);
  Node *d = BuyNode(4);
  Node *e = BuyNode(5);
  Node *f = BuyNode(6);
  Node *g = BuyNode(7);

  a->left = b;
  a->right = c;
  c->left = d;
  c->right = f;
  d->right = e;
  f->right = g;

  preorder(a);
  printf("\n");
  inorder(a);
  printf("\n");
  postorder(a);
  printf("\n");
}
int main()
{
  test();

  return 0;
}
