"""private message"""

import re
import django
from django.utils.text import wrap
from django.contrib.sites.models import Site
from django.template.loader import render_to_string
from django.conf import settings
from django.utils.translation import ugettext


if "mailer" in settings.INSTALLED_APPS:
    from mailer import send_mail
else:
    from django.core.mail import send_mail

#format for reply
def format_quote(sender, body):
    lines = wrap(body, 60).split('\n')
    for i, line in enumerate(lines):
        lines[i] = "> %s" % line
    quote = '\n'.join(lines)
    return ugettext(u"%(sender)s wrote:\n%(body)s") % {
        'sender': sender,
        'body': quote
    }

#format for subject. Prepends Re: in front of the subject
def format_subject(subject):
    subject_prefix_re = r'^Re\[(\d*)\]:\ '
    m = re.match(subject_prefix_re, subject, re.U)
    prefix = u""
    if subject.startswith('Re: '):
        prefix = u"[2]"
        subject = subject[4:]
    elif m is not None:
        try:
            num = int(m.group(1))
            prefix = u"[%d]" % (num+1)
            subject = subject[6+len(str(num)):]
        except:
            
            pass
        
    return ugettext(u"Re%(prefix)s: %(subject)s") % {
        'subject': subject, 
        'prefix': prefix
    }
    
def get_user_model():
    if django.VERSION[:2] >= (1, 5):
        from django.contrib.auth import get_user_model
        return get_user_model()
    else:
        from django.contrib.auth.models import User
        return User


def get_username_field():
    if django.VERSION[:2] >= (1, 5):
        return get_user_model().USERNAME_FIELD
    else:
        return 'username'