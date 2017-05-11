import tkinter as tk
from tkinter import messagebox, font
from tkinter.filedialog import askopenfilename
from tkinter import *
from tkinter import simpledialog
from Crypto import Random
from Crypto.Hash import SHA256
from Crypto.Cipher import DES3
import json

import requests
import os

iv = 0
encryptedBool = False
user = ""

def authenticate(username, password):
    loginDetails = {
        'username': username,
        'password': password
    }
    #r = requests.post('http://127.0.0.1:8000/fdalogin/', data=loginDetails)
    #r = requests.post('http://arcane-ridge-63055.herokuapp.com/fdalogin/', data=loginDetails)
    r = requests.post(url+'/fdalogin/', data=loginDetails)
    if (r.text=="Valid"):
        #valid login
        messagebox.showinfo("Success!", "You have successfully logged in.")
        return True
    else:
        messagebox.showerror("Error", "Invalid login. Please try again.")
        return False

def encrypt_file(filename,key):
    """Go to the file, open it, encrypt its contents with the key, and write to a file"""

    hashed = SHA256.new(key)
    key_size16 = hashed.digest()[0:16]
    global iv
    iv = Random.get_random_bytes(8)
    des3 = DES3.new(key_size16, DES3.MODE_CFB, iv)

    with open(filename, 'rb') as in_file:
        outputFile = filename+".enc"
        with open(outputFile, 'wb') as out_file:
            while True:
                chunk = in_file.read(16)
                if len(chunk) == 0:
                    break
                encrypted = des3.encrypt(chunk)
                out_file.write(iv + encrypted)
        messagebox.showinfo("Success!","\nEncrypted into "+filename+".enc\n")
    return True

def decrypt_file(filename,key):
    hashed = SHA256.new(key)
    key_size16 = hashed.digest()[0:16]
    with open(filename, 'rb') as in_file:
        iv = in_file.read(8)
    in_file.closed
    des3 = DES3.new(key_size16, DES3.MODE_CFB, iv)
    with open(filename, 'rb') as in_file:
        tempname = filename.replace(".enc","")

        index = tempname.rfind("_")
        if index == -1:
            outputFile = "DEC_" + tempname
        elif index>0:
            outputFile = "DEC_"+tempname[:index]

        with open(outputFile,'wb') as out_file:
            while True:
                iv = in_file.read(8)
                chunk = in_file.read(16)
                if len(chunk) == 0:
                    break
                out_file.write(des3.decrypt(chunk))
        messagebox.showinfo("Success!","\n Decrypted into "+outputFile+"\n")
    return True


class Menu:
    def __init__(self, master):
        self.master = master
        self.frame = tk.Frame(self.master)
        self.master.title("File Download Application")
        self.master.geometry("300x300")
        label = Label(self.frame, text = " \n Welcome to the File Download Application! \n")
        label.pack()
        self.button1 = tk.Button(self.frame, text = 'Login', width = 25, command = self.new_window)

        self.button1.pack()
        self.frame.pack()

    def new_window(self):
        self.newWindow = tk.Toplevel(self.master)
        self.app = Authenticate(self.newWindow)
        #self.newWindow.attributes("-topmost", True)

        self.frame.forget()

        self.menuFrame = tk.Frame(self.master)
        titleFont = font.Font(size=10, weight='bold')
        self.label = Label(self.menuFrame, text=" \n Welcome to the File Download Application! \n \n Menu \n", font=titleFont)

        self.label.pack()
        self.viewReports = tk.Button(self.menuFrame, text = 'View a list of reports', width = 25, command = self.view_reports)
        self.encrypt = tk.Button(self.menuFrame, text='Encrypt a file', width=25, command = self.encrypt_file)
        self.decrypt = tk.Button(self.menuFrame, text='Decrypt a file', width=25, command=self.decrypt_file)

        self.viewReports.pack()
        self.encrypt.pack()
        self.decrypt.pack()
        self.menuFrame.pack()

    def view_reports(self):
        self.newWindow = tk.Toplevel(self.master)
        self.app = ViewReports(self.newWindow)

    def encrypt_file(self):
        name= askopenfilename()
        key = simpledialog.askstring("Key", "Key:" )
        byteKey = bytes(key, encoding='utf-8')
        encrypt_file(name,byteKey)

    def decrypt_file(self):
        #name = askopenfilename()
        name = os.path.basename(askopenfilename())
        if name[-4:] == ".enc":
            key = simpledialog.askstring("Key","Key: ")
            byteKey = bytes(key, encoding='utf-8')
            decrypt_file(name,byteKey)
        else:
            messagebox.showerror("Invalid file","Oops! Looks like this file hasn't been encrypted by the FDA yet!")

class ViewReports:
    def __init__(self, master):
        self.master = master
        self.frame = tk.Frame(self.master)

        self.master.attributes("-topmost", True)

        self.master.title("File Download Application")
        self.master.geometry("300x300")
        x = (self.master.winfo_screenwidth() - self.master.winfo_reqwidth())/ 5.5
        y = (self.master.winfo_screenheight() - self.master.winfo_reqheight()) / 5.5
        self.master.geometry("+%d+%d" % (x, y))
        titleFont = font.Font(size=10, weight='bold')
        self.label = tk.Label(self.frame, text = "\n List of reports: \n", font=titleFont)
        self.label.pack()
        #r = requests.post('http://127.0.0.1:8000/fdareportlist/', data={'username': user})
        #r = requests.post('http://arcane-ridge-63055.herokuapp.com/fdareportlist/', data={'username': user})
        r = requests.post(url+'fdareportlist/', data={'username': user})
        names = json.loads(r.text)
        for name in names:
            self.list = tk.Label(self.frame, text=name)
            self.list.pack()
        self.choicelabel = tk.Label(self.frame, text=" \n Enter the name of a report to display:")
        self.choice = tk.Entry(self.frame)
        self.button = tk.Button(self.frame, text="Enter", command=lambda:self.pick_report(names))
        self.choicelabel.pack()
        self.choice.pack()
        self.button.pack()
        self.frame.pack()

    def pick_report(self, names):
        choice = self.choice.get()
        if choice in names:
            self.display_report(choice)
        else:
            print("Invalid choice. Please try again.\n")

    def display_report(self, choice):
        self.frame.destroy()
        username = user
        #rep = requests.post('http://127.0.0.1:8000/fdadisplay/', data={'username': username, 'reportname' : choice})
        #rep  = requests.post('http://arcane-ridge-63055.herokuapp.com/fdadisplay/', data={'username': username, 'reportname': choice})
        rep = requests.post(url+'fdadisplay/',
                            data={'username': username, 'reportname': choice})
        reports = json.loads(rep.text)
        #print(reports)
        self.reportFrame = tk.Frame(self.master)
        titleFont = font.Font(size=10, weight='bold')
        reportFont = font.Font(size=10, slant='italic')
        self.label = tk.Label(self.reportFrame, text="\n "+choice, font = titleFont)
        self.report = tk.Message(self.reportFrame, text="\n" + reports, font = reportFont)
        self.label.pack()
        self.report.pack()
        self.reportFrame.pack()
        download = messagebox.askyesno("Download files", "Download the file or files for this report?")
        if (download):
            self.display_report1(choice)
            self.display_report2(choice)
            self.display_report3(choice)

        else:
            messagebox.showinfo("No download","You chose not to download files\n")

    def display_report1(self, choice):
        username = user
        #r = requests.post('http://127.0.0.1:8000/fdadownload/', stream=True,
        #                  data={'username': username, 'reportname': choice})
        # r = requests.post('http://arcane-ridge-63055.herokuapp.com/fdadownload/', stream=True, data={'username': username, 'reportname': choice})
        r = requests.post(url+'fdadownload/', stream=True,
                          data={'username': username, 'reportname': choice})
        if r.status_code == 200:

            #filename = requests.post('http://127.0.0.1:8000/getfilename/', stream=True,
             #                        data={'username': username, 'reportname': choice})
            #filename = requests.post('http://arcane-ridge-63055.herokuapp.com/getfilename/', stream=True, data={'username': username, 'reportname': choice})
            filename = requests.post(url+'getfilename/', stream=True,
                                     data={'username': username, 'reportname': choice})

            with open(filename.text, 'wb') as f:
                for chunk in r:
                    f.write(chunk)
            messagebox.showinfo("Success!", "Successfully downloaded " + filename.text + "\n")
        else:
            messagebox.showerror("No files", "No files to download\n")

    def display_report2(self, choice):
        username = user
        #r = requests.post('http://127.0.0.1:8000/fdadownload2/', stream=True,
         #                 data={'username': username, 'reportname': choice})
        #r = requests.post('http://arcane-ridge-63055.herokuapp.com/fdadownload2/', stream=True, data={'username': username, 'reportname': choice})
        r = requests.post(url+'fdadownload2/', stream=True,
                          data={'username': username, 'reportname': choice})
        if r.status_code == 200:

            #filename = requests.post('http://127.0.0.1:8000/getfilename2/', stream=True,
             #                        data={'username': username, 'reportname': choice})
            #filename = requests.post('http://arcane-ridge-63055.herokuapp.com/getfilename2/', stream=True, data={'username': username, 'reportname': choice})
            filename = requests.post(url+'getfilename2/', stream=True,
                                     data={'username': username, 'reportname': choice})

            with open(filename.text, 'wb') as f:
                for chunk in r:
                    f.write(chunk)
            messagebox.showinfo("Success!", "Successfully downloaded " + filename.text + "\n")


    def display_report3(self, choice):
        username = user
        #r = requests.post('http://127.0.0.1:8000/fdadownload3/', stream=True,
         #                 data={'username': username, 'reportname': choice})
        # r = requests.post('http://arcane-ridge-63055.herokuapp.com/fdadownload3/', stream=True, data={'username': username, 'reportname': choice})
        r = requests.post(url+'fdadownload3/', stream=True,
                          data={'username': username, 'reportname': choice})
        if r.status_code == 200:
            #filename = requests.post('http://127.0.0.1:8000/getfilename3/', stream=True,
             #                        data={'username': username, 'reportname': choice})
            #filename = requests.post('http://arcane-ridge-63055.herokuapp.com/getfilename3/', stream=True, data={'username': username, 'reportname': choice})
            filename = requests.post(url+'getfilename3/', stream=True,
                                     data={'username': username, 'reportname': choice})

            with open(filename.text, 'wb') as f:
                for chunk in r:
                    f.write(chunk)
            messagebox.showinfo("Success!", "Successfully downloaded " + filename.text + "\n")



class Authenticate:
    def __init__(self, master):
        self.master = master
        self.frame = tk.Frame(self.master)

        self.master.attributes("-topmost", True)

        self.master.title("File Download Application")
        self.master.geometry("300x300")
        x = (self.master.winfo_screenwidth() - self.master.winfo_reqwidth())/ 5.5
        y = (self.master.winfo_screenheight() - self.master.winfo_reqheight()) / 5.5
        self.master.geometry("+%d+%d" % (x, y))

        self.label1 = tk.Label(self.frame, text="\n Username:")
        self.txt1 = tk.Entry(self.frame)
        self.label2 = tk.Label(self.frame, text="Password:")
        self.txt2 = tk.Entry(self.frame)
        self.button = tk.Button(self.frame, text="Login", command=self.authenticate_login)

        self.label1.pack()
        self.txt1.pack()
        self.label2.pack()
        self.txt2.pack()
        self.button.pack()
        self.frame.pack()

    def authenticate_login(self):
        username = self.txt1.get()
        password = self.txt2.get()
        authenticated = authenticate(username, password)
        if authenticated:
            self.close_windows()
            global user
            user = username

    def close_windows(self):
        self.master.destroy()


def main():
    root = tk.Tk()
    x = (root.winfo_screenwidth() - root.winfo_reqwidth()) / 5.5
    y = (root.winfo_screenheight() - root.winfo_reqheight())/ 5.5
    root.geometry("+%d+%d" % (x, y))

    app = Menu(root)
    root.mainloop()

if __name__ == '__main__':
    url = input("Enter Heroku url: ")
    print(url)
    main()