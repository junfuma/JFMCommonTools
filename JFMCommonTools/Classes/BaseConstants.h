//
//  BaseConstants.h
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#ifndef BaseConstants_h
#define BaseConstants_h

#import "UIColor+AlphaColor.h"

//是否是X系列手机
#define JFIPhoneXSeries  ({ \
BOOL ipX = NO; \
if (@available(iOS 11.0, *)) { \
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject]; \
    ipX = window.safeAreaInsets.bottom > 0; \
} \
  ipX; \
})

//是否是 iOS11 的系统
#define IOS_IOS_11  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.f)
//是否是X
#define IOS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)

//全局的宏定义
#define JFScreenW       ([[UIScreen mainScreen] bounds].size.width)
#define JFScreenH       ([[UIScreen mainScreen] bounds].size.height)

//适配iPhone X
#define SafeAreaTopH            (JFIPhoneXSeries ? 44.0 : 20.0)
#define SafeAreaBottomH         (JFIPhoneXSeries? 34.0 : 0.0)
#define SafeAreaAllTopH         (JFIPhoneXSeries ? 88.0 : 64.0)
#define SafeAreaAllBottomH      (JFIPhoneXSeries ? 83.0 : 49.0)

#define JFStatusBarHeight           (JFIPhoneXSeries ? 44.0f : 20.0f)  // 状态栏高度
#define JFNavigationBarHeight        44.0f   // 导航栏高度
#define JFStatusBarAndNavigationBarHeight  (JFStatusBarHeight + JFNavigationBarHeight) // 状态栏+导航栏高度

#define JFMFont(font) [UIFont systemFontOfSize:font weight:UIFontWeightMedium]
#define JFRFont(font) [UIFont systemFontOfSize:font weight:UIFontWeightRegular]
#define JFBFont(font) [UIFont systemFontOfSize:font weight:UIFontWeightBold]

/*
 Tips:
 函数不通过对象调用，所以不会走OC的消息转发流程，效率远高于方法调用；而且函数会有返回值和参数类型以及参数检查，而这些都是宏定义没有的。
 */
UIKIT_STATIC_INLINE NSString * kJFNSStringFromInteger(NSInteger a) {
  return [NSString stringWithFormat:@"%ld", (long)a];
}
UIKIT_STATIC_INLINE NSString * kJFNSStringFromInt(int a) {
  return [NSString stringWithFormat:@"%d", a];
}
UIKIT_STATIC_INLINE NSString * kJFNSStringFromString(NSString *a) {
  return [NSString stringWithFormat:@"%@", a];
}
//判断字符串是否为空
#define JFStringIsEmpty(str) (![str isKindOfClass:[NSString class]] || [str length] == 0 ? YES : NO)
//判断数组是否为空
#define JFArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//判断字典是否为空
#define JFDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
//判断对象是否为空
#define JFObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

UIKIT_STATIC_INLINE UIColor * kJFHexColorWithAlpha(NSString *colorName, CGFloat alpha) {
  return [UIColor JFColorWithHexString:colorName alpha:alpha];
}

UIKIT_STATIC_INLINE UIColor * kJFHexColor(NSString *colorName) {
  return [UIColor JFColorWithHexString:colorName alpha:1.0];
}

#endif /* BaseConstants_h */
