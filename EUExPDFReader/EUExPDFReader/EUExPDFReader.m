//
//  EUExPDFReader.m
//  AppCan
//
//  Created by AppCan on 13-3-21.
//
//

#import "EUExPDFReader.h"
#import "ReaderViewController.h"



@interface EUExPDFReader()<ReaderViewControllerDelegate>
@property (nonatomic,strong)ReaderViewController *readerController;
@property (nonatomic,strong)UIWebView *pdfView;
@end

@implementation EUExPDFReader



- (void)openPDFReader:(NSMutableArray *)inArguments{
    
    ACArgsUnpack(NSString *inPath) = inArguments;
    if (!inPath) {
        return;
    }
    NSString *absPath = [self absPath:inPath];
    NSString *kResScheme = @"res://";
    if ([inPath hasPrefix:kResScheme]) {
        NSString *documentPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject;
        NSString *filePath = [inPath substringFromIndex:kResScheme.length];
        NSString *copyPath = [documentPath stringByAppendingPathComponent:filePath];
        if([[NSFileManager defaultManager] copyItemAtPath:absPath toPath:copyPath error:nil]){
            absPath = copyPath;
        }
        
    }

    //Document password (for unlocking most encrypted PDF files)
    NSString *phrase = nil;
	ReaderDocument *document = [ReaderDocument withDocumentFilePath:absPath password:phrase];
    if (!document) {
        return;
    }
    

    if (!self.readerController) {
        self.readerController = [[ReaderViewController alloc] initWithReaderDocument:document];
    }
    self.readerController.delegate = self;
    [[self.webViewEngine viewController] presentViewController:self.readerController animated:YES completion:nil];
}



- (void)openView:(NSMutableArray *)inArguments{
    ACArgsUnpack(NSDictionary *info) = inArguments;
    CGSize screenSize = [UIScreen mainScreen].bounds.size;
    NSNumber *xNumber = numberArg(info[@"x"]);
    NSNumber *yNumber = numberArg(info[@"y"]);
    NSNumber *widthNumber = numberArg(info[@"width"]);
    NSNumber *heightNumber = numberArg(info[@"height"]);
    NSString *path = stringArg(info[@"path"]);
    UEX_PARAM_GUARD_NOT_NIL(path);
    NSString *absPath = [self absPath:path];
    BOOL scrollWithWeb = [numberArg(info[@"scrollWithWeb"]) boolValue];
    CGFloat x = xNumber ? xNumber.floatValue : 0;
    CGFloat y = yNumber ? yNumber.floatValue : 0;
    CGFloat width = widthNumber ? widthNumber.floatValue : screenSize.width;
    CGFloat height = heightNumber ? heightNumber.floatValue : screenSize.height;
    if (!self.pdfView) {
        self.pdfView = [[UIWebView alloc] init];
        self.pdfView.scalesPageToFit = YES;
    }
    
    self.pdfView.frame = CGRectMake(x, y, width, height);
    [self.pdfView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:absPath]]];
    if (scrollWithWeb) {
        [[self.webViewEngine webScrollView] addSubview:self.pdfView];
    }else{
        [[self.webViewEngine webView] addSubview:self.pdfView];
    }
}

- (void)closeView:(NSMutableArray *)inArguments{
    [self.pdfView removeFromSuperview];
    self.pdfView = nil;
}


- (void)dismissReaderViewController:(ReaderViewController *)viewController{
    [self close:nil];
    
}




- (void)close:(NSMutableArray *)inArguments{
    [self.readerController dismissViewControllerAnimated:YES completion:nil];
    self.readerController.delegate = nil;
    self.readerController = nil;
}



- (void)clean{
    [self close:nil];
    [self closeView:nil];
}

- (void)dealloc{
    [self clean];
}

@end
