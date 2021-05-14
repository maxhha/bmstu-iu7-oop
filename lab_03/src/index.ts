import createModelManager from "../engine/build/render";

createModelManager().then(({ Engine }) => {
  const engine = new Engine("#render");
  requestAnimationFrame(() => {
    engine.render();
  });
});
