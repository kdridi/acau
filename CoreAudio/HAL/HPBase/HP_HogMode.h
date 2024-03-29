/*	Copyright � 2007 Apple Inc. All Rights Reserved.
	
	Disclaimer: IMPORTANT:  This Apple software is supplied to you by 
			Apple Inc. ("Apple") in consideration of your agreement to the
			following terms, and your use, installation, modification or
			redistribution of this Apple software constitutes acceptance of these
			terms.  If you do not agree with these terms, please do not use,
			install, modify or redistribute this Apple software.
			
			In consideration of your agreement to abide by the following terms, and
			subject to these terms, Apple grants you a personal, non-exclusive
			license, under Apple's copyrights in this original Apple software (the
			"Apple Software"), to use, reproduce, modify and redistribute the Apple
			Software, with or without modifications, in source and/or binary forms;
			provided that if you redistribute the Apple Software in its entirety and
			without modifications, you must retain this notice and the following
			text and disclaimers in all such redistributions of the Apple Software. 
			Neither the name, trademarks, service marks or logos of Apple Inc. 
			may be used to endorse or promote products derived from the Apple
			Software without specific prior written permission from Apple.  Except
			as expressly stated in this notice, no other rights or licenses, express
			or implied, are granted by Apple herein, including but not limited to
			any patent rights that may be infringed by your derivative works or by
			other works in which the Apple Software may be incorporated.
			
			The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
			MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
			THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
			FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
			OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
			
			IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
			OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
			SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
			INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
			MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
			AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
			STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
			POSSIBILITY OF SUCH DAMAGE.
*/
#if !defined(__HP_HogMode_h__)
#define __HP_HogMode_h__

//==================================================================================================
//	Includes
//==================================================================================================

//	PublicUtility
#include "../../PublicUtility/CAProcess.h"
#include "../../PublicUtility/CATokenMap.h"

//	System Includes
#include <CoreFoundation/CoreFoundation.h>
#include <pthread.h>
#include <sys/types.h>

//#define	HogMode_UseCFPrefs	1

//==================================================================================================
//	Types
//==================================================================================================

class	HP_Device;

#if	!HogMode_UseCFPrefs
	class	CASettingsStorage;
#endif

//==================================================================================================
//	HP_HogMode
//
//	Implements tracking hog mode on behalf of a device. Note that it is currently implemented in
//	terms of a global preference and uses CFDistributedNotificationCenter for notifications. It
//	would be better to have this implemented in a way that avoided the disk, such as by having a
//	message protocol for use with Mach messages.
//==================================================================================================

class HP_HogMode
{

//	Construction/Destruction
public:
									HP_HogMode(HP_Device* inDevice);
	virtual							~HP_HogMode();
	
	virtual void					Initialize();

private:
	static void						StaticInitializer();
	
	static pthread_once_t			sStaticInitializer;

//	Operations
public:
	pid_t							GetOwner() const;
	bool							IsFree() const;
	bool							CurrentProcessIsOwner() const;
	bool							CurrentProcessIsOwnerOrIsFree() const;
	
	void							Take();
	void							Release();

//	Implementation
protected:
	HP_Device*						GetDevice() const { return mDevice; }
	void							SetOwner(pid_t inOwner) { mOwner = inOwner; }
	virtual pid_t					GetOwnerFromPreference(bool inSendNotifications) const;
	virtual void					SetOwnerInPreference(pid_t inOwner) const;
	virtual void					MarkPreferencesDirty();
	virtual void					SendHogModeChangedNotification() const;
	static void						ChangeNotification(CFNotificationCenterRef inCenter, const void* inHogModeToken, CFStringRef inNotificationName, const void* inObject, CFDictionaryRef inUserInfo);
	
	UInt32							mToken;
	HP_Device*						mDevice;
	CFStringRef						mPrefName;
	pid_t							mOwner;
	
#if	!HogMode_UseCFPrefs
	static CASettingsStorage*		sSettingsStorage;
#endif	
	static CATokenMap<HP_HogMode>*	sTokenMap;

};

#endif
