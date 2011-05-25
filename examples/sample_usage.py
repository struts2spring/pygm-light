import ctypes
import gm_wrap
import sys

gm_wrap.InitializeMagick(sys.argv[0]);
exception = ctypes.pointer(gm_wrap.ExceptionInfo())
gm_wrap.GetExceptionInfo(exception)

image_info = gm_wrap.CloneImageInfo(None)
image_info.contents.filename = "03.jpg"

image = gm_wrap.ReadImage(image_info, exception)
image = gm_wrap.EnhanceImage(image, exception)
gm_wrap.NormalizeImage(image, exception)
image = gm_wrap.ResizeImage(image, 1000, 1000, gm_wrap.LanczosFilter, 1, exception)

pixels = gm_wrap.GetImagePixels(image, 0, 0, 1000, 1000)
print pixels[0].red
print pixels[1].red

image.contents.filename = "04.jpg"
gm_wrap.WriteImage(image_info, image)







