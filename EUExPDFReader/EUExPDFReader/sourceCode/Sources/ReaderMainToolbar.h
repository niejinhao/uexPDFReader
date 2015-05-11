//
//	ReaderMainToolbar.h
//	Reader v2.5.4
//
//	Created by asdkios on 2013-03-20.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "UIXToolbarView.h"

@class ReaderMainToolbar;
@class ReaderDocument;

@protocol ReaderMainToolbarDelegate <NSObject>

@required // Delegate protocols

- (void)tappedInToolbar:(ReaderMainToolbar *)toolbar doneButton:(UIButton *)button;
- (void)tappedInToolbar:(ReaderMainToolbar *)toolbar thumbsButton:(UIButton *)button;
- (void)tappedInToolbar:(ReaderMainToolbar *)toolbar printButton:(UIButton *)button;
- (void)tappedInToolbar:(ReaderMainToolbar *)toolbar emailButton:(UIButton *)button;
- (void)tappedInToolbar:(ReaderMainToolbar *)toolbar markButton:(UIButton *)button;

@end

@interface ReaderMainToolbar : UIXToolbarView
{
@private // Instance variables

	UIButton *markButton;

	UIImage *markImageN;
	UIImage *markImageY;
}

@property (nonatomic, assign, readwrite) id <ReaderMainToolbarDelegate> delegate;

- (id)initWithFrame:(CGRect)frame document:(ReaderDocument *)object;

- (void)setBookmarkState:(BOOL)state;

- (void)hideToolbar;
- (void)showToolbar;

@end
