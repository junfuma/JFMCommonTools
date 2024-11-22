//
//  JFMultiDelegate.h
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define gmd_multi_delegate_default_header(protocol_name)                                \
  gmd_multi_delegate_header(protocol_name, MultiDelegate)

#define gmd_multi_delegate_default_imp(protocol_name)                                   \
  gmd_multi_delegate_imp(protocol_name, MultiDelegate)


#define gmd_multi_delegate_header(protocol_name, p_name)                                \
@property (nonatomic, strong, nullable) JFMultiDelegate<protocol_name> *p_name;         \
-(void)add##p_name:(id<protocol_name>)delegate;                                         \
-(void)remove##p_name:(id<protocol_name>)delegate;

#define gmd_multi_delegate_imp(protocol_name, p_name)                                   \
- (JFMultiDelegate<protocol_name> *)p_name {                                            \
  if (!_##p_name) {                                                                     \
    _##p_name = [[JFMultiDelegate<protocol_name> alloc] init];                          \
  }                                                                                     \
  return _##p_name;                                                                     \
}                                                                                       \
                                                                                        \
-(void)add##p_name:(id<protocol_name>)delegate {                                        \
  [self.p_name addDelegate:delegate];                                                   \
}                                                                                       \
                                                                                        \
-(void)remove##p_name:(id<protocol_name>)delegate {                                     \
  [self.p_name removeDelegate:delegate];                                                \
}


/*
 使用方法：
 .h gmd_multi_delegate_default_header(xxxDelegate)
 .m gmd_multi_delegate_default_imp(xxxDelegate)
 
 [self addMultiDelegate:obj];
 
 [self.MultiDelegate delegateFunction:param];
 
 [self removeMultiDelegate:obj];

 */

@interface JFMultiDelegate : NSObject
- (void)addDelegate:(id)delegate;
- (void)removeDelegate:(id)delegate;
@end

NS_ASSUME_NONNULL_END
