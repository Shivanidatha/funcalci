#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

struct Date
{
    int d, m, y;
};
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
 

int cal1();
int cal2();
int cal3();
int cal4();
int cal5();
int cal6();
int isLeapYear(int year, int mon); 
string zodiac_sign(int day, string month);
int e_function ();
int countLeapYears(Date d);
int getDifference(Date dt1, Date dt2);
int d;
int m;
int y;
string weekday_name( int weekday );
string weekday( int dd, int mm, int yyyy );
int monthOffset( int month );
bool isLeap( int year );



int main()
{
    int s;
    cout<<"## Welcome to FUNCALCI WORLD ##\n Here's the calci list"<<endl;
    cout<<"1 Age calci\n2 BMI calci\n3 Horoscope calci\n4 BMR calci\n5 Duration calci\n6 Weekday calci"<<endl;
    cout<<"Enter the calci key"<<endl;
    cin>>s;
    switch(s){
        case 1: cal1();
            break;
        case 2: cal2();
            break;
        case 3: cal3();
            break;
        case 4: cal4();
            break;
        case 5: cal5();
            break;
        case 6: cal6();
            break;
        default:
            cout<<"You entered invalid key";
            break;
    }
        return 0;

}

int cal1(){
    
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm *ct;
    
    cout<<"Enter your date of birth (DD MM YYYY): ";
    cin>>days>>month >>year;
 
    ts = time(NULL);
    ct = localtime(&ts);
 
    cout<<"Current Date:"<<
            ct->tm_mday<< ct->tm_mon + 1<<ct->tm_year + 1900;
 
    days = monthDays[month - 1] - days + 1;
 
    /* leap year checking*/
    if (isLeapYear(year, month)) 
    {
            days = days + 1;
    }
 
    /* calculating age in no of days, years and months */
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;
 
    /* checking for leap year feb - 29 days */
    if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1))) 
    {
            if (days >= (monthDays[ct->tm_mon] + 1)) 
            {
                    days = days - (monthDays[ct->tm_mon] + 1);
                    month = month + 1;
            }
    } 
    else if (days >= monthDays[ct->tm_mon]) 
    {
            days = days - (monthDays[ct->tm_mon]);
            month = month + 1;
    }
 
    if (month >= 12) 
    {
            year = year + 1;
            month = month - 12;
    }
 
    cout<<"\n## Hey you are "<<year<< "years"<<month<< "months and"<<days<< "days old. ##\n";
 
    return 0;
}

int isLeapYear(int year, int mon) 
{
    int flag = 0;
    if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (mon == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (mon == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}

int cal2(){
    
    float w,h,bmi;
    cout<<"Enter weight in kgs and height in meters";
    cin>>w>>h;
    bmi=w/(h*h);
    cout<<"BMI : "<<bmi;
    bmi<18.5?cout<<"Underweight":(bmi<25)?cout<<"Normal weight":(bmi<30)?cout<<"Overweight":cout<<"Obesity";
    return 0;
}

int cal3(){
    int day ;
    cout<<"Enter date";
    cin>>day;
    char month[20];
    cout<<"Enter the month name";
    cin>>month;
    string s=zodiac_sign(day, month);
    cout<<s;
    return 0;
}
string zodiac_sign(int day, string month)
{
    string astro_sign="";
     
    if (month == "december"){
         
        if (day < 22)
        astro_sign = "Sagittarius";
        else
        astro_sign ="capricorn";
    }
         
    else if (month == "january"){
        if (day < 20)
        astro_sign = "Capricorn";
        else
        astro_sign = "aquarius";
    }
         
    else if (month == "february"){
        if (day < 19)
        astro_sign = "Aquarius";
        else
        astro_sign = "pisces";
    }
         
    else if(month == "march"){
        if (day < 21) 
        astro_sign = "Pisces";
        else
        astro_sign = "aries";
    }
    else if (month == "april"){
        if (day < 20)
        astro_sign = "Aries";
        else
        astro_sign = "taurus";
    }
         
    else if (month == "may"){
        if (day < 21)
        astro_sign = "Taurus";
        else
        astro_sign = "gemini";
    }
         
    else if( month == "june"){
        if (day < 21)
        astro_sign = "Gemini";
        else
        astro_sign = "cancer";
    }
         
    else if (month == "july"){
        if (day < 23)
        astro_sign = "Cancer";
        else
        astro_sign = "leo";
    }
         
    else if( month == "august"){
        if (day < 23) 
        astro_sign = "Leo";
        else
        astro_sign = "virgo";
    }
         
    else if (month == "september"){
        if (day < 23)
        astro_sign = "Virgo";
        else
        astro_sign = "libra";
    }
         
    else if (month == "october"){
        if (day < 23)
        astro_sign = "Libra";
        else
        astro_sign = "scorpio";
    }
         
    else if (month == "november"){
        if (day < 22)
        astro_sign = "scorpio";
        else
        astro_sign = "sagittarius";
    }
         
    return astro_sign;
}
    
int cal4(){
     cout << "Your BMR will tell you roughly how many calories" << endl;
    cout << "Your body burns in a day without any additonal exercise" << endl;    

    e_function ();

}

int e_function()
{
     const int g2SIZE = 7;

     cout << "\n\n";
     cout << "What is your height in inches? ";
     
     int height;
     cin >> height; //get height
     
         while (height < 50 || height > 96)
               {
                       cout << "\n\n";
                       cout << "You must be taller than 50 inches" << endl;
                       cout << "Please enter a height between 50 and 96" << endl;
                       cin >> height;

                       }
    cout << "Thank you." << endl;


    cout << "\n\n";
    cout << "Now, how much do you weight in pounds? ";
    int weight;
    cin >> weight;
    
    while (weight <40 || weight>450)
    {
    cout << "\n\n";
    cout << "Please enter a weight between 40 and 450" << endl;
    cin >> weight;
    }
    
    cout << "Thank you" << endl;
    cout << "\n\n";
    cout << "Now how old are you (In Years): "; // get age
    int age;
    cin >> age;

    while (age < 10 || age > 80)
          {
               cout << "\n\n";
               cout << "Im sorry, but this program is not accurate" << endl;
               cout << "Please enter an age beteeen 10 and 80" << endl;
               cin >> age;
               }
    cout << "\n\nn" << "Calculating BMR..." << endl;
    double bmr;
    double amr;
    bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    cout << "\n\n";
    cout << "Your Basal Metabolic Rate is " << bmr << "." << endl;
    cout << "\n" << "This is roughly the amount of calories your body will burn in a day" << endl;
    cout << "without any additional exercise." << endl;
    
    cout << "\n\n" << "Now that you know your Basal Metobolic Rate (BMR)" << endl;
    cout << "Let's take a look at your AMR" << endl;
    cout << "Your AMR is your BMR adjusted for your activity level. " << endl;
    
    cout << "\n\n";
    cout << "Please select your activity level; " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Little to no exercise " << endl;
    cout << "2. Light exercise (1-3 days per week) " << endl;
    cout << "3. Moderate exercise ( 3-5 days per week) " << endl;
    cout << "4. Heavy exercise ( 6-7 days per week ) " << endl;
    cout << "5. Very heavy exercise (twice per day, extra heavy workouts) " << endl;
    cout << "\n\n" << "Please enter the number to the left of your activity" ;
    
    int selection;
    cin>>selection;
    
    if (selection == 1)
    {
    	
               amr = bmr * 1.2;
               cout << "\n\n";
               cout << "Your BMR is: " << bmr << endl;
               cout << "Your AMR is: " << amr << endl;
    }
    
    if (selection == 2)
    {         
               
               amr = bmr * 1.375;
               cout << "\n\n";
               cout << "Your BMR is: " << bmr << endl;
               cout << "Your AMR is: " << amr << endl;
    }
    
    if (selection == 3)
    {
    	    
               amr = bmr * 1.55;
               cout << "\n\n";
               cout << "Your BMR is: " << bmr << endl;
               cout << "Your AMR is: " << amr << endl;
    }
    
    if (selection == 4)
    {
    	       
               amr = bmr * 1.475;
               cout << "\n\n";
               cout << "Your BMR is: " << bmr << endl;
               cout << "Your AMR is: " << amr << endl;
    }
    
    if (selection == 5)
    {           
                
               amr = bmr * 1.9;
               cout << "\n\n";
               cout << "Your BMR is: " << bmr << endl;
               cout << "Your AMR is: " << amr << endl;
    }
    
                      
                      
    
    return 0;
}

int cal5(){
    int a,b,c,x,y,z;
    cout<<"Enter day month year of first date"<<endl;
    cin>>a>>b>>c;
    cout<<"Enter day month year of second date"<<endl;
    cin>>x>>y>>z;    
    Date dt1 = {a,b,c};
    Date dt2 = {x,y,z};
 
    cout << "Difference between two dates is " << getDifference(dt1, dt2);
 
    return 0;
}
int countLeapYears(Date d)
{
    int years = d.y;
 
    if (d.m <= 2)
        years--;
 
    return years / 4 - years / 100 + years / 400;
}
 

int getDifference(Date dt1, Date dt2)
{
   
    long int n1 = dt1.y*365 + dt1.d;
 
    for (int i=0; i<dt1.m - 1; i++)
        n1 += monthDays[i];
 
   
    n1 += countLeapYears(dt1);
 

    long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    return (n2 - n1);
}
int cal6(){
    cout<<"Enter date month and year";
    cin >> d >> m >> y;
    cout << weekday(d, m, y);
    
}
string weekday( int dd, int mm, int yyyy )
  {
  	int yy, total;
  	string date = "";
      yy= yyyy-1900;
      total= (yy/4) + yy +dd;
      total = monthOffset(mm) + total;
      bool leapyear = isLeap(yyyy);
      if (leapyear == true)
      {
          if (mm == 1 || mm == 2)
              total = total -1;
      }
      int weekday = total%7;
      weekday_name(weekday);
  	date = weekday_name(weekday);

  	return date;
  }

string weekday_name( int weekday )
  {
  	string result = "";

  	if (weekday == 1)
  	{
  		result = "Sunday";
  	}
  	else if (weekday == 2)
  	{
  		result = "Monday";
  	}
      else if (weekday == 3)
  	{
  		result = "Tuesday";
  	}
      else if (weekday == 4)
  	{
  		result = "Wensday";
  	}
      else if (weekday == 5)
  	{
  		result = "Thursday";
  	}
      else if (weekday == 6)
  	{
  		result = "Friday";
  	}
      else if (weekday == 7)
  	{
  		result = "Saturday";
  	}
      else if (weekday == 0)
  	{
  		result = "Saturday";
  	}
  	else
      {
          result= "ERROR!";
      }
  	return result;
  }
 
int monthOffset( int month )
  {
  	int result=0;
  	if (month==1)
          result=1;
      if (month==2)
          result=4;
      if (month==3)
          result=4;
  	if (month==4)
          result=0;
      if (month==5)
          result=2;
      if (month==6)
          result=5;
      if (month==7)
          result=0;
      if (month==8)
          result=3;
      if (month==9)
          result=6;
      if (month==10)
          result=1;
      if (month==11)
          result=4;
      if (month==12)
          result=6;
      else if (month< 1 || month>12)
          result=-1;
  	return result;
  }
bool isLeap( int year )
{
 
  bool result;

  if ( year%400 == 0 )
  	result = true;
  else if ( year%100 == 0 )
  	result = false;
  else if ( year%4 == 0 )
  	result = true;
  else
  	result = false;
  
  return result;
}
      