//
//	ReaderThumbQueue.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReaderThumbQueue : NSObject
{
@private // Instance variables

	NSOperationQueue *loadQueue;

	NSOperationQueue *workQueue;
}

+ (ReaderThumbQueue *)sharedInstance;

- (void)addLoadOperation:(NSOperation *)operation;

- (void)addWorkOperation:(NSOperation *)operation;

- (void)cancelOperationsWithGUID:(NSString *)guid;

- (void)cancelAllOperations;

@end

#pragma mark -

//
//	ReaderThumbOperation class interface
//

@interface ReaderThumbOperation : NSOperation
{
@protected // Instance variables

	NSString *_guid;
}

@property (nonatomic, retain, readonly) NSString *guid;

- (id)initWithGUID:(NSString *)guid;

@end
