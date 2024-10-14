#include <iostream>
#include <string>
#include <vector>

// Enum for valid building types.
enum class BuildingType 
{
    MissionHall,
    LumberMill,
    Storehouse,
    Mine,
    Farm,
    Garden,
    ArcaneTower,
    Blacksmith,
    TrainingGrounds,
    Tavern,
    Temple,
    HuntingLodge,
    Workshop,
    Stables,
    Docks,
    // Add more types if needed later
};

// Base class for all buildings
class Building 
{
protected:
    int level;          ///< Building level (1 to 1000)
    BuildingType type;  ///< Building type (e.g., Mission Hall, Blacksmith, etc.)
    std::string name;   ///< Optional name for the building

public:
    // Constructor
    Building(BuildingType buildingType, int startLevel = 1) : type(buildingType), level(1) 
    {
        setLevel(startLevel); // Set initial level.
    }

    // Getter for level
    int getLevel() const 
    {
        return level;
    }

    // Setter for level (1 to 1000)
    void setLevel(int newLevel) 
    {
        if (newLevel < 1) 
        {
            level = 1;
        } 
        else if (newLevel > 1000) 
        {
            level = 1000;
        } 
        else 
        {
            level = newLevel;
        }
    }

    // Getter for type
    BuildingType getType() const 
    {
        return type;
    }

    // Getter for building name
    std::string getBuildingName() const 
    {
        return name;
    }

    // Setter for building name
    void setBuildingName(const std::string& newName) 
    {
        name = newName;
    }

    // Virtual method to display building details (can be overridden by derived classes)
    virtual void displayBuildingInfo() const 
    {
        std::cout << "Building Type: " << getBuildingTypeName() << "\n";
        std::cout << "Level: " << level << "\n";
    }

    // Virtual destructor
    virtual ~Building() {}

protected:
    // Helper function to convert BuildingType enum to string for display
    std::string getBuildingTypeName() const 
    {
        switch (type) 
        {
            case BuildingType::MissionHall: return "Mission Hall";
            case BuildingType::LumberMill: return "Lumber Mill";
            case BuildingType::Storehouse: return "Storehouse";
            case BuildingType::Mine: return "Mine";
            case BuildingType::Farm: return "Farm";
            case BuildingType::Garden: return "Garden";
            case BuildingType::ArcaneTower: return "Arcane Tower";
            case BuildingType::Blacksmith: return "Blacksmith";
            case BuildingType::TrainingGrounds: return "Training Grounds";
            case BuildingType::Tavern: return "Tavern";
            case BuildingType::Temple: return "Temple";
            case BuildingType::HuntingLodge: return "Hunting Lodge";
            case BuildingType::Workshop: return "Workshop";
            case BuildingType::Stables: return "Stables";
            case BuildingType::Docks: return "Docks";
            default: return "Unknown Building Type";
        }
    }
};
