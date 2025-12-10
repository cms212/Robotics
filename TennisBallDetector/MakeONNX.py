from ultralytics  import YOLO

model = YOLO("runs/detect/train/weights/best.pt")

model.export(format="onnx", opset=11, simplify=True, dynamic=False, imgsz=640)