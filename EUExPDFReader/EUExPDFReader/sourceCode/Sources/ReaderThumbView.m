//
//	ReaderThumbView.m
//	Reader v2.5.5
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import "ReaderThumbView.h"

@implementation ReaderThumbView

#pragma mark Properties

@synthesize operation = _operation;
@synthesize targetTag = _targetTag;

#pragma mark ReaderThumbView instance methods

- (id)initWithFrame:(CGRect)frame
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	if ((self = [super initWithFrame:frame]))
	{
		self.autoresizesSubviews = NO;
		self.userInteractionEnabled = NO;
		self.contentMode = UIViewContentModeRedraw;
		self.autoresizingMask = UIViewAutoresizingNone;
		self.backgroundColor = [UIColor clearColor];

		imageView = [[UIImageView alloc] initWithFrame:self.bounds];

		imageView.autoresizesSubviews = NO;
		imageView.userInteractionEnabled = NO;
		imageView.contentMode = UIViewContentModeScaleAspectFit;
		imageView.autoresizingMask = UIViewAutoresizingNone;
		//imageView.backgroundColor = [UIColor clearColor];

		[self addSubview:imageView];
	}

	return self;
}

- (void)dealloc
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	[imageView release], imageView = nil;

	[super dealloc];
}

- (void)showImage:(UIImage *)image
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	imageView.image = image; // Show image
}

- (void)showTouched:(BOOL)touched
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif
}

- (void)removeFromSuperview
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	_targetTag = 0; // Clear target tag

	[self.operation cancel], self.operation = nil;

	[super removeFromSuperview];
}

- (void)reuse
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	_targetTag = 0; // Clear target tag

	[self.operation cancel], self.operation = nil;

	imageView.image = nil; // Release image
}

@end
