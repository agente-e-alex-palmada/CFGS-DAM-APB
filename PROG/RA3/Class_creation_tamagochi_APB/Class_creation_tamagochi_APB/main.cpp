#include "myheader.h"
#include "Critter.h"
#include "Farm.h"

void menu(Farm myFarm);
Critter critterCreator();
int critterSelector(const Farm& myFarm);
void interactingCritter(Farm& myFarm, int selectedCritter);

int main() {
	// Select option
	int selection, selectedCritter;

	// Handles menus
	bool programRunning = true;

	// Creates an empty farm
	Farm myFarm;
	Critter defaultCritter;
	cout << "Welcome to Critter Caretaker\n\n";

	// Starts the first menu
	while (programRunning)
	{
		myFarm.checkAndRemoveDeadCritters();
		menu(myFarm);
		cout << "\nEnter option: ";
		cin >> selection;

		// Input validation for invalid input
		if (cin.fail() || selection < 0 || selection > 2) {

			// Clear the error state and ignore the rest of the invalid input
			cin.clear(); // Reset the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			system("cls");
			continue; // Skip the rest of the loop and prompt again
		}
		switch (selection)
		{
		case 0:
			system("cls");  // Clear the screen (Windows only)
			programRunning = false; // Exit the program
			break;
		case 1:
			system("cls");
			defaultCritter = critterCreator();  // Create a new critter
			myFarm.addCritter(defaultCritter);  // Add it to the farm
			break;
		case 2:
			system("cls");
			if (myFarm.getCritterCount() > 0) {
				selectedCritter = critterSelector(myFarm); // Let user select a critter
				if (selectedCritter == 0) {

					// User canceled or made an invalid selection
					programRunning = true;
					break;
				}
				else {
					
					// Function to interact with the selected critter
					system("cls");
					interactingCritter(myFarm, selectedCritter); // Interact with the critter
				}
			}
			break;
		default:
			system("cls");
			programRunning = true;
			break;
		}
	}

	cout << "Goodbye :3\n";
	return 0;
}

// Function to interact with created Critters
void interactingCritter(Farm& myFarm, int selectedCritter) {
	// Start the interaction menu
	bool interactionRunning = true;
	int selection;

	// Adjust for 0-indexed vector (subtract 1 to access vector correctly)
	int critterIndex = selectedCritter - 1;

	while (interactionRunning) {
		// Check for dead critters before starting interaction
		myFarm.checkAndRemoveDeadCritters();

		// Verify if the critter still exists (alive)
		if (critterIndex >= 0 && critterIndex < myFarm.getCritterCount()) {
			// Display the interaction menu if the critter is alive
			menuCritter();
		}
		else {
			interactionRunning = false;  // Exit the interaction loop if critter is dead
			break;  // Exit the loop as the critter is dead
		}

		// User input for interaction
		cin >> selection;
		system("cls"); // Clear screen

		if (cin.fail() || selection < 0) {
			cin.clear();  // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the input
			continue;
		}

		// Handle the interaction based on user input
		if (selection == 0) {
			interactionRunning = false;  // Exit the interaction loop
		}
		else {
			// Perform the selected action using the performAction function
			performAction(myFarm, critterIndex, selection);
			interactionRunning = true;  // Continue interacting
		}
	}
}


// Function to create a new Critter
Critter critterCreator() {
	string name;
	cout << "What name do you want to give to your new Critter?\n\nWrite: ";

	// Clears the input buffer to avoid issues with leftover newline characters
	cin.ignore();

	// Read the full name input from the user
	getline(cin, name);

	// Clear the screen after input
	system("cls");

	// Get the current time when the critter is "born" (created)
	auto now = chrono::system_clock::now();
	time_t bornTime = chrono::system_clock::to_time_t(now);

	// Create a new Critter object with default hunger and boredom values, and the provided name and time
	Critter newCritter(DEFAULT_HUNGER, DEFAULT_BOREDOM, name, bornTime);

	// Return the newly created Critter object
	return newCritter;
}

// Function to select a Critter from the farm
int critterSelector(const Farm& myFarm) {
	bool selectingCritter = true;  // A flag to keep the selection loop running
	int selection;
	// Loop to keep asking for a critter until a valid selection is made or user exits
	while (selectingCritter)
	{
		system("cls");  // Clear the console screen
		cout << "Critters at the farm:\n\n";
		myFarm.listCritters();  // List all the critters on the farm
		size_t crittersCount = myFarm.getCritterCount();  // Get the total number of critters
		cout << "\nSelect which Critter you want to interact with (0 to go back): ";
		cin >> selection;  // Read the user's selection

		// If the input is not valid or the selection is greater than the number of critters
		if (cin.fail() || selection > crittersCount)
		{
			cin.clear();  // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the input
			selectingCritter = true;  // Stay in the loop for re-selection
		}
		else if (selection == 0)  // If user chooses to exit
		{
			system("cls");
			selectingCritter = false;  // Exit the selection loop
			return 0;  // Return 0 (no critter selected)
		}
		else
		{
			return selection;  // Return the selected critter's index (1-based)
		}
	}
}

// Function to display the main menu for the farm caretaker
void menu(Farm myFarm) {
	cout << "0. Exit\n";  // Option to exit the program
	cout << "1. Create a new Critter\n";  // Option to create a new critter

	// If there are critters in the farm, show option to interact with them
	if (myFarm.getCritterCount() != 0)
	{
		cout << "2. Interact with Critters\n";  // Option to interact with existing critters
	}
}
