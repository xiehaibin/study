# coding=utf-8
import flask

app = flask.Flask(__name__)

@app.route("/upload", methods = ["GET", "POST"])
def upload():
    if flask.request.method == "GET":
        return flask.render_template("upload.html")
    else:
        file = flask.request.files["file"]
        if file:
            file.save("pake/"+file.filename)
            return "上传成功"

if __name__ == "__main__":
    app.run()
