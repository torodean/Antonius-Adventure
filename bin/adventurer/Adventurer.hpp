#include <string>
#include <memory> // for smart pointers

// Forward declarations of the equipment classes
class Weapon;
class Armor;
class Steed;
class Special;

enum class ClassType 
{
    Warrior,
    Mage,
    Hunter,
    Rogue,
    Healer
};

class Adventurer 
{
protected:
    std::string name;          ///< Name of the adventurer
    ClassType adventurerClass; ///< Adventurer's class/role (e.g., Warrior, Mage, Rogue)

    // Adventurer attributes
    int strength;
    int stamina;
    int agility;
    int intelligence;
    int wisdom;

    // Equipment (using smart pointers to manage dynamic memory)
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Armor> armor;
    std::shared_ptr<Steed> steed;
    std::shared_ptr<Special> specialItem;

public:
    // Constructor with name, class, and attributes
    Adventurer(const std::string& name, const ClassType& adventurerClass, 
               int str, int stam, int agi, int intel, int wis)
        : name(name), adventurerClass(adventurerClass), 
          strength(str), stamina(stam), agility(agi), intelligence(intel), wisdom(wis) {}

    // Getters for name and class
    std::string getName() const { return name; }
    ClassType getAdventurerClass() const { return adventurerClass; }

    // Getters for attributes
    int getStrength() const { return strength; }
    int getStamina() const { return stamina; }
    int getAgility() const { return agility; }
    int getIntelligence() const { return intelligence; }
    int getWisdom() const { return wisdom; }

    // Setters and getters for equipment
    void setWeapon(std::shared_ptr<Weapon> newWeapon) { weapon = newWeapon; }
    std::shared_ptr<Weapon> getWeapon() const { return weapon; }

    void setArmor(std::shared_ptr<Armor> newArmor) { armor = newArmor; }
    std::shared_ptr<Armor> getArmor() const { return armor; }

    void setSteed(std::shared_ptr<Steed> newSteed) { steed = newSteed; }
    std::shared_ptr<Steed> getSteed() const { return steed; }

    void setSpecialItem(std::shared_ptr<Special> newSpecial) { specialItem = newSpecial; }
    std::shared_ptr<Special> getSpecialItem() const { return specialItem; }

    // Display basic adventurer info
    void displayAdventurerInfo() const 
    {
        std::cout << "Adventurer Name: " << name << "\n"
                  << "Class: " << classTypeToString(adventurerClass) << "\n"
                  << "Strength: " << strength << "\n"
                  << "Stamina: " << stamina << "\n"
                  << "Agility: " << agility << "\n"
                  << "Intelligence: " << intelligence << "\n"
                  << "Wisdom: " << wisdom << "\n";
                  << "Weapon: " << weapon->displayWeaponInfo() << "\n";
                  << "Armor: " << armor->displayArmorInfo() << "\n";
                  << "Steed: " << steed->displaySteedInfo() << "\n";
                  << "Special: " << specialItem->displaySpeclialInfo() << "\n";
    }

    // Helper function to convert ClassType to string
    std::string classTypeToString(ClassType classType) 
    {
        switch (classType) 
        {
            case ClassType::Warrior: return "Warrior";
            case ClassType::Mage: return "Mage";
            case ClassType::Ranger: return "hunter";
            case ClassType::Rogue: return "Rogue";
            case ClassType::Healer: return "Healer";
            default: return "Unknown";
        }
    }
};
