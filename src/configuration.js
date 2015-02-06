Pebble.addEventListener("ready", function(e) {
    console.log("PebbleKit JS ready!");
});

Pebble.addEventListener("showConfiguration", function(e) {
    //Load the remote config page
    Pebble.openURL("https://dl.dropboxusercontent.com/s/8ll1yn8ecd2lzwc/shadow.html");
});

Pebble.addEventListener("webviewclosed", function(e) {
    //Get JSON dictionary
    var configuration = JSON.parse(decodeURIComponent(e.response));
    console.log("Configuration window returned: " + JSON.stringify(configuration));

    //Send to Pebble, persist there
    Pebble.sendAppMessage({"HORIZONTAL_SHADOW": configuration.shadow},
        function(e) {
            console.log("Sending settings data...");
        },
        function(e) {
            console.log("Settings feedback failed!");
        });
});
