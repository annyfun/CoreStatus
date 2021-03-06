//
//  CoreNetWorkStatusObserver.h
//  CoreNetWorkStatusObserver
//
//  Created by LiHaozhen on 15/5/2.
//  Copyright (c) 2015年 ihojin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Reachability.h"

/** 网络状态 */
typedef enum{
    
    /** 无网络 */
    CoreNetWorkStatusNone=0,
    
    /** Wifi网络 */
    CoreNetWorkStatusWifi,
    
    /** 蜂窝网络 */
    CoreNetWorkStatusWWAN,
    
    /** 2G网络 */
    CoreNetWorkStatus2G,
    
    /** 3G网络 */
    CoreNetWorkStatus3G,
    
    /** 4G网络 */
    CoreNetWorkStatus4G,
    
    //未知网络
    CoreNetWorkStatusUnkhow
    
}CoreNetWorkStatus;

/** 网络状态改变回调 */
typedef void (^CSStatusDidChangedBlock) (NSString *statusName,CoreNetWorkStatus status);

@interface CoreStatus : NSObject

+ (instancetype)sharedCoreStatus;

/** 获取当前网络状态：枚举 */
+(CoreNetWorkStatus)currentNetWorkStatus;

/** 获取当前网络状态：字符串 */
+(NSString *)currentNetWorkStatusString;

/** 添加监听 */
+(void)addNetworkStatusListener:(NSString *)listenerName withDidChangeBlock:(CSStatusDidChangedBlock)block;
/** 移除监听 */
+(void)removeNetworkStatusListener:(NSString *)listenerName;


/*
 *  新增API
 */
/** 是否是Wifi */
+(BOOL)isWifiEnable;

/** 是否有网络 */
+(BOOL)isNetworkEnable;

/** 是否处于高速网络环境：3G、4G、Wifi */
+(BOOL)isHighSpeedNetwork;
@end


#pragma mark - Deprecated
@protocol CoreStatusProtocol <NSObject>

@property (nonatomic,assign) NetworkStatus currentStatus;

@optional

/** 网络状态变更 */
-(void)coreNetworkChangeNoti:(NSNotification *)noti;

@end


@interface CoreStatus (CoreStatusDeprecated)

/** 开始网络监听 */
+(void)beginNotiNetwork:(id<CoreStatusProtocol>)listener __deprecated_msg("Use `addNetworkStatusListener: withDidChangeBlock:`");
/** 停止网络监听 */
+(void)endNotiNetwork:(id<CoreStatusProtocol>)listener __deprecated_msg("Use `removeNetworkStatusListener:`");

@end

