package com.example.textapp;

// Only import this if we want to create new questions
/*import static com.example.textapp.TriviaQuestionManager.createSecurityQuestions;
import static com.example.textapp.TriviaQuestionManager.createNetworkingQuestions;
import static com.example.textapp.TriviaQuestionManager.createProgrammingQuestions;*/

import android.app.AlertDialog;
import android.content.Intent;
import android.content.res.ColorStateList;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import com.google.android.material.button.MaterialButton;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;


public class TriviaActivity extends AppCompatActivity implements QuizTimer.TimerListener {
    private static final String TAG = "TriviaActivity";
    private static final int QUESTIONS_PER_QUIZ = 10;

    private TextView questionTextView;
    private TextView questionCounter;
    private Button[] optionButtons;
    private List<TriviaQuestion> questionList;
    private int currentQuestionIndex = 0;
    private int score = 0;
    private String quizCategory;
    private CustomProgressDialog progressDialog;
    private QuizTimer quizTimer;

    private TextView correctAnswersText;
    private TextView wrongAnswersText;
    private TextView remainingQuestionsText;
    private ProgressBar quizProgress;
    private int wrongAnswers = 0;

    private Difficulty currentDifficulty;
    private float totalScore = 0f;

    private Button optionButton1, optionButton2, optionButton3, optionButton4;
    private TriviaQuestion currentQuestion;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
            Log.d(TAG, "TriviaActivity onCreate started");
            setContentView(R.layout.activity_trivia);

            // Get intent extras
            Intent intent = getIntent();
            String category = intent.getStringExtra("QUIZ_CATEGORY");
            String difficultyStr = intent.getStringExtra("DIFFICULTY");

            Log.d(TAG, "Received extras - Category: " + category +
                    ", Difficulty: " + difficultyStr);

            if (category == null) {
                category = "random";
                Log.d(TAG, "Using default category: random");
            }

            Difficulty difficulty = Difficulty.MEDIUM; // default
            if (difficultyStr != null) {
                try {
                    difficulty = Difficulty.valueOf(difficultyStr);
                    Log.d(TAG, "Successfully parsed difficulty: " + difficulty.name());
                } catch (IllegalArgumentException e) {
                    Log.e(TAG, "Invalid difficulty value: " + difficultyStr, e);
                }
            } else {
                Log.d(TAG, "Using default difficulty: MEDIUM");
            }

            Log.d(TAG, "Setting up quiz with category: " + category +
                    " and difficulty: " + difficulty.name());

            setupQuiz(difficulty);

        } catch (Exception e) {
            Log.e(TAG, "Error in onCreate", e);
            Toast.makeText(this, "Error starting quiz", Toast.LENGTH_SHORT).show();
            finish();
        }
    }


    private void setupQuiz(Difficulty difficulty) {
        // Save the difficulty
        currentDifficulty = difficulty;

        // Initialize views
        initializeViews();

        // Setup category
        setupQuizCategory();

        // Setup difficulty
        setupDifficulty();

        // Load questions
        loadQuestionsFromFirebase();
    }


    private void setupDifficulty() {
        quizTimer.setDifficulty(currentDifficulty);

        // Update UI to show difficulty
        if (getSupportActionBar() != null) {
            getSupportActionBar().setSubtitle(
                    capitalizeFirstLetter(currentDifficulty.name()) + " Mode");
        }
    }

    private void initializeViews() {
        questionTextView = findViewById(R.id.question_text_view);
        questionCounter = findViewById(R.id.question_counter);
        TextView timerTextView = findViewById(R.id.timer_text_view);

        // Initialize option buttons
        optionButton1 = findViewById(R.id.option_button_1);
        optionButton2 = findViewById(R.id.option_button_2);
        optionButton3 = findViewById(R.id.option_button_3);
        optionButton4 = findViewById(R.id.option_button_4);

        optionButtons = new Button[]{optionButton1, optionButton2, optionButton3, optionButton4};

        progressDialog = new CustomProgressDialog(this, "Loading questions...");
        quizTimer = new QuizTimer(timerTextView, this);

        // Initialize score tracking views
        correctAnswersText = findViewById(R.id.correct_answers);
        wrongAnswersText = findViewById(R.id.wrong_answers);
        remainingQuestionsText = findViewById(R.id.remaining_questions);
        quizProgress = findViewById(R.id.quiz_progress);
    }

    private void setupQuizCategory() {
        quizCategory = getIntent().getStringExtra("QUIZ_CATEGORY");
        if (quizCategory == null) {
            quizCategory = "random";
        }

        if (getSupportActionBar() != null) {
            getSupportActionBar().setDisplayHomeAsUpEnabled(true);
            getSupportActionBar().setTitle(capitalizeFirstLetter(quizCategory) + " Quiz");
        }
    }

    private void loadQuestionsFromFirebase() {
        DatabaseReference triviaRef = FirebaseDatabase.getInstance().getReference("Trivia questions");
        progressDialog.show();

        Log.d(TAG, "Loading questions for category: " + quizCategory + ", difficulty: " + currentDifficulty.name());

        triviaRef.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                try {
                    List<TriviaQuestion> allQuestions = new ArrayList<>();

                    for (DataSnapshot questionSnapshot : dataSnapshot.getChildren()) {
                        String questionId = questionSnapshot.getKey();

                        // Modified category check for random questions
                        if (!quizCategory.equalsIgnoreCase("random")) {
                            // If not random, check if question belongs to selected category
                            if (questionId == null || !questionId.toLowerCase().startsWith(quizCategory.toLowerCase())) {
                                continue;
                            }
                        }
                        // If random, accept all questions

                        String questionText = questionSnapshot.child("questionText").getValue(String.class);
                        List<String> options = new ArrayList<>();

                        DataSnapshot answersSnapshot = questionSnapshot.child("answer");
                        for (DataSnapshot answerSnapshot : answersSnapshot.getChildren()) {
                            String answer = answerSnapshot.getValue(String.class);
                            if (answer != null) {
                                options.add(answer);
                            }
                        }

                        Long correctAnswer = questionSnapshot.child("correctAnswer").getValue(Long.class);
                        int correctAnswerIndex = correctAnswer != null ? correctAnswer.intValue() : 0;

                        if (questionText != null && !options.isEmpty()) {
                            TriviaQuestion question = new TriviaQuestion(
                                    questionText,
                                    options.toArray(new String[0]),
                                    correctAnswerIndex
                            );
                            allQuestions.add(question);
                            Log.d(TAG, "Added question: " + questionText);
                        }
                    }

                    Log.d(TAG, "Total questions found: " + allQuestions.size());

                    if (allQuestions.isEmpty()) {
                        showError("No questions available for " + quizCategory +
                                " category at " + currentDifficulty + " difficulty");
                        return;
                    }

                    // Shuffle all questions for randomization
                    Collections.shuffle(allQuestions);

                    // Take only the required number of questions
                    questionList = new ArrayList<>(allQuestions.subList(0,
                            Math.min(QUESTIONS_PER_QUIZ, allQuestions.size())));

                    Log.d(TAG, "Final quiz questions: " + questionList.size());

                    runOnUiThread(() -> {
                        progressDialog.dismiss();
                        startQuiz();
                    });

                } catch (Exception e) {
                    Log.e(TAG, "Error loading questions", e);
                    showError("Error loading questions: " + e.getMessage());
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {
                Log.e(TAG, "Database error", databaseError.toException());
                showError("Database error: " + databaseError.getMessage());
            }
        });
    }


    private void startQuiz() {
        currentQuestionIndex = 0;
        score = 0;
        wrongAnswers = 0;
        updateScoreDisplay();
        displayQuestion();
    }

    private void updateScoreDisplay() {
        correctAnswersText.setText(String.format(Locale.getDefault(),
                "Correct: %d (%.1f pts)", score, totalScore));
        wrongAnswersText.setText(String.format(Locale.getDefault(),
                "Wrong: %d", wrongAnswers));

        int remaining = questionList.size() - (currentQuestionIndex);
        remainingQuestionsText.setText(String.format(Locale.getDefault(),
                "Remaining: %d", remaining));

        quizProgress.setMax(questionList.size());
        quizProgress.setProgress(currentQuestionIndex);
    }

    private void displayQuestion() {
        if (questionList == null || questionList.isEmpty()) {
            showError("No questions available");
            return;
        }

        if (currentQuestionIndex < questionList.size()) {
            updateScoreDisplay();
            quizTimer.startTimer();

            questionCounter.setText(String.format(Locale.getDefault(),
                    "Question %d/%d", currentQuestionIndex + 1, questionList.size()));

            // Get current question
            currentQuestion = questionList.get(currentQuestionIndex);
            currentQuestion.randomizeOptions();

            questionTextView.setText(currentQuestion.getQuestion());

            // Reset and set up each button
            String[] options = currentQuestion.getOptions();
            for (int i = 0; i < optionButtons.length && i < options.length; i++) {
                final int answerIndex = i;
                Button button = optionButtons[i];

                // Reset button appearance
                resetButtonStyle(button);

                // Set new text and enable
                button.setText(options[i]);
                button.setEnabled(true);
                button.setOnClickListener(v -> checkAnswer(answerIndex));
            }
        } else {
            showComplete();
        }
    }

    private void updateUserScore(float quizScore, int correctAnswers, int wrongAnswers) {
        FirebaseAuth auth = FirebaseAuth.getInstance();
        if (auth.getCurrentUser() == null) {
            Log.d(TAG, "User not logged in, skipping score update");
            return;
        }

        String userId = auth.getCurrentUser().getUid();
        String username = auth.getCurrentUser().getDisplayName();

        // If username is null or empty, use email or a default name
        if (username == null || username.isEmpty()) {
            username = auth.getCurrentUser().getEmail();
            if (username == null || username.isEmpty()) {
                username = "Anonymous Player";
            }
        }

        DatabaseReference userScoreRef = FirebaseDatabase.getInstance()
                .getReference("scores")
                .child(userId);

        Log.d(TAG, "Updating score for user: " + username);
        Log.d(TAG, "Quiz Score: " + quizScore + ", Correct: " + correctAnswers + ", Wrong: " + wrongAnswers);

        String finalUsername = username;
        userScoreRef.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                ScoreEntry currentScore = dataSnapshot.getValue(ScoreEntry.class);
                if (currentScore == null) {
                    // First time user, create new score entry
                    currentScore = new ScoreEntry(
                            userId,
                            finalUsername,
                            quizScore,
                            1,
                            correctAnswers,
                            wrongAnswers
                    );
                    Log.d(TAG, "Created new score entry for user");
                } else {
                    // Update existing score
                    currentScore.setTotalScore(currentScore.getTotalScore() + quizScore);
                    currentScore.setGamesPlayed(currentScore.getGamesPlayed() + 1);
                    currentScore.setCorrectAnswers(currentScore.getCorrectAnswers() + correctAnswers);
                    currentScore.setWrongAnswers(currentScore.getWrongAnswers() + wrongAnswers);
                    Log.d(TAG, "Updated existing score entry");
                }

                userScoreRef.setValue(currentScore)
                        .addOnSuccessListener(aVoid -> Log.d(TAG, "Score updated successfully"))
                        .addOnFailureListener(e -> Log.e(TAG, "Error updating score", e));
            }
            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {
                Log.e(TAG, "Error updating score", databaseError.toException());
            }
        });
    }


    // Add this new method to reset button style
    private void resetButtonStyle(Button button) {
        MaterialButton materialButton = (MaterialButton) button;

        // Reset background tint
        materialButton.setBackgroundTintList(ColorStateList.valueOf(
                ContextCompat.getColor(this, android.R.color.transparent)));

        // Reset text color
        materialButton.setTextColor(ContextCompat.getColor(this, R.color.primary_button_color));

        // Reset stroke color
        materialButton.setStrokeColor(ColorStateList.valueOf(
                ContextCompat.getColor(this, R.color.primary_button_color)));

        // Reset stroke width
        materialButton.setStrokeWidth(getResources().getDimensionPixelSize(R.dimen.button_stroke_width));
    }

    private void checkAnswer(int selectedAnswerIndex) {
        quizTimer.stopTimer();
        currentQuestion = questionList.get(currentQuestionIndex);
        boolean isCorrect = selectedAnswerIndex == currentQuestion.getAnswerIndex();
        Button selectedButton = optionButtons[selectedAnswerIndex];

        // Show visual feedback
        showAnswerFeedback(selectedButton, isCorrect);

        // Update scores
        if (isCorrect) {
            score++;
            float multiplier = currentDifficulty.getScoreMultiplier();
            totalScore += multiplier;
        } else {
            wrongAnswers++;
        }

        // Show feedback notification
        String feedbackMessage = isCorrect ? "Correct!" :
                "Wrong! The correct answer was: " + currentQuestion.getOptions()[currentQuestion.getAnswerIndex()];
        CustomNotification.show(
                this,
                feedbackMessage,
                isCorrect ? CustomNotification.NotificationType.CORRECT : CustomNotification.NotificationType.WRONG
        );

        // Disable all buttons temporarily
        for (Button button : optionButtons) {
            button.setEnabled(false);
        }

        // Move to next question after delay
        new Handler().postDelayed(() -> {
            currentQuestionIndex++;
            for (Button button : optionButtons) {
                button.setEnabled(true);
            }
            displayQuestion();
        }, 2000);

        updateScoreDisplay();
    }

    @Override
    public void onTimerFinish() {
        runOnUiThread(() -> {
            for (Button button : optionButtons) {
                button.setEnabled(false);
            }

            wrongAnswers++;
            updateScoreDisplay();

            CustomNotification.show(this, "Time's up!", CustomNotification.NotificationType.TIME_UP);

            TriviaQuestion currentQuestion = questionList.get(currentQuestionIndex);
            String correctAnswer = currentQuestion.getOptions()[currentQuestion.getAnswerIndex()];

            new Handler().postDelayed(() -> CustomNotification.show(this,
                    "Correct answer: " + correctAnswer,
                    CustomNotification.NotificationType.WRONG), 1000);

            new Handler().postDelayed(() -> {
                currentQuestionIndex++;
                displayQuestion();
            }, 2000);
        });
    }


    private void showComplete() {
        // Calculate final statistics
        float finalScore = totalScore;
        int finalCorrectAnswers = score;
        int finalWrongAnswers = wrongAnswers;
        float accuracy = (score * 100f) / (score + wrongAnswers);

        // Update user score in Firebase
        updateUserScore(finalScore, finalCorrectAnswers, finalWrongAnswers);

        // Show completion dialog
        new AlertDialog.Builder(this)
                .setTitle("Quiz Complete!")
                .setMessage(String.format(Locale.getDefault(),
                        "Difficulty: %s\n" +
                                "Total Score: %.1f points\n" +
                                "Correct Answers: %d\n" +
                                "Wrong Answers: %d\n" +
                                "Accuracy: %.1f%%",
                        currentDifficulty.name(),
                        finalScore,
                        finalCorrectAnswers,
                        finalWrongAnswers,
                        accuracy))
                .setPositiveButton("Return to Menu", (dialog, which) -> finish())
                .setCancelable(false)
                .show();
    }


    private void showError(String message) {
        runOnUiThread(() -> {
            if (progressDialog.isShowing()) {
                progressDialog.dismiss();
            }
            new AlertDialog.Builder(this)
                    .setTitle("Error")
                    .setMessage(message)
                    .setPositiveButton("OK", (dialog, which) -> finish())
                    .setCancelable(false)
                    .show();
        });
    }

    private void showAnswerFeedback(Button selectedButton, boolean isCorrect) {
        int color = isCorrect ?
                ContextCompat.getColor(this, R.color.success_green) :
                ContextCompat.getColor(this, R.color.error_red);

        // Store the original colors
        ColorStateList originalTextColor = selectedButton.getTextColors();
        ColorStateList originalStrokeColor = ((MaterialButton) selectedButton).getStrokeColor();

        // Change button appearance
        selectedButton.setBackgroundTintList(ColorStateList.valueOf(color));
        selectedButton.setTextColor(Color.WHITE);
        ((MaterialButton) selectedButton).setStrokeColor(ColorStateList.valueOf(color));

        // Reset button appearance after delay
        new Handler().postDelayed(() -> {
            selectedButton.setBackgroundTintList(null);
            selectedButton.setTextColor(originalTextColor);
            ((MaterialButton) selectedButton).setStrokeColor(originalStrokeColor);
        }, 1000); // Reset after 1 second
    }

    private void disableAllButtons() {
        optionButton1.setEnabled(false);
        optionButton2.setEnabled(false);
        optionButton3.setEnabled(false);
        optionButton4.setEnabled(false);
    }

    private void enableAllButtons() {
        optionButton1.setEnabled(true);
        optionButton2.setEnabled(true);
        optionButton3.setEnabled(true);
        optionButton4.setEnabled(true);
    }


    @Override
    protected void onPause() {
        super.onPause();
        if (quizTimer != null) {
            quizTimer.stopTimer();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (questionList != null && currentQuestionIndex < questionList.size()) {
            quizTimer.startTimer();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (quizTimer != null) {
            quizTimer.stopTimer();
        }
        if (progressDialog != null && progressDialog.isShowing()) {
            progressDialog.dismiss();
        }
    }

    private void updateScore(boolean isCorrect) {
        if (isCorrect) {
            score++;
            float multiplier = currentDifficulty.getScoreMultiplier();
            totalScore += multiplier;
        }
        updateScoreDisplay();
    }

    private void loadNextQuestion() {
        currentQuestionIndex++;
        displayQuestion();
    }

    private String capitalizeFirstLetter(String text) {
        if (text == null || text.isEmpty()) return text;
        return text.substring(0, 1).toUpperCase() + text.substring(1).toLowerCase();
    }
}
