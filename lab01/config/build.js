require("dotenv").config();
const child_process = require("child_process");
const path = require("path");
const fs = require("fs");

const pathSrc = path.resolve(__dirname, "..", "model", "src");

child_process.exec(
  [
    process.env.EMCC_COMMAND,
    "-I" + path.resolve(__dirname, "..", "model", "inc"),
    "-o",
    path.resolve(__dirname, "..", "model", "build", "modelManager.js"),
    "-Oz",
    "-s MODULARIZE=1",
    "-s EXPORT_NAME=createModelManager",
    "-s ENVIRONMENT=web",
    "--bind",
    ...fs.readdirSync(pathSrc).map((x) => path.resolve(pathSrc, x)),
  ].join(" "),
  (error, stdout, stderr) => {
    if (error) return console.error(error);
    if (stdout) console.log(stdout);
    if (stderr) console.error(stderr);
  }
);
