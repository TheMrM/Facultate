package com.example.textapp;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class ScoreboardAdapter extends RecyclerView.Adapter<ScoreboardAdapter.ScoreViewHolder> {

    public static class ScoreViewHolder extends RecyclerView.ViewHolder {
        TextView rankText, usernameText, statsText, scoreText;

        public ScoreViewHolder(@NonNull View itemView) {
            super(itemView);
            rankText = itemView.findViewById(R.id.rank_text);
            usernameText = itemView.findViewById(R.id.username_text);
            statsText = itemView.findViewById(R.id.stats_text);
            scoreText = itemView.findViewById(R.id.score_text);
        }
    }

    private List<ScoreEntry> scores = new ArrayList<>();

    @NonNull
    @Override
    public ScoreViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.item_scoreboard, parent, false);
        return new ScoreViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ScoreViewHolder holder, int position) {
        ScoreEntry entry = scores.get(position);
        holder.rankText.setText(String.format(Locale.getDefault(), "%d.", position + 1));
        holder.usernameText.setText(entry.getUsername());
        holder.statsText.setText(String.format(Locale.getDefault(),
                "Games: %d | Accuracy: %.1f%%",
                entry.getGamesPlayed(), entry.getAccuracy()));
        holder.scoreText.setText(String.format(Locale.getDefault(), "%.1f", entry.getTotalScore()));
    }

    @Override
    public int getItemCount() {
        return scores.size();
    }

    public void setScores(List<ScoreEntry> scores) {
        this.scores = new ArrayList<>(scores);
        notifyDataSetChanged();
    }
}
