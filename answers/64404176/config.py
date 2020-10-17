import os
from tempfile import mkdtemp

class Config(object):

    # Main config
    SECRET_KEY = 'f6e7afe4643e273d54440ce81bcd13cc2d9feb8bd4261c2c'
    SECURITY_PASSWORD_SALT = '142ef85f197e7bf66738c271472cc52d'
    TEMPLATES_AUTO_RELOAD = True
    SEND_FILE_MAX_AGE_DEFAULT = 0
    DEBUG = False
    SESSION_FILE_DIR = mkdtemp()
    SESSION_PERMANENT = False
    SESSION_TYPE = "filesystem"
    PERMANENT_SESSION_LIFETIME = 600

    # Set cookies options
    SESSION_COOKIE_SECURE = False
    REMEMBER_COOKIE_SECURE = True
    SESSION_COOKIE_HTTPONLY = True
    REMEMBER_COOKIE_HTTPONLY = True
    SESSION_COOKIE_SAMESITE = 'Lax'


