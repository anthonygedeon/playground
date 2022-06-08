const fs = require("fs/promises");
const path = require("path");
const url = require("node:url");
const http = require("http");

const PORT = process.env.PORT || 3000;
const HOST = "127.0.0.1";

/** Handles the request from the web server and serves the correct html document.
 * @param res - the response object from the web server.
 * @param doc - the HTML document that will be served back to the web
 * server.
 */
async function handleRequest(res, doc) {
    let data = await fs.readFile(path.join(__dirname, doc), {encoding: "utf8"});
    res.write(data);
    res.end();
}

const server = http.createServer(async (req, res) => {

    const uri = new URL(req.url, `http://${req.headers.host}`);

    res.writeHead(200, { "Content-Type": "text/html" });

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

server.listen(PORT, HOST, () => {
    console.log(`listening on port: ${PORT} on host: ${HOST}`);
})

