from django.conf.urls import patterns, include, url
from django.contrib import admin

urlpatterns = [
	
	# Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

	url(r'^admin/', include(admin.site.urls)),
#<<<<<<< HEAD:cs3240/mysite/urls.py
	# url(r'^myapplication/', include('myapplication.urls')),
	url(r'^', include('myapplication.urls')),
#]
#=======

	#need this for Jessica's
	url(r'^myapplication/', include('myapplication.urls')),
	#need this for Ora's
	url(r'^', include('myapplication.urls')),
]
#>>>>>>> 48b66d308f9eb8a630a73ce8ca1e98ce6d4e3ac6:mysite/urls.py
