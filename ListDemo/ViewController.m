//
//  ViewController.m
//  ListDemo
//
//  Created by SunJiangting on 12-9-18.
//  Copyright (c) 2012年 SunJiangting. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void) dealloc {
    NSUserDefaults * stand = [NSUserDefaults standardUserDefaults];
    [stand setValue:@"sdfsdfdsfsdf" forKey:@"abc"];
    [stand synchronize];
}

- (id) initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        
       
        SListView * listView = [[SListView alloc] initWithFrame:CGRectMake(0, 200, 320, 100)];
        listView.delegate = self;
        listView.dataSource = self;
        
        [self.view addSubview:listView];
    }
    return self;
}

- (id) initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        
        NSUserDefaults * stand = [NSUserDefaults standardUserDefaults];
        NSLog(@"%@",[stand valueForKey:@"abc"]);
        
       
        
        SListView * listView = [[SListView alloc] initWithFrame:CGRectMake(0, 200, 320, 100)];
        listView.delegate = self;
        listView.dataSource = self;
        
        [self.view addSubview:listView];
    }
    return self;
}

- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
}
- (void) viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
}

- (void) viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];


}

/**
 * @brief 共有多少列
 * @param listView 当前所在的ListView
 */
- (NSInteger) numberOfColumnsInListView:(SListView *) listView {
    return 10000;
}

/**
 * @brief 这一列有多宽，根据有多宽，算出需要加载多少个
 * @param index  当前所在列
 */
- (CGFloat) widthForColumnAtIndex:(NSInteger) index {
    if (index % 2== 0) {
        return 60;
    }else
        return  90;
}

/**
 * @brief 每列 显示什么
 * @param listView 当前所在的ListView
 * @param index  当前所在列
 * @return  当前所要展示的页
 */
- (SListViewCell *) listView:(SListView *)listView viewForColumnAtIndex:(NSInteger) index {
    static NSString * CELL = @"CELL";
    SListViewCell * cell;
    cell = [listView dequeueReusableCellWithIdentifier:CELL];
    if (!cell) {
        cell = [[SListViewCell alloc] initWithReuseIdentifier:CELL];
        
    }
    cell.alpha = 0.5;
    cell.backgroundColor = [UIColor yellowColor];
    return  cell;
}

- (void) listView:(SListView *)listView didSelectColumnAtIndex:(NSInteger)index {
    
}


@end
