import numpy as np
import cv2

cap = cv2.VideoCapture()
cap.open("rtsp://username:password@0.0.0.0:123/100")

idx = 0
while(cap.isOpened()):
     # Capture frame-by-frame
    ret, frame = cap.read()

    # Our operations on the frame come here
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    cv2.imshow('frame',frame)
    print(ret)
    #cv2.imwrite("img" + str(idx) + ".png", frame)
    #idx = idx+1
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
