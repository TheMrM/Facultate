package com.example.textapp;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;

public class MessageAdapter extends RecyclerView.Adapter<MessageAdapter.MessageViewHolder> {
    private List<Message> messages = new ArrayList<>();
    private String currentUserId;

    public MessageAdapter(String currentUserId) {
        this.currentUserId = currentUserId;
    }

    @NonNull
    @Override
    public MessageViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.message_item, parent, false);
        return new MessageViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MessageViewHolder holder, int position) {
        Message message = messages.get(position);
        holder.bind(message);
    }

    @Override
    public int getItemCount() {
        return messages.size();
    }

    public void updateMessages(List<Message> newMessages) {
        messages = newMessages;
        notifyDataSetChanged();
    }

    class MessageViewHolder extends RecyclerView.ViewHolder {
        TextView messageText;
        TextView userEmail;
        TextView timestamp;

        MessageViewHolder(View itemView) {
            super(itemView);
            messageText = itemView.findViewById(R.id.messageText);
            userEmail = itemView.findViewById(R.id.userEmail);
            timestamp = itemView.findViewById(R.id.timestamp);
        }

        void bind(Message message) {
            messageText.setText(message.getText());
            userEmail.setText(message.getUserEmail());

            SimpleDateFormat sdf = new SimpleDateFormat("MM/dd HH:mm", Locale.getDefault());
            String timeString = sdf.format(new Date(message.getTimestamp()));
            timestamp.setText(timeString);

            // Set different background for current user's messages
            itemView.setBackgroundResource(
                    message.getUserId().equals(currentUserId)
                            ? R.drawable.message_background_self
                            : R.drawable.message_background_other
            );
        }
    }
}
