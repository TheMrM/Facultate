// Initialize variables for buttons and text display
const startButton = document.getElementById("start-btn");
const stopButton = document.getElementById("stop-btn");
const textElement = document.getElementById("text");

// Check if annyang is available
if (annyang) {
    // Set the language to Romanian (can be adjusted as needed)
    annyang.setLanguage("ro");

    // Define a simple command to handle spoken words
    let commands = {
        '*text': function(text) {
            textElement.innerHTML += `Ati rostit cuvantul: <strong>${text}</strong><br>`;
        }
    };

    // Add the defined commands to annyang
    annyang.addCommands(commands);

    // Start and stop event handlers
    startButton.addEventListener("click", function() {
        annyang.start(); // Start listening
        startButton.disabled = true; // Disable start button
        stopButton.disabled = false; // Enable stop button
        textElement.innerHTML += `<p style="color: green;"><strong>Recognition Started...</strong></p>`;
    });

    stopButton.addEventListener("click", function() {
        annyang.abort(); // Stop listening
        startButton.disabled = false; // Enable start button
        stopButton.disabled = true; // Disable stop button
        textElement.innerHTML += `<p style="color: red;"><strong>Recognition Stopped.</strong></p>`;
    });

    // Error handler (optional)
    annyang.addCallback('error', function(error) {
        textElement.innerHTML += `<p style="color: red;"><strong>Error:</strong> ${error.error}</p>`;
        console.error("Annyang Error: ", error);
    });

} else {
    // Display a message if the browser doesn't support speech recognition
    textElement.innerHTML = "<strong>Your browser does not support Speech Recognition.</strong>";
    console.error("Annyang is not supported in this browser.");
}
