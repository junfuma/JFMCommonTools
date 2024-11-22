//
//  UIView+GradientLayer.h
//  JFMCommonTools
//
//  Created by Alex on 2024/11/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (GradientLayer)
/**
 * 设置 view 渐变色
 *
 * @param frame frame
 * @param colors 渐变颜色数组
 *  默认渐变方向 (0,0)  -> (1,1) 数组格式  @[(__bridge id)UIColorHex(#FF0000).CGColor,(__bridge id)UIColorHex(#FF0000).CGColor]
 */
+ (CAGradientLayer *)createGradientLayerWithFrame:(CGRect)frame
                                           colors:(NSArray *)colors;

/**
 * 设置 view 渐变色
 *
 * @param frame frame
 * @param colors 渐变颜色数组  格式@[(__bridge id)UIColorHex(#FF0000).CGColor,(__bridge id)UIColorHex(#FF0000).CGColor]
 * @param startPoint 渐变起始点
 * @param endPoint  渐变终止点
 */
+ (CAGradientLayer *)createGradientLayerWithFrame:(CGRect)frame
                                           colors:(NSArray *)colors
                                       startPoint:(CGPoint)startPoint
                                         endPoint:(CGPoint)endPoint;
#pragma mark - 设置部分圆角
/**
 *  设置部分圆角(绝对布局)
 *
 *  @param corners 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
 *  @param radii   需要设置的圆角大小 例如 CGSizeMake(20.0f, 20.0f)
 */
- (void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii;
/**
 *  设置部分圆角(相对布局)
 *
 *  @param corners 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
 *  @param radii   需要设置的圆角大小 例如 CGSizeMake(20.0f, 20.0f)
 *  @param rect    需要设置的圆角view的rect
 */
- (void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii
                 viewRect:(CGRect)rect;
@end

NS_ASSUME_NONNULL_END
