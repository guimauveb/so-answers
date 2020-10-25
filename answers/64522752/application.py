import json
import datetime

from flask import Flask, flash, jsonify, redirect, url_for, render_template
from flask import request, session, Markup, send_from_directory

from flask_wtf.csrf import generate_csrf

from werkzeug import secure_filename
from werkzeug.urls import url_parse

from tempfile import mkdtemp
from config import Config
from __init__ import application

@application.after_request
def after_request(response):

    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    response.headers['X-Content-Type-Options'] = 'nosniff'
    response.headers['X-Frame-Options'] = 'SAMEORIGIN'
    response.headers['X-XSS-Protection'] = '1; mode=block'

    return response

@application.route('/', methods=["GET", "POST"])
def index():

    return render_template('index.html')

