package com.example.textapp;

import android.os.CountDownTimer;
import android.widget.TextView;
import java.util.Locale;

public class QuizTimer {
    private final TextView timerTextView;
    private CountDownTimer countDownTimer;
    private final TimerListener listener;
    private boolean isRunning;
    private long timeInMillis;
    private static final long INTERVAL = 1000; // 1 second intervals

    public interface TimerListener {
        void onTimerFinish();
    }

    public QuizTimer(TextView timerTextView, TimerListener listener) {
        this.timerTextView = timerTextView;
        this.listener = listener;
        this.isRunning = false;
        this.timeInMillis = Difficulty.MEDIUM.getTimeInMillis(); // default
    }

    public void setDifficulty(Difficulty difficulty) {
        this.timeInMillis = difficulty.getTimeInMillis();
    }

    public void startTimer() {
        if (isRunning) {
            stopTimer();
        }

        isRunning = true;
        countDownTimer = new CountDownTimer(timeInMillis, INTERVAL) {
            @Override
            public void onTick(long millisUntilFinished) {
                updateTimerDisplay(millisUntilFinished);
            }

            @Override
            public void onFinish() {
                isRunning = false;
                updateTimerDisplay(0);
                if (listener != null) {
                    listener.onTimerFinish();
                }
            }
        }.start();
    }

    public void stopTimer() {
        if (countDownTimer != null) {
            countDownTimer.cancel();
            isRunning = false;
        }
    }

    private void updateTimerDisplay(long millisUntilFinished) {
        int seconds = (int) (millisUntilFinished / 1000);
        String timeLeftFormatted = String.format(Locale.getDefault(), "%02d", seconds);
        if (timerTextView != null) {
            timerTextView.setText(String.format(Locale.getDefault(), "Time: %s", timeLeftFormatted));
        }
    }

}

