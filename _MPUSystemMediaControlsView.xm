
#import "_MPUSystemMediaControlsView.h"
#import "MCCTweakController.h"
#import <objc/runtime.h>
#import <MediaPlayer/MPVolumeView.h>
#import "Utils.h"

@interface MPVolumeView()
@property(nonatomic) BOOL showsVolumeSlider;
@end

// static char const * const IsCCSectionKey = "IsCCSection";
static char const * const FirstLayoutKey = "FirstLayout";
static char const * const AirPlayButtonKey = "AirPlayButton";
static char const * const MenuButtonKey = "MenuButton";

#define volumeViewHeight 49.000000
#define timeInformationViewHeight 34.000000
#define trackInformationViewHeight 40.000000
#define transportControlsViewHeight 52.000000

#define volumeViewTop 101.000000
#define timeInformationViewTop 3.000000
#define trackInformationViewTop 31.000000
#define transportControlsViewTop 58.000000

float getMediaControlsHeight(BOOL isLS)
{
    BOOL hideVolume, hideInfo, hideTime, hideButtons;
    if (isLS) {
        hideVolume = !BOOL_PROP(lsShowVolume);
        hideInfo = !BOOL_PROP(lsShowInfo);
        hideTime = !BOOL_PROP(lsShowTime);
        hideButtons = !BOOL_PROP(lsShowButtons);
    } else {
        hideVolume = !BOOL_PROP(ccShowVolume);
        hideInfo = !BOOL_PROP(ccShowInfo);
        hideTime = !BOOL_PROP(ccShowTime);
        hideButtons = !BOOL_PROP(ccShowButtons);
    }

    CGFloat height = 0;
    CGFloat top = timeInformationViewTop;
    if (!hideTime) {
        height = MAX(height, top + timeInformationViewHeight);
        top += (trackInformationViewTop - timeInformationViewTop);
    }
    if (!hideInfo) {
        height = MAX(height, top + trackInformationViewHeight);
        top += (transportControlsViewTop - trackInformationViewTop);
    }
    if (!hideButtons) {
        height = MAX(height, top + transportControlsViewHeight);
        top += (volumeViewTop - transportControlsViewTop);
    }
    if (!hideVolume) {
        height = MAX(height, top + volumeViewHeight);
    }
    else {
        height += 10;
    }
    return height;
}

static CGRect originalTrackInformationViewFrame;
static CGRect originalTransportControlsViewFrame;
static CGRect originalTimeInformationViewFrame;
static CGRect originalVolumeViewFrame;

@interface _MPUSystemMediaControlsView()
-(BOOL)gesturesEnabled ;
-(BOOL)gesturesInversed ;
-(void)afterLayoutSubviews;
-(float)getMediaControlsHeight;
-(BOOL)shouldLayout;
@end

@implementation _MPUSystemMediaControlsView (Additions)
@dynamic isCCSection;
@dynamic firstLayout;

- (BOOL)isCCSection {
    return ([self style] == 1);
}


- (BOOL)firstLayout {
    NSNumber *number = objc_getAssociatedObject(self, FirstLayoutKey);
    return number?[number boolValue]:TRUE; //default is true
}

- (void)setFirstLayout:(BOOL)value {
    objc_setAssociatedObject(self, FirstLayoutKey,  [NSNumber numberWithBool: value], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}


- (MPVolumeView*)airplayButton {
    return objc_getAssociatedObject(self, AirPlayButtonKey);
}

- (void)setAirplayButton:(MPVolumeView*)value {
    objc_setAssociatedObject(self, AirPlayButtonKey, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (UIButton*)menuButton {
    return objc_getAssociatedObject(self, MenuButtonKey);
}
- (void)setMenuButton:(UIButton*)value {
    objc_setAssociatedObject(self, MenuButtonKey, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
@end

%hook _MPUSystemMediaControlsView

%new 
-(BOOL)shouldLayout{
    BOOL isCCControl = [self isCCSection];
    return SHOULD_HOOK() && isCCControl?BOOL_PROP(ccCustomLayout):BOOL_PROP(lsCustomLayout);
}

%new
-(void)afterLayoutSubviews
{
    MPVolumeView* airPlayButton = [self airplayButton];
    UIButton* menuButton = [self menuButton];
    if (![self shouldLayout]) {
        if (![self firstLayout]) {
            [self.volumeView setHidden:NO];
            [self.timeInformationView setHidden:NO];
            [self.trackInformationView setHidden:NO];
            [self.transportControlsView setHidden:NO];
            self.trackInformationView.frame = originalTrackInformationViewFrame;
            self.transportControlsView.frame = originalTransportControlsViewFrame;
            self.timeInformationView.frame = originalTimeInformationViewFrame;
            self.volumeView.frame = originalVolumeViewFrame;
            [airPlayButton setHidden:YES];
            [menuButton setHidden:YES];
            self.firstLayout = YES;
        }
        return;
    }
    if ([self firstLayout]) {
        originalTrackInformationViewFrame = self.trackInformationView.frame;
        originalTransportControlsViewFrame = self.transportControlsView.frame;
        originalTimeInformationViewFrame = self.timeInformationView.frame;
        originalVolumeViewFrame = self.volumeView.frame;
        self.firstLayout = NO;
    }
    BOOL hideVolume, hideInfo, hideTime, hideButtons, hideAirPlay, hideMenuButton;
    BOOL isCCControl = [self isCCSection];
    MPUNowPlayingTitlesView* trackInformationView = ((MPUNowPlayingTitlesView*)self.trackInformationView);

    if (trackInformationView.titleText == nil) {
        [trackInformationView setTitleText:isCCControl?STRING_PROP(ccNoPlayingText):STRING_PROP(lsNoPlayingText)];
    }

    if (trackInformationView.artistText == nil || trackInformationView.artistText == [NSNull null]) {
        BOOL oneTapToOpen = (isCCControl && BOOL_PROP(ccOneTapToOpenNoMusic)) || (!isCCControl && BOOL_PROP(lsOneTapToOpenNoMusic));
        SBApplication* app = [[%c(SBApplicationController) sharedInstance] applicationWithDisplayIdentifier:STRING_PROP(DefaultApp)];  
        [trackInformationView setArtistText:[NSString stringWithFormat:oneTapToOpen?@"Tap to open %@":@"Long press to open %@", [app displayName]]];
    }

    
    if (isCCControl) {
        hideVolume = !BOOL_PROP(ccShowVolume);
        hideInfo = !BOOL_PROP(ccShowInfo);
        hideTime = !BOOL_PROP(ccShowTime);
        hideButtons = !BOOL_PROP(ccShowButtons);
        hideAirPlay = !BOOL_PROP(ccShowAirplay);
        hideMenuButton = !BOOL_PROP(ccShowMenuButton);
    } else {
        hideVolume = !BOOL_PROP(lsShowVolume);
        hideInfo = !BOOL_PROP(lsShowInfo);
        hideTime = !BOOL_PROP(lsShowTime);
        hideButtons = !BOOL_PROP(lsShowButtons);
        hideAirPlay = !BOOL_PROP(lsShowAirplay);
        hideMenuButton = !BOOL_PROP(lsShowMenuButton);
    }
    hideMenuButton |= !menuButton || (hideInfo && hideButtons);
    hideAirPlay |= !airPlayButton || (hideInfo && hideButtons);

    [self.volumeView setHidden:hideVolume];
    [self.timeInformationView setHidden:hideTime];
    [self.trackInformationView setHidden:hideInfo];
    [self.transportControlsView setHidden:hideButtons];

    CGFloat top = timeInformationViewTop;
    CGRect frame;
    if (!hideTime) {
        top += (trackInformationViewTop - timeInformationViewTop);
    }

    if (!hideInfo) {
        frame = self.trackInformationView.frame;
        frame.origin.y = top;
        frame.size.height = trackInformationViewHeight;
        self.trackInformationView.frame = frame;
        top += (transportControlsViewTop - trackInformationViewTop);
    }

    if (!hideButtons) {
        frame = self.transportControlsView.frame;
        frame.origin.y = top;
        frame.size.height = transportControlsViewHeight;
        self.transportControlsView.frame = frame;
        top += (volumeViewTop - transportControlsViewTop);
    }
    else {
        //to add a little padding between info and volume
        top += 5;
    }
    if (!hideVolume) {
        frame = self.volumeView.frame;
        frame.origin.y = top;
        frame.size.height = volumeViewHeight;
        self.volumeView.frame = frame;
    }


    if (!hideAirPlay || !hideMenuButton) {
        [airPlayButton sizeToFit];
        CGRect menuButtonFrame = menuButton.frame;
        menuButtonFrame.origin.x = 2;
        CGRect airplayFrame = airPlayButton.frame;
        CGFloat aWidth = airplayFrame.size.width + 2; //for a little right padding
        CGFloat aHeight = airplayFrame.size.height;
        CGRect myFrame = self.bounds;
        if (!hideButtons) {
            CGRect buttonsFrame = self.transportControlsView.frame;
            airplayFrame.origin.x = CGRectGetMaxX(myFrame) - aWidth;
            airplayFrame.origin.y = CGRectGetMidY(buttonsFrame) - aHeight/2.0f + 10.0f; //why is not centered ?
            menuButtonFrame.origin.y = CGRectGetMidY(buttonsFrame) - menuButtonFrame.size.height/2.0f + 10.0f; //why is not centered?
        }
        else if (!hideInfo) {
            CGRect infoFrame = self.trackInformationView.frame;
            airplayFrame.origin.x = CGRectGetMaxX(myFrame) - aWidth;
            airplayFrame.origin.y = CGRectGetMidY(infoFrame) - aHeight/2.0f;
            menuButtonFrame.origin.y = CGRectGetMidY(infoFrame) - menuButtonFrame.size.height/2.0f;
            infoFrame.origin.x = aWidth;
            infoFrame.size.width -= 2*aWidth;
            self.trackInformationView.frame = infoFrame;
        }
        airPlayButton.frame = airplayFrame;
        menuButton.frame = menuButtonFrame;
    }
    [airPlayButton setHidden:hideAirPlay];    
    [menuButton setHidden:hideMenuButton];  
}

// -(void)setFrame:(CGRect)frame {
//     if (SHOULD_HOOK()) {
//         frame.size.height = [self getMediaControlsHeight];
//     }
//     %orig(frame);

//     Log(@"setFrame %@ %@", BOOL_TO_STRING([self isCCSection]), NSStringFromCGRect(frame));
// }

// -(CGRect)frame {
//     CGRect result = %orig;
//     if (SHOULD_HOOK()) {
//         result.size.height = [self getMediaControlsHeight];
//     }
//     Log(@"getFrame %@", NSStringFromCGRect(result));
//     return result;
// }

%new
-(float)getMediaControlsHeight
{
    return getMediaControlsHeight(![self isCCSection]);
}

// - (void)setFrame:(CGRect)frame {
//     frame.size.height =  [self getMediaControlsHeight];
//     %orig(frame);
//     Log(@"setFrame %@", NSStringFromCGRect(frame));
// }

- (void)layoutSubviews {
    %orig;
    [self afterLayoutSubviews];
}

- (void)_layoutSubviewsControlCenteriPad {
    %orig;
    [self afterLayoutSubviews];
}

-(id)initWithStyle:(int)arg1 {
    UIView* view = %orig;
    UISwipeGestureRecognizer *swipeReco = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipeLeftGesture:)];
    [swipeReco setDirection:(UISwipeGestureRecognizerDirectionLeft)];
    [view addGestureRecognizer:swipeReco];

    swipeReco = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipeRightGesture:)];
    [swipeReco setDirection:(UISwipeGestureRecognizerDirectionRight)];
    [view addGestureRecognizer:swipeReco];

    UILongPressGestureRecognizer *longPressReco = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPressGesture:)];
    longPressReco.delegate = (id<UILongPressGestureRecognizerDelegate>)self;
    [view addGestureRecognizer:longPressReco];

    MPVolumeView *volumeView = [[MPVolumeView alloc] init];
    [volumeView setShowsVolumeSlider:NO];
    [volumeView setHidden:![self shouldLayout]];
    [volumeView sizeToFit];
    [view addSubview:volumeView];
    [self setAirplayButton:volumeView];

    UIButton *menuButton = [UIButton buttonWithType:UIButtonTypeCustom];
    menuButton.userInteractionEnabled = YES;
    [menuButton setFrame:CGRectMake(0.0,0.0, 29.0, 29.0)];
    menuButton.showsTouchWhenHighlighted = YES;
    [menuButton setImage:getBundleImage(@"menu") forState:UIControlStateNormal];
    [menuButton addTarget:self action:@selector(menuButtonAction) forControlEvents:UIControlEventTouchUpInside];
    [view addSubview:menuButton];
    [self setMenuButton:menuButton];
    return view;
}

%new
-(void)menuButtonAction
{
    if (!SHOULD_HOOK()) return;
    BOOL isCCControl = [self isCCSection];

    NSOrderedSet * actions = [NSOrderedSet orderedSetWithArray:[MCCTweakController getProp:isCCControl?@"ccEnabledSections":@"lsEnabledSections"]];
    UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:nil delegate:((id<UIActionSheetDelegate>)self) cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:nil];
    for( NSString *ID in actions)  {
        LAEvent *event = [[LAEvent alloc] initWithName:ID];
        NSString* listenerName = [LASharedActivator assignedListenerNameForEvent:event];
        NSArray* listeners = [listenerName componentsSeparatedByString:@";"];
        if ([listeners count] > 0) {
            [actionSheet addButtonWithTitle:getActivatorDisplayName(listeners)]; 
            [[[actionSheet valueForKey:@"_buttons"] lastObject] setImage:getActivatorEventImage(listeners) forState:UIControlStateNormal];
        }
    }
    actionSheet.cancelButtonIndex = [actionSheet addButtonWithTitle:@"Cancel"];
    [actionSheet showInView:self];
}

%new
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == actionSheet.cancelButtonIndex) return;
    BOOL isCCControl = [self isCCSection];
    NSOrderedSet * actions = [NSOrderedSet orderedSetWithArray:[MCCTweakController getProp:isCCControl?@"ccEnabledSections":@"lsEnabledSections"]];
    NSString* ID = [actions objectAtIndex:buttonIndex];
    LAEvent *event = [[LAEvent alloc] initWithName:ID];
    [LASharedActivator sendEventToListener:event];
}


%new
-(BOOL)gesturesEnabled 
{
    if (!SHOULD_HOOK()) return false;
    BOOL isCCControl = [self isCCSection];
    return ((isCCControl && BOOL_PROP(ccGesturesEnabled)) || (!isCCControl && BOOL_PROP(lsGesturesEnabled)));
}

%new
-(BOOL)gesturesInversed 
{
    return BOOL_PROP(gesturesInversed);
}

%new
- (void) handleDoubleTap:(UIGestureRecognizer*) sender
{
    if (![self gesturesEnabled]) return;
}

%new
-(void)handleSwipeLeftGesture:(UISwipeGestureRecognizer*)sender
{
    if (![self gesturesEnabled]) return;
    // [[%c(SBMediaController) sharedInstance] changeTrack:[self gesturesInversed]?-1:1];
    [MCCTweakController runAction:[self gesturesInversed]?kMCCActionPreviousTrack:kMCCActionNextTrack];
}

%new
-(void)handleSwipeRightGesture:(UISwipeGestureRecognizer*)sender
{
    if (![self gesturesEnabled]) return;
    [MCCTweakController runAction:[self gesturesInversed]?kMCCActionNextTrack:kMCCActionPreviousTrack];
   // [[%c(SBMediaController) sharedInstance] changeTrack:[self gesturesInversed]?1:-1];
}

%new
-(void)handleLongPressGesture:(UILongPressGestureRecognizer*)sender
{
    if (![self gesturesEnabled]) return;
    if (sender.state == UIGestureRecognizerStateEnded) {
    } else if (sender.state == UIGestureRecognizerStateBegan) {
        SBApplication* app = [[%c(SBMediaController) sharedInstance] nowPlayingApplication];
        NSString* defaultApp = STRING_PROP(DefaultApp);
        if (BOOL_PROP(alwaysUseDefaultApp) || !app) {
            [[%c(SBUIController) sharedInstance] activateApplicationAnimated:[[%c(SBApplicationController) sharedInstance] applicationWithDisplayIdentifier:defaultApp]];
        }
        else {
            [[%c(SBUIController) sharedInstance] activateApplicationAnimated:app];
        }
    }
}
%end
