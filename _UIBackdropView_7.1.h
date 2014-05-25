/* Generated by RuntimeBrowser
   Image: /System/Library/Frameworks/UIKit.framework/UIKit
 */

@class <_UIBackdropViewGraphicsQualityChangeDelegate>, <_UIBackdropViewObserver>, CAFilter, NSHashTable, NSMutableDictionary, NSMutableSet, NSString, UIColor, UIImage, UIView, _UIBackdropEffectView, _UIBackdropViewSettings;

@interface _UIBackdropView : UIView {
    BOOL __backdropVisible;
    NSString *__blurQuality;
    float __blurRadius;
    float __saturationDeltaFactor;
    BOOL __zoomsBack;
    BOOL _allowsColorSettingsSuppression;
    double _appliesOutputSettingsAnimationDuration;
    BOOL _appliesOutputSettingsAutomatically;
    BOOL _appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
    BOOL _applySettingsAfterLayout;
    BOOL _applyingBackdropChanges;
    BOOL _applyingTransition;
    BOOL _autosizesToFitSuperview;
    _UIBackdropEffectView *_backdropEffectView;
    BOOL _backdropVisibilitySetOnce;
    int _blurHardEdges;
    BOOL _blurRadiusSetOnce;
    BOOL _blursBackground;
    UIImage *_colorBurnTintMaskImage;
    UIView *_colorBurnTintView;
    UIColor *_colorMatrixColorTint;
    float _colorMatrixColorTintAlpha;
    float _colorMatrixGrayscaleTintAlpha;
    float _colorMatrixGrayscaleTintLevel;
    CAFilter *_colorSaturateFilter;
    UIImage *_colorTintMaskImage;
    UIView *_colorTintMaskViewContainer;
    NSMutableDictionary *_colorTintMaskViewMap;
    UIView *_colorTintView;
    id _computeAndApplySettingsNotificationObserver;
    BOOL _computesColorSettings;
    int _configuration;
    UIView *_contentView;
    BOOL _contentViewAccessed;
    BOOL _contentViewAccessorGuard;
    UIImage *_darkeningTintMaskImage;
    UIView *_darkeningTintView;
    UIImage *_filterMaskImage;
    UIView *_filterMaskViewContainer;
    NSMutableDictionary *_filterMaskViewMap;
    CAFilter *_gaussianBlurFilter;
    <_UIBackdropViewGraphicsQualityChangeDelegate> *_graphicsQualityChangeDelegate;
    UIImage *_grayscaleTintMaskImage;
    UIView *_grayscaleTintMaskViewContainer;
    NSMutableDictionary *_grayscaleTintMaskViewMap;
    UIView *_grayscaleTintView;
    NSString *_groupName;
    _UIBackdropViewSettings *_inputSettings;
    int _maskMode;
    <_UIBackdropViewObserver> *_observer;
    NSHashTable *_observers;
    _UIBackdropViewSettings *_outputSettings;
    NSMutableSet *_partialMaskViews;
    float _previousBackdropStatisticsBlue;
    float _previousBackdropStatisticsContrast;
    float _previousBackdropStatisticsGreen;
    float _previousBackdropStatisticsRed;
    BOOL _requiresTintViews;
    _UIBackdropViewSettings *_savedInputSettingsDuringRenderInContext;
    BOOL _simulatesMasks;
    int _style;
    CAFilter *_tintFilter;
    struct __CFRunLoopObserver { } *_updateInputBoundsRunLoopObserver;
    BOOL _updateMaskViewsForViewReentrancyGuard;
    BOOL _wantsColorSettings;
}

@property BOOL _backdropVisible;
@property(copy) NSString * _blurQuality;
@property float _blurRadius;
@property float _saturationDeltaFactor;
@property(setter=setZoomsBack:) BOOL _zoomsBack;
@property BOOL allowsColorSettingsSuppression;
@property double appliesOutputSettingsAnimationDuration;
@property BOOL appliesOutputSettingsAutomatically;
@property BOOL appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
@property BOOL applySettingsAfterLayout;
@property BOOL applyingBackdropChanges;
@property BOOL applyingTransition;
@property BOOL autosizesToFitSuperview;
@property(retain) _UIBackdropEffectView * backdropEffectView;
@property BOOL backdropVisibilitySetOnce;
@property int blurHardEdges;
@property BOOL blurRadiusSetOnce;
@property BOOL blursBackground;
@property(retain) UIImage * colorBurnTintMaskImage;
@property(retain) UIView * colorBurnTintView;
@property(retain) UIColor * colorMatrixColorTint;
@property float colorMatrixColorTintAlpha;
@property float colorMatrixGrayscaleTintAlpha;
@property float colorMatrixGrayscaleTintLevel;
@property(retain) CAFilter * colorSaturateFilter;
@property(retain) UIImage * colorTintMaskImage;
@property(retain) UIView * colorTintMaskViewContainer;
@property(retain) NSMutableDictionary * colorTintMaskViewMap;
@property(retain) UIView * colorTintView;
@property(retain) id computeAndApplySettingsNotificationObserver;
@property BOOL computesColorSettings;
@property int configuration;
@property(retain) UIView * contentView;
@property BOOL contentViewAccessed;
@property BOOL contentViewAccessorGuard;
@property(retain) UIImage * darkeningTintMaskImage;
@property(retain) UIView * darkeningTintView;
@property(readonly) UIView * effectView;
@property(retain) UIImage * filterMaskImage;
@property(retain) UIView * filterMaskViewContainer;
@property(retain) NSMutableDictionary * filterMaskViewMap;
@property(retain) CAFilter * gaussianBlurFilter;
@property <_UIBackdropViewGraphicsQualityChangeDelegate> * graphicsQualityChangeDelegate;
@property(retain) UIImage * grayscaleTintMaskImage;
@property(retain) UIView * grayscaleTintMaskViewContainer;
@property(retain) NSMutableDictionary * grayscaleTintMaskViewMap;
@property(retain) UIView * grayscaleTintView;
@property(copy) NSString * groupName;
@property(retain) _UIBackdropViewSettings * inputSettings;
@property int maskMode;
@property <_UIBackdropViewObserver> * observer;
@property(retain) NSHashTable * observers;
@property(retain) _UIBackdropViewSettings * outputSettings;
@property(retain) NSMutableSet * partialMaskViews;
@property float previousBackdropStatisticsBlue;
@property float previousBackdropStatisticsContrast;
@property float previousBackdropStatisticsGreen;
@property float previousBackdropStatisticsRed;
@property BOOL requiresTintViews;
@property(retain) _UIBackdropViewSettings * savedInputSettingsDuringRenderInContext;
@property BOOL simulatesMasks;
@property int style;
@property(retain) CAFilter * tintFilter;
@property struct __CFRunLoopObserver { }* updateInputBoundsRunLoopObserver;
@property BOOL updateMaskViewsForViewReentrancyGuard;
@property BOOL wantsColorSettings;

+ (void)adjustGraphicsQualityForAccessibilityIfNeeded:(id)arg1;
+ (id)allBackdropViews;
+ (Class)defaultSettingsClass;
+ (Class)layerClass;
+ (void)restoreColorSettingsForDidBecomeActive:(id)arg1;
+ (void)restoreColorSettingsForRequester:(id)arg1;
+ (void)restoreColorSettingsForRunLoopModePop:(id)arg1;
+ (void)setAllBackdropViewsToGraphicsQuality:(int)arg1;
+ (void)suppressColorSettingsForRequester:(id)arg1;
+ (void)suppressColorSettingsForRunLoopModePush:(id)arg1;
+ (void)suppressColorSettingsForWillResignActive:(id)arg1;

- (BOOL)_backdropVisible;
- (id)_blurQuality;
- (float)_blurRadius;
- (float)_saturationDeltaFactor;
- (void)_setBlursBackground:(BOOL)arg1;
- (void)_updateFilters;
- (void)_updateInputBounds;
- (BOOL)_zoomsBack;
- (void)addBackdropEffectViewIfNeededForSettings:(id)arg1;
- (void)addColorBurnTintViewIfNeededForSettings:(id)arg1;
- (void)addColorTintViewIfNeededForSettings:(id)arg1;
- (void)addContentViewIfNeededForSettings:(id)arg1;
- (void)addDarkeningTintViewIfNeededForSettings:(id)arg1;
- (void)addGrayscaleTintViewIfNeededForSettings:(id)arg1;
- (void)addObserver:(id)arg1;
- (void)adjustTintImplementationIfNeeded:(id)arg1;
- (BOOL)allowsColorSettingsSuppression;
- (double)appliesOutputSettingsAnimationDuration;
- (BOOL)appliesOutputSettingsAutomatically;
- (BOOL)appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
- (void)applyOverlayBlendMode:(int)arg1 toView:(id)arg2;
- (void)applyOverlayBlendModeToView:(id)arg1;
- (void)applySettings:(id)arg1;
- (BOOL)applySettingsAfterLayout;
- (void)applySettingsWithBuiltInAnimation:(id)arg1;
- (BOOL)applyingBackdropChanges;
- (BOOL)applyingTransition;
- (BOOL)autosizesToFitSuperview;
- (id)backdropEffectView;
- (void)backdropLayerStatisticsDidChange:(id)arg1;
- (id)backdropViewLayer;
- (BOOL)backdropVisibilitySetOnce;
- (int)blurHardEdges;
- (id)blurQuality;
- (float)blurRadius;
- (BOOL)blurRadiusSetOnce;
- (BOOL)blursBackground;
- (BOOL)blursWithHardEdges;
- (void)clearUpdateInputBoundsRunLoopObserver;
- (id)colorBurnTintMaskImage;
- (id)colorBurnTintView;
- (id)colorMatrixColorTint;
- (float)colorMatrixColorTintAlpha;
- (float)colorMatrixGrayscaleTintAlpha;
- (float)colorMatrixGrayscaleTintLevel;
- (id)colorSaturateFilter;
- (id)colorTintMaskImage;
- (id)colorTintMaskViewContainer;
- (id)colorTintMaskViewMap;
- (id)colorTintView;
- (void)computeAndApplySettings:(id)arg1;
- (void)computeAndApplySettingsForTransition;
- (id)computeAndApplySettingsNotificationObserver;
- (BOOL)computesColorSettings;
- (int)configuration;
- (id)contentView;
- (BOOL)contentViewAccessed;
- (BOOL)contentViewAccessorGuard;
- (id)darkeningTintMaskImage;
- (id)darkeningTintView;
- (void)dealloc;
- (void)delayedComputeAndApplySettings;
- (void)didCallRenderInContextOnBackdropViewLayer;
- (void)didMoveToSuperview;
- (BOOL)disablesOccludedBackdropBlurs;
- (id)effectView;
- (void)ensureProperSubviewOrdering;
- (id)filterMaskImage;
- (id)filterMaskViewContainer;
- (id)filterMaskViewMap;
- (id)filters;
- (id)gaussianBlurFilter;
- (id)graphicsQualityChangeDelegate;
- (id)grayscaleTintMaskImage;
- (id)grayscaleTintMaskViewContainer;
- (id)grayscaleTintMaskViewMap;
- (id)grayscaleTintView;
- (id)groupName;
- (id)init;
- (id)initWithFrame:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1 autosizesToFitSuperview:(BOOL)arg2 settings:(id)arg3;
- (id)initWithFrame:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1 privateStyle:(int)arg2;
- (id)initWithFrame:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1 settings:(id)arg2;
- (id)initWithFrame:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1 style:(int)arg2;
- (id)initWithFrame:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1;
- (id)initWithPrivateStyle:(int)arg1;
- (id)initWithSettings:(id)arg1;
- (id)initWithStyle:(int)arg1;
- (id)inputSettings;
- (BOOL)isBackdropVisible;
- (void)layoutSubviews;
- (int)maskMode;
- (id)observer;
- (id)observers;
- (id)outputSettings;
- (id)partialMaskViews;
- (void)prepareForTransitionToSettings:(id)arg1;
- (float)previousBackdropStatisticsBlue;
- (float)previousBackdropStatisticsContrast;
- (float)previousBackdropStatisticsGreen;
- (float)previousBackdropStatisticsRed;
- (void)removeMaskViews;
- (void)removeObserver:(id)arg1;
- (void)removeOverlayBlendModeFromView:(id)arg1;
- (BOOL)requiresTintViews;
- (float)saturationDeltaFactor;
- (id)savedInputSettingsDuringRenderInContext;
- (void)scheduleUpdateInputBoundsIfNeeded;
- (void)setAllowsColorSettingsSuppression:(BOOL)arg1;
- (void)setAppliesOutputSettingsAnimationDuration:(double)arg1;
- (void)setAppliesOutputSettingsAutomatically:(BOOL)arg1;
- (void)setAppliesOutputSettingsAutomaticallyEnabledComputesColorSettings:(BOOL)arg1;
- (void)setApplySettingsAfterLayout:(BOOL)arg1;
- (void)setApplyingBackdropChanges:(BOOL)arg1;
- (void)setApplyingTransition:(BOOL)arg1;
- (void)setAutosizesToFitSuperview:(BOOL)arg1;
- (void)setBackdropEffectView:(id)arg1;
- (void)setBackdropVisibilitySetOnce:(BOOL)arg1;
- (void)setBackdropVisible:(BOOL)arg1;
- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(id)arg2 blurHardEdges:(int)arg3;
- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(id)arg2;
- (void)setBlurHardEdges:(int)arg1;
- (void)setBlurQuality:(id)arg1;
- (void)setBlurRadius:(float)arg1;
- (void)setBlurRadiusSetOnce:(BOOL)arg1;
- (void)setBlursBackground:(BOOL)arg1;
- (void)setBlursWithHardEdges:(BOOL)arg1;
- (void)setBounds:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1;
- (void)setColorBurnTintMaskImage:(id)arg1;
- (void)setColorBurnTintView:(id)arg1;
- (void)setColorMatrixColorTint:(id)arg1;
- (void)setColorMatrixColorTintAlpha:(float)arg1;
- (void)setColorMatrixGrayscaleTintAlpha:(float)arg1;
- (void)setColorMatrixGrayscaleTintLevel:(float)arg1;
- (void)setColorSaturateFilter:(id)arg1;
- (void)setColorTintMaskImage:(id)arg1;
- (void)setColorTintMaskViewContainer:(id)arg1;
- (void)setColorTintMaskViewMap:(id)arg1;
- (void)setColorTintView:(id)arg1;
- (void)setComputeAndApplySettingsNotificationObserver:(id)arg1;
- (void)setComputesColorSettings:(BOOL)arg1;
- (void)setConfiguration:(int)arg1;
- (void)setContentView:(id)arg1;
- (void)setContentViewAccessed:(BOOL)arg1;
- (void)setContentViewAccessorGuard:(BOOL)arg1;
- (void)setDarkeningTintMaskImage:(id)arg1;
- (void)setDarkeningTintView:(id)arg1;
- (void)setDisablesOccludedBackdropBlurs:(BOOL)arg1;
- (void)setFilterMaskImage:(id)arg1;
- (void)setFilterMaskViewContainer:(id)arg1;
- (void)setFilterMaskViewMap:(id)arg1;
- (void)setFrame:(struct CGRect { struct CGPoint { float x_1_1_1; float x_1_1_2; } x1; struct CGSize { float x_2_1_1; float x_2_1_2; } x2; })arg1;
- (void)setGaussianBlurFilter:(id)arg1;
- (void)setGraphicsQualityChangeDelegate:(id)arg1;
- (void)setGrayscaleTintMaskImage:(id)arg1;
- (void)setGrayscaleTintMaskViewContainer:(id)arg1;
- (void)setGrayscaleTintMaskViewMap:(id)arg1;
- (void)setGrayscaleTintView:(id)arg1;
- (void)setGroupName:(id)arg1;
- (void)setInputSettings:(id)arg1;
- (void)setMaskImage:(id)arg1 onLayer:(id)arg2;
- (void)setMaskMode:(int)arg1;
- (void)setObserver:(id)arg1;
- (void)setObservers:(id)arg1;
- (void)setOutputSettings:(id)arg1;
- (void)setPartialMaskViews:(id)arg1;
- (void)setPreviousBackdropStatisticsBlue:(float)arg1;
- (void)setPreviousBackdropStatisticsContrast:(float)arg1;
- (void)setPreviousBackdropStatisticsGreen:(float)arg1;
- (void)setPreviousBackdropStatisticsRed:(float)arg1;
- (void)setRequiresTintViews:(BOOL)arg1;
- (void)setSaturationDeltaFactor:(float)arg1;
- (void)setSavedInputSettingsDuringRenderInContext:(id)arg1;
- (void)setShouldRasterizeEffectsView:(BOOL)arg1;
- (void)setSimulatesMasks:(BOOL)arg1;
- (void)setStyle:(int)arg1;
- (void)setTintFilter:(id)arg1;
- (void)setTintFilterForSettings:(id)arg1;
- (void)setUpdateInputBoundsRunLoopObserver:(struct __CFRunLoopObserver { }*)arg1;
- (void)setUpdateMaskViewsForViewReentrancyGuard:(BOOL)arg1;
- (void)setUsesZoom;
- (void)setWantsColorSettings:(BOOL)arg1;
- (void)setZoomsBack:(BOOL)arg1;
- (void)set_backdropVisible:(BOOL)arg1;
- (void)set_blurQuality:(id)arg1;
- (void)set_blurRadius:(float)arg1;
- (void)set_saturationDeltaFactor:(float)arg1;
- (void)settingsDidChange:(id)arg1;
- (BOOL)simulatesMasks;
- (int)style;
- (id)tintFilter;
- (void)transitionComplete;
- (void)transitionIncrementallyToPrivateStyle:(int)arg1 weighting:(float)arg2;
- (void)transitionIncrementallyToStyle:(int)arg1 weighting:(float)arg2;
- (void)transitionToColor:(id)arg1;
- (void)transitionToPrivateStyle:(int)arg1;
- (void)transitionToSettings:(id)arg1;
- (void)transitionToStyle:(int)arg1;
- (struct __CFRunLoopObserver { }*)updateInputBoundsRunLoopObserver;
- (void)updateMaskViewForView:(id)arg1 flag:(int)arg2;
- (void)updateMaskViewsForView:(id)arg1;
- (BOOL)updateMaskViewsForViewReentrancyGuard;
- (void)updateSubviewHierarchyIfNeededForSettings:(id)arg1;
- (BOOL)wantsColorSettings;
- (void)willCallRenderInContextOnBackdropViewLayer;

@end