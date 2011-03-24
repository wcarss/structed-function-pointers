#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct inner_structure
{
  int *x;
  int *y;
}is;

typedef struct complicated_structure
{
  char *str_one;
  char *str_two;
  is *struct1;
  is *struct2;
  int *i;
}cs;

typedef struct other_complicated_structure
{
  char *str_one;
  is *struct1;
  double *d;
}ocs;

typedef struct holder
{
  char name[8];
  void *v;
  void *(*init)();
  int (*free)(void *);
}h;

void *init_cs()
{
  cs *example = malloc(sizeof(cs));

  example->str_one = malloc(10);
  example->str_two = malloc(10);
  example->struct1 = malloc(sizeof(is)*10);
  example->struct2 = malloc(sizeof(is)*10);
  example->i = malloc(sizeof(int)*10);

  printf("cs init.\n");

  return (void *)example;
}

void *init_ocs()
{
  ocs *example = malloc(sizeof(ocs));

  example->str_one = malloc(10);
  example->struct1 = malloc(sizeof(is)*10);
  example->d = malloc(sizeof(double)*10);

  printf("ocs init.\n");

  return (void *)example;
}

int free_cs(void *_del)
{
  cs *del = (cs *)_del;
  if(NULL == del) return -1;


  free(del->str_one);
  free(del->str_two);
  free(del->struct1);
  free(del->struct2);
  free(del->i);

  free(del);

  printf("cs free.\n");
  return 0;
}


int free_ocs(void *_del)
{
  ocs *del = (ocs *)_del;
  if(NULL == del) return -1;

  free(del->str_one);
  free(del->struct1);
  free(del->d);

  free(del);

  printf("ocs free.\n");
  return 0;
}

int main()
{
  int i, ret;
  h **structs = malloc(sizeof(h *)*10);

  for(i = 0; i < 10; i++)
  {
    structs[i] = malloc(sizeof(h));
    strcpy((structs[i])->name, i % 2 ? "ocs" : "cs");
    (structs[i])->init = i % 2 ? init_ocs : init_cs;
    (structs[i])->free = i % 2 ? free_ocs : free_cs;
    (structs[i])->v = ((structs[i])->init)();
    printf("struct %d is a %s.\n", i, (structs[i])->name);
  }

  for(i = 0; i < 10; i++)
  {
    ret = ((structs[i])->free)((structs[i])->v);
    printf("struct %d returned %d on free. type: %s.\n", i, ret, (structs[i])->name);
    free(structs[i]);
  }

  free(structs);
  return 0;
}
