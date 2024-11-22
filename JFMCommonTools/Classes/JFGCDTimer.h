//
//  JFGCDTimer.h
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JFGCDTimer : NSObject
// 默认主线程创建
- (instancetype)initWithTimeInterval:(NSTimeInterval)interval repeat:(BOOL)repeat block:(dispatch_block_t)block;
- (instancetype)initWithTimeInterval:(NSTimeInterval)interval repeat:(BOOL)repeat queue:(dispatch_queue_t)queue block:(dispatch_block_t)block;
+ (instancetype)scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeat:(BOOL)repeat queue:(dispatch_queue_t)queue block:(dispatch_block_t)block;
+ (instancetype)scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeat:(BOOL)repeat block:(dispatch_block_t)block;
- (void)setTimeInterval:(NSTimeInterval)interval;
- (void)stop;
- (void)restart;
- (void)invalidate;
@end

NS_ASSUME_NONNULL_END
