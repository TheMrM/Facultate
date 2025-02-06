package com.example.textapp;

public class Message {
    private String userId;
    private String userEmail;
    private String text;
    private long timestamp;

    // Required empty constructor for Firebase
    public Message() {}

    public Message(String userId, String userEmail, String text) {
        this.userId = userId;
        this.userEmail = userEmail;
        this.text = text;
        this.timestamp = System.currentTimeMillis();
    }

    // Getters and setters
    public String getUserId() { return userId; }
    public void setUserId(String userId) { this.userId = userId; }
    public String getUserEmail() { return userEmail; }
    public void setUserEmail(String userEmail) { this.userEmail = userEmail; }
    public String getText() { return text; }
    public void setText(String text) { this.text = text; }
    public long getTimestamp() { return timestamp; }
    public void setTimestamp(long timestamp) { this.timestamp = timestamp; }
}
