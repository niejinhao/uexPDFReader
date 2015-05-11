//
//	ReaderThumbRequest.m
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import "ReaderThumbRequest.h"
#import "ReaderThumbView.h"

@implementation ReaderThumbRequest

#pragma mark Properties

@synthesize guid = _guid;
@synthesize fileURL = _fileURL;
@synthesize password = _password;
@synthesize thumbView = _thumbView;
@synthesize thumbPage = _thumbPage;
@synthesize thumbSize = _thumbSize;
@synthesize thumbName = _thumbName;
@synthesize targetTag = _targetTag;
@synthesize cacheKey = _cacheKey;
@synthesize scale = _scale;

#pragma mark ReaderThumbRequest class methods

+ (id)forView:(ReaderThumbView *)view fileURL:(NSURL *)url password:(NSString *)phrase guid:(NSString *)guid page:(NSInteger)page size:(CGSize)size
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	return [[[ReaderThumbRequest alloc] initWithView:view fileURL:url password:phrase guid:guid page:page size:size] autorelease];
}

#pragma mark ReaderThumbRequest instance methods

- (id)initWithView:(ReaderThumbView *)view fileURL:(NSURL *)url password:(NSString *)phrase guid:(NSString *)guid page:(NSInteger)page size:(CGSize)size
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	if ((self = [super init])) // Initialize object
	{
		NSInteger w = size.width; NSInteger h = size.height;

		_thumbView = [view retain]; _thumbPage = page; _thumbSize = size;

		_fileURL = [url copy]; _password = [phrase copy]; _guid = [guid copy];

		_thumbName = [[NSString alloc] initWithFormat:@"%07d-%04dx%04d", page, w, h];

		_cacheKey = [[NSString alloc] initWithFormat:@"%@+%@", _thumbName, _guid];

		_targetTag = [_cacheKey hash]; _thumbView.targetTag = _targetTag;

		_scale = [[UIScreen mainScreen] scale]; // Thumb screen scale
	}

	return self;
}

- (void)dealloc
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	[_guid release], _guid = nil;

	[_fileURL release], _fileURL = nil;

	[_password release], _password = nil;

	[_thumbView release], _thumbView = nil;

	[_thumbName release], _thumbName = nil;

	[_cacheKey release], _cacheKey = nil;

	[super dealloc];
}

@end
