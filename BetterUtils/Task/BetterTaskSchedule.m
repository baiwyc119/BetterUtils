//
//  BetterTaskSchedule.m
//  BetterUtils
//
//  Created by lingchen on 3/23/15.
//  Copyright (c) 2015 HH. All rights reserved.
//

#import "BetterTaskSchedule.h"



@interface BetterTaskSchedule()

@property (nonatomic, strong) NSOperationQueue *operationQueue;

@property (nonatomic,getter=isExecuting) BOOL executing;

@property (nonatomic, strong) NSArray *taskContainer;

@property (nonatomic, strong) dispatch_queue_t dispatchQueue;

@end

@implementation BetterTaskSchedule

+ (instancetype)sharedInstance
{
    static dispatch_once_t once;
    static BetterTaskSchedule *instance;
    dispatch_once(&once, ^{
        instance = [self new];
        instance.operationQueue = [NSOperationQueue new];
        instance.dispatchQueue = dispatch_queue_create("com.hh.bettertask.queue", DISPATCH_QUEUE_SERIAL);
        [instance.operationQueue setMaxConcurrentOperationCount:NSOperationQueueDefaultMaxConcurrentOperationCount];
    });
    return instance;
}



@end
