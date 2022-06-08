const fs = require("fs/promises");
const path = require("path");
const url = require("node:url");
const http = require("http");

const port = process.env.PORT || 3000;
const host = "127.0.0.1";

async function handleRequest(res, document) {
    let fileData = await fs.readFile(path.join(__dirname, document), {encoding: "utf8"});
    res.write(fileData);
    res.end();
}

const server = http.createServer(async (req, res) => {

    const uri = new URL(req.url, `http://${req.headers.host}`);

    res.writeHead(200, {
        "Content-Type": "text/html", 
    });
    let fileData;
    switch(uri.pathname) {
        case "/":
            handleRequest(res, "index.html").catch((err) => console.error(err));
            break;
        case "/about":
            handleRequest(res, "about.html").catch((err) => console.error(err));
            break;
        case "/contact-me":
            handleRequest(res, "contact-me.html").catch((err) => console.error(err));
            break;
        default:
            handleRequest(res, "404.html").catch((err) => console.error(err));
            break;
    }
});

server.listen(port, host, () => {
    console.log(`listening on port: ${port} on host: ${host}`);
})

