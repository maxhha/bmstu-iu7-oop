import M from "minimatch";
import createModelManager from "./model/build/modelManager";

createModelManager().then(({ requestModelManager, ManagerResponce }) => {
  console.log(requestModelManager());
});
