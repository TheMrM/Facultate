package com.example.textapp;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.button.MaterialButton;
import com.google.android.material.card.MaterialCardView;

public class CategorySelectionActivity extends AppCompatActivity {
    private static final String TAG = "CategorySelectionActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_quiz_menu);

        // Initialize MaterialCardViews
        MaterialCardView securityCard = findViewById(R.id.btn_security);
        MaterialCardView networkingCard = findViewById(R.id.btn_networking);
        MaterialCardView programmingCard = findViewById(R.id.btn_programming);
        MaterialCardView randomCard = findViewById(R.id.btn_random);
        MaterialButton backButton = findViewById(R.id.back_button);

        View.OnClickListener categoryClickListener = v -> {
            String category;
            if (v.getId() == R.id.btn_security) {
                category = "security";  // use lowercase to match database keys
            } else if (v.getId() == R.id.btn_networking) {
                category = "networking";
            } else if (v.getId() == R.id.btn_programming) {
                category = "programming";
            } else if (v.getId() == R.id.btn_random) {
                category = "random";
            } else {
                category = "random"; // default to random if somehow none matched
            }

            Log.d(TAG, "Selected category: " + category);

            Intent intent = new Intent(this, QuizMenuActivity.class);
            intent.putExtra("CATEGORY", category);
            startActivity(intent);
            overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);
        };


        // Set click listeners for cards
        securityCard.setOnClickListener(categoryClickListener);
        networkingCard.setOnClickListener(categoryClickListener);
        programmingCard.setOnClickListener(categoryClickListener);
        randomCard.setOnClickListener(categoryClickListener);

        // Add ripple effect to cards
        securityCard.setClickable(true);
        networkingCard.setClickable(true);
        programmingCard.setClickable(true);
        randomCard.setClickable(true);

        securityCard.setFocusable(true);
        networkingCard.setFocusable(true);
        programmingCard.setFocusable(true);
        randomCard.setFocusable(true);

        // Setup back button
        backButton.setOnClickListener(v -> {
            finish();
            overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);
        });
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
    }
}
