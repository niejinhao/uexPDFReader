//
//	ReaderThumbQueue.m
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import "ReaderThumbQueue.h"

@implementation ReaderThumbQueue

//#pragma mark Properties

//@synthesize ;

#pragma mark ReaderThumbQueue class methods

+ (ReaderThumbQueue *)sharedInstance
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	static dispatch_once_t predicate = 0;

	static ReaderThumbQueue *object = nil; // Object

	dispatch_once(&predicate, ^{ object = [self new]; });

	return object; // ReaderThumbQueue singleton
}

#pragma mark ReaderThumbQueue instance methods

- (id)init
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	if ((self = [super init])) // Initialize
	{
		loadQueue = [NSOperationQueue new];

		[loadQueue setName:@"ReaderThumbLoadQueue"];

		[loadQueue setMaxConcurrentOperationCount:1];

		workQueue = [NSOperationQueue new];

		[workQueue setName:@"ReaderThumbWorkQueue"];

		[workQueue setMaxConcurrentOperationCount:1];
	}

	return self;
}

- (void)dealloc
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	[loadQueue release], loadQueue = nil;

	[workQueue release], workQueue = nil;

	[super dealloc];
}

- (void)addLoadOperation:(NSOperation *)operation
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	if ([operation isKindOfClass:[ReaderThumbOperation class]])
	{
		[loadQueue addOperation:operation]; // Add to load queue
	}
}

- (void)addWorkOperation:(NSOperation *)operation
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	if ([operation isKindOfClass:[ReaderThumbOperation class]])
	{
		[workQueue addOperation:operation]; // Add to work queue
	}
}

- (void)cancelOperationsWithGUID:(NSString *)guid
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	[loadQueue setSuspended:YES]; [workQueue setSuspended:YES];

	for (ReaderThumbOperation *operation in loadQueue.operations)
	{
		if ([operation isKindOfClass:[ReaderThumbOperation class]])
		{
			if ([operation.guid isEqualToString:guid]) [operation cancel];
		}
	}

	for (ReaderThumbOperation *operation in workQueue.operations)
	{
		if ([operation isKindOfClass:[ReaderThumbOperation class]])
		{
			if ([operation.guid isEqualToString:guid]) [operation cancel];
		}
	}

	[workQueue setSuspended:NO]; [loadQueue setSuspended:NO];
}

- (void)cancelAllOperations
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	[loadQueue cancelAllOperations]; [workQueue cancelAllOperations];
}

@end

#pragma mark -

//
//	ReaderThumbOperation class implementation
//

@implementation ReaderThumbOperation

@synthesize guid = _guid;

#pragma mark ReaderThumbOperation instance methods

- (id)initWithGUID:(NSString *)guid
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	if ((self = [super init]))
	{
		_guid = [guid retain];
	}

	return self;
}

- (void)dealloc
{
#ifdef DEBUGX
	NSLog(@"%s", __FUNCTION__);
#endif

	[_guid release], _guid = nil;

	[super dealloc];
}

@end
