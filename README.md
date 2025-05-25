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

## Preview

![1ofeach](https://github.com/user-attachments/assets/13d93e54-6bdc-4c3f-a358-7beb370c2f64)

---

## How to Run

- There is a release that you can download and run in the Releases section. Simply download **2D-Ray-Tracing-CPP.zip**, extract it, and run the **Ray-Tracing-in-CPP.exe** file.
- It is necessary that you the Ray-Tracing-in-CPP.exe file and SDL3.dll file to be in the same directory for the executable to run.

---

## Source for the Formula Used In Reflection

- https://www.gamedeveloper.com/programming/pool-hall-lessons-fast-accurate-collision-detection-between-circles-or-spheres
