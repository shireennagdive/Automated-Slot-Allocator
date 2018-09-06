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

void pref_sort(string prof_arr[],int prof_pref_arr[],string sub_arr[],string slot_pref_arr[],int no_pref){
	int i,j,pos=0,min,done=0;string temp;
	for(i=0;i<no_pref;i++){
		done=0;
		min=prof_pref_arr[i];
		for(j=i+1;j<no_pref;j++){
			if(prof_pref_arr[j]<min){
			  min=prof_pref_arr[j];
			  pos=j;done=1;
		   }
		}
		if(done==1){
		prof_pref_arr[pos]=prof_pref_arr[i];
		prof_pref_arr[i]=min;
		temp=prof_arr[i];
		prof_arr[i]=prof_arr[pos];
		prof_arr[pos]=temp;
		temp=sub_arr[i];
		sub_arr[i]=sub_arr[pos];
		sub_arr[pos]=temp;
		temp=slot_pref_arr[i];
		slot_pref_arr[i]=slot_pref_arr[pos];
		slot_pref_arr[pos]=temp;
	  }
	}
}

int find_prof_position(string prof_name){
	    int position=0,done=0,count=0;
	    string line;
        ifstream proffile;
        proffile.open("E:/About VNIT/Final Year Project/prof_name.txt");
        while(getline(proffile,line) && !done){
        	if(line.empty())
        	   continue;
        	if(line.compare(prof_name)!=0)
        	  count++;
        	else
        	   done=1;
        }
        
    return count+1;
}

int slot_count(int slot_no, string slots[], string slot_table[][5])
{
	int x=0, i , j;			//flexible value of x according to slot table.  //monika
			            for(i=0;i<5;i++)
			           {
    		          	for(j=0;j<5;j++)
				        {
					         if(slots[slot_no].compare(slot_table[i][j])==0)
					         x++;
					         
				        }
			           }
			           return x;
}
string check_OC(string pref_slot, string oc_subject)
{
        int stop = 1;
        string ocline ;
        ifstream ocfile;
        ocfile.open("E:/About VNIT/Final Year Project/oclist.txt");
    
        while (getline(ocfile,ocline) && stop == 1)
		{
						
				if(!ocline.empty())
				{
					if(pref_slot == ocline)
					{
						cout << "Prof preference can't be given for subject " << oc_subject << " and slot " << pref_slot << " because this slot is already alloted to OC" << endl;
						cout << "Enter any other slot or NO"<<endl;
						cin >> pref_slot;
						stop = 0;
					}
				}
		}
		
					
		if((stop==0) && (pref_slot != "NO"))
		pref_slot = check_OC(pref_slot, oc_subject);
					
		return pref_slot;
}
void check_preference(string slot_pref_arr[],int i,string subject, int year){
    		   int stop=1,j;
    		   string pref_slot;
    		   for(j=0;j<i && (stop==1);j++){
    		   	if(slot_pref_arr[j]==slot_pref_arr[i]){
    		   		cout << "Prof preference can't be given for subject " << subject << " and "<< slot_pref_arr[i] <<" because this slot is already asked by senoior professor" << endl ;
						cout << "Enter any other slot or NO"<<endl;
						cin >> pref_slot;
						stop=0;
						
    		   	   }
    		   }
    		   if(stop==0 && pref_slot !="NO")
			   {
                   slot_pref_arr[i]=pref_slot;
                 	if(year == 4)
                        pref_slot=check_OC(pref_slot,subject);
                   	
					 if(pref_slot!="NO")
                     {
                        slot_pref_arr[i]=pref_slot;
						check_preference(slot_pref_arr,i,subject,year);
					 }
                   else
                    {
                    	slot_pref_arr[i]="**";
                    }
                     
    		       
				}
				if(pref_slot=="NO" && stop==0 )
			   {
    		   	slot_pref_arr[i]="**";
    		   }
}
        		
int subject_number(int nos,string pref_sub,string subject[])
{
	for(int i=0;i<nos;i++)
	{
		if(subject[i]==pref_sub)   //error
		{
			return (i+1);
		}
	}
	cout << "Enter valid subject" << endl;
	return 0;
}

int slot_number(string pref_slot,string slots[])
{
	for(int i=0;i<8;i++)
	{
		if(slots[i] == pref_slot)
		{
			return (i+1);
		}
		
	}
	cout << "Enter valid slot" << endl;
	return 0;
}

int subject_no(int temp_year,int nos2,int nos3,int nos4,int nos5,int nos6,string temp_sub,string subject2[],string subject3[],string subject4[],string subject5[],string subject6[]){
		int i;
		if(temp_year==2){
			for(i=0;i<nos2;i++){
				if(temp_sub==subject2[i]){
					return i+1;
				}
			}
		}else if(temp_year==3){
			for(i=0;i<nos3;i++){
				if(temp_sub==subject3[i]){
					return i+1;
				}
			}
		}else if(temp_year==4){
			for(i=0;i<nos4;i++){
				if(temp_sub==subject4[i]){
					return i+1;
				}
			}
		}else if(temp_year==5){
			for(i=0;i<nos5;i++){
				if(temp_sub==subject5[i]){
					return i+1;
				}
			}
		}else if(temp_year==6){
			for(i=0;i<nos6;i++){
				if(temp_sub==subject6[i]){
					return i+1;
				}
			}
		}
	
}
void slot_position(int slot_arr[],string slot,string slot_table[][5])
{
	int k=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(slot_table[i][j]==slot)
			{
				slot_arr[k++]=(i+1)*10+(j+1);
			}
		}
	}
}

int function(int sub_year,int nos2,int nos3,int nos4,int nos5,int nos6,string subject2[],string subject3[],string subject4[],string subject5[],string subject6[],string temp_subject[]){
	int p,i, temp_nos;
	if(sub_year==2){
  	  for(p=0;p<nos2;p++){
  	  temp_subject[p]=subject2[p];
  	  }
  	  temp_nos=nos2;
    }
     else if(sub_year==3){
  		for(p=0;p<nos3;p++){
  		  temp_subject[p]=subject3[p];
  		  }
  		temp_nos=nos3;
  	}
  	else if (sub_year==4){
  	  for(p=0;p<nos4;p++){
  		temp_subject[p]=subject4[p];
  		}
  	  temp_nos=nos4;
  	}
  	else if (sub_year==5){
  	  for(p=0;p<nos5;p++){
  		temp_subject[p]=subject5[p];
  		}
  	  temp_nos=nos5;
  	}
  	else if (sub_year==6){
  	  for(p=0;p<nos6;p++){
  		temp_subject[p]=subject6[p];
  		}
  	  temp_nos=nos6;
  	}
  	return temp_nos;
}

int main() 
{	
	int numVars=1000,slot_table_no,sub_no; //CHANGE
	int nos,slot_no,i,k,j,s,l,count_de,count_dc, count_oc;
    vector< vector<int> > cnf;
    int nos2,nos3,nos4,nos5,nos6;
    vector<int> dnf; 
    string pref_sub,oc_slot,dc_slot[100];string pref_slot;int pref;
    int pref_subtable[5],lala[100];
    int year=2;int count_dc2,count_dc3;
    string subject[20], subject2[20],subject3[20],subject4[20],subject5[20],subject6[20];
    string dc_name[10],dc2[10],dc3[10];
    string de_name[10];
    string oc_name[10];
    int temp_nos,p;
    string temp_subject[20];
    stringstream stream;
    string line,filename,ocline ;
    ifstream infile;int slot_arr[4];
    string slots[8]={ "A","B","C","D","E","F","G","H"};
    
    string slot_table[5][5] = {{"C","A","B","H","G"},
	                           {"A","C","D","E","F"},
							   {"D","A","B","E","F"},
							   {"B","G","H","C","D"},
							   {"A","G","H","F","E"}};
     for (i = 0; i < 5; i++ ) //Printing Slot Table
	 {
      	for (j = 0; j < 5; j++ )
      	{
        	 cout << slot_table[i][j] << "  ";
      	}
      	cout << endl;
     }
     
    while(year < 7)
	{
    	cout <<" year is "<< year << endl ;
    	if(year==2 || year==3 || year==4)
    	  stream << "E:/About VNIT/Final Year Project/subject"  << year << ".txt";
    	else if(year==5 || year==6)
    	  stream << "E:/About VNIT/Final Year Project/mtech"  << year-4 << ".txt";
    	filename = stream.str();
		infile.open( filename.c_str() );
		stream.str("");
		i=0,k=0,j=0;
	
		if (infile.is_open())   //Reading DC and DE subjects from file
    	{
   			int flag=-1;
   			while ( getline (infile,line) )
    		{	
    
    			if(line.compare("DC")==0 )
    			{
    	   			flag=1; 
		   			continue;
				}
    	 		if( line.compare("DE")==0 )
    	 		{
    	     		flag=0;
			 		continue;   
		 		}
    	
		 		if( line.empty())
    	  		continue; 
       
        		if(flag==1)   //Reading DC subjects
				{
        	 		//strcpy(dc_name[i],line);
			 
				 	dc_name[i]=line;
        		 	cout << "dc    " << dc_name[i] << endl;
        	 		i++;
        	 		subject[k++]=line;
        		}
        		else if(flag==0)      //Reading DE subjects
				{
        			//strcpy(de_name[j],line);
        			de_name[j]=line;
        			cout  << "de    " << de_name[j] << endl;
					j++;
					subject[k++]=line;
        		}
    	
    		}
    	
    		count_dc=i;count_de=j;
    		infile.close();
   		}
 	
     	int dc_no[count_dc];
     	int de_no[count_de];
     	
	 	nos=count_dc+count_de;
	 
	 	for(i=0;i<count_dc;i++)
	 	{
    		dc_no[i]=subject_number(nos,dc_name[i],subject);
     	}	
    	 cout << "dc no" << endl;
	 
	 	for(i=0;i<count_dc;i++)
	 	{
    		cout << dc_no[i] << endl;
     	}
     
     	for(i=0;i<count_de;i++)
	 	{
    		de_no[i]=subject_number(nos,de_name[i],subject);
     	}	
     	cout << "de no" << endl;
	 
	 	for(i=0;i<count_de;i++)
	 	{
    		cout << de_no[i]<<endl;
    	}
     
	 
	 /* CONSTRAINT 01: *******************************prof preference code************************************/
	 string prof_arr[10],sub_arr[10],slot_pref_arr[10];int no_pref=0,prof_pref_arr[10];
	 int x;
     ifstream proffile, ocfile;
     if(year==2 || year==3 || year==4)
        stream << "E:/About VNIT/Final Year Project/prof_pref" << year << ".txt";
     else if(year==5 || year==6)
         stream << "E:/About VNIT/Final Year Project/prof_pref_mtech" << year-4 << ".txt";
     
	 filename = stream.str();
	 proffile.open( filename.c_str() );
	 stream.str("");
	 
	 ocfile.open("E:/About VNIT/Final Year Project/oclist.txt");
    	i=0;
    	while(getline(proffile,line))
		{
    		if(line.empty())
    		  continue;
    		prof_arr[i]=line;
    		prof_pref_arr[i]=find_prof_position(prof_arr[i]);
    		getline(proffile,line);
    		sub_arr[i]=line;
    		getline(proffile,line);
    		slot_pref_arr[i]=line;
    		i++;
    		no_pref++;
    	
		}
    	if(no_pref!=1)
    	    pref_sort(prof_arr,prof_pref_arr,sub_arr,slot_pref_arr,no_pref);
    	for(i=0;i<no_pref;i++)
		{
    		cout << prof_arr[i] << "  " << prof_pref_arr[i] << "  " << sub_arr[i] << "  " << slot_pref_arr[i] << endl;
    	}
    	
    	if(year==4)
		{
    		for(i=0;i<no_pref;i++)
			{
    		   pref_slot = check_OC(slot_pref_arr[i],sub_arr[i]);
    		   if(pref_slot=="NO")
			   {
    		   	slot_pref_arr[i]="**";
    		   }
    		   else
    		     slot_pref_arr[i]=pref_slot;
    		     
    	       check_preference(slot_pref_arr,i,sub_arr[i], year);
    		}
    	}
    	else
    	{
    		for(i=0;i<no_pref;i++)
    	        check_preference(slot_pref_arr,i,sub_arr[i], year);
    	}
    	for(i=0;i<no_pref;i++){
    		cout << prof_arr[i] << "  " << prof_pref_arr[i] << "  " << sub_arr[i] << "  " << slot_pref_arr[i] << endl;
    	}	
    	
    	//AB CONSTAINT GENERATION....
    	
    	for(i=0;i<no_pref;i++)
    	{
    		slot_position(slot_arr,slot_pref_arr[i],slot_table);
    		slot_no = slot_number(slot_pref_arr[i],slots);    		
    		x = slot_count(slot_no-1,slots, slot_table);
    		sub_no= subject_number(nos,sub_arr[i],subject);
    		
    		for(j =0; j<x; j++)
    		{
    					s = year*10000+slot_arr[j]*100+slot_no*10+sub_no;
    					dnf.push_back(s);
    					cnf.push_back(dnf);
    					dnf.clear();
    		}
    	}
    /*CONSTRAINT 02: ********************************** DC should not overlap *****************************************/
   
		for(i=1;i<=5;i++)
		{
    		for(int j=1;j<=5;j++)
			{
    			slot_table_no=slot_number(slot_table[i-1][j-1],slots);
    		 				
				for(int l=0;l<count_dc;l++)
				{
    		 		sub_no=dc_no[l];
			 		for(int k=l+1;k<count_dc;k++)
			 		{ 
    		   			dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+sub_no));
               			dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+dc_no[k]));
               			cnf.push_back(dnf);
               			dnf.clear();
           	 		}
		   		}	
	  	  	}
    	}

	/*CONSTRAINT 03: ******************************** Each subject can be in any slot. **************************************/
	
		
		for(i=1;i<=nos;i++)
		{
			for(j=0;j<8;j++)
			{
				slot_position(slot_arr,slots[j],slot_table);
				dnf.push_back(year*10000+(slot_arr[0]*100+(j+1)*10+i));
			}
			cnf.push_back(dnf);
			dnf.clear();
		}
	
	
	/*CONSTRAINT 04: ********************************* For checking if same slot has same subject. ******************************/
	 
		for(l=0;l<8;l++)  //value of x is hardcoded 
		{
			//x=3;
			//if(l==0)
			//x=4;
		
			slot_no=l+1;
		 
	
	        x= slot_count(l, slots, slot_table);
	//	cout<<" x is : \n"<<x;
	  		for(i=1;i<=nos;i++)
	  		{		
	    		slot_position(slot_arr,slots[l],slot_table);   //fucntion call to return the position of slot
	    	
				for(j=0;j<x;j++)
				{
					for(k=0;k<x;k++)
					{	
						if(k!=j)				//A->B i.e. (~A OR B)
						{	
							dnf.push_back(-(year*10000+slot_arr[j]*100+slot_no*10+i));
							dnf.push_back(year*10000+slot_arr[k]*100+slot_no*10+i);
							cnf.push_back(dnf);
							dnf.clear();
			   			}
					}
				}	
	 		}
   		}
   
   /*CONSTRAINT 05: ******************************** Two slots cannot have same subject*********************************/
   
   		int slot_arr1[4],slot_arr2[4];
   		for(i=1;i<=nos;i++)
   		{
   			for(j=0;j<8;j++)
	   		{
   				slot_position(slot_arr1,slots[j],slot_table);
   				for(k=j+1;k<8;k++)
		   		{
   					slot_position(slot_arr2,slots[k],slot_table);
   					dnf.push_back(-(year*10000+slot_arr1[0]*100+(j+1)*10+i));
					dnf.push_back(-(year*10000+slot_arr2[0]*100+(k+1)*10+i));
			    	cnf.push_back(dnf);
					dnf.clear();
   		   		}
	   		}
   		}
   
   /* CONSTRAINT 06: ***************************DE should not overlap with DC *********************************/
   
   		for(i=1;i<=5;i++)  //each subject can be in any slot
   		{
			for(j=1;j<=5;j++)
			{
				slot_table_no=slot_number(slot_table[i-1][j-1],slots);
			
				for(k=0;k<count_de;k++)
				{		
					for(l=0;l<count_dc;l++)
					{	
						dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+de_no[k]));
						dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+dc_no[l]));
						cnf.push_back(dnf);
                    	dnf.clear();
					}	
				}
				
			}
   		}
	
	/* CONSTRAINT 07: ***************************DE should overlap with DE only when Nos > no. of slots *********************************/
   
		if(nos <= 8)
		{
			for(i=1;i<=5;i++)
			{
    			for(int j=1;j<=5;j++)
				{
    				slot_table_no=slot_number(slot_table[i-1][j-1],slots);
    		 				
					for(int l=0;l<count_de;l++)
					{
    		 			sub_no=de_no[l];
			 			for(int k=l+1;k<count_de;k++)
			 			{ 
    		   				dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+sub_no));
               				dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+de_no[k]));
               				cnf.push_back(dnf);
               				dnf.clear();	 
           	 			}
		   			}
	    		}
    		}
		}
		else         //DE should overlap with De only.
		{
			int extra_de = nos - 8;
			int non_overlapped_de = count_de - extra_de;
			
			for(i=1;i<=5;i++)
			{
    			for(int j=1;j<=5;j++)
				{
    				slot_table_no=slot_number(slot_table[i-1][j-1],slots);
    		 				
					for(int l=0;l<non_overlapped_de;l++)
					{
    		 			sub_no=de_no[l];
			 			for(int k=l+1;k<non_overlapped_de;k++)
			 			{ 
    		   				dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+sub_no));
               				dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+de_no[k]));
               				cnf.push_back(dnf);
               				dnf.clear();	 
           	 			}
		   			}
	    		}
    		}
		}	
	
    /* CONSTRAINT 08 : ***************************** OC for final year ********************************/
    
    	if (year==4)
		{
    		ifstream ocfile;
    		count_oc = 0;
    		ocfile.open("E:/About VNIT/Final Year Project/oclist.txt");
    	
			while (getline(ocfile,line))
			{
				if(!line.empty())
				{
					int l=nos;
					pref_sub=line;
					
					oc_name[count_oc]=line;
        		 	cout << "oc    " << oc_name[count_oc] << endl;
        	 		count_oc++;
        	 		
					subject[nos++]=pref_sub;
					getline(ocfile,line);
        			pref_slot=line;
    				k=0;
    		
					for(i=0;i<=4;i++)
					{
    					for(j=0;j<=4;j++)
						{
    						if(pref_slot==slot_table[i][j])
    		  				pref_subtable[k++]=(i+1)*10+(j+1);
    					}
    				}
    	
					for(i=0;i<k;i++)
					{
    	    			s=(year*10000)+(pref_subtable[i]*100)+((slot_number(pref_slot,slots))*10)+(l+1);
    					dnf.push_back(s);
    					cnf.push_back(dnf);
    					dnf.clear();
    				}
     			}
    		}	
  		}
  		
  		
  		
  	/* CONSTRAINT 09 : ***************************** OC Over DE ********************************/
  	
    	
    	if(year == 4)
    	{    	
			int oc_no[count_oc];
     	
	 	//nos=count_dc+count_de;
	 
	 		for(i=0;i<count_oc;i++)
	 		{
    			oc_no[i]=subject_number(nos,oc_name[i],subject);
     		}	
    	 	cout << "oc no" << endl;
	 
	 		for(i=0;i<count_oc;i++)
	 		{
    			cout << oc_no[i] << endl;
     		}
     
			for(i=1;i<=5;i++)  //each subject can be in any slot
   			{
				for(j=1;j<=5;j++)
				{
					slot_table_no=slot_number(slot_table[i-1][j-1],slots);
			
					for(k=0;k<count_de;k++)
					{		
						for(l=0;l<count_oc;l++)
						{	
							dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+de_no[k]));
							dnf.push_back(-(year*10000+i*1000+j*100+slot_table_no*10+oc_no[l]));
							cnf.push_back(dnf);
                    		dnf.clear();
						}	
					}
				
				}
   			}	
  		}	
  		if(year==2){
  			for(i=0;i<nos;i++){
  				subject2[i]=subject[i];
  				
  			}
  			nos2=nos;
  			for(i=0;i<count_dc;i++){
  				dc2[i]=dc_name[i];
  			}
  			count_dc2=count_dc;
  		}
  		else if(year==3){
  				for(i=0;i<nos;i++){
  				subject3[i]=subject[i];
  			}
  			nos3=nos;
  			for(i=0;i<count_dc;i++){
  				dc3[i]=dc_name[i];
  			}
  			count_dc3=count_dc;
  		}
  		else if (year==4){
  		 	for(i=0;i<nos;i++){
  				subject4[i]=subject[i];
  			}
  			nos4=nos;
  		}
  		else if (year==5){
  		 	for(i=0;i<nos;i++){
  				subject5[i]=subject[i];
  			}
  			nos5=nos;
  		}
  		else if (year==6){
  		 	for(i=0;i<nos;i++){
  				subject6[i]=subject[i];
  			}
  			nos6=nos;
  		}
  		year++;
  		
	} // End of loop for all years
	
    /*
    ***************** consecutive slots for a professor************************
    */
    
	ifstream sublist;string sub[5];
	int  sub_year[5];
	ifstream prof_name;int temp;
     int list_size=0, flag = 0;k=0;
      sublist.open("E:/About VNIT/Final Year Project/prof_subjectlist.txt");
     	while (getline(sublist,line))
			{
				cout << line << endl;
				if( line.empty())
    	  		continue; 
    	  		
				if(line=="**"){
					getline(sublist,line);
					cout << line << endl;
					getline(sublist,line);
					cout << line << endl;
					list_size =atoi(line.c_str());
					temp=list_size;
					getline(sublist,line);
					cout << line << endl;
			    }
			if(temp!=1)
			{
				 if(list_size)
				 {
				  sub[k]=line;
				  //cout <<"sub  " << sub[k] <<endl;
				  getline(sublist,line);
				  cout << line << endl;
				  sub_year[k]=atoi(line.c_str());
				  
				  //cout <<"sub year " << sub_year[k] <<endl;
				  k++;
				  list_size--;
				 }
				 if(list_size==0){
				 	//check consecutive method
				 	int sub_nos=k;
				 	for(i=0;i<sub_nos;i++){
				 		for(j=i+1;j<sub_nos;j++){
				 			for(int m=1;m <=5;m++){
				 				for(l=1;l<=5;l++){
				 					temp_nos=function(sub_year[i],nos2,nos3,nos4,nos5,nos6,subject2,subject3,subject4,subject5,subject6,temp_subject);
				 					slot_no=slot_number(slot_table[m-1][l-1], slots);
				 					sub_no=subject_number(temp_nos,sub[i],temp_subject);
				 					s=(sub_year[i])*10000+(m*1000)+(l*100)+(slot_no *10)+sub_no;
				 					//cout << s <<endl;
				 					dnf.push_back(-s);
				 					temp_nos=function(sub_year[j],nos2,nos3,nos4,nos5,nos6,subject2,subject3,subject4,subject5,subject6,temp_subject);
				 					slot_no=slot_number(slot_table[m-1][l-1], slots);
				 					sub_no=subject_number(temp_nos,sub[j],temp_subject);  //error
				 					s=(sub_year[j])*10000+(m*1000)+(l*100)+(slot_no *10)+sub_no;
				 					//cout << s <<endl;
				 					dnf.push_back(-s);
    					            cnf.push_back(dnf);
    					            dnf.clear();
    					            if(l!=5){
    					            temp_nos=function(sub_year[i],nos2,nos3,nos4,nos5,nos6,subject2,subject3,subject4,subject5,subject6,temp_subject);
				 					slot_no=slot_number(slot_table[m-1][l-1], slots);
				 					sub_no=subject_number(temp_nos,sub[i],temp_subject);
				 					s=sub_year[i]*10000+(m*1000)+(l*100)+(slot_no *10)+sub_no;
				 					//cout << s <<endl;
				 					dnf.push_back(-s);
				 					
				 					temp_nos=function(sub_year[j],nos2,nos3,nos4,nos5,nos6,subject2,subject3,subject4,subject5,subject6,temp_subject);
				 					slot_no=slot_number(slot_table[m-1][l], slots);
				 					sub_no=subject_number(temp_nos,sub[j],temp_subject);
				 					s=sub_year[j]*10000+((m)*1000)+((l+1)*100)+(slot_no *10)+sub_no;
				 					//cout << s <<endl;
				 					dnf.push_back(-s);
    					            cnf.push_back(dnf);
    					            dnf.clear();
    					            }
    					            if(l!=1)
    					            {
    					            	temp_nos=function(sub_year[i],nos2,nos3,nos4,nos5,nos6,subject2,subject3,subject4,subject5,subject6,temp_subject);
				 						slot_no=slot_number(slot_table[m-1][l-1], slots);
				 						sub_no=subject_number(temp_nos,sub[i],temp_subject);
				 						s=(sub_year[i])*10000+(m*1000)+(l*100)+(slot_no *10)+sub_no;
				 					//	cout << s <<endl;
				 						dnf.push_back(-s);
				 						
				 						temp_nos=function(sub_year[j],nos2,nos3,nos4,nos5,nos6,subject2,subject3,subject4,subject5,subject6,temp_subject);
				 						slot_no=slot_number(slot_table[m-1][l-2], slots);
				 						sub_no=subject_number(temp_nos,sub[j],temp_subject);
				 						s=sub_year[j]*10000+((m)*1000)+((l-1)*100)+(slot_no *10)+sub_no;
				 					//	cout << s <<endl;
				 						dnf.push_back(-s);
    					            	cnf.push_back(dnf);
    					            	dnf.clear();
    					            }
    					        }
				 			}
				 		}
				 	}
					k=0;
					int size = sizeof(sub);
					for(i =0; i< 5; i++)
			  		{
			  			sub[i]='\0';
			  		}
			  		size = sizeof(sub_year);
			  		for(i =0; i< 5; i++)
			  		{
			  		    sub_year[i]='\0';
			  		}
				 }
				 
			  }
			  
			  
			}
			sublist.close();
			
			/*
    ***************** backlog conditions ************************
    */
    	
        list_size=0;int slot_arr1[4];
        int temp_list_size=0,x;string back_sub[10];
		ifstream backlog_list;
        backlog_list.open("E:/About VNIT/Final Year Project/backlog_sub.txt");
     	while (getline(backlog_list,line))
			{
				if(line.empty())
				  continue;
				list_size =atoi(line.c_str());
				temp_list_size=list_size;
				while(list_size){
					getline(backlog_list,line);
					back_sub[k++]=line;
					list_size--;
				}
				if(list_size==0){
					
					 for(i=0;i<8;i++){
						x = slot_count(i,slots, slot_table);
						slot_position(slot_arr1,slots[i],slot_table);
						for(j=0;j<temp_list_size;j++){
							for(k=0;k<count_dc3;k++){
								for(l=0;l<x;l++){
									s=(2*10000)+slot_arr1[l]*100+(i+1)*10+subject_number(nos2,back_sub[j],subject2);
									dnf.push_back(-s);
    					            s=(3*10000)+slot_arr1[l]*100+(i+1)*10+subject_number(nos3,dc3[k],subject3);
    					            dnf.push_back(-s);
									cnf.push_back(dnf);
    					            dnf.clear();
								}
							}
						}
					}
				 
				}
			}
			
	/*
    ***************** first year subject like CP************************
    *
			
    ifstream cp_prof_list, prof_subjectlist;
	string professor_name, cp_slot,temp_sub;
	int cp_slot_no,temp_year;
    cp_prof_list.open("E:/About VNIT/Final Year Project/CP_Prof_List.txt");
 	while (getline(cp_prof_list,line))
 	{
 		if(line.empty())
          continue;
 		professor_name=line;
 		getline(cp_prof_list,line);
 		cp_slot=line;
 		cp_slot_no=slot_number(cp_slot,slots);
 	
 		x = slot_count(cp_slot_no-1, slots, slot_table);
	    
 		slot_position(slot_arr,cp_slot,slot_table);
 		
 	    prof_subjectlist.open("E:/About VNIT/Final Year Project/prof_subjectlist.txt");
 		int done=0;
 		while (getline(prof_subjectlist,line) && done==0)
    		{
    			if(line.empty()  && line.compare("**")==0)
                  continue;
                if(line.compare(professor_name)==0){
                	done=1;
                	getline(prof_subjectlist,line);
                	list_size=atoi(line.c_str());
                	while(list_size){
                		
                		getline(prof_subjectlist,line);
                		if(line.empty())
                             continue;
                		temp_sub=line;
                		getline(prof_subjectlist,line);
                		temp_year=atoi(line.c_str());
                		sub_no=subject_no(temp_year,nos2,nos3,nos4,nos5,nos6,temp_sub,subject2,subject3,subject4,subject5,subject6);
                		for(i=0;i<x;i++){
                			dnf.push_back(-(temp_year*10000+slot_arr[i]*100+cp_slot_no*10+sub_no));
                			cnf.push_back(dnf);
                			dnf.clear();
                		}
                		
                		list_size--;
                	}
                }
    		}
			if(done==1)
			   prof_subjectlist.close();
 		
    }  
    cp_prof_list.close();
    */
    /****************** CP In consecutive slot *********************************/
   /* 
    
    cp_prof_list.open("E:/About VNIT/Final Year Project/CP_Prof_List.txt");
 	while (getline(cp_prof_list,line))
 	{
 		if(line.empty())
          continue;
 		professor_name=line;
 		getline(cp_prof_list,line);
 		cp_slot=line;
 		cp_slot_no=slot_number(cp_slot,slots);
 	
 		x = slot_count(cp_slot_no-1, slots, slot_table);
	    
 		slot_position(slot_arr,cp_slot,slot_table);
 		
 		prof_subjectlist.open("E:/About VNIT/Final Year Project/prof_subjectlist.txt");
 		int done=0,col,row;
 		while (getline(prof_subjectlist,line) && done==0)
    		{
    			if(line.empty()  && line.compare("**")==0)
                  continue;
                if(line.compare(professor_name)==0){
                	done=1;
                	getline(prof_subjectlist,line);
                	list_size=atoi(line.c_str());
                	while(list_size){
                		
                		getline(prof_subjectlist,line);
                		if(line.empty())
                             continue;
                		temp_sub=line;
                		getline(prof_subjectlist,line);
                		temp_year=atoi(line.c_str());
                		sub_no=subject_no(temp_year,nos2,nos3,nos4,nos5,nos6,temp_sub,subject2,subject3,subject4,subject5,subject6);
        		
        				for(i=0;i<x;i++)
        				{
        					col = slot_arr[i] % 10;
        					row=slot_arr[i]/10;
        					if(col == 1)
        					{
        						slot_no=slot_number(slot_table[row-1][1],slots);
								dnf.push_back(-(temp_year*10000+(slot_arr[i]+1)*100+slot_no*10+sub_no));
                				cnf.push_back(dnf);
                				dnf.clear();                		
        					}
        					else if(col == 5)
        					{
        						slot_no=slot_number(slot_table[row-1][3],slots);
								dnf.push_back(-(temp_year*10000+(slot_arr[i]-1)*100+slot_no*10+sub_no));
                				cnf.push_back(dnf);
                				dnf.clear();   
        					}
        					else
        					{
        						slot_no=slot_number(slot_table[row-1][col],slots);
								dnf.push_back(-(temp_year*10000+(slot_arr[i]+1)*100+slot_no*10+sub_no));
                				cnf.push_back(dnf);
                				dnf.clear();   
                				slot_no=slot_number(slot_table[row-1][col-2],slots);
								dnf.push_back(-(temp_year*10000+(slot_arr[i]-1)*100+slot_no*10+sub_no));
                				cnf.push_back(dnf);
                				dnf.clear();   
        					}
        				}
					 list_size--;   
					}
				}
		   }
		   if(done==1)
			 prof_subjectlist.close();
	}
	*/
	 /*
     ***************** mtech btech same subjects constraint ************************
    */
    
			ifstream mixfile;
			
    		mixfile.open("E:/About VNIT/Final Year Project/mix_file.txt");
    	
			int mix_year[10],total_sub,total_year,row,col;
			string mix_sub[10];
			i=0;
			while (getline(mixfile,line))
			{
			
				if(!line.empty())
				{
					mix_sub[i]=line;
		//			cout<<line;
					getline(mixfile,line);
					mix_year[i]=atoi(line.c_str());
					cout<<mix_year[i] << endl;
					i++;
				}
				
			}
			
			total_sub=i; 		//2 sub
			total_year=i;       //2
			k=0;
	
			for(i=0;i<total_sub;i++)
			{
					for(row=0;row<5;row++){
						for(col=0;col<5;col++){		
    						//~x union y
							sub_no=subject_no(mix_year[i],nos2,nos3,nos4,nos5,nos6,mix_sub[i],subject2,subject3,subject4,subject5,subject6);
    						slot_no=slot_number(slot_table[row][col],slots);
							s = mix_year[i]*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(-s);
    						sub_no=subject_no(4,nos2,nos3,nos4,nos5,nos6,mix_sub[i],subject2,subject3,subject4,subject5,subject6);
    						s = 4*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(s);
							cnf.push_back(dnf);
    						dnf.clear();
    						
    						//x union ~y
    						sub_no=subject_no(mix_year[i],nos2,nos3,nos4,nos5,nos6,mix_sub[i],subject2,subject3,subject4,subject5,subject6);
    						slot_no=slot_number(slot_table[row][col], slots);
							s = mix_year[i]*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(s);
    						sub_no=subject_no(4,nos2,nos3,nos4,nos5,nos6,mix_sub[i],subject2,subject3,subject4,subject5,subject6);
    						s = 4*10000+(row+1)*1000+(col+1)*100+slot_no*10+sub_no;
    						dnf.push_back(-s);
							cnf.push_back(dnf);
    						dnf.clear();
    				}
    					
						}
					
	
			}
	
	/*
    ***************** Writing constraints to the example.txt i.e. the input file to MiniSAT ************************
    */
    
	ofstream fout;
    fout.open ("C:/cygwin/bin/example.txt");
    fout << "p cnf " << numVars << " " << cnf.size() << endl;
    
	for (int i=0; i<cnf.size(); i++)
	{	
       for (int j=0; j<cnf[i].size(); j++)
	   {
        fout << cnf[i][j] << " ";
       }
       fout << " 0" << endl;  
    }

} /********End Of -Main FUnction*********/
