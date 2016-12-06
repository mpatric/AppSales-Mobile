//
//  SAMKeychain.h
//  SSToolkit
//
//  Created by Sam Soffes on 5/19/10.
//  Copyright 2009-2010 Sam Soffes. All rights reserved.
//

#import <Security/Security.h>

typedef enum {
	SAMKeychainErrorBadArguments = -1001,
	SAMKeychainErrorNoPassword = -1002,
	SAMKeychainErrorInvalidParameter = errSecParam,
	SAMKeychainErrorFailedToAllocated = errSecAllocate,
	SAMKeychainErrorNotAvailable = errSecNotAvailable,
	SAMKeychainErrorAuthorizationFailed = errSecAuthFailed,
	SAMKeychainErrorDuplicatedItem = errSecDuplicateItem,
	SAMKeychainErrorNotFound = errSecItemNotFound,
	SAMKeychainErrorInteractionNotAllowed = errSecInteractionNotAllowed,
	SAMKeychainErrorFailedToDecode = errSecDecode
} SAMKeychainErrorCode;

extern NSString *SAMKeychainErrorDomain;

@interface SAMKeychain : NSObject {
	
}

+ (NSString *)passwordForService:(NSString *)service account:(NSString *)account;
+ (NSString *)passwordForService:(NSString *)service account:(NSString *)account error:(NSError **)error;

+ (BOOL)deletePasswordForService:(NSString *)service account:(NSString *)account;
+ (BOOL)deletePasswordForService:(NSString *)service account:(NSString *)account error:(NSError **)error;

+ (BOOL)setPassword:(NSString *)password forService:(NSString *)service account:(NSString *)account;
+ (BOOL)setPassword:(NSString *)password forService:(NSString *)service account:(NSString *)account error:(NSError **)error;

@end
