# !/usr/bin/env python
# coding=utf-8
import flask

from flask import request,jsonify,send_from_directory,abort
import os

app = flask.Flask(__name__)

@app.route("/_get", methods = ["GET"])
def _get():
    print("GET")
    return flask.render_template("download.html")

@app.route("/get_info")
def get_info():
        print("开始下载")
        #response = make_response(send_file("Jinja2-2.9.5.tar"))
        #response.headers["Content-Disposition"] = "attachment, filename=Jinja2-2.9.5.tar"
        #return response
        
        if os.path.isfile(os.path.join('pake', "Jinja2-2.9.5.tar")):
            return send_from_directory('pake', "Jinja2-2.9.5.tar", as_attachment=True)

if __name__ == "__main__":
    app.run("192.168.2.136")
    
