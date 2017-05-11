import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'mysite.settings')

import django
django.setup()
from django.contrib.auth.models import Group, User, Permission

def create_SM():
    user = User.objects.create_user(username='siteManager',
                                 email='jjbleser@comcast.net',
                                 password='sitemanager')
    user.is_staff = False
    user.is_staff=True
    user.save()

if __name__ == '__main__':
    create_SM()