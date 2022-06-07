const EventEmiiter = require("events");

const eventEmitter = new EventEmiiter();

eventEmitter.on("start", (start, end) => {
    for (let i = start; i < end; i++) {
        console.log(`number ${i}`);
    }
});

eventEmitter.emit("start", 0, 5);

eventEmitter.once("once", () => console.log("only once"));

eventEmitter.emit("once");


eventEmitter.off("start", () => console.log("end connection!"));

console.log(eventEmitter);

