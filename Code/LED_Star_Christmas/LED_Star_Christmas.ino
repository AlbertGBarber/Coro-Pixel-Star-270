//By Albert Barber
//last updated Dec 2020
#include <PixelStrip.h>
#define PIN 4 //4
#define LIGHTSENPIN A0

const uint16_t stripLength = 270; //61
const uint8_t stripType = NEO_RGB + NEO_KHZ800;
PixelStrip strip = PixelStrip(stripLength, PIN, stripType); //12 NEO_GRB

//Define some colors we'll use frequently
RGB white = { 255, 255, 255, strip.Color(255, 255, 255) };
RGB UCLAGold = { 254, 187, 54, strip.Color(254, 187, 54) };
RGB UCLABlue = { 83, 104, 149, strip.Color(83, 104, 149) };
RGB off = { 0, 0, 0, 0 };
RGB red = { 255, 0, 0, strip.Color(255, 0, 0) };
RGB orange = { 255, 43, 0, strip.Color(255, 43, 0) };
RGB ltOrange = { 255, 143, 0, strip.Color(255, 143, 0) };
RGB yellow = { 255, 255, 0, strip.Color(255, 255, 0) };
RGB green = { 0, 128, 0, strip.Color(0, 128, 0) };
RGB blue = { 0, 0, 255, strip.Color(0, 0, 255) };
RGB indigo = { 75, 0, 130, strip.Color( 75, 0, 130) };
RGB violet = { 238, 130, 238, strip.Color(238, 130, 238) };
RGB purple = {123, 7, 197, strip.Color(123, 7, 197) };
RGB pink = {225, 0, 127, strip.Color(225, 0, 127) };

//define pallet array, contains 32bit representations of all colors used in patterns
uint32_t pallet[9] = { off.color32, white.color32, UCLAGold.color32, UCLABlue.color32, blue.color32, yellow.color32, red.color32, green.color32, purple.color32 };
//                   {------0-----, ------1-----, ---------2-------, ---------3-------, -----4-----, -------5------, -----6-----, ------7------ -------8--------}

uint32_t firePallet[3] = { red.color32, ltOrange.color32, white.color32 };

uint32_t christmasPallet1[5] = { red.color32, blue.color32, green.color32, yellow.color32, purple.color32 };


//uint32_t firePallet[3] = { red.color32, ltOrange.color32, white.color32 };
//uint32_t firePalletGreen[3] = { blue.color32, green.color32, white.color32 };

//some notes on the BG pallet:
//when setting a pallet for the Bg, call setBgPallet(newPallet, SIZE(newPallet)) to set it
//with the RGB pallet you want. You must do this each time you change the background pallet
//this will also set bgPalletStripSize which is the length of the current pallet
RGB BgPallet[0];

//for pattern sweep function
//for simple repeart drawing functions
//using christmas pallet
byte simpleRepeatPattern[5] = {8, 6, 7, 4, 5};

const PROGMEM segmentSection ringSec0[] = {{0, 70}}; //outer ring 0, 70 pixels
Segment ringSegment0 = { SIZE(ringSec0), ringSec0, true }; //numSections, section array pointer

const PROGMEM segmentSection ringSec1[] = {{70, 60}}; //outer ring 1, 60 pixels
Segment ringSegment1 = { SIZE(ringSec1), ringSec1, true }; //numSections, section array pointer

const PROGMEM segmentSection ringSec2[] = {{130, 50}}; //outer ring 2, 50 pixels
Segment ringSegment2 = { SIZE(ringSec2), ringSec2, true }; //numSections, section array pointer

const PROGMEM segmentSection ringSec3[] = {{180, 40}}; //outer ring 3, 40 pixels
Segment ringSegment3 = { SIZE(ringSec3), ringSec3, true }; //numSections, section array pointer

const PROGMEM segmentSection ringSec4[] = {{220, 30}}; //outer ring 4, 30 pixels
Segment ringSegment4 = { SIZE(ringSec4), ringSec4, true }; //numSections, section array pointer

const PROGMEM segmentSection ringSec5[] = {{250, 20}}; //outer ring 5, 20 pixels
Segment ringSegment5 = { SIZE(ringSec5), ringSec5, true }; //numSections, section array pointer

Segment *rings_arr[] = { &ringSegment0 , &ringSegment1, &ringSegment2, &ringSegment3, &ringSegment4, &ringSegment5 };
SegmentSet ringSegments = { SIZE(rings_arr), rings_arr };
//====================================================================================================

const PROGMEM segmentSection pointSec0[] = { {0, 7}, {64, 12}, {125, 10}, {176, 8}, {217, 6}, {248, 4}, {269, 1} }; //outer ring 0, 70 pixels
Segment pointSegment0 = { SIZE(pointSec0), pointSec0, true }; //numSections, section array pointer

const PROGMEM segmentSection pointSec1[] = { {8, 13}, {77, 11}, {136, 9}, {185, 7}, {224, 5}, {253, 3} };
Segment pointSegment1 = { SIZE(pointSec1), pointSec1, true }; //numSections, section array pointer

const PROGMEM segmentSection pointSec2[] = { {22, 13}, {89, 11}, {146, 9}, {193, 7}, {230, 5}, {257, 3} };
Segment pointSegment2 = { SIZE(pointSec2), pointSec2, true }; //numSections, section array pointer

const PROGMEM segmentSection pointSec3[] = { {36, 13}, {101, 11}, {156, 9}, {201, 7}, {236, 5}, {261, 3} };
Segment pointSegment3 = { SIZE(pointSec3), pointSec3, true }; //numSections, section array pointer

const PROGMEM segmentSection pointSec4[] = { {50, 13}, {113, 11}, {166, 9}, {209, 7}, {242, 5}, {265, 3} };
Segment pointSegment4 = { SIZE(pointSec4), pointSec4, true }; //numSections, section array pointer

Segment *points_arr[] = { &pointSegment0 , &pointSegment1, &pointSegment2, &pointSegment3, &pointSegment4 };
SegmentSet pointSegments = { SIZE(points_arr), points_arr };
//================================================================================================

const PROGMEM segmentSection halvesSec0[] = { {0, 36} }; //outer ring 0, 70 pixels
Segment halvesSegment0 = { SIZE(halvesSec0), halvesSec0, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec1[] = { {36, 36} }; //outer ring 0, 70 pixels
Segment halvesSegment1 = { SIZE(halvesSec1), halvesSec1, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec2[] = { {70, 31} }; //outer ring 1, 60 pixels
Segment halvesSegment2 = { SIZE(halvesSec2), halvesSec2, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec3[] = { {100, 31} }; //outer ring 1, 60 pixels
Segment halvesSegment3 = { SIZE(halvesSec3), halvesSec3, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec4[] = { {130, 26} }; //outer ring 2, 50 pixels
Segment halvesSegment4 = { SIZE(halvesSec4), halvesSec4, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec5[] = { {155, 26} }; //outer ring 2, 50 pixels
Segment halvesSegment5 = { SIZE(halvesSec5), halvesSec5, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec6[] = { {180, 21} }; //outer ring 3, 40 pixels
Segment halvesSegment6 = { SIZE(halvesSec6), halvesSec6, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec7[] = { {200, 21} }; //outer ring 3, 40 pixels
Segment halvesSegment7 = { SIZE(halvesSec7), halvesSec7, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec8[] = { {220, 16} }; //outer ring 4, 30 pixels
Segment halvesSegment8 = { SIZE(halvesSec8), halvesSec8, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec9[] = { {235, 16} }; //outer ring 4, 30 pixels
Segment halvesSegment9 = { SIZE(halvesSec9), halvesSec9, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec10[] = { {250, 11} }; //outer ring 5, 20 pixels
Segment halvesSegment10 = { SIZE(halvesSec10), halvesSec10, true }; //numSections, section array pointer

const PROGMEM segmentSection halvesSec11[] = { {260, 11} }; //outer ring 5, 20 pixels
Segment halvesSegment11 = { SIZE(halvesSec11), halvesSec11, true }; //numSections, section array pointer

Segment *halves_arr[] = { &halvesSegment0, &halvesSegment1, &halvesSegment2, &halvesSegment3, &halvesSegment4, &halvesSegment5, &halvesSegment6, &halvesSegment7, &halvesSegment8, &halvesSegment9, &halvesSegment10, &halvesSegment11 };
SegmentSet halvesSegments = { SIZE(halves_arr), halves_arr };

//================================================================================================

byte wavepattern[2]  = { 6, 1 };
byte wavepattern2[2] = { 5, 4 };
byte wavepattern3[2] = { 6, 7 };
byte wavepattern4[2] = { 8, 7 };
byte christmasWavePattern[4] = { 0, 1, 2, 3 };

byte christmasStreamerPatternColors[5] = { 5, 6, 7, 4, 8 };

//sample spin pattern for use with the colorSpin function
//arranged as a single array, which is split into sub-sections
//each section has the following pattern;
//{section start point, section end point, pallet index for zeroth segment, '' '' '' first segment, ..... '' '' '' last segment}
//you must fill in a pallet index for all segments!
//if you simply want to sweep solid colors, you can call :
//be sure to set the array's length correctly, you can use an equation like below
//spin patterns will probably only work for a specific segment set, so make sure you are careful when calling the functions
byte americaSpinPattern[(6 + 2) * 5] = { //0,1 5,6 8,9
  0, 5, 4, 1, 4, 1, 4, 1,
  5, 9, 1, 4, 1, 4, 1, 4,
  9, 13, 4, 1, 4, 1, 4, 1,
  13, 17, 1, 4, 1, 4, 1, 4,
  17, 69, 6, 1, 6, 1, 6, 1,
};

byte unionJackSpinPattern[(6 + 2) * 6] = {
  0, 6, 6, 6, 6, 6, 6, 6,
  6, 9, 4, 4, 4, 4, 4, 6,
  9, 11, 1, 1, 1, 1, 1, 6,
  11, 13, 6, 6, 6, 6, 6, 6,
  13, 15, 1, 1, 1, 1, 1, 6,
  15, 18, 4, 4, 4, 4, 4, 6,
};


byte sparkleSpinPattern[(6 + 2) * 4] = {
  0, 1, 2, 2, 0, 0, 0, 0,
  1, 6, 0, 0, 0, 0, 0, 0,
  6, 9, 1, 1, 1, 1, 1, 1,
  9, 14, 0, 0, 0, 0, 0, 0,
};

//some notes on running simple spin patterns
//if you want to repeat the pattern across the strip,
//you should try to make it fit evenly into the longest segment
//a formula for the space a pattern takes up is
//(sweepLength + sweepSpacing) * patternLength
byte spinSimplePattern[5] = {8, 6, 7, 4, 5};
byte simpleRepeatPattern2[] = {8, 8, 8, 0, 0, 6, 6, 6, 0, 0, 7, 7, 7, 0, 0, 4, 4, 4, 0, 0, 5, 5, 5, 0, 0};

//byte radialColorWipePat[7] = {6, 6, 6, 6, 1, 1, 1};


int minLight = 150; //300
boolean lightSensorDisable = false;
int lightLevel;

byte normalBrightness = 100;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(normalBrightness);

  strip.show();
  //Serial.begin(9600);
  randomSeed(analogRead(2));

}

void loop() {
  boolean direct = true;
  delay(500); //let the light sensor settle
  lightLevel = analogRead(LIGHTSENPIN);
  if (lightLevel <= minLight || lightSensorDisable) {

    //  for (int i = 0; i < 5; i++) {
    //    strip.singleWave( pointSegments, RC(), off.color32, 1, pointSegments.numSegs, false, 10, 20);
    //  }

    //strip.shooterSeg( halvesSegments, christmasPallet1, SIZE(christmasPallet1), 0, 2, 4, 0, 0, 1, true, true, 60, 350);

    strip.colorSpinRainbow(ringSegments, direct, 50, 250);

    //strip.segGradientCycleSweep(ringSegments, spinSimplePattern, SIZE( spinSimplePattern), pallet, SIZE(pallet), 14, 100, true, 50);

    //strip.segGradientCycleRand(pointSegments, 14, 5, 150, true, 2, 50);

    strip.randomColorSet(off.color32, true, christmasPallet1, SIZE(christmasPallet1), 100, 8, 15000);

    strip.colorSpin( ringSegments, americaSpinPattern, SIZE(americaSpinPattern), pallet, red.color32, 1, false, 300, 60 );

    strip.colorSpin( ringSegments, unionJackSpinPattern, SIZE(unionJackSpinPattern), pallet, 1, 1, true, 300, 60 );

    strip.patternSweepRand( 2, -1, 0, 1, 25, true, 1, 2, 40, 270 * 2 ); //long rainbow
    //strip.patternSweepRand( 5, 0, RC(), 0, 0, false, 10, 1, 40, 320 ); //bgColor, 10 eyeSize streamers
    // strip.patternSweepRand( 18, 0, RC(), 0, 0, false, 0, 1, 50, 320 ); //bgColor, single pixels

    //strip.colorWipePalletSeg(ringSegments, SIZE(ringSegments), 1, false, radialColorWipePat, SIZE(radialColorWipePat), pallet, -2, 3000, true, false);
    //delay(2000);
    //strip.colorWipeSeg(ringSegments, SIZE(ringSegments), 0, -2, 3000, false, false, false);

    strip.stripOff();
    for (int i = 0; i < 3; i++) {
      if ((i % 2) == 0 ) {
        strip.colorWipeRandomSeg( ringSegments, 1, 5, -1, 30, true, true, false);
        strip.colorWipeSeg(ringSegments, 0, -1, 30, false, false, false);
      } else {
        strip.colorWipeRandomSeg( ringSegments, 1, 5, -1, 30, true, true, true);
        strip.colorWipeSeg(ringSegments, 0, -1, 30, true, false, true);
      }
    }

    direct = true;
    for (int i = 0; i < 4; i++) {
      strip.segGradientCycleRand(ringSegments, 7, 5, 150, direct, 2, 50);
      direct = !direct;
    }

    //strip.colorWipeRandomSeg( ringSegments, SIZE(ringSegments), 1, 5, 14, 200, true, true, false);
    //strip.colorWipeSeg(ringSegments, SIZE(ringSegments), 0, 8, 2000, true, true, true);
    strip.stripOff();
    halvesSegments.flipSegDirectionEvery(2, false);
    for (int i = 0; i < 4; i++) {
      if ((i % 2) == 0 ) {
        strip.colorWipeRainbowSeg( halvesSegments, 80, 0, true, false, true, true);
        strip.colorWipeSeg(halvesSegments, 0, 0, 80, true, false, true);
      } else {
        strip.colorWipeRainbowSeg( halvesSegments, 80, 0, false, false, false, true);
        strip.colorWipeSeg(halvesSegments, 0, 0, 80, false, true, true);
      }
    }
    halvesSegments.flipSegDirectionEvery(2, false);

    strip.colorSpinSimpleSet( ringSegments, wavepattern, SIZE(wavepattern), pallet, off.color32, 5, -1, 4, 1, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern, SIZE(wavepattern), pallet, off.color32, 18, -1, 0, 0, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern2, SIZE(wavepattern2), pallet, off.color32, 5, -1, 4, 1, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern2, SIZE(wavepattern2), pallet, off.color32, 18, -1, 0, 0, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern3, SIZE(wavepattern3), pallet, off.color32, 5, -1, 4, 1, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern3, SIZE(wavepattern3), pallet, off.color32, 18, -1, 0, 0, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern4, SIZE(wavepattern4), pallet, off.color32, 5, -1, 4, 1, 1, 24 * 5, 60 );
    strip.colorSpinSimpleSet( ringSegments, wavepattern4, SIZE(wavepattern4), pallet, off.color32, 18, -1, 0, 0, 1, 24 * 5, 60 );

    strip.colorSpinSimpleSet( ringSegments, simpleRepeatPattern, SIZE(simpleRepeatPattern), pallet, off.color32, 5, -1, 4, 1, 1, 24 * 5, 60 );

    strip.colorSpinSimpleSet( ringSegments, simpleRepeatPattern, SIZE(simpleRepeatPattern), pallet, off.color32, 14, -1, 0, 0, 1, 24 * 5, 60 );

    for (int i = 0; i < 3; i++) {
      strip.patternSweepRand( 8, -1, 0, 1, 6, false, 0, 1, 50, 290 ); //8 random colors, trail length 6
    }

    strip.colorSpinSimple( ringSegments, 1, white.color32, -1, 3, -1, 7, 0, 1, 270 * 2, 60 ); //white on rainbow Bg

    //  RGB newPallet2[2] = {blue, red};
    //  strip.setBgPallet(newPallet2, SIZE(newPallet2));
    strip.stripOff();
    for (int i = 0; i < 4; i++) {
      if ((i % 2) == 0 ) {
        strip.colorWipeRainbowSeg( halvesSegments, 80, 0, true, true, true, true);
        strip.colorWipeSeg(halvesSegments, 0, 0, 80, true, true, true);
      } else {
        strip.colorWipeRainbowSeg( halvesSegments, 80, 0, false, false, true, true);
        strip.colorWipeSeg(halvesSegments, 0, 0, 80, false, true, true);
      }
    }

    strip.stripOff();
    strip.colorSpinSimple( pointSegments, 1, 0, 0, 12, 1, 0, 0, 2, 350, 40 ); //rainbow
    strip.colorSpinSimple( pointSegments, 3, 0, 0, 10, -1, 6, 0, 1, 350, 40 );
    strip.colorSpinSimple( pointSegments, 3, 0, 0, 10, -1, 6, 0, 1, 350, 40 );
    //strip.colorSpinSimple( pointSegments, pointSegmentsNum, 3, 0, 0, 1, -1, 7, 0, 1, 300, 80 );

    strip.stripOff();
    for (int i = 0; i < 3; i++) {
      strip.colorWipeRandomSeg( ringSegments, 3, 6, 70, 50, false, true, false);
      strip.colorWipeSeg(ringSegments, 0, 70, 50, true, true, true);
    }

    direct = true;
    for (int i = 0; i < 10; i++) {
      strip.singleWave( ringSegments, RC(), off.color32, 1, ringSegments.numSegs - 1, direct, 10, 20);
      direct = !direct;
    }
    //strip.waves( ringSegments, SIZE(ringSegments),  pallet, SIZE(pallet), christmasStreamerPatternColors, SIZE(christmasStreamerPatternColors), 30, true, 20, 20);

    strip.segGradientCycle(ringSegments, wavepattern, SIZE(wavepattern),  pallet, SIZE(pallet), 8, 50, true, 100);
    strip.segGradientCycle(ringSegments, wavepattern2, SIZE(wavepattern2),  pallet, SIZE(pallet), 8, 50, true, 100);
    strip.segGradientCycle(ringSegments, wavepattern3, SIZE(wavepattern3),  pallet, SIZE(pallet), 8, 50, true, 100);
    strip.segGradientCycle(ringSegments, wavepattern4, SIZE(wavepattern4),  pallet, SIZE(pallet), 8, 50, true, 100);

    strip.segGradientCycle(ringSegments, christmasStreamerPatternColors, SIZE(christmasStreamerPatternColors),  pallet, SIZE(pallet), 5, 130, true, 100);

    //strip.waves( ringSegments, SIZE(ringSegments),  pallet, SIZE(pallet), wavepattern, SIZE(wavepattern), 20, true, 20, 20);
    //strip.waves( ringSegments, SIZE(ringSegments),  pallet, SIZE(pallet), wavepattern2, SIZE(wavepattern2), 20, true, 20, 20);
    //strip.waves( ringSegments, SIZE(ringSegments),  pallet, SIZE(pallet), wavepattern3, SIZE(wavepattern3), 20, true, 20, 20);
    //strip.waves( ringSegments, SIZE(ringSegments),  pallet, SIZE(pallet), wavepattern4, SIZE(wavepattern4), 20, true, 20, 20);

    strip.colorSpinSimple( ringSegments, 1, 0, 0, 35, 1, 0, 0, 2, 270 * 2, 40 ); //rainbow half

    strip.stripOff();
    halvesSegments.flipSegDirectionEvery(2, false);
    strip.colorSpinSimple( halvesSegments, 1, 0, 0, 17, 1, 0, 0, 2, 270 * 2, 40 ); //rainbow half flipped
    halvesSegments.flipSegDirectionEvery(2, false);

    strip.stripOff();
    strip.colorWipeRandomSeg( pointSegments, 1, 5, -1, 20, true, false, false);
    delay(1500);
    strip.colorWipeSeg(ringSegments, 0, -2, 3000, false, false, false);
    strip.colorWipeRandomSeg( pointSegments, 1, 5, -1, 20, false, false, false);
    delay(1500);
    strip.colorWipeSeg(ringSegments, 0, -2, 3000, false, false, false);

    direct = true;
    strip.stripOff();
    for (int i = 0; i < 3; i++) {
      strip.randomWaves(pointSegments, byte(pointSegments.numSegs) , 1, 0 , 50, direct, 20, 15);
      direct = !direct;
    }
    strip.waves( pointSegments, pallet, SIZE(pallet), christmasStreamerPatternColors, SIZE(christmasStreamerPatternColors), 20, false, 20, 20);

    for (int i = 0; i < 4; i++) {
      strip.gradientCycleRand( 5, 11, 300, direct, 50);
      direct = !direct;
    }

    strip.patternSweepRand( 10, white.color32, -1, 0, 0, false, 0, 1, 60, 250 ); //rainbow BG, white pixels

    strip.sparkSeg( ringSegments, 5, 1, 3, 0, 1, 0, 1, true, false, 150, 60 ); //three random colors, moving inwards
    strip.sparkSeg( ringSegments, 5, 1, 3, 0, 1, 0, 1, true, false, 150, 60 ); //three random colors, moving inwards
    strip.sparkSeg( ringSegments, 5, 1, 3, 0, 1, 0, 1, true, false, 150, 60 ); //three random colors, moving inwards
    strip.sparkSeg( ringSegments, 15, 1, 1, 0, 2, 0, 1, true, false, 150, 60 ); //segmented rainbow sparks, blank Bg
    strip.sparkSeg( ringSegments, 20, 1, 1, white.color32, 1, 0, 5, false, true, 300, 60 ); //radial rainbow Bg, white sparks

    strip.colorSpinSimple( ringSegments, 1, 0, 0, 5, -1, 5, 0, 2, 270 * 2, 40 ); //rainbow slims

    /////
    //  direct = true;
    //  for (int i = 0; i < 4; i++) {
    //    strip.segGradientCycleRand(ringSegments, 2, 3, 150, direct, 1, 100);
    //    direct = !direct;
    //  }
    //  strip.segGradientCycleRand(ringSegments, 6, 3, 150, true, 1, 100);

    direct = true;
    strip.stripOff();
    halvesSegments.flipSegDirectionEvery(2, false);
    for (int i = 0; i < 5; i++) {
      strip.segGradientCycleRand(halvesSegments, 7, 5, 150, direct, 2, 50);
      direct = !direct;
    }
    halvesSegments.flipSegDirectionEvery(2, false);

    strip.stripOff();
    for (int i = 0; i < 8; i++) {
      if ((i % 2) == 0 ) {
        strip.colorWipeRainbowSeg( ringSegments, 270, 8, true, true, false, false);
        delay(500);
        strip.colorWipeSeg(ringSegments, 0, 8, 5000, true, false, true);
      } else {
        strip.colorWipeRainbowSeg( ringSegments, 270, 8, false, true, false, false);
        delay(500);
        strip.colorWipeSeg(ringSegments, 0, 8, 5000, false, false, true);
      }
    }

    uint32_t palletRand[3];
    for (int i = 0; i < 4; i++) {
      strip.genRandPallet(palletRand, 3);
      palletRand[0] = 0;
      strip.colorSpin( ringSegments, sparkleSpinPattern, SIZE(sparkleSpinPattern), palletRand, 0, 1, true, 260, 60);
    }
    strip.stripOff();


    //strip.colorSpinSimple( ringSegments,  SIZE(ringSegments), 3, 0, 0, 4, -1, 4, 0, 1, 24*5, 40 );
    //strip.colorSpinSimpleSet( ringSegments,  SIZE(ringSegments), simpleRepeatPattern, SIZE(simpleRepeatPattern), pallet, off.color32, 5, -1, 4, 1, 1, 24*5, 60 );
    //strip.colorSpinSimpleSet( ringSegments,  SIZE(ringSegments), simpleRepeatPattern, SIZE(simpleRepeatPattern), pallet, off.color32, 7, -1, 7, 0, 1, 24*5, 60 );//thin rainbow strips
    //strip.colorSpinSimpleSet( ringSegments,  SIZE(ringSegments), simpleRepeatPattern, SIZE(simpleRepeatPattern), pallet, off.color32, 14, -1, 0, 0, 1, 24*5, 60 );
    //strip.colorSpinSimple( ringSegments,  SIZE(ringSegments), 1, 0, 0, 18, 1, 0, 0, 3, 24*5, 60 ); //seg gradient
    //strip.colorSpinSimple( ringSegments,  SIZE(ringSegments), 1, 0, 0, 18, 1, 0, 0, 4, 24*5, 60 ); //bg gradient
    //strip.colorSpinSimple( ringSegments,  SIZE(ringSegments), 5, 0, 0, 7, -1, 7, 0, 1, 24*5, 40 ); //5 rand colors
    // strip.colorSpinSimple( ringSegments,  SIZE(ringSegments), 2, 0, 0, 3, -1, 32, 0, 1, 24*5, 40 );
    //strip.colorSpinSimple( ringSegments,  SIZE(ringSegments), 3, 0, 0, 2, -1, 2, 0, 1, 24*5, 60 );

    //strip.shiftGradient(200, 50);


    //    strip.rainbowWave( ringSegments, SIZE(ringSegments), 0, 0, 0, 20, true, 30, 20);
    //    strip.rainbowSingleWave( ringSegments, SIZE(ringSegments), waveOmissions, SIZE(waveOmissions), -1, 1, 10, 2, 5, 15);
    //strip.randomColors(-1, false, white.color32, 70, 5, 10000);
    //strip.randomColors(RC(), false, RC(), 70, 8, 10000);
    //strip.randomColors(-2, false, 0, 70, 8, 10000);
    //strip.randomColors(off.color32, true, -1, 70, 5, 10000);

    //    strip.stripOff();
    //    strip.colorWipe(red.color32, stripLength/2, 300, true, true, true);
    //    strip.colorWipe(off.color32, stripLength/2, 300, false, true, true);
    //    strip.colorWipeRainbow(20, stripLength, true, false, false, true);
    //    strip.colorWipe(off.color32, stripLength, 20, false, false, true);
    //    strip.colorWipeRainbow(400, 10, true, false, true, true);
    //    strip.colorWipe(off.color32, 10, 400, false, true, true);
    //    for(int i = 0; i < 3; i++){
    //      strip.stripOff();
    //      strip.colorWipeRandom(1, 1, 4, 300, true, true, false);
    //      strip.stripOff();
    //      strip.colorWipeRandom(1, 3, 4, 300, true, true, false);
    //      strip.stripOff();
    //      strip.colorWipeRandom(2, 3, 5, 300, true, true, false);
    //    }
    //
    //  strip.twinkle(0, -1, 0, 150, 10, 10000);
    //  strip.twinkle(-1, white.color32, 1, 100, 10, 10000);
    //  strip.twinkle(0, -1, 2, 80, 10, 10000);
    //
    //    //strip.theaterChaseRainbow(off.color32, 50, 4, 2);
    //  //
    //
    //    for (int j = 0; j < 256; j++) {
    //      strip.randomColors(off.color32, true, strip.Wheel(j & 255), 30, 16, 110);
    //    }
    //
  }
}

//a quick shortening of the random color function, just to reduce the pattern function calls more readable
uint32_t RC() {
  return strip.randColor();
}
