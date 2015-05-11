//
//	ThumbsMainToolbar.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "UIXToolbarView.h"

@class ThumbsMainToolbar;

@protocol ThumbsMainToolbarDelegate <NSObject>

@required // Delegate protocols

- (void)tappedInToolbar:(ThumbsMainToolbar *)toolbar doneButton:(UIButton *)button;

- (void)tappedInToolbar:(ThumbsMainToolbar *)toolbar showControl:(UISegmentedControl *)control;

@end

@interface ThumbsMainToolbar : UIXToolbarView
{
@private // Instance variables
}

@property (nonatomic, assign, readwrite) id <ThumbsMainToolbarDelegate> delegate;

- (id)initWithFrame:(CGRect)frame title:(NSString *)title;

@end
