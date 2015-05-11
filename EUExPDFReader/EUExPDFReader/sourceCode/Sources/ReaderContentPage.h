//
//	ReaderContentPage.h
//	Reader v2.5.5
//
//	Created by asdkios on 2013-03-20.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ReaderContentPage : UIView
{
@private // Instance variables

	NSMutableArray *_links;

	CGPDFDocumentRef _PDFDocRef;

	CGPDFPageRef _PDFPageRef;

	NSInteger _pageAngle;

	CGFloat _pageWidth;
	CGFloat _pageHeight;
	CGFloat _pageOffsetX;
	CGFloat _pageOffsetY;
}

- (id)initWithURL:(NSURL *)fileURL page:(NSInteger)page password:(NSString *)phrase;

- (id)singleTap:(UITapGestureRecognizer *)recognizer;

@end

#pragma mark -

//
//	ReaderDocumentLink class interface
//

@interface ReaderDocumentLink : NSObject
{
@private // Instance variables

	CGPDFDictionaryRef _dictionary;

	CGRect _rect;
}

@property (nonatomic, assign, readonly) CGRect rect;

@property (nonatomic, assign, readonly) CGPDFDictionaryRef dictionary;

+ (id)withRect:(CGRect)linkRect dictionary:(CGPDFDictionaryRef)linkDictionary;

- (id)initWithRect:(CGRect)linkRect dictionary:(CGPDFDictionaryRef)linkDictionary;

@end
