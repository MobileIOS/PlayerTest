//
//  XCAVPlayerView.h
//  PlayerTest
//
//  Created by wangwenke on 16/7/13.
//  Copyright © 2016年 wangwenke. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,XCAVPlayerStatues){
    XCPlayerStatusReadyToPlay,
    XCPlayerStatusFailed,
    XCPlayerStatusUnknown,
};

@class XCAVPlayerView;

@protocol XCAVPlayerDelegate <NSObject>

/** 播放器状态改变 */
- (void)xcAVPlayerView:(XCAVPlayerView *)playerView reloadStatuesChanged:(XCAVPlayerStatues)xcPlayerStatues;

/** 播放时间进度改变 */
- (void)xcAVPlayerView:(XCAVPlayerView *)playerView currentPlayTimeChanged:(Float64)currentPlayTime;

@end


@interface XCAVPlayerView : UIView




@property (nonatomic, strong) NSURL *playerUrl;/**< 播放链接 */

@property (nonatomic, assign) id<XCAVPlayerDelegate> delegate;
@property (nonatomic, assign) Float64 currentPlayTime;/**< current play time */
@property (nonatomic, assign) Float64 totalDuration;/**< video duration */
@property (nonatomic, assign) Float64 timeInterval;/**< available Duration (cached) */

@property (nonatomic, assign) BOOL    isSHowBottomProgressView;/**< default is YES */
@property (nonatomic, assign) BOOL    isSHowResumViewAtPlayEnd;/**< */


/** 播放状态 */
- (BOOL)isPlaying;

/** play */
- (void)play;

/** pause */
- (void)pause;

/** resume */
- (void)resume;

/** 拉动进度条 */
- (void)seekToTime:(CGFloat)seekTime;

/** 播放时间 00:00:00 */
- (NSString *)convertTimeToString:(CGFloat)second;

@end
