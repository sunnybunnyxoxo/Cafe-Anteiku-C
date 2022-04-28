#include <stdio.h>
#include <stdlib.h>
void intro();
void customerChoices();
void menu();
void menuChoice();
void orderAgain();
void viewOrder();
void serve();
void adminLogin();
void incorrectLogin();
void adminChoices();
void viewStock();
void restockItems();
int stock[8] = {50,50,50,50,50,50,50,50};
int orderCount = 0;
char name[12];
int totalCost = 0;
FILE *fptr;
FILE *allfptr;
int orderStart = 0;

int main()
{
	int choice;
	
	intro();
	scanf("%d", &choice);
	
	
	switch(choice){
		case 1:
				customerChoices();
				break;
		case 2:
				adminLogin();
				break;
		case 3:
				printf("Thank you for your time. Goodbye.");
				exit(0);
				break;
		default:
				printf("Please enter a number between 1-3");
				intro();
				break;
	}
	return 0;
}

void intro(){
	printf("\n\n*******************************************************************\n");
	printf("===================================================================");
	printf("\n			WELCOME TO CAFE ANTEIKU\n");
	printf("===================================================================");
	printf("\n*******************************************************************\n");
	printf("1.Customer Panel.\n");
	printf("2.Admin panel.\n");
	printf("3.Exit.\n");
	printf("Please Pick a Choice: ");
}

void customerChoices(){
	int choice;
	
	printf("\n1.Place Order.");
	printf("\n2.View Order.");
	printf("\n3.Serve Order.");
	printf("\n4.Go back to main menu.");
	printf("\n\nPick a choice: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
				if(orderCount > 0){
					printf("\nPlease serve existing order first.");
					customerChoices();
				}
				printf("\nPlease enter Customer name:");
				scanf("%s", name);
				fptr = fopen("currentOrder.txt","w");
				fclose(fptr);
				menu();
				menuChoice();
				break;
		case 2:
				if(orderCount == 0){
					printf("\nPlease Place an Order First\n");
					customerChoices();
				}else{
					viewOrder();
				}
				break;
		case 3:
				if(orderCount == 0){
					printf("\nPlease Place an Order First\n");
					customerChoices();
				}
				printf("\nYour order has been served!");
				printf("\nWhat would you like to do next?");
				serve();
		case 4:
				main();
				break;
		default:
				printf("\nPlease enter a number between 1-4");
				customerChoices();
				break;
	}
}

void menu(){
	printf("_________________________________________________________________________\n");
	printf("|	Item No.	|	Item Name	|	Price		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	01		|	Americano	|	Rs. 350		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	02		|	Latte		|	Rs. 400		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	03		|	Mocha		|	Rs. 450		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	04		|	Irish		|	Rs. 500		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	05		| 	Cookie		|	Rs. 250		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	06		|	Brownie		|	Rs. 250		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	07		|	Choco Cake	|	Rs. 600		|\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|	08		|	Cheescake	|	Rs. 650		|\n");
	printf("_________________________________________________________________________\n");
}

void menuChoice(){
	int choice, quantity, totalItemCost;
	
	printf("\nPlease pick your choice of Item: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
				printf("\nEnter Number of Americanos to Order: ");
				scanf("%d",&quantity);
				stock[0] = stock[0] - quantity;
				totalItemCost = 350*quantity;
				totalCost = totalCost + (quantity*350);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Americano\t   %d\t\t  Rs.350\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();	
				break;					
		case 2:
				printf("\nEnter Number of Lattes to Order: ");
				scanf("%d", &quantity);
				stock[1] = stock[1] - quantity;
				totalItemCost = 400*quantity;
				totalCost = totalCost + (quantity*400);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Latte\t   %d\t\t  Rs.400\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		case 3:
				printf("\nEnter Number of Mocchas to order: ");
				scanf("%d",&quantity);
				stock[2] = stock[2] - quantity;
				totalItemCost = 450*quantity;
				totalCost = totalCost + (quantity*450);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Mocchas\t   %d\t\t  Rs.450\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		case 4:
				printf("\nEnter Number of Irish's to Order: ");
				scanf("%d", &quantity);
				stock[3] = stock[3] - quantity;
				totalItemCost = 500*quantity;
				totalCost = totalCost + (quantity*500);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Irish\t   %d\t\t  Rs.500\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		case 5:
				printf("\nEnter Number of Cookies to Order: ");
				scanf("%d", &quantity);
				stock[4] = stock[4] - quantity;
				totalItemCost = 250*quantity;
				totalCost = totalCost + (quantity*250);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Cookie\t   %d\t\t  Rs.250\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		case 6:
				printf("\nEnter Number of Brownies to Order: ");
				scanf("%d", &quantity);
				stock[5] = stock[5] - quantity;
				totalItemCost = 250*quantity;
				totalCost = totalCost + (quantity*250);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Brownie\t   %d\t\t  Rs.250\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		case 7:
				printf("\nEnter Number of Chocolate Cakes to Order: ");
				scanf("%d", &quantity);
				stock[6] = stock[6] - quantity;
				totalItemCost = 600*quantity;
				totalCost = totalCost + (quantity*600);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Chocolate Cake\t   %d\t\t  Rs.600\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		case 8:
				printf("\nEnter Number of Cheesecakes to Order: ");
				scanf("%d", &quantity);
				stock[7] = stock[7] - quantity;
				totalItemCost = 650*quantity;
				totalCost = totalCost + (quantity*650);
				orderCount++;
				fptr = fopen("currentOrder.txt", "a");
				fprintf(fptr,"\n%d. Cheesecake\t   %d\t\t  Rs.650\t    Rs.%d",orderCount,quantity,totalItemCost);
				fclose(fptr);
				orderAgain();
				break;
		default:
				printf("\nPlease enter a valid number");
				menuChoice();
				break;
		}
}

void orderAgain(){
	int choice;
	char c;
	printf("\nYour Item has been added!\nWould you like to order another item?\n1.Yes\n2.No\nEnter choice: ");
				scanf("%d", &choice);
				switch(choice){
					case 1: 
							menuChoice();
							break;
					case 2:
							fptr = fopen("currentOrder.txt","r");
							allfptr = fopen("allOrders.txt","a");
							c = fgetc(fptr);
							while(c != EOF){
								fputc(c,allfptr);
								c = fgetc(fptr);
							}					
							fclose(fptr);
							fclose(allfptr);
							printf("\nThank you for your Order!\n");
							customerChoices();
							break;
					default:
							printf("\nPlease enter a number, 1 or 2.");
							orderAgain();
							break;	
				}
}


void viewOrder(){
	char c;
	int choice;
	
	printf("\n***************************************************************");
	printf("\n\t\t\tRECIEPT");
	printf("\n---------------------------------------------------------------");
	printf("\nCustomer Name: %s\n",name);
	printf("\nItem Name\tQuantity\tItem Cost\tTotal Item Cost");
	fptr = fopen("currentOrder.txt","r");
	while((c = getc(fptr)) !=EOF){
		printf("%c", c);
	}
	fclose(fptr);
	printf("\n\t\t\t\t\t\tTotal Amount");
	printf("\n\t\t\t\t\t\t    Rs.%d",totalCost);
	printf("\n***************************************************************");
	printf("\n\t\t\tTHANK YOU");
	printf("\n---------------------------------------------------------------");
	printf("\nWhat would you like to do next?\n1.Go back to customer choices.\n2.Go back to main menu.\nPick a choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
				customerChoices();
				break;
		case 2: 
				main();
				break;
		default:
				printf("\ninvalid input!");
				viewOrder();
				break;
				
	}
}

void serve(){
	int i,choice;
	
	orderCount = 0;	
	for(i = 0; i <=12; i++){
		name[i] = ' ';
	}		
	totalCost = 0;
	
	printf("\n1.Go back to customer panel\n2.Go to home Screen.\n3.Exit Program.");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
				customerChoices();
				break;
		case 2:
				main();
				break;
		case 3:
				printf("Thank you for your time. Goodbye.");
				exit(0);
				break;	
		default:
				printf("Please enter a number between 1-3");
				serve();
				break;
	}
}

void adminLogin(){
	char username[20];
	char password[20];
	printf("\nPlease Enter Username: ");
	scanf("%s", username);
	printf("\nPlease Enter Password: ");
	scanf("%s", password);
	if(strcmp(username, "touka") == 0 && strcmp(password, "kaneki") == 0){
		printf("\nYou have successfully logged into the system!\n");
		adminChoices();
	}else{
		incorrectLogin();
	}
}

void incorrectLogin(){
		int choice;
		printf("\nIncorrect Username or Password.");
		printf("\nWhat do you want to do next?\n");
		printf("1.Re-enter username/password.\n2.go back to main menu.\n3.exit program.\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
					adminLogin();
					break;
			case 2:
					main();
					break;
			case 3:
					printf("Thank you for your time. Goodbye.");
					exit(0);
					break;		
			default:
					printf("\nPlease enter a valid choice.");
					incorrectLogin();
					break;		
		}
	}

void adminChoices(){
	int choice,c;
	
	printf("\n1.View Stock.");
	printf("\n2.Restock items.");
	printf("\n3.View orders of the day.");
	printf("\n4.Go back to main menu.");
	printf("\n5.Exit the program.\n");
	printf("\nPlease pick an option:");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
				viewStock();
				break;
		case 2:
				restockItems();
				break;
		case 3:
				printf("\nItem Name\tQuantity\tItem Cost\tTotal Item Cost");
				allfptr = fopen("allOrders.txt","r");
				if(allfptr){
					while((c = getc(allfptr)) != EOF){
						putchar(c);
					}
					fclose(allfptr);
				}
				break;
		case 4:
				main();
				break;
		case 5:
				printf("\nGood work!");
				exit(0);
				break;
		default:
				printf("\nPlease enter a valid choice");
				adminChoices();
				break;
	}
}

void viewStock(){
	int choice;
	
	printf("\nNumber of Americanos left in stock:	%d", stock[0]);
	printf("\nNumber of Lattes left in stock:		%d", stock[1]);
	printf("\nNumber of Mochas left in stock:		%d", stock[2]);
	printf("\nNumber of Irish's left in stock:	%d", stock[3]);
	printf("\nNumber of Cookies left in stock:	%d", stock[4]);
	printf("\nNumber of Brownies left in stock:	%d", stock[5]);
	printf("\nNumber of Choco Cakes left in stock:	%d", stock[6]);
	printf("\nNumber of Cheesecake left in stock:	%d", stock[7]);

	printf("\n\nWhat would you like to do next?\n1.Go back to Admin Panel.\n2.Go to Main menu.\n3.Exit program.");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
				adminChoices();
				break;
		case 2:
				main();
				break;
		case 3:
				printf("\nGood Work!");
				exit(0);
				break;
		default:
				printf("\nPlease enter a valid choice. ");
				viewStock();
				break;
	}
}

void restockItems(){
	int i, choice;
	for(i = 0; i < 8; i++){
		stock[i] = 50;
	}
	printf("\nPantry items have been Restocked!.");
	printf("\nWhat would you like to do next?\n1.Go back to Admin Panel.\n2.Go to Main menu.\n3.Exit program.");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
				adminChoices();
				break;
		case 2:
				main();
				break;
		case 3:
				printf("\nThank you for your time. Goodbye");
				exit(0);
				break;
		default:
				printf("\nPlease enter a valid choice: ");
				restockItems();
				break;
	}
}
