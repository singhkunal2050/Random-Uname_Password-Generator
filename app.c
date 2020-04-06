#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"app.h"
#define MAX 100

int main()
{
    FILE *fp=NULL;
    char key;
    char noun[20];
    char adj[20];
    char no[10];
    char *uname=(char *)malloc(sizeof(char)*40);
    char *passwd=(char *)malloc(sizeof(char)*40);
	int i,n;
    srand(time(0));                         // psuedo random base for random generation init by curr time


	for(i=10;i<30;i++)
	{
        printf("----------------------------------------------------\n");
        printf("Please Select One OPtion ::: \n");
        printf("1] Create UP\t2]Recover Password \n");
        printf("----------------------------------------------------\n");

        scanf("%d",&n);

        switch (n)
        {
            case 1: getRandom("Adj.txt",adj);
                    getRandom("noun.txt",noun);
                    getRandom("no.txt",no);
                    uname=MakeUsername(adj,noun,no);
                    puts(uname);
                    passwd=MakePasswd(uname);
                    puts(passwd);
                    break;
            
            case 2: printf("----------------------------------------------------\n");
                    printf("PAssword Recovery\n");
                    printf("----------------------------------------------------\n");
                    printf("Please Enter Your Key \t:: ");
                    scanf(" %c",&key);
                    printf("Please Enter Your Username \t:: ");
                    scanf("%s",uname);
                    printf("Please Choose your Chosen Encryption Method!\n");
                    printf("=======================================================\n");
                    printf("1::XOR\t2::RSA\t3::Shuffle\n4::RSA\t5::RSA\t6::RSA\n");
                    scanf("%d",&n);
                    int len=strlen(uname);

                    switch (n)
                    {
                        case 1 :for(i=0;i<len;i++)
                                    passwd[i]=uname[i]^key;
                                
                                printf("Your Password is :: ");
                                puts(passwd);
                                break;
                    
                         default:
                        break;
                    }





                    break;

            case 3: printf("-----Exiting-----");
                    free(uname);
                    free(passwd);
                    exit(0);    
                    break;

            default: printf("\nPlease Enter VAlid Input\n");
        }
	}

    free(uname);
    free(passwd);

    return 0;
	

}

