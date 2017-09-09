flask文件的上传和下载

from werkzeug.utils import secure_filename
from flask import Flask,render_template,jsonify,request
import time
import os
import base64
 
app = Flask(__name__)
UPLOAD_FOLDER='upload'
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
basedir = os.path.abspath(os.path.dirname(__file__))
ALLOWED_EXTENSIONS = set(['txt','png','jpg','xls','JPG','PNG','xlsx','gif','GIF'])
 
# 用于判断文件后缀
def allowed_file(filename):
    return '.' in filename and filename.rsplit('.',1)[1] in ALLOWED_EXTENSIONS
 
# 用于测试上传，稍后用到
@app.route('/test/upload')
def upload_test():
    return render_template('upload.html')
 
# 上传文件
@app.route('/api/upload',methods=['POST'],strict_slashes=False)
def api_upload():
    file_dir=os.path.join(basedir,app.config['UPLOAD_FOLDER'])
    if not os.path.exists(file_dir):
        os.makedirs(file_dir)
    f=request.files['myfile']  # 从表单的file字段获取文件，myfile为该表单的name值
    if f and allowed_file(f.filename):  # 判断是否是允许上传的文件类型
        fname=secure_filename(f.filename)
        print fname
        ext = fname.rsplit('.',1)[1]  # 获取文件后缀
        unix_time = int(time.time())
        new_filename=str(unix_time)+'.'+ext  # 修改了上传的文件名
        f.save(os.path.join(file_dir,new_filename))  #保存文件到upload目录
        token = base64.b64encode(new_filename)
        print token
 
        return jsonify({"errno":0,"errmsg":"上传成功","token":token})
    else:
        return jsonify({"errno":1001,"errmsg":"上传失败"})
 
if __name__ == '__main__':
    app.run(debug=True)
上面我们写了一个上传接口，我们为了测试这个接口是否工作正常，还得写一个页面（upload.html）：


<form id="form1" method="post" action="/api/upload" enctype="multipart/form-data">
    <div>
        <input id="File1" type="file" name="myfile"/>
        <input type="submit">提交</input>
    </div>
</form>
好了，页面也写完了，我们运行flask服务后，可以访问到http://127.0.0.1/test/upload页面，上传文件并提交后，我们的接口会返回如下信息：

{
  "errmsg": "\u4e0a\u4f20\u6210\u529f",
  "errno": 0,
  "token": "MTQ2MzU4MDc5Mi5KUEc="
}
同时upload目录中也有了刚上传的文件，表明测试成功。

文件下载
文件下载要比上传简单的多，核心代码如下：


from flask import request,jsonify,send_from_directory,abort
import os
 
def download(filename):
    if request.method=="GET":
        if os.path.isfile(os.path.join('upload', filename)):
            return send_from_directory('upload',filename,as_attachment=True)
        abort(404)
这里主要需要注意的是send_from_directory方法，经过实测，需加参数as_attachment=True，否则对于图片格式、txt格式，会把文件内容直接显示在浏览器，对于xlsx等格式，虽然会下载，但是下载的文件名也不正确，切记切记
