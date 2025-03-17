# fract'ol

![Fractals](https://img.shields.io/badge/Fractals-Computer%20Graphics-4EAA25?logo=gnubash&logoColor=white)  

Welcome to **fract'ol**, a mesmerizing journey into the world of fractals! This project is a computer graphics exploration of fractal geometry, implemented in C using the **MiniLibX** library. Dive into the beauty of mathematical patterns and create stunning visualizations of fractals like the **Mandelbrot** and **Julia** sets.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Fractals](#fractals)
7. [Graphic Management](#graphic-management)
8. [Bonus Features](#bonus-features)

---

## Introduction

Fractals are fascinating mathematical objects that exhibit intricate patterns at every scale. The term "fractal" was coined by mathematician **Benoit Mandelbrot** in 1974, derived from the Latin word *fractus*, meaning "broken" or "fractured." These patterns are not only abstract mathematical constructs but also appear in nature, such as in the Romanesco cabbage.

This project, **fract'ol**, is your opportunity to explore the beauty of fractals through computer graphics. Using the **MiniLibX** library, you'll create a program that generates and visualizes fractals in real-time.

---

## Objectives

- **Learn the MiniLibX**: Get hands-on experience with the school's graphical library, which provides tools for window management, image creation, and event handling.
- **Explore Fractals**: Understand the mathematical concepts behind fractals, including complex numbers and iterative functions.
- **Optimize Graphics**: Dive into computer graphics optimization techniques to render fractals efficiently.
- **Event Handling**: Implement smooth user interactions, such as zooming and navigating through fractals.

---

## Features

- **Fractal Rendering**:
  - **Mandelbrot Set**: The classic fractal that reveals infinite complexity.
  - **Julia Set**: A customizable fractal that changes based on user-provided parameters.
- **Interactive Zoom**: Use the mouse wheel to zoom in and out infinitely, exploring the fractal's depth.
- **Dynamic Coloring**: Apply color gradients to highlight the fractal's intricate patterns.
- **Smooth Window Management**: Handle window events like resizing, minimizing, and closing gracefully.
- **User-Friendly Controls**:
  - **ESC**: Close the window and exit the program.
  - **Mouse Wheel**: Zoom in and out.
  - **Arrow Keys**: Move the view around the fractal (bonus feature).

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yasminefontenele/42_Fract-ol.git
   cd fractol
2. Compile the project using the provided `Makefile`:
   ```bash
   make
3. Run the program:
   ```bash
   ./fractol <fractal_type> [options]
   [Replace <fractal_type> with one of the available fractals (e.g., mandelbrot, julia)]

## Usage

### Basic Commands

- **Mandelbrot Set**:
  ```bash
  ./fractol mandelbrot
- **Julia Set** (with custom parameters)::
  ```bash
  ./fractol julia <real_part> <imaginary_part>

## Controls

- **Mouse Wheel**: Zoom in and out.
- **Arrow Keys**: Move the view (bonus feature).
- **ESC**: Exit the program.
- **Close Button**: Click the window's close button to exit.

---

## Fractals

### Mandelbrot Set
The Mandelbrot set is a set of complex numbers that, when iterated through a specific function, do not diverge to infinity. It is one of the most famous fractals, known for its intricate and infinitely detailed boundary.

### Julia Set
The Julia set is generated using a similar iterative process as the Mandelbrot set but with a fixed constant. By changing the constant, you can create an infinite variety of Julia sets, each with unique patterns.

---

## Graphic Management

- **Window Management**: The program maintains smooth window operations, including resizing and minimizing.
- **Event Handling**:
  - **ESC Key**: Closes the window and exits the program.
  - **Close Button**: Closes the window and exits the program.
- **Image Rendering**: Uses MiniLibX's image functions to render fractals efficiently.

---

## Bonus Features

- **Mouse-Based Zoom**: Zoom in and out centered on the mouse cursor.
- **View Movement**: Use arrow keys to move around the fractal.
- **Color Shifting**: Dynamically shift the color range for psychedelic effects.

