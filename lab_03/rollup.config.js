import path from "path";
import copy from "rollup-plugin-copy";
import resolve from "@rollup/plugin-node-resolve";
import commonjs from "@rollup/plugin-commonjs";
import typescript from "@rollup/plugin-typescript";
import replace from "@rollup/plugin-replace";

export default {
  input: path.resolve(__dirname, "src/index.ts"),
  output: {
    file: path.resolve(__dirname, "build", "bundle.js"),
    sourcemap: true,
  },
  plugins: [
    copy({
      targets: [
        {
          src: "lab_03/engine/build/render.wasm",
          dest: "lab_03/build",
        },
      ],
      verbose: true,
    }),
    typescript({ target: "esnext", jsx: "react" }),
    replace({
      "process.env.NODE_ENV": JSON.stringify("development"),
    }),
    resolve(),
    commonjs(),
  ],
  watch: {
    exclude: [
      path.resolve(__dirname, "engine/src"),
      path.resolve(__dirname, "engine/inc"),
    ],
  },
};
