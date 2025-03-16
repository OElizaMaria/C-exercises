#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
# define N 101

struct cartiere  //structura cartierelor 
      {
        int id;
        char *nume;
      };
    struct cartiere nrC[N];    

struct pachete   //structura pachetelor
     {
        int id;
        int adrs [18];
        int idCartier;
        int strada;
        int numar;
        int prioritate;
        float greutate;
        char *mesaj;
        int codmsj;
      
      };
    struct pachete pac[N];

struct postas //structura postasi
      {
        int id;
        int nrPachete;
        int dedistribuit[50];

      };
    struct postas post[N];

//CERINTA 1 SUBPUNCT 1
    
void citire(int *cerinta,struct cartiere nrC[],int * nrcart,int * nrP, struct pachete pac[])
   
   {   int i,j;
       
      scanf(" %d", cerinta); // citeste cerinta       

       scanf(" %d\n", nrcart); //cartiere
          
         for(i = 0; i < *nrcart ; i++)
            {
               nrC[i].nume=(char*)malloc(100 * sizeof(char)); //alocare initiala
                  fgets(nrC[i].nume,100,stdin); //citire
                  nrC[i].nume[strlen(nrC[i].nume)-1]=0;
                   //fgets pune ultimul caracter \n, il eliminam
              nrC[i].nume=(char *)realloc(nrC[i].nume,strlen(nrC[i].nume)*sizeof(char));
                 //realocare
               
            }
           
           for( i = 0; i < *nrcart; i++)  
        nrC[i].id = i;//completam id-ul cartierelor

   
      scanf(" %d", nrP);  //pachete

        
        for(i = 0; i < *nrP; i++)
          { for(j = 0; j < 18; j++)
              scanf(" %d", &pac[i].adrs[j]);
              
              scanf(" %d", &pac[i].prioritate);

              scanf(" %f\n", &pac[i].greutate);
             
            pac[i].mesaj=(char*)malloc(100 * sizeof(char)); //alocare initiala
                
                fgets(pac[i].mesaj,100,stdin); //citire
                
            pac[i].mesaj[strlen(pac[i].mesaj)-1]=0;
              //fgets pune ultimul caracter \n, il eliminam

            pac[i].mesaj=(char *)realloc(pac[i].mesaj,strlen(pac[i].mesaj)*sizeof(char));
            //realocare
              
              
          } 

          for( i = 0; i < *nrP; i++)
       pac[i].id = i;  //completam id pachete

   }
    
//CERINTA 1 SUBPUNCT 2
    
int putere2(int n) // calculare 2^n
{
  int i,a=1;

  if (n==0)return 1;

  for( i = 1; i <= n; i++)
    a = a*2;

  return a;

}

int transformare(int v[],int n) //transformare vector in baza 10
{  
    int i,a=0;

   for (i = 0; i <n; i++)
      a = a + v[n-1-i] * putere2(i);
   
   return a;
} 

void ex1sub2(struct pachete pac[],int nrP)
  { 
   
   int aux[100],i,j,k;

   for( k = 0; k < nrP; k++) //pt fiecare pachet

  { for( i = 0; i < 5; i++)
      aux[i] = pac[k].adrs[i]; //copie vector

      pac[k].idCartier=transformare(aux,5);
    //transformare primele 5 val ale vectorului echivalente idCartier

   j=0;
   for( i = 5; i < 10; i++)
     aux[j++] = pac[k].adrs[i];

   pac[k].strada = transformare(aux,5);
   //transformare urmatoarele 5 val echivalente strada

   j=0;
   for( i = 10; i < 18; i++)
     aux[j++] = pac[k].adrs[i];   
   pac[k].numar = transformare(aux,8);
    //transformare ultimele 8 valori echivalente numar
   }
  }

//CERINTA 1 SUBPUNCT 3

void ex1sub3(struct pachete pac[],struct postas post[],int nrP,int nrcart, int dim[])
    {
          
        int sefu[N],i,j,k=0;
      
      for( i = 0; i < nrP; i++)
      sefu[i] = pac[i].id; //postasul sef care primeste toate pachetele

      for(i=0; i < nrcart; i++)
        post[i].id=i;  //completare id

    for(i = 0; i < nrcart; i++) //distribuire pachete
      {for(j=0 ; j < nrP; j++) 
         if(post[i].id == pac[j].idCartier)
          { 
            post[i].dedistribuit[k++] = pac[j].id;
           dim[i]++;
          }
        k=0;
      }
    //nr de pachete se afla in vectorul dim, i fiind idul fiecarui postas,
    //vectorul dedistribuit tine pachetele  
    }
    
//CERINTA 1 SUBPUNCT 4
void swap (int  *a, int *b) // pt subpunctul4
{
   int aux;
   aux = *a;
   *a = *b;
   *b = aux;}


void ex1sub4(struct pachete pac[],int nrP,int dim[],int nrcart,struct postas post[])
    {
        int i,j,k,aux;

         for(k = 0;k < nrcart; k++) //trecem la fiecare postas
        {  
          for(i = 0; i < dim[k] - 1; i++)  //vectorul dim contine nr pachete pt postasul k
             for(j = 0; j < dim[k]-1-i; j++)
         {
           
            //dedistribuit[] contine nr dupa care sunt recunoscute pachetele
            //de aceea il folosim in interiorul lui pac[]

           if(pac[ post[k].dedistribuit[j+1] ].prioritate > pac[ post[k].dedistribuit[j] ].prioritate)
                   swap(&(post[k].dedistribuit[j+1]),&(post[k].dedistribuit[j]));
                 
             
            if(pac[ post[k].dedistribuit[j+1] ].prioritate == pac[ post[k].dedistribuit[j] ].prioritate)
                if(pac[ post[k].dedistribuit[j+1] ].greutate > pac[ post[k].dedistribuit[j] ].greutate )
                    swap(&(post[k].dedistribuit[j+1]),&(post[k].dedistribuit[j]));
                  
            //un fel de bubble sort doar ca in loc de varianta cu while
            //am folosit 2 for-uri

          } 
         }
     }

//CERINTA 1 SUBPUNCT 5     
 
void semnsireverse(struct pachete pac[], int nrP)
//sterge toate semnele de punctuatie si inverseaza cuvintele
{
   int i,j,k=0;
   char dup[100];
//STERGERE PUNCTUATIE (exceptie cratima)
   for(i = 0; i < nrP; i++)
  {
      k=0;
     strcpy(dup," ");
      for(j = 0; j <= strlen(pac[i].mesaj); j++)
     { 
         if(pac[i].mesaj[j]=='.')dup[k++]=' ';
         //in caz in care semnul de punctuatie
         //este intre 2 cvine lipite
        
        else if(ispunct(pac[i].mesaj[j])==0 || pac[i].mesaj[j]=='-')//sterge puncte exceptie cratima
          dup[k++]=pac[i].mesaj[j];}
    


//INVERSARE CUVINTE
    char dup2[100];
    int l,m=0,start,end, p=0;
    l=strlen(dup);
    start=l-1;
    end=l-1;
      while(start>0)
     {
         if(dup[start]==' ')//cauta spatiile dintre cuvinte
       {
            m=start+1;
            while(m <= end)
            dup2[p++]=dup[m++];
            
            end=start-1;
       }
          start--;
       //o data ce gaseste un spatiu stie care e inceputul si sfarsitul cuvantului   
      }

      for(m = 0; m <= end; m++)
    dup2[p++]=dup[m]; //ultimul cuv nu putea fi bagat cu while 
                  //deoarece nu exista spatiu la inceputul propozitiei

    dup2[p]='\0';
    strcpy(dup,dup2);
    l=strlen(dup);

      for(m = 0; m < l; m++)
    if(!((dup[m]>='a'&&dup[m]<='z')
 || (dup[m]>='A'&&dup[m]<='Z') || (dup[m]>='0'&&dup[m]<='9')||dup[m]=='-'))
  {
        strcpy(dup+m,dup+m+1);m--;
  }

   l=strlen(dup);

      for(m = 0; m < l; m++)
        if(dup[m]=='Q')
      {strcpy(dup+m,dup+m+1);m--;}
//stergerea oricarui caracter parazitar cum ar fi spatii, endlineuri etc

    strcpy(pac[i].mesaj,dup);
}
}

void ex1sub5(struct pachete pac[],int nrP)
  {

    int i,j,sum=0;
    for(i = 0; i < nrP; i++)
     {
        
       for(j = 0; j < strlen(pac[i].mesaj); j++)
          sum=sum+j*pac[i].mesaj[j];
        
       pac[i].codmsj=sum%(pac[i].strada*pac[i].numar+1);  
      //formare cod dupa formula
       sum=0;

     }

  }         

//CERINTA 2 SUBPUNCT 1
int gasit(int a, int b) //verificare daca b se afla in a
{ 
  int aux;
  aux=a;

    while(b)
   {   
      while(aux)
     {
      if(aux%10==b)return 1;
      aux=aux/10;
     }
      b=b/10;
      aux=a;
    }

 return 0;

}      

void factoriprimi(int a, int div[],int* dim) //in div se vor afla factorii primi
{
    int i,j,k=1,nrdiv=0,v[100],m=0;
    v[0]=0;

   for(i = 2; i <= 31; i++)//lista de factori primi
   {                       //pana in 31 pt observatia din cerinta
    for(j = 2; j*j <= i; j++)
     if(i%j==0)nrdiv++;
      if(nrdiv==0)v[k++]=i;
    nrdiv=0;
}


    for(i = 1; i < k; i++) //daca nu e divizor factorul se face 0
   if(a%v[i]!=0)v[i]=0;

    for(i = 0; i < k; i++)
      if(v[i]!=0)div[m++]=v[i];//scoatere 0-uri
                               //pt a ramane cu un vector doar cu factorii primi corecti
      *dim=m;

     if(a==0)//caz special
         {div[0]=0;
          *dim=1;}

      if(a==1)//caz special
         {div[0]=1;
          *dim=1;} 
}


int ex2sub1(int cod, int id)
{
   
  int div[100],d,k;
  if(gasit(cod,id)==1)
  {
     factoriprimi(id,div,&d);//in div se afla vectorul
   for(k = 0; k < d; k++)
    cod = cod ^ (1 << div[k]);//folosim operatia xor pt modificare bit
  }

   return cod;

}


int main() 
{   
      // declarare date
     int nrP,i,j,nrcart,cerinta,id,dim[N]={0};
  
    struct pachete pac[N];
    struct cartiere nrC[N];

    citire(&cerinta,nrC,&nrcart, &nrP,pac);
    
  //PRINTARE CERINTA 1

    if(cerinta==1)
     { for(i = 0; i < nrcart ; i++)
        {printf("%d ",i);
        printf("%s\n", nrC[i].nume); } //nume cartiere
        

       for( i = 0; i < nrP; i++) //printare info pachete
         { printf("%d\n",i);  

         for( j = 0; j < 17; j++)
        printf("%d ",pac[i].adrs[j]);

        printf("%d",pac[i].adrs[17]); //ca sa nu avem trailing whitespace la final

        printf("\n");
        printf("%d ",pac[i].prioritate);
        printf("%.3f\n",pac[i].greutate);
        printf("%s\n", pac[i].mesaj);
         } 
     }

   
    
    ex1sub2(pac,nrP);

  //PRINTARE CERINTA 2

    if(cerinta==2)
   {
    for( i = 0; i < nrP; i++)
     {
      printf("%d\n",i);
      printf("%d %d %d\n",pac[i].idCartier,pac[i].strada,pac[i].numar);
     }
    }

     ex1sub3(pac,post,nrP,nrcart,dim);

  //PRINTARE CERINTA 3

    if(cerinta==3)
   {
        for(i = 0; i < nrcart ; i++)
       {
          printf("%d ",post[i].id);
           printf("%d\n",dim[i]);

           if(dim[i]!=0)
           {  if(dim[i]==1)printf("%d",post[i].dedistribuit[0]);
              else {for( j = 0; j < dim[i] -1 ; j++)
              printf("%d ", post[i].dedistribuit[j]);
              printf("%d",post[i].dedistribuit[dim[i]-1]); }//ca sa nu ramana trailing whitespace la final
            }
       
           if(dim[i]!=0)printf("\n");
                 }
             
                }
  //PRINTARE CERINTA 4

    ex1sub4(pac,nrP,dim,nrcart,post);

   if(cerinta==4)
    {  
     for(i = 0; i < nrcart ; i++)
       {
          printf("%d ",post[i].id);
           printf("%d\n",dim[i]);

           if(dim[i]!=0)
           {  if(dim[i]==1)printf("%d",post[i].dedistribuit[0]);
              else {for( j = 0; j < dim[i] -1 ; j++)
              printf("%d ", post[i].dedistribuit[j]);
              printf("%d",post[i].dedistribuit[dim[i]-1]); }//ca sa nu ramana trailing whitespace la final
            }
       
           if(dim[i]!=0)printf("\n");
        }
             
    }

    semnsireverse(pac,nrP);
    ex1sub5(pac,nrP);


  //PRINTARE CERINTA 5
if(cerinta==5)
    {
       for(i = 0; i < nrcart ; i++)
       {
        printf("%d ",post[i].id);
        printf("%d\n",dim[i]);

          if(dim[i]!=0)
           { 
              for( j = 0; j < dim[i] ; j++)
              printf("%d %d\n", post[i].dedistribuit[j], pac[post[i].dedistribuit[j]].codmsj);
           }
        }

    }

  //PRINTARE CERINTA 6
      
   if(cerinta==6)
     {
         for(i = 0; i < nrcart ; i++)
        {
        printf("%d ",post[i].id);
        printf("%d\n",dim[i]);

          if(dim[i]!=0)
           { 
              for( j = 0; j < dim[i] ; j++)
              printf("%d %d\n", post[i].dedistribuit[j], ex2sub1(pac[post[i].dedistribuit[j]].codmsj,post[i].id));
               
            }
        }
      }

  //PRINTARE CERINTA 7
      int nr;
      nr=0;

     if(cerinta==7)
 {  float rez;
    
    for(i = 0; i < nrcart ; i++)
    {
       { for(j = 0; j < dim[i]; j++)
       if(pac[post[i].dedistribuit[j]].codmsj==ex2sub1(pac[post[i].dedistribuit[j]].codmsj,post[i].id))nr++;

       if(dim[i]==0||nr==0)rez=0.000;
       else rez=1.0*nr/dim[i];
       
       printf("%d %.3f\n",post[i].id,rez);

        nr = 0;}

    }
  }

    return 0;
}