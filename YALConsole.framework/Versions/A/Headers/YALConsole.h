//
//  YALConsole.h
//  YALConsole
//
//  Created by aleksey on 26.12.14.
//  Copyright (c) 2014 Aleksey Chernish. All rights reserved.
//

#import <UIKit/UIKit.h>

#define YALog(args...) ya_log(__LINE__, __PRETTY_FUNCTION__, args);
void ya_log(int lineNumber, const char *funcName, NSString *format,...);

@interface YALConsole : NSObject

#pragma mark - Observer
+ (void)addObserverOf:(id)object keyPath:(NSString *)keyPath forIdentifier:(NSString *)identifier;

#pragma mark - Counter
+ (void)addCounterForIdentifier:(NSString *)identifier;
+ (void)incrementCounterForIdentifier:(NSString *)identifier;

#pragma mark - Action
+ (void)addAction:(void(^)(void))action forIdentifier:(NSString *)identifier;

#pragma mark - Items removing
+ (void)removeItemForIdentifier:(NSString *)identifier;
+ (void)removeAllItems;

#pragma mark - Preferences
+ (void)setHistoryLimit:(NSUInteger)limit; //default is 50
+ (void)setNumberOfTouchesRequired:(NSUInteger)touches; //default is 2

@end