#include <stdio.h>
#include <string.h>

// declare structure with typedef painting
typedef struct {
	            char code[7];
	            char artistName[20];
              	int pStyle;
              	char pName[100];
              	int pSubject;
              	int pSize;
              	int pMedium;
              	int pMaterial;
              	int pOrientation;
	            double pPrice;
               }painting;

// array of character pointers for style
char *styleArr[8]={"", 
                   "Abstract", 
                   "Fine Art",
                   "Figurative", 
                   "Modern", 
                   "Abstract Expressionism", 
                   "Expressionism"};
// array of character pointers for size              
char *sizeArr[6]={"", 
                  "Small", 
                  "Medium", 
                  "Large", 
                  "Oversize"};
// array of character pointers for subject
char *subjectArr[7]={"",
                     "Abstract", 
                     "Landscape", 
                     "People", 
                     "Portrait", 
                     "Nature", 
                     "Animal"};
// array of character pointers for medium
char *mediumArr[7]={"", 
                    "Acrylic", 
                    "Oil", 
                    "Watercolor", 
                    "Ink", 
                    "Paint", 
                    "Spray Paint"};
// array of character pointers for material
char *materialArr[7]={"", 
                      "Canvas", 
                      "Paper", 
                      "Wood", 
                      "Other", 
                      "Cardboard", 
                      "Soft"};
// array of character pointers for orientation
char *orientationArr[4]={"", 
                         "Portrait", 
                         "Landscape", 
                         "Square"}; 
// initialize an array of members of type 'painting'
painting database[1000] = 
                    {
					  {"", "", 0, "", 0, 0, 0, 0, 0, 0},
					  {"NT0001", "Nester Torro", 1, "Late Spring", 1, 1, 1, 1, 1, 1000.00},
					  {"FM0001", "Fabienne Monestier", 2, "Sweet Roses", 1, 1, 1, 1, 1, 2300.00},
					  {"NL0001", "Nikos Lamprinos", 1, "Untitled", 1, 1, 1, 1, 1, 1000.00},
		            };

// declare and define starting total of members in database
int totalItems = 3;

// function prototypes
char menu (void);
void printHelp(void);
void printHeader(void);
void printAll (void);
void addPainting (void);
void deleteItem(void);
void filterPaintings(void);
void modifyItem(void);

int main(void) 
{
  char choice = menu();
  
  // menu repitition
  while(choice != 'x')
  {   
    // switch statement based on input
    switch (choice) 
    {
      case 'a': 
        addPainting();
        break;
         
      case 'e':   
        deleteItem();
        break;
         
      case 'p':
        printAll();
        break;
        
      case 's':
        filterPaintings();
        break;
           
      case 'm':
        modifyItem();
        break;
            
      case 'x':
        break;
            
      default:
        puts("Error, please choose a valid option.");
        break;
    }
    // call menu again, get new character
    choice=menu();
  }
  // if 'x'
  printf("\n\nThank you. Exiting.");
    
  return 0;
}

// printout of the "help" for modifying/adding members of the type painting
void printHelp(void) 
{
  // placed in own function due to girth of printing formatting
  printf("\n[Help Codes]\n");
  printf("\n%-15s %-10s", 
         "Code:", 
         "The Artist's Initials and a 4 digit code. Ex: AB0001");
  printf("\n%-15s %-15s %-15s %-17s %-15s %-28s %-21s", 
         "Style:", 
         "[1] - Abstract",  
         "[2] - Fine Art",  
         "[3] - Figurative",  
         "[4] - Modern",  
         "[5] - Abstract Expressionism",  
         "[6] - Expressionism");
	printf("\n%-15s %-15s %-15s %-17s %-15s %-28s %-21s",
         "Subject:", 
         "[1] - Abstract",  
         "[2] - Landscape",  
         "[3] - People",  
         "[4] - Portrait",  
         "[5] - Nature",  
         "[6] - Animal");
	printf("\n%-15s %-15s %-15s %-17s %-15s", 
         "Size:", 
         "[1] - Small",  
         "[2] - Medium",  
         "[3] - Large",  
         "[4] - Oversize");
	printf("\n%-15s %-15s %-15s %-17s %-15s %-28s %-21s", 
         "Medium:", 
         "[1] - Acrylic",  
         "[2] - Oil",  
         "[3] - Watercolor",  
         "[4] - Ink",  
         "[5] - Paint",  
         "[6] - Spray Paint");
  printf("\n%-15s %-15s %-15s %-17s %-15s %-28s %-21s", 
         "Material:", 
         "[1] - Canvas",  
         "[2] - Paper",  
         "[3] - Wood",  
         "[4] - Other",  
         "[5] - Cardboard",  
         "[6] - Soft");
  printf("\n%-15s %-15s %-15s %-17s", 
         "Orientation:", 
         "[1] - Portrait",  
         "[2] - Landscape",  
         "[3] - Square");
  printf("\n----------------------------------------"
         "------------------------------------------"
         "-------------------\n\n");
}

// printout for the Header. Used often and has a lot of print data which can muddle up code later on.
void printHeader(void) 
{
  printf("\n\n-----------------------------------------------------------------"
		 "----------------------------------------------------------------------");
  printf("\n%-3s %-6s %-25s %-10s %-20.19s %-10s %-10s %-10s %-10s %-10s %10s", 
         "No", 
         "Code",
         "Artist Name", 
         "Style",
         "Painting Name", 
         "Subject", 
         "Size", 
         "Medium", 
         "Material", 
         "Orientation",
         "Price");
  printf("\n---------------------------------------------------------------------"
		 "------------------------------------------------------------------");
}

// menu which returns a choice from user input
char menu (void) 
{
  // small array to hold one character for choice
  char choice[2];
  printf("\n-----------------------------------"
         "\nWelcome to the Art Gallery Database"
         "\n-----------------------------------"
         "\n\n\tPress 'a' to add a painting"
         "\n\tPress 'e' to remove a painting"
         "\n\tPress 'p' to print data for all paintings"
         "\n\tPress 's' to search for a special painting"
         "\n\tPress 'm' to modify the data for a painting"
         "\n\tPress 'x' to Exit" 
         "\n\n\tPlease select an option: ");
         
  scanf("%s", choice);
    
  return choice[0];
}

// develop function to print entire database list.
void printAll (void) 
{
  printf("\n\nList of all paintings in inventory: ");
  printHeader();
  // iterates over list using a predefined integer, which updates only in the addItem function.
  for (int i=1; i<=totalItems; i++) 
  {
      printf("\n%-3d %-6s %-25s %-10.9s %-20.19s %-10s %-10s %-10.9s %-10.9s %-10.9s %10.2f", 
             i, 
             database[i].code, 
             database[i].artistName, 
             styleArr[database[i].pStyle], 
             database[i].pName, 
             subjectArr[database[i].pSubject], 
             sizeArr[database[i].pSize], 
             mediumArr[database[i].pMedium], 
             materialArr[database[i].pMaterial], 
             orientationArr[database[i].pOrientation], 
             database[i].pPrice);
   }
    printf("\n\n");
} 

// develop function to add a member to the database
void addPainting(void)
{
  printf("\n----------------------------------------"
         "------------------------------------------"
         "-------------------");
  printf("\nTo add a painting, please enter the information required.");
  printf("\n----------------------------------------"
         "------------------------------------------"
         "-------------------");
  printHelp();

  // blank array and type painting
  char userNames[100];
  painting userEntered = {"", "", 0, "", 0, 0, 0, 0, 0, 0};

  // input: Code
  printf("\nWhat is the code for the painting? ");
  scanf("%s", userEntered.code);

  // input: Artist Name
  printf("\nWhat is the Artist's name? ");
  scanf("%*c%[^\n]s", userNames);
  strcpy(userEntered.artistName, userNames);  

  // painting name
  printf("\nWhat is the Painting's name? ");
  scanf("%*c%[^\n]s", userNames);
  strcpy(userEntered.pName, userNames);

  // style
  printf("\nWhat is the style? ");
  scanf("%d", &userEntered.pStyle);

  // subject
  printf("\nWhat is the subject? ");
  scanf("%d", &userEntered.pSubject);
  //size
  printf("\nWhat is the size? ");
  scanf("%d", &userEntered.pSize);

  // medium
  printf("\nWhat is the medium? ");
  scanf("%d", &userEntered.pMedium);

  // material
  printf("\nWhat is the material? ");
  scanf("%d", &userEntered.pMaterial);

  // orientation
  printf("\nWhat is the orientation? ");
  scanf("%d", &userEntered.pOrientation);

  // price
  printf("\nWhat is the price? ");
  scanf("%lf", &userEntered.pPrice);

  // insert now-filled painting: userEntered into database.
  database[totalItems+1]=userEntered;
  // update integer detailing memberlist
  totalItems++;

  printf("\n\n");
  printAll();
}

// function for deleting members of database
void deleteItem(void) 
{
  printf("\n---------------------------------");
  printf("\nPlease select an item to delete: ");
  printf("\n---------------------------------");
  
  printAll();

  // empty painting to replace deleted space
  painting empty = {"", "", 0, "", 0, 0, 0, 0, 0, 0};
  int choice=0;
  printf("Choice: ");
  scanf("%d", &choice);

  // replace all parameters with empty member
  // position in database array will remain empty until modified. Array does not "push up" 
  // members, and we therefore cannot update totalItems.
  database[choice]=empty;

  printf("\n\n[Results]:");
  
  printAll();

}

// function to filter or selectively choose members of database.
void filterPaintings(void)
{
  // initialize empty structure painting
  painting specialPainting = {"", "", 0, "", 0, 0, 0, 0, 0, 0};
  // declare and define variables
  int selection = 0; 
  double minPrice= 0;
  double maxPrice= 0;

  printf("\n----------------------------------------"
         "------------------------------------------"
         "-------------------");
  printf("\nSearching for a special item? Please help us define your filters");
  printf("\n----------------------------------------"
         "------------------------------------------"
         "-------------------");
  printHelp();

  // do...while to designate paramters for each section of database members. 
  // To ignore a paramter, 0 may be entered.
  int confirm = 0;
  do
  {
    printf("\n\nStyle? [1-6, 0 to skip] ");
    scanf("%d", &specialPainting.pStyle);
  
    printf("\nSubject? [1-6, 0 to skip] ");
    scanf("%d", &specialPainting.pSubject);

    printf("\nSize? [1-4, 0 to skip] ");
    scanf("%d", &specialPainting.pSize);

    printf("\nMedium? [1-6, 0 to skip] ");
    scanf("%d", &specialPainting.pMedium);

    printf("\nMaterial? [1-6, 0 to skip] ");
    scanf("%d", &specialPainting.pMaterial);

    printf("\nOrientation? [1-3, 0 to skip] ");
    scanf("%d", &specialPainting.pOrientation);

    printf("\nMinimum Price? [required] ");
    scanf("%lf", &minPrice);

    printf("\nMaximum Price? [required] ");
    scanf("%lf", &maxPrice);

    // display filter choices in custom header
    printf("\nSummary of filters:");
    printf("\n---------------------------------"
            "-----------------------------------"
            "----------------------");
    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s %10s %10s",  
           "Style", 
           "Subject", 
           "Size", 
           "Medium", 
           "Material", 
           "Orientation",
           "Min Price",
           "Max Price");
    printf("\n---------------------------------"
            "-----------------------------------"
            "----------------------");
    printf("\n%-10.9s %-10.9s %-10.9s %-10.9s %-10.9s %-10.9s %10.2f %10.2f",       
           styleArr[specialPainting.pStyle], 
           subjectArr[specialPainting.pSubject],
           sizeArr[specialPainting.pSize],
           mediumArr[specialPainting.pMedium],
           materialArr[specialPainting.pMaterial],
           orientationArr[specialPainting.pOrientation],
           minPrice,
           maxPrice);

    // confirm choices
    printf("\n\nAre these filters correct? [1 - Y / 0 - N]: ");
    scanf("%d", &confirm);
  }
  // test that user is happy with input
  while (!confirm);

  printf("\n\n[Results]\n");
  printHeader();

  // iterate over members in database and compare integer categories with our parameters
  for (int i=1; i<=totalItems; i++) 
  {
    if (specialPainting.pStyle != database[i].pStyle && specialPainting.pStyle != 0) 
       continue;

    if (specialPainting.pSubject != database[i].pStyle && specialPainting.pSubject != 0) 
      continue;

    if (specialPainting.pSize != database[i].pStyle && specialPainting.pSize != 0) 
      continue;

    if (specialPainting.pMedium != database[i].pStyle && specialPainting.pMedium != 0) 
      continue;

    if (specialPainting.pMaterial != database[i].pStyle && specialPainting.pMaterial != 0) 
      continue;

    if (specialPainting.pOrientation != database[i].pStyle && specialPainting.pOrientation != 0) 
      continue;
    
    //last if statement compares prices, and is only accessed once all other paramters have been 
	// evaluated as false. Prints database[i] once completed.
    if (minPrice <= database[i].pPrice && maxPrice >= database[i].pPrice)
      printf("\n%-3d %-6s %-25.24s %-10.9s %-20.19s %-10.9s %-10.9s %-10.9s %-10.9s %-10.9s %10.2f", 
             i, 
             database[i].code, 
             database[i].artistName, 
             styleArr[database[i].pStyle], 
             database[i].pName, 
             subjectArr[database[i].pSubject], 
             sizeArr[database[i].pSize], 
             mediumArr[database[i].pMedium], 
             materialArr[database[i].pMaterial], 
             orientationArr[database[i].pOrientation], 
             database[i].pPrice);
  }
  printf("\n\n");
}

// modify function. 
void modifyItem(void)
{
  printHelp(); 

  printf("\n---------------------------------");
  printf("\nPlease select an item to modify: ");
  printf("\n---------------------------------");

  printAll();

  // declare and define variables/character array
  int choice=0;
  char newNames[100];
  // find and assign choice, which will be used in database position
  printf("Choice: ");
  scanf("%d", &choice);

  // for each category, reassign values
  printf("\nNew code [ex: AB0001]: ");
  scanf("%s", database[choice].code);

  printf("\nNew Artist Name: ");
  scanf("%*c%[^\n]s", newNames);
  strcpy(database[choice].artistName, newNames);

  printf("\nNew Painting Name: ");
  scanf("%*c%[^\n]s", newNames);
  strcpy(database[choice].pName, newNames);

  printf("\nNew Style [1-6]: ");
  scanf("%d", &database[choice].pStyle);

  printf("\nNew Subject [1-6]: ");
  scanf("%d", &database[choice].pSubject);

  printf("\nNew Size [1-4]: ");
  scanf("%d", &database[choice].pSize);

  printf("\nNew Medium [1-6]: ");
  scanf("%d", &database[choice].pMedium);

  printf("\nNew Material [1-6]: ");
  scanf("%d", &database[choice].pMaterial);

  printf("\nNew Orientation [1-3]: ");
  scanf("%d", &database[choice].pOrientation);

  printf("\nNew Price: ");
  scanf("%lf", &database[choice].pPrice);

  printf("\n\n[Results]:");
  printAll();

}
