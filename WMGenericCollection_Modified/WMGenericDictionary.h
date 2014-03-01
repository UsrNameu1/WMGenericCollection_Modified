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
//  WMGenericDictionary.h
//  WMGenericCollection
//
//  Created with convert.py on 2013-03-14.
//  Input files: NSDictionary.h
//
//  Altered by yad on 2014-03-01
//

#import <Foundation/NSObject.h>
#import <Foundation/NSEnumerator.h>

@class NSArray, NSSet, NSString, NSURL;

#if !__has_feature(objc_arc) // MRC

#if NS_BLOCKS_AVAILABLE

#pragma mark - BLOCK AVAILABLE MRC

#define WMGENERICDICTIONARY_INTERFACE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
@interface WMGenericDictionary : NSDictionary <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
@end;\
\
@interface WMGenericDictionary (NSExtendedDictionary)\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSArray_keys_class)keysSortedByValueUsingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
- (NSArray_keys_class)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet_keys_class)keysOfEntriesPassingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet_keys_class)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
@end;\
\
@interface WMGenericDictionary (NSDictionaryCreation)\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
@end;\
\
@interface WMGenericMutableDictionary : NSMutableDictionary\
\
- (void)removeObjectForKey:(ns_copying_compliant_key_class)aKey;\
- (void)setObject:(object_class)anObject forKey:(ns_copying_compliant_key_class)aKey;\
\
/** Interface from super class: NSDictionary */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSArray_keys_class)keysSortedByValueUsingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
- (NSArray_keys_class)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet_keys_class)keysOfEntriesPassingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet_keys_class)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableDictionary (NSExtendedMutableDictionary)\
\
- (void)addEntriesFromDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)removeAllObjects;\
- (void)removeObjectsForKeys:(NSArray_keys_class)keyArray;\
- (void)setDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)setObject:(object_class)obj forKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSMutableDictionaryCreation)\
\
+ (id)dictionaryWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
@end;\
\
@interface WMGenericDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)sharedKeySetForKeys:(NSArray_keys_class)keys NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)dictionaryWithSharedKeySet:(ns_copying_compliant_key_class)keyset NS_AVAILABLE(10_8, 6_0);\
\
@end;\


#define WMGENERICDICTIONARY_SYNTHESIZE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericDictionary\
\
+ (id)alloc {\
    return (id)[NSDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSDictionary allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableDictionary\
\
+ (id)alloc {\
    return (id)[NSMutableDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSMutableDictionary allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#else // NS_BLOCKS_AVAILABLE

#pragma mark - BLOCK UNAVAILABLE MRC

#define WMGENERICDICTIONARY_INTERFACE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
@interface WMGenericDictionary : NSDictionary <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
@end;\
\
@interface WMGenericDictionary (NSExtendedDictionary)\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
\
@end;\
\
@interface WMGenericDictionary (NSDictionaryCreation)\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
@end;\
\
@interface WMGenericMutableDictionary : NSMutableDictionary\
\
- (void)removeObjectForKey:(ns_copying_compliant_key_class)aKey;\
- (void)setObject:(object_class)anObject forKey:(ns_copying_compliant_key_class)aKey;\
\
/** Interface from super class: NSDictionary */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const object_class [])objects forKeys:(const ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableDictionary (NSExtendedMutableDictionary)\
\
- (void)addEntriesFromDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)removeAllObjects;\
- (void)removeObjectsForKeys:(NSArray_keys_class)keyArray;\
- (void)setDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)setObject:(object_class)obj forKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSMutableDictionaryCreation)\
\
+ (id)dictionaryWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
@end;\
\
@interface WMGenericDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)sharedKeySetForKeys:(NSArray_keys_class)keys NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)dictionaryWithSharedKeySet:(ns_copying_compliant_key_class)keyset NS_AVAILABLE(10_8, 6_0);\
\
@end;\


#define WMGENERICDICTIONARY_SYNTHESIZE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericDictionary\
\
+ (id)alloc {\
    return (id)[NSDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSDictionary allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableDictionary\
\
+ (id)alloc {\
    return (id)[NSMutableDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
    return (id)[NSMutableDictionary allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#endif // NS_BLOCKS_AVAILABLE

#else // ARC

#if NS_BLOCKS_AVAILABLE

#pragma mark - BLOCK AVAILABLE ARC

#define WMGENERICDICTIONARY_INTERFACE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
@interface WMGenericDictionary : NSDictionary <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
@end;\
\
@interface WMGenericDictionary (NSExtendedDictionary)\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSArray_keys_class)keysSortedByValueUsingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
- (NSArray_keys_class)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet_keys_class)keysOfEntriesPassingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet_keys_class)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
@end;\
\
@interface WMGenericDictionary (NSDictionaryCreation)\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
@end;\
\
@interface WMGenericMutableDictionary : NSMutableDictionary\
\
- (void)removeObjectForKey:(ns_copying_compliant_key_class)aKey;\
- (void)setObject:(object_class)anObject forKey:(ns_copying_compliant_key_class)aKey;\
\
/** Interface from super class: NSDictionary */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);\
\
- (NSArray_keys_class)keysSortedByValueUsingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
- (NSArray_keys_class)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr NS_AVAILABLE(10_6, 4_0);\
\
- (NSSet_keys_class)keysOfEntriesPassingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
- (NSSet_keys_class)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ns_copying_compliant_key_class key, object_class obj, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);\
\
\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableDictionary (NSExtendedMutableDictionary)\
\
- (void)addEntriesFromDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)removeAllObjects;\
- (void)removeObjectsForKeys:(NSArray_keys_class)keyArray;\
- (void)setDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)setObject:(object_class)obj forKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSMutableDictionaryCreation)\
\
+ (id)dictionaryWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
@end;\
\
@interface WMGenericDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)sharedKeySetForKeys:(NSArray_keys_class)keys NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)dictionaryWithSharedKeySet:(ns_copying_compliant_key_class)keyset NS_AVAILABLE(10_8, 6_0);\
\
@end;\


#define WMGENERICDICTIONARY_SYNTHESIZE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericDictionary\
\
+ (id)alloc {\
return (id)[NSDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSDictionary allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableDictionary\
\
+ (id)alloc {\
return (id)[NSMutableDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSMutableDictionary allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#else // NS_BLOCKS_AVAILABLE

#pragma mark - BLOCK UNAVAILABLE ARC

#define WMGENERICDICTIONARY_INTERFACE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
@interface WMGenericDictionary : NSDictionary <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
@end;\
\
@interface WMGenericDictionary (NSExtendedDictionary)\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
\
@end;\
\
@interface WMGenericDictionary (NSDictionaryCreation)\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
@end;\
\
@interface WMGenericMutableDictionary : NSMutableDictionary\
\
- (void)removeObjectForKey:(ns_copying_compliant_key_class)aKey;\
- (void)setObject:(object_class)anObject forKey:(ns_copying_compliant_key_class)aKey;\
\
/** Interface from super class: NSDictionary */\
\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wduplicate-method-match\"")\
\
- (NSUInteger)count;\
- (object_class)objectForKey:(ns_copying_compliant_key_class)aKey;\
- (NSEnumerator *)keyEnumerator;\
\
\
- (NSArray_keys_class)allKeys;\
- (NSArray_keys_class)allKeysForObject:(object_class)anObject;    \
- (NSArray_values_class)allValues;\
- (NSString *)description;\
- (NSString *)descriptionInStringsFileFormat;\
- (NSString *)descriptionWithLocale:(id)locale;\
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level;\
- (BOOL)isEqualToDictionary:(WMGenericDictionary *)otherDictionary;\
- (NSEnumerator *)objectEnumerator;\
- (NSArray_values_class)objectsForKeys:(NSArray_keys_class)keys notFoundMarker:(id)marker;\
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;\
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
\
- (NSArray_keys_class)keysSortedByValueUsingSelector:(SEL)comparator;\
- (void)getObjects:(object_class __unsafe_unretained [])objects andKeys:(ns_copying_compliant_key_class __unsafe_unretained [])keys;\
\
- (object_class)objectForKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
\
\
\
+ (id)dictionary;\
+ (id)dictionaryWithObject:(object_class)object forKey:(ns_copying_compliant_key_class)key;\
\
+ (id)dictionaryWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
+ (id)dictionaryWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
+ (id)dictionaryWithDictionary:(WMGenericDictionary *)dict;\
+ (id)dictionaryWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
\
- (id)initWithObjects:(const __strong object_class [])objects forKeys:(const __strong ns_copying_compliant_key_class [])keys count:(NSUInteger)cnt;\
\
- (id)initWithObjectsAndKeys:(object_class)firstObject, ... NS_REQUIRES_NIL_TERMINATION;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary;\
- (id)initWithDictionary:(WMGenericDictionary *)otherDictionary copyItems:(BOOL)flag;\
- (id)initWithObjects:(NSArray_values_class)objects forKeys:(NSArray_keys_class)keys;\
\
+ (id)dictionaryWithContentsOfFile:(NSString *)path;\
+ (id)dictionaryWithContentsOfURL:(NSURL *)url;\
- (id)initWithContentsOfFile:(NSString *)path;\
- (id)initWithContentsOfURL:(NSURL *)url;\
\
\
_Pragma("clang diagnostic pop")@end;\
\
@interface WMGenericMutableDictionary (NSExtendedMutableDictionary)\
\
- (void)addEntriesFromDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)removeAllObjects;\
- (void)removeObjectsForKeys:(NSArray_keys_class)keyArray;\
- (void)setDictionary:(WMGenericDictionary *)otherDictionary;\
- (void)setObject:(object_class)obj forKeyedSubscript:(ns_copying_compliant_key_class)key NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSMutableDictionaryCreation)\
\
+ (id)dictionaryWithCapacity:(NSUInteger)numItems;\
- (id)initWithCapacity:(NSUInteger)numItems;\
\
@end;\
\
@interface WMGenericDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)sharedKeySetForKeys:(NSArray_keys_class)keys NS_AVAILABLE(10_8, 6_0);\
\
@end;\
\
@interface WMGenericMutableDictionary (NSSharedKeySetDictionary)\
\
\
+ (id)dictionaryWithSharedKeySet:(ns_copying_compliant_key_class)keyset NS_AVAILABLE(10_8, 6_0);\
\
@end;\


#define WMGENERICDICTIONARY_SYNTHESIZE(object_class, ns_copying_compliant_key_class, NSArray_values_class, NSArray_keys_class, NSSet_keys_class, WMGenericDictionary, WMGenericMutableDictionary)\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"")\
_Pragma("clang diagnostic ignored \"-Wprotocol\"")\
\
@implementation WMGenericDictionary\
\
+ (id)alloc {\
return (id)[NSDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSDictionary allocWithZone:zone];\
}\
\
@end;\
\
\
@implementation WMGenericMutableDictionary\
\
+ (id)alloc {\
return (id)[NSMutableDictionary alloc];\
}\
\
+ (id)allocWithZone:(NSZone *)zone {\
return (id)[NSMutableDictionary allocWithZone:zone];\
}\
\
@end;\
\
_Pragma("clang diagnostic pop")

#endif // NS_BLOCKS_AVAILABLE

#endif
