document.addEventListener("DOMContentLoaded", function () {
    const video = document.getElementById("video");
    let imageCounter = 1;
    let keyLoggedArray = [];

    // Consolidate `keydown` event listener into one.
    window.addEventListener('keydown', function (e) {
        console.log("Keys Pressed" + (" -> ") + e.key);
        keyLoggedArray.push(e.key);
    });

    video.addEventListener('playing', function () {
        video.addEventListener("touchstart", capture);
        video.addEventListener("mousedown", capture);
    });

    function on_cam_success(stream) {
        video.srcObject = stream;
    }

    function on_cam_error(err) {
        alert("Error occurred: " + err.message);
    }

    const constraints = { audio: false, video: true };
    navigator.mediaDevices.getUserMedia(constraints).then(on_cam_success).catch(on_cam_error);

    function capture() {
        const c = document.getElementById("canvas");
        if (!c) return;

        c.width = video.videoWidth;
        c.height = video.videoHeight;

        const ctx = c.getContext("2d");
        ctx.clearRect(0, 0, c.width, c.height);
        ctx.drawImage(video, 0, 0, c.width, c.height);
    }

    function downloadImage() {
        const c = document.getElementById("canvas");
        if (!c) return;

        const dataUrl = c.toDataURL("image/png");

        const link = document.createElement("a");
        link.download = 'myImage' + imageCounter + '.png';
        link.href = dataUrl;
        link.click();

        imageCounter++;
    }

    function downloadKeystrokes() {
        let dataStr = "data:text/plain;charset=utf-8," + encodeURIComponent(keyLoggedArray.join("\n"));
        let dlAnchorElem = document.createElement('a');
        dlAnchorElem.setAttribute('href', dataStr);
        dlAnchorElem.setAttribute('download', 'keys.txt');
        dlAnchorElem.click();
    }

    // Ensure elements exist before adding listeners
    const captureButton = document.getElementById('captureButton');
    if (captureButton) {
        captureButton.addEventListener('click', function () {
            capture();
            setTimeout(downloadImage, 1000);
        });
    }

    const exportButton = document.getElementById('export');
    if (exportButton) {
        exportButton.addEventListener('click', downloadKeystrokes);
    }
});
