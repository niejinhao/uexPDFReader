//
//	ReaderMainPagebar.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ReaderThumbView.h"

@class ReaderMainPagebar;
@class ReaderTrackControl;
@class ReaderPagebarThumb;
@class ReaderDocument;

@protocol ReaderMainPagebarDelegate <NSObject>

@required // Delegate protocols

- (void)pagebar:(ReaderMainPagebar *)pagebar gotoPage:(NSInteger)page;

@end

@interface ReaderMainPagebar : UIView
{
@private // Instance variables

	ReaderDocument *document;

	ReaderTrackControl *trackControl;

	NSMutableDictionary *miniThumbViews;

	ReaderPagebarThumb *pageThumbView;

	UILabel *pageNumberLabel;

	UIView *pageNumberView;

	NSTimer *enableTimer;
	NSTimer *trackTimer;
}

@property (nonatomic, assign, readwrite) id <ReaderMainPagebarDelegate> delegate;

- (id)initWithFrame:(CGRect)frame document:(ReaderDocument *)object;

- (void)updatePagebar;

- (void)hidePagebar;
- (void)showPagebar;

@end

#pragma mark -

//
//	ReaderTrackControl class interface
//

@interface ReaderTrackControl : UIControl
{
@private // Instance variables

	CGFloat _value;
}

@property (nonatomic, assign, readonly) CGFloat value;

@end

#pragma mark -

//
//	ReaderPagebarThumb class interface
//

@interface ReaderPagebarThumb : ReaderThumbView
{
@private // Instance variables
}

- (id)initWithFrame:(CGRect)frame small:(BOOL)small;

@end

#pragma mark -

//
//	ReaderPagebarShadow class interface
//

@interface ReaderPagebarShadow : UIView
{
@private // Instance variables
}

@end
