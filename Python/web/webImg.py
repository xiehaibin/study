#!/usr/bin/env python
# coding=utf-8
import flask

app = flask.Flask(__name__)

@app.route("/helo")
def helo():
    return flask.render_template('index.html')

if __name__ == "__main__":
    app.run()
