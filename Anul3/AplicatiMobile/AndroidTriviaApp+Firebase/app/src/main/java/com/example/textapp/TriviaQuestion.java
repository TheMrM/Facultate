package com.example.textapp;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TriviaQuestion {
    private final String question;
    private String[] options;
    private int answerIndex;
    private final int originalAnswerIndex;

    public TriviaQuestion(String question, String[] options, int answerIndex) {
        this.question = question;
        this.options = options.clone(); // Create a copy of the array
        this.answerIndex = answerIndex;
        this.originalAnswerIndex = answerIndex;
    }

    public void randomizeOptions() {
        // Create a list of answer indices
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < options.length; i++) {
            indices.add(i);
        }

        // Create temporary arrays for shuffling
        String[] newOptions = new String[options.length];
        Collections.shuffle(indices);

        // Rearrange options and track new position of correct answer
        for (int i = 0; i < indices.size(); i++) {
            newOptions[i] = options[indices.get(i)];
            if (indices.get(i) == originalAnswerIndex) {
                answerIndex = i;
            }
        }

        options = newOptions;
    }

    public String getQuestion() {
        return question;
    }

    public String[] getOptions() {
        return options;
    }

    public int getAnswerIndex() {
        return answerIndex;
    }
}

