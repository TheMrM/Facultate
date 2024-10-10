document.addEventListener("touchstart", on_touch);
document.addEventListener("mousedown", on_touch);

let recognition;
if ('webkitSpeechRecognition' in window) {
    recognition = new webkitSpeechRecognition();
}

let recognition_start = false;
recognition.lang = "ro";
function on_touch() {
    if(recognition_start) {
        recognition.stop();
        recognition_start = false;
    } else {
        recognition.start();
        recognition_start = true;
    }
}
function onend() {
    recognition.stop();
    recognition_start = false;
}
recognition.onend = onend;
recognition.onsoundend = onend;
recognition.onspeechend = onend;

recognition.onresult = function (e) {
    let textElement = document.getElementById("text");
    if (textElement !== null) {
        let resultIndex = e.resultIndex;
        let transcript = e.results[resultIndex][0].transcript;
        let confidence = e.results[resultIndex][0].confidence;

        textElement.innerHTML += `Ati rostit cuvantul: <strong>${transcript}</strong>, acuratete: ${confidence.toFixed(2)}<br>`;
    }
}