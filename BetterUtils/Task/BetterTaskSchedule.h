//
//  BetterTaskSchedule.h
//  BetterUtils
//
//  Created by lingchen on 3/23/15.
//  Copyright (c) 2015 HH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BetterBaseTask.h"

//task schedule
@interface BetterTaskSchedule : NSObject

- (void)addTaskSchedule:(BetterBaseTask *)task;

- (void)removeTask:(BetterBaseTask *)task;

- (void)removeAllTasks;



@end
