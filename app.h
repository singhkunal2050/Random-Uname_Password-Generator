#include<stdio.h>
#include<time.h>

void getRandom(char fname[],char *c)
{
    int i;
    FILE *f=NULL;

    int num = (rand() % (2000 - 1));        // number in range of 2000


    f=fopen(fname,"r");
    if(f==NULL)
    {
        printf("The File Could not be Opened!\n");
        exit(0);
    }

    //printf("Random Number :: %d\t",num);

    for(i=0; i<num-1 && f!=NULL ;i++)      // traversed to random line in file
    {
            //printf("Pass %d\t",i);
            fscanf(f,"%s",c);
           // printf("Name Accepted :: %s\n",c);
    }

        //printf("Name Accepted :: %s\n",c);

}

char * MakeUsername(char a[],char b[],char c[])
{
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Inside Username Creation\n");
    

        char *u=(char *)malloc(40*sizeof(char));

        strcpy(u,a);
        strcat(u,"_");
        strcat(u,b);
        strcat(u,"_");
        strcat(u,c);

        return u;
}

char * MakePasswd(char *uname)
{
    int c,i;
    char pass[15];
    char key =  'A' + (rand() % 26 );        // common char key  in range of A-Z for every encryptn
	char *passwd=(char *)malloc(sizeof(char)*40);
    int len=strlen(uname);


    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Please Choose an Encryption Method For your Password!\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("1::XOR\t2::RSA\t3::Shuffle\n4::RSA\t5::RSA\t6::RSA\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    scanf("%d",&c);

    switch(c)
    {
        case 1 : printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                 printf("++++XOR ENCRYTION++++\n");
                 printf("Your Key is [%c] PLEASE REMEMBER IT FOR PASSWORD RECOVERY\n",key);
                
                printf("PAssword:: ");

                 for(i=0;i<len;i++)
                     passwd[i]=uname[i]^key;

                 return passwd;                                   
                 break;




                break;

		default : return passwd;

    }

    return passwd;

}

