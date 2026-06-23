#pragma once

#include <QList>

struct controller_events {
	QList<int>* btn_west = nullptr;
	QList<int>* btn_east = nullptr;
	QList<int>* btn_south = nullptr;
	QList<int>* btn_north = nullptr;

	QList<int>* btn_dpad_up = nullptr;
	QList<int>* btn_dpad_right = nullptr;
	QList<int>* btn_dpad_down = nullptr;
	QList<int>* btn_dpad_left = nullptr;

	QList<int>* btn_start = nullptr;
	QList<int>* btn_mode = nullptr;
	QList<int>* btn_select = nullptr;

	QList<int>* btn_tl = nullptr;
	QList<int>* btn_tr = nullptr;
	QList<int>* btn_tl2 = nullptr;
	QList<int>* btn_tr2 = nullptr;

	QList<int>* abs_ljoy_up = nullptr;
	QList<int>* abs_ljoy_right = nullptr;
	QList<int>* abs_ljoy_down = nullptr;
	QList<int>* abs_ljoy_left = nullptr;
	QList<int>* btn_thumbl = nullptr;

	QList<int>* abs_rjoy_up = nullptr;
	QList<int>* abs_rjoy_right = nullptr;
	QList<int>* abs_rjoy_down = nullptr;
	QList<int>* abs_rjoy_left = nullptr;
	QList<int>* btn_thumbr = nullptr;
};

struct keyboard_events {
    QList<int>* key_a = nullptr;
    QList<int>* key_b = nullptr;
    QList<int>* key_c = nullptr;
    QList<int>* key_d = nullptr;
    QList<int>* key_e = nullptr;
    QList<int>* key_f = nullptr;
    QList<int>* key_g = nullptr;
    QList<int>* key_h = nullptr;
    QList<int>* key_i = nullptr;
    QList<int>* key_j = nullptr;
    QList<int>* key_k = nullptr;
    QList<int>* key_l = nullptr;
    QList<int>* key_m = nullptr;
    QList<int>* key_n = nullptr;
    QList<int>* key_o = nullptr;
    QList<int>* key_p = nullptr;
    QList<int>* key_q = nullptr;
    QList<int>* key_r = nullptr;
    QList<int>* key_s = nullptr;
    QList<int>* key_t = nullptr;
    QList<int>* key_u = nullptr;
    QList<int>* key_v = nullptr;
    QList<int>* key_w = nullptr;
    QList<int>* key_x = nullptr;
    QList<int>* key_y = nullptr;
    QList<int>* key_z = nullptr;

    QList<int>* key_space = nullptr;
    QList<int>* key_enter = nullptr;
    QList<int>* key_backspace = nullptr;
    QList<int>* key_tab = nullptr;
    QList<int>* key_esc = nullptr;
    QList<int>* key_capslock = nullptr;

    QList<int>* key_leftshift = nullptr;
    QList<int>* key_rightshift = nullptr;
    QList<int>* key_leftctrl = nullptr;
    QList<int>* key_rightctrl = nullptr;
    QList<int>* key_leftalt = nullptr;
    QList<int>* key_rightalt = nullptr;
    QList<int>* key_leftmeta = nullptr;
    QList<int>* key_rightmeta = nullptr;

    QList<int>* key_1 = nullptr;
    QList<int>* key_2 = nullptr;
    QList<int>* key_3 = nullptr;
    QList<int>* key_4 = nullptr;
    QList<int>* key_5 = nullptr;
    QList<int>* key_6 = nullptr;
    QList<int>* key_7 = nullptr;
    QList<int>* key_8 = nullptr;
    QList<int>* key_9 = nullptr;
    QList<int>* key_0 = nullptr;
    QList<int>* key_minus = nullptr;
    QList<int>* key_equal = nullptr;

    QList<int>* key_semicolon = nullptr;
    QList<int>* key_apostrophe = nullptr;
    QList<int>* key_comma = nullptr;
    QList<int>* key_dot = nullptr;
    QList<int>* key_slash = nullptr;
    QList<int>* key_backslash = nullptr;
    QList<int>* key_leftbrace = nullptr;
    QList<int>* key_rightbrace = nullptr;
    QList<int>* key_grave = nullptr;

    QList<int>* key_up = nullptr;
    QList<int>* key_down = nullptr;
    QList<int>* key_left = nullptr;
    QList<int>* key_right = nullptr;
    QList<int>* key_home = nullptr;
    QList<int>* key_end = nullptr;
    QList<int>* key_pageup = nullptr;
    QList<int>* key_pagedown = nullptr;
    QList<int>* key_insert = nullptr;
    QList<int>* key_delete = nullptr;

    QList<int>* key_f1 = nullptr;
    QList<int>* key_f2 = nullptr;
    QList<int>* key_f3 = nullptr;
    QList<int>* key_f4 = nullptr;
    QList<int>* key_f5 = nullptr;
    QList<int>* key_f6 = nullptr;
    QList<int>* key_f7 = nullptr;
    QList<int>* key_f8 = nullptr;
    QList<int>* key_f9 = nullptr;
    QList<int>* key_f10 = nullptr;
    QList<int>* key_f11 = nullptr;
    QList<int>* key_f12 = nullptr;

    QList<int>* key_numlock = nullptr;
    QList<int>* key_kp0 = nullptr;
    QList<int>* key_kp1 = nullptr;
    QList<int>* key_kp2 = nullptr;
    QList<int>* key_kp3 = nullptr;
    QList<int>* key_kp4 = nullptr;
    QList<int>* key_kp5 = nullptr;
    QList<int>* key_kp6 = nullptr;
    QList<int>* key_kp7 = nullptr;
    QList<int>* key_kp8 = nullptr;
    QList<int>* key_kp9 = nullptr;
    QList<int>* key_kpdot = nullptr;
    QList<int>* key_kpenter = nullptr;
    QList<int>* key_kpplus = nullptr;
    QList<int>* key_kpminus = nullptr;
    QList<int>* key_kpasterisk = nullptr;
    QList<int>* key_kpslash = nullptr;
    QList<int>* key_kpequal = nullptr;
    QList<int>* key_kpcomma = nullptr;
};