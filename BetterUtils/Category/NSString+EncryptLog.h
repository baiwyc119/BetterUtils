//
//  NSString+EncryptLog.h
//  BetterUtils
//
//  Created by lingchen on 11/26/14.
//  Copyright (c) 2014 HH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (EncryptLog)

+ (NSString *)encryptWithKey:(NSString *)key withFormat:(NSString *)format,...;

+ (NSString *)decryptWithKey:(NSString *)key withString:(NSString *)strEncrypt;

@end
