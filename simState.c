#include <stdlib.h>
#include <stdio.h>
char g[8]={0,0,0,0,0,0,0,0};
char del[8]={0,0,0,0,0,0,0,0};
//define structure
	typedef struct state_machine{
		char name;
		struct state_machine *next0;
		struct state_machine *next1;
		int statenum;
	}state;

//function to determine garbage and print it
int garbage(state*current1)
	{
		state *next=current1;
		//int nextnum=next->statenum;
		next=next->next0;
		if (g[(next->name)-65]!=0)
		{
			garbage(next);
		}
		next=current1->next1;
		//nextnum=next->statenum;
		if(g[(next->name)-65]!=0)
		{
			garbage(next);
		}
		if(g[0]==0&&g[1]==0&&g[2]==0&&g[3]==0&&g[4]==0&&g[5]==0&&g[6]==0&&g[7]==0)
			{
				fprintf(stdout,"No Garbage\n");
				return 0;
			}
		else  {
			printf("garbage:\n");
			int i=0;
			for(i;i<sizeof(g);i++)
				{
				if(g[i]!=0){
						fprintf(stdout,"%c ",g[i]);
					    }
				} return 1;
			}
					
				
	}

void delete(state*current, char command[]){
			//initally all unreachable
			int k;
			for (k=0;k<sizeof(g);k++)
				{
					g[k]==65+k;
				} //in this case a letter indicates unreachable while 0 indicates reachable
			garbage(current);
			//find garbage of current
			//int x=garbage(current);
			//command is d and a state
 			if(command[1]>='A'&&command[1]<='H')
				{
					
					
						if(g[command[1]-65]==command[1]&&del[command[1]-65]!=command[1])
						{
							fprintf(stdout,"Deleted");
							del[command[1]-65]=command[1];
						}
					
					
						else 
							//if(g[command[1]-65]=!command[1]&&del[command[1]-65]!=command[1]&&g[dell]==command[1])
							
						{
							fprintf(stdout,"Not Deleted\n");
						}
					
				}
			else
				{
					//no garbage
					if(g[0]==del[0]&&g[1]==del[1]&&g[2]==del[2]&&g[3]==del[3]&&g[4]==del[4]&&g[5]==del[5]&&g[6]==del[6]&&g[7]==del[7])
					{
						fprintf(stdout,"No deleted states\n");
					}
					else {
						//garbage found
						fprintf(stdout,"Deleted");
						int dl=0;
						for(dl;dl<sizeof(g);dl++)
							{
							if(g[dl]!='0'&&del[dl]!=dl+65)
								{
								fprintf(stdout,"%c ",g[dl]);
								del[dl]=g[dl];
								}
							}	
						}
				}
	

			return;
}

	


int main(int argc, char * argv[])
{
	fprintf(stdout,"The beggining state is C\n");
	
	state machine[8]; 
	//Initalizing State Machine
	//Assigning State Names
		int i;
  		for(i=0;i<8;i++)
			{
				machine[i].name = 65+i;
    				machine[i].statenum=i;
			}
	//Setting starting state as C
	state *current;
	current=&machine[2];
	//garbage(&current);

	//State A's next states
	machine[0].next0=&machine[7];
	machine[0].next1=&machine[1];

	//State B's next states
	machine[1].next0=&machine[6];
	machine[1].next1=&machine[7];

	//State C's next states
	machine[2].next0=&machine[0];
	machine[2].next1=&machine[2];

	//State D's next states
	machine[3].next0=&machine[2];
	machine[3].next1=&machine[5];

	//State E's next states
	machine[4].next0=&machine[3];
	machine[4].next1=&machine[6];

	//State F's next states
	machine[5].next0=&machine[1];
	machine[5].next1=&machine[4];

	//State G's next states
	machine[6].next0=&machine[4];
	machine[6].next1=&machine[2];

	//State H's next states
	machine[7].next0=&machine[5];
	machine[7].next1=&machine[3];

	char command[3];
	int go=1;


	while(go==1)
{
	//Taking Commands
	printf("Please enter the command you wish to execute or enter q to quite the commands:\n");
	scanf("%c%c%c",&command[0],&command[1],&command[2]);
	if(command[0]=='0')
		{
			delete(current,command);
			if(del[current->next1->name]-65!=0)
			{
				fprintf(stdout,"%c\n",current->next0->name);
				current=&machine[current->next0->statenum];
			}
			else
				{
					fprintf(stdout,"this state no longer exsists");
				}
		}
	if(command[0]=='q')
		{
			fprintf(stdout,"goodbye\n");
			exit(0);
		}
	if(command[0]=='1')
		{
			delete(current,command);
			if(del[current->next1->name]-65!=0)
				{
					fprintf(stdout,"%c\n",current->next1->name);
					current=&machine[current->next1->statenum];
				}
			else
				{
					fprintf(stdout,"this state no longer exsists");
				}
			
		}
	if(command[0]=='c'&&command[1]=='0')
	{
			delete(current,command);
			if(del[command[2]-65]!='0')
		{
			int k;
			for(k=0;k<8;k++)
			{
				if(command[2]==(machine[k].name))
					{
						machine[current->statenum].next0=&machine[k];
					}
			}
		}
		else
		{
			fprintf(stdout,"This state no longer exsists");
		}
	}
			
	if(command[0]=='c'&&command[1]=='1')
	{

			delete(current,command);
			if(del[command[2]-65]!='0')
		{
			int q;
			for(q=0;q<8;q++)
			{
				if(command[2]==(machine[q].name))
					{
						machine[current->statenum].next1=&machine[q];
						

					}
					
				
			}
		}
		else
		{
			//fprintf(stdout,"This state no longer exsists");
		}
	}
	if(command[0]=='p')
		{
			delete(current,command);
			
			int j=0;
			for(j;j<8;j++)
				{
					if((del[j]-65)!='0')
					{
						fprintf(stdout,"%c %c %c\n",machine[j].name,machine[j].next0->name,machine[j].next1->name);
					}
					
					
				}
		}
	
	if(command[0]=='g')
		{	
			garbage(current);
				
		}
	if (command[0]=='d')
		{
			delete(current,command);
					
					
			
		}
	
	
		
		
	

	
    
}
exit(0);
}
