//
//	ReaderThumbFetch.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ReaderThumbQueue.h"

@class ReaderThumbRequest;

@interface ReaderThumbFetch : ReaderThumbOperation
{
@private // Instance variables

	ReaderThumbRequest *request;
}

- (id)initWithRequest:(ReaderThumbRequest *)object;

@end
