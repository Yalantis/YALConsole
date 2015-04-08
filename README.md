<p align="left" >
  <img src="https://raw.githubusercontent.com/mmrmmlrr/YALConsole/master/logo.png" alt="Yalantis" title="Yalantis" height = "100">
</p>

YALConsole v1.0
===============

**YALConsole is handy and flexible logging utility that integrates into your iOS project. It may be useful to QA engineers that usually do not have access to debugger. Besides custom logging you can add counters, observers and actions.**

Requirements
------------

-   iOS 7.0 or later
-   ARC


Integration
-----------
-   Downolad YALConsole
-   Add **YALConsole.framework** and **YALConsole.bundle** to the project
-   Add **-all_load** flag to Other Compiler Flags in Build Settings
-   Import header: `#import <YALConsole/YALConsole.h>`
 

**Installation with CocoaPods:**

Add following to your podfile:
```ruby
pod 'YALConsole', :git => "https://github.com/mmrmmlrr/YALConsole"
```

Usage
-----

Console instantiates on first call. You can do that at any point of your app from any thread. After instantiation console is available by two-finger tap gesture. It consists of two tabs: ‘Console’ as it is and ‘Dashboard’. 

### Console
Following code is similar to NSLog, it throws text message into console.

```objective-c
YALog(@"Hello, console!");
```

Unlike NSLog, output contains information about thread, class, method an line of code where call happens.
Tap output cell on ‘Console’ tab to see additional info.

### Dashboard

There are three types of items can be placed on the Dashboard: **observers, counters and actions.**

###Observer

Adding observer item you get ability to watch for value for key path using KVO.
```objective-c
[YALConsole addObserverOf:self keyPath:@"user.name" forIdentifier:@"Name"];
```
*Identifier is mandatory for each Dashboard Item. It defines uniquity of item and allows to remove object from the Dashboard when you don’t need it anymore.*

Observer highlights potentially invalid values: **null** and **nil.** 
Click the item to see history of values of observed variable. Buttons at the bottom of the screen are ‘Clear’, ‘Follow’ and ‘Freeze’. Switching ‘Follow’ off allows you to scroll list even when data updates dynamically. Freezing temporarily unsubscribes list from history updates.

###Counter

Counter works almost similar to observer, but incrementing is up to you. Counter’s values history is also available by click. 
Adding and incrementing Counter Item:
```objective-c
[YALConsole addCounterForIdentifier:@"Steps"];
[YALConsole incrementCounterForIdentifier:@"Steps"];
```

###Action

Action Items is a button on the Dashboard that is assigned execution of specified block. This can be handy for specific actions like Keychain clearing.
```objective-c
[YALConsole addAction:^{NSLog(@"Bang!");} forIdentifier:@"Make some noise"];
```

*And don’t forget of retain cycles!*

### Call Stack Symbols

Click a value on the History screen to see call stack that led to current value assignment. You will also find thread’s identifier there. Tap the icon at the the bottom of the screen to copy all the info into Pasteboard.

### Items removal
You can delete item by identifier:
```objective-c
[YALConsole removeItemForIdentifier:@"Steps"];
```
Or clear whole Dashboard:
```objective-c
[YALConsole removeAllItems];
```

### Setup

Set the history limit with this:
```objective-c
[YALConsole setHistoryLimit:200];
```
Notice that history doesn’t store values. That would make impact on app’s performance or even lead to inconsistency.
So history just keeps description strings.
In order to avoid interference with gestures used in your application, you can set the number of taps required to show console:
```objective-c
[YALConsole setNumberOfTouchesRequired:3];
```
## Contact

Follow our blog at [yalantis.com](http://yalantis.com/blog/)

### Maintainers

[Aleksey Chernish](mailto:achernish85@gmail.com)

## License

YALConsole is available under the MIT license. See the LICENSE file for more info.
