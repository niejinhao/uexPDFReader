//
//  EUExPDFReader.h
//  AppCan
//
//  Created by AppCan on 13-3-21.
//
//

#import <UIKit/UIKit.h>
#import "EUExBase.h"
#import "EUExBaseDefine.h"

#import "ReaderViewController.h"

@interface EUExPDFReader : EUExBase <ReaderViewControllerDelegate>
{
    ReaderViewController *readerController;
}

- (void)openPDFReader:(NSMutableArray *)inArguments;
- (void)close:(NSMutableArray *)inArguments;

@end
