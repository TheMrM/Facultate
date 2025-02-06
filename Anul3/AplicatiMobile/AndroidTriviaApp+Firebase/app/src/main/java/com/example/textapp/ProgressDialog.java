package com.example.textapp;

import android.content.Context;

public class ProgressDialog {
    private final android.app.ProgressDialog dialog;

    public ProgressDialog(Context context) {
        dialog = new android.app.ProgressDialog(context);
        dialog.setCancelable(false);
    }

    public void setMessage(String message) {
        dialog.setMessage(message);
    }

    public void show() {
        dialog.show();
    }

    public void dismiss() {
        if (dialog != null && dialog.isShowing()) {
            dialog.dismiss();
        }
    }
}
