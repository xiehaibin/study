#!/usr/bin/env python
# coding=utf-8
import flask

app = flask.Flask(__name__)


html_txt = """
<!DOCTYPE html>
<html>
    <body>
        <h5>GET</h5>
        <form method = "post">
        <input type = "text" name = "name" placeholder = "input">
        <input type = "submit" value = "Save POST"/>
        </form>
    </body>
</html>
"""

@app.route("/helo", methods = ["GET", "POST"])
def helo():
    if flask.request.method == "GET":
        return html_txt
    else:
        #print(name)
        name = "name" in flask.request.form and flask.request.form["name"]
        if name:
            return "I is " + name
        return "NO INPUT"



@app.route("/helo")
def helo():
#return "aaa"
    return flask.render_template('index.html')

if __name__ == "__main__":
    app.run()
