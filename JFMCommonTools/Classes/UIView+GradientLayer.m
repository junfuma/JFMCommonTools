//
//  UIView+GradientLayer.m
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import "UIView+GradientLayer.h"

@implementation UIView (GradientLayer)
/**
 * 设置 view 渐变色
 *
 * @param frame frame
 * @param colors 渐变颜色数组
 *  默认渐变方向 (0,0)  -> (1,1)
 */
+ (CAGradientLayer *)createGradientLayerWithFrame:(CGRect)frame
                                           colors:(NSArray*)colors {
  CAGradientLayer *gl = [CAGradientLayer layer];
  gl.frame = frame;
  gl.startPoint = CGPointMake(0, 0);
  gl.endPoint = CGPointMake(1, 1);
  gl.colors = colors;
  gl.locations = @[@(0.0),@(1.0)];
  return gl;
}

/**
 * 设置 view 渐变色
 *
 * @param frame frame
 * @param colors 渐变颜色数组
 * @param startPoint 渐变起始点
 * @param endPoint  渐变终止点
 */
+ (CAGradientLayer *)createGradientLayerWithFrame:(CGRect)frame
                                           colors:(NSArray *)colors
                                       startPoint:(CGPoint)startPoint
                                         endPoint:(CGPoint)endPoint {
  CAGradientLayer *gl = [CAGradientLayer layer];
  gl.frame = frame;
  gl.startPoint = startPoint;
  gl.endPoint = endPoint;
  gl.colors = colors;
  gl.locations = @[@(0.0),@(1.0)];
  return gl;
}

#pragma mark - 设置部分圆角
/**
 *  设置部分圆角(绝对布局)
 *
 *  @param corners 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
 *  @param radii   需要设置的圆角大小 例如 CGSizeMake(20.0f, 20.0f)
 */
- (void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii {
    
    UIBezierPath* rounded = [UIBezierPath bezierPathWithRoundedRect:self.bounds byRoundingCorners:corners cornerRadii:radii];
    CAShapeLayer* shape = [[CAShapeLayer alloc] init];
    [shape setPath:rounded.CGPath];
    
    self.layer.mask = shape;
}

/**
 *  设置部分圆角(相对布局)
 *
 *  @param corners 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
 *  @param radii   需要设置的圆角大小 例如 CGSizeMake(20.0f, 20.0f)
 *  @param rect    需要设置的圆角view的rect
 */
- (void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii
                 viewRect:(CGRect)rect {
    
    UIBezierPath* rounded = [UIBezierPath bezierPathWithRoundedRect:rect byRoundingCorners:corners cornerRadii:radii];
    CAShapeLayer* maskLayer = [[CAShapeLayer alloc] init];
    maskLayer.frame = rect;
    maskLayer.path = rounded.CGPath;

    
    self.layer.mask = maskLayer;
}

@end
