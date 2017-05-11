from django.conf.urls import patterns, url
from myapplication import views, views_fda
from django.views.generic import RedirectView

urlpatterns = patterns('',
    url(r'^$', views.index, name='index'),
    url(r'^index1/$', views.index1, name='index1'),
    url(r'^register/$', views.register, name='register'),
    url(r'^login/$', views.user_login, name='login'),
    url(r'^logout/$', views.user_logout, name='logout'),
    url(r'^modifygroup/$', views.user_modifygroup, name='modifygroup'),
    url(r'^creategroup/$', views.user_creategroup, name='creategroup'),
    url(r'^addtogroup/$', views.user_addtogroup, name='addtogroup'),
    url(r'^uploadfile/$', views.upload_file, name='uploadfile'),
    url(r'^uploaded/$', views.uploaded, name = 'uploaded'),
    url(r'^fdalogin/$', views_fda.user_login, name='fdalogin'),
    url(r'^fdareportlist/$', views_fda.view_reports, name='fdareportlist'),
    url(r'^fdadisplay/$', views_fda.display_reports, name='fdadisplay'),
    url(r'^fdadownload/$', views_fda.download_reports, name='fdadownload'),
    url(r'^fdadownload2/$', views_fda.download_reports2, name='fdadownload2'),
    url(r'^fdadownload3/$', views_fda.download_reports3, name='fdadownload3'),
    url(r'^getfilename/$', views_fda.get_filename, name='getfilename'),
    url(r'^getfilename2/$', views_fda.get_filename2, name='getfilename2'),
    url(r'^getfilename3/$', views_fda.get_filename3, name='getfilename3'),
    url(r'^staff/$', views.staff, name='staff'),
    url(r'^activeUsers/$', views.activeUsers, name='activeUsers'),
    url(r'^createSM/$', views.createSM, name='createSM'),
    url(r'^suspendUser/$', views.user_suspendUser, name='suspendUser'),
    url(r'^enableUser/$', views.user_enableUser, name='enableUser'),
    url(r'^removeUser/$', views.user_removeUser, name='removeUser'),
    url(r'^edit/(?P<id>\d+)/$', views.edit_file, name='edit_reports'),
    url(r'^reports/$', views.user_reports, name='reports'),
    url(r'^post/(?P<pk>\d+)/$', views.post_detail, name='post_detail'),
    url(r'^delete/(?P<pk>\d+)/$', views.delete_post, name='delete'),
    url(r'^search/$', views.search, name='search'),
    url(r'^search_result/$', views.search, name='search'),
    url(r'^modifyfolder/$', views.user_modifyfolder, name='modifyfolder'),
    url(r'^createfolder/$', views.user_createfolder, name='createfolder'),
    url(r'^removefolder/$', views.user_removefolder, name='removefolder'),
    url(r'^access/$', views.user_getFolderContents, name='access'),
    url(r'^$', RedirectView.as_view(permanent=True, url='inbox/'), name='messages_redirect'),
    url(r'^inbox/$', views.inbox, name='messages_inbox'),
    url(r'^outbox/$', views.outbox, name='messages_outbox'),
    url(r'^compose/$', views.compose, name='messages_compose'),
    url(r'^compose/(?P<recipient>[\w.@+-]+)/$', views.compose, name='messages_compose_to'),
    url(r'^reply/(?P<message_id>[\d]+)/$', views.reply, name='messages_reply'),
    url(r'^view/(?P<message_id>[\d]+)/$', views.view, name='messages_detail'),
    url(r'^delete1/(?P<message_id>[\d]+)/$', views.delete, name='messages_delete'),
    url(r'^undelete/(?P<message_id>[\d]+)/$', views.undelete, name='messages_undelete'),
    url(r'^trash/$', views.trash, name='messages_trash'),
    url(r'^message/$',views.message, name='messages_message'),
    url(r'^encComp/$', views.encryptCompose, name="encrypt_Compose"),
    url(r'^decView/$', views.decView, name='decView'),
    url(r'^forgot/$', views.forgot,name ='forgot'),
    url(r'^reset/$', views.reset,name ='reset'),
    url(r'^downloads/(?P<file_path>\w+.\w+)$', views.download, name='download'),
    url(r'^removefolder/$', views.user_removefolder, name='removefolder'),
    url(r'^renamefolder/$', views.user_renamefolder, name='renamefolder'),
    )