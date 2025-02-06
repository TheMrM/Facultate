package com.example.textapp;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ProgressBar;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.tabs.TabLayout;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.List;

public class ScoreboardActivity extends AppCompatActivity {
    private RecyclerView recyclerView;
    private ScoreboardAdapter adapter;
    private ProgressBar loadingIndicator;
    private TabLayout tabLayout;
    private List<ScoreEntry> scoreEntries;
    private DatabaseReference scoresRef;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scoreboard);

        // Initialize views
        recyclerView = findViewById(R.id.scoreboard_recycler);
        loadingIndicator = findViewById(R.id.loading_indicator);
        tabLayout = findViewById(R.id.tab_layout);

        // Setup back button
        ImageButton backButton = findViewById(R.id.back_button);
        backButton.setOnClickListener(v -> {
            finish();
            overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);
        });

        // Setup RecyclerView
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        adapter = new ScoreboardAdapter();
        recyclerView.setAdapter(adapter);

        // Initialize Firebase
        scoresRef = FirebaseDatabase.getInstance().getReference("scores");

        // Load initial data
        loadScores("total_score");

        // Setup tab selection listener
        tabLayout.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                switch (tab.getPosition()) {
                    case 0:
                        loadScores("total_score");
                        break;
                    case 1:
                        loadScores("games_played");
                        break;
                    case 2:
                        loadScores("accuracy");
                        break;
                }
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {}

            @Override
            public void onTabReselected(TabLayout.Tab tab) {}
        });
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);
    }

    private void loadScores(String orderBy) {
        loadingIndicator.setVisibility(View.VISIBLE);
        scoresRef.orderByChild(orderBy)
                .limitToLast(50)
                .addListenerForSingleValueEvent(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                        scoreEntries = new ArrayList<>();
                        for (DataSnapshot scoreSnapshot : dataSnapshot.getChildren()) {
                            ScoreEntry entry = scoreSnapshot.getValue(ScoreEntry.class);
                            if (entry != null) {
                                scoreEntries.add(0, entry);
                            }
                        }
                        adapter.setScores(scoreEntries);
                        loadingIndicator.setVisibility(View.GONE);
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError databaseError) {
                        Toast.makeText(ScoreboardActivity.this,
                                "Error loading scores", Toast.LENGTH_SHORT).show();
                        loadingIndicator.setVisibility(View.GONE);
                    }
                });
    }
}
