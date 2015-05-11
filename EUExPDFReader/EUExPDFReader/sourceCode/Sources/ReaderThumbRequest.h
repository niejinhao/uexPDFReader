//
//	ReaderThumbRequest.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ReaderThumbView;

@interface ReaderThumbRequest : NSObject
{
@private // Instance variables

	NSURL *_fileURL;

	NSString *_guid;

	NSString *_password;

	NSString *_cacheKey;

	NSString *_thumbName;

	ReaderThumbView *_thumbView;

	NSUInteger _targetTag;

	NSInteger _thumbPage;

	CGSize _thumbSize;

	CGFloat _scale;
}

@property (nonatomic, retain, readonly) NSURL *fileURL;
@property (nonatomic, retain, readonly) NSString *guid;
@property (nonatomic, retain, readonly) NSString *password;
@property (nonatomic, retain, readonly) NSString *cacheKey;
@property (nonatomic, retain, readonly) NSString *thumbName;
@property (nonatomic, retain, readonly) ReaderThumbView *thumbView;
@property (nonatomic, assign, readonly) NSUInteger targetTag;
@property (nonatomic, assign, readonly) NSInteger thumbPage;
@property (nonatomic, assign, readonly) CGSize thumbSize;
@property (nonatomic, assign, readonly) CGFloat scale;

+ (id)forView:(ReaderThumbView *)view fileURL:(NSURL *)url password:(NSString *)phrase guid:(NSString *)guid page:(NSInteger)page size:(CGSize)size;

- (id)initWithView:(ReaderThumbView *)view fileURL:(NSURL *)url password:(NSString *)phrase guid:(NSString *)guid page:(NSInteger)page size:(CGSize)size;

@end
