void NRZ_L(int arr[])
{
    graph() ;
    for(int i=0 ; i< 14 ; i++)
    {
            int next = 0 , prev = 0;
	    if(arr[i]==arr[i+1] && i <=12)
	      next = 1 ;
	    if(arr[i]==arr[i-1] && i >=1)
	      prev  = 1 ;
	    if(arr[i]==0)
	    {
		glBegin(GL_LINE_STRIP);
		glColor3f( 1.0f, 0.0f, 0.0f);
		if(prev != 1)
		glVertex2f(i*0.05,0);
		glVertex2f(i*0.05,-0.3);
		glVertex2f(i*0.05+0.05,-0.3);
		if( next != 1)
		glVertex2f(i*0.05+0.05,0);
		glEnd();
		glFlush();
	     }

	    else
	    {
		glBegin(GL_LINE_STRIP);
		glColor3f( 1.0f, 0.0f, 0.0f);
		if(prev != 1)
		glVertex2f(i*0.05,0);
		glVertex2f(i*0.05,0.3);
		glVertex2f(i*0.05+0.05, 0.3);
		if( next != 1)
		glVertex2f(i*0.05+0.05,0);
		glEnd();
		glFlush();
	     }
    }
}  

//Code for NRZ-I

void NRZ_I(int arr[])
{
     graph() ;
     int flag1=0;
     int flag2;
     for(int i=0;i<14;i++)
     {
        glColor3f( 1.0f, 0.0f, 0.0f);
        if(arr[i+1]==0 && i<=12)
          flag1=1;
        else
         flag1=0;
        if(i==0 )
        {
		if(arr[i]==1)
		{
		   glBegin(GL_LINE_STRIP);
		   glVertex2f(i*0.05,0);
		   glVertex2f(i*0.05,0.3);
		   glVertex2f(i*0.05+0.05, 0.3);
		   if(flag1!=1)
		   glVertex2f(i*0.05+0.05,0);
		   flag2=1;
		   glEnd();
		   glFlush();
		}
		else
		{
		   glBegin(GL_LINE_STRIP);
		   glVertex2f(i*0.05,0);
		   glVertex2f(i*0.05,-0.3);
		   glVertex2f(i*0.05+0.05, -0.3);
		   if(flag1!=1)
		   glVertex2f(i*0.05+0.05,0);
		   flag2=-1;
		   glEnd();
		   glFlush();
		}
        }
        else
        {
           if(arr[i]==1)
           {
              if(flag2==-1)
              {
              glBegin(GL_LINE_STRIP);
              glVertex2f(i*0.05,0);
              glVertex2f(i*0.05,0.3);
              glVertex2f(i*0.05+0.05,0.3);
              if(flag1!=1)
              glVertex2f(i*0.05+0.05,0);
              flag2=1;
              glEnd();
              glFlush();
              }
              else
              {
              glBegin(GL_LINE_STRIP);
              glVertex2f(i*0.05,0);
              glVertex2f(i*0.05,-0.3);
              glVertex2f(i*0.05+0.05, -0.3);
              if(flag1!=1)
              glVertex2f(i*0.05+0.05,0);
              flag2=-1;
              glEnd();
              glFlush();
              }
           }
           else
           {
             if(flag2==-1)
             {
              glBegin(GL_LINE_STRIP);
              glVertex2f(i*0.05,-0.3);
              glVertex2f(i*0.05+0.05,-0.3);
              if(flag1!=1)
              glVertex2f(i*0.05+0.05,0);
              flag2=-1;
              glEnd();
              glFlush();
             }
             else
             {
               glBegin(GL_LINE_STRIP);
               glVertex2f(i*0.05,0.3);
               glVertex2f(i*0.05+0.05,0.3);
               if(flag1!=1)
               glVertex2f(i*0.05+0.05,0);
               flag2=1;
               glEnd();
               glFlush();
             }
           }
        }
     }
} 


