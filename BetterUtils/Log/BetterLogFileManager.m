//
//  BetterLogFileManager.m
//  BetterUtils
//
//  Created by lingchen on 11/26/14.
//  Copyright (c) 2014 HH. All rights reserved.
//

#import "BetterLogFileManager.h"
#import <CocoaLumberjack/DDFileLogger.h>

@implementation BetterLogFileManager

- (NSString *)newLogFileName
{
    if (_logFileName) {
        NSString *appName = [self applicationName];
        
        NSDateFormatter *dateFormatter = [self logFileDateFormatter];
        NSString *formattedDate = [dateFormatter stringFromDate:[NSDate date]];
        
        return [NSString stringWithFormat:@"%@_%@_%@.log", appName,_logFileName, formattedDate];
    }else
    {
        return [super newLogFileName];
    }
}

- (NSString *)applicationName
{
    static NSString *_appName;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        _appName = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleIdentifier"];
        
        if (! _appName)
        {
            _appName = [[NSProcessInfo processInfo] processName];
        }
        
        if (! _appName)
        {
            _appName = @"";
        }
    });
    
    return _appName;
}

- (NSDateFormatter *)logFileDateFormatter
{
    NSMutableDictionary *dictionary = [[NSThread currentThread]
                                       threadDictionary];
    NSString *dateFormat = @"yyyy'-'MM'-'dd' 'HH'-'mm'";
    NSString *key = [NSString stringWithFormat:@"logFileDateFormatter.%@", dateFormat];
    NSDateFormatter *dateFormatter = [dictionary objectForKey:key];
    if (dateFormatter == nil) {
        dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:dateFormat];
        [dateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
        [dictionary setObject:dateFormatter
                       forKey:key];
    }
    
    return dateFormatter;
}

@end
