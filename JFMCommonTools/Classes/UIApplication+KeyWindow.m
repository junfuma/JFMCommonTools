//
//  UIApplication+KeyWindow.m
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import "UIApplication+KeyWindow.h"

@implementation UIApplication (KeyWindow)
+ (UIWindow *)getKeyWindow {
  if([[[UIApplication sharedApplication] delegate] respondsToSelector:@selector(window)]){
    return [[[UIApplication sharedApplication] delegate] window];
  }else {
    if (@available(iOS 13.0,*)) {
      NSArray *arr = [[[UIApplication sharedApplication] connectedScenes] allObjects];
      UIWindowScene *windowScene = (UIWindowScene *)arr[0];
      UIWindow *_window = windowScene.windows.firstObject;
      if (_window) {
        return _window;
      }
    }
    return [UIApplication sharedApplication].windows.lastObject;
  }
}
@end
