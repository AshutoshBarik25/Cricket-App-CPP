import java.util.*;

class Player {
    String name;
    int id;
    int runsScored;
    int ballsPlayed;
    int ballsBowled;
    int runsGiven;
    int wicketsTaken;

    // Constructor for Player class
    Player() {
        this.runsScored = 0;
        this.ballsPlayed = 0;
        this.ballsBowled = 0;
        this.runsGiven = 0;
        this.wicketsTaken = 0;
    }
}

class Team {
    String name;
    int totalRunsScored;
    int wicketsLost;
    int totalBallsBowled;
    List<Player> players;

    // Constructor for Team class
    Team(String name) {
        this.name = name;
        this.totalRunsScored = 0;
        this.wicketsLost = 0;
        this.totalBallsBowled = 0;
        this.players = new ArrayList<>();
    }
}

class Game {
    int playersPerTeam = 4;
    int maxBalls = 6;
    int totalPlayers = 22;
    String[] players;
    boolean isFirstInnings;
    Team teamA, teamB;
    Team battingTeam, bowlingTeam;
    Player batsman, bowler;
    
    // Constructor
    Game() {
        players = new String[]{"Virat", "Rohit", "Dhawan", "Pant", "Karthik", "KLRahul", "Jadeja", "Hardik", "Bumrah", "BKumar", "Mdhoni", "Rahul", "Sourav", "Ravishankar", "Sachin", "Kapil", "Anil", "Zaheer", "Harbhajan", "Yuvraj", "Imran", "Brian"};
        isFirstInnings = false;
        teamA = new Team("Team-A");
        teamB = new Team("Team-B");
    }
    
    void welcome() {
        System.out.println("---------------------------------------");
        System.out.println("|=========== GULLY-CRICKET ===========|");
        System.out.println("|                                     |");
        System.out.println("|   Welcome to our GULLY CRICKET..!   |");
        System.out.println("---------------------------------------\n");
    }

    void showAllPlayers() {
        System.out.println("\n---------------------------------------");
        System.out.println("|========== Pool of Players ==========|");
        System.out.println("---------------------------------------\n");
        for (int i = 0; i < totalPlayers; i++) {
            System.out.println("\t\t[" + i + "] " + players[i]);
        }
    }

    int takeIntegerInput(Scanner scanner) {
        while (!scanner.hasNextInt()) {
            System.out.println("Invalid input! Please try again with valid input: ");
            scanner.next();
        }
        return scanner.nextInt();
    }

    boolean validateSelectedPlayer(int index) {
        for (Player player : teamA.players) {
            if (player.id == index) return false;
        }
        for (Player player : teamB.players) {
            if (player.id == index) return false;
        }
        return true;
    }

    void selectPlayers(Scanner scanner) {
        System.out.println("\n------------------------------------------------");
        System.out.println("|========== Create Team-A and Team-B ==========|");
        System.out.println("------------------------------------------------\n");

        for (int i = 0; i < playersPerTeam; i++) {
            int playerIndexTeamA;
            do {
                System.out.println("Select player " + (i + 1) + " of Team A: ");
                playerIndexTeamA = takeIntegerInput(scanner);
            } while (!validateSelectedPlayer(playerIndexTeamA));
            teamA.players.add(new Player());
            teamA.players.get(i).name = players[playerIndexTeamA];
            
            int playerIndexTeamB;
            do {
                System.out.println("Select player " + (i + 1) + " of Team B: ");
                playerIndexTeamB = takeIntegerInput(scanner);
            } while (!validateSelectedPlayer(playerIndexTeamB));
            teamB.players.add(new Player());
            teamB.players.get(i).name = players[playerIndexTeamB];
        }
    }

    void showTeamPlayers() {
        System.out.println("\n--------------------------\t\t--------------------------");
        System.out.println("|=======  Team-A  =======|\t\t|=======  Team-B  =======|");
        System.out.println("--------------------------\t\t--------------------------");

        for (int i = 0; i < playersPerTeam; i++) {
            System.out.println("|\t[" + i + "] " + teamA.players.get(i).name + "\t |"
                    + "\t\t" + "|\t[" + i + "] " + teamB.players.get(i).name + "\t |");
        }
        System.out.println("--------------------------\t\t--------------------------\n");
    }
    
    void toss(Scanner scanner) {
        System.out.println("\n-----------------------------------");
        System.out.println("|========== Let's Toss  ==========|");
        System.out.println("-----------------------------------\n");
        System.out.println("Tossing the coin...\n");
        int randomValue = new Random().nextInt(2);
        if (randomValue == 0) {
            System.out.println("Team-A won the toss!");
            tossChoice(teamA, scanner);
        } else {
            System.out.println("Team-B won the toss!");
            tossChoice(teamB, scanner);
        }
    }

    void tossChoice(Team tossWinnerTeam, Scanner scanner) {
        System.out.println("Enter 1 to bat or 2 to bowl first: ");
        int tossInput = takeIntegerInput(scanner);
        if (tossInput == 1) {
            System.out.println(tossWinnerTeam.name + " won the toss and elected to bat first\n");
            battingTeam = tossWinnerTeam;
            bowlingTeam = (tossWinnerTeam == teamA) ? teamB : teamA;
        } else if (tossInput == 2) {
            System.out.println(tossWinnerTeam.name + " won the toss and chose to bowl first\n");
            bowlingTeam = tossWinnerTeam;
            battingTeam = (tossWinnerTeam == teamA) ? teamB : teamA;
        } else {
            System.out.println("Invalid input! Try again.");
            tossChoice(tossWinnerTeam, scanner);
        }
    }
}
