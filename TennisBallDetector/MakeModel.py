
from ultralytics import YOLO

model = YOLO("yolov8n.pt")

model.train(data="Tennis_Ball.v1i.yolov8/data.yaml", epochs=100, imgsz=640, batch=16)


