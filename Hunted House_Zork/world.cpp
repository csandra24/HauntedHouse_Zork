#include <iostream>
#include <string>
#include "world.h"

using namespace text;

World::World() {

	commands = {
		new Command({"pick", "take", "get" }, PICK, 1),
		new Command({"move", "go" }, MOVE, 1),
		new Command({"inventory" }, INVENTORY, 1),
		new Command({"drop"}, DROP, 1),
		new Command({"save", "put" }, SAVE, 1),
		new Command({ "help" }, HELP, 1),
		new Command({"end", "quit", "exit"}, END, 1),

	};

	Room* basement  = new Room("Primer lugar"s, "descripción..."s);
	Room* basementRoom = new Room("Nombre lugar"s, "descripción..."s);
	Room* hall = new Room("Nombre lugar"s, "descripción..."s);
	Room* kitchen = new Room("Nombre lugar"s, "descripción..."s);
	Room* bedroom = new Room("Nombre lugar"s, "descripción..."s);
	Room* outdoor = new Room("Nombre lugar"s, "descripción..."s);
	Room* monster = new Room("Nombre lugar"s, "descripción..."s);
	/*falta end*/

	worldEntities.push_back(basement);
	worldEntities.push_back(basementRoom);
	worldEntities.push_back(hall);
	worldEntities.push_back(kitchen);
	worldEntities.push_back(bedroom);
	worldEntities.push_back(outdoor);
	worldEntities.push_back(monster);

	// exit
	Exit* basementToRoom = new Exit("You succeed in opening the door"s, ""s, basement, basementRoom, EAST);
	Exit* roomToHall = new Exit("Descripción"s, ""s, basementRoom, hall, UP);
	Exit* hallToKitchen = new Exit("Descripción"s, ""s, hall, kitchen, EAST);
	Exit* hallToBedroom = new Exit("Descripción"s, ""s, hall, bedroom, WEST);
	Exit* hallToOutdoor = new Exit("Descripción"s, ""s, hall, outdoor, NORTH);

	worldEntities.push_back(basementToRoom);
	worldEntities.push_back(roomToHall);
	worldEntities.push_back(hallToKitchen);
	worldEntities.push_back(hallToBedroom);
	worldEntities.push_back(hallToOutdoor);

	//items
	Item* bag = new Item("Nombre"s, "descripción", NULL, BAG);
	Item* box = new Item("Nombre"s, "descripción"s, NULL, BAG);
	Item* peach = new Item("Nombre"s, "descripción"s, box, FOOD);
	Item* closet = new Item("Nombre"s, "descripción"s, NULL, BAG);
	Item* silverKey = new Item("Nombre"s, "descripción"s, closet, SILVER_KEY);
	Item* kitchenCabinet = new Item("Nombre"s, "descripción"s, NULL, BAG);
	Item* kitchenCabinet1 = new Item("Nombre"s, "descripción"s, NULL, BAG);
	Item* fridge = new Item("Nombre"s, "descripción"s, NULL, BAG);
	Item* meat = new Item("Nombre"s, "descripción"s, kitchenCabinet, FOOD);
	Item* silverKey1 = new Item("Nombre"s, "descripción"s, kitchenCabinet1, SILVER_KEY);
	Item* firecracker = new Item("Nombre"s, "descripción"s, fridge, WEAPON);
	Item* goldKey = new Item("Nombre"s, "descripción"s, NULL, GOLD_KEY);

	worldEntities.push_back(bag);
	worldEntities.push_back(box);
	worldEntities.push_back(peach);
	worldEntities.push_back(closet);
	worldEntities.push_back(silverKey);
	worldEntities.push_back(kitchenCabinet);
	worldEntities.push_back(kitchenCabinet1);
	worldEntities.push_back(fridge);
	worldEntities.push_back(meat);
	worldEntities.push_back(silverKey1);
	worldEntities.push_back(firecracker);
	worldEntities.push_back(goldKey);

	Creature* slimeMonster = new Creature("Monster's name"s, "Descripción"s, basementRoom);
	Creature* slimeMonster = new Creature("Monster's name"s, "Descripción"s, bedroom);
	player = new Player("Player"s, "Descripción player"s, basement);

	worldEntities.push_back(monster);
	worldEntities.push_back(player);

	basement->addItem(box);
	basement->addItem(closet);
	kitchen->addItem(kitchenCabinet);
	kitchen->addItem(kitchenCabinet1);
	kitchen->addItem(fridge);
	bedroom->addItem(goldKey);

	printIntro();

	//posar sota de items
	/*bool gotSilverKey = false;
	bool gotGoldKey = false;

	for (entity* item : Player->childEntities) {
		if (compareString(item->name, "Silver Key")) {
			gotSilverKey = true;
		}
		else if (compareString(item->name, "Gold Key")) {
			gotGoldKey = true;
		}
	}*/

}

World::~World() {
	for (list<entity*>::reverse_iterator rit = worldEntities.rgbegin(); rit != worldEntities.rend(); ++rit) {
		delete* rit;
	}
	worldEntities.clear();

	for (command* cm = commands) {
		delete cm;
	}
	commands.clear();
}

Actions World::Input(const string& input)
{


}