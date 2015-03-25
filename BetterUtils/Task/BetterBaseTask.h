//
//  BetterBaseTask.h
//  BetterUtils
//
//  Created by lingchen on 3/23/15.
//  Copyright (c) 2015 HH. All rights reserved.
//

#import <Foundation/Foundation.h>

//task should store in db ~

typedef NS_ENUM(int, BetterTaskType) {
    BetterTaskTypeNormal,   // Down, default, normal priority
    BetterTaskTypeLongTime, // Up, long time tasks, e.g. send mail with attachments
    BetterTaskTypeDownHigh, // Down, independent tasks, separated from normal, use only for time-sensitive scenario. e.g. APNS -> mail detail
    BetterTaskTypeImmediate // Down, process at once when added to taskQueue
};

typedef NS_ENUM(int, BetterTaskBizType) {
    BetterTaskBizTypeDefault,
    BetterTaskBizTypeSync,
    BetterTaskBizTypeUpdate,
};

@interface BetterBaseTask : NSObject

@property (nonatomic, copy) NSString *taskId;

@property (nonatomic, assign) BetterTaskBizType bizType;

- (void)excuteTask;

- (void)cancelTask;

@end

@protocol BetterTaskProtocol <NSObject>

@optional
/*
 taskProtocol 定义了
            task的依赖关系，
            task的合并规则，
            task优先级规则，
            。。。
 */

/**
 *	@brief	task depend on which task
 *
 *	@return	the depend task
 *
 *	Created by hh on 2015-03-23 23:13
 */
- (BetterBaseTask *)taskDependOn;


/**
 *	@brief	任务合并，可以合并的任务一定有依赖关系（顶层节点是同一个）
 *
 *	@param 	other
 *
 *	@return
 *
 *	Created by hh on 2015-03-23 23:17
 */
- (id)taskMerge:(BetterBaseTask *)other;

/**
 *	@brief	task score来控制优先级，任务每次都很快的执行，失败率低，耗时少，得分就高，然后任务的优先级会比较高
 *
 *	@return	满分是10分 （默认是5分；如果某一task执行的一直不顺畅，score -- ，某一task执行很成功，score ++）
 *
 *	Created by lingchen on 2015-03-24 21:15
 */
- (NSInteger)taskScore;





@end
