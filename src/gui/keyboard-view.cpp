#include "keyboard-view.hpp"
#include <iostream>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QThread>

KeyboardView::KeyboardView(std::string& selected_device, QWidget* parent) : QWidget(parent), m_selected_device(selected_device) {

	QFormLayout* layout = new QFormLayout();
	this->setLayout(layout);

	LabelButton* key_a = new LabelButton("A", "No key assigned");
	layout->addRow(key_a);
	connect(key_a->button, &QPushButton::clicked, this, [this, key_a](){ start_key_listener(key_a); });
	m_events.key_a = &key_a->key_code;

	LabelButton* key_b = new LabelButton("B", "No key assigned");
	layout->addRow(key_b);
	connect(key_b->button, &QPushButton::clicked, this, [this, key_b](){ start_key_listener(key_b); });
	m_events.key_b = &key_b->key_code;

	LabelButton* key_c = new LabelButton("C", "No key assigned");
	layout->addRow(key_c);
	connect(key_c->button, &QPushButton::clicked, this, [this, key_c](){ start_key_listener(key_c); });
	m_events.key_c = &key_c->key_code;

	LabelButton* key_d = new LabelButton("D", "No key assigned");
	layout->addRow(key_d);
	connect(key_d->button, &QPushButton::clicked, this, [this, key_d](){ start_key_listener(key_d); });
	m_events.key_d = &key_d->key_code;

	LabelButton* key_e = new LabelButton("E", "No key assigned");
	layout->addRow(key_e);
	connect(key_e->button, &QPushButton::clicked, this, [this, key_e](){ start_key_listener(key_e); });
	m_events.key_e = &key_e->key_code;

	LabelButton* key_f = new LabelButton("F", "No key assigned");
	layout->addRow(key_f);
	connect(key_f->button, &QPushButton::clicked, this, [this, key_f](){ start_key_listener(key_f); });
	m_events.key_f = &key_f->key_code;

	LabelButton* key_g = new LabelButton("G", "No key assigned");
	layout->addRow(key_g);
	connect(key_g->button, &QPushButton::clicked, this, [this, key_g](){ start_key_listener(key_g); });
	m_events.key_g = &key_g->key_code;

	LabelButton* key_h = new LabelButton("H", "No key assigned");
	layout->addRow(key_h);
	connect(key_h->button, &QPushButton::clicked, this, [this, key_h](){ start_key_listener(key_h); });
	m_events.key_h = &key_h->key_code;

	LabelButton* key_i = new LabelButton("I", "No key assigned");
	layout->addRow(key_i);
	connect(key_i->button, &QPushButton::clicked, this, [this, key_i](){ start_key_listener(key_i); });
	m_events.key_i = &key_i->key_code;

	LabelButton* key_j = new LabelButton("J", "No key assigned");
	layout->addRow(key_j);
	connect(key_j->button, &QPushButton::clicked, this, [this, key_j](){ start_key_listener(key_j); });
	m_events.key_j = &key_j->key_code;

	LabelButton* key_k = new LabelButton("K", "No key assigned");
	layout->addRow(key_k);
	connect(key_k->button, &QPushButton::clicked, this, [this, key_k](){ start_key_listener(key_k); });
	m_events.key_k = &key_k->key_code;

	LabelButton* key_l = new LabelButton("L", "No key assigned");
	layout->addRow(key_l);
	connect(key_l->button, &QPushButton::clicked, this, [this, key_l](){ start_key_listener(key_l); });
	m_events.key_l = &key_l->key_code;

	LabelButton* key_m = new LabelButton("M", "No key assigned");
	layout->addRow(key_m);
	connect(key_m->button, &QPushButton::clicked, this, [this, key_m](){ start_key_listener(key_m); });
	m_events.key_m = &key_m->key_code;

	LabelButton* key_n = new LabelButton("N", "No key assigned");
	layout->addRow(key_n);
	connect(key_n->button, &QPushButton::clicked, this, [this, key_n](){ start_key_listener(key_n); });
	m_events.key_n = &key_n->key_code;

	LabelButton* key_o = new LabelButton("O", "No key assigned");
	layout->addRow(key_o);
	connect(key_o->button, &QPushButton::clicked, this, [this, key_o](){ start_key_listener(key_o); });
	m_events.key_o = &key_o->key_code;

	LabelButton* key_p = new LabelButton("P", "No key assigned");
	layout->addRow(key_p);
	connect(key_p->button, &QPushButton::clicked, this, [this, key_p](){ start_key_listener(key_p); });
	m_events.key_p = &key_p->key_code;

	LabelButton* key_q = new LabelButton("Q", "No key assigned");
	layout->addRow(key_q);
	connect(key_q->button, &QPushButton::clicked, this, [this, key_q](){ start_key_listener(key_q); });
	m_events.key_q = &key_q->key_code;

	LabelButton* key_r = new LabelButton("R", "No key assigned");
	layout->addRow(key_r);
	connect(key_r->button, &QPushButton::clicked, this, [this, key_r](){ start_key_listener(key_r); });
	m_events.key_r = &key_r->key_code;

	LabelButton* key_s = new LabelButton("S", "No key assigned");
	layout->addRow(key_s);
	connect(key_s->button, &QPushButton::clicked, this, [this, key_s](){ start_key_listener(key_s); });
	m_events.key_s = &key_s->key_code;

	LabelButton* key_t = new LabelButton("T", "No key assigned");
	layout->addRow(key_t);
	connect(key_t->button, &QPushButton::clicked, this, [this, key_t](){ start_key_listener(key_t); });
	m_events.key_t = &key_t->key_code;

	LabelButton* key_u = new LabelButton("U", "No key assigned");
	layout->addRow(key_u);
	connect(key_u->button, &QPushButton::clicked, this, [this, key_u](){ start_key_listener(key_u); });
	m_events.key_u = &key_u->key_code;

	LabelButton* key_v = new LabelButton("V", "No key assigned");
	layout->addRow(key_v);
	connect(key_v->button, &QPushButton::clicked, this, [this, key_v](){ start_key_listener(key_v); });
	m_events.key_v = &key_v->key_code;

	LabelButton* key_w = new LabelButton("W", "No key assigned");
	layout->addRow(key_w);
	connect(key_w->button, &QPushButton::clicked, this, [this, key_w](){ start_key_listener(key_w); });
	m_events.key_w = &key_w->key_code;

	LabelButton* key_x = new LabelButton("X", "No key assigned");
	layout->addRow(key_x);
	connect(key_x->button, &QPushButton::clicked, this, [this, key_x](){ start_key_listener(key_x); });
	m_events.key_x = &key_x->key_code;

	LabelButton* key_y = new LabelButton("Y", "No key assigned");
	layout->addRow(key_y);
	connect(key_y->button, &QPushButton::clicked, this, [this, key_y](){ start_key_listener(key_y); });
	m_events.key_y = &key_y->key_code;

	LabelButton* key_z = new LabelButton("Z", "No key assigned");
	layout->addRow(key_z);
	connect(key_z->button, &QPushButton::clicked, this, [this, key_z](){ start_key_listener(key_z); });
	m_events.key_z = &key_z->key_code;

	LabelButton* key_space = new LabelButton("Space", "No key assigned");
	layout->addRow(key_space);
	connect(key_space->button, &QPushButton::clicked, this, [this, key_space](){ start_key_listener(key_space); });
	m_events.key_space = &key_space->key_code;

	LabelButton* key_enter = new LabelButton("Enter", "No key assigned");
	layout->addRow(key_enter);
	connect(key_enter->button, &QPushButton::clicked, this, [this, key_enter](){ start_key_listener(key_enter); });
	m_events.key_enter = &key_enter->key_code;

	LabelButton* key_backspace = new LabelButton("Backspace", "No key assigned");
	layout->addRow(key_backspace);
	connect(key_backspace->button, &QPushButton::clicked, this, [this, key_backspace](){ start_key_listener(key_backspace); });
	m_events.key_backspace = &key_backspace->key_code;

	LabelButton* key_tab = new LabelButton("Tab", "No key assigned");
	layout->addRow(key_tab);
	connect(key_tab->button, &QPushButton::clicked, this, [this, key_tab](){ start_key_listener(key_tab); });
	m_events.key_tab = &key_tab->key_code;

	LabelButton* key_esc = new LabelButton("Esc", "No key assigned");
	layout->addRow(key_esc);
	connect(key_esc->button, &QPushButton::clicked, this, [this, key_esc](){ start_key_listener(key_esc); });
	m_events.key_esc = &key_esc->key_code;

	LabelButton* key_capslock = new LabelButton("Caps Lock", "No key assigned");
	layout->addRow(key_capslock);
	connect(key_capslock->button, &QPushButton::clicked, this, [this, key_capslock](){ start_key_listener(key_capslock); });
	m_events.key_capslock = &key_capslock->key_code;

	LabelButton* key_leftshift = new LabelButton("Left Shift", "No key assigned");
	layout->addRow(key_leftshift);
	connect(key_leftshift->button, &QPushButton::clicked, this, [this, key_leftshift](){ start_key_listener(key_leftshift); });
	m_events.key_leftshift = &key_leftshift->key_code;

	LabelButton* key_rightshift = new LabelButton("Right Shift", "No key assigned");
	layout->addRow(key_rightshift);
	connect(key_rightshift->button, &QPushButton::clicked, this, [this, key_rightshift](){ start_key_listener(key_rightshift); });
	m_events.key_rightshift = &key_rightshift->key_code;

	LabelButton* key_leftctrl = new LabelButton("Left Ctrl", "No key assigned");
	layout->addRow(key_leftctrl);
	connect(key_leftctrl->button, &QPushButton::clicked, this, [this, key_leftctrl](){ start_key_listener(key_leftctrl); });
	m_events.key_leftctrl = &key_leftctrl->key_code;

	LabelButton* key_rightctrl = new LabelButton("Right Ctrl", "No key assigned");
	layout->addRow(key_rightctrl);
	connect(key_rightctrl->button, &QPushButton::clicked, this, [this, key_rightctrl](){ start_key_listener(key_rightctrl); });
	m_events.key_rightctrl = &key_rightctrl->key_code;

	LabelButton* key_leftalt = new LabelButton("Left Alt", "No key assigned");
	layout->addRow(key_leftalt);
	connect(key_leftalt->button, &QPushButton::clicked, this, [this, key_leftalt](){ start_key_listener(key_leftalt); });
	m_events.key_leftalt = &key_leftalt->key_code;

	LabelButton* key_rightalt = new LabelButton("Right Alt", "No key assigned");
	layout->addRow(key_rightalt);
	connect(key_rightalt->button, &QPushButton::clicked, this, [this, key_rightalt](){ start_key_listener(key_rightalt); });
	m_events.key_rightalt = &key_rightalt->key_code;

	LabelButton* key_leftmeta = new LabelButton("Left Meta", "No key assigned");
	layout->addRow(key_leftmeta);
	connect(key_leftmeta->button, &QPushButton::clicked, this, [this, key_leftmeta](){ start_key_listener(key_leftmeta); });
	m_events.key_leftmeta = &key_leftmeta->key_code;

	LabelButton* key_rightmeta = new LabelButton("Right Meta", "No key assigned");
	layout->addRow(key_rightmeta);
	connect(key_rightmeta->button, &QPushButton::clicked, this, [this, key_rightmeta](){ start_key_listener(key_rightmeta); });
	m_events.key_rightmeta = &key_rightmeta->key_code;

	LabelButton* key_1 = new LabelButton("1", "No key assigned");
	layout->addRow(key_1);
	connect(key_1->button, &QPushButton::clicked, this, [this, key_1](){ start_key_listener(key_1); });
	m_events.key_1 = &key_1->key_code;

	LabelButton* key_2 = new LabelButton("2", "No key assigned");
	layout->addRow(key_2);
	connect(key_2->button, &QPushButton::clicked, this, [this, key_2](){ start_key_listener(key_2); });
	m_events.key_2 = &key_2->key_code;

	LabelButton* key_3 = new LabelButton("3", "No key assigned");
	layout->addRow(key_3);
	connect(key_3->button, &QPushButton::clicked, this, [this, key_3](){ start_key_listener(key_3); });
	m_events.key_3 = &key_3->key_code;

	LabelButton* key_4 = new LabelButton("4", "No key assigned");
	layout->addRow(key_4);
	connect(key_4->button, &QPushButton::clicked, this, [this, key_4](){ start_key_listener(key_4); });
	m_events.key_4 = &key_4->key_code;

	LabelButton* key_5 = new LabelButton("5", "No key assigned");
	layout->addRow(key_5);
	connect(key_5->button, &QPushButton::clicked, this, [this, key_5](){ start_key_listener(key_5); });
	m_events.key_5 = &key_5->key_code;

	LabelButton* key_6 = new LabelButton("6", "No key assigned");
	layout->addRow(key_6);
	connect(key_6->button, &QPushButton::clicked, this, [this, key_6](){ start_key_listener(key_6); });
	m_events.key_6 = &key_6->key_code;

	LabelButton* key_7 = new LabelButton("7", "No key assigned");
	layout->addRow(key_7);
	connect(key_7->button, &QPushButton::clicked, this, [this, key_7](){ start_key_listener(key_7); });
	m_events.key_7 = &key_7->key_code;

	LabelButton* key_8 = new LabelButton("8", "No key assigned");
	layout->addRow(key_8);
	connect(key_8->button, &QPushButton::clicked, this, [this, key_8](){ start_key_listener(key_8); });
	m_events.key_8 = &key_8->key_code;

	LabelButton* key_9 = new LabelButton("9", "No key assigned");
	layout->addRow(key_9);
	connect(key_9->button, &QPushButton::clicked, this, [this, key_9](){ start_key_listener(key_9); });
	m_events.key_9 = &key_9->key_code;

	LabelButton* key_0 = new LabelButton("0", "No key assigned");
	layout->addRow(key_0);
	connect(key_0->button, &QPushButton::clicked, this, [this, key_0](){ start_key_listener(key_0); });
	m_events.key_0 = &key_0->key_code;

	LabelButton* key_minus = new LabelButton("-", "No key assigned");
	layout->addRow(key_minus);
	connect(key_minus->button, &QPushButton::clicked, this, [this, key_minus](){ start_key_listener(key_minus); });
	m_events.key_minus = &key_minus->key_code;

	LabelButton* key_equal = new LabelButton("=", "No key assigned");
	layout->addRow(key_equal);
	connect(key_equal->button, &QPushButton::clicked, this, [this, key_equal](){ start_key_listener(key_equal); });
	m_events.key_equal = &key_equal->key_code;

	LabelButton* key_semicolon = new LabelButton(";", "No key assigned");
	layout->addRow(key_semicolon);
	connect(key_semicolon->button, &QPushButton::clicked, this, [this, key_semicolon](){ start_key_listener(key_semicolon); });
	m_events.key_semicolon = &key_semicolon->key_code;

	LabelButton* key_apostrophe = new LabelButton("'", "No key assigned");
	layout->addRow(key_apostrophe);
	connect(key_apostrophe->button, &QPushButton::clicked, this, [this, key_apostrophe](){ start_key_listener(key_apostrophe); });
	m_events.key_apostrophe = &key_apostrophe->key_code;

	LabelButton* key_comma = new LabelButton(",", "No key assigned");
	layout->addRow(key_comma);
	connect(key_comma->button, &QPushButton::clicked, this, [this, key_comma](){ start_key_listener(key_comma); });
	m_events.key_comma = &key_comma->key_code;

	LabelButton* key_dot = new LabelButton(".", "No key assigned");
	layout->addRow(key_dot);
	connect(key_dot->button, &QPushButton::clicked, this, [this, key_dot](){ start_key_listener(key_dot); });
	m_events.key_dot = &key_dot->key_code;

	LabelButton* key_slash = new LabelButton("/", "No key assigned");
	layout->addRow(key_slash);
	connect(key_slash->button, &QPushButton::clicked, this, [this, key_slash](){ start_key_listener(key_slash); });
	m_events.key_slash = &key_slash->key_code;

	LabelButton* key_backslash = new LabelButton("\\", "No key assigned");
	layout->addRow(key_backslash);
	connect(key_backslash->button, &QPushButton::clicked, this, [this, key_backslash](){ start_key_listener(key_backslash); });
	m_events.key_backslash = &key_backslash->key_code;

	LabelButton* key_leftbrace = new LabelButton("[", "No key assigned");
	layout->addRow(key_leftbrace);
	connect(key_leftbrace->button, &QPushButton::clicked, this, [this, key_leftbrace](){ start_key_listener(key_leftbrace); });
	m_events.key_leftbrace = &key_leftbrace->key_code;

	LabelButton* key_rightbrace = new LabelButton("]", "No key assigned");
	layout->addRow(key_rightbrace);
	connect(key_rightbrace->button, &QPushButton::clicked, this, [this, key_rightbrace](){ start_key_listener(key_rightbrace); });
	m_events.key_rightbrace = &key_rightbrace->key_code;

	LabelButton* key_grave = new LabelButton("`", "No key assigned");
	layout->addRow(key_grave);
	connect(key_grave->button, &QPushButton::clicked, this, [this, key_grave](){ start_key_listener(key_grave); });
	m_events.key_grave = &key_grave->key_code;

	LabelButton* key_up = new LabelButton("Up", "No key assigned");
	layout->addRow(key_up);
	connect(key_up->button, &QPushButton::clicked, this, [this, key_up](){ start_key_listener(key_up); });
	m_events.key_up = &key_up->key_code;

	LabelButton* key_down = new LabelButton("Down", "No key assigned");
	layout->addRow(key_down);
	connect(key_down->button, &QPushButton::clicked, this, [this, key_down](){ start_key_listener(key_down); });
	m_events.key_down = &key_down->key_code;

	LabelButton* key_left = new LabelButton("Left", "No key assigned");
	layout->addRow(key_left);
	connect(key_left->button, &QPushButton::clicked, this, [this, key_left](){ start_key_listener(key_left); });
	m_events.key_left = &key_left->key_code;

	LabelButton* key_right = new LabelButton("Right", "No key assigned");
	layout->addRow(key_right);
	connect(key_right->button, &QPushButton::clicked, this, [this, key_right](){ start_key_listener(key_right); });
	m_events.key_right = &key_right->key_code;

	LabelButton* key_home = new LabelButton("Home", "No key assigned");
	layout->addRow(key_home);
	connect(key_home->button, &QPushButton::clicked, this, [this, key_home](){ start_key_listener(key_home); });
	m_events.key_home = &key_home->key_code;

	LabelButton* key_end = new LabelButton("End", "No key assigned");
	layout->addRow(key_end);
	connect(key_end->button, &QPushButton::clicked, this, [this, key_end](){ start_key_listener(key_end); });
	m_events.key_end = &key_end->key_code;

	LabelButton* key_pageup = new LabelButton("Page Up", "No key assigned");
	layout->addRow(key_pageup);
	connect(key_pageup->button, &QPushButton::clicked, this, [this, key_pageup](){ start_key_listener(key_pageup); });
	m_events.key_pageup = &key_pageup->key_code;

	LabelButton* key_pagedown = new LabelButton("Page Down", "No key assigned");
	layout->addRow(key_pagedown);
	connect(key_pagedown->button, &QPushButton::clicked, this, [this, key_pagedown](){ start_key_listener(key_pagedown); });
	m_events.key_pagedown = &key_pagedown->key_code;

	LabelButton* key_insert = new LabelButton("Insert", "No key assigned");
	layout->addRow(key_insert);
	connect(key_insert->button, &QPushButton::clicked, this, [this, key_insert](){ start_key_listener(key_insert); });
	m_events.key_insert = &key_insert->key_code;

	LabelButton* key_delete = new LabelButton("Delete", "No key assigned");
	layout->addRow(key_delete);
	connect(key_delete->button, &QPushButton::clicked, this, [this, key_delete](){ start_key_listener(key_delete); });
	m_events.key_delete = &key_delete->key_code;

	LabelButton* key_f1 = new LabelButton("F1", "No key assigned");
	layout->addRow(key_f1);
	connect(key_f1->button, &QPushButton::clicked, this, [this, key_f1](){ start_key_listener(key_f1); });
	m_events.key_f1 = &key_f1->key_code;

	LabelButton* key_f2 = new LabelButton("F2", "No key assigned");
	layout->addRow(key_f2);
	connect(key_f2->button, &QPushButton::clicked, this, [this, key_f2](){ start_key_listener(key_f2); });
	m_events.key_f2 = &key_f2->key_code;

	LabelButton* key_f3 = new LabelButton("F3", "No key assigned");
	layout->addRow(key_f3);
	connect(key_f3->button, &QPushButton::clicked, this, [this, key_f3](){ start_key_listener(key_f3); });
	m_events.key_f3 = &key_f3->key_code;

	LabelButton* key_f4 = new LabelButton("F4", "No key assigned");
	layout->addRow(key_f4);
	connect(key_f4->button, &QPushButton::clicked, this, [this, key_f4](){ start_key_listener(key_f4); });
	m_events.key_f4 = &key_f4->key_code;

	LabelButton* key_f5 = new LabelButton("F5", "No key assigned");
	layout->addRow(key_f5);
	connect(key_f5->button, &QPushButton::clicked, this, [this, key_f5](){ start_key_listener(key_f5); });
	m_events.key_f5 = &key_f5->key_code;

	LabelButton* key_f6 = new LabelButton("F6", "No key assigned");
	layout->addRow(key_f6);
	connect(key_f6->button, &QPushButton::clicked, this, [this, key_f6](){ start_key_listener(key_f6); });
	m_events.key_f6 = &key_f6->key_code;

	LabelButton* key_f7 = new LabelButton("F7", "No key assigned");
	layout->addRow(key_f7);
	connect(key_f7->button, &QPushButton::clicked, this, [this, key_f7](){ start_key_listener(key_f7); });
	m_events.key_f7 = &key_f7->key_code;

	LabelButton* key_f8 = new LabelButton("F8", "No key assigned");
	layout->addRow(key_f8);
	connect(key_f8->button, &QPushButton::clicked, this, [this, key_f8](){ start_key_listener(key_f8); });
	m_events.key_f8 = &key_f8->key_code;

	LabelButton* key_f9 = new LabelButton("F9", "No key assigned");
	layout->addRow(key_f9);
	connect(key_f9->button, &QPushButton::clicked, this, [this, key_f9](){ start_key_listener(key_f9); });
	m_events.key_f9 = &key_f9->key_code;

	LabelButton* key_f10 = new LabelButton("F10", "No key assigned");
	layout->addRow(key_f10);
	connect(key_f10->button, &QPushButton::clicked, this, [this, key_f10](){ start_key_listener(key_f10); });
	m_events.key_f10 = &key_f10->key_code;

	LabelButton* key_f11 = new LabelButton("F11", "No key assigned");
	layout->addRow(key_f11);
	connect(key_f11->button, &QPushButton::clicked, this, [this, key_f11](){ start_key_listener(key_f11); });
	m_events.key_f11 = &key_f11->key_code;

	LabelButton* key_f12 = new LabelButton("F12", "No key assigned");
	layout->addRow(key_f12);
	connect(key_f12->button, &QPushButton::clicked, this, [this, key_f12](){ start_key_listener(key_f12); });
	m_events.key_f12 = &key_f12->key_code;

	LabelButton* key_numlock = new LabelButton("Num Lock", "No key assigned");
	layout->addRow(key_numlock);
	connect(key_numlock->button, &QPushButton::clicked, this, [this, key_numlock](){ start_key_listener(key_numlock); });
	m_events.key_numlock = &key_numlock->key_code;

	LabelButton* key_kp0 = new LabelButton("KP 0", "No key assigned");
	layout->addRow(key_kp0);
	connect(key_kp0->button, &QPushButton::clicked, this, [this, key_kp0](){ start_key_listener(key_kp0); });
	m_events.key_kp0 = &key_kp0->key_code;

	LabelButton* key_kp1 = new LabelButton("KP 1", "No key assigned");
	layout->addRow(key_kp1);
	connect(key_kp1->button, &QPushButton::clicked, this, [this, key_kp1](){ start_key_listener(key_kp1); });
	m_events.key_kp1 = &key_kp1->key_code;

	LabelButton* key_kp2 = new LabelButton("KP 2", "No key assigned");
	layout->addRow(key_kp2);
	connect(key_kp2->button, &QPushButton::clicked, this, [this, key_kp2](){ start_key_listener(key_kp2); });
	m_events.key_kp2 = &key_kp2->key_code;

	LabelButton* key_kp3 = new LabelButton("KP 3", "No key assigned");
	layout->addRow(key_kp3);
	connect(key_kp3->button, &QPushButton::clicked, this, [this, key_kp3](){ start_key_listener(key_kp3); });
	m_events.key_kp3 = &key_kp3->key_code;

	LabelButton* key_kp4 = new LabelButton("KP 4", "No key assigned");
	layout->addRow(key_kp4);
	connect(key_kp4->button, &QPushButton::clicked, this, [this, key_kp4](){ start_key_listener(key_kp4); });
	m_events.key_kp4 = &key_kp4->key_code;

	LabelButton* key_kp5 = new LabelButton("KP 5", "No key assigned");
	layout->addRow(key_kp5);
	connect(key_kp5->button, &QPushButton::clicked, this, [this, key_kp5](){ start_key_listener(key_kp5); });
	m_events.key_kp5 = &key_kp5->key_code;

	LabelButton* key_kp6 = new LabelButton("KP 6", "No key assigned");
	layout->addRow(key_kp6);
	connect(key_kp6->button, &QPushButton::clicked, this, [this, key_kp6](){ start_key_listener(key_kp6); });
	m_events.key_kp6 = &key_kp6->key_code;

	LabelButton* key_kp7 = new LabelButton("KP 7", "No key assigned");
	layout->addRow(key_kp7);
	connect(key_kp7->button, &QPushButton::clicked, this, [this, key_kp7](){ start_key_listener(key_kp7); });
	m_events.key_kp7 = &key_kp7->key_code;

	LabelButton* key_kp8 = new LabelButton("KP 8", "No key assigned");
	layout->addRow(key_kp8);
	connect(key_kp8->button, &QPushButton::clicked, this, [this, key_kp8](){ start_key_listener(key_kp8); });
	m_events.key_kp8 = &key_kp8->key_code;

	LabelButton* key_kp9 = new LabelButton("KP 9", "No key assigned");
	layout->addRow(key_kp9);
	connect(key_kp9->button, &QPushButton::clicked, this, [this, key_kp9](){ start_key_listener(key_kp9); });
	m_events.key_kp9 = &key_kp9->key_code;

	LabelButton* key_kpdot = new LabelButton("KP .", "No key assigned");
	layout->addRow(key_kpdot);
	connect(key_kpdot->button, &QPushButton::clicked, this, [this, key_kpdot](){ start_key_listener(key_kpdot); });
	m_events.key_kpdot = &key_kpdot->key_code;

	LabelButton* key_kpenter = new LabelButton("KP Enter", "No key assigned");
	layout->addRow(key_kpenter);
	connect(key_kpenter->button, &QPushButton::clicked, this, [this, key_kpenter](){ start_key_listener(key_kpenter); });
	m_events.key_kpenter = &key_kpenter->key_code;

	LabelButton* key_kpplus = new LabelButton("KP +", "No key assigned");
	layout->addRow(key_kpplus);
	connect(key_kpplus->button, &QPushButton::clicked, this, [this, key_kpplus](){ start_key_listener(key_kpplus); });
	m_events.key_kpplus = &key_kpplus->key_code;

	LabelButton* key_kpminus = new LabelButton("KP -", "No key assigned");
	layout->addRow(key_kpminus);
	connect(key_kpminus->button, &QPushButton::clicked, this, [this, key_kpminus](){ start_key_listener(key_kpminus); });
	m_events.key_kpminus = &key_kpminus->key_code;

	LabelButton* key_kpasterisk = new LabelButton("KP *", "No key assigned");
	layout->addRow(key_kpasterisk);
	connect(key_kpasterisk->button, &QPushButton::clicked, this, [this, key_kpasterisk](){ start_key_listener(key_kpasterisk); });
	m_events.key_kpasterisk = &key_kpasterisk->key_code;

	LabelButton* key_kpslash = new LabelButton("KP /", "No key assigned");
	layout->addRow(key_kpslash);
	connect(key_kpslash->button, &QPushButton::clicked, this, [this, key_kpslash](){ start_key_listener(key_kpslash); });
	m_events.key_kpslash = &key_kpslash->key_code;

	LabelButton* key_kpequal = new LabelButton("KP =", "No key assigned");
	layout->addRow(key_kpequal);
	connect(key_kpequal->button, &QPushButton::clicked, this, [this, key_kpequal](){ start_key_listener(key_kpequal); });
	m_events.key_kpequal = &key_kpequal->key_code;

	LabelButton* key_kpcomma = new LabelButton("KP ,", "No key assigned");
	layout->addRow(key_kpcomma);
	connect(key_kpcomma->button, &QPushButton::clicked, this, [this, key_kpcomma](){ start_key_listener(key_kpcomma); });
	m_events.key_kpcomma = &key_kpcomma->key_code;
}

void KeyboardView::start_key_listener(LabelButton* lb) {

	if (m_selected_device == "") return;

	if (m_input_listener) {
		m_input_listener->stop();
		m_input_listener = nullptr;
	}

	lb->button->setText("Waiting for key...");
	m_selected_label_button = lb;

	m_input_listener = new InputListener(m_selected_device, this);
	m_input_listener_exists = true;

	connect(m_input_listener, &InputListener::send_detected_keys, this, &KeyboardView::recieve_detected_keys);
	connect(m_input_listener, &QThread::finished, m_input_listener, &QThread::deleteLater);

	m_input_listener->start();
}

void KeyboardView::recieve_detected_keys(QList<int> keys) {
	
	if (m_selected_label_button) {

		m_selected_label_button->key_code = QList<int>() << 0;

		if (keys.size() < 1) {
			m_selected_label_button->button->setText("No key assigned");
			return;
		}

		QString text;

		for (int k : keys) {
			text.append(libevdev_event_code_get_name(EV_KEY, k));
			text.append(" + ");
		}
		text.chop(3);

		m_selected_label_button->button->setText(text);
		m_selected_label_button->key_code = keys;

		m_selected_label_button = nullptr;
		m_input_listener = nullptr;
		m_input_listener_exists = false;
		text.clear();
	}
}

void KeyboardView::start() {
	m_virtual_keyboard_dev = new VirtualKeyboard(m_selected_device, m_events, m_input_listener_exists, this);
	m_virtual_keyboard_dev->start();
}

void KeyboardView::stop() {
	if (m_virtual_keyboard_dev) {
		m_virtual_keyboard_dev->stop();
		delete m_virtual_keyboard_dev;
		m_virtual_keyboard_dev = nullptr;
	}
}