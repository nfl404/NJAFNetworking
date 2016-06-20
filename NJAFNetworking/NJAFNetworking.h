//
//  NJAFNetworking.h
//  NJAFNetworkingExtension
//
//  Created by Mr nie on 16/6/16.
//  Copyright © 2016年 程序猿:NiePlus   博客地址:http://nieplus.blog.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, NJAFNetworkReachabilityStatus) {
    NJAFNetworkReachabilityStatusUnkonw             = -1,   // 未知网络
    NJAFNetworkReachabilityStatusNotReachable       = 0,    // 网络无法链接
    NJAFNetworkReachabilityStatusReachableViaWWAN   = 1,    // 2，3，4G
    NJAFNetworkReachabilityStatusReachableViaWiFi   = 2     // WIFI
};


typedef NS_ENUM(NSUInteger, NJServerRequestsStatus) {
    NJServerRequestsStatusFail              = 0,        // 请求失败
    NJServerRequestsStatusSuccess           = 1,        // 请求成功
    NJServerRequestsStatusNotConnected      = 2,        // 无法连接
    NJServerRequestsStatusconnectedTimeOut  = 3         // 请求超时
};

typedef NS_ENUM(NSUInteger, NJResponseType) {
    NJResponseTypeJSON = 1,         // 默认
    NJResponseTypeXML  = 2,         // XML
    NJResponseTypeData = 3          // 特殊情况下，一转换服务器就无法识别的，默认会尝试转换成JSON，若失败则需要自己去转换
};

typedef NS_ENUM(NSUInteger, NJRequestType) {
    NJRequestTypeJSON       = 1,    // 默认
    NJRequestTypePlainText  = 2     // 普通text/html
};

typedef NSURLSessionTask NJURLSessionTask;
typedef void(^NJResponseSuccess)(NJServerRequestsStatus status, NJAFNetworkReachabilityStatus reachability,  id response);
typedef void(^NJResponseFail)(NJServerRequestsStatus status, NJAFNetworkReachabilityStatus reachability, id response, NSError *error);


typedef void(^NJLoadProgress)(int_fast64_t bytesRead, int_fast64_t totalBytesRead);


@interface NJAFNetworking : NSObject

/**
 *  更新请求接口基础url（如果服务器地址有多个）
 *  @param baseUrl 请求接口基础url
 */
+ (void)updateBaseUrl:(NSString *)baseUrl;


/**
 *  配置公共的请起头，用于区分请求来源，需要与服务器约定好
 *  @param httpHeaders      如@{"client" : "iOS"}
 */
+ (void)configCommonHttpHeaders:(NSDictionary *)httpHeaders;


/**
 *  GET请求接口
 *  @param url          访问地址路径，如/user/index/login
 *  @param refreshCache 是否刷新缓存，YES
 *  @param params       需要传的参数，如@{@"user_id" :@(80011)}
 *  @param progress     进度回调，
 *  @param success      接口请求响应成功回调
 *  @param fail         接口请求响应失败回调
 *  @return             NSURLSessionTask
 */
+ (NJURLSessionTask *)getWithUrl:(NSString *)url
                    refreshCache:(BOOL)refreshCache
                          params:(NSDictionary *)params
                        progress:(NJLoadProgress)progress
                         success:(NJResponseSuccess)success
                            fail:(NJResponseFail)fail;

/**
 *  POST请求接口
 *  @param url          访问地址路径，如/user/index/login
 *  @param refreshCache 是否刷新缓存，YES
 *  @param params       需要传的参数，如@{@"user_id" :@(80011)}
 *  @param progress     进度回调，
 *  @param success      接口请求响应成功回调
 *  @param fail         接口请求响应失败回调
 *  @return             NSURLSessionTask
 */
+ (NJURLSessionTask *)postWithUrl:(NSString *)url
                     refreshCache:(BOOL)refreshCache
                           params:(NSDictionary *)params
                         progress:(NJLoadProgress)progress
                          success:(NJResponseSuccess)success
                             fail:(NJResponseFail)fail;


/**
 *  图片上传接口
 *  @param image        图片对象
 *  @param url          上传图片路径，如/user/images
 *  @param filename     文件名字，默认为当前时间yyyyMMddHHmmss.jpg
 *  @param name         约定关联名称，如image
 *  @param mimeType     默认iamge/jpeg
 *  @param parameters   需要传的参数，如@{@"user_id" :@(80011)}
 *  @param progress     上传进度回调
 *  @param success      上传成功回调
 *  @param fail         上传失败回调
 *  @return             NSURLSessionTask
 */
+ (NJURLSessionTask *)uploadWithImage:(UIImage *)image
                                  url:(NSString *)url
                             filename:(NSString *)filename
                                 name:(NSString *)name
                             mimeType:(NSString *)mimeType
                           parameters:(NSDictionary *)parameters
                             progress:(NJLoadProgress)progress
                              success:(NJResponseSuccess)success
                                 fail:(NJResponseFail)fail;


/**
 *  上传文件
 *  @param url              上传文件路径，如/user/images
 *  @param uploadingFile    待上传文件路径，如/user/images
 *  @param progress         进度回调
 *  @param success          上传成功回调
 *  @param fail             上传失败回调
 *  @return                 NSURLSessionTask
 */
+ (NJURLSessionTask *)uploadFileWithUrl:(NSString *)url
                          uploadingFile:(NSString *)uploadingFile
                               progress:(NJLoadProgress)progress
                                success:(NJResponseSuccess)success
                                   fail:(NJResponseFail)fail;


/**
 *  下载文件
 *  @param url              下载文件URL
 *  @param saveToPath       下载到那个路径下
 *  @param progress         下载进度
 *  @param success          下载成功后的回调
 *  @param fail             下载失败后的回调
 *  @return NSURLSessionTask
 */
+ (NJURLSessionTask *)downloadWithUrl:(NSString *)url
                           saveToPath:(NSString *)saveToPath
                             progress:(NJLoadProgress)progress
                              success:(NJResponseSuccess)success
                                 fail:(NJResponseFail)fail;




@end
