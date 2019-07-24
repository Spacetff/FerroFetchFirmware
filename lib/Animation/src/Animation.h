/*
  Animation.h - library for storing Animations for Fetch
  Copyright (c) 20019 Simen E. Sørensen. 
*/

// ensure this library description is only included once
#ifndef Animation_h
#define Animation_h

#include <Arduino.h>

class Frame
{
public:
                Frame(int cols, int rows, uint8_t **duty_cycle = nullptr, uint32_t *picture = nullptr);
    void        delete_frame(void);
    uint32_t*   get_picture();
    uint32_t    get_picture_at(int x);
    uint8_t**   get_duty_cycle();
    uint8_t     get_duty_cycle_at(int x, int y);
    inline void write_picture(uint32_t *picture);
    inline void write_pixel(int x, int y, bool state);
    inline void set_pixel(int x, int y);
    inline void clear_pixel(int x, int y);

private:
    int         _cols;
    int         _rows;

    uint8_t**   _duty_cycle;
    uint32_t*   _picture;

    inline void _delete_picture();
    inline void _delete_duty_cycle();
};

class Animation
{
public:
            Animation(int num_frames, int cols, int rows, Frame **frames = nullptr);
    void    delete_anim(void);
    Frame*  get_frame(int frame_num);
    void    set_frame(int frame_num, Frame* frame);
    void    goto_next_frame();
    Frame*  get_current_frame();
    Frame*  get_next_frame();
    Frame*  get_prev_frame();
private:
    int     _cols;
    int     _rows;
    int     _num_frames; 
    int     _current_frame = 0;

    Frame **_frames;
    int     _get_next_frame_idx();
    int     _get_prev_frame_idx();
};

#endif