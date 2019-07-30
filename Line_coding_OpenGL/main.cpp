#include <GL/glut.h>
#include <bits/stdc++.h>
#include "AMI.h"
#include "NRZ.h"
#include "MANCHASTER.h"

using namespace std;

                    
void initGL()                   // Initialize OpenGL Graphics 
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}

void display()                // Reset the model-view matrix
{
    glClear(GL_COLOR_BUFFER_BIT);    
    glMatrixMode(GL_MODELVIEW);     
    glLoadIdentity();

}
void SubString(string s, int l, int h)
{
    for( int i = l; i <= h; i++ )
        printf("%c ", s[i]);
}



// function prints the longest palindrome substring
void longestPalSubstr(string s)
{
    int maxLength = 1;  

    int start = 0;
    int len = s.length();

    int low, high;
    for (int i = 1; i < len; i++)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            low--;
            high++;
        }

        // Find the longest odd length palindrome with center
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            low--;
            high++;
        }
    }

    printf("\n\nLongest palindrome substring is: \n\n");

    SubString(s, start, start + maxLength - 1);


    cout<<"\n\nLength of longest palindrome: "<<maxLength<<endl ;
}                                                                                       //end of palindrome function

string array_to_string(int arr[] , int size_of_array)
{
  string S = "";
  for(int i =0 ; i< size_of_array ; i++)
  {
    S += to_string(arr[i]) ;
  }
  return S ;
}


void program ()
{
 cout<<"Select type of Data generation : \n";
 cout<<"1.Random sequence \n" ;
 cout<<"2.Random sequence with fixed sub-sequence\n" ;
 int choice  ;
 cin>>choice ;
 int Zeroes ;
 srand(time(NULL));
 int input[14] ;
 if(choice == 2)
   {
	   cout<<"Choose the subsequence : \n";
	   cout<<"1. 8 consecutive zeroes\n";
	   cout<<"2. 4 consecutive zeroes\n";
	   cin>>Zeroes ;

	   if(Zeroes == 1)  //Zeroes = 8
	   {
	     for(int i =0 ; i< 14 ; i++)
	     {
	       input[i]= rand() & 1 ;
	     }

	     int bla = rand() %  7 ;
	     cout<<bla<<endl;
	     for(int i = bla; i<bla+8 ; i++)
	     {
	       input[i] = 0 ;
	     }
	   }
	   else   //Zeroes = 4
	   {
	     for(int i =0 ; i< 14 ; i++)
	     {
	      input[i]= rand() & 1 ;
	     }
	     int bla = rand() %  11 ;
	     for(int i = bla; i<bla+4 ; i++)
	     {
	       input[i] = 0 ;
	     } 
	   }
   }

else
{
     for(int i =0 ; i< 14 ; i++)
     {
       input[i]= ( rand() & 1) ;
     }
}

   cout<<"\n14 bit Data stream is : \n" ;
   for(int i =0 ; i<14 ; i++)
   {
    cout<<input[i]<<" ";
   }

   string  s = array_to_string(input,14) ;
   longestPalSubstr(s) ;
   cout<<"\n\nSelect Encoding scheme: \n" ;
   cout<<"\n1 : NRZ-L";
   cout<<"\n2 : NRZ-I";
   cout<<"\n3 : MANCHESTER";
   cout<<"\n4 : DIFFERENTIAL MANCHASTER";
   cout<<"\n5 : AMI";      
   cout<<"\n\nEnter Choice : ";
   int type ;
   cin>>type ;

   if(type==1)
   {
    glutInitWindowSize(840, 480);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(500, 100); // Position the window's initial top-left corner
    glutCreateWindow("NRZ-L");  // Create window with the given title
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);      // Select the Projection matrix for operation
    glLoadIdentity();                 // Reset Projection matrix
    gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
    NRZ_L(input) ;
   }

   else if (type==2)
   {

    glutInitWindowSize(840, 480);  
    glutInitWindowPosition(500, 100); 
    glutCreateWindow("NRZ-I");  
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);     
    glLoadIdentity();                
    gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
    NRZ_I(input) ;
   }

   else if(type == 3)
   {
    glutInitWindowSize(840, 480);  
    glutInitWindowPosition(500, 100); 
    glutCreateWindow("Biphase Manchester"); 
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);     
    glLoadIdentity();               
    gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
    manch(input) ;
   }

   else if(type == 4)
   {
   glutInitWindowSize(840, 480);   
   glutInitWindowPosition(500, 100); 
   glutCreateWindow("Differential Manchester ");  
   glutDisplayFunc(display);
   glMatrixMode(GL_PROJECTION);      
   glLoadIdentity();                 
   gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
   diff_manch(input) ;
   }

   else if(type == 5)
   {

   cout<<"Do you want to use scrambling : "<<endl;
   cout<<"1. Yes\n";
   cout<<"2. No \n";
   int yes ;
   cin>>yes ;

     if(yes == 1)
     {
       cout<<"Choose scrambling techniques : "<<endl;
       cout<<"1. B8ZS"<<endl;
       cout<<"2. HDB3"<<endl;
       int b8zs ;
       cin>>b8zs ;

	     if(b8zs == 1)
	     {
               glutInitWindowSize(840, 480);   
	       glutInitWindowPosition(500, 100); 
	       glutCreateWindow("B8ZS"); 
	       glutDisplayFunc(display);
	       glMatrixMode(GL_PROJECTION);      
	       glLoadIdentity();                 
	       gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
	       B8ZS(input) ;
	     }
	     else
	     {
	       glutInitWindowSize(840, 480);   
	       glutInitWindowPosition(500, 100);
	       glutCreateWindow("HDB3");  
	       glutDisplayFunc(display);
	       glMatrixMode(GL_PROJECTION);      
	       glLoadIdentity();                 
	       gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
	       hdb3(input) ;
	     }
     }
     else
     {
       glutInitWindowSize(840, 480);   
       glutInitWindowPosition(500, 100); 
       glutCreateWindow("Differential Manchester ");  
       glutDisplayFunc(display);
       glMatrixMode(GL_PROJECTION);      
       glLoadIdentity();                 
       gluOrtho2D(-0.05, 1.0, -1.0, 1.0);
       AMI(input) ;
     }

   }
  else
   {
     cout<<"INVALID INPUT\n";
     return;
   }

}

void starts()
{
    program() ;
    initGL() ;
    glutMainLoop() ;
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);         
    starts();
    return 0;
}
