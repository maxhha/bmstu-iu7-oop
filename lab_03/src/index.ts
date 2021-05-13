import createModelManager from "../engine/build/render";

createModelManager().then(({ requestModelManager, ManagerResponce }) => {
  console.log(requestModelManager());
});
