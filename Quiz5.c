// Vector in C  in 2 Versions 
// 1) Reallocating when you add a new value 
// 2) Reallocating and deallocating using powers of 2 

struct Stack {
int top;
int *array;
};

struct Stack * createStack(){
struct Stack * stack = (struct Stack *)malloc(sizeof(struct Stack));
stack->top=-1;
return stack;
}

int isEmpty ( struct Stack* stack){
if(stack->top == -1 ){
  return 1;
}
else{
  return 0;
}
}

void push(struct Stack* stack,int item){
if(isEmpty(stack) == 1 ){
  stack->top++;
  stack->array = (int *)malloc(sizeof(int)*(stack->top+1));
}
else{
stack->top++;
stack->array = (int *)realloc(stack->array , sizeof(int)*(stack->top+1));
stack->array[stack->top] = item ;
}
}

int pop(struct Stack * stack){
if(isEmpty(stack)!=1){
int ritem = stack->array[stack->top];
stack->top--;
stack->array = (int *)realloc(stack->array , sizeof(int)*(stack->top+1));
return ritem;
}
else{
  exit(isEmpty(stack));
}
}


struct StackFast {

int top;
int *array;

};

struct StackFast * createStackFast(){
  struct StackFast * stack = (struct StackFast *)malloc(sizeof(struct StackFast));
  stack->top=-1;
  return stack;
}

int isEmptyFast ( struct StackFast* stack){
  if(stack->top == -1 ){
    return 1;
  }
  else{
    return 0;
  }
}


void pushFast(struct StackFast* stack , int item ){
  if(isEmptyFast(stack)==1){
  //  printf("Prwth fora  \n");
    stack->top++;
    stack->array = (int *)malloc(stack->top+1 * sizeof(int));
  }
 else{
  stack->top++;
  if(ceil(log2(stack->top)) == floor(log2(stack->top)))
  {
    // printf("To top einai %d kai kanw diplasiasmo \n" , stack->top );
  stack->array = (int *)realloc(stack->array ,sizeof(int)*(stack->top * 2));
  //printf("SKAW \n");
  stack->array[stack->top] = item ;
  }
else{
   //printf("To top einai %d kai apla mpainw  \n" , stack->top );
  stack->array[stack->top] = item ;
}
  }
}


int popFast(struct StackFast * stack){
  if(isEmptyFast(stack)!=1){

    if(ceil(log2(stack->top)) == floor(log2(stack->top))){
    // printf("To top einai %d kai kanw upodiplasiasmo kai vgazws \n" , stack->top );
    int ritem = stack->array[stack->top];
    stack->array = (int *)realloc(stack->array , sizeof(int)*stack->top);
    stack->top--;
    return ritem;
  }
  else{
  //   printf("To top einai %d kai  vgainw \n" , stack->top );
    int ritem = stack->array[stack->top];
    stack->top--;
    return ritem;
  }
}
  else{
    exit(isEmptyFast(stack));
  }
}
