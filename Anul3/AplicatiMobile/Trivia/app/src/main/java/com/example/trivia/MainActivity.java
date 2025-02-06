package com.example.trivia;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.Button;
import android.util.Log;
import java.io.ByteArrayOutputStream;

import androidx.appcompat.app.AppCompatActivity;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private TextView questionText;
    private Button option1, option2, option3, option4;
    private List<Question> questions;
    private int currentQuestionIndex = 0;
    private int score = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Intent musicServiceIntent = new Intent(this, MusicService.class);
        startService(musicServiceIntent);

        questionText = findViewById(R.id.questionText);
        option1 = findViewById(R.id.option1);
        option2 = findViewById(R.id.option2);
        option3 = findViewById(R.id.option3);
        option4 = findViewById(R.id.option4);

        questions = loadQuestions();
        showQuestion();

        option1.setOnClickListener(v -> checkAnswer(option1.getText().toString()));
        option2.setOnClickListener(v -> checkAnswer(option2.getText().toString()));
        option3.setOnClickListener(v -> checkAnswer(option3.getText().toString()));
        option4.setOnClickListener(v -> checkAnswer(option4.getText().toString()));
    }

    private List<Question> loadQuestions() {
        List<Question> questions = new ArrayList<>();
        try (InputStream is = getResources().openRawResource(R.raw.questions)) {
            ByteArrayOutputStream buffer = new ByteArrayOutputStream();
            byte[] data = new byte[1024]; // Read in chunks of 1 KB
            int bytesRead;
            while ((bytesRead = is.read(data, 0, data.length)) != -1) {
                buffer.write(data, 0, bytesRead);
            }
            String json = buffer.toString(StandardCharsets.UTF_8.name());

            JSONArray array = new JSONArray(json);
            for (int i = 0; i < array.length(); i++) {
                JSONObject obj = array.getJSONObject(i);
                String question = obj.getString("question");
                JSONArray optionsArray = obj.getJSONArray("options");
                String[] options = new String[optionsArray.length()];
                for (int j = 0; j < optionsArray.length(); j++) {
                    options[j] = optionsArray.getString(j);
                }
                String answer = obj.getString("answer");
                questions.add(new Question(question, options, answer));
            }
        } catch (Exception e) {
            logError("Failed to load questions: " + e.getMessage());
        }
        return questions;
    }

    private void logError(String message) {
        Log.e("MainActivity", message);
    }

    private void showQuestion() {
        if (currentQuestionIndex < questions.size()) {
            Question question = questions.get(currentQuestionIndex);
            questionText.setText(question.getQuestion());
            option1.setText(question.getOptions()[0]);
            option2.setText(question.getOptions()[1]);
            option3.setText(question.getOptions()[2]);
            option4.setText(question.getOptions()[3]);
        } else {
            Intent resultIntent = new Intent(this, ResultActivity.class);
            resultIntent.putExtra("score", score);
            startActivity(resultIntent);
            finish();
        }
    }

    private void checkAnswer(String selectedAnswer) {
        Question currentQuestion = questions.get(currentQuestionIndex);
        if (selectedAnswer.equals(currentQuestion.getAnswer())) {
            score++;
            Toast.makeText(this, "Correct!", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Wrong", Toast.LENGTH_SHORT).show();
        }
        currentQuestionIndex++;
        showQuestion();
    }
}
