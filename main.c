#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
     int id;
     char name[30];
     char gender[7];
     int quizes;
     int mid;
     int finals;
     float total;
     char temp[30];
};
struct student s[20];
struct student sort[20];
int len=0;
void option(void){
printf("-------------------------------------------------------\n");
printf("-------------------------------------------------------\n");
printf("                         Menu                          \n");
printf("-------------------------------------------------------\n");
printf("-------------------------------------------------------\n");
printf("1. Add Student record\n");
printf("2. Delete Student record\n");
printf("3. Update Student record\n");
printf("4. View all Student record\n");
printf("5. Calculate an average of a selected Student's score\n");
printf("6. Show student who gets the max total score\n");
printf("7. Show student who gets the min total score\n");
printf("8. Find student by ID\n");
printf("9. Sort record by total scores\n");
printf("10. Exit\n");
printf("-------------------------------------------------------\n");
printf("\nChoose Your Option: ");

}
void addstudent(void){
    printf("Enter Student ID, Name, Gender, Quizzes Score, Mid-term Score, Final Score:\n");
    scanf("%d%s%s%d%d%d",&s[len].id,s[len].name,s[len].gender,&s[len].quizes,&s[len].mid,&s[len].finals);
    s[len].total=((float)(s[len].quizes+s[len].mid+s[len].finals)/3);
            sort[len].id = s[len].id;
            strcpy(sort[len].name,s[len].name);
            strcpy(sort[len].gender,s[len].gender);
            sort[len].quizes = s[len].quizes;
            sort[len].mid = s[len].mid;
            sort[len].finals = s[len].finals;
            sort[len].total = s[len].total;
    len= len+1;

}
void deletestudent(void){
    int i,id,p;
    printf("Enter Student ID to Perform Deletion:\n");
    scanf("%d", &id);
    for(i=0;i<len;i++)
    {
        if(id==s[i].id)
        {
           p=i;
           break;
        }
    }
   for(i=p; i<len-1; i++)
        {
            s[i].id = s[i + 1].id;
            strcpy(s[i].name,s[i+1].name);
            strcpy(s[i].gender,s[i+1].gender);
            s[i].quizes = s[i + 1].quizes;
            s[i].mid = s[i + 1].mid;
            s[i].finals = s[i + 1].finals;
            s[i].total = s[i + 1].total;
        }

        len--;


}
void updatestudent(void){
    int i,id,p,o,k;
    char v[20];
    printf("Enter Student ID to Perform Update:\n");
    scanf("%d", &id);
    for(i=0;i<len;i++)
    {
        if(id==s[i].id)
        {
           p=i;
           break;
        }
    }
    printf("--------------------------------------------\n");
    printf("                Option for Update            \n");
    printf("--------------------------------------------\n");
    printf("1. Student ID\n");
    printf("2. Name \n");
    printf("3. Gender\n");
    printf("4. Quizzes Score\n");
    printf("5. Mid Score\n");
    printf("6. Final Score\n");
    printf("--------------------------------------------\n");
    printf("Chose Option:");
    scanf("%d",&o);
    if(o==1)
    {
        printf("Enter Update ID:");
        scanf("%d",&k);
        s[p].id = k;

    }
    else if(o==2)
    {
        printf("Enter Update Name:");
        scanf("%s",v);
        strcpy(s[p].name,v);
    }
     else if(o==3)
    {
        printf("Enter Update Gender:");
        scanf("%s",v);
        strcpy(s[p].gender,v);
    }
     else if(o==4)
    {
        printf("Enter Update Quizzes Score:");
        scanf("%d",&k);
        s[p].quizes= k;
        s[p].total=((float)(s[p].quizes+s[p].mid+s[p].finals)/3);
    }
      else if(o==5)
    {
        printf("Enter Update Mid Score:");
        scanf("%d",&k);
        s[p].mid= k;
        s[p].total=((float)(s[p].quizes+s[p].mid+s[p].finals)/3);
    }
    else if(o==6)
    {
        printf("Enter Update Final Score:");
        scanf("%d",&k);
        s[p].finals= k;
        s[p].total=((float)(s[p].quizes+s[p].mid+s[p].finals)/3);
    }
    else{

        printf("\n");
    }



}
void viewstudent(void){

    int i;
     printf("Student ID:  Name:   Gender:   Quizzes Score:   Mid-term Score:   Final Score:   Total Score\n");
    for(i=0;i<len;i++)
    {

    printf("  %d     %s       %s       %d      %d       %d      %f\n",s[i].id,s[i].name,s[i].gender,s[i].quizes,s[i].mid,s[i].finals,s[i].total);
    }

}
void avgstudent(void){
    int i,j,n,p;
    printf("Enter number of Student to Calculate Average:\n");
    scanf("%d", &n);
    int std[n];
    float sum=0.0,avg;
    float score[n];
    printf("Enter Student's ID to calculate average: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&std[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<len;j++){
        if(std[i]==s[j].id)
        {
           score[i]=s[j].total;
           break;
        }
        }
    }
   for(i=0; i<n; i++)
        {
           sum+= score[i];
        }

     avg= sum/n;

  printf("\nAverage of a Selected Student's Total Score: %f\n",avg);
}
void maxtotal(void){
    int i,p;
    float max=0.0;

      max = s[0].total;
    for (i = 1; i < len; i++){
        if (s[i].total > max){
            max = s[i].total;
        }
    }
     for(i=0;i<len;i++)
    {
        if(max==s[i].total)
        {
           p=i;
           break;
        }
    }
   printf("Max Total Score Getting Student Data:\n");
   printf("Student ID:  Name:  Gender:   Quizzes Score:   Mid-term Score:  Final Score:   Total Score:\n");
   printf("  %d         %s      %s      %d      %d     %d     %f\n",s[i].id,s[i].name,s[i].gender,s[i].quizes,s[i].mid,s[i].finals,s[i].total);

}
void mintotal(void){
    int i,p;
    float min=0.0;

      min = s[0].total;
    for (i = 1; i < len; i++){
        if (s[i].total < min){
            min = s[i].total;
        }
    }
     for(i=0;i<len;i++)
    {
        if(min==s[i].total)
        {
           p=i;
           break;
        }
    }
   printf("Min Total Score Getting Student Data:\n");
   printf("Student ID:  Name:   Gender:  Quizzes Score:  Mid-term Score:   Final Score:   Total Score:\n");
   printf("  %d         %s      %s      %d      %d     %d     %f\n",s[i].id,s[i].name,s[i].gender,s[i].quizes,s[i].mid,s[i].finals,s[i].total);

}
void findstudent(void){
    int i,id,p, flag=0;
    printf("Enter Student ID to Find:\n");
    scanf("%d", &id);
    for(i=0;i<len;i++)
    {
        if(id==s[i].id)
        {
           p=i;
           flag=1;
           break;
        }
    }
    if(flag==1){
   printf("Student ID:  Name:   Gender:   Quizzes Score:   Mid-term Score:    Final Score:   Total Score\n");
   printf("  %d         %s        %s       %d       %d       %d       %f\n",s[p].id,s[p].name,s[p].gender,s[p].quizes,s[p].mid,s[p].finals,s[p].total);
    }
    else
    {
        printf("Wrong Student ID Chose.\n");
    }
}
void sortstudent(void){
    int i,j,id,q;
    float p;
for(i=0;i<len-i;i++)
{
    for(j=0;j<len-1-i;j++)
    {
        if(sort[j].total<sort[j+1].total)
        {
            p=sort[j].total;
            sort[j].total=sort[j+1].total;
            sort[j+1].total=p;

             q=sort[j].id;
            sort[j].id=sort[j+1].id;
            sort[j+1].id=q;


            strcpy(sort[j].temp,sort[j].name);
            strcpy(sort[j].name,sort[j+1].name);
            strcpy(sort[j+1].name,sort[j].temp);

            strcpy(sort[j].temp,sort[j].gender);
            strcpy(sort[j].gender,sort[j+1].gender);
             strcpy(sort[j+1].gender,sort[j].temp);

        }
    }
}
    printf("Student ID:       Name:         Gender:           Total Score\n");
    for(i=0;i<len;i++)
    {

    printf("  %d        %s        %s        %f\n",sort[i].id,sort[i].name,sort[i].gender,sort[i].total);
    }


}
int main()
{
int t;
while (1){
option();
scanf("%d",&t);
switch(t){

         case 1:{
              addstudent();
              break;

               }

         case 2:
             {
          deletestudent();
            break;
             }

         case 3:
             {
             updatestudent();
             break;
             }

         case 4:{
                viewstudent();
                break;
         }
         case 5:
             {
                 avgstudent();
                 break;
             }

         case 6:
             {
                maxtotal();
                 break;
             }
         case 7:
             {
                 mintotal();
                 break;
             }

         case 8:
                {
                    findstudent();
                    break;
                }
         case 9:
               {
                   sortstudent();
                   break;
               }
         case 10:{
         return 0;

         }
         default:
             {
                 printf("Wrong Output\n");
             }

    }


}

     return 0;
}
