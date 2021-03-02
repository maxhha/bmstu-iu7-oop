import p5 from "p5"
import createModelManager from "./model/build/modelManager"

function scetch(
  $: p5,
  { requestModelManager, ManagerRequest, RequestType, ManagerResponce, ...rest }
) {
  function onClickLoadModel() {
    const resp = requestModelManager({ type: RequestType.LOAD })
    console.log(resp, resp === ManagerResponce.OK)
  }

  $.windowResized = () => {
    const size: any = $.select("#canvas-container").size()
    $.resizeCanvas(size.width, size.height)
  }

  $.setup = () => {
    $.windowResized()
    $.noLoop()
    $.select("#load-model").mouseClicked(onClickLoadModel)
  }
}

createModelManager().then(
  (manager) =>
    new p5(
      ($) => scetch($, manager),
      document.getElementById("canvas-container")
    )
)
