package com.example.textapp;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import androidx.cardview.widget.CardView;

public class CustomNotification {
    public static void show(Activity activity, String message, NotificationType type) {
        @SuppressLint("InflateParams") View layout = LayoutInflater.from(activity).inflate(R.layout.custom_notification, null);

        CardView cardView = layout.findViewById(R.id.notification_card);
        ImageView iconView = layout.findViewById(R.id.notification_icon);
        TextView messageView = layout.findViewById(R.id.notification_message);

        messageView.setText(message);

        // Set background color and icon based on type
        switch (type) {
            case CORRECT:
                cardView.setCardBackgroundColor(activity.getResources().getColor(R.color.success_green));
                iconView.setImageResource(R.drawable.ic_check_circle);
                break;
            case WRONG:
                cardView.setCardBackgroundColor(activity.getResources().getColor(R.color.error_red));
                iconView.setImageResource(R.drawable.ic_error);
                break;
            case TIME_UP:
                cardView.setCardBackgroundColor(activity.getResources().getColor(R.color.warning_yellow));
                iconView.setImageResource(R.drawable.ic_timer);
                break;
        }

        Toast toast = new Toast(activity);
        toast.setDuration(Toast.LENGTH_SHORT);
        toast.setView(layout);
        toast.show();
    }

    public enum NotificationType {
        CORRECT,
        WRONG,
        TIME_UP
    }
}
