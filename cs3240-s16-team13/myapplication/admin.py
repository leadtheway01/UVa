from django.contrib import admin
from myapplication.models import UserProfile, Upload, Message

admin.site.register(UserProfile)
admin.site.register(Upload)
admin.site.register(Message)
#admin.site.register(Linker)
# Register your models here.