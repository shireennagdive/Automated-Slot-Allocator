#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
			ifstream mixfile;
			
    		mixfile.open("C:/Users/Shireen/Desktop/mix_file.txt");
    	
			int i=0,k=0,j,mix_year[10];
			string mix_sub[10],line;
			while (getline(mixfile,line))
			{
			
				if(!line.empty())
				{
					mix_sub[i]=line;
					cout<<line;
					getline(mixfile,line);
					mix_year[i]=atoi(line.c_str());
					cout<<mix_year[i];
					i++;
				}
				
			}
			
			total_sub=i; //2 sub
			total_year=i;       //2
			k=0;
	
		
			for(i=0;i<total_sub;i++){
					for(row=0;row<5;row++){
						for(col=0;col<5;col++){		
    						//sub_no=subject_number(mix_year[k],mix_sub[i],subject);
    						sub_no=subject_no(mix_year[i],nos2,nos3,nos4,nos5,nos6,temp_sub,subject2,subject3,subject4,subject5,subject6);
    						slot_no=slot_number(slot_table[row][col], slots);
							s = mix_year[i]*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(-s);
    						sub_no=subject_no(4,nos2,nos3,nos4,nos5,nos6,temp_sub,subject2,subject3,subject4,subject5,subject6);
    						s = 4*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(s);
							cnf.push_back(dnf);
    						dnf.clear();
    						
    						sub_no=subject_no(mix_year[i],nos2,nos3,nos4,nos5,nos6,temp_sub,subject2,subject3,subject4,subject5,subject6);
    						slot_no=slot_number(slot_table[row][col], slots);
							s = mix_year[i]*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(s);
    						sub_no=subject_no(4,nos2,nos3,nos4,nos5,nos6,temp_sub,subject2,subject3,subject4,subject5,subject6);
    						s = 4*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(-s);
							cnf.push_back(dnf);
    						dnf.clear();
    				}
    					
						}
					}
				
			}
			
		}
