//
//  SListViewCell.m
//  SPhoto
//
//  Created by SunJiangting on 12-8-12.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "SListViewCell.h"

@implementation SListViewCell
@synthesize separatorView = _separatorView1;

- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier {
    self = [super init];
    if (self) {
        // Initialization code
        self.reuseIdentifier = reuseIdentifier;
        _separatorView1 = [[UIView alloc] init];
        [self addSubview:_separatorView1];
    }
    return self;
}

@end
