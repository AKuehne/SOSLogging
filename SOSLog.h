/*
Copyright (c) 2009, Meinhard Gredig

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 */

// SOSLog.h

#import <Foundation/Foundation.h>

#if SOSLOGGING
#import "Socket.h"
#define log(level, message, ...){\
[SOSLog log:(int)level fromFile:[@__FILE__ lastPathComponent] fromLine:__LINE__ withMessage:(NSString *)message,##__VA_ARGS__];\
}
#else
#define log(level, message, ...){}
#endif

#define _SOS_VERSION_MAJOR 1
#define _SOS_VERSION_MINOR 2

enum {
    sos_Off = 0,
    sos_Fatal,
    sos_Error,
	sos_Warn,
    sos_Info,
    sos_Debug,
    sos_Trace,
};

@interface SOSLog : NSObject {}

+(void)setIP:(NSString *)theIP;
+(void)setGlobalLogLevel:(int)level;
+(void)setLogLevel:(int)theLevel forComponent:(NSString *)theComponentsName;
+(void)showLogLevel:(BOOL)showLevel andComponentName:(BOOL)showComponentName andLineNumber:(BOOL)showLineNumber;
+(void)log:(int)atLevel fromFile:(NSString *)theFile fromLine:(int)theLine withMessage:(NSString *)theMessage, ... ;

@end
