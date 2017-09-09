flask�ļ����ϴ�������

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
 
# �����ж��ļ���׺
def allowed_file(filename):
    return '.' in filename and filename.rsplit('.',1)[1] in ALLOWED_EXTENSIONS
 
# ���ڲ����ϴ����Ժ��õ�
@app.route('/test/upload')
def upload_test():
    return render_template('upload.html')
 
# �ϴ��ļ�
@app.route('/api/upload',methods=['POST'],strict_slashes=False)
def api_upload():
    file_dir=os.path.join(basedir,app.config['UPLOAD_FOLDER'])
    if not os.path.exists(file_dir):
        os.makedirs(file_dir)
    f=request.files['myfile']  # �ӱ���file�ֶλ�ȡ�ļ���myfileΪ�ñ���nameֵ
    if f and allowed_file(f.filename):  # �ж��Ƿ��������ϴ����ļ�����
        fname=secure_filename(f.filename)
        print fname
        ext = fname.rsplit('.',1)[1]  # ��ȡ�ļ���׺
        unix_time = int(time.time())
        new_filename=str(unix_time)+'.'+ext  # �޸����ϴ����ļ���
        f.save(os.path.join(file_dir,new_filename))  #�����ļ���uploadĿ¼
        token = base64.b64encode(new_filename)
        print token
 
        return jsonify({"errno":0,"errmsg":"�ϴ��ɹ�","token":token})
    else:
        return jsonify({"errno":1001,"errmsg":"�ϴ�ʧ��"})
 
if __name__ == '__main__':
    app.run(debug=True)
��������д��һ���ϴ��ӿڣ�����Ϊ�˲�������ӿ��Ƿ�������������дһ��ҳ�棨upload.html����


<form id="form1" method="post" action="/api/upload" enctype="multipart/form-data">
    <div>
        <input id="File1" type="file" name="myfile"/>
        <input type="submit">�ύ</input>
    </div>
</form>
���ˣ�ҳ��Ҳд���ˣ���������flask����󣬿��Է��ʵ�http://127.0.0.1/test/uploadҳ�棬�ϴ��ļ����ύ�����ǵĽӿڻ᷵��������Ϣ��

{
  "errmsg": "\u4e0a\u4f20\u6210\u529f",
  "errno": 0,
  "token": "MTQ2MzU4MDc5Mi5KUEc="
}
ͬʱuploadĿ¼��Ҳ���˸��ϴ����ļ����������Գɹ���

�ļ�����
�ļ�����Ҫ���ϴ��򵥵Ķ࣬���Ĵ������£�


from flask import request,jsonify,send_from_directory,abort
import os
 
def download(filename):
    if request.method=="GET":
        if os.path.isfile(os.path.join('upload', filename)):
            return send_from_directory('upload',filename,as_attachment=True)
        abort(404)
������Ҫ��Ҫע�����send_from_directory����������ʵ�⣬��Ӳ���as_attachment=True���������ͼƬ��ʽ��txt��ʽ������ļ�����ֱ����ʾ�������������xlsx�ȸ�ʽ����Ȼ�����أ��������ص��ļ���Ҳ����ȷ���м��м�
