#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib> // for random values 
#include<ctime> // for time 
using namespace std;

//   STRUCTURE 
  
struct Triangle{

    double a,b,c; // sides 
    double A,B,C; // angles of triangle
    double area , perimeter; 

};

// Function related to Generation of random triangles 

Triangle generateValid_tri(){
    Triangle t;

    do{
        t.a= rand() % 50 + 1;
        t.b= rand() % 50 + 1;
        t.c= rand() % 50 + 1;
    }while(!(t.a + t.b > t.c && t.b + t.c> t.a && t.c +t.a > t.b));
    return t;
}

// function related to calculating AREA , PERIMETER 

void calculateAngles(Triangle &t){

    double pi=3.1415;

    t.C= acos((t.a*t.a+t.b*t.b-t.c*t.c)/(2 * t.a*t.b))* 180/pi;
    t.A= acos((t.b*t.b+t.c*t.c-t.a*t.a)/(2 * t.c*t.b))* 180/pi;
    t.B= 180.0 - ( t.A+ t.c);

}


void calculateArea_Perimeter(Triangle &t){


    double s;

    t.perimeter = t.a + t.b + t.c;
    s= t.perimeter/2;
    t.area = sqrt( s * ( s- t.a) * (s - t.b) * (s-t.c));
    
}

void displayTriangle(Triangle &t){


    cout<<"Sides :";
    cout<<" a = "<<t.a<<" b = "<<t.b<<" c = "<<t.c<<endl;
    cout<<"Angles : ";
    cout<<" A = "<<t.A<<" B = "<<t.B<<" C = "<<t.C<<endl;
    cout<<"\n";
    cout<<" AREA = "<<t.area<<endl;
    cout<<" PERIMETER = "<<t.perimeter<<endl;
    cout<<"\n";

}

// saving files in txt form and binary form 
  


// MAiN FUNCTION 

int main(){

    srand(time(0)); // to genarte different seed each time 
    const int SIZE = 100;
    Triangle triangle[SIZE];

    for(int i =0 ; i<SIZE; i++){

        triangle[i]=generateValid_tri();
        calculateAngles(triangle[i]);
        calculateArea_Perimeter(triangle[i]);
        cout<<"Triangle = "<<i+1<<endl;
        displayTriangle(triangle[i]);

    }

    // flie handling 
    ofstream newfile;

    newfile.open("C:\\Users\\GMT\\OneDrive\\Desktop\\project pf\\triangles.txt");
    for(int j =0 ; j<SIZE; j++){

        newfile<<"Triangle "<<j+1<<endl;
        newfile<<"Sides  :  ";
        newfile<<" a = "<<triangle[j].a<<"  b = "<<triangle[j].b<<"  c = "<<triangle[j].c<<endl;
        newfile<<"Angles  :  A = "<<triangle[j].A<<"  B = "<<triangle[j].B<<"  C = "<<triangle[j].C<<endl;
        newfile<<"Area = "<<triangle[j].area<<endl;
        newfile<<"perimeter = "<<triangle[j].perimeter<<endl;


    }

    newfile.open("C:\\Users\\GMT\\OneDrive\\Desktop\\project pf\\triangles.bin");
    for(int x=0 ; x<SIZE ; x++){
    newfile.write(reinterpret_cast<char*>(&triangle[x]), sizeof(triangle));
    }
    newfile.close();


    return 0;
}

