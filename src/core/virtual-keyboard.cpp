#include "virtual-keyboard.hpp"

VirtualKeyboard::VirtualKeyboard(const std::string& device_path, struct keyboard_events& events, std::atomic<bool>& input_listener_exists, QObject* parent) : VirtualDevice(device_path, input_listener_exists, parent), m_events(events) {

	struct libevdev* dev = libevdev_new();
	libevdev_set_name(dev, "Key Remapper Virtual Keyboard");

	libevdev_enable_event_type(dev, EV_KEY);
	libevdev_enable_event_code(dev, EV_KEY, KEY_A, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_B, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_C, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_D, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_E, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_G, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_H, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_I, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_J, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_K, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_L, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_M, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_N, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_O, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_P, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_Q, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_R, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_S, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_T, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_U, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_V, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_W, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_X, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_Y, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_Z, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_SPACE, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_ENTER, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_BACKSPACE, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_TAB, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_ESC, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_CAPSLOCK, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_LEFTSHIFT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_RIGHTSHIFT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_LEFTCTRL, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_RIGHTCTRL, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_LEFTALT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_RIGHTALT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_LEFTMETA, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_RIGHTMETA, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_1, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_2, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_3, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_4, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_5, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_6, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_7, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_8, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_9, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_0, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_MINUS, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_EQUAL, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_SEMICOLON, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_APOSTROPHE, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_COMMA, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_DOT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_SLASH, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_BACKSLASH, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_LEFTBRACE, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_RIGHTBRACE, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_GRAVE, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_UP, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_DOWN, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_LEFT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_RIGHT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_HOME, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_END, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_PAGEUP, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_PAGEDOWN, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_INSERT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_DELETE, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_F1, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F2, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F3, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F4, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F5, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F6, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F7, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F8, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F9, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F10, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F11, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_F12, nullptr);

	libevdev_enable_event_code(dev, EV_KEY, KEY_NUMLOCK, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP0, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP1, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP2, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP3, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP4, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP5, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP6, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP7, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP8, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KP9, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPDOT, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPENTER, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPPLUS, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPMINUS, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPASTERISK, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPSLASH, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPEQUAL, nullptr);
	libevdev_enable_event_code(dev, EV_KEY, KEY_KPCOMMA, nullptr);

	libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &m_uinput);
}

void VirtualKeyboard::generate_key_event(int code, int value) {
	libevdev_uinput_write_event(m_uinput, EV_KEY, code, value);
	libevdev_uinput_write_event(m_uinput, EV_SYN, SYN_REPORT, 0);
}

void VirtualKeyboard::handle_key_events(int code, int value) {

	if (value == 1) m_held_keys.insert(code);
	else m_held_keys.erase(code);

	if (m_events.key_a->contains(code)) {
		if (std::all_of(m_events.key_a->begin(), m_events.key_a->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_A, 1);
		else generate_key_event(KEY_A, 0);
	}
	
	else if (m_events.key_b->contains(code)) {
		if (std::all_of(m_events.key_b->begin(), m_events.key_b->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_B, 1);
		else generate_key_event(KEY_B, 0);
	}
	
	else if (m_events.key_c->contains(code)) {
		if (std::all_of(m_events.key_c->begin(), m_events.key_c->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_C, 1);
		else generate_key_event(KEY_C, 0);
	}
	
	else if (m_events.key_d->contains(code)) {
		if (std::all_of(m_events.key_d->begin(), m_events.key_d->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_D, 1);
		else generate_key_event(KEY_D, 0);
	}
	
	else if (m_events.key_e->contains(code)) {
		if (std::all_of(m_events.key_e->begin(), m_events.key_e->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_E, 1);
		else generate_key_event(KEY_E, 0);
	}
	
	else if (m_events.key_f->contains(code)) {
		if (std::all_of(m_events.key_f->begin(), m_events.key_f->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F, 1);
		else generate_key_event(KEY_F, 0);
	}
	
	else if (m_events.key_g->contains(code)) {
		if (std::all_of(m_events.key_g->begin(), m_events.key_g->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_G, 1);
		else generate_key_event(KEY_G, 0);
	}
	
	else if (m_events.key_h->contains(code)) {
		if (std::all_of(m_events.key_h->begin(), m_events.key_h->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_H, 1);
		else generate_key_event(KEY_H, 0);
	}
	
	else if (m_events.key_i->contains(code)) {
		if (std::all_of(m_events.key_i->begin(), m_events.key_i->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_I, 1);
		else generate_key_event(KEY_I, 0);
	}
	
	else if (m_events.key_j->contains(code)) {
		if (std::all_of(m_events.key_j->begin(), m_events.key_j->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_J, 1);
		else generate_key_event(KEY_J, 0);
	}
	
	else if (m_events.key_k->contains(code)) {
		if (std::all_of(m_events.key_k->begin(), m_events.key_k->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_K, 1);
		else generate_key_event(KEY_K, 0);
	}
	
	else if (m_events.key_l->contains(code)) {
		if (std::all_of(m_events.key_l->begin(), m_events.key_l->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_L, 1);
		else generate_key_event(KEY_L, 0);
	}
	
	else if (m_events.key_m->contains(code)) {
		if (std::all_of(m_events.key_m->begin(), m_events.key_m->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_M, 1);
		else generate_key_event(KEY_M, 0);
	}
	
	else if (m_events.key_n->contains(code)) {
		if (std::all_of(m_events.key_n->begin(), m_events.key_n->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_N, 1);
		else generate_key_event(KEY_N, 0);
	}
	
	else if (m_events.key_o->contains(code)) {
		if (std::all_of(m_events.key_o->begin(), m_events.key_o->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_O, 1);
		else generate_key_event(KEY_O, 0);
	}
	
	else if (m_events.key_p->contains(code)) {
		if (std::all_of(m_events.key_p->begin(), m_events.key_p->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_P, 1);
		else generate_key_event(KEY_P, 0);
	}
	
	else if (m_events.key_q->contains(code)) {
		if (std::all_of(m_events.key_q->begin(), m_events.key_q->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_Q, 1);
		else generate_key_event(KEY_Q, 0);
	}
	
	else if (m_events.key_r->contains(code)) {
		if (std::all_of(m_events.key_r->begin(), m_events.key_r->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_R, 1);
		else generate_key_event(KEY_R, 0);
	}
	
	else if (m_events.key_s->contains(code)) {
		if (std::all_of(m_events.key_s->begin(), m_events.key_s->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_S, 1);
		else generate_key_event(KEY_S, 0);
	}
	
	else if (m_events.key_t->contains(code)) {
		if (std::all_of(m_events.key_t->begin(), m_events.key_t->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_T, 1);
		else generate_key_event(KEY_T, 0);
	}
	
	else if (m_events.key_u->contains(code)) {
		if (std::all_of(m_events.key_u->begin(), m_events.key_u->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_U, 1);
		else generate_key_event(KEY_U, 0);
	}
	
	else if (m_events.key_v->contains(code)) {
		if (std::all_of(m_events.key_v->begin(), m_events.key_v->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_V, 1);
		else generate_key_event(KEY_V, 0);
	}
	
	else if (m_events.key_w->contains(code)) {
		if (std::all_of(m_events.key_w->begin(), m_events.key_w->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_W, 1);
		else generate_key_event(KEY_W, 0);
	}
	
	else if (m_events.key_x->contains(code)) {
		if (std::all_of(m_events.key_x->begin(), m_events.key_x->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_X, 1);
		else generate_key_event(KEY_X, 0);
	}
	
	else if (m_events.key_y->contains(code)) {
		if (std::all_of(m_events.key_y->begin(), m_events.key_y->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_Y, 1);
		else generate_key_event(KEY_Y, 0);
	}
	
	else if (m_events.key_z->contains(code)) {
		if (std::all_of(m_events.key_z->begin(), m_events.key_z->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_Z, 1);
		else generate_key_event(KEY_Z, 0);
	}
	
	else if (m_events.key_space->contains(code)) {
		if (std::all_of(m_events.key_space->begin(), m_events.key_space->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_SPACE, 1);
		else generate_key_event(KEY_SPACE, 0);
	}
	
	else if (m_events.key_enter->contains(code)) {
		if (std::all_of(m_events.key_enter->begin(), m_events.key_enter->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_ENTER, 1);
		else generate_key_event(KEY_ENTER, 0);
	}
	
	else if (m_events.key_backspace->contains(code)) {
		if (std::all_of(m_events.key_backspace->begin(), m_events.key_backspace->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_BACKSPACE, 1);
		else generate_key_event(KEY_BACKSPACE, 0);
	}
	
	else if (m_events.key_tab->contains(code)) {
		if (std::all_of(m_events.key_tab->begin(), m_events.key_tab->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_TAB, 1);
		else generate_key_event(KEY_TAB, 0);
	}
	
	else if (m_events.key_esc->contains(code)) {
		if (std::all_of(m_events.key_esc->begin(), m_events.key_esc->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_ESC, 1);
		else generate_key_event(KEY_ESC, 0);
	}
	
	else if (m_events.key_capslock->contains(code)) {
		if (std::all_of(m_events.key_capslock->begin(), m_events.key_capslock->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_CAPSLOCK, 1);
		else generate_key_event(KEY_CAPSLOCK, 0);
	}
	
	else if (m_events.key_leftshift->contains(code)) {
		if (std::all_of(m_events.key_leftshift->begin(), m_events.key_leftshift->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_LEFTSHIFT, 1);
		else generate_key_event(KEY_LEFTSHIFT, 0);
	}
	
	else if (m_events.key_rightshift->contains(code)) {
		if (std::all_of(m_events.key_rightshift->begin(), m_events.key_rightshift->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_RIGHTSHIFT, 1);
		else generate_key_event(KEY_RIGHTSHIFT, 0);
	}
	
	else if (m_events.key_leftctrl->contains(code)) {
		if (std::all_of(m_events.key_leftctrl->begin(), m_events.key_leftctrl->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_LEFTCTRL, 1);
		else generate_key_event(KEY_LEFTCTRL, 0);
	}
	
	else if (m_events.key_rightctrl->contains(code)) {
		if (std::all_of(m_events.key_rightctrl->begin(), m_events.key_rightctrl->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_RIGHTCTRL, 1);
		else generate_key_event(KEY_RIGHTCTRL, 0);
	}
	
	else if (m_events.key_leftalt->contains(code)) {
		if (std::all_of(m_events.key_leftalt->begin(), m_events.key_leftalt->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_LEFTALT, 1);
		else generate_key_event(KEY_LEFTALT, 0);
	}
	
	else if (m_events.key_rightalt->contains(code)) {
		if (std::all_of(m_events.key_rightalt->begin(), m_events.key_rightalt->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_RIGHTALT, 1);
		else generate_key_event(KEY_RIGHTALT, 0);
	}
	
	else if (m_events.key_leftmeta->contains(code)) {
		if (std::all_of(m_events.key_leftmeta->begin(), m_events.key_leftmeta->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_LEFTMETA, 1);
		else generate_key_event(KEY_LEFTMETA, 0);
	}
	
	else if (m_events.key_rightmeta->contains(code)) {
		if (std::all_of(m_events.key_rightmeta->begin(), m_events.key_rightmeta->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_RIGHTMETA, 1);
		else generate_key_event(KEY_RIGHTMETA, 0);
	}
	
	else if (m_events.key_1->contains(code)) {
		if (std::all_of(m_events.key_1->begin(), m_events.key_1->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_1, 1);
		else generate_key_event(KEY_1, 0);
	}
	
	else if (m_events.key_2->contains(code)) {
		if (std::all_of(m_events.key_2->begin(), m_events.key_2->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_2, 1);
		else generate_key_event(KEY_2, 0);
	}
	
	else if (m_events.key_3->contains(code)) {
		if (std::all_of(m_events.key_3->begin(), m_events.key_3->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_3, 1);
		else generate_key_event(KEY_3, 0);
	}
	
	else if (m_events.key_4->contains(code)) {
		if (std::all_of(m_events.key_4->begin(), m_events.key_4->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_4, 1);
		else generate_key_event(KEY_4, 0);
	}
	
	else if (m_events.key_5->contains(code)) {
		if (std::all_of(m_events.key_5->begin(), m_events.key_5->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_5, 1);
		else generate_key_event(KEY_5, 0);
	}
	
	else if (m_events.key_6->contains(code)) {
		if (std::all_of(m_events.key_6->begin(), m_events.key_6->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_6, 1);
		else generate_key_event(KEY_6, 0);
	}
	
	else if (m_events.key_7->contains(code)) {
		if (std::all_of(m_events.key_7->begin(), m_events.key_7->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_7, 1);
		else generate_key_event(KEY_7, 0);
	}
	
	else if (m_events.key_8->contains(code)) {
		if (std::all_of(m_events.key_8->begin(), m_events.key_8->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_8, 1);
		else generate_key_event(KEY_8, 0);
	}
	
	else if (m_events.key_9->contains(code)) {
		if (std::all_of(m_events.key_9->begin(), m_events.key_9->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_9, 1);
		else generate_key_event(KEY_9, 0);
	}
	
	else if (m_events.key_0->contains(code)) {
		if (std::all_of(m_events.key_0->begin(), m_events.key_0->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_0, 1);
		else generate_key_event(KEY_0, 0);
	}
	
	else if (m_events.key_minus->contains(code)) {
		if (std::all_of(m_events.key_minus->begin(), m_events.key_minus->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_MINUS, 1);
		else generate_key_event(KEY_MINUS, 0);
	}
	
	else if (m_events.key_equal->contains(code)) {
		if (std::all_of(m_events.key_equal->begin(), m_events.key_equal->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_EQUAL, 1);
		else generate_key_event(KEY_EQUAL, 0);
	}
	
	else if (m_events.key_semicolon->contains(code)) {
		if (std::all_of(m_events.key_semicolon->begin(), m_events.key_semicolon->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_SEMICOLON, 1);
		else generate_key_event(KEY_SEMICOLON, 0);
	}
	
	else if (m_events.key_apostrophe->contains(code)) {
		if (std::all_of(m_events.key_apostrophe->begin(), m_events.key_apostrophe->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_APOSTROPHE, 1);
		else generate_key_event(KEY_APOSTROPHE, 0);
	}
	
	else if (m_events.key_comma->contains(code)) {
		if (std::all_of(m_events.key_comma->begin(), m_events.key_comma->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_COMMA, 1);
		else generate_key_event(KEY_COMMA, 0);
	}
	
	else if (m_events.key_dot->contains(code)) {
		if (std::all_of(m_events.key_dot->begin(), m_events.key_dot->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_DOT, 1);
		else generate_key_event(KEY_DOT, 0);
	}
	
	else if (m_events.key_slash->contains(code)) {
		if (std::all_of(m_events.key_slash->begin(), m_events.key_slash->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_SLASH, 1);
		else generate_key_event(KEY_SLASH, 0);
	}
	
	else if (m_events.key_backslash->contains(code)) {
		if (std::all_of(m_events.key_backslash->begin(), m_events.key_backslash->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_BACKSLASH, 1);
		else generate_key_event(KEY_BACKSLASH, 0);
	}
	
	else if (m_events.key_leftbrace->contains(code)) {
		if (std::all_of(m_events.key_leftbrace->begin(), m_events.key_leftbrace->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_LEFTBRACE, 1);
		else generate_key_event(KEY_LEFTBRACE, 0);
	}
	
	else if (m_events.key_rightbrace->contains(code)) {
		if (std::all_of(m_events.key_rightbrace->begin(), m_events.key_rightbrace->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_RIGHTBRACE, 1);
		else generate_key_event(KEY_RIGHTBRACE, 0);
	}
	
	else if (m_events.key_grave->contains(code)) {
		if (std::all_of(m_events.key_grave->begin(), m_events.key_grave->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_GRAVE, 1);
		else generate_key_event(KEY_GRAVE, 0);
	}
	
	else if (m_events.key_up->contains(code)) {
		if (std::all_of(m_events.key_up->begin(), m_events.key_up->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_UP, 1);
		else generate_key_event(KEY_UP, 0);
	}
	
	else if (m_events.key_down->contains(code)) {
		if (std::all_of(m_events.key_down->begin(), m_events.key_down->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_DOWN, 1);
		else generate_key_event(KEY_DOWN, 0);
	}
	
	else if (m_events.key_left->contains(code)) {
		if (std::all_of(m_events.key_left->begin(), m_events.key_left->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_LEFT, 1);
		else generate_key_event(KEY_LEFT, 0);
	}
	
	else if (m_events.key_right->contains(code)) {
		if (std::all_of(m_events.key_right->begin(), m_events.key_right->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_RIGHT, 1);
		else generate_key_event(KEY_RIGHT, 0);
	}
	
	else if (m_events.key_home->contains(code)) {
		if (std::all_of(m_events.key_home->begin(), m_events.key_home->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_HOME, 1);
		else generate_key_event(KEY_HOME, 0);
	}
	
	else if (m_events.key_end->contains(code)) {
		if (std::all_of(m_events.key_end->begin(), m_events.key_end->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_END, 1);
		else generate_key_event(KEY_END, 0);
	}
	
	else if (m_events.key_pageup->contains(code)) {
		if (std::all_of(m_events.key_pageup->begin(), m_events.key_pageup->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_PAGEUP, 1);
		else generate_key_event(KEY_PAGEUP, 0);
	}
	
	else if (m_events.key_pagedown->contains(code)) {
		if (std::all_of(m_events.key_pagedown->begin(), m_events.key_pagedown->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_PAGEDOWN, 1);
		else generate_key_event(KEY_PAGEDOWN, 0);
	}
	
	else if (m_events.key_insert->contains(code)) {
		if (std::all_of(m_events.key_insert->begin(), m_events.key_insert->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_INSERT, 1);
		else generate_key_event(KEY_INSERT, 0);
	}
	
	else if (m_events.key_delete->contains(code)) {
		if (std::all_of(m_events.key_delete->begin(), m_events.key_delete->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_DELETE, 1);
		else generate_key_event(KEY_DELETE, 0);
	}
	
	else if (m_events.key_f1->contains(code)) {
		if (std::all_of(m_events.key_f1->begin(), m_events.key_f1->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F1, 1);
		else generate_key_event(KEY_F1, 0);
	}
	
	else if (m_events.key_f2->contains(code)) {
		if (std::all_of(m_events.key_f2->begin(), m_events.key_f2->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F2, 1);
		else generate_key_event(KEY_F2, 0);
	}
	
	else if (m_events.key_f3->contains(code)) {
		if (std::all_of(m_events.key_f3->begin(), m_events.key_f3->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F3, 1);
		else generate_key_event(KEY_F3, 0);
	}
	
	else if (m_events.key_f4->contains(code)) {
		if (std::all_of(m_events.key_f4->begin(), m_events.key_f4->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F4, 1);
		else generate_key_event(KEY_F4, 0);
	}
	
	else if (m_events.key_f5->contains(code)) {
		if (std::all_of(m_events.key_f5->begin(), m_events.key_f5->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F5, 1);
		else generate_key_event(KEY_F5, 0);
	}
	
	else if (m_events.key_f6->contains(code)) {
		if (std::all_of(m_events.key_f6->begin(), m_events.key_f6->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F6, 1);
		else generate_key_event(KEY_F6, 0);
	}
	
	else if (m_events.key_f7->contains(code)) {
		if (std::all_of(m_events.key_f7->begin(), m_events.key_f7->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F7, 1);
		else generate_key_event(KEY_F7, 0);
	}
	
	else if (m_events.key_f8->contains(code)) {
		if (std::all_of(m_events.key_f8->begin(), m_events.key_f8->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F8, 1);
		else generate_key_event(KEY_F8, 0);
	}
	
	else if (m_events.key_f9->contains(code)) {
		if (std::all_of(m_events.key_f9->begin(), m_events.key_f9->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F9, 1);
		else generate_key_event(KEY_F9, 0);
	}
	
	else if (m_events.key_f10->contains(code)) {
		if (std::all_of(m_events.key_f10->begin(), m_events.key_f10->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F10, 1);
		else generate_key_event(KEY_F10, 0);
	}
	
	else if (m_events.key_f11->contains(code)) {
		if (std::all_of(m_events.key_f11->begin(), m_events.key_f11->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F11, 1);
		else generate_key_event(KEY_F11, 0);
	}
	
	else if (m_events.key_f12->contains(code)) {
		if (std::all_of(m_events.key_f12->begin(), m_events.key_f12->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_F12, 1);
		else generate_key_event(KEY_F12, 0);
	}
	
	else if (m_events.key_numlock->contains(code)) {
		if (std::all_of(m_events.key_numlock->begin(), m_events.key_numlock->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_NUMLOCK, 1);
		else generate_key_event(KEY_NUMLOCK, 0);
	}
	
	else if (m_events.key_kp0->contains(code)) {
		if (std::all_of(m_events.key_kp0->begin(), m_events.key_kp0->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP0, 1);
		else generate_key_event(KEY_KP0, 0);
	}
	
	else if (m_events.key_kp1->contains(code)) {
		if (std::all_of(m_events.key_kp1->begin(), m_events.key_kp1->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP1, 1);
		else generate_key_event(KEY_KP1, 0);
	}
	
	else if (m_events.key_kp2->contains(code)) {
		if (std::all_of(m_events.key_kp2->begin(), m_events.key_kp2->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP2, 1);
		else generate_key_event(KEY_KP2, 0);
	}
	
	else if (m_events.key_kp3->contains(code)) {
		if (std::all_of(m_events.key_kp3->begin(), m_events.key_kp3->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP3, 1);
		else generate_key_event(KEY_KP3, 0);
	}
	
	else if (m_events.key_kp4->contains(code)) {
		if (std::all_of(m_events.key_kp4->begin(), m_events.key_kp4->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP4, 1);
		else generate_key_event(KEY_KP4, 0);
	}
	
	else if (m_events.key_kp5->contains(code)) {
		if (std::all_of(m_events.key_kp5->begin(), m_events.key_kp5->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP5, 1);
		else generate_key_event(KEY_KP5, 0);
	}
	
	else if (m_events.key_kp6->contains(code)) {
		if (std::all_of(m_events.key_kp6->begin(), m_events.key_kp6->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP6, 1);
		else generate_key_event(KEY_KP6, 0);
	}
	
	else if (m_events.key_kp7->contains(code)) {
		if (std::all_of(m_events.key_kp7->begin(), m_events.key_kp7->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP7, 1);
		else generate_key_event(KEY_KP7, 0);
	}
	
	else if (m_events.key_kp8->contains(code)) {
		if (std::all_of(m_events.key_kp8->begin(), m_events.key_kp8->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP8, 1);
		else generate_key_event(KEY_KP8, 0);
	}
	
	else if (m_events.key_kp9->contains(code)) {
		if (std::all_of(m_events.key_kp9->begin(), m_events.key_kp9->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KP9, 1);
		else generate_key_event(KEY_KP9, 0);
	}
	
	else if (m_events.key_kpdot->contains(code)) {
		if (std::all_of(m_events.key_kpdot->begin(), m_events.key_kpdot->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPDOT, 1);
		else generate_key_event(KEY_KPDOT, 0);
	}
	
	else if (m_events.key_kpenter->contains(code)) {
		if (std::all_of(m_events.key_kpenter->begin(), m_events.key_kpenter->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPENTER, 1);
		else generate_key_event(KEY_KPENTER, 0);
	}
	
	else if (m_events.key_kpplus->contains(code)) {
		if (std::all_of(m_events.key_kpplus->begin(), m_events.key_kpplus->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPPLUS, 1);
		else generate_key_event(KEY_KPPLUS, 0);
	}
	
	else if (m_events.key_kpminus->contains(code)) {
		if (std::all_of(m_events.key_kpminus->begin(), m_events.key_kpminus->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPMINUS, 1);
		else generate_key_event(KEY_KPMINUS, 0);
	}
	
	else if (m_events.key_kpasterisk->contains(code)) {
		if (std::all_of(m_events.key_kpasterisk->begin(), m_events.key_kpasterisk->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPASTERISK, 1);
		else generate_key_event(KEY_KPASTERISK, 0);
	}
	
	else if (m_events.key_kpslash->contains(code)) {
		if (std::all_of(m_events.key_kpslash->begin(), m_events.key_kpslash->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPSLASH, 1);
		else generate_key_event(KEY_KPSLASH, 0);
	}
	
	else if (m_events.key_kpequal->contains(code)) {
		if (std::all_of(m_events.key_kpequal->begin(), m_events.key_kpequal->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPEQUAL, 1);
		else generate_key_event(KEY_KPEQUAL, 0);
	}
	
	else if (m_events.key_kpcomma->contains(code)) {
		if (std::all_of(m_events.key_kpcomma->begin(), m_events.key_kpcomma->end(), [this](int k){return m_held_keys.contains(k);})) generate_key_event(KEY_KPCOMMA, 1);
		else generate_key_event(KEY_KPCOMMA, 0);
	}

	else {
		generate_key_event(code, value);
	}
}