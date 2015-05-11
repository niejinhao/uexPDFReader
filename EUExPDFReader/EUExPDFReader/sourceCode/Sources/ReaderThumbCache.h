//
//	ReaderThumbCache.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ReaderThumbRequest.h"

@interface ReaderThumbCache : NSObject
{
@private // Instance variables

	NSCache *thumbCache;
}

+ (ReaderThumbCache *)sharedInstance;

+ (void)touchThumbCacheWithGUID:(NSString *)guid;

+ (void)createThumbCacheWithGUID:(NSString *)guid;

+ (void)removeThumbCacheWithGUID:(NSString *)guid;

+ (void)purgeThumbCachesOlderThan:(NSTimeInterval)age;

+ (NSString *)thumbCachePathForGUID:(NSString *)guid;

- (id)thumbRequest:(ReaderThumbRequest *)request priority:(BOOL)priority;

- (void)setObject:(UIImage *)image forKey:(NSString *)key;

- (void)removeObjectForKey:(NSString *)key;

- (void)removeNullForKey:(NSString *)key;

- (void)removeAllObjects;

@end
