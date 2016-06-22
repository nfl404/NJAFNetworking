
网络框架（以下称NJAFNetworking）是基于AFNetworking框架的简单封装，基本功能包括POST请求，GET请求，上传文件，下载文件，网络状态，缓存等。

## 为什么要使用NJAFNetworking？
在使用AFNetworking的时候我们会发现对外开发接口比较多，当项目需求涉及到缓存，以及网络判断的时候，我们都无从下手。然NJAFNetworking框架将这些过多的开发接口封装到一起，让我们使用起来更为方便。

- 优点：
  - 网络状态已经封装，在通过GET/POST请求会回调；
  - 缓存已经封装，当GET/POST请求失败后会回调；
  - 开发接口少，只需调用相应功能功能的接口即可。



## NJAFNetworking究竟是什么？
- 配置公共的请求头（可以不配置）

    ///**
    //*  更新请求接口基础url（如果服务器地址有多个）
    //*  @param baseUrl 请求接口基础url
    //*/
    + (void)updateBaseUrl:(NSString *)baseUrl;


- 更新请求接口基础url（如果服务器地址有多个，可以不配置）
        /**
         *  更新请求接口基础url（如果服务器地址有多个）
         *  @param baseUrl 请求接口基础url
         */
        + (void)updateBaseUrl:(NSString *)baseUrl;
- GET请求接口
        /**
         *  GET请求接口
         *  @param url          访问地址路径，如/user/index/login
         *  @param refreshCache 是否刷新缓存，YES
         *  @param params       需要传的参数，如@{@"user_id" :@(80011)}
         *  @param progress     进度回调，
         *  @param success      接口请求响应成功回调
         *  @param fail         接口请求响应失败回调
         *  @return             NSURLSessionTask
         */
        + (NJURLSessionTask *)getWithUrl:(NSString *)url
                            refreshCache:(BOOL)refreshCache
                                  params:(NSDictionary *)params
                                progress:(NJLoadProgress)progress
                                 success:(NJResponseSuccess)success
                                    fail:(NJResponseFail)fail;
- POST请求接口
        /**
         *  POST请求接口
         *  @param url          访问地址路径，如/user/index/login
         *  @param refreshCache 是否刷新缓存，YES
         *  @param params       需要传的参数，如@{@"user_id" :@(80011)}
         *  @param progress     进度回调，
         *  @param success      接口请求响应成功回调
         *  @param fail         接口请求响应失败回调
         *  @return             NSURLSessionTask
         */
        + (NJURLSessionTask *)postWithUrl:(NSString *)url
                             refreshCache:(BOOL)refreshCache
                                   params:(NSDictionary *)params
                                 progress:(NJLoadProgress)progress
                                  success:(NJResponseSuccess)success
                                     fail:(NJResponseFail)fail;
- 图片上传接口
        /**
         *  图片上传接口
         *  @param image        图片对象
         *  @param url          上传图片路径，如/user/images
         *  @param filename     文件名字，默认为当前时间yyyyMMddHHmmss.jpg
         *  @param name         约定关联名称，如image
         *  @param mimeType     默认iamge/jpeg
         *  @param parameters   需要传的参数，如@{@"user_id" :@(80011)}
         *  @param progress     上传进度回调
         *  @param success      上传成功回调
         *  @param fail         上传失败回调
         *  @return             NSURLSessionTask
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
- 上传文件
        /**
         *  上传文件
         *  @param url              上传文件路径，如/user/images
         *  @param uploadingFile    待上传文件路径，如/user/images
         *  @param progress         进度回调
         *  @param success          上传成功回调
         *  @param fail             上传失败回调
         *  @return                 NSURLSessionTask
         */
        + (NJURLSessionTask *)uploadFileWithUrl:(NSString *)url
                                  uploadingFile:(NSString *)uploadingFile
                                       progress:(NJLoadProgress)progress
                                        success:(NJResponseSuccess)success
                                           fail:(NJResponseFail)fail;
- 下载文件
        /**
         *  下载文件
         *  @param url              下载文件URL
         *  @param saveToPath       下载到那个路径下
         *  @param progress         下载进度
         *  @param success          下载成功后的回调
         *  @param fail             下载失败后的回调
         *  @return NSURLSessionTask
         */
        + (NJURLSessionTask *)downloadWithUrl:(NSString *)url
                                   saveToPath:(NSString *)saveToPath
                                     progress:(NJLoadProgress)progress
                                      success:(NJResponseSuccess)success
                                         fail:(NJResponseFail)fail;

##  如何使用NJAFNetworking？
- NJAFNetworking支持CocoaPods([CocoaPods是什么？](http://www.jianshu.com/p/e46d57ecc1f2))
写在Podfile文件中，
        source 'https://github.com/CocoaPods/Specs.git'
        inhibit_all_warnings!

        target "这里写你的工程名字" do
        pod 'NJAFNetworking', '~> 1.0.1'
        end

- 下载NJAFNetworking（[下载地址](https://github.com/nfl404/NJAFNetworking)）
下载完后将NJAFNetworking文件夹拖入工程中即可。


结束。 
***********************************
你们的支持也是我前进的动力,非常感谢支持!
