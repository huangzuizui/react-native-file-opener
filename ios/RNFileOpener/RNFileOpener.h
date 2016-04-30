#import "RCTBridgeModule.h"
#import "RCTBridge.h"

@import UIKit;

@interface FileOpener : NSObject <RCTBridgeModule>
@property (nonatomic) UIDocumentInteractionController * FileOpener;
@end