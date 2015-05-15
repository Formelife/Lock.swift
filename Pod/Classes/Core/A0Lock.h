// A0Lock.h
//
// Copyright (c) 2015 Auth0 (http://auth0.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "A0APIClientProvider.h"
#import "A0AuthenticatorProvider.h"

@class A0APIClient, A0UserAPIClient, A0IdentityProviderAuthenticator;

/**
 *  Main interface with Auth0 Lock for iOS.
 */
@interface A0Lock : NSObject<A0APIClientProvider, A0AuthenticatorProvider>

/**
 *  Auth0 account's client identifier
 */
@property (strong, readonly, nonatomic) NSString *clientId;
/**
 *  Auth0 account's domain URL
 */
@property (strong, readonly, nonatomic) NSURL *domainURL;
/**
 *  Auth0 account's application info URL. By default is Auth0 CDN (EU or US).
 */
@property (strong, readonly, nonatomic) NSURL *configurationURL;

/**
 *  Initialise a new instance with values from Info.plist
 *
 *  @return an instance of A0Lock
 */
- (instancetype)init;

/**
 *  Initialise a new instance with a clientId and domain
 *
 *  @param clientId account clientId
 *  @param domain   account domain, it can be a full URL or just the domain name e.g.: samples.auth0.com.
 *
 *  @return an instance of A0Lock
 */
- (instancetype)initWithClientId:(NSString *)clientId
                          domain:(NSString *)domain;

/**
 *  Initialise a new instance with a clientId and domain
 *
 *  @param clientId account clientId
 *  @param domain   account domain, it can be a full URL or just the domain name e.g.: samples.auth0.com.
 *  @param configurationDomain domain where the account configuration can be obtained. By default https://cdn.auth0.com for US or https://cdn.eu.auth0.com for EU
 *
 *  @return an instance of A0Lock
 */
- (instancetype)initWithClientId:(NSString *)clientId
                          domain:(NSString *)domain
             configurationDomain:(NSString *)configurationDomain;

/**
 *  Creates a new instance of Lock with a clientId and domain
 *
 *  @param clientId account client identifier
 *  @param domain   account domain
 *
 *  @return a new instance
 */
+ (instancetype)newLockWithClientId:(NSString *)clientId
                             domain:(NSString *)domain;

/**
 *  Creates a new instance of Lock with a clientId, domain and configuration domain.
 *
 *  @param clientId            account client identifier
 *  @param domain              account domain
 *  @param configurationDomain domain where the account configuration can be obtained. By default https://cdn.auth0.com for US or https://cdn.eu.auth0.com for EU
 *
 *  @return a new instance
 */
+ (instancetype)newLockWithClientId:(NSString *)clientId
                             domain:(NSString *)domain
                configurationDomain:(NSString *)configurationDomain;


/**
 *  Creates a new instance of Lock using information stored in your Info.plist.
 *  These are the the valid entries:
 *      - Auth0ClientId: Your app's client identifier in Auth0.
 *      - Auth0Domain: Your app's domain name or url in Auth0. e.g: samples.auth0.com or https://samples.auth0.com
 *      - Auth0ConfigurationDomain: Your app's configuration domain name or url where we get yout app configuration. This value is optional and will default to Auth0 CDN.
 *
 *  @return a new instance
 */
+ (instancetype)newLock;

/**
 *  Auth0 Authentication API client.
 *
 *  @return an API client
 */
- (A0APIClient *)apiClient;

/**
 *  API client to make request to Auth0 authorized by the id_token
 *
 *  @param idToken user's id_token
 *
 *  @return an new API client
 */
- (A0UserAPIClient *)newUserAPIClientWithIdToken:(NSString *)idToken;

/**
 *  Auth0 IdP authenticator for Social & Enterprise connections.
 *  This object handles either native integrations or Web-flow for authentication.
 *
 *  @return a IdP authenticator instance
 */
- (A0IdentityProviderAuthenticator *)identityProviderAuthenticator;

@end
