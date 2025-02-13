package model;

import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "players")
public class Player {
    
    @Id
    @GeneratedValue(strategy= GenerationType.AUTO)
    protected int user_id;
    
    @Basic
    @Column(name = "name", length = 50, nullable = true)
    protected String name;
    
    @Basic
    @Column(name = "level", nullable = true)
    protected int level;
    
    @Basic
    @Column(name = "trophies", nullable = true)
    protected int trophies;
    
    @Basic
    @Column(name = "gold", nullable = true)
    protected int gold;
    
    @Basic
    @Column(name = "gems", nullable = true)    
    protected int gems;
    
    @Basic
    @Column(name = "stars", nullable = true)    
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
