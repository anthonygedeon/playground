const fs = require("fs/promises");
const path = require("path");
const url = require("node:url");
const http = require("http");

const port = process.env.PORT || 3000;
const host = "127.0.0.1";

const server = http.createServer(async (req, res) => {

    const uri = new URL(req.url, `http://${req.headers.host}`);

    res.writeHead(200, {
        "Content-Type": "text/html", 
    });
    switch(uri.pathname) {
        case "/":
            fileData = await fs.readFile(path.join(__dirname, "index.html"), {encoding: "utf8"});
            res.write(fileData);
            res.end()
            break;
        case "/about":
            fileData = await fs.readFile(path.join(__dirname, "about.html"), {encoding: "utf8"});
            res.write(fileData);
            res.end()
            break;
        case "/contact-me":
            fileData = await fs.readFile(path.join(__dirname, "contact-me.html"), {encoding: "utf8"});
            res.write(fileData);
            res.end()
            break;
        default:
            fileData = await fs.readFile(path.join(__dirname, "404.html"), {encoding: "utf8"});
            res.write(fileData);
            res.end()
            break;
    }
});

server.listen(port, host, () => {
    console.log(`listening on port: ${port} on host: ${host}`);
})

