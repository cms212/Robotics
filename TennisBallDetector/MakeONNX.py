from ultralytics  import YOLO

model = YOLO("runs/detect/train/weights/best.pt")  # load a pretrained model (recommended for training)

model.export(format="onnx", opset=11, simplify=True, dynamic=False, imgsz=640)