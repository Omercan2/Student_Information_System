#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
//ömer can cetinkaya
int admin=123;
char adminPassword[25]="asd";

struct lecturers{
    int number;
    char name[25];
    char surname[25];
    char password[25];
}lecturer[4];

struct officers{
    int number;
    char name[25];
    char surname[25];
    char password[25];

}officer;



struct students{
    char name[25];
    char surname[25];
    int number;
    char password[25];
    char department[25];

}student[100];

//ogrenci ekleme(adding students)
void addStudent(){
    int i;
    FILE *studentAdress=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\students.txt","a");
    for( i=0;i<100;i++){
        if(student[i].number==-1){
            break;
        }
    }
    printf("Enter students name\n");
    scanf("%s",student[i].name);
    printf("Enter students surname\n");
    scanf("%s",student[i].surname);
    printf("Enter students department\n");
    scanf("%s",student[i].department);

    printf("Enter a students number\n");
    scanf("%d",&student[i].number);
    printf("Enter students password\n");
    scanf("%s",student[i].password);
    student[i+1].number=-1;

    fprintf(studentAdress,"%10s %10s %10s %10d %10s \n" ,student[i].name,student[i].surname,student[i].department,student[i].number,student[i].password);

    printf("Student successfully added\n");

    fclose(studentAdress);
}
//ders ekleme fonksiyonu(adding lessons)

void addLesson(){

    char lesson[25];
    FILE *printlecturer=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\lecturers.txt","r");
    FILE *updatelecturer=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedlecturers.txt","a");

    int tempnumber[4],choose=0;
    char tempname[4][25];
    char tempsurname[4][25];
    char temppassword[4][25];
    printf("Enter a lesson\n");
        scanf("%s",lesson);
    printf("Choose lecturer for opening a lesson\n");
    for(int i=0;i<4;i++){
        fscanf(printlecturer,"%s %s %d %s\n",tempname[i],tempsurname[i],&tempnumber[i],temppassword[i]);
        printf("%d. %s %s \n",i+1,tempname[i],tempsurname[i]);

    }
    scanf("%d",& choose);

    if(choose==1){
        fprintf(updatelecturer,"%20s %20s %20d %20s %20s \n",tempname[0],tempsurname[0],tempnumber[0],temppassword[0],lesson);
    }
    else if(choose==2){
        fprintf(updatelecturer,"%20s %20s %20d %20s %20s \n",tempname[1],tempsurname[1],tempnumber[1],temppassword[1],lesson);
    }
    else if(choose==3){
        fprintf(updatelecturer,"%20s %20s %20d %20s %20s \n",tempname[2],tempsurname[2],tempnumber[2],temppassword[2],lesson);
    }
    else if(choose==4){
        fprintf(updatelecturer,"%20s %20s %20d %20s %20s \n",tempname[3],tempsurname[3],tempnumber[3],temppassword[3],lesson);
    }


    fclose(printlecturer);
    fclose(updatelecturer);



}



void adminFunction(){
    FILE *lecturerAdress=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\lecturers.txt","w");
    //ogretim gorevlilsi gorevlendirme(appointment of a lecturer)
    for(int i=0;i<4;i++){
        printf("Enter lecturers name\n");
        scanf("%s",lecturer[i].name);
        printf("Enter lecturers surname\n");
        scanf("%s",lecturer[i].surname);

        printf("Enter a lecturers number\n");
        scanf("%d",&lecturer[i].number);
        printf("Enter lecturers password\n");
        scanf("%s",lecturer[i].password);


        fprintf(lecturerAdress,"%20s %20s %20d %20s \n" ,lecturer[i].name,lecturer[i].surname,lecturer[i].number,lecturer[i].password);

    }
    fclose(lecturerAdress);
    //memur gorevlendirme(appointment of a officer)
    FILE *officerAdress=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\officer.txt","w");
    printf("Enter officers name\n");
    scanf("%s",officer.name);
    printf("Enter officers surname\n");
    scanf("%s",officer.surname);
    printf("Enter a officers number\n");
    scanf("%d",&officer.number);
    printf("Enter officers password\n");
    scanf("%s",officer.password);
    fprintf(officerAdress,"%10s %10s %10d %10s \n",officer.name,officer.surname,officer.number,officer.password);

    fclose(officerAdress);

}

void officerFunction(){
    int choice=0;
    printf("1-Student registration\n");
    printf("2-Open a lesson\n");
    scanf("%d",&choice);
    if(choice==1){ //ogrenci ekleme(adding students)
        addStudent();

    }
    else if(choice==2){  //ders acma(opening lessons)
        addLesson();
    }

}
//basari durumunu bulan fonksýyon string dondurmesý ýcýn basýnda const char * var
//function for finding success status at start const char* is for returning string
const char * succsesStatus(int midtermexam,int finalexam){
    if(finalexam>=40&&(midtermexam+finalexam)>=80){
        return "Succesful";
    }
    else{
        return "Unsuccesful";
    }

}

//ogretmen fonksiyonu(lecturer Function)
void lecturerFunction(int number,char password[]){

    char tempname[25],lecturerName[25];
    char tempsurname[25],lecturerSurname[25];
    int tempnumber,lecturerNumber,midtermNote,finalNote;
    char temppassword[25],lecturerPassword[25];
    char tempdepartment[25];
    char templesson1[25],lecturerlesson[25];
    char templesson2[25];
    FILE *lecturerFile=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedlecturers.txt","r");
    FILE *studentFile=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedstudents.txt","r");
    FILE *updatedFile=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedstudents1.txt","a");
    for(int i=0;i<4;i++){
        fscanf(lecturerFile,"%s %s %d %s %s",lecturerName,lecturerSurname,&lecturerNumber,lecturerPassword,
               lecturerlesson);
            if(lecturerNumber==number&&(strcmp(lecturerPassword,password)==0)){
                break;
            }
        }

    //burada býr ogrencýye iki satir kullanýlacak iki dersi oldugu icin boyle kullandým
    //student has two lines in the file because he have two lessons
    while(!feof(studentFile)){
        fscanf(studentFile,"%s %s %s %d %s %s %s\n",tempname,tempsurname,tempdepartment,&tempnumber,temppassword,
               templesson1,templesson2);

        if((strcmp(lecturerlesson,templesson1)==0)){

        printf("%s %s %s %d\n",tempname,tempsurname,tempdepartment,tempnumber);
        printf("Enter students midterm exam note\n");
        scanf("%d",&midtermNote);
        printf("Enter students final exam note\n");
        scanf("%d",&finalNote);

        fprintf(updatedFile,"%10s %10s %10s %10d %10s %10s %10d %10d %10s\n",tempname,tempsurname,tempdepartment,tempnumber,
                temppassword,templesson1,midtermNote,finalNote,succsesStatus(midtermNote,finalNote));

            }

        //ikinci dersin notlarýný alma yerý
        //place for second lessons notes
        else if(strcmp(lecturerlesson,templesson2)==0){
        printf("%s %s %s %d\n",tempname,tempsurname,tempdepartment,tempnumber);
        printf("Enter students midterm exam note\n");
        scanf("%d",&midtermNote);
        printf("Enter students final exam note\n");
        scanf("%d",&finalNote);

        fprintf(updatedFile,"%10s %10s %10s %10d %10s %10s %10d %10d %10s\n",tempname,tempsurname,tempdepartment,tempnumber,
                temppassword,templesson2,midtermNote,finalNote,succsesStatus(midtermNote,finalNote));

            }


        }



    fclose(studentFile);
    fclose(updatedFile);
    fclose(lecturerFile);

}
//ortalama bulma fonksiyonu
float findAverage(int number1,int number2){

    return (number1+number2)/2;


}





//ogrenci fonsiyonu
void studentFunction(char name[],char surname[],char department[],int number,char password[]){
    int choose,lesson1,lesson2;
    float average1,average2;
    char tempname[4][25];
    char tempsurname[4][25];
    int tempnumber[4];
    char temppassword[4][25];
    char templesson[4][25];
    char studentName[25];
    char studentSurname[25];
    char studentDepartment[25];
    int studentNumber;
    char studentPassword[25];
    char studentLesson[25];
    int midtermnote,finalnote;
    char studentStatus[25];



    printf("1. Select lesson\n");
    printf("2. See your exam notes\n");
    printf("3. Get a student certificate\n");
    scanf("%d",&choose);
    FILE *studentFile=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedstudents.txt","a");
    FILE *lecturerFile=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedlecturers.txt","r");
    FILE *updatedStudentFile=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\updatedstudents1.txt","a");
    if(choose==1){
        printf("Choose your first lesson\n");
        for(int i=0;i<4;i++){
            fscanf(lecturerFile,"%s %s %d %s %s\n",tempname[i],tempsurname[i],&tempnumber[i],temppassword[i],templesson[i]);
            printf("%d. %s %s %s\n",i+1,tempname[i],tempsurname[i],templesson[i]);
        }
    scanf("%d",&lesson1);
    printf("%s lesson selected \n",templesson[lesson1-1]);
    printf("Choose your second lesson\n");
    scanf("%d",&lesson2);
    printf("%s lesson selected\n",templesson[lesson2-1]);

        if(lesson1==lesson2){
            printf("You cant choose same lesson\n");
        }
        else{
        fprintf(studentFile,"%10s %10s %10s %10d %10s %15s %15s\n",name,surname,department,number,password,
                templesson[lesson1-1],templesson[lesson2-1]);
        }


    }
    //ders notlarinin gorme(seeing lesson notes)
    else if(choose==2){
       while(!feof(updatedStudentFile)){
            fscanf(updatedStudentFile,"%s %s %s %d %s %s %d %d %s\n",studentName,studentSurname,studentDepartment,&studentNumber,
                   studentPassword,studentLesson,&midtermnote,&finalnote,studentStatus);

            if(studentNumber==number&&(strcmp(studentPassword,password)==0)){
                printf("%s midterm:%d final:%d\n",studentLesson,midtermnote,finalnote);

            }
       }


    }
    //ogrenci belgesi(student document)
    else if(choose==3){
        while(!feof(updatedStudentFile)){
            fscanf(updatedStudentFile,"%s %s %s %d %s %s %d %d %s\n",studentName,studentSurname,studentDepartment,&studentNumber,
                   studentPassword,studentLesson,&midtermnote,&finalnote,studentStatus);

            if(studentNumber==number&&(strcmp(studentPassword,password)==0)){
                average1=findAverage(midtermnote,finalnote);

                printf("Students name: %s\n",studentName);
                printf("Students surname: %s\n",studentSurname);
                printf("Students department: %s\n",studentDepartment);
                printf("Students number: %d\n",studentNumber);
                printf("Students first lesson ,midterm note ,final note, average note , succes status: %s ,%d ,%d ,%f,%s \n",studentLesson
                       ,midtermnote,finalnote,average1,studentStatus);

                break;
            }
       }
       //1. donguyu ismini soyismini bir daha yazmamasý ýcýn kýrdým
       // ý broke first loop because ý dont want to write twice name and surname
        while(!feof(updatedStudentFile)){
            fscanf(updatedStudentFile,"%s %s %s %d %s %s %d %d %s\n",studentName,studentSurname,studentDepartment,&studentNumber,
                   studentPassword,studentLesson,&midtermnote,&finalnote,studentStatus);

            if(studentNumber==number&&(strcmp(studentPassword,password)==0)){
                average2=findAverage(midtermnote,finalnote);

                printf("Students seccond lesson ,midterm note ,final note, average note , succes status: %s ,%d ,%d ,%f,%s \n",studentLesson
                       ,midtermnote,finalnote,findAverage(midtermnote,finalnote),studentStatus);
                printf("Overall average of the student: %f\n ",findAverage(average1,average2));

                break;
            }
       }



    }

    fclose(studentFile);
    fclose(lecturerFile);
    fclose(updatedStudentFile);


}




//kullanici giris fonksiyonu(login Function)
void login(){
    char password[25];
    int number=0;
    char exit;
    printf("Enter your number\n");
    scanf("%d",&number);
    printf("Enter your password(it must be only characters)\n");
    scanf("%s",password);

    //admin kontrol
    if(number==admin&&(strcmp(password,adminPassword)==0)){
       adminFunction();
    }
    //ogretim uyesi kontrol
    FILE *lecturerLogin=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\lecturers.txt","r");
    int tempnumber;
    char tempname[25];
    char tempsurname[25];
    char temppassword[25];
    char tempdepartment[25];
    for(int i=0;i<4;i++){
        fscanf(lecturerLogin,"%s %s %d %s\n",tempname,tempsurname,&tempnumber,temppassword);
            if(tempnumber==number&&(strcmp(temppassword,password)==0)){
                lecturerFunction(number,password);
                break;
            }
    }
    fclose(lecturerLogin);

    //memur kontrol
    FILE *officerLogin=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\officer.txt","r");

    fscanf(officerLogin,"%s %s %d %s\n",tempname,tempsurname,&tempnumber,temppassword);

        if(tempnumber==number&&(strcmp(temppassword,password)==0)){
            officerFunction();
        }
    fclose(officerLogin);

    // ogrenci kontrol
    int exit1=0;
    FILE *studentLogin=fopen("C:\\Users\\Omer\\Desktop\\C\\OBS\\students.txt","r");
    for(int j=0;j<100;j++){
        fscanf(studentLogin,"%s %s %s %d %s\n",tempname,tempsurname,tempdepartment,&tempnumber,temppassword);
            if(tempnumber==number&&(strcmp(temppassword,password)==0)){

                while(exit1==0){
                studentFunction(tempname,tempsurname,tempdepartment,tempnumber,temppassword);
                printf("do you want to exit yes(1) no(0)\n");
                scanf("%d",&exit1);


                }
                break;
            }
    }

    fclose(studentLogin);

}






int main()
{

    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);
    setlocale(LC_ALL,"Turkish_turkish.1254");//for turkish character problem
    student[0].number=-1;//ogrencinin numarasi -1 ise orasi bos anlamina geliyor(if students number is equals -1 it means its empty
    login();

    return 0;
}
