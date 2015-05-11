//
//	ReaderThumbsView.h
//	Reader v2.5.4
//
//	Created by asdkios on 2011-09-01.
//	Copyright © 2013-2014 asdkios. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ReaderThumbView.h"

@class ReaderThumbsView;

@protocol ReaderThumbsViewDelegate <NSObject, UIScrollViewDelegate>

@required // Delegate protocols

- (NSUInteger)numberOfThumbsInThumbsView:(ReaderThumbsView *)thumbsView;

- (id)thumbsView:(ReaderThumbsView *)thumbsView thumbCellWithFrame:(CGRect)frame;

- (void)thumbsView:(ReaderThumbsView *)thumbsView updateThumbCell:(id)thumbCell forIndex:(NSInteger)index;

- (void)thumbsView:(ReaderThumbsView *)thumbsView didSelectThumbWithIndex:(NSInteger)index;

@optional // Delegate protocols

- (void)thumbsView:(ReaderThumbsView *)thumbsView refreshThumbCell:(id)thumbCell forIndex:(NSInteger)index;

- (void)thumbsView:(ReaderThumbsView *)thumbsView didPressThumbWithIndex:(NSInteger)index;

@end

@interface ReaderThumbsView : UIScrollView <UIScrollViewDelegate, UIGestureRecognizerDelegate>
{
@private // Instance variables

	CGPoint lastContentOffset;

	ReaderThumbView *touchedCell;

	NSMutableArray *thumbCellsQueue;

	NSMutableArray *thumbCellsVisible;

	NSInteger _thumbsX, _thumbsY, _thumbX;

	CGSize _thumbSize, _lastViewSize;

	NSUInteger _thumbCount;

	BOOL canUpdate;
}

@property (nonatomic, assign, readwrite) id <ReaderThumbsViewDelegate> delegate;

- (void)setThumbSize:(CGSize)thumbSize;

- (void)reloadThumbsCenterOnIndex:(NSInteger)index;

- (void)reloadThumbsContentOffset:(CGPoint)newContentOffset;

- (void)refreshThumbWithIndex:(NSInteger)index;

- (void)refreshVisibleThumbs;

- (CGPoint)insetContentOffset;

@end
