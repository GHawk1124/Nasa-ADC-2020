import numpy as np 
import colorsys
import cv2

a = np.array([100,0,0]) # Point one with x=0,y=0-max and rgb value
b =  np.array([0,255,0]) # point two with x=max,y=0-max and rgb value
#in this case i loop from y=0 to y=max for corresponding point on the other side of drawing space - that is x=max
a = a[::-1]
b= b[::-1]
leds = 31 # just constant
h_color=100 # height of drawing space
t_lengt = (600/leds)*leds #recalculation of width (because I need integer)
vector = (b-a)*1.0/t_lengt

arr_texture = np.zeros(shape=[h_color, t_lengt, 3], dtype=np.uint8) #drawing space defined by x,y and 3d value

for i in range(t_lengt): # loop for all points in x=0 to x=max (that is y=0 to max)
    for j in range(h_color):

        arr_texture[j][i]=[a[0]+vector[0]*i,a[1]+vector[1]*i,a[2]+vector[2]*i]


cv2.imwrite('color_img.jpg', arr_texture)
cv2.imshow("image", arr_texture);
cv2.waitKey(0)
cv2.destroyAllWindows()