package com.example.trivia;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class ResultActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);

        // Linking the UI elements with the layout file
        TextView resultText = findViewById(R.id.resultText);
        Button retryButton = findViewById(R.id.retryButton);
        Button exitButton = findViewById(R.id.exitButton);

        // Display the user's score
        int score = getIntent().getIntExtra("score", 0);
        resultText.setText("Your Score: " + score);

        // Retry Button: Restart the game
        retryButton.setOnClickListener(v -> {
            Intent retryIntent = new Intent(ResultActivity.this, MainActivity.class);
            retryIntent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP); // Clear previous activities
            startActivity(retryIntent);
        });

        // Exit Button: Close the app
        exitButton.setOnClickListener(v -> {
            stopMusicService(); // Stop the music service
            finishAffinity(); // Close all activities
        });
    }

    private void stopMusicService() {
        Intent musicServiceIntent = new Intent(this, MusicService.class);
        stopService(musicServiceIntent);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // Stop the music only if the user exits the app
        if (isFinishing()) {
            stopMusicService();
        }
    }
}
