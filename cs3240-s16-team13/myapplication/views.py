from django.shortcuts import render, get_object_or_404, render_to_response
from django.http import HttpResponse, HttpResponseRedirect, Http404, HttpResponseForbidden
from myapplication.forms import UserForm, UserProfileForm, CreateGroupForm, AddToGroupForm, UploadFileForm, suspendUserForm, enableUserForm, removeUserForm, ComposeForm, EncryptComposeForm, UploadKeyFileForm, CreateFolderForm, RemoveFolderForm, RenameFolderForm
from myapplication.models import Message, Upload, Folder
from django.contrib.auth.models import Group, User, Permission
from django.contrib import messages
from django.utils import timezone
from django.core.urlresolvers import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from myapplication.utils    import *
from django.conf import settings
from Crypto.PublicKey import RSA
from Crypto import Random
from django.shortcuts import render, get_object_or_404, render_to_response
from django.core.urlresolvers import reverse
from django.contrib.auth import authenticate, login, logout
from django.http import HttpResponseForbidden
from django.template import RequestContext, response
from django.shortcuts import redirect
from django.utils import timezone
from django.contrib.contenttypes.models import ContentType
from django.db.models import Q
from django.contrib import messages
from django.core.servers.basehttp import FileWrapper
import re

count = 0

#key = RSA.generate(2048)
random_generator = Random.new().read
key = RSA.generate(1024, random_generator)
public_key = key.publickey()

"""user"""
def index1(request):
    message_list = Message.objects.inbox_for(request.user)
    #context_dict = {'boldmessage': "I am a bold font from the context"}
    return render(request, 'templates/myapplication/index1.html', {'message_list': message_list })

def index(request):
    context_dict = {'boldmessage': "I am a bold font from the context"}
    return render(request, 'templates/myapplication/index.html', context_dict)

def register(request):

    # A boolean value for telling the template whether the registration was successful.
    # Set to False initially. Code changes value to True when registration succeeds.
    registered = False

    # If it's a HTTP POST, we're interested in processing form data.
    if request.method == 'POST':
        # Attempt to grab information from the raw form information.
        # Note that we make use of both UserForm and UserProfileForm.
        user_form = UserForm(data=request.POST)
        profile_form = UserProfileForm(data=request.POST)

        # If the two forms are valid...
        if user_form.is_valid() and profile_form.is_valid():
            # Save the user's form data to the database.
            user = user_form.save()

            # Now we hash the password with the set_password method.
            # Once hashed, we can update the user object.
            user.set_password(user.password)
            user.save()

            # Now sort out the UserProfile instance.
            # Since we need to set the user attribute ourselves, we set commit=False.
            # This delays saving the model until we're ready to avoid integrity problems.
            profile = profile_form.save(commit=False)
            profile.user = user

            # Did the user provide a profile picture?
            # If so, we need to get it from the input form and put it in the UserProfile model.
            if 'picture' in request.FILES:
                profile.picture = request.FILES['picture']

            # Now we save the UserProfile model instance.
            profile.save()

            # Update our variable to tell the template registration was successful.
            registered = True

        # Invalid form or forms - mistakes or something else?
        # Print problems to the terminal.
        # They'll also be shown to the user.
        else:
            print (user_form.errors, profile_form.errors)

    # Not a HTTP POST, so we render our form using two ModelForm instances.
    # These forms will be blank, ready for user input.
    else:
        user_form = UserForm()
        profile_form = UserProfileForm()

    # Render the template depending on the context.
    return render(request,
            'templates/myapplication/register.html',
            {'user_form': user_form, 'profile_form': profile_form, 'registered': registered} )


def user_login(request):

    # If the request is a HTTP POST, try to pull out the relevant information.
    if request.method == 'POST':
        # Gather the username and password provided by the user.
        # This information is obtained from the login form.
                # We use request.POST.get('<variable>') as opposed to request.POST['<variable>'],
                # because the request.POST.get('<variable>') returns None, if the value does not exist,
                # while the request.POST['<variable>'] will raise key error exception
        username = request.POST.get('username')
        password = request.POST.get('password')

        # Use Django's machinery to attempt to see if the username/password
        # combination is valid - a User object is returned if it is.
        user = authenticate(username=username, password=password)

        # If we have a User object, the details are correct.
        # If None (Python's way of representing the absence of a value), no user
        # with matching credentials was found.
        if user:
            # Is the account active? It could have been disabled.
            if user.is_active:
                # If the account is valid and active, we can log the user in.
                # We'll send the user back to the homepage.
                login(request, user)
                return HttpResponseRedirect('/')
            else:
                # An inactive account was used - no logging in!
                return HttpResponse("Your SafeCollab account is disabled.")
        else:
            # Bad login details were provided. So we can't log the user in.
            print ("Invalid login details: {0}, {1}".format(username, password))
            #return HttpResponse("Invalid login details supplied.")
            invalid = True
            return render(request,'templates/myapplication/login.html', {"invalid":invalid})

    # The request is not a HTTP POST, so display the login form.
    # This scenario would most likely be a HTTP GET.
    else:
        # No context variables to pass to the template system, hence the
        # blank dictionary object...
        return render(request, 'templates/myapplication/login.html', {})


def user_logout(request):
    # Since we know the user is logged in, we can now just log them out.
    logout(request)
    
    # Take the user back to the homepage.
    return render(request, 'templates/myapplication/index.html', {})
    #return HttpResponseRedirect('/')

"""group"""
def user_modifygroup(request):
    if request.user.is_authenticated():
        context_dict = {'boldmessage': "I am a bold font from the context"}
        return render(request, 'templates/myapplication/modifyGroup.html', context_dict)
    else:
        return HttpResponseRedirect('/')

def user_creategroup(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False
        if request.method == 'POST':
            # Attempt to grab information from the raw form information.
            # Note that we make use of both UserForm and UserProfileForm.
            create_form = CreateGroupForm(data=request.POST)

            # If the two forms are valid...
            if create_form.is_valid():
                # Save the user's form data to the database.
                group = create_form.save()
                group.save()
                valid = True
                attempted = True
                return render(request,
                'templates/myapplication/modifyGroup.html',
                {'valid': valid, 'attempted': attempted} )
            else:
                attempted = True
                return render(request,
                    'templates/myapplication/modifyGroup.html',
                    {'creategroup_form': CreateGroupForm, 'valid': valid, 'attempted': attempted })
        else:
            return HttpResponseRedirect('/')


def user_creategroup(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False
        if request.method == 'POST':
            # Attempt to grab information from the raw form information.
            # Note that we make use of both UserForm and UserProfileForm.
            create_form = CreateGroupForm(data=request.POST)

            # If the two forms are valid...
            if create_form.is_valid():
                # Save the user's form data to the database.
                group = create_form.save()
                group.save()
                valid = True
                attempted = True
                name = request.POST.get('name')
                content_type = ContentType.objects.get_for_model(Upload)
                groupPermission = Permission.objects.create(codename=name + '_can_view', name=name + '_can_view',
                                                            content_type=content_type)
                group.permissions.add(groupPermission)
                return render(request,
                              'templates/myapplication/modifyGroup.html',
                              {'validCreate': valid, 'attempted': attempted})
            else:
                attempted = True
                return render(request,
                    'templates/myapplication/modifyGroup.html',
                    {'creategroup_form': CreateGroupForm, 'validCreate': valid, 'attempted': attempted })
    else:
        return HttpResponseRedirect('/')

def user_addtogroup(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False

        if request.method == 'POST':

            #Attempt to grab information from the raw form information.
            #Note that we make use of both UserForm and UserProfileForm.

            add_form = AddToGroupForm(data=request.POST)

            # If the two forms are valid...
            if add_form.is_valid():
                name = request.POST.get('username')
                group = request.POST.get('group')
                try:
                    Group.objects.get(name=group)
                except Group.DoesNotExist:
                    messages.add_message(request, messages.INFO,
                                         'This is an invalid group, please enter a valid group')
                    return HttpResponseRedirect('/modifygroup')
                try:
                    User.objects.get(username=name)
                except User.DoesNotExist:
                    messages.add_message(request, messages.INFO,
                                         'This is not a valid user, please enter a valid user')
                    return HttpResponseRedirect('/modifygroup')
            #g = Group.objects.get(name='apma')
            #user = User.objects.get(name)
                user = User.objects.get(username=name)
                user.groups.add(Group.objects.get(name=group))
                # Save the user's form data to the database.
                #group = add_form.save()
                #group.save()
                valid = True
                attempted = True
                return render(request,
                'templates/myapplication/modifyGroup.html',
                {'validAdd': valid, 'attempted': attempted} )
            else:
                attempted = True
                return render(request,
                    'templates/myapplication/modifyGroup.html',
                    {'addtogroup_form': AddToGroupForm, 'validAdd': valid, 'attempted': attempted })
    else:
        return HttpResponseRedirect('/')


"""file edit"""
def edit_file(request, id):
    if request.user.is_authenticated():
         user = request.user.get_username()
         e = Upload.objects.get(pk=int(id))
         if(user == e.user) or (request.user.is_staff == True):
             print("This is the author or a site manager and they can edit this form")
             context_instance=RequestContext(request)
             obj_list = Upload.objects.all()
             print(id)
             form = UploadFileForm(instance=e)
             content_type = ContentType.objects.get_for_model(Upload)
             title = e.title
             Upload.objects.get(pk=int(id)).delete()
             return render_to_response('templates/myapplication/upload.html', {'form': form}, context_instance,)
         else:
            messages.add_message(request, messages.INFO, 'You do not have permission to edit this report')
            print("You do not have permission to edit this report")
            return HttpResponseRedirect('/reports')
    else:
        return HttpResponseRedirect('/')


def post_edit(request, id):
    if request.user.is_authenticated():
        post = get_object_or_404(Upload, pk=id)
        if request.method == "POST":
            form = UploadFileForm(request.POST, instance=post)
            if form.is_valid():
                post = form.save(commit=False)
                post.user = request.user
                post.time = timezone.now()
                post.save()
                return HttpResponseRedirect('/reports/')
        else:
            form = UploadFileForm(instance=post)
        return render(request, '/edited.html', {'form': form})
    else:
        return HttpResponseRedirect('/')


"""file"""
def upload_file(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False
        if request.method == 'POST':
            #create_form = UploadFileForm(data=request.POST)
            #if create_form.is_valid():
                #upload = create_form.save()
                #upload.save()
                #valid = True
                #attempted = True

                if (request.POST.get('encrypted_1') == "on"):
                    print("Must be encrypted by the FDA")

                group = request.POST.get('group')
                try:
                    Group.objects.get(name=group)
                except Group.DoesNotExist:
                    messages.add_message(request, messages.INFO, 'This is an invalid group, please enter a valid group')
                    return HttpResponseRedirect('/uploadfile')

                form = UploadFileForm(request.POST, request.FILES)

                if form.is_valid:
                    if form.has_changed():

                        #if (request.POST.get('group') == True):
                        print("valid group")
                        instance = form.save(commit=False)
                        instance.user = request.user.get_username()
                        title = request.POST.get('title')
                        content_type = ContentType.objects.get_for_model(Upload)
                        # permission = Permission.objects.create(codename=instance.user +'_can_delete_' + title,
                        #                    name='Can Delete Report', content_type=content_type)
                        # permissionTwo = Permission.objects.create(codename=instance.user+'_can_edit_' + title,
                        #                    name='Can Edit Report',
                        #                    content_type=content_type)
                        # request.user.user_permissions.add(permission, permissionTwo)
                        instance.save()
                        form.save()
                        valid = True
                        attempted = True
                    #return HttpResponseRedirect('/uploaded/')
                        return render(request,
                    'templates/myapplication/upload.html',
                    {'validCreate': valid, 'attempted': attempted} )
                       # else:
                            #return HttpResponseRedirect('/reports')
        else:
            return render(request, 'templates/myapplication/upload.html', {'form':UploadFileForm, 'validCreate': valid, 'attempted': attempted})
    else:
        return HttpResponseRedirect('/')

def uploaded (request):
    if request.user.is_authenticated():
        print("uploaded")
        return render(request,'templates/myapplication/upload.html')
    else:
        return HttpResponseRedirect('/')

def download(request, file_path):
  with open('mysite/{0}'.format(file_path), 'rb') as file:
      wrapper = FileWrapper(file)
      response = HttpResponse(wrapper)
      response['Content-Disposition'] = 'Attachment; file={0}'.format('file.php')
      return response

"""site manager"""
def staff(request):
    context_dict = {'boldmessage': "I am a bold font from the context"}
    return render(request, 'templates/myapplication/staff.html', context_dict)

def createSM(request):
    # A boolean value for telling the template whether the registration was successful.
    # Set to False initially. Code changes value to True when registration succeeds.
    registered = False

    # If it's a HTTP POST, we're interested in processing form data.
    if request.method == 'POST':
        # Attempt to grab information from the raw form information.
        # Note that we make use of both UserForm and UserProfileForm.
        user_form = UserForm(data=request.POST)
        profile_form = UserProfileForm(data=request.POST)

        # If the two forms are valid...
        users = User.objects.filter(is_staff = True).count()
        print(users)
        if user_form.is_valid() & (users < 4):
            # Save the user's form data to the database.
            user = user_form.save()

            # Now we hash the password with the set_password method.
            # Once hashed, we can update the user object.
            user.set_password(user.password)
            user.is_staff = True
            user.save()



            # Update our variable to tell the template registration was successful.
            registered = True

        # Invalid form or forms - mistakes or something else?
        # Print problems to the terminal.
        # They'll also be shown to the user.
        else:
            print (user_form.errors)

    # Not a HTTP POST, so we render our form using two ModelForm instances.
    # These forms will be blank, ready for user input.
    else:
        user_form = UserForm()


    # Render the template depending on the context.
    return render(request,
            'templates/myapplication/createSM.html',
            {'user_form': user_form,'registered': registered} )

def activeUsers(request):
    if request.user.is_authenticated():
        users = User.objects.filter(is_staff = False)
        groups = Group.objects.values_list('name', flat = True)
        return render(request, 'templates/myapplication/activeUsers.html', {'users': users, 'groups': groups})
    else:
        return HttpResponseRedirect('/')

def user_suspendUser(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False

        if request.method == 'POST':

            #Attempt to grab information from the raw form information.
            #Note that we make use of both UserForm and UserProfileForm.

            suspend_form = suspendUserForm(data=request.POST)

            # If the two forms are valid...
            if suspend_form.is_valid():
                name = request.POST.get('username')
                user = User.objects.get(username=name)
                print(user)
                user.is_active = False
                user.save()
                valid = True
                attempted = True
                return render(request,
                'templates/myapplication/activeUsers.html',
                {'suspended': valid, 'attempted': attempted} )
            else:
                attempted = True
                return render(request,
                    'templates/myapplication/activeUsers.html',
                    {'suspendUser_form': suspendUserForm, 'suspended': valid, 'attempted': attempted })
    else:
        return HttpResponseRedirect('/')

def user_enableUser(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False

        if request.method == 'POST':

            #Attempt to grab information from the raw form information.
            #Note that we make use of both UserForm and UserProfileForm.

            enable_form = enableUserForm(data=request.POST)

            # If the two forms are valid...
            if enable_form.is_valid():
                name = request.POST.get('username')
                user = User.objects.get(username=name)
                print(user)
                user.is_active = True
                user.save()
                valid = True
                attempted = True
                return render(request,
                'templates/myapplication/activeUsers.html',
                {'enabled': valid, 'attempted': attempted} )
            else:
                attempted = True
                return render(request,
                    'templates/myapplication/activeUsers.html',
                    {'enableUser_form': suspendUserForm, 'enabled': valid, 'attempted': attempted })
    else:
        return HttpResponseRedirect('/')

def user_removeUser(request):
    if request.user.is_authenticated():
        valid = False
        attempted = False

        if request.method == 'POST':

            #Attempt to grab information from the raw form information.
            #Note that we make use of both UserForm and UserProfileForm.

            remove_form = removeUserForm(data=request.POST)
            name = request.POST.get('username')
            group = request.POST.get('group')
            # If the two forms are valid...
            if remove_form.is_valid():


            #g = Group.objects.get(name='apma')
            #user = User.objects.get(name)
                user = User.objects.get(username=name)
                user.groups.remove(Group.objects.get(name=group))
                # Save the user's form data to the database.
                #group = add_form.save()
                #group.save()
                valid = True
                attempted = True
                return render(request,
                              'templates/myapplication/activeUsers.html',
                              {'removed': valid, 'attempted': attempted} )
            else:
                attempted = True
                return render(request,
                    'templates/myapplication/activeUsers.html',
                    {'removeUser_form': removeUserForm, 'removed': valid, 'attempted': attempted })
    else:
        return HttpResponseRedirect('/')


"""view reports and search"""
def user_reports(request):
    if request.user.is_authenticated():
        reports = Upload.objects.all()
        return render(request, 'templates/myapplication/reports.html', {'reports': reports})
    else:
        return HttpResponseRedirect('/')

def post_detail(request, pk):
    if request.user.is_authenticated():
        user = request.user
        #request.get
        #if user.groups.filter(name=group_name):

        post = get_object_or_404(Upload, pk=pk)
        print(post.counter)
        if (post.private == True):
             if (post.user != request.user.get_username()):
                 if (request.user.groups.filter(name= post.group).count() == 1):
                     print("Access granted for group member")
                     post.counter = post.counter + 1
                     post.save()
                     return render(request, 'templates/myapplication/detailed.html', {'post': post, 'count': post.counter})
                 else:
                    messages.add_message(request, messages.INFO, 'This report is private, and cannot be viewed by you!')
                    print("This report is private, and cannot be viewed by you!")
                    return HttpResponseRedirect('/reports')
             print("This is your report")
             post.counter = post.counter + 1
             post.save()
             return render(request, 'templates/myapplication/detailed.html', {'post': post, 'count': post.counter})
        else:
            post.counter = post.counter + 1
            print(post.counter)
            post.save()
            print("This is a public report")
            return render(request, 'templates/myapplication/detailed.html', {'post': post, 'count': post.counter})
    else:
        return HttpResponseRedirect('/')

def delete_post(request, pk):
    if request.user.is_authenticated():
        user = request.user.get_username()
        e = Upload.objects.get(pk=pk)
        if(request.user.is_staff == True):
            Upload.objects.get(pk=pk).delete()
            print("Report successfully deleted by the site manager")
            return HttpResponseRedirect('/reports')
        if(user == e.user):
            Upload.objects.get(pk=pk).delete()
            print("Report successfully deleted by the author")
            return HttpResponseRedirect('/reports')
        else:
            messages.add_message(request, messages.INFO, 'You do not have permission to delete this report')
            print("You do not have permission to delete this report")
            return HttpResponseRedirect('/reports')
    else:
        return HttpResponseRedirect('/')


def normalize_query(query_string,
                    findterms=re.compile(r'"([^"]+)"|(\S+)').findall,
                    normspace=re.compile(r'\s{2,}').sub):
    ''' Splits the query string in invidual keywords, getting rid of unecessary spaces
        and grouping quoted words together.


    '''
    return [normspace(' ', (t[0] or t[1]).strip()) for t in findterms(query_string)]


def get_query(query_string, search_fields):
    ''' Returns a query, that is a combination of Q objects. That combination
        aims to search keywords within a model by testing the given search fields.

    '''
    query = None # Query to search for every search term
    terms = normalize_query(query_string)
    for term in terms:
        or_query = None # Query to search for a given term in each field
        for field_name in search_fields:
            q = Q(**{"%s__icontains" % field_name: term})
            if or_query is None:
                or_query = q
            else:
                or_query = or_query | q
        if query is None:
            query = or_query
        else:
            query = query & or_query
    return query

def search(request):
    query_string = ''
    found_entries = None
    if ('q' in request.GET) and request.GET['q'].strip():
        query_string = request.GET['q']

        entry_query = get_query(query_string, ['title', 'group','short_description','long_description', 'encrypted_1', 'encrypted_2', 'encrypted_3', 'file_1', 'file_2', 'file_3', 'user'])

        found_entries = Upload.objects.filter(entry_query).order_by('time')
    return render(request, 'templates/myapplication/search_result.html',{'query_string': query_string, 'found_entries': found_entries })

"""folder"""
def user_modifyfolder(request):
    if request.user.is_authenticated():
        context_dict = {'boldmessage': "I am a bold font from the context"}
        return render(request, 'templates/myapplication/modifyfolder.html', context_dict)
    else:
        return HttpResponseRedirect('/')

def user_createfolder(request):
    valid = False
    attempted = False
    if request.method == 'POST':
        form = CreateFolderForm(data=request.POST)
        if form.is_valid():
            form.save()
            valid = True
            attempted = True
            return render(request,'templates/myapplication/modifyfolder.html',
                      {'validFolderCreate': valid, 'attempted': attempted})
        else:
            attempted = True
            return render(request, 'templates/myapplication/modifyfolder.html',
                      {'createfolder_form': CreateFolderForm, 'validFolderCreate': valid, 'attempted': attempted})
 
def user_removefolder(request):
    valid = False
    if request.method == 'POST':
        remove_form = RemoveFolderForm(data=request.POST)
        #title = request.POST.get('title')
        if remove_form.is_valid():
            #user = Folder.objects.get(name=title)
            valid = True
            attempted = True
            return render(request,
                          'templates/myapplication/modifyFolder.html',
                          {'removed': valid, 'attempted': attempted} )
        else:
            attempted = True
            return render(request,
                'templates/myapplication/modifyFolder.html',
                {'removefolder_form': RemoveFolderForm, 'removed': valid, 'attempted': attempted })
 
def user_getFolderContents(request):
    groups = Group.objects.all()
    query = Upload.objects.all()
    query_data = {}
    for group in groups:
        query = Upload.objects.filter(group=group)
        for upload in query:
            f1 = upload.file_1
            f2 = upload.file_2
            f3 = upload.file_3
            files =[f1, f2, f3]
            query_data[group] = files
    query_data = {
        'query': query , 'f1':f1, 'f2':f2, 'f3':f3, 'groups':groups}
    return render_to_response('templates/myapplication/access.html', query_data, context_instance=RequestContext(request))
 
def user_removefolder(request):
   valid = False
   attemptedRemove = False
   if request.method == 'POST':
       remove_form = RemoveFolderForm(data=request.POST)
       if remove_form.is_valid():
           title = request.POST.get('title')
           exists = Folder.objects.filter(title=title)
           if (len(exists)!=0):
               exists.delete()
               valid = True
           else:
               attemptedRemove = True
               #messages.add_message(request, messages.INFO, 'This is not a valid folder, please enter a valid folder')
               return render(request,
                             'templates/myapplication/modifyfolder.html',
                             {'attemptedRemove': attemptedRemove})
           #user = Folder.objects.get(name=title)
           return render(request,
                         'templates/myapplication/modifyfolder.html',
                         {'removed': valid} )
       else:
           return render(request,
               'templates/myapplication/modifyfolder.html',
               {'removefolder_form': RemoveFolderForm, 'removed': valid })

def user_renamefolder(request):
   valid = False
   attemptedRename = False
   if request.method == 'POST':
       rename_form = RenameFolderForm(data=request.POST)
       if rename_form.is_valid():
           oldtitle = request.POST.get('old_title')
           newtitle = request.POST.get('new_title')
           folder = Folder.objects.filter(title=oldtitle)
           if (len(folder)!=0):
               folder.update(title=newtitle)
               valid = True
           else:
               attemptedRename = True
               messages.add_message(request, messages.INFO, 'This is not a valid folder, please enter a valid folder')
               return render(request,
                             'templates/myapplication/modifyfolder.html',
                             {'attemptedRename': attemptedRename})

           return render(request,
                         'templates/myapplication/modifyfolder.html',
                         {'renamed': valid})
       else:
           return render(request,
                         'templates/myapplication/modifyfolder.html',
                         {'renamefolder_form': RenameFolderForm, 'renamed': valid})

def user_getFolderContents(request):
   groups = request.user.groups.values_list('name', flat=True)
   folders = Folder.objects.all()
   query = Upload.objects.all()
   query_data = {}
   for group in groups:
       #permission = User.objects.filter(groups=group)
       #if len(permission) > 0:
       #   query_data['permissions'] = permission
       query = Upload.objects.filter(group=group)
       f1 = None
       f2 = None
       f3 = None
       for upload in query:
            try:
                if upload.file_1:
                    f1 = upload.file_1.file.name.rsplit('/')[0]
            except FileNotFoundError:
                print("wrong")
               #messages.add_message(request, messages.INFO, 'no files, womp')
               #return HttpResponseRedirect('/')
            try:
                if upload.file_2:
                    f2 = upload.file_2.file.name.rsplit('/')[0]
            except FileNotFoundError:
                print("wrong")
            try:
                if upload.file_3:
                    f3 = upload.file_3.file.name.rsplit('/')[0]
            except FileNotFoundError:
                print("wrong")

            files =[f1, f2, f3]
            query_data['groups'] = files

   query_data = {
       'query': query , 'groups':groups, 'folders':folders}
   return render_to_response('templates/myapplication/access.html', query_data, context_instance=RequestContext(request))

def user_modifyfolder(request):
   context_dict = {'boldmessage': "I am a bold font from the context"}
   return render(request, 'templates/myapplication/modifyfolder.html', context_dict)


"""private message"""
def inbox(request):
    if request.user.is_authenticated():
        message_list = Message.objects.inbox_for(request.user)
        return render(request,
                    'templates/myapplication/inbox.html',
                    {'message_list': message_list })
    else:
        return HttpResponseRedirect('/')


def outbox(request):
    if request.user.is_authenticated():
        message_list = Message.objects.outbox_for(request.user)
        return render(request,
                'templates/myapplication/outbox.html',
                {'message_list': message_list})
    else:
        return HttpResponseRedirect('/')


def trash(request):
    if request.user.is_authenticated():
        message_list = Message.objects.trash_for(request.user)
        return render(request,
                'templates/myapplication/trash.html',
                {'message_list': message_list})
    else:
        return HttpResponseRedirect('/')

def message(request):
    message_count = Message.objects.unread_messages(request.user)
    return render(request,
            'templates/myapplication/message.html',
            {'message_count': message_count})


def compose(request, recipient=None, form_class=ComposeForm,
        success_url=None, recipient_filter=None):
    if request.user.is_authenticated():
        if request.method == "POST":
            sender = request.user
            form = form_class(request.POST, recipient_filter=recipient_filter)
            if form.is_valid():
                form.save(sender=request.user, enc=request)
                
                if success_url is None:
                    success_url = reverse('messages_message')
                if 'next' in request.GET:
                    success_url = request.GET['next']
                return HttpResponseRedirect(success_url)
        else:
            form = form_class()
            if recipient is not None:
                recipients = [u for u in User.objects.filter(**{'%s__in' % get_username_field(): [r.strip() for r in recipient.split('+')]})]
                form.fields['recipient'].initial = recipients

        return render(request,
                'templates/myapplication/compose.html',
                {'form': form})
    else:
        return HttpResponseRedirect('/')

def encryptCompose(request, recipient=None, form_class=EncryptComposeForm,
        success_url=None, recipient_filter=None):
    if request.method == "POST":
        sender = request.user
        form = form_class(request.POST, recipient_filter=recipient_filter)
        if form.is_valid():
            form.save(sender=request.user)
            
            if success_url is None:
                success_url = reverse('messages_message')
            if 'next' in request.GET:
                success_url = request.GET['next']
            return HttpResponseRedirect(success_url)
    else:
        form = form_class()
        if recipient is not None:
            recipients = [u for u in User.objects.filter(**{'%s__in' % get_username_field(): [r.strip() for r in recipient.split('+')]})]
            form.fields['recipient'].initial = recipients

    return render(request,
            'templates/myapplication/encryptCompose.html',
            {'form': form})

def reply(request, message_id, form_class=ComposeForm, success_url=None,
        recipient_filter=None, quote_helper=format_quote,
        subject_template=(u"Re: %(subject)s")):
    parent = get_object_or_404(Message, id=message_id)

    if parent.sender != request.user and parent.recipient != request.user:
        raise Http404

    if request.method == "POST":
        sender = request.user
        form = form_class(request.POST, recipient_filter=recipient_filter)
        if form.is_valid():
            form.save(sender=request.user, parent_msg=parent, enc=False)
            messages.info(request, (u"Message successfully sent."))
            if success_url is None:
                success_url = reverse('messages_inbox')
            return HttpResponseRedirect(success_url)
    else:
        form = form_class(initial={
            'body': quote_helper(parent.sender, parent.body),
            'subject': subject_template % {'subject': parent.subject},
            'recipient': [parent.sender,]
            })

    return render(request,
            'templates/myapplication/compose.html',
            {'form': form})


def delete(request, message_id, success_url=None):
    user = request.user
    now = timezone.now()
    message = get_object_or_404(Message, id=message_id)
    deleted = False
    if success_url is None:
        success_url = reverse('messages_inbox')
    if 'next' in request.GET:
        success_url = request.GET['next']
    if message.sender == user:
        message.sender_deleted_at = now
        deleted = True
    if message.recipient == user:
        message.recipient_deleted_at = now
        deleted = True
    if deleted:
        message.save()
        
        return HttpResponseRedirect(success_url)
    raise Http404


def undelete(request, message_id, success_url=None):
    user = request.user
    message = get_object_or_404(Message, id=message_id)
    undeleted = False
    if success_url is None:
        success_url = reverse('messages_inbox')
    if 'next' in request.GET:
        success_url = request.GET['next']
    if message.sender == user:
        message.sender_deleted_at = None
        undeleted = True
    if message.recipient == user:
        message.recipient_deleted_at = None
        undeleted = True
    if undeleted:
        message.save()
        messages.info(request, (u"Message successfully recovered."))
        
        return HttpResponseRedirect(success_url)
    raise Http404


def view(request, message_id, form_class=ComposeForm, quote_helper=format_quote,
        subject_template=(u"Re: %(subject)s"),
        ):
    user = request.user
    now = timezone.now()
    message = get_object_or_404(Message, id=message_id)
    if (message.sender != user) and (message.recipient != user):
        raise Http404
    if message.read_at is None and message.recipient == user:
        message.read_at = now
        message.save()

    context = {'message': message, 'reply_form': None}
    if message.recipient == user:
        form = form_class(initial={
            'body': quote_helper(message.sender, message.body),
            'subject': subject_template % {'subject': message.subject},
            'recipient': [message.sender,]
            })
        context['reply_form'] = form

    return render(request,
            'templates/myapplication/view.html',
            context)

def decView(request):
    valid = False
    attempted = False
    if request.method == 'POST':

            form = UploadKeyFileForm(request.POST, request.FILES)
            if form.is_valid:
                # handle_upload(request.FILES['file'])
                form.save()
                valid = True
                attempted = True
                #return HttpResponseRedirect('/uploaded/')
                return render(request,
            'templates/myapplication/decView.html',
            {'validCreate': valid, 'attempted': attempted} )
    else:
        return render(request, 'templates/myapplication/decView.html', {'form':UploadKeyFileForm, 'validCreate': valid, 'attempted': attempted})    

"""reset password"""
def forgot(request):
    emailed = False
    if request.method == 'POST':
        email = request.POST.get('email')
        username = request.POST.get('username')
        try:
           user = User.objects.get(username=username)
        except User.DoesNotExist:
            messages.add_message(request, messages.INFO, 'This is not a valid user, please enter a valid user')
            return HttpResponseRedirect('/forgot')
        if(user.email == email):
            print("this works")
            print(email)
            emailed = True
            send_mail('Password', ' Please follow this link to reset your password: http://127.0.0.1:8040/reset/ ' , 'teamthirteenuva@outlook.com', [email], fail_silently=False)
        else:
            messages.add_message(request, messages.INFO, 'This is not the correct email address corresponding to this username')
            return HttpResponseRedirect('/forgot')
    return render(request,
                      'templates/myapplication/forgot.html',
                      {'emailed': emailed} )

def reset(request):
     reset = False
     if request.method == 'POST':
         username = request.POST.get('username')
         password = request.POST.get('password')
         user = User.objects.get(username=username)
         user.set_password(password)
         user.save()
         reset = True
     return render(request,
                       'templates/myapplication/reset.html',
                       {'reset': reset})

