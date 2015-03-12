//
//  BetterLogFileManager.h
//  BetterUtils
//
//  Created by lingchen on 11/26/14.
//  Copyright (c) 2014 HH. All rights reserved.
//


#import <CocoaLumberjack/DDFileLogger.h>
@interface BetterLogFileManager : DDLogFileManagerDefault

@property (nonatomic, strong) NSString *logFileName;
@end
