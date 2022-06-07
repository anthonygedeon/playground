const https = require("https");

const options = {
        hostname: "example.com",
        port: 443, 
        path: "/todos",
        method: "GET", 
};

const req = https.request(options, res => {
    console.log(`status code: ${res.statusCode}`);

    res.on('data', d => {
        process.stdout.write(d);
    });
});

req.on("error", error => {
        console.log(error);
});

req.end();
