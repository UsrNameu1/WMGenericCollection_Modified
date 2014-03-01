//
//  Copyright (c) 2013 Wieland Morgenstern
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  https://github.com/w-m/WMGenericCollection
//

//
//  WMGenericSet.h
//  WMGenericCollection
//
//  Created with convert.py on 2013-03-14.
//  Input files: NSSet.h
//
//  Altered by yad on 2014-03-01
//


#import <Foundation/NSObject.h>
#import <Foundation/NSEnumerator.h>

@class NSArray, NSDictionary, NSString;

#if !__has_feature(objc_arc) // MRC

#if NS_BLOCKS_AVAILABLE

#pragma mark - BLOCKS AVAILABLE MRC

#define WMGENERICSET_INTERFACE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
@interface WMGenericSet : NSSet <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
@end;\
\
@interface WMGenericSet (NSExtendedSet)\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
- (void)enumerateObjectsUsingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet *)objectsPassingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
@end;\
\
@interface WMGenericSet (NSSetCreation)\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
@end;\
\
@interface WMGenericMutableSet : NSMutableSet\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
- (void)enumerateObjectsUsingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet *)objectsPassingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableSet (NSExtendedMutableSet)\
\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
@end;\
\
@interface WMGenericMutableSet (NSMutableSetCreation)\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
    \
@end;\
\
@interface WMGenericCountedSet : NSCountedSet\
\
\
- (id)initWithCapacity:(NSUInteger)numItems; \
\
- (id)initWithArray:(NSArray_values_class)array;\
- (id)initWithSet:(WMGenericSet *)set;\
\
- (NSUInteger)countForObject:(object_class)object;\
\
- (NSEnumerator *)objectEnumerator;\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSMutableSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
- (void)enumerateObjectsUsingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet *)objectsPassingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
    \
\
_Pragma("clang diagnostic pop")@end;\


#define WMGENERICSET_SYNTHESIZE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericSet\
\
+ (id)alloc {\
    return (id)[NSSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableSet\
\
+ (id)alloc {\
    return (id)[NSMutableSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSMutableSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericCountedSet\
\
+ (id)alloc {\
    return (id)[NSCountedSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSCountedSet allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#else // NS_BLOCKS_AVAILABLE

#pragma mark - BLOCKS UNAVAILABLE MRC

#define WMGENERICSET_INTERFACE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
@interface WMGenericSet : NSSet <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
@end;\
\
@interface WMGenericSet (NSExtendedSet)\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
\
@end;\
\
@interface WMGenericSet (NSSetCreation)\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
@end;\
\
@interface WMGenericMutableSet : NSMutableSet\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableSet (NSExtendedMutableSet)\
\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
@end;\
\
@interface WMGenericMutableSet (NSMutableSetCreation)\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
    \
@end;\
\
@interface WMGenericCountedSet : NSCountedSet\
\
\
- (id)initWithCapacity:(NSUInteger)numItems; \
\
- (id)initWithArray:(NSArray_values_class)array;\
- (id)initWithSet:(WMGenericSet *)set;\
\
- (NSUInteger)countForObject:(object_class)object;\
\
- (NSEnumerator *)objectEnumerator;\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSMutableSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
    \
\
_Pragma("clang diagnostic pop")@end;\


#define WMGENERICSET_SYNTHESIZE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericSet\
\
+ (id)alloc {\
    return (id)[NSSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableSet\
\
+ (id)alloc {\
    return (id)[NSMutableSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSMutableSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericCountedSet\
\
+ (id)alloc {\
    return (id)[NSCountedSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSCountedSet allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#endif // NS_BLOCKS_AVAILABLE

#else // ARC

#if NS_BLOCKS_AVAILABLE

#pragma mark - BLOCKS AVAILABLE ARC

#define WMGENERICSET_INTERFACE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
@interface WMGenericSet : NSSet <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
@end;\
\
@interface WMGenericSet (NSExtendedSet)\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
- (void)enumerateObjectsUsingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet *)objectsPassingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
@end;\
\
@interface WMGenericSet (NSSetCreation)\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
@end;\
\
@interface WMGenericMutableSet : NSMutableSet\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
- (void)enumerateObjectsUsingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet *)objectsPassingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableSet (NSExtendedMutableSet)\
\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
@end;\
\
@interface WMGenericMutableSet (NSMutableSetCreation)\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
@end;\
\
@interface WMGenericCountedSet : NSCountedSet\
\
\
- (id)initWithCapacity:(NSUInteger)numItems; \
\
- (id)initWithArray:(NSArray_values_class)array;\
- (id)initWithSet:(WMGenericSet *)set;\
\
- (NSUInteger)countForObject:(object_class)object;\
\
- (NSEnumerator *)objectEnumerator;\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSMutableSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
- (void)enumerateObjectsUsingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet *)objectsPassingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
\
_Pragma("clang diagnostic pop")@end;\


#define WMGENERICSET_SYNTHESIZE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericSet\
\
+ (id)alloc {\
return (id)[NSSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableSet\
\
+ (id)alloc {\
return (id)[NSMutableSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSMutableSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericCountedSet\
\
+ (id)alloc {\
return (id)[NSCountedSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSCountedSet allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#else // NS_BLOCKS_AVAILABLE

#pragma mark - BLOCKS UNAVAILABLE ARC

#define WMGENERICSET_INTERFACE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
@interface WMGenericSet : NSSet <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
@end;\
\
@interface WMGenericSet (NSExtendedSet)\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
\
@end;\
\
@interface WMGenericSet (NSSetCreation)\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
@end;\
\
@interface WMGenericMutableSet : NSMutableSet\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableSet (NSExtendedMutableSet)\
\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
@end;\
\
@interface WMGenericMutableSet (NSMutableSetCreation)\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
@end;\
\
@interface WMGenericCountedSet : NSCountedSet\
\
\
- (id)initWithCapacity:(NSUInteger)numItems; \
\
- (id)initWithArray:(NSArray_values_class)array;\
- (id)initWithSet:(WMGenericSet *)set;\
\
- (NSUInteger)countForObject:(object_class)object;\
\
- (NSEnumerator *)objectEnumerator;\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSMutableSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (void)addObject:(object_class)object;\
- (void)removeObject:(object_class)object;\
\
/** Interface from super class: NSSet */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)member:(object_class)object;\
- (NSEnumerator *)objectEnumerator;\
\
\
- (NSArray_values_class)allObjects;\
- (object_class)anyObject;\
- (BOOL)containsObject:(object_class)anObject;\
- (NSString *)description;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (BOOL)intersectsSet:(WMGenericSet *)otherSet;\
- (BOOL)isEqualToSet:(WMGenericSet *)otherSet;\
- (BOOL)isSubsetOfSet:(WMGenericSet *)otherSet;\
\
- (void)makeObjectsPerformSelector:(SEL)aSelector;\
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument;\
\
- (WMGenericSet *)setByAddingObject:(object_class)anObject NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromSet:(WMGenericSet *)other NS_AVAILABLE(10_5, 2_0);\
- (WMGenericSet *)setByAddingObjectsFromArray:(NSArray_values_class)other NS_AVAILABLE(10_5, 2_0);\
\
\
\
\
+ (id)set;\
+ (id)setWithObject:(object_class)object;\
+ (id)setWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
+ (id)setWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)setWithSet:(WMGenericSet *)set;\
+ (id)setWithArray:(NSArray_values_class)array;\
\
- (id)initWithObjects:(const __strong object_class [])objects count:(NSUInteger)cnt;\
- (id)initWithObjects:(object_class)firstObj, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithSet:(WMGenericSet *)set;\
- (id)initWithSet:(WMGenericSet *)set copyItems:(BOOL)flag;\
- (id)initWithArray:(NSArray_values_class)array;\
\
\
_Pragma("clang diagnostic pop")\
- (void)addObjectsFromArray:(NSArray_values_class)array;\
- (void)intersectSet:(WMGenericSet *)otherSet;\
- (void)minusSet:(WMGenericSet *)otherSet;\
- (void)removeAllObjects;\
- (void)unionSet:(WMGenericSet *)otherSet;\
\
- (void)setSet:(WMGenericSet *)otherSet;\
\
\
+ (id)setWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
\
_Pragma("clang diagnostic pop")@end;\


#define WMGENERICSET_SYNTHESIZE(object_class, NSArray_values_class, WMGenericSet, WMGenericMutableSet, WMGenericCountedSet)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericSet\
\
+ (id)alloc {\
return (id)[NSSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableSet\
\
+ (id)alloc {\
return (id)[NSMutableSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSMutableSet allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericCountedSet\
\
+ (id)alloc {\
return (id)[NSCountedSet alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSCountedSet allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#endif // NS_BLOCKS_AVAILABLE

#endif

