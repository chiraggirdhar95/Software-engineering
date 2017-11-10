#include<bits/stdc++.h>
#include<math.h>
using namespace std;

double mat[3][4]={{2.4, 1.05, 2.5, 0.38},{3.0, 1.12, 2.5, 0.35},{3.6, 1.20, 2.5, 0.32} };

int main()
{
    FILE *fp;
    int kloc = 0;  // Line counter (result)
    char filename[100];
    char c;  // To store a character read from file
    int k;
    // Get file name from user. The file should be
    // either in current folder or complete path should be provided
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            kloc = kloc + 1;

    // Close the file
    fclose(fp);
    printf("The file %s has %d lines\n ", filename, kloc);

    if(kloc>1 && kloc<51)
        k=0;
    else if(kloc>50 && kloc<301)
        k=1;
    else if(kloc>300)
        k=2;
    else
	{
	    cout<<"INVALID";
	    return 0;
    }

    double E=mat[k][0]*pow(kloc, mat[k][1]);
    double D=mat[k][2]*pow(E, mat[k][3]);

    cout<<"Effort Applied(E) = "<<E<<endl;
    cout<<"Development Time(D) = "<<D<<endl;
    cout<<"People Required(P) = "<< E/D<<endl;
    cout<<"Productivity = "<<kloc/E<<endl;
    return 0;
}
