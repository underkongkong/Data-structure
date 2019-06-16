from tkinter import *
# 导入tkinter模块的所有内容

root = Tk()

# 创建一个文本Label对象
textLabel = Label(root,   # 将内容绑定在  root 初始框上面
                  text="您所下载的影片含有未成年人限制内容，\n请满18岁后再点击观看！",
                  justify=LEFT, # 用于 指明文本的 位置
                  padx=10)        #   限制 文本的 位置 , padx 是 x轴的意思 . 
textLabel.pack(side=LEFT)   # 致命 textlabel 在初识框 中的位置

# 创建一个图像Label对象
# 用PhotoImage实例化一个图片对象（支持gif格式的图片）
photo = PhotoImage(file="18.gif")
imgLabel = Label(root, image=photo)  # 绑定在初始旷上面 
imgLabel.pack(side=RIGHT)  # 指明 图片位置

mainloop()