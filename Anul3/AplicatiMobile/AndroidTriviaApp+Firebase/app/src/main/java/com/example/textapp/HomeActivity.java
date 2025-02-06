package com.example.textapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.card.MaterialCardView;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.List;

public class HomeActivity extends AppCompatActivity {
    private FirebaseAuth mAuth;
    private DatabaseReference messagesRef;
    private MessageAdapter messageAdapter;
    private EditText messageInput;
    private RecyclerView messagesRecyclerView;

    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        // Initialize Firebase
        mAuth = FirebaseAuth.getInstance();
        FirebaseUser currentUser = mAuth.getCurrentUser();
        if (currentUser == null) {
            startActivity(new Intent(this, MainActivity.class));
            finish();
            return;
        }

        // Initialize Database
        messagesRef = FirebaseDatabase.getInstance().getReference("messages");

        // Initialize views
        TextView welcomeText = findViewById(R.id.welcomeText);
        messageInput = findViewById(R.id.messageInput);
        Button sendButton = findViewById(R.id.sendButton);
        Button logoutButton = findViewById(R.id.logoutButton);
        messagesRecyclerView = findViewById(R.id.messagesRecyclerView);

        // Setup RecyclerView
        messageAdapter = new MessageAdapter(currentUser.getUid());
        messagesRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        messagesRecyclerView.setAdapter(messageAdapter);

        // Set welcome message
        welcomeText.setText("Welcome, " + currentUser.getEmail());

        // Setup send button
        sendButton.setOnClickListener(v -> sendMessage());

        // Setup logout button
        logoutButton.setOnClickListener(v -> {
            mAuth.signOut();
            startActivity(new Intent(HomeActivity.this, MainActivity.class));
            finish();
        });

        // Setup trivia button
        Button triviaButton = findViewById(R.id.triviaButton);

        // In HomeActivity.java, update the trivia button click listener
        triviaButton.setOnClickListener(v -> {
            Intent intent = new Intent(HomeActivity.this, CategorySelectionActivity.class);
            startActivity(intent);
        });

        // Listen for messages
        loadMessages();

        // Initialize scoreboard button
        MaterialCardView scoreboardButton = findViewById(R.id.btn_scoreboard);
        scoreboardButton.setOnClickListener(v -> {
            Intent intent = new Intent(HomeActivity.this, ScoreboardActivity.class);
            startActivity(intent);
            overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);
        });
    }

    private void sendMessage() {
        String messageText = messageInput.getText().toString().trim();
        if (messageText.isEmpty()) return;

        FirebaseUser user = mAuth.getCurrentUser();
        if (user == null) return;

        Message message = new Message(
                user.getUid(),
                user.getEmail(),
                messageText
        );

        messagesRef.push().setValue(message)
                .addOnSuccessListener(aVoid -> messageInput.setText(""))
                .addOnFailureListener(e -> Toast.makeText(HomeActivity.this,
                        "Failed to send message", Toast.LENGTH_SHORT).show());
    }

    private void loadMessages() {
        messagesRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                List<Message> messages = new ArrayList<>();
                for (DataSnapshot snapshot : dataSnapshot.getChildren()) {
                    Message message = snapshot.getValue(Message.class);
                    if (message != null) {
                        messages.add(message);
                    }
                }
                messageAdapter.updateMessages(messages);
                messagesRecyclerView.scrollToPosition(messages.size() - 1);
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {
                Toast.makeText(HomeActivity.this,
                        "Failed to load messages", Toast.LENGTH_SHORT).show();
            }
        });
    }
}
