# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('myapplication', '0002_auto_20160502_2151'),
    ]

    operations = [
        migrations.AddField(
            model_name='upload',
            name='folder',
            field=models.ForeignKey(to='myapplication.Folder', null=True),
        ),
        migrations.AlterField(
            model_name='upload',
            name='counter',
            field=models.IntegerField(default=0),
        ),
    ]
