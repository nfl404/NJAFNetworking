//
//  ViewController.m
//  NJAFNetworkingExtension
//
//  Created by Mr nie on 16/6/16.
//  Copyright © 2016年 程序猿:NiePlus   博客地址:http://nieplus.blog.com. All rights reserved.
//

#import "ViewController.h"
#import "NJAFNetworking.h"

@interface ViewController ()

@end
#define imageEssenceUrl @"http://api.budejie.com/api/api_open.php?market=anzhi&maxid=&udid=862949026831409&a=list&c=data&os=4.2.2&client=android&page=1&per=20&visiting=&type=&time=week&mac=30%3A92%3Af6%3Add%3A13%3A58&ver=4.2.0"

#define imageNewUrl @"http://api.budejie.com/api/api_open.php?market=anzhi&maxid=&udid=862949026831409&a=newlist&c=data&os=4.2.2&client=android&userID=&page=1&per=20&visiting=&type=&time=week&mac=30%3A92%3Af6%3Add%3A13%3A58&ver=4.2.0"

#define url @"http://api.helloworld.com/"
@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self connectTest];
}

- (void)connectTest {
    [NJAFNetworking postWithUrl:imageNewUrl refreshCache:NO params:nil progress:nil success:^(NJServerRequestsStatus status, NJAFNetworkReachabilityStatus reachability, id response) {
        NSLog(@"status->%ld, reachability->%ld, response->%@", status, reachability, response);
    } fail:^(NJServerRequestsStatus status, NJAFNetworkReachabilityStatus reachability,id response, NSError *error) {
        NSLog(@"status->%ld, reachability->%ld, response->%@, error->%@", status, reachability, response, error);
    }];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self connectTest];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
