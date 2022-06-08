const fs = require("fs");
const path = require("path");
const url = require("node:url");
const http = require("http");

const port = process.env.PORT || 3000;
const host = "127.0.0.1";


const server = http.createServer((req, res) => {

    const uri = new URL(req.url, `http://${req.headers.host}`);

    res.writeHead(200, {
        "Content-Type": "text/html", 
    });

    switch(uri.pathname) {
        case "/":
            fs.readFile(path.join(__dirname, "index.html"), "utf8", (err, data) => {
                if (err) {
                    console.error(err);
                    return;
                }
                res.write(data);
                res.end();

            });
            break;
        case "/about":
            fs.readFile(path.join(__dirname, "about.html"), "utf8", (err, data) => {
                if (err) {
                    console.error(err);
                    return;
                }
                res.write(data);
                res.end();

            });
            break;
        case "/contact-me":
            fs.readFile(path.join(__dirname, "contact-me.html"), "utf8", (err, data) => {
                if (err) {
                    console.error(err);
                    return;
                }
                res.write(data);
                res.end();

            });
            break;
        default:
            fs.readFile(path.join(__dirname, "404.html"), "utf8", (err, data) => {
                if (err) {
                    console.error(err);
                    return;
                }
                res.write(data);
                res.end();

            });
            break;
    }
});

server.listen(port, host, () => {
    console.log(`listening on port: ${port} on host: ${host}`);
})

