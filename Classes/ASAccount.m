//
//  Account.m
//  AppSales
//
//  Created by Ole Zorn on 30.06.11.
//  Copyright (c) 2011 omz:software. All rights reserved.
//

#import "ASAccount.h"
#import "SAMKeychain.h"

#define kAccountKeychainServiceIdentifier	@"iTunesConnect"

@implementation ASAccount

@dynamic username, vendorID, title, sortIndex, dailyReports, weeklyReports, products, payments, reportsBadge, paymentsBadge;
@synthesize isDownloadingReports, downloadStatus, downloadProgress;

- (NSString *)password
{
	return [SAMKeychain passwordForService:kAccountKeychainServiceIdentifier account:self.username];
}

- (void)setPassword:(NSString *)newPassword
{
	[SAMKeychain setPassword:newPassword forService:kAccountKeychainServiceIdentifier account:self.username];
}

- (void)deletePassword
{
	[SAMKeychain deletePasswordForService:kAccountKeychainServiceIdentifier account:self.username];
}

- (NSString *)displayName
{
	if (self.title && ![self.title isEqualToString:@""]) {
		return self.title;
	}
	return self.username;
}

@end
