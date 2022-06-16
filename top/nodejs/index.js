const path = require("path");

const express = require("express");
const app = express();

const port = process.env.PORT || 3000;

function requestFile(doc) {
	return path.join(__dirname, doc);
}

app.get("/", (req, res) => {
	res.status(200).sendFile(requestFile("index.html"));
});

app.get("/about", (req, res) => {
	res.status(200).sendFile(requestFile("about.html"));
});

app.get("/contact-me", (req, res) => {
	res.status(200).sendFile(requestFile("contact-me.html"));
});

app.use((req, res, next) => {
	res.status(404).sendFile(requestFile("404.html"));
});

app.listen(port, () => {
    console.log(`listening on 127.0.0.1:${port}`);
})

