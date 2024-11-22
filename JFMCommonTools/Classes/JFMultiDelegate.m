//
//  JFMultiDelegate.m
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import "JFMultiDelegate.h"

@interface JFMultiDelegate ()

@property (nonatomic, strong) NSPointerArray *delegates;

@end

@implementation JFMultiDelegate
- (instancetype)init {
    self = [super init];
    if (self) {
        self.delegates = [NSPointerArray weakObjectsPointerArray];
    }
    return self;
}

- (void)addDelegate:(id)delegate {
    [self.delegates addPointer:(__bridge void * _Nullable)(delegate)];
}

- (void)removeDelegate:(id)delegate {
    NSUInteger index = [self.delegates.allObjects indexOfObject:delegate];
    if (index != NSNotFound) {
        [self.delegates removePointerAtIndex:index];
    }
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)selector {
    NSMethodSignature *signature = [super methodSignatureForSelector:selector];
    if (!signature) {
        for (id delegate in self.delegates) {
            if ([delegate respondsToSelector:selector]) {
                signature = [delegate methodSignatureForSelector:selector];
                break;
            }
        }
    }
    if (!signature) {
      signature = [self methodSignatureForSelector:@selector(emptyImp)];
    }
    return signature;
}

- (void)forwardInvocation:(NSInvocation *)invocation {
    for (id delegate in self.delegates) {
        if ([delegate respondsToSelector:invocation.selector]) {
            [invocation invokeWithTarget:delegate];
        }
    }
}

- (void)emptyImp {
  
}

- (BOOL)respondsToSelector:(SEL)aSelector {
  return YES;
}
@end
