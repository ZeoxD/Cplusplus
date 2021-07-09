#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct text
{
    int id;
    char sentence[50];
};
  
int main ()
{
    char loop_exit;
    do{
        //file pointer initialized
        FILE *file;

        //writing to the file
        file = fopen ("archive.dat", "ab");
        struct text t;
        int id; char line[50];
        printf("Enter your ID: "); scanf("%d", &id); t.id = id;
        int x = 0;
        printf("Type the Note you want to save:\n");
        
        while( x<30 )
        { 
            scanf("%c", &line[x]);
            t.sentence[x] = line[x];
            x++; 
        } t.sentence[x] = '\0';

        fwrite (&t, sizeof(struct text), 1, file);
        fclose (file);

        //reading the file
        struct text tn; 
        file = fopen ("archive.dat", "rb");
        int search_id; 
        printf("Enter the ID you want to search: "); 
        for(int j = 0 ; j< 10; j++) 
        {
            fflush(stdin);
            fflush(stdout); 
        }
        scanf("%d", &search_id);
        while(fread(&tn, sizeof(struct text), 1, file))
        {   
            if(tn.id == search_id) 
            {  
                printf(" %s", tn.sentence);
            }
        }
        fclose(file); 

        printf("\nDo you want to exit (Y or N): "); scanf(" %c", &loop_exit);
    }while (loop_exit == 'n' || loop_exit == 'N');

    return 0;
}