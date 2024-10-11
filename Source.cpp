#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>
#include <string>
#include <vector>

bool end = false;
const int fruit_length = 4, vegetable_length = 3, tea_length = 2;
const double total_discoeunt_starts_at = 10500;


std::vector<std::string> check_positions;
std::vector<double> check_positions_cost;
std::vector<int> check_positions_amount;

std::string Fruit_Juices[fruit_length]{ "Apple", "Orange", "Apricot", "Pear" }, Vegetable_Juices[vegetable_length]{ "Tomato", "Onion", "Cucumber" }, Tea[tea_length]{ "Garlic", "Parsley" };
double Fruit_j_cost[fruit_length]{200, 120, 150, 210}, Vegetable_j_cost[vegetable_length]{90, 1200, 2400}, Tea_cost[tea_length]{155, 4000};



void ta(std::string text) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text[i];
		if (text[i] == '.') {
			Sleep(600);
		}
		else {
			Sleep(4);
		}
	}
	text.clear();
}

void main_menu() {
	int position_in_menu = 0;
	ta("   ---   ===  Nikita's Juices  ===   ---   \n\n");
	std::cout 
		<< "| JUICES\t\t\t\t|\n"
		<< "|\tFruit\t\t\t\t|\n";
	for (int i = 0; i < fruit_length; i++) {
		position_in_menu += 1;
		if (Fruit_Juices[i].length() < 8) {
			std::cout << "|\t-- " << position_in_menu << "\t" << Fruit_Juices[i] << "\t\t" << Fruit_j_cost[i] << "r\t|\n";
		}
		else { std::cout << "|\t-- " << position_in_menu << "\t" << Fruit_Juices[i] << "\t" << Fruit_j_cost[i] << "r\t|\n"; }
	}
	std::cout << "|\tVegetable\t\t\t|\n";
	for (int i = 0; i < vegetable_length; i++) {
		position_in_menu += 1;
		if (Vegetable_Juices[i].length() < 8) {
			std::cout << "|\t-- " << position_in_menu << "\t" << Vegetable_Juices[i] << "\t\t" << Vegetable_j_cost[i] << "r\t|\n";
		}
		else{ std::cout << "|\t-- " << position_in_menu << "\t" << Vegetable_Juices[i] << "\t" << Vegetable_j_cost[i] << "r\t|\n"; }
	}
	std::cout << "| TEA\t\t\t\t\t|\n";
	for (int i = 0; i < tea_length; i++) {
		position_in_menu += 1;
		if (Tea[i].length() < 8) {
			std::cout << "|\t-- " << position_in_menu << "\t" << Tea[i] << "\t\t" << Tea_cost[i] << "r\t|\n";
		}
		else { std::cout << "|\t-- " << position_in_menu << "\t" << Tea[i] << "\t" << Tea_cost[i] << "r\t|\n"; }
	}
	std::cout << "|_______________________________________|\n";
}

void into_the_check(std::string choosen_product, double choosen_product_cost, int product_amount) {

	int id_of_finded_place = 0;
	bool is_object_in_list = false;




	if (check_positions.size() > 0) {
		for (int i = 0; i < check_positions.size(); i++) {
			if (check_positions[i] == choosen_product) {
				is_object_in_list = true;
				id_of_finded_place = i;
			}
		}
		if (is_object_in_list == true) {
			check_positions_cost[id_of_finded_place] = choosen_product_cost;
			check_positions_amount[id_of_finded_place] = product_amount;
		}
		else {
			check_positions.push_back(choosen_product);
			check_positions_cost.push_back(choosen_product_cost);
			check_positions_amount.push_back(product_amount);
		}

	}
	else {
		check_positions.push_back(choosen_product);
		check_positions_cost.push_back(choosen_product_cost);
		check_positions_amount.push_back(product_amount);
	}
	
	
	
}

int checklist_cout(std::vector<std::string> check_positions, std::vector<double> check_positions_cost, std::vector<int> check_positions_amount) {
	double Parsley_discount_amount = 0,	Free_onion_amount = 0, Total_discount = 0, Total_cost = 0;
	int Parsley_place_id = -1, Onion_place_id = -1, choice = 0, Onion_amount = -1;
	
	if (check_positions.size() > 0) {
		for (int i = 0; i < check_positions.size(); i++) {
			if (check_positions[i] == "Parsley") {
				Parsley_place_id = i;
			}
			if (check_positions[i] == "Onion") {
				Onion_place_id = i;
			}
		}
		if (Parsley_place_id > -1) {
			if (check_positions_amount[Parsley_place_id] / 3 > 1) {
				Parsley_discount_amount = 0.5;
			}
		}
		
		
		if (Onion_place_id > -1) {
			Onion_amount = check_positions_amount[Onion_place_id];
			while (Onion_amount > 1) {
				Onion_amount -= 4;
				if (Onion_amount >= 0) {
					Free_onion_amount += 1;
				}
				
			}
		}
	}
	else { ta("There's nothing in list, add something to calculate total cost"); }
	
	if (Parsley_place_id > -1) {
		Total_discount += (1 - Parsley_discount_amount) * (check_positions_amount[Parsley_place_id] * check_positions_cost[Parsley_place_id]);
	}
	if (Onion_place_id > -1) { Total_discount += (Free_onion_amount * check_positions_cost[Onion_place_id]); }
	
	for (int i = 0; i < check_positions.size(); i++) {

		Total_cost += check_positions_cost[i] * check_positions_amount[i];
	}
	if (Total_cost > total_discoeunt_starts_at) { Total_discount = Total_cost * 0.13; }


	

	std::cout
		<< "__________________________________________________\n"
		<< "|      Product            Cost           Amount  |\n"
		<< "+------------------------------------------------+\n";
	for (int i = 0; i < check_positions.size(); i++) {
		
		if (check_positions[i].length() < 8) {
			std::cout << "|\t" << check_positions[i] << "\t\t" << check_positions_cost[i] << "r\t\t" << check_positions_amount[i] << "\t |\n";
		}
		else { std::cout << "|\t" << check_positions[i] << "\t\t" << check_positions_cost[i] << "r\t" << check_positions_amount[i] << "\t |\n"; }
	}
	std::cout
		<< "+------------------------------------------------+\n"
		<< "| Total cost:\t" << Total_cost<< "r\tTotal discount:\t"<< Total_discount <<"r\t |\n"
		<< "| Total cost\t[Discount included]:\t" << Total_cost - Total_discount << "r\t |\n"
		<< "+------------------------------------------------+\n";




	std::cout << "\n\nIs it all?\n1 - Confirm purchase\n2 - Continue purchases\n\n";
	do {
		std::cout << ">>> ";
		std::cin >> choice;
	} while (choice < 1 || choice > 2);
	if (choice == 2) {
		system("cls");
	}
	else if (choice == 1) {
		end = true;
		return 0;
	}
	
	

}


int main() {
	

	srand(time(0));
	int choice = 0, choosen_cost = 0, amount = 0, total_menu_capacity = fruit_length + vegetable_length + tea_length;
	std::string current_choice = "blank";


	while (end != true) {
		current_choice.clear();
		main_menu();
		ta("\nWhat position you want to order?\n\n>>> ");
		do {
			std::cin >> choice;
		} while (choice <= 0 || choice > total_menu_capacity);
		if (choice > 0 && choice <= fruit_length) {
			current_choice = Fruit_Juices[choice - 1];
			choosen_cost = Fruit_j_cost[choice - 1];
		}
		else if (choice > fruit_length && choice <= total_menu_capacity - tea_length) {
			current_choice = Vegetable_Juices[choice - (1 + fruit_length)];
			choosen_cost = Vegetable_j_cost[choice - (1 + fruit_length)];
		}
		else if (choice > total_menu_capacity - tea_length && choice <= total_menu_capacity) {
			current_choice = Tea[choice - (1 + fruit_length + vegetable_length)];
			choosen_cost = Tea_cost[choice - (1 + fruit_length + vegetable_length)];
		}


		ta("\nHow many?\n\n>>> ");
		do {
			std::cin >> amount;
		} while (amount < 0);
		system("cls");

		
		into_the_check(current_choice, choosen_cost, amount);
		checklist_cout(check_positions, check_positions_cost, check_positions_amount);


	}
	return 0;
}