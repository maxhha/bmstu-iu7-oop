import path from "path"
import copy from "rollup-plugin-copy"
import resolve from "@rollup/plugin-node-resolve"
import commonjs from "@rollup/plugin-commonjs"
import typescript from "@rollup/plugin-typescript"

export default {
  input: path.resolve(__dirname, "script.ts"),
  output: {
    file: path.resolve(__dirname, "build", "bundle.js"),
    sourcemap: true,
  },
  plugins: [
    copy({
      targets: [
        {
          src: "lab01/model/build/modelManager.wasm",
          dest: "lab01/build",
        },
      ],
      verbose: true,
    }),
    typescript(),
    resolve(),
    commonjs(),
  ],
  watch: {
    exclude: [
      path.resolve(__dirname, "model", "src"),
      path.resolve(__dirname, "model", "inc"),
    ],
  },
}
