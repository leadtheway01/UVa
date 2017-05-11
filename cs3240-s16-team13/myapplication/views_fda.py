from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect

from django.contrib.auth import authenticate, login, logout
from django.views.decorators.csrf import csrf_exempt
#from myapplication.models import Group
from myapplication.models import Upload
from django.http import JsonResponse

@csrf_exempt
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
            return HttpResponse("Valid")
        else:
            # Bad login details were provided. So we can't log the user in.
            print ("Invalid login details: {0}, {1}".format(username, password))
            return HttpResponse("Invalid login details supplied.")

    # The request is not a HTTP POST, so display the login form.
    # This scenario would most likely be a HTTP GET.
    else:
        # No context variables to pass to the template system, hence the
        # blank dictionary object...
        return render(request, 'templates/myapplication/login.html', {})

def view_reports(request):
   reports = Upload.objects.all()
   names=[]
   for report in reports:
    names.append(report.title)
   return HttpResponse(JsonResponse(names, safe=False))

   # return render(request, 'templates/myapplication/login.html', {})

def display_reports(request):
    name = request.POST.get('reportname')
   # reports = Upload.objects.all()
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        report=rep.long_description
    return HttpResponse(JsonResponse(report,safe=False))

def download_reports(request):
    name = request.POST.get('reportname')
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        #if (rep.file_1.name!="MEDIA_ROOT/"):
        if (len(reports)!=0):
            report=rep.file_1

        # if (rep.file_2.name != "MEDIA_ROOT/"):
        #     download_reports2(request)
        #     report2=rep.file_2
        #
        # if (rep.file_3.name != "MEDIA_ROOT/"):
        #     report3=rep.file_3

    return HttpResponse(report)

def download_reports2(request):
    name = request.POST.get('reportname')
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        #if (rep.file_2.name != "MEDIA_ROOT/"):
        if (len(reports)!=0):
            report = rep.file_2
        # if (rep.file_3.name !="MEDIA_ROOT/"):
        #     download_reports3(request)
    return HttpResponse(report)

def download_reports3(request):
    name = request.POST.get('reportname')
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        #if (rep.file_3.name != "MEDIA_ROOT/"):
        if (len(reports)!=0):
            report = rep.file_3
    return HttpResponse(report)

def get_filename(request):
    name = request.POST.get('reportname')
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        filename = rep.file_1.name
        filename = filename[2:]
    return HttpResponse(filename)

def get_filename2(request):
    name = request.POST.get('reportname')
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        filename = rep.file_2.name
        filename = filename[2:]
    return HttpResponse(filename)

def get_filename3(request):
    name = request.POST.get('reportname')
    reports = Upload.objects.filter(title=name)
    for rep in reports:
        filename = rep.file_3.name
        filename = filename[2:]
    return HttpResponse(filename)


    #return HttpResponse(JsonResponse({'report':report, 'filename':filename }))