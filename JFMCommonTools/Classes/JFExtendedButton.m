//
//  JFExtendedButton.m
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import "JFExtendedButton.h"

@implementation JFExtendedButton

- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event {
    UIEdgeInsets hitEdgeInsets = self.hitTestEdgeInsets;
    CGRect hitBounds = UIEdgeInsetsInsetRect(self.bounds, hitEdgeInsets);
    return CGRectContainsPoint(hitBounds, point);
}


@end
