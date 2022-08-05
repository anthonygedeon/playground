const fs = require("fs/promises");
const path = require("path");

const express = require("express");
const MongoClient = require("mongodb").MongoClient;
const logger = require("morgan");

const userRouter = express.Router();
const adminRouter = express.Router(); 
const productRouter = express.Router();

const square = require("./mod");

const app = express();
const port = 3000;

app.use(logger("dev"));

function middleware1(req, res, next) {
	console.log("middleware 1");
	next();
}

function middleware2(req, res, next) {
	console.log("middleware 2");
	next();
}

function middleware3(req, res, next) {
	console.log("middleware 3");
	next();
}

app.use(middleware1);
app.use(middleware2);
app.use(middleware3);

app.use(express.static("public"));

app.set("views", path.join(__dirname, "views"));
app.set("view engine", "jade");

console.log(`path ${__dirname}`);

app.use((err, req, res, next) => {
	console.error(err.stack);
	res.status(500).send("Something broke!");
});

adminRouter.get("/", (req, res) => {
	res.send("admin page");
});

adminRouter.get("/login", (req, res) => {
	res.send("admin login page");
});

adminRouter.get("/sign-up", (req, res) => {
	res.send("admin sign up page");
});

userRouter.get("/", (req, res) => {
	console.log("user page");
});

userRouter.get("/:id", (req, res) => {
	console.log("user :id page");
});

userRouter.get("/details", (req, res) => {
	console.log("user details page");
});

productRouter.get("/", (req, res) => {
	console.log("product page");
});

productRouter.get("/:id", (req, res) => {
	console.log("id page");
});

productRouter.get("/shipping", (req, res) => {
	console.log("shipping page");
});

app.get("/", async (req, res) => {
	res.render("index");
});

app.all("/secret", (req, res, next) => {
	console.log("Accessing the secret section...");
	next();
});

app.use('/admin', adminRouter);
app.use('/user', userRouter);

app.listen(port, () => {
	console.log(`Example app listening on port ${port}!`);
});
