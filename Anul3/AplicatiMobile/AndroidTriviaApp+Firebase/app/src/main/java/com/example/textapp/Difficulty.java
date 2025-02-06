package com.example.textapp;

public enum Difficulty {
    EASY(20000, 1.0f),    // 20 seconds, normal scoring
    MEDIUM(15000, 1.5f),  // 15 seconds, 1.5x scoring
    HARD(10000, 2.0f);    // 10 seconds, 2x scoring

    private final long timeInMillis;
    private final float scoreMultiplier;

    Difficulty(long timeInMillis, float scoreMultiplier) {
        this.timeInMillis = timeInMillis;
        this.scoreMultiplier = scoreMultiplier;
    }

    public long getTimeInMillis() {
        return timeInMillis;
    }

    public float getScoreMultiplier() {
        return scoreMultiplier;
    }
}

