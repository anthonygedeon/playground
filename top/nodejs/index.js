const fs = require("fs/promises");

async function example() {
    const fileName = `${__dirname}/test.txt`;

    try {
        const data = await fs.readFile(fileName, "utf8");
        console.log(data);

        const content = "My booboo hit the floor";
        await fs.writeFile(fileName, content);
        console.log("Wrote some content");

        const newData = await fs.readFile(fileName, "utf8");
        console.log(newData);
    } catch (err) {
        console.log(err);
    }
}

example();
