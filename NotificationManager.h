//
//  NotificationManager.h
//  MacDroidNotifier
//
//  Created by Rodrigo Damazio on 25/12/09.
//

#import <Cocoa/Cocoa.h>
#import "NotificationListener.h"

@class ActionDispatcher;
@class Notification;

// The callback which receives notifications from this manager.
@protocol NotificationCallback
- (void)handleNotification:(Notification *)notification;
@end

// Notification manager, which receives raw notifications from the listeners,
// decodes them, and forwards them to the given notification callback.
@interface NotificationManager : NSObject<NotificationListenerCallback> {
 @private
  // Dispatcher which takes action on notifications
  ActionDispatcher *dispatcher;

  // TODO(rdamazio): Replace this with PairAction.
  NSObject<NotificationCallback> *pairingCallback;

  // Listeners which receive notifications and pass them to this object
  NSArray *listeners;

  // Last few received notifications, for eliminating duplicates
  NSMutableArray *lastNotifications;

  // Total count of received notifications
  int notificationCount;
}

// Initializes the notification manager, with an action dispatcher which is
// called to handle every notification, including for pairing.
- (id)initWithDispatcher:(ActionDispatcher *)dispatcher
     withPairingCallback:(NSObject<NotificationCallback> *)pairingCallback;

@end
