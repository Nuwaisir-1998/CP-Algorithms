'''
Created on Apr 3, 2016

@author: Bill BEGUERADJ
'''
import cv2
import numpy as np 

drawing = False # true if mouse is pressed
mode = True # if True, draw rectangle. Press 'm' to toggle to curve

coords = ""

labels = ['WM', 'L1', 'L2', 'L3', 'L4', 'L5', 'L6', 'Background']
layer_colors = {
          'WM': (120, 116, 116),
          'L1': (255, 0, 0),
          'L2': (0, 255, 0),
          'L3': (0, 0, 255),
          'L4': (247, 223, 136),
          'L5': (237, 64, 208),
          'L6': (0, 136, 255),
          'Background': (255, 255, 255),
          }
label_idx = 0
paint_brush_size = 3

dlpfc_sample = '151670'

coords_int = set()

# mouse callback function
def begueradj_draw(event,former_x, former_y, flags, param):
    global current_former_x, current_former_y, drawing, mode, f, coords, label_idx, paint_brush_size

    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        current_former_x, current_former_y = former_x, former_y
        # print(current_former_x, current_former_y)
        # coords += str(current_former_x) + ',' +  str(current_former_y) + ',' + str(label_idx) + '\n'
        coords_int.add((current_former_x, current_former_y, label_idx))
        # f.write(str(current_former_x) + ',' +  str(current_former_y) + '\n')


    elif event==cv2.EVENT_MOUSEMOVE:
        if drawing==True:
            if mode==True:
                cv2.line(im, (current_former_x, current_former_y), (former_x,former_y), layer_colors[labels[label_idx]], paint_brush_size)
                current_former_x = former_x
                current_former_y = former_y
                # print(current_former_x, current_former_y)
                # coords += str(current_former_x) + ',' +  str(current_former_y)  + ',' + str(label_idx) + '\n'
                # coords_int.add((current_former_x, current_former_y, label_idx))
                at_x = current_former_x
                at_y = current_former_y
                for i in range(at_x - paint_brush_size, at_x + paint_brush_size + 1):
                    for j in range(at_y - paint_brush_size, at_y + paint_brush_size + 1):
                        coords_int.add((i, j, label_idx))

    elif event==cv2.EVENT_LBUTTONUP:
        drawing=False
        if mode==True:
            cv2.line(im, (current_former_x, current_former_y), (former_x, former_y), layer_colors[labels[label_idx]], paint_brush_size)
            current_former_x = former_x
            current_former_y = former_y
            at_x = current_former_x
            at_y = current_former_y
            for i in range(at_x - paint_brush_size, at_x + paint_brush_size + 1):
                for j in range(at_y - paint_brush_size, at_y + paint_brush_size + 1):
                    coords_int.add((i, j, label_idx))
    elif event == cv2.EVENT_RBUTTONDOWN:
        label_idx += 1
   
    return former_x, former_y

im = cv2.imread("Python_workspace/" + dlpfc_sample + "/manual_annotation_rounded.jpg")
print(im.shape)
cv2.namedWindow("Nuwaisir OpenCV")
cv2.setMouseCallback('Nuwaisir OpenCV', begueradj_draw)
while(1):
    cv2.imshow('Nuwaisir OpenCV', im)
    k = cv2.waitKey(1)&0xFF
    if k == 99:
        f = open("Python_workspace/" + dlpfc_sample + "/scribble_pixel_coordinates.csv", "w")
        f.write('imagecol,imagerow,cluster.init\n')
        for i in coords_int:
            coords += str(i[0]) + ',' + str(i[1]) + ',' + str(i[2]) + '\n'
        f.write(coords)
        f.close()
        break
    if k == 101:
        paint_brush_size += 1
    if k == 100:
        paint_brush_size -= 1
cv2.destroyAllWindows()