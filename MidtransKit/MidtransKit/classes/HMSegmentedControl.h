#import <UIKit/UIKit.h>

@class HMSegmented;

typedef void (^IndexChangeBlock)(NSInteger index);
typedef NSAttributedString *(^HMTitleFormatterBlock)(HMSegmented *segmentedControl, NSString *title, NSUInteger index, BOOL selected);

typedef NS_ENUM(NSInteger, HMSegmentedSelectionStyle) {
    HMSegmentedSelectionStyleTextWidthStripe, // Indicator width will only be as big as the text width
    HMSegmentedSelectionStyleFullWidthStripe, // Indicator width will fill the whole segment
    HMSegmentedSelectionStyleBox, // A rectangle that covers the whole segment
    HMSegmentedSelectionStyleArrow // An arrow in the middle of the segment pointing up or down depending on `HMSegmentedSelectionIndicatorLocation`
};

typedef NS_ENUM(NSInteger, HMSegmentedSelectionIndicatorLocation) {
    HMSegmentedSelectionIndicatorLocationUp,
    HMSegmentedSelectionIndicatorLocationDown,
    HMSegmentedSelectionIndicatorLocationNone // No selection indicator
};

typedef NS_ENUM(NSInteger, HMSegmentedSegmentWidthStyle) {
    HMSegmentedSegmentWidthStyleFixed, // Segment width is fixed
    HMSegmentedSegmentWidthStyleDynamic, // Segment width will only be as big as the text width (including inset)
};

typedef NS_OPTIONS(NSInteger, HMSegmentedBorderType) {
    HMSegmentedBorderTypeNone = 0,
    HMSegmentedBorderTypeTop = (1 << 0),
    HMSegmentedBorderTypeLeft = (1 << 1),
    HMSegmentedBorderTypeBottom = (1 << 2),
    HMSegmentedBorderTypeRight = (1 << 3)
};

enum {
    HMSegmentedNoSegment = -1   // Segment index for no selected segment
};

typedef NS_ENUM(NSInteger, HMSegmentedType) {
    HMSegmentedTypeText,
    HMSegmentedTypeImages,
    HMSegmentedTypeTextImages
};

typedef NS_ENUM(NSInteger, HMSegmentedImagePosition) {
    HMSegmentedImagePositionBehindText,
    HMSegmentedImagePositionLeftOfText,
    HMSegmentedImagePositionRightOfText,
    HMSegmentedImagePositionAboveText,
    HMSegmentedImagePositionBelowText
};

@interface HMSegmented : UIControl

@property (nonatomic, strong) NSArray<NSString *> *sectionTitles;
@property (nonatomic, strong) NSArray<UIImage *> *sectionImages;
@property (nonatomic, strong) NSArray<UIImage *> *sectionSelectedImages;

/**
 Provide a block to be executed when selected index is changed.
 
 Alternativly, you could use `addTarget:action:forControlEvents:`
 */
@property (nonatomic, copy) IndexChangeBlock indexChangeBlock;

/**
 Used to apply custom text styling to titles when set.
 
 When this block is set, no additional styling is applied to the `NSAttributedString` object returned from this block.
 */
@property (nonatomic, copy) HMTitleFormatterBlock titleFormatter;

/**
 Text attributes to apply to item title text.
 */
@property (nonatomic, strong) NSDictionary *titleTextAttributes UI_APPEARANCE_SELECTOR;

/*
 Text attributes to apply to selected item title text.
 
 Attributes not set in this dictionary are inherited from `titleTextAttributes`.
 */
@property (nonatomic, strong) NSDictionary *selectedTitleTextAttributes UI_APPEARANCE_SELECTOR;

/**
 Segmented control background color.
 
 Default is `[UIColor whiteColor]`
 */
@property (nonatomic, strong) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;

/**
 Color for the selection indicator stripe
 
 Default is `R:52, G:181, B:229`
 */
@property (nonatomic, strong) UIColor *selectionIndicatorColor UI_APPEARANCE_SELECTOR;

/**
 Color for the selection indicator box
 
 Default is selectionIndicatorColor
 */
@property (nonatomic, strong) UIColor *selectionIndicatorBoxColor UI_APPEARANCE_SELECTOR;

/**
 Color for the vertical divider between segments.
 
 Default is `[UIColor blackColor]`
 */
@property (nonatomic, strong) UIColor *verticalDividerColor UI_APPEARANCE_SELECTOR;

/**
 Opacity for the seletion indicator box.
 
 Default is `0.2f`
 */
@property (nonatomic) CGFloat selectionIndicatorBoxOpacity;

/**
 Width the vertical divider between segments that is added when `verticalDividerEnabled` is set to YES.
 
 Default is `1.0f`
 */
@property (nonatomic, assign) CGFloat verticalDividerWidth;

/**
 Specifies the style of the control
 
 Default is `HMSegmentedTypeText`
 */
@property (nonatomic, assign) HMSegmentedType type;

/**
 Specifies the style of the selection indicator.
 
 Default is `HMSegmentedSelectionStyleTextWidthStripe`
 */
@property (nonatomic, assign) HMSegmentedSelectionStyle selectionStyle;

/**
 Specifies the style of the segment's width.
 
 Default is `HMSegmentedSegmentWidthStyleFixed`
 */
@property (nonatomic, assign) HMSegmentedSegmentWidthStyle segmentWidthStyle;

/**
 Specifies the location of the selection indicator.
 
 Default is `HMSegmentedSelectionIndicatorLocationUp`
 */
@property (nonatomic, assign) HMSegmentedSelectionIndicatorLocation selectionIndicatorLocation;

/*
 Specifies the border type.
 
 Default is `HMSegmentedBorderTypeNone`
 */
@property (nonatomic, assign) HMSegmentedBorderType borderType;

/**
 Specifies the image position relative to the text. Only applicable for HMSegmentedTypeTextImages
 
 Default is `HMSegmentedImagePositionBehindText`
 */
@property (nonatomic) HMSegmentedImagePosition imagePosition;

/**
 Specifies the distance between the text and the image. Only applicable for HMSegmentedTypeTextImages
 
 Default is `0,0`
 */
@property (nonatomic) CGFloat textImageSpacing;

/**
 Specifies the border color.
 
 Default is `[UIColor blackColor]`
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 Specifies the border width.
 
 Default is `1.0f`
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 Default is YES. Set to NO to deny scrolling by dragging the scrollView by the user.
 */
@property(nonatomic, getter = isUserDraggable) BOOL userDraggable;

/**
 Default is YES. Set to NO to deny any touch events by the user.
 */
@property(nonatomic, getter = isTouchEnabled) BOOL touchEnabled;

/**
 Default is NO. Set to YES to show a vertical divider between the segments.
 */
@property(nonatomic, getter = isVerticalDividerEnabled) BOOL verticalDividerEnabled;

@property (nonatomic, getter=shouldStretchSegmentsToScreenSize) BOOL stretchSegmentsToScreenSize;

/**
 Index of the currently selected segment.
 */
@property (nonatomic, assign) NSInteger selectedSegmentIndex;

/**
 Height of the selection indicator. Only effective when `HMSegmentedSelectionStyle` is either `HMSegmentedSelectionStyleTextWidthStripe` or `HMSegmentedSelectionStyleFullWidthStripe`.
 
 Default is 5.0
 */
@property (nonatomic, readwrite) CGFloat selectionIndicatorHeight;

/**
 Edge insets for the selection indicator.
 NOTE: This does not affect the bounding box of HMSegmentedSelectionStyleBox
 
 When HMSegmentedSelectionIndicatorLocationUp is selected, bottom edge insets are not used
 
 When HMSegmentedSelectionIndicatorLocationDown is selected, top edge insets are not used
 
 Defaults are top: 0.0f
 left: 0.0f
 bottom: 0.0f
 right: 0.0f
 */
@property (nonatomic, readwrite) UIEdgeInsets selectionIndicatorEdgeInsets;

/**
 Inset left and right edges of segments.
 
 Default is UIEdgeInsetsMake(0, 5, 0, 5)
 */
@property (nonatomic, readwrite) UIEdgeInsets segmentEdgeInset;

@property (nonatomic, readwrite) UIEdgeInsets enlargeEdgeInset;

/**
 Default is YES. Set to NO to disable animation during user selection.
 */
@property (nonatomic) BOOL shouldAnimateUserSelection;

- (id)initWithSectionTitles:(NSArray<NSString *> *)sectiontitles;
- (id)initWithSectionImages:(NSArray<UIImage *> *)sectionImages sectionSelectedImages:(NSArray<UIImage *> *)sectionSelectedImages;
- (instancetype)initWithSectionImages:(NSArray<UIImage *> *)sectionImages sectionSelectedImages:(NSArray<UIImage *> *)sectionSelectedImages titlesForSections:(NSArray<NSString *> *)sectiontitles;
- (void)setSelectedSegmentIndex:(NSUInteger)index animated:(BOOL)animated;
- (void)setIndexChangeBlock:(IndexChangeBlock)indexChangeBlock;
- (void)setTitleFormatter:(HMTitleFormatterBlock)titleFormatter;

@end
