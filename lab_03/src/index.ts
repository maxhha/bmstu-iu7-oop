import createModelManager from "../engine/build/render";

fetch("build/render.wasm")
  .then(resp => resp.arrayBuffer())
  .then(wasmBinary => createModelManager({ wasmBinary }))
  .then(({ Engine, RenderCommand }) => {
    const engine = new Engine("#render");
    const render = new RenderCommand(engine);

    requestAnimationFrame(() => {
        render.execute()
    });
});
