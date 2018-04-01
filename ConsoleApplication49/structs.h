
struct hockey
{
	char *surname;
	int age;
	int countGame;
	int countGoal;
};
struct product
{
	char *name;
	char *PrName;
	int year;
	int count;
	int price;
};
struct employee
{
	char *name;
	int year;
	char *position;
	int salary;
	char* education;
};
struct students
{
	char *name;
	int group;
	int year;
	int physics;
	int math;
	int informatics;
};

struct dob
{
	int year;
	int month;
	int day;
};

struct note1
{
	char *name;
	char *tele;
	dob ymd;
};

struct tovar
{
	char*name;
	int count;
	int price;
	dob ymd;
};

struct marshrut
{
	int number;
	char*nameStart;
	char*nameEnd;
	int lenght;
};