package model;

public class Player {

    protected int user_id;
    protected String name;
    protected int level;
    protected int trophies;
    protected int gold;
    protected int gems;
    protected int stars;

    public Player(int user_id, String name, int level, int trophies, int gold, int gems, int stars) {
        this.user_id = user_id;
        this.name = name;
        this.level = level;
        this.trophies = trophies;
        this.gold = gold;
        this.gems = gems;
        this.stars = stars;
    }

    public int getUser_id() {
        return user_id;
    }

    public void setUser_id(int new_user_id) {
        user_id = new_user_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String new_name) {
        name = new_name;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int new_level) {
        level = new_level;
    }

    public int getTrophies() {
        return trophies;
    }

    public void setTrophies(int new_trophies) {
        trophies = new_trophies;
    }

    public int getGold() {
        return gold;
    }

    public void setGold(int new_gold) {
        gold = new_gold;
    }

    public int getGems() {
        return gems;
    }

    public void setGems(int new_gems) {
        gems = new_gems;
    }

    public int getStars() {
        return stars;
    }

    public void setStars(int new_stars) {
        stars = new_stars;
    }

    public void showPlayerStats() {
        System.out.println("ID: " + user_id);
        System.out.println("Name: " + name);
        System.out.println("Level: " + level);
        System.out.println("Trophies: " + trophies);
        System.out.println("Gold: " + gold);
        System.out.println("Gems: " + gems);
        System.out.println("Stars: " + stars);
    }
}
