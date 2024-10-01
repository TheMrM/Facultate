var video = document.getElementById("video");

function on_cam_success(stream) {
    video.srcObject = stream;
}

function on_cam_error(err) {
    alert("error occurred"+err.message);
}

var constraints = { audio: false, video: true };
navigator.mediaDevices.getUserMedia(constraints).then(on_cam_success).catch(on_cam_error);

function capteaza() {
    var c = document.getElementById("canvas");
    c.width = window.width;
    c.height = window.height;

    var ctx = c.getContext("2d");
    ctx.clearRect(0, 0, 640, 480);
}