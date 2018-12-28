#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void CourseGrade(float mark,int i,int j,int k,int l); 
void CourseTaken();
void Culculate_GPAandCGPA(int i,int j,int k);
void Student_Info();
 
void Display_GradeReport();
void Status(float);
void CourseGrade(float mark,int i,int j,int k,int l);
void Write_GradeReport(int i,int j,int k);
struct SemesterCourses
{
	char course_number[6][100];
	char course[6][100];
	float score[6];
	int credit_hour[6];
	int totalcredit_hour;
	float grade_point[6];
	char grade[6][2];
	float GPA;
	float CGPA;
};

struct Year
{
	int semester;
	SemesterCourses CS[2];
};
 
struct student
{
	int ID,year,semester,age;
	char sex[10];
	string stuID[1][15];
	char stuFName[15];
	char stuLName[15];
	int acadamicyear, y;
  	Year ye[3];
};
struct student s[100];

int n;
int semester;

int main()
{
 	fstream file;
 	file.open("Gradereport.txt",ios::out);//open a file to write
 	 cout<<"====================================================\n";

          cout<<"StudentGrade Report \n"; 
          cout<<"Welcome To Student Grade Report:\n";

          cout<<"====================================================\n";
//----------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
			file<<"====================================================\n";

          file<<"Student Grade Report \n";
          file<<"Welcome To Student Grade Report:\n";
          file<<"====================================================\n";
	file.close();
  
  Student_Info();
	CourseTaken();
  for(int i=0;i<n;i++){
  	//cout<<"\nHave entered in the loop";
   for(int j=0;j<s[i].y;j++)
	{
	//cout<<"\nHave entered in the 2nd loop";
	for(int k=0;k<semester;k++)
	{
		//cout<<"\nHave entered in the 3rd loop";
		Write_GradeReport(i,j,k);
	}
}

 }
 Display_GradeReport();
 return 0;
 }

 void Student_Info()
 {
  int i;
  cout<<"How many Students you want to do grade report ?";
  cin>>n;
  cout<<"\nStudent Information:\n";

  for(i=0;i<n;i++)
  {
   cout<<"Enter Acadamic Year:\n";
   cin>>s[i].acadamicyear;
   cout<<"Enter student_"<<i+1<<" First name:\n";
   cin>>s[i].stuFName;
   cout<<"Enter student_"<<i+1<<" Last name:\n";
   cin>>s[i].stuLName;
   cout<<"Enter student_"<<i+1<<" ID number:\n";
   cin>>s[i].ID;
   cout<<"Enter student_"<<i+1<<" Sex:\n";
   cin>>s[i].sex;
   cout<<"Enter student_"<<i+1<<" Year:\n";
   cin>>s[i].y;
   cout<<"Enter student_"<<i+1<<" Semester:\n";
   cin>>semester;

  }

 }
 
 void CourseTaken()
 {
 cout<<"/n-------------------------------------------------------------------/n";
  cout<<"/n-------------------------------------------------------------------/n";
  cout<<"Enter the Courses and their corresponding Course id that have been taken by you:\n";
  for(int i=0;i<n;i++)
  {
  	for (int j=0; j<s[i].y;j++)
  	{
  	cout<<"Enter student_"<<i+1<<" courses taken in year"<<j+1<<"\n";
	 for(int k=0;k<semester;k++)
	  {
	  	int TCH=0;//total credit hour
	  	cout<<"Enter student_"<<i+1<<" courses taken in Semester"<<k+1<<"\n";
		for(int l=0;l<6;l++)
		{
		cout<<"course"<<l+1;
		cout<<"\n\t name:";
			cin>>s[i].ye[j].CS[k].course[l];
		cout<<"\n\tcourse number:\n";
			cin>>s[i].ye[j].CS[k].course_number[l];
		cout<<"\n\tcredit hour:\n";
			cin>>s[i].ye[j].CS[k].credit_hour[l];
			TCH=TCH+s[i].ye[j].CS[k].credit_hour[l];
		cout<<"\n\tScored mark:\n";
			cin>>s[i].ye[j].CS[k].score[l];
			CourseGrade(s[i].ye[j].CS[k].score[l],i,j,k,l);
		}
		s[i].ye[j].CS[k].totalcredit_hour=TCH;
		Culculate_GPAandCGPA(i,j,k);
	  } 
	  
	}
  }
 }
 
void CourseGrade(float mark,int i,int j,int k,int l)
  {
    int result;
    if(mark<=100 && mark>90)
    {
    s[i].ye[j].CS[k].grade_point[l]=4.0;
	s[i].ye[j].CS[k].grade[l][0]='A';
    s[i].ye[j].CS[k].grade[l][1]='+';
    }
    else if(mark<=90 && mark>85)
    {
    s[i].ye[j].CS[k].grade_point[l]=4;
    s[i].ye[j].CS[k].grade[l][0]='A';
    s[i].ye[j].CS[k].grade[l][1]='\t';
    }
    else if(mark<=85 && mark>80)
    {
    s[i].ye[j].CS[k].grade_point[l]=3.75;
    s[i].ye[j].CS[k].grade[l][0]='A';
    s[i].ye[j].CS[k].grade[l][1]='-';
    }
    else if(mark<=80 && mark>75)
    {
    s[i].ye[j].CS[k].grade_point[l]=3.5;
    s[i].ye[j].CS[k].grade[l][0]='B';
    s[i].ye[j].CS[k].grade[l][1]='+';
    }
    else if(mark<=75 && mark>70)
    {
    s[i].ye[j].CS[k].grade_point[l]=3;
    s[i].ye[j].CS[k].grade[l][0]='B';
    s[i].ye[j].CS[k].grade[l][1]='\t';
    }
    else if(mark<=70 && mark>65)
    {
	s[i].ye[j].CS[k].grade_point[l]=2.75;
    s[i].ye[j].CS[k].grade[l][0]='B';
    s[i].ye[j].CS[k].grade[l][1]='-';
     
    }
    else if(mark<=65 && mark>60)
    {
    s[i].ye[j].CS[k].grade_point[l]=2.5;
    s[i].ye[j].CS[k].grade[l][0]='C';
    s[i].ye[j].CS[k].grade[l][1]='+';
    }
    else if(mark<=60 && mark>50)
    {
    s[i].ye[j].CS[k].grade_point[l]=2;
    s[i].ye[j].CS[k].grade[l][0]='C';
    s[i].ye[j].CS[k].grade[l][1]='\t';
    }
    else if(mark<=50 && mark>45)
    {
	s[i].ye[j].CS[k].grade_point[l]=1.75;
    s[i].ye[j].CS[k].grade[l][0]='C';
	s[i].ye[j].CS[k].grade[l][1]='-';
    }
	else if(mark<=45 && mark>40)
	{
    s[i].ye[j].CS[k].grade_point[l]=1;
    s[i].ye[j].CS[k].grade[l][0]='D';
    s[i].ye[j].CS[k].grade[l][1]='\t';
	}
    else if(mark<=40 && mark>30)
    {
    s[i].ye[j].CS[k].grade_point[l]=0;
    s[i].ye[j].CS[k].grade[l][0]='F';
    s[i].ye[j].CS[k].grade[l][1]='x';
    }
    else if(mark<=30 && mark>0)
    {
    s[i].ye[j].CS[k].grade_point[l]=0;
    s[i].ye[j].CS[k].grade[l][0]='F';
    s[i].ye[j].CS[k].grade[l][1]='\t';
    }
    else
    {
    cout<<"mark out of range.\n";
    }
 }
 
void Culculate_GPAandCGPA(int i,int j,int k)
 {
int TCH=0;

float CGPA, Gpoint=0.0;
float GPA=0.0;
for(int l=0;l<6;l++)
 {
 	GPA=GPA + (s[i].ye[j].CS[k].credit_hour[l]*s[i].ye[j].CS[k].grade_point[l]);
 }
GPA=GPA/(s[i].ye[j].CS[k].totalcredit_hour);
s[i].ye[j].CS[k].GPA=GPA;
for(int a=0;a<j;a++)
{ int b;
for ( b=0;b<k;b++)
{
	Gpoint=Gpoint + (s[i].ye[a].CS[b].GPA * s[i].ye[a].CS[b].totalcredit_hour);
	TCH=TCH+s[i].ye[a].CS[b].totalcredit_hour;
}
CGPA=Gpoint/TCH;
s[i].ye[a].CS[b].CGPA=CGPA;
}

cout<<"GPA and CGPA of the Year "<<j+1<<"Semester "<<k+1<<"of student"<<i+1<<"have been Calculated";
 }


  void Status(float sta)
 {
  if(sta==4)
  {
   cout<<"Status: Very great distinction.\n";
  }
  else if(sta>=3.75 && sta<=3.99)
  {
   cout<<"Status: Grate distinction.\n";
  }
  else if(sta>3.5 && sta<=3.74)
  {
   cout<<"Status: Distinction.\n";
  }
  else if(sta>3.49 && sta<=3.25)
  {
   cout<<"Status: dean's list.\n";
  }
  else if(sta>=2.0 && sta<=3.24)
  {
   cout<<"Status: Promoted.\n";
  }
  else if(sta>1.75 && sta<=1.99)
  {
   cout<<"Status: Warning.\n";
  }
  else if(sta>1.00 && sta<=1.74)
  {
   cout<<"Status: Readmission.\n";
  }
  else if(sta>0.0 && sta<1.0)
  {
   cout<<"Status: GO HoMe.\n";

  }

}

void Write_GradeReport(int i,int j,int k)
{
	string grade;
	cout<<"\nGetting into the Part";
	fstream file;
	file.open("Gradereport.txt",ios::out);

file<<"=============================================================================";  
file<<endl<<endl<<endl;
file<<"                             STUDENTS GRADE REPORT"<<endl;
file<<"________________________________________________________________________________"<<endl;

file<<"A/C Year:"<<s[i].acadamicyear-j<<"                                   STUDENT's NAME:"<<s[i].stuFName<<" "<<s[i].stuLName<<endl;
file<<"year:"<<j+1<<"                                          ID No:"<<s[i].ID<<endl;
file<<"semester:"<<k+1<<"                                      sex:"<<s[i].sex<<endl<<endl;
file<<"________________________________________________________________________________"<<endl;
file<<"|Course Name | Course Number | GRADE |Credit hour|Grade point|"<<endl;
file<<"________________________________________________________________________________"<<endl;
for(int a=0;a<6;a++)
{
	grade="";
for(int h=0;h<2;h++)
{
grade=grade+s[i].ye[j].CS[k].grade[a][h];
}
file<<"|"<<s[i].ye[j].CS[k].course[a]<<"|"<<s[i].ye[j].CS[k].course_number[a]<<"           |    "<<grade<<" |     "<<s[i].ye[j].CS[k].credit_hour[a]<<"     |     "<<s[i].ye[j].CS[k].grade_point[a]<<"   |"<<endl;
file<<"________________________________________________________________________________"<<endl;
}
file<<endl;
file<<" _______________________________"<<endl;
file<<"|________________GPA____________|"<<endl;
file<<"|Current semester  |"<<s[i].ye[j].CS[k].GPA<<"      |"<<endl;
file<<"|__________________|____________|"<<endl;
if(k==1)
{
file<<"|Previous semester |"<<s[i].ye[j].CS[k-1].GPA<<"        |"<<endl;
}
else if(k==0 && j>0){
file<<"|Previous semester |"<<s[i].ye[j-1].CS[k+1].GPA<<"      |"<<endl;
}
else{
file<<"|Previous semester |"<<0.0<<"          |"<<endl;
}
file<<"|__________________|____________|"<<endl;
file<<"|cumulative        |"<<s[i].ye[j].CS[k].CGPA<<"           |"<<endl;
file<<"|__________________|____________|"<<endl;
Status(s[i].ye[j].CS[k].CGPA);	
	
file.close();
}

void Display_GradeReport()
{
fstream file;
file.open("GradeReport.txt",ios::in);
char ch[300]; //to read single character
while(!file.eof())
   {
       file.getline(ch,300); //read single character from file
       cout<<ch<<'\n';
   }
    
file.close();
}

