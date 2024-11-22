//
//  NSObject+CurrentViewController.m
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import "NSObject+CurrentViewController.h"

@implementation NSObject (CurrentViewController)
/// 获取当前UI最顶层控制器 可以通过该控制器push到下一页
- (UIViewController *)JFCurrentVC {
  UIViewController *rootViewController = [UIApplication sharedApplication].windows.firstObject.rootViewController;
  
  UIViewController *currentVC = [self getCurrentVCFrom:rootViewController];
  
  return currentVC;
}

- (UIViewController *)getCurrentVCFrom:(UIViewController *)rootVC {
  UIViewController *currentVC;
  
  if ([rootVC presentedViewController]) {
    // 视图是被presented出来的
    rootVC = [rootVC presentedViewController];
  }
  if ([rootVC isKindOfClass:[UITabBarController class]]) {
    // 根视图为UITabBarController
    currentVC = [self getCurrentVCFrom:[(UITabBarController *)rootVC selectedViewController]];
  } else if ([rootVC isKindOfClass:[UINavigationController class]]){
    // 根视图为UINavigationController
    currentVC = [self getCurrentVCFrom:[(UINavigationController *)rootVC visibleViewController]];
  }
  else {
    // 根视图为非导航类
    currentVC = rootVC;
  }
  
  return currentVC;
}
@end
