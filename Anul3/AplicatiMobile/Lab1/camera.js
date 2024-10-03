const video = document.getElementById("video");

let imageCounter = 1;
video.addEventListener('playing', function () {
    video.addEventListener("touchstart", capture);
    video.addEventListener("mousedown", capture);
});

function on_cam_success(stream) {
    video.srcObject = stream;
}

function on_cam_error(err) {
    alert("error occurred"+err.message);
}

const constraints = {audio: false, video: true};
navigator.mediaDevices.getUserMedia(constraints).then(on_cam_success).catch(on_cam_error);

function capture() {
    const c = document.getElementById("canvas");
    c.width = video.videoWidth;
    c.height = video.videoHeight;

    const ctx = c.getContext("2d");
    ctx.clearRect(0, 0, c.width, c.height);

    ctx.drawImage(video, 0, 0, c.width, c.height);
}

function downloadImage() {
    const c = document.getElementById("canvas");
    const dataUrl = c.toDataURL("image/png");

    const link = document.createElement("a");
    link.download = 'myImage' + imageCounter + '.png';
    link.href = dataUrl;
    link.click();

    imageCounter++;
}

document.querySelector('button').addEventListener('click', function () {
    capture();
    setTimeout(downloadImage, 100);

    setTimeout(function () {
        window.addEventListener('keydown', function (e) {
            console.log(e.key, e.code);
        });
    }, 9000);
});
