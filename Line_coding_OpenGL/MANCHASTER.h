void manch(int arr[])
{
    graph() ;

    for(int i=0 ; i< 14 ; i++)
    {
    if(arr[i] == arr[i-1] && i>0)
    {
        glBegin(GL_LINES);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,0.3);
        glVertex2f(i*0.05,-0.3);
        glEnd();
    }

    if(arr[i]==0)
    {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,0.3);
        glVertex2f(i*0.05+0.025,0.3);
        glVertex2f(i*0.05+0.025,-0.3);
        glVertex2f(i*0.05+0.05,-0.3);
        glEnd();
        glFlush();
     }
    else
    {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,-0.3);
        glVertex2f(i*0.05+0.025,-0.3);
        glVertex2f(i*0.05+0.025,0.3);
        glVertex2f(i*0.05+0.05 ,0.3);
        glEnd();
        glFlush();
     }
    }
}  


//FOR DIFFERENTIAL MANCHASTER

void z(int i)
{
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,0.3);
        glVertex2f(i*0.05+0.025,0.3);
        glVertex2f(i*0.05+0.025, -0.3);
        glVertex2f(i*0.05+0.05 , -0.3);
        glEnd();
        glFlush();
}

void s(int i)
{
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 0.0f, 0.0f);
        glVertex2f(i*0.05,-0.3);
        glVertex2f(i*0.05+0.025,-0.3);
        glVertex2f(i*0.05+0.025,0.3);
        glVertex2f(i*0.05+0.05,0.3);
        glEnd();
        glFlush();

}

void diff_manch(int arr[])
{
    graph() ;
    int last = 0 ;
    for(int i=0 ; i< 14 ; i++)
    {
	    if(i == 0 )
	    {
	      if(arr[i]==0)
	       {
	       z(i) ;
	       }
	      else
	       {
	       s(i);
	       last = 1 ;
	       }
	    }

    else
    {
    if(last==1)
    {
	    if(arr[i]==0)
	       {
		glBegin(GL_LINES);
		glColor3f( 1.0f, 0.0f, 0.0f);
		glVertex2f(i*0.05,0.3);
		glVertex2f(i*0.05,-0.3);
		glEnd();
		s(i) ;
		last = 1;
	       }
	    else
	       {
		z(i) ;
		last = 0;
	       }
    }
    else
    {
	     if(arr[i]==1)
	       {
	       s(i) ;
	       last = 1;
	       }
	    else
	      {
		glBegin(GL_LINES);
		glColor3f( 1.0f, 0.0f, 0.0f);
		glVertex2f(i*0.05,0.3);
		glVertex2f(i*0.05,-0.3);
		glEnd();
		z(i) ;
		last = 0;
      }
    }
  }
 }
} 



