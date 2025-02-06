package com.example.textapp;

public class ScoreEntry {
    private String userId;
    private String username;
    private float totalScore;
    private int gamesPlayed;
    private int correctAnswers;
    private int wrongAnswers;
    private float accuracy;
    private long lastPlayed;

    // Empty constructor for Firebase
    public ScoreEntry() {}

    public ScoreEntry(String userId, String username, float totalScore, int gamesPlayed,
                      int correctAnswers, int wrongAnswers) {
        this.userId = userId;
        this.username = username;
        this.totalScore = totalScore;
        this.gamesPlayed = gamesPlayed;
        this.correctAnswers = correctAnswers;
        this.wrongAnswers = wrongAnswers;
        this.accuracy = calculateAccuracy();
        this.lastPlayed = System.currentTimeMillis();
    }

    private float calculateAccuracy() {
        if (correctAnswers + wrongAnswers == 0) return 0;
        return (float) correctAnswers / (correctAnswers + wrongAnswers) * 100;
    }

    // Getters and setters
    public String getUserId() { return userId; }
    public void setUserId(String userId) { this.userId = userId; }
    public String getUsername() { return username; }
    public void setUsername(String username) { this.username = username; }
    public float getTotalScore() { return totalScore; }
    public void setTotalScore(float totalScore) { this.totalScore = totalScore; }
    public int getGamesPlayed() { return gamesPlayed; }
    public void setGamesPlayed(int gamesPlayed) { this.gamesPlayed = gamesPlayed; }
    public int getCorrectAnswers() { return correctAnswers; }
    public void setCorrectAnswers(int correctAnswers) { this.correctAnswers = correctAnswers; }
    public int getWrongAnswers() { return wrongAnswers; }
    public void setWrongAnswers(int wrongAnswers) { this.wrongAnswers = wrongAnswers; }
    public float getAccuracy() { return accuracy; }
    public void setAccuracy(float accuracy) { this.accuracy = accuracy; }
    public long getLastPlayed() { return lastPlayed; }
    public void setLastPlayed(long lastPlayed) { this.lastPlayed = lastPlayed; }
}
