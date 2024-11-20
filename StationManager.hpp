#ifndef STATIONMANAGER_HPP
#define STATIONMANAGER_HPP

#include "LinkedList.hpp"
#include "KitchenStation.hpp"
#include "Dish.hpp"
#include <string>
#include <vector>
#include <queue>

class StationManager : public LinkedList<KitchenStation*> {
public:
    /**
     * Default Constructor
     * @post: Initializes an empty station manager.
     */
    StationManager();


    /**
     * Adds a new station to the station manager.
     * @param station A pointer to a KitchenStation object.
     * @post: Inserts the station into the linked list.
     */
    bool addStation(KitchenStation* station);

    /**
     * Removes a station from the station manager by name.
     * @param station_name A string representing the station's name.
     * @post: Removes the station from the list and deallocates it.
     * @return: True if the station was found and removed; false otherwise.
     */
    bool removeStation(const std::string& station_name);

    /**
     * Finds a station in the station manager by name.
     * @param station_name A string representing the station's name.
     * @return: A pointer to the KitchenStation if found; nullptr otherwise.
     */
    KitchenStation* findStation(const std::string& station_name) const;

    /**
     * Moves a specified station to the front of the station manager list.
     * @param station_name A string representing the station's name.
     * @post: The station is moved to the front of the list if it exists.
     * @return: True if the station was found and moved; false otherwise.
     */
    bool moveStationToFront(const std::string& station_name);

    /**
     * Merges the dishes and ingredients of two specified stations.
     * @param station_name1 The name of the first station.
     * @param station_name2 The name of the second station.
     * @post: The second station is removed from the list, and its contents are added to the first station.
     * @return: True if both stations were found and merged; false otherwise.
     */
    bool mergeStations(const std::string& station_name1, const std::string& station_name2);

    /**
     * Assigns a dish to a specific station.
     * @param station_name A string representing the station's name.
     * @param dish A pointer to a Dish object.
     * @post: Assigns the dish to the specified station.
     * @return: True if the station was found and the dish was assigned; false otherwise.
     */
    bool assignDishToStation(const std::string& station_name, Dish* dish);

    /**
     * Replenishes an ingredient at a specific station.
     * @param station_name A string representing the station's name.
     * @param ingredient An Ingredient object.
     * @post: Replenishes the ingredient stock at the specified station.
     * @return: True if the station was found and the ingredient was replenished; false otherwise.
     */
    bool replenishIngredientAtStation(const std::string& station_name, const Ingredient& ingredient);

    /**
     * Checks if any station in the station manager can complete an order for a specific dish.
     * @param dish_name A string representing the name of the dish.
     * @return: True if any station can complete the order; false otherwise.
     */
    bool canCompleteOrder(const std::string& dish_name) const;

    /**
     * Prepares a dish at a specific station if possible.
     * @param station_name A string representing the station's name.
     * @param dish_name A string representing the name of the dish.
     * @post: If the dish can be prepared, reduces the quantities of the used ingredients at the station.
     * @return: True if the dish was prepared successfully; false otherwise.
     */
    bool prepareDishAtStation(const std::string& station_name, const std::string& dish_name);

private:
    // helper function to get index of a station by name
    int getStationIndex(const std::string& station_name) const;
};

#endif // STATIONMANAGER_HPP