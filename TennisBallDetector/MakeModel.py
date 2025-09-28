
from ultralytics import YOLO

model = YOLO("yolov8n.pt")  # load a pretrained model (recommended for training)

#train on a new dataset with paramters need for onnx export
model.train(data="Tennis_Ball.v1i.yolov8/data.yaml", epochs=100, imgsz=640, batch=16)


