#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //toupper tolower için kullanıldı
typedef struct dugum {
  char *word;
  int count;
  struct dugum* next;
}node;
void basa_ekle(node** ,node* );
void araya_ekle(node**,node*);
void sona_ekle(node**,char*);
char* varsaArttir(node**, char *);
node* dugum_tutan=NULL;

int main() {

    node* head = NULL;
    FILE *dosya,*diger_dosya2;
    char *line=(char *)malloc(sizeof(char)*1000);
   
    char tutucu;
    if((dosya=fopen("/Users/sulevural/Desktop/projelab3/projelab3/deneme.txt","r"))==NULL){
        printf("DOSYA ACİLMADİ!\n");
        exit(0);
    }
    if((diger_dosya2=fopen("lowerchardosyasi.txt", "w"))==NULL){
        printf("DİGER DOSYA ACİLMADİ!\n");
        exit(0);
    }
    while (fscanf(dosya, "%c", &tutucu) != EOF){
        tutucu=toupper(tutucu);
        tutucu=tolower(tutucu);
       fputc(tutucu,diger_dosya2);
    }
   
    
    fclose(dosya);
    fclose(diger_dosya2);

    if((diger_dosya2=fopen("lowerchardosyasi.txt", "r"))==NULL){
        printf("DİGER DOSYA ACİLMADİ!\n");
        exit(0);
    }
 
    
   
  fgets(line,10000, diger_dosya2);
  
  line[strlen(line) - 1] = '\0';
  char *wordd=NULL;
  wordd=strtok(line," \n");
  sona_ekle(&head, wordd);
  while (wordd!= NULL) {
  wordd = strtok(NULL, " ");
  if(wordd==NULL)
  {
      break;
  }
      if(varsaArttir(&head,wordd)==wordd){
      if(dugum_tutan->count>head->count){
          basa_ekle(&head,dugum_tutan);
      }
      else if(dugum_tutan->count<=head->count){
          araya_ekle(&head,dugum_tutan);
      }
     }
      else if(strcmp(head->word,wordd)==0){
           head->count++;}
         else{
             sona_ekle(&head,wordd);
         }
    
    }

  fclose(diger_dosya2);
    
  int i=1;
  while (head!= NULL) {
    printf("%d. %s %d \n",i, head->word,head->count);
    head = head->next;
    i++;
  }
  return 0;
}

void basa_ekle(node** iter,node* dugum) {
  
  node* new = (node*) malloc(sizeof(node));

    new->word=dugum->word;
    new->count  = dugum->count;

    new->next = *iter;
    *iter   = new;

}
void araya_ekle(node** previous,node* araElemaan) {
    if(previous==NULL){
        printf("Önceki düğüm NULL olamaz.");
        
    }else{
    node* temp = *previous;
     node* tempsonraki = temp->next;
       while(tempsonraki!=NULL){
           if(araElemaan->count>tempsonraki->count){
               araElemaan->next=tempsonraki;
               temp->next=araElemaan;
               break;
           }
           temp=tempsonraki;
           tempsonraki=tempsonraki->next;
       }
       }}
void sona_ekle(node** iter, char* wordd) {
  node* new = (node*)malloc(sizeof(node));
  new->count=0;
  node* tail = *iter;

  new->word= wordd;
  new->count++;
  new->next = NULL;

  if (*iter == NULL) {
    *iter = new;
    return;
  }

  while (tail->next != NULL)
    tail = tail->next;

  tail->next = new;
  return;
}
char* varsaArttir(node **head, char *wordd){

    node* slow =*head;
    node* fast = slow-> next;
    while (fast != NULL)
    {
        if (strcmp(fast->word,wordd)==0)
        {   fast->count++;
            slow->next=fast->next;
            dugum_tutan=fast;
            return wordd;
        }
        slow=fast;
        fast=fast->next;
    }
    
    
        return NULL;
}




