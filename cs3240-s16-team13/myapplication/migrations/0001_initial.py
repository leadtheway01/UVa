# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
import django.utils.timezone
from django.conf import settings


class Migration(migrations.Migration):

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
        ('auth', '0006_require_contenttypes_0002'),
    ]

    operations = [
        migrations.CreateModel(
            name='Category',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('name', models.CharField(max_length=128, unique=True)),
            ],
        ),
        migrations.CreateModel(
            name='Folder',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('title', models.CharField(max_length=50, unique=True)),
                ('private', models.BooleanField(default=False)),
                ('groups', models.ManyToManyField(to='auth.Group')),
            ],
        ),
        migrations.CreateModel(
            name='KeyUpload',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('file', models.FileField(upload_to='', blank=True, default='MEDIA_ROOT/', null=True)),
            ],
        ),
        migrations.CreateModel(
            name='Message',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('subject', models.CharField(max_length=120, verbose_name='Subject')),
                ('body', models.CharField(max_length=300, verbose_name='Body')),
                ('sent_at', models.DateTimeField(verbose_name='sent at', blank=True, null=True)),
                ('read_at', models.DateTimeField(verbose_name='read at', blank=True, null=True)),
                ('replied_at', models.DateTimeField(verbose_name='replied at', blank=True, null=True)),
                ('sender_deleted_at', models.DateTimeField(verbose_name='Sender deleted at', blank=True, null=True)),
                ('recipient_deleted_at', models.DateTimeField(verbose_name='Recipient deleted at', blank=True, null=True)),
                ('recipient', models.ForeignKey(verbose_name='Recipient', to=settings.AUTH_USER_MODEL, related_name='received_messages')),
                ('sender', models.ForeignKey(verbose_name='Sender', to=settings.AUTH_USER_MODEL, related_name='sent_messages')),
            ],
            options={
                'verbose_name': 'Message',
                'ordering': ['-sent_at'],
                'verbose_name_plural': 'Messages',
            },
        ),
        migrations.CreateModel(
            name='Page',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('title', models.CharField(max_length=128)),
                ('url', models.URLField()),
                ('views', models.IntegerField(default=0)),
                ('category', models.ForeignKey(to='myapplication.Category')),
            ],
        ),
        migrations.CreateModel(
            name='Upload',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('title', models.CharField(max_length=128)),
                ('short_description', models.CharField(max_length=128, blank=True, null=True)),
                ('long_description', models.TextField(blank=True, null=True)),
                ('file_1', models.FileField(upload_to='', blank=True, default='MEDIA_ROOT/', null=True)),
                ('encrypted_1', models.BooleanField(default=False)),
                ('file_2', models.FileField(upload_to='', blank=True, default='MEDIA_ROOT/', null=True)),
                ('encrypted_2', models.BooleanField(default=False)),
                ('file_3', models.FileField(upload_to='', blank=True, default='MEDIA_ROOT/', null=True)),
                ('encrypted_3', models.BooleanField(default=False)),
                ('user', models.CharField(max_length=128)),
                ('group', models.CharField(max_length=128)),
                ('time', models.DateTimeField(default=django.utils.timezone.now)),
                ('private', models.BooleanField()),
                ('counter', models.IntegerField()),
            ],
            options={
                'permissions': (('edit_report', 'Edit report'),),
            },
        ),
        migrations.CreateModel(
            name='UserProfile',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('website', models.URLField(blank=True)),
                ('picture', models.ImageField(upload_to='profile_images', blank=True)),
                ('user', models.OneToOneField(to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]
