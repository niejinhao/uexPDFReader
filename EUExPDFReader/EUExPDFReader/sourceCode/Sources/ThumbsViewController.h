//
//	ThumbsViewController.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ThumbsMainToolbar.h"
#import "ReaderThumbsView.h"

@class ThumbsViewController;
@class ReaderDocument;

@protocol ThumbsViewControllerDelegate <NSObject>

@required // Delegate protocols

- (void)thumbsViewController:(ThumbsViewController *)viewController gotoPage:(NSInteger)page;

- (void)dismissThumbsViewController:(ThumbsViewController *)viewController;

@end

@interface ThumbsViewController : UIViewController <ThumbsMainToolbarDelegate, ReaderThumbsViewDelegate>
{
@private // Instance variables

	ReaderDocument *document;

	ThumbsMainToolbar *mainToolbar;

	ReaderThumbsView *theThumbsView;

	NSMutableArray *bookmarked;

	BOOL updateBookmarked;

	CGPoint thumbsOffset;
	CGPoint markedOffset;

	BOOL showBookmarked;
}

@property (nonatomic, assign, readwrite) id <ThumbsViewControllerDelegate> delegate;

- (id)initWithReaderDocument:(ReaderDocument *)object;

@end

#pragma mark -

//
//	ThumbsPageThumb class interface
//

@interface ThumbsPageThumb : ReaderThumbView
{
@private // Instance variables

	UIView *backView;

	UIView *maskView;

	UILabel *textLabel;

	UIImageView *bookMark;

	CGSize maximumSize;

	CGRect defaultRect;
}

- (CGSize)maximumContentSize;

- (void)showText:(NSString *)text;

- (void)showBookmark:(BOOL)show;

@end
