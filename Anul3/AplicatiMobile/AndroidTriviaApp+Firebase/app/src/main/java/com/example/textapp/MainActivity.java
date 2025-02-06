package com.example.textapp;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.dialog.MaterialAlertDialogBuilder;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseAuthInvalidCredentialsException;
import com.google.firebase.auth.FirebaseAuthInvalidUserException;


public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";
    private EditText emailInput, passwordInput;
    private FirebaseAuth mAuth;
    private ProgressDialog progressDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {
            // Initialize Firebase Auth
            mAuth = FirebaseAuth.getInstance();
            Log.d(TAG, "Firebase Auth instance: " + mAuth);

            // Initialize views
            emailInput = findViewById(R.id.emailInput);
            passwordInput = findViewById(R.id.passwordInput);
            Button loginButton = findViewById(R.id.loginButton);
            TextView registerText = findViewById(R.id.registerText);
            Button registerButton = findViewById(R.id.registerButton);
            TextView forgetPasswordText = findViewById(R.id.forgotPasswordText);

            // Initialize progress dialog
            progressDialog = new ProgressDialog(this);
            progressDialog.setMessage("Logging in...");
            progressDialog.setCancelable(false);

            // Check if user is already logged in
            if (mAuth.getCurrentUser() != null) {
                startActivity(new Intent(MainActivity.this, HomeActivity.class));
                finish();
                return;
            }

            // Login button click listener
            loginButton.setOnClickListener(v -> {
                try {
                    loginUser();
                } catch (Exception e) {
                    Log.e(TAG, "Error in login button click: ", e);
                    Toast.makeText(this, "Error: " + e.getMessage(), Toast.LENGTH_LONG).show();
                }
            });

            // Register button click listener
            registerButton.setOnClickListener(v -> {
                try {
                    Log.d(TAG, "Register button clicked");
                    Intent intent = new Intent(MainActivity.this, RegisterActivity.class);
                    startActivity(intent);
                    overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);
                } catch (Exception e) {
                    Log.e(TAG, "Error launching RegisterActivity: ", e);
                    Toast.makeText(this, "Error: " + e.getMessage(), Toast.LENGTH_LONG).show();
                }
            });

            // Register text click listener (if you want to keep it)
            registerText.setOnClickListener(v -> {
                Intent intent = new Intent(MainActivity.this, RegisterActivity.class);
                startActivity(intent);
                overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);
            });

            // Add Forgot Password click listener
            forgetPasswordText.setOnClickListener(v -> showResetPasswordDialog());

        } catch (Exception e) {
            Log.e(TAG, "Error in onCreate: ", e);
            Toast.makeText(this, "Error initializing app: " + e.getMessage(), Toast.LENGTH_LONG).show();
        }
    }

    private void showResetPasswordDialog() {
        MaterialAlertDialogBuilder builder = new MaterialAlertDialogBuilder(this);
        View dialogView = getLayoutInflater().inflate(R.layout.dialog_reset_password, null);
        EditText emailEditText = dialogView.findViewById(R.id.emailInput);

        // Pre-fill email if it's already entered in the login form
        String existingEmail = emailInput.getText().toString().trim();
        if (!existingEmail.isEmpty()) {
            emailEditText.setText(existingEmail);
        }

        builder.setView(dialogView)
                .setTitle("Reset Password")
                .setMessage("Enter your email address to receive a password reset link")
                .setPositiveButton("Send", null) // Set null here to prevent dialog from dismissing automatically
                .setNegativeButton("Cancel", (dialog, which) -> dialog.dismiss());

        AlertDialog dialog = builder.create();
        dialog.show();

        // Get the positive button and set its click listener
        Button positiveButton = dialog.getButton(AlertDialog.BUTTON_POSITIVE);
        positiveButton.setOnClickListener(v -> {
            String email = emailEditText.getText().toString().trim();

            if (email.isEmpty()) {
                emailEditText.setError("Email is required");
                return;
            }

            // Show progress
            dialog.setMessage("Sending reset link...");
            positiveButton.setEnabled(false);

            // Send reset email
            mAuth.sendPasswordResetEmail(email)
                    .addOnCompleteListener(task -> {
                        if (task.isSuccessful()) {
                            dialog.dismiss();
                            showSuccessDialog();
                        } else {
                            positiveButton.setEnabled(true);
                            dialog.setMessage("Enter your email address to receive a password reset link");
                            String errorMessage = task.getException() != null ?
                                    task.getException().getMessage() :
                                    "Failed to send reset email";
                            Toast.makeText(MainActivity.this,
                                    errorMessage, Toast.LENGTH_LONG).show();
                        }
                    });
        });
    }

    private void showSuccessDialog() {
        new MaterialAlertDialogBuilder(this)
                .setTitle("Reset Link Sent")
                .setMessage("Check your email for instructions to reset your password")
                .setPositiveButton("OK", null)
                .show();
    }

    private void loginUser() {
        try {
            String email = emailInput.getText().toString().trim();
            String password = passwordInput.getText().toString().trim();

            Log.d(TAG, "Attempting login for email: " + email);

            // Validation
            if (email.isEmpty()) {
                emailInput.setError("Email is required");
                return;
            }

            if (password.isEmpty()) {
                passwordInput.setError("Password is required");
                return;
            }

            progressDialog.show();

            mAuth.signInWithEmailAndPassword(email, password)
                    .addOnSuccessListener(authResult -> {
                        Log.d(TAG, "Login successful");
                        if (!isFinishing()) {
                            progressDialog.dismiss();
                            startActivity(new Intent(MainActivity.this, HomeActivity.class));
                            finish();
                        }
                    })
                    .addOnFailureListener(e -> {
                        Log.e(TAG, "Login failed", e);
                        if (!isFinishing()) {
                            progressDialog.dismiss();
                            String message = "Authentication failed";
                            if (e instanceof FirebaseAuthInvalidUserException) {
                                message = "No user found with this email";
                            } else if (e instanceof FirebaseAuthInvalidCredentialsException) {
                                message = "Invalid password";
                            }
                            Toast.makeText(MainActivity.this, message, Toast.LENGTH_LONG).show();
                        }
                    });

        } catch (Exception e) {
            Log.e(TAG, "Error in loginUser: ", e);
            if (!isFinishing()) {
                progressDialog.dismiss();
                Toast.makeText(this, "Error: " + e.getMessage(), Toast.LENGTH_LONG).show();
            }
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (progressDialog != null && progressDialog.isShowing()) {
            progressDialog.dismiss();
        }
    }

    // Add animation for when returning to this activity
    @Override
    public void finish() {
        super.finish();
        overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);
    }
}
