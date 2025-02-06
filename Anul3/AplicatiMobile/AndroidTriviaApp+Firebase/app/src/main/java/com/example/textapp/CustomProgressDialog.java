package com.example.textapp;

import android.app.AlertDialog;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;

// CustomProgressDialog.java
public class CustomProgressDialog {
    private AlertDialog dialog;
    private boolean isShowing = false;

    public CustomProgressDialog(Context context, String message) {
        // Create the dialog
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        View view = LayoutInflater.from(context).inflate(R.layout.progress_dialog_layout, null);
        TextView messageText = view.findViewById(R.id.progress_message);
        messageText.setText(message);
        builder.setView(view);
        builder.setCancelable(false);
        dialog = builder.create();
    }

    public void show() {
        if (!isShowing && dialog != null) {
            dialog.show();
            isShowing = true;
        }
    }

    public void dismiss() {
        if (isShowing && dialog != null) {
            dialog.dismiss();
            isShowing = false;
        }
    }

    public boolean isShowing() {
        return isShowing;
    }

    public void setMessage(String message) {
        if (dialog != null) {
            TextView messageText = dialog.findViewById(R.id.progress_message);
            if (messageText != null) {
                messageText.setText(message);
            }
        }
    }
}

