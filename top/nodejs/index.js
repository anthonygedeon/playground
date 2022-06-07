const fs = require("fs");
const path = require("path");

const content = "Some content!";

try {
        fs.writeFileSync(path.join(__dirname, "test.txt"), content)
} catch (err) {
        console.log(err);
}
