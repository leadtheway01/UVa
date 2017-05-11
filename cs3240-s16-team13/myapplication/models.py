from django.db import models
from django.contrib.auth.models import User, Group
from django.conf import settings
from django.utils import timezone
from django.utils.encoding import python_2_unicode_compatible

AUTH_USER_MODEL = getattr(settings, 'AUTH_USER_MODEL', 'auth.User')


# Create your models here.
"""User"""
class Category(models.Model):
    name = models.CharField(max_length=128, unique=True)

    def __str__(self):  #For Python 2, use __str__ on Python 3
        return self.name

class Page(models.Model):
    category = models.ForeignKey(Category)
    title = models.CharField(max_length=128)
    url = models.URLField()
    views = models.IntegerField(default=0)

    def __str__(self):      #For Python 2, use __str__ on Python 3
        return self.title

class UserProfile(models.Model):
    user = models.OneToOneField(User)
    website = models.URLField(blank=True)
    picture = models.ImageField(upload_to='profile_images', blank=True)

    def __str__(self):
        return self.user.username


"""file"""
class Upload(models.Model):
   title = models.CharField(max_length=128, unique=False)
   short_description = models.CharField(max_length=128, null=True, blank=True)
   long_description = models.TextField(null=True, blank=True)
   file_1 = models.FileField(default='MEDIA_ROOT/', blank=True, null=True)
   encrypted_1 = models.BooleanField(default=False)
   file_2 = models.FileField(default='MEDIA_ROOT/', blank=True, null=True)
   encrypted_2 = models.BooleanField(default=False)
   file_3 = models.FileField(default='MEDIA_ROOT/', blank=True, null=True)
   encrypted_3 = models.BooleanField(default=False)
   user = models.CharField(max_length=128, unique=False)
   group = models.CharField(max_length=128)
   folder=models.ForeignKey('Folder', blank=True, null=True)
   time = models.DateTimeField(default=timezone.now)
   private = models.BooleanField()
   counter = models.IntegerField(default=0)
   #groups = models.ManyToManyField(Group)
   class Meta:
       permissions = (
           ('edit_report', 'Edit report'),
       )
   def __str__(self):
       return self.title

"""folder"""
class Folder(models.Model):
   title = models.CharField(max_length=50, unique=True)
   private = models.BooleanField(default=False)
   groups = models.ManyToManyField(Group)

   def __str__(self):
       return self.title

"""private message"""
class MessageManager(models.Manager):

    def inbox_for(self, user):

        return self.filter(
                recipient=user,
                recipient_deleted_at__isnull=True,
                )

    def outbox_for(self, user):

        return self.filter(
                sender=user,
                sender_deleted_at__isnull=True,
                )

    def trash_for(self, user):

        return self.filter(
            recipient=user,
            recipient_deleted_at__isnull=False,
            ) | self.filter (
                sender=user,
                sender_deleted_at__isnull=False,
                )

    def inbox_count(self, user):
        return Message.objects.filter(recipient=user, read_at__isnull=True, recipient_deleted_at__isnull=True).count()

    def unread_messages(self, user):
        return Message.objects.filter(read_at__isnull=False).count()

class Message(models.Model):
    subject = models.CharField(("Subject"), max_length=120)
    body = models.CharField(("Body"), max_length=300)
    sender = models.ForeignKey(AUTH_USER_MODEL, related_name='sent_messages', verbose_name=("Sender"))
    recipient = models.ForeignKey(AUTH_USER_MODEL, related_name='received_messages', verbose_name=("Recipient"))
    #parent_msg = models.ForeignKey('self', related_name='next_messages', null=True, blank=True, verbose_name=("Next Message"))
    sent_at = models.DateTimeField(("sent at"), null=True, blank=True)
    read_at = models.DateTimeField(("read at"), null=True, blank=True)
    replied_at = models.DateTimeField(("replied at"), null=True, blank=True)
    sender_deleted_at = models.DateTimeField(("Sender deleted at"), null=True, blank=True)
    recipient_deleted_at = models.DateTimeField(("Recipient deleted at"), null=True, blank=True)
    
    objects = MessageManager()

    def new(self):
        if self.read_at is not None:
            return False
        return ('received_messages',True)

    def replied(self):
        if self.replied_at is not None:
            return True
        return False

    def __str__(self):
        return self.subject

    def get_absolute_url(self):
        return ('messages_detail', [self.id])
    get_absolute_url = models.permalink(get_absolute_url)

    def save(self, **kwargs):
        if not self.id:
            self.sent_at = timezone.now()
        super(Message, self).save(**kwargs)

    class Meta:
        ordering = ['-sent_at']
        verbose_name = ("Message")
        verbose_name_plural = ("Messages")

class KeyUpload(models.Model):
    #title = models.CharField(max_length=128, unique=False)
    #short_description = models.CharField(max_length=128, null=True, blank=True)
    #long_description = models.TextField(null=True, blank=True)
    file = models.FileField(default='MEDIA_ROOT/', blank=True, null=True)
    # user = models.OneToOneField(User)
    #groups = models.ManyToManyField(Group)

    def __str__(self):
        return self.title