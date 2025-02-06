package com.example.textapp;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.button.MaterialButton;

public class QuizMenuActivity extends AppCompatActivity {
    private RadioButton easyRadio, mediumRadio, hardRadio;
    private String category;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_category_selection);

        // Get category from intent
        category = getIntent().getStringExtra("CATEGORY");

        // Initialize views
        Button startQuizButton = findViewById(R.id.start_quiz_button);
        TextView categoryTitle = findViewById(R.id.category_title);

        // Initialize radio buttons
        easyRadio = findViewById(R.id.difficulty_easy);
        mediumRadio = findViewById(R.id.difficulty_medium);
        hardRadio = findViewById(R.id.difficulty_hard);

        // Initialize clickable layouts
        View layoutEasy = findViewById(R.id.layout_easy);
        View layoutMedium = findViewById(R.id.layout_medium);
        View layoutHard = findViewById(R.id.layout_hard);

        // Make entire layouts clickable
        View.OnClickListener radioClickListener = v -> {
            easyRadio.setChecked(false);
            mediumRadio.setChecked(false);
            hardRadio.setChecked(false);

            if (v.getId() == R.id.layout_easy) {
                easyRadio.setChecked(true);
            } else if (v.getId() == R.id.layout_medium) {
                mediumRadio.setChecked(true);
            } else if (v.getId() == R.id.layout_hard) {
                hardRadio.setChecked(true);
            }
        };

        layoutEasy.setOnClickListener(radioClickListener);
        layoutMedium.setOnClickListener(radioClickListener);
        layoutHard.setOnClickListener(radioClickListener);

        // Set title
        categoryTitle.setText(String.format("%s Quiz", capitalizeFirstLetter(category)));

        // Set default selection
        mediumRadio.setChecked(true);

        // Setup start button
        startQuizButton.setOnClickListener(v -> startQuiz());

        // Setup back button
        MaterialButton backButton = findViewById(R.id.back_button);
        backButton.setOnClickListener(v -> finish());
    }

    private void startQuiz() {
        String difficulty;
        if (easyRadio.isChecked()) {
            difficulty = "EASY";
        } else if (hardRadio.isChecked()) {
            difficulty = "HARD";
        } else {
            difficulty = "MEDIUM";
        }

        Intent intent = new Intent(this, TriviaActivity.class);
        intent.putExtra("QUIZ_CATEGORY", category);
        intent.putExtra("DIFFICULTY", difficulty);
        startActivity(intent);
        finish();
    }

    private String capitalizeFirstLetter(String text) {
        if (text == null || text.isEmpty()) return text;
        return text.substring(0, 1).toUpperCase() + text.substring(1).toLowerCase();
    }
}
