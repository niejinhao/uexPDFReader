//
//	ReaderThumbView.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ReaderThumbView : UIView
{
@private // Instance variables

	NSUInteger _targetTag;

	NSOperation *_operation;

@protected // Instance variables

	UIImageView *imageView;
}

@property (assign, readwrite) NSOperation *operation;

@property (nonatomic, assign, readwrite) NSUInteger targetTag;

- (void)showImage:(UIImage *)image;

- (void)showTouched:(BOOL)touched;

- (void)reuse;

@end
