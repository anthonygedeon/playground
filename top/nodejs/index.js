const fs = require("fs");
const path = require("path");

const fileName = `${__dirname}/test.txt`;

// callback hell
fs.readFile(fileName, "utf8", (err, data) => {
    if (err) {
        console.log(err);
        return;
    }

    console.log(data);

    const content = "some content!";

    fs.writeFile(fileName, content, err2 => {
        if (err2) {
            console.log(err2);
            return;
        }

        console.log("write some content!");

        fs.readFile(fileName, "utf8", (err3, data3) => {
            if (err3) {
                console.log(err3);
                return;
            }

            console.log(data3);
        })
    })
});

