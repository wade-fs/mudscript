#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("城鎮西大門");
    set_long("這是城鎮的西側入口，厚重的木門平時敞開著。這裡是防禦外部野獸威脅的第一線。\n");
    set_coordinate(0, 4, 0);
    add_exit("east", "/area/newbie/room_1_4.c");
    
    object ob = clone_object("/npc/guard.c");
    if (ob) move_object(ob, this_object());
}
