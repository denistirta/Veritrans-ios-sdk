//
//  VTStringHelper.m
//  MidtransKit
//
//  Created by Arie on 6/16/16.
//  Copyright © 2016 Veritrans. All rights reserved.
//

#import "VTStringHelper.h"
#import <UIKit/UIKit.h>
@implementation VTStringHelper

+ (NSString *)emptyString {
    return @"";
}

+ (NSMutableAttributedString *)indentText:(NSAttributedString *)attributedString {
    NSMutableAttributedString *mutableAttributedString = [[NSMutableAttributedString alloc] initWithAttributedString:attributedString];
    NSMutableParagraphStyle *paragrahStyle = [[NSMutableParagraphStyle alloc] init];
    paragrahStyle.lineSpacing = 2.0f;
    paragrahStyle.paragraphSpacing = 2.0f;
    paragrahStyle.paragraphSpacingBefore = 2.0f;
    paragrahStyle.firstLineHeadIndent = 0.0f;  // First line is the one with bullet point
    paragrahStyle.headIndent = 28.0f;    // Set the indent for given bullet character and size font
    [mutableAttributedString addAttribute:NSParagraphStyleAttributeName value:paragrahStyle
                                    range:NSMakeRange(0, attributedString.length)];
    return mutableAttributedString;
}

+ (NSMutableAttributedString *)indentTextWithDefaultStyle:(NSAttributedString *)attributedString {
    NSMutableAttributedString *mutableAttributedString = [self indentText:attributedString];
    [mutableAttributedString addAttribute:NSFontAttributeName
                                    value:[UIFont fontWithName:@"HelveticaNeue" size:14.0f]
                                    range:NSMakeRange(0, attributedString.length)];
    [mutableAttributedString addAttribute:NSForegroundColorAttributeName
                                    value:[UIColor lightGrayColor]
                                    range:NSMakeRange(0, attributedString.length)];
    return mutableAttributedString;
}

+ (NSMutableAttributedString *)numberingTextWithLocalizedString:(NSString *)localizedString
                                                 withTotalCount:(NSUInteger)count{
    
    NSMutableArray *points = [[NSMutableArray alloc] init];
    
    for (NSInteger i = 1; i <= count; i++) {
        NSString *key = [NSString stringWithFormat:@"%@%ld", localizedString, (long)i];
        [points addObject:[NSString stringWithFormat:@"%ld.\t%@", (long)i, NSLocalizedString(key, nil)]];
    }
    
    NSMutableAttributedString *mutableAttributedString = [[NSMutableAttributedString alloc] initWithString:[points componentsJoinedByString:@"\n"]];
    mutableAttributedString = [self indentTextWithDefaultStyle:mutableAttributedString];
    return mutableAttributedString;
}

@end
