#include "torch-onnx/transforms/passes.h"

namespace torch_onnx {

void registerConversionPasses() {
  mlir::PassPipelineRegistration<
      mlir::torch::Torch::TorchLoweringPipelineOptions>(
      "torch-backend-to-onnx-backend-pipeline",
      "Pipeline lowering torch backend contract to ONNX backend "
      "contract.",
      createTorchBackendToOnnxBackendPipeline);
}

void createTorchBackendToOnnxBackendPipeline(
    OpPassManager &pm,
    const mlir::torch::Torch::TorchLoweringPipelineOptions &options) {
  // Check some invariants to catch errors in a clear way.
  pm.addPass(mlir::torch::TorchConversion::
                 createVerifyInvariantsBeforeBackendLoweringPass());

  //   pm.addNestedPass<FuncOp>(createConvertTorchToTosaPass());
  //   // Perform rank broadcasting so TosaToLinalg pass works
  //   pm.addNestedPass<FuncOp>(createTosaMakeBroadcastablePass());

  //   if (options.optimize) {
  //     // Clean up any non-canonical code introduced above..
  //     pm.addNestedPass<FuncOp>(createCanonicalizerPass());
  //     // The resolution of `dim` ops tends to create identical ops. CSE them.
  //     pm.addNestedPass<FuncOp>(createCSEPass());
  //   }

  //   // Finish the type conversion from `torch` types to the types of the
  //   // TOSA backend contract.
  //   pm.addPass(TorchConversion::createFuncBackendTypeConversionPass());
  //   pm.addNestedPass<FuncOp>(
  //       TorchConversion::createFinalizingBackendTypeConversionPass());

  //   // Verify that we have lowered to the form that TOSA backends
  //   // expect. This fails compilation (signalPassFailure) if the IR is not in
  //   the
  //   // correct form.
  //   pm.addPass(TorchConversion::createVerifyTosaBackendContractPass());
}

} // namespace torch_onnx
