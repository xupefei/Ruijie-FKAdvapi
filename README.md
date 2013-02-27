#Ruijie FKAdvapi

*Work on Ruijie Supplicant versioned from 3.9 to 4.22*

##Why we all hate Ruijie Supplicant

Ruijie Supplicant is a client-side authorization program used by many universities in China. To <del>earn more money</del> ensure network safety, some universities are blocking third-party authorization programs (like MentoHust) to access their authorization systems. There are serveal methods used by these universities:

* Client program version check
* MD5 check of the client program's `code` section 
* Enumerate all your network adapter, ensuring there is only one adapter working (If you have more than two adapters working, you may providing proxy service to other clients or devices, eg. your iPad).

With these mothods, universities can ensure every student are paying money to them. For the students, it is not possible to make their smart devices (even Virtual Machines) accessing the Internet though their computer.

##How this work

We now know that Ruijie uses `SetTimer` API to enumerate all your network adapters. And with the power of EasyHook, it is very easy to hijack it to our own method. We can enlarge the `uElapse` arguments to `0xFFFFFFFF` to (almost) disable the enumeration.

##Use the code

For all users:

1. Install Ruijie Supplicant.
2. Load `8021x.exe` with any HEX editor.
3. Replace string `SUAdvapi.dll` with `FKAdvapi.dll`.

Then for 64bit OS users:

1. Install Microsoft Visual Studio 2012.
2. Clone the whole repo to your disk.
3. Open the project in VS2012, then go to `TODO:` in `SetTimerHook` method.
4. Do whatever you like with the code.
8. Copy `FKAdvapi.dll` and `EasyHook64.dll` to Ruijie's folder.

And for 32bit OS users:

1. Install Microsoft Visual Studio 2012.
2. Clone the whole repo to your disk.
3. Open the project in VS2012, then go to `TODO:` in `SetTimerHook` method.
4. Change the build profile to x86.
5. Download EasyHook 2.6, put `EasyHook32.dll` to your build folder and put `EasyHook32.lib` to your source folder.
6. Replace `EasyHook64.lib` to `EasyHook32.lib` in the source files.
7. Do whatever you like with the code.
8. Copy `FKAdvapi.dll` and `EasyHook32.dll` to Ruijie's folder.

----------------

Regards,

Paddy Xu, 27/02/2013.