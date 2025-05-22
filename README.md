# 2D Ray Tracer with SDL3

A minimalist real-time 2D ray-tracer written in C++ and SDL3.  
Cast hundreds of rays from a movable “emissive” light-source circle, and watch them  
• **Absorb** on dark “absorptive” obstacles  
• **Bounce** off shiny “reflective” obstacles  

---

## Features

- **Interactive light source**: Move your mouse to reposition the emitter.  
- **Absorptive circles**: Rays end when they hit these.  
- **Reflective circles**: Rays mirror off at perfect angles, up to N bounces.  
- **Scan-line filled circles**: Fast, easy circle-drawing via horizontal spans.  

---

## Showcases

- One Absorbtive and One Reflective Circle

- Two Reflective Circles

- Two Absorptive Circles

---

## Source for the Formula Used In Reflection

- https://www.gamedeveloper.com/programming/pool-hall-lessons-fast-accurate-collision-detection-between-circles-or-spheres
