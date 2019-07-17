struct dateofbirth
{
    int day,mon,year;
};
typedef struct dateofbirth dob;

typedef struct address
{
    int housenum;
    char area[50];
    char city[30];

}add;
 typedef struct customar
{
    int custID;
    char FirstName[30];
    char MiddleName[30];
    char gender;
    struct dateofbirth dob;
    int pincode;  
    long custNum;   
    struct address add; 

 }cust;
 
void insertAtEnd();
void displayList();
void delet();
void customer();
