void graph()
 {
    glLineWidth(2);
                                                     //print reference lines
    for(int i=0 ; i< 15 ; i++)
    {
     glEnable(GL_LINE_STIPPLE);
     glLineStipple(1,0x099);
     glBegin(GL_LINES);
     glColor3f( 1.0f, 1.0f, 1.0f);
     glVertex2f(i*0.05,-0.5);
     glColor3f( 1.0f, 1.0f, 1.0f);
     glVertex2f(i*0.05, 0.5);
     glEnd();
     glFlush();
     glDisable(GL_LINE_STIPPLE);
    }

     glBegin(GL_LINES);
     glColor3f( 0.0f, 0.0f, 1.0f);
     glVertex2f(0,0);                                 //coordinate axis
     glVertex2f(1,0);
     glVertex2f(0,0.5);
     glVertex2f(0,-0.5);

     glEnd();
     glFlush();
}

void AMI(int arr[])
{
  graph() ;
  int count=0;
  for(int i=0 ; i< 14 ; i++)
  {

    if(arr[i]==0)
    {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,0);
        glVertex2f(i*0.05+0.05,0);
        glEnd();
        glFlush();
     }
    else
    {
       if(count%2==0)
       {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,0);
        glVertex2f(i*0.05,0.3);
        glVertex2f(i*0.05+0.05, 0.3);
        glVertex2f(i*0.05+0.05,0);
        glEnd();
        glFlush();
       }

       else 
       {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,0);
        glVertex2f(i*0.05,-0.3);
        glVertex2f(i*0.05+0.05,-0.3);
        glVertex2f(i*0.05+0.05,0);
        glEnd();
        glFlush();
       }
      count++;
    }
  }
}  
//END of basic AMI


//Scrambling

void up(int i)
{
            glBegin(GL_LINE_STRIP);
            glColor3f( 1.0f, 0.0f, 0.0f);
            glVertex2f(i*0.05,0);
            glVertex2f(i*0.05,0.3);
            glVertex2f(i*0.05+0.05,0.3);
            glVertex2f(i*0.05+0.05,0);
            glEnd();                                                          
            glFlush();
}

void down(int i)
{
            glBegin(GL_LINE_STRIP);
            glColor3f( 1.0f, 0.0f, 0.0f);
            glVertex2f(i*0.05,0);
            glVertex2f(i*0.05,-0.3);
            glVertex2f(i*0.05+0.05,-0.3);
            glVertex2f(i*0.05+0.05,0);
            glEnd();                                                            
            glFlush();
}
void middle(int i)
{
            glBegin(GL_LINE_STRIP);
            glColor3f( 1.0f, 0.0f, 0.0f);
            glVertex2f(i*0.05,0);
            glVertex2f(i*0.05+0.05,0);
            glEnd();
            glFlush();
}

//FOR B8ZS

void B8ZS(int arr[])
{
   graph();
   int one=1;
   int i=0;
   while(i<14)
   {
      if(arr[i]==1)
      {
         one++;
         if(one%2==0)
            up(i);
         else
             down(i);
         i++;
      }
      else if(arr[i]==0)
      {
          int zeroes=0;
	  int j=i;
	  int k=j+7;
	  if(k<=11)
	  {
	     while(j<=k)
	     {
	        if(arr[j]==0)
	          zeroes++;
	        else
	          break;
	        j++;
	     }
	  }
          if(zeroes==8)
          {
	   //FOR 000v 
	         int t=0;
                 int l=i;
                 while(i<=l+3)
                 {
                     if(t==3)
                     {
                       if(one%2==1)
		       {
		         down(i);
		       }
                       else
		       {
		         up(i);
		       }
		       i++;
		       t++;
                     }
                     else
                     {
                        middle(i);
                        i++;
                        t++;
                     }
                 }
          one++;
         //FOR BOVB 

		       k=0;
		       l=i;
		       while(i<=l+3)
		       {
		         if(k==0)
		          {
		            if(one%2==0)
		              up(i);
		            else
		             down(i);
		            k=1;
		            i++;
		          }
		         else
		         {
		           if(k==2)
		           {
		             if(one%2==0)
		              up(i);
		             else
		              down(i);
		            i++;
		            k++;
		           }
		           if(k==3)
		           {
		            if(one%2==0)
		               down(i);
		            else
		               up(i);
		            i++;
		            k++;
		            one++;
		          }
		          else
		          {
		           middle(i);
		           k++;
		           i++;
		          }
		       }
		     }
		   }
           else
           {
             middle(i);
             i++;
           }
      }
   }
}                                                                                       

//FOR HDB3

void hdb3(int arr[])
{
   graph();
   int i=0;
   int one=1;
   int previous_one=0;
   while(i<14)
   {
      if(arr[i]==1)
      {
         previous_one++;
         one++;
         if(one%2==0)
            up(i);
          else
             down(i);
          i++;
      }
      else if(arr[i]==0)
      {
          int zeroes=0;
          int j=i;
          int k=j+3;
          if(k<=13)
          {
             while(j<=k)
             {
                if(arr[j]==0)
                  zeroes++;
                else
                  break;
                j++;
             }
          }
             if(zeroes==4)
            {
            if(previous_one%2==0)
            {
              one+=1;
              int k=0;
              int p=i;
              while(i<=p+3)
               {
                 if(k==0)
                  {
                    if(!(one & 1))
                      up(i);
                   else
                     down(i);
                   k=1;
                   i++;
                  }
              else
              {
                 if(k==3)
                 {
                    if(!(one & 1))
                       up(i);
                   else
                       down(i);
                i++;
                k++;
                }
                else
                {
                  middle(i);
                  k++;
                  i++;

                }
          }
              }
              previous_one+=2;
              }
              else if(previous_one%2==1)
              {
                 int k=0;
                 int p=i;
                 while(i<=p+3)
                 {
                     if(k==3)
                     {
                       if(one%2==1)
                 {
                   down(i);
                 }
                   else
                {
                 up(i);
                }
                i++;
                k++;
                     }
                     else
                     {
                        middle(i);
                        i++;
                        k++;
                     }
                 }
               previous_one+=1;
              }
             }
             else
             {
               middle(i);
               i++;
             }
          }
      }
   }        



