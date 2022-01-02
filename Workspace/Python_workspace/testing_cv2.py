import cv2
import numpy as np

height = 500
width = 500
blank_image = np.zeros((height, width, 3), np.uint8)
blank_image[:, 0:width//2] = (255, 0, 0)      # (B, G, R)
blank_image[:, width//2:width] = (0, 255, 0)

cv2.imshow('img', blank_image)
cv2.waitKey()

