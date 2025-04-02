#include<iostream>
#include<string> 
#include <cctype>
#include<cstdlib>
#include<ctime>










using namespace std;

    /*
    TASKS LIST:
    
    1. array of tasks that are randomly generated from a set of already made tasks **DONE**

    2. let user add additional tasks to the list **DONE**
    
    3. assign values to each task
    
    4. keep track of value and grow character **DONE**

    5. mental health rating bar that generates a quote

    6. mark task from to do to done **DONE**
    
    7. delete task
    
    8. resources input to select to display the resources available **DONE**

    9. Make a menu **DONE**
    */



//select random tasks for the list
void preSelectTasks(string taskarr[], string taskList[], int numbers[], int & numbersCount, int & count, int preSelectAmount);


//add a task to the array of tasks
void addATask(string taskarr[], int & usedSize, string task);


//moves a task from to do list to done list
void markAsDone(string taskarr[], int index, int & usedSize, string donearr[], int & doneUsedSize);


//function to track the value of each task and update the value
//int trackValue(int & total, int valueToAdd);

//function to check if number is inside array
bool isInside(int num, int numbers[], int numbersCount);

//function to generate a mental health quote
void generateQuote();

//delete an element from to do list
void deleteTask(string taskarr[], int & usedSize, int index);


//check on character
void character(int tasksDone);

//Displays tasks
void displayList(string taskList[], int count);

void resources();

void optionCheck(string taskList[], int taskListCount, string doneTasks[], int doneTasksCount, string name);

void displayMenu();

void printMenu(int taskListCount, string taskList[], string doneTasks[], int doneTasksCount);




int main()
{
    string taskList[100];
    string doneTasks[100];
    int numbers[13];
    int numbersCount = 0;
    int doneSize = 0;
    int taskListCount = 0;
    
    string tasks[13] = {"Brush your teeth", "Wash your face", "Walk 10,000 steps", "Get 7-9 hours of sleep", "Exercise for 20 mins", 
        "Practice mindful breathing", "Take multivitamins", "Eat fruits and vegetables", "Digital detox for 3 hours", "Put on sunscreen", 
        "Brush your hair", "Take a shower", "Eat three healthy meals"};
    preSelectTasks(tasks, taskList, numbers, numbersCount, taskListCount, 3); //CHANGE THIS NUMBER FOR THE AMOUNT OF PREMADE TASKS

        
    string name;
    cout << "You have a little buddy who will grow as you do tasks! What is their name: ";
    cin >> name;

    
    cout << "How do you feel today? Scale 1-100: ";
    int feelings = 0; 
    cin >> feelings;
    printMenu(taskListCount, taskList, doneTasks, doneSize);
    displayMenu();
    optionCheck(taskList, taskListCount, doneTasks, doneSize, name);
    cout << "Day Over! How do you feel? Scale 1-100: ";
    int feelingsEnd = 0; 
    cin >> feelingsEnd; 
    if(feelingsEnd >= feelings)
        cout << "Glad your day got better!\n\n";
    else
        cout << "Hope your day is better tomorrow :)\n\n";
    
    cout << "Thank you for using the Healthy Habit Helper!\n";
    cout << "Good bye!\n";
}
 
//adds a user-entered task to the list of tasks
void addATask(string taskList[], int & usedSize, string task)
{
    if(usedSize < 100)
    {
        taskList[usedSize] = task;
        usedSize++;
    }
    else
    {
        cout << "List is full! Try completing some tasks first." << endl;
    }
}


//displays the list of tasks
void displayList(string taskList[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << taskList[i];
        cout << endl;
    }
}


bool isInside(int num, int numbers[], int numbersCount)
{
    for (int i = 0; i < numbersCount; i++)
    {
        if (numbers[i] == num)
        {
            return true;
        }
    }
    return false;
}

//selects 3 random tasks and adds them to the list of tasks

void preSelectTasks(string taskarr[], string taskList[], int numbers[], int & numbersCount, int & count, int preSelectAmount)
{
    srand(time(0));
    int num;
    for (int i = 0; i < preSelectAmount; i++)
    {
        num = rand() % 13;
        
        if (!(isInside(num, numbers, numbersCount)))
        {
            numbers[numbersCount] = num;
            numbersCount++;
            addATask(taskList, count, taskarr[num]);   
        }
        else
        {
            i--;
        }
        //taskList[i] = taskarr[num]; 
    }
}





//prints resources  *DONE*
void resources()
{
    cout << "Here are the resources available at ECU:\n";
    cout << "https://studenthealth.ecu.edu/ \n";
    cout << "https://counselingcenter.ecu.edu/ \n";
    cout << "https://career.ecu.edu/ \n\n"; 
}

void generateQuote()
{
    srand(time(0));
    int num = rand() % 50 + 1;
    //QUOTES MADE BY CHATGPT
    string quoteList[50] = {"You are stronger than you think", "Your feelings are valid", "Healing takes time—be patient with yourself", "You are not alone in this journey", "Small steps still lead to progress", "Your struggles do not define you", "It’s okay to ask for help", "You deserve kindness—including from yourself", "One bad day does not mean a bad life", "You are worthy of love and happiness", "Rest is productive too", "Your past does not determine your future", "You are doing the best you can", "Breathe—this moment will pass", "You are enough just as you are", "Self-care is not selfish", "Every day is a new opportunity", "Progress, not perfection", "You have survived 100 percent of your bad days", "It’s okay to take breaks", "Your mind deserves peace", "Mistakes do not make you a failure", "You are growing through what you’re going through", "Choose self-compassion over self-criticism", "The world is better with you in it", "Your mental health matters", "It’s okay to not be okay", "Keep going—even slow progress is progress", "You deserve happiness and peace", "Don’t be afraid to set boundaries", "Every storm runs out of rain", "Your voice matters", "You are not broken—you are healing", "Focus on what you can control", "Be as kind to yourself as you are to others", "There is hope even in the darkest times", "You are loved more than you know", "Your best is enough", "You are not alone—reach out", "Healing is not linear", "Believe in yourself even when it’s hard", "You are more than your struggles", "Keep fighting—you are worth it", "Take life one step at a time", "You are allowed to prioritize yourself", "Strength comes from perseverance", "There is beauty in imperfection", "You don’t have to have it all figured out", "Happiness is still possible", "You matter"};
    cout << quoteList[num] << endl;
}
//displays menu   *DONE*
void displayMenu()
{

    cout << "\n\n==========Healthy-Habit-Helper==========" << endl;
    cout << "1. View Tasks" << endl;
    cout << "2. Add A Task To Your List" << endl;
    cout << "3. Mark A Task As Done" << endl;
    cout << "4. Delete A Task" << endl;
    cout << "5. Display an inspirational quote" << endl;
    cout << "6. View Your Buddy (Based On Tasks Done)" << endl;
    cout << "7. View Resources" << endl; 
    cout << "8. End Day" << endl;
    cout << "========================================" << endl << endl;
}

void character(int tasksDone, string name)
{
    switch(tasksDone)
    {
        case 0:
        case 1:
            cout << name << " is looking very small. Do some tasks to help them grow!\n\n";
            cout << "    |    \n\n";
            break;
        case 2:
            cout << name << " is looking a bit happier, but they've still got room to grow!\n\n";
            cout << "   \\ o /   \n";
            cout << "     |    \n";
            cout << "    / \\    \n\n";
            break;
        case 3: 
        case 4:
            cout << name << " is looking quite happy! Looks like they're almost done growing!\n\n";
            cout << "    _O_     \n";
            cout << "   |   |   \n";
            cout << "    \\ /      \n";
            cout << "    / \\    \n\n";
            break;

        case 5:
        default:
            cout << name << " is as happy as can be! Congratulations!\n\n";
            cout << "   ----------   \n";
            cout << "  / (*)  (*) \\      \n";
            cout << " |  _ _ _ _   |   \n";
            cout << "  \\ \\_ _ _/  /       \n";
            cout << "    --------       \n\n";
    }
}


void markAsDone(string taskarr[], int index, int & usedSize, string donearr[], int & doneUsedSize)
{
    int goal = index;
    donearr[doneUsedSize] = taskarr[index];
    doneUsedSize++;

    for (int i = goal; i < usedSize; i++)
    {
        taskarr[i] = taskarr[i + 1];
    }
    usedSize--;
}

void deleteTask(string taskarr[], int & usedSize, int index)
{
    int goal = index;
    for (int i = goal; i < usedSize; i++)
    {
        taskarr[i] = taskarr[i + 1];
    }
    usedSize--;
}

void printMenu(int taskListCount, string taskList[], string doneTasks[], int doneSize)
{
	cout << "Tasks to do:\t\t\t\tDone Tasks:\n";
    int counter = taskListCount;
    if (doneSize > taskListCount)
        counter = doneSize;
	for (int i = 0; i < counter; i++)
	{
		
		printf("|%d: %20s\t\t|%d: %s\n", i + 1, taskList[i].data(), i + 1, doneTasks[i].data());
		
	}
    cout << "\n\n";
}

void optionCheck(string taskList[], int taskListCount, string doneTasks[], int doneTasksCount, string name)
{
    int choice = -1; 
    
    while(choice <= 0 || choice >= 10)
    {
        cout << "Please choose one of the above options: ";
        cin >> choice;
    }

    string task;

    int index;
    char temp;
    switch(choice)
    {
        case 1: //DISPLAY THE LIST
            printMenu(taskListCount, taskList, doneTasks, doneTasksCount);
            //clear line
            cout << "Hit enter to continue";
            cin.ignore();
            cin.get(temp);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;
            
        case 2: //ADD A TASK TO THE LIST
            cout << "Enter task to be added to To-Do List: ";
            cin.ignore();
            getline(cin, task);
            addATask(taskList, taskListCount, task);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;

        case 3: //MARK A TASK AS DONE
            cout << "Enter the number of the task you want to mark as done: ";
            cin >> index;
            markAsDone(taskList, index - 1, taskListCount, doneTasks, doneTasksCount);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;


        case 4: //DELETE A TASK
            cout << "Enter the number of the task you want to delete: ";
            cin >> index;
            deleteTask(taskList, taskListCount, index - 1);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;

        case 5: //DISPLAY AN INSPIRATIONAL QUOTE
            generateQuote();
            cout << "Hit enter to continue";
            cin.ignore();
            cin.get(temp);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;

        case 6: //DISPLAY CHARACTER
            character(doneTasksCount, name);
            cout << "Hit enter to continue";
            cin.ignore();
            cin.get(temp);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;

        case 7: //DISPLAY RESOURCES
            resources();
            cout << "Hit enter to continue";
            cin.ignore();
            cin.get(temp);
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount, name);
            break;

        case 8:
            break;
    }
}
