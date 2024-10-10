// Initialize the map and set its view to the specified location and zoom level
var map = L.map('map').setView([46.06879102602265, 23.572793150398642], 13);

// Add the OpenStreetMap tile layer to the map
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
}).addTo(map);

// Add a marker to the map at the same location
L.marker([46.06879102602265, 23.572793150398642]).addTo(map)
    .bindPopup('A simple marker popup.<br> Easily customizable.')
    .openPopup();
