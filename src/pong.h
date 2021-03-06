/*
    Pong Header File
*/

#ifndef INCLUDED
#define INCLUDED

// Game Variables
bool game_start = false;
bool start_txt = true;
bool show_phrase = false;
int paddle_speed = 2;
int lives = 3;

clock_t reference_t, now_t, diff_t;
int tick_counter = 0;

// Ball Properties //
const int ball_radius = 7;
const int ball_sectors = 24;
const int court_margin = 80;

int ball_x = WIN_WIDTH / 2;
int ball_y = WIN_HEIGHT / 2;

int ball_speed = 3;
int ball_state[2] = {1, -1};

double b_color[4] = {
	1.0, 1.0, 1.0, 1.0};

int chain_track = 1;
const float chain[10][4] = {
    {1.0, 0.1, 0.0, 1.0}, // Red
    {1.0, 0.3, 0.0, 1.0}, // Red / Orange
    {1.0, 0.7, 0.0, 1.0}, // Orange / Yellow
    {0.9, 1.0, 0.0, 1.0}, // Yellow
    {0.5, 1.0, 0.0, 1.0}, // Green
    {0.0, 1.0, 0.7, 1.0}, // Cyan
    {0.0, 0.5, 1.0, 1.0}, // Cyan / Blue
    {0.0, 0.0, 1.0, 1.0}, // Blue
    {0.5, 0.0, 1.0, 1.0}, // Purple
    {0.9, 0.0, 0.8, 1.0}  // Purple / Red
};

// Paddle Properties //
const int y_margin = 85;
const int pad_w = 15;
const int pad_h = 60;

// Player Paddle //
float right_x = WIN_WIDTH - WIN_WIDTH / 20;
float right_y = WIN_HEIGHT / 2;
int right_paddle[4][2];
int right_catches = 0;

// AI Paddle //
float left_x = WIN_WIDTH / 20;
float left_y = WIN_HEIGHT / 2;
int left_paddle[4][2];
int left_catches = 0;

// Update Paddles //
void paddle_update(int pad[4][2], float *x, float *y);

// Feedback Phrases //
bool new_phrase = true;
double phrase_fade = 1.00;

char phrase1[11] = "Nice Catch!";
char phrase2[11] = "Close Miss!";
char phrase3[11] = "Quick Save!";

const char* phrases[] = {
    phrase1, phrase2, phrase3
};

// Text Objects
S2D_Text *title;
S2D_Text *play;
S2D_Text *fun_tag;
S2D_Text *fun_text;
S2D_Text *version_tag;
S2D_Text *lives_count;
S2D_Text *catch_counter;
S2D_Text *game_over;
S2D_Text *feedback;

// Debug Function
void debug(char input[]);

// Simple2D Functions
void render();
void update();
void input(S2D_Event event);

// Check Flags
void read_flags(int argc, char *argv[]);

// Key Actions
void key_actions(char key, int state);

#endif