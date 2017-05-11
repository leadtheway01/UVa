from django import forms
from django.contrib.auth.models import User, Group
from myapplication.models import UserProfile, Category, Page, Upload, Message, MessageManager, KeyUpload, Folder
from myapplication.fields import *
from django.utils import timezone

from Crypto.PublicKey import RSA
from Crypto import Random
import base64

"""user"""
class UserForm(forms.ModelForm):
    password = forms.CharField(widget=forms.PasswordInput())

    class Meta:
        model = User
        fields = ('username', 'email', 'password')


class UserProfileForm(forms.ModelForm):
    class Meta:
        model = UserProfile
        fields = ('website', 'picture')


"""group"""
class CreateGroupForm(forms.ModelForm):
    class Meta:
        model = Group
        fields = ('name',)


class AddToGroupForm(forms.Form):
    username = forms.CharField(max_length=20)
    group = forms.CharField(max_length=20)


class UploadFileForm(forms.ModelForm):
   class Meta:
       model = Upload
       title = forms.CharField(max_length=50)
       group = forms.CharField(max_length=50)
       folder = forms.CharField(max_length=50, required=False)
       short_description = forms.CharField(max_length=50)
       long_description = forms.Textarea()
       file_1 = forms.FileField(required=False)
       encrypted_1 = forms.BooleanField()
       file_2 = forms.FileField(required=False)
       encrypted_2 = forms.BooleanField()
       file_3 = forms.FileField(required=False)
       encrypted_3 = forms.BooleanField()
       private = forms.BooleanField()
       fields = ('title', 'group', 'folder', 'short_description', 'long_description', 'private', 'file_1', 'encrypted_1','file_2', 'encrypted_2', 'file_3', 'encrypted_3')

"""site manager"""
class SMForm(forms.Form):
    password = forms.CharField(widget=forms.PasswordInput())

    class Meta:
        model = User
        fields = ('username', 'email', 'password',)

class suspendUserForm(forms.Form):
        username = forms.CharField(max_length=20)

class enableUserForm(forms.Form):
        username = forms.CharField(max_length=20)

class removeUserForm(forms.Form):
        username = forms.CharField(max_length=20)
        group = forms.CharField(max_length=20)

"""folder"""
class CreateFolderForm(forms.ModelForm):
   class Meta:
       model = Folder
       title = forms.CharField(max_length=20, required=True)
       private = forms.BooleanField(widget=forms.CheckboxInput, initial=False, required=False)
       groups = forms.BooleanField(widget=forms.CheckboxSelectMultiple, required=False)
       fields = ('title', 'private', 'groups')

 
class RemoveFolderForm(forms.Form):
    title = forms.CharField(max_length=20)

class RenameFolderForm(forms.Form):
   old_title = forms.CharField(max_length=20)
   new_title = forms.CharField(max_length=20)

"""private message"""
class ComposeForm(forms.Form):
    recipient = CommaSeparatedUserField(label=(u"To"), widget=forms.Textarea(attrs={'rows': '1', 'cols':'60'}))
    subject = forms.CharField(label=(u"Subject"), max_length=128, widget=forms.Textarea(attrs={'rows': '1', 'cols':'60'}))
    body = forms.CharField(label=(u"Body"), widget=forms.Textarea(attrs={'rows': '18', 'cols':'60'}))

    def __init__(self, *args, **kwargs):
        recipient_filter = kwargs.pop('recipient_filter', None)
        super(ComposeForm, self).__init__(*args, **kwargs)
        if recipient_filter is not None:
            self.fields['recipient']._recipient_filter = recipient_filter
    
                
    def save(self, sender, enc, parent_msg=None):
        recipients = self.cleaned_data['recipient']
        subject = self.cleaned_data['subject']
        body = self.cleaned_data['body']
        message_list = []

        for r in recipients:
            msg = Message(
                sender = sender,
                recipient = r,
                subject = subject,
                body = body,
            )
            if parent_msg is not None:
                msg.parent_msg = parent_msg
                parent_msg.replied_at = timezone.now()
                parent_msg.save()
            msg.save()
            message_list.append(msg)

        return message_list


class EncryptComposeForm(forms.Form):
    recipient = CommaSeparatedUserField(label=(u"To"), widget=forms.Textarea(attrs={'rows': '1', 'cols':'60'}))
    subject = forms.CharField(label=(u"Subject"), max_length=128, widget=forms.Textarea(attrs={'rows': '1', 'cols':'60'}))
    body = forms.CharField(label=(u"Body"), widget=forms.Textarea(attrs={'rows': '18', 'cols':'60'}))

    def __init__(self, *args, **kwargs):
        recipient_filter = kwargs.pop('recipient_filter', None)
        super(EncryptComposeForm, self).__init__(*args, **kwargs)
        if recipient_filter is not None:
            self.fields['recipient']._recipient_filter = recipient_filter
        
    def save(self, sender, parent_msg=None):
        recipients = self.cleaned_data['recipient']
        subject = self.cleaned_data['subject']
        body = self.cleaned_data['body']
        message_list = []

        random_generator = Random.new().read
        key = RSA.generate(1024, random_generator)

        bytes_obj = body.encode()
        enc_data = key.encrypt(bytes_obj, 32)
        body = enc_data[0]
        body =base64.b64encode(body)
        privateKey = key.exportKey()
        
        f = open("privateKey.txt", 'wb')
        f.write(privateKey)
        f.close()
        
        for r in recipients:
            msg = Message(
                sender = sender,
                recipient = r,
                subject = subject,
                body = body,
            )
            if parent_msg is not None:
                msg.parent_msg = parent_msg
                parent_msg.replied_at = timezone.now()
                parent_msg.save()
            msg.save()
            message_list.append(msg)

        return message_list

class UploadKeyFileForm(forms.ModelForm):
    class Meta:
        model = KeyUpload
        file = forms.FileField(required=False)
        fields = ('file',)