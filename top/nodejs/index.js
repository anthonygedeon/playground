const fs = require("fs");
const path = require("path");

const content = "Some content!";

fs.writeFile(path.join(__dirname, "test.txt"), content, err => {
        if (err) {
                console.error(err);
        }

})
