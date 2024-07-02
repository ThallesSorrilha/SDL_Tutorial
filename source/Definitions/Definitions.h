#pragma once

inline constexpr int defaultBlockSize = 72;
inline constexpr int defaultSpriteUnit = 72;

inline constexpr int defaultWidthBlocks = 12;
inline constexpr int defaultHeightBlocks = 9;

inline constexpr int defaultFps = 60;
inline constexpr int defaultFrameDelay = 1000 / defaultFps;
inline constexpr float defaultFrameDelayinSeconds = defaultFrameDelay / 1000.0f;

inline constexpr int defaultGifFrameDelay = 250;
inline constexpr int defaultGifSteps = 4;

inline constexpr float defaultDynamicFrictionCoefficient = 2;
inline constexpr float gravity = 10;