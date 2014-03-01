//
//  ViewController.m
//  WMGenericCollection_Modified
//
//  Created by adachi yuichi on 2014/03/01.
//  Copyright (c) 2014年 yad. All rights reserved.
//

#import "ViewController.h"
#import "WMGenericArray.h"
#import "WMGenericSet.h"
#import "WMGenericDictionary.h"

WMGENERICARRAY_INTERFACE(NSString *, NSStringArray, NSMutableStringArray)
WMGENERICARRAY_SYNTHESIZE(NSString *, NSStringArray, NSMutableStringArray);

WMGENERICARRAY_INTERFACE(NSURL *, NSURLArray, NSMutableURLArray)
WMGENERICARRAY_SYNTHESIZE(NSURL *, NSURLArray, NSMutableURLArray);

WMGENERICSET_INTERFACE(NSString *, NSStringArray *, NSStringSet, NSMutableStringSet, NSCountedStringSet);
WMGENERICSET_SYNTHESIZE(NSString *, NSStringArray *, NSStringSet, NSMutableStringSet, NSCountedStringSet);

WMGENERICDICTIONARY_INTERFACE(NSURL *, NSString *, NSURLArray *, NSStringArray *, NSStringSet *, NSURLStringDictionary, NSMutableURLStringDictionary);
WMGENERICDICTIONARY_SYNTHESIZE(NSURL *, NSString *, NSURLArray *, NSStringArray *, NSStringSet *, NSURLStringDictionary, NSMutableURLStringDictionary);

@interface ViewController ()

@end

@implementation ViewController

#pragma mark - Lifecycle methods

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSStringArray *strings = (NSStringArray *)@[@"https://", @"http://"];
    
    NSLog(@"%@", strings[1]);
    
    NSMutableStringArray *stringsMutableArray = [NSMutableStringArray new];
    stringsMutableArray[0] = strings[1];
    
    NSLog(@"%@", stringsMutableArray);
    
    NSURLArray *URLs = [self URLArrayFromStrings:strings];
    
    NSLog(@"%@", URLs[1].absoluteURL);
    
    NSStringSet *stringSet = [NSStringSet setWithArray:strings];
    
    NSLog(@"%lu", (unsigned long)stringSet.anyObject.length);
    
    NSURLStringDictionary *URLDictionary = [NSURLStringDictionary dictionaryWithObjects:URLs forKeys:strings];
    
    NSLog(@"urlString : %@ , keylength : %lu", [URLDictionary objectForKey:strings.firstObject].absoluteURL, (unsigned long)strings.firstObject.length);
}

#pragma mark - Private methods

- (NSURLArray *)URLArrayFromStrings:(NSStringArray *)strings
{
	NSMutableURLArray *URLs = [NSMutableURLArray array];
	for (NSString *string in strings) {
		[URLs addObject:[NSURL URLWithString:string]];
	}
	return [NSURLArray arrayWithArray:(NSURLArray*)URLs];
}

@end
