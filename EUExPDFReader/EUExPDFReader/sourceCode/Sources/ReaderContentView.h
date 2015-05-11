//
//	ReaderContentView.h
//	Reader v2.5.4
//
//	Created by asdkios on 2013-03-20.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ReaderThumbView.h"

@class ReaderContentView;
@class ReaderContentPage;
@class ReaderContentThumb;

@protocol ReaderContentViewDelegate <NSObject>

@required // Delegate protocols

- (void)contentView:(ReaderContentView *)contentView touchesBegan:(NSSet *)touches;

@end

@interface ReaderContentView : UIScrollView <UIScrollViewDelegate>
{
@private // Instance variables

	ReaderContentPage *theContentView;

	ReaderContentThumb *theThumbView;

	UIView *theContainerView;

	CGFloat zoomAmount;
}

@property (nonatomic, assign, readwrite) id <ReaderContentViewDelegate> message;

- (id)initWithFrame:(CGRect)frame fileURL:(NSURL *)fileURL page:(NSUInteger)page password:(NSString *)phrase;

- (void)showPageThumb:(NSURL *)fileURL page:(NSInteger)page password:(NSString *)phrase guid:(NSString *)guid;

- (id)singleTap:(UITapGestureRecognizer *)recognizer;

- (void)zoomIncrement;
- (void)zoomDecrement;
- (void)zoomReset;

@end

#pragma mark -

//
//	ReaderContentThumb class interface
//

@interface ReaderContentThumb : ReaderThumbView
{
@private // Instance variables
}

@end
