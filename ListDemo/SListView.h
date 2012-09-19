//
//  SListView.h
//  SPhoto
//
//  Created by SunJiangting on 12-8-12.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "SListViewCell.h"
#import <QuartzCore/QuartzCore.h>

@class SListView;
/// 定义一种结构体，用来表示区间。表示一个 从 几到几 的概念
typedef struct _SRange{
    NSInteger start;
    NSInteger end;
} SRange;
 
/**
 * @brief 创建结构体 SRange，结构体中保存start，end
 * @param start 范围开始
 * @param end   范围结束
 * @return 返回 该范围
 * @note eg. SRangeMake(0,5) 则返回 0~5
 */
NS_INLINE SRange SRangeMake(NSInteger start, NSInteger end) {
    SRange range;
    range.start = start;
    range.end = end;
    return range;
}

/**
 * @brief 该int 数 是否在 SRange区间内
 * @param r 整形区间
 * @param i 要比较的数
 * @return i在区间 r内，返回YES；否则，返回NO
 */
NS_INLINE BOOL InRange(SRange r,NSInteger i) {
    return (r.start <= i) && (r.end >= i);
}

/**
 * @brief SListView 在滑动过程中表示向左滑还是向右滑
 * @enum SDirectionType
 * @constant   SDirectionLeft   表示向左滑
 * @constant   SDirectionRight  表示向右滑
 */
typedef enum _SDirection {
    SDirectionTypeLeft,
    SDirectionTypeRight
} SDirectionType;

@protocol SListViewDelegate <NSObject, UIScrollViewDelegate>

/**
 * @brief 当前列 被选中的事件
 * @param index  当前所在列
 */
- (void) listView:(SListView *) listView didSelectColumnAtIndex:(NSInteger) index;

@end

@protocol SListViewDataSource <NSObject>

@optional
/**
 * @brief 共有多少列
 * @param listView 当前所在的ListView
 */
- (NSInteger) numberOfColumnsInListView:(SListView *) listView;

/**
 * @brief 这一列有多宽，根据有多宽，算出需要加载多少个
 * @param index  当前所在列
 */
- (CGFloat) widthForColumnAtIndex:(NSInteger) index;

/**
 * @brief 每列 显示什么
 * @param listView 当前所在的ListView
 * @param index  当前所在列
 * @return  当前所要展示的页
 */
- (SListViewCell *) listView:(SListView *)listView viewForColumnAtIndex:(NSInteger) index;

@end

@interface UIScrollView (Rect)

- (CGRect) visibleRect;

@end

/// 参考 UITableView
@interface SListView : UIView <NSCoding, UIScrollViewDelegate> {
    /// ListCell 个数
    NSInteger _columns;
    /// 每个SListViewCell 的高度
    CGFloat _height;
    /// 所有的SListViewCell 的frame
    NSMutableArray * _columnRects;
    /// 可见的column范围
    SRange _visibleRange;
    /// scrollView 的可见区域
    CGRect _visibleRect;
    /// 可见的SListViewCell;
    NSMutableArray * _visibleListCells;
    /// 可重用的ListCells {identifier:[cell1,cell2]}
    NSMutableDictionary * _reusableListCells;
    
    // 选中的列
    NSInteger _selectedIndex;
}

@property (nonatomic,assign) id<SListViewDelegate> delegate;
@property (nonatomic,assign) id<SListViewDataSource> dataSource;
@property (nonatomic, readonly) UIScrollView * scrollView;

@property(nonatomic,retain) UIColor * separatorColor;

- (id)dequeueReusableCellWithIdentifier:(NSString *)identifier;

- (void) reloadData;

@end
